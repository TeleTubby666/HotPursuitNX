#include <lib/glidetmu.h>

namespace win32
{
    
static const x86::reg32 s_atlasSlotCount = 2048;
static const x86::reg32 s_atlasLodCount = 9;

GlideTMU::GlideTMU(x86::reg32 atlasSize)
    :   m_textureSlots(new GlTextureSlot*[s_atlasLodCount])
    ,   m_textureSlotPool(new GlTextureSlot[s_atlasSlotCount])
    ,   m_firstFreeTextureSlot(m_textureSlotPool)
{
    for (x86::reg32 i = 0; i < s_atlasLodCount; ++i)
    {
        m_textureSlots[i] = nullptr;
    }
    for (x86::reg32 i = 0; i < s_atlasSlotCount; ++i)
    {
        m_textureSlotPool[i].next = (i < s_atlasSlotCount - 1) ? &m_textureSlotPool[i + 1] : nullptr;
        m_textureSlotPool[i].lod = 0;
    }
    for (x86::reg32 i = 0;i < (atlasSize/256) * (atlasSize/256); ++i)
    {
        GlTextureSlot* slot = allocateTextureSlot();
        slot->lod = 0;
        slot->x = (256 * i) % atlasSize;
        slot->y = 256 * (256 * i / atlasSize);
        slot->next = m_textureSlots[0];
        m_textureSlots[0] = slot;
    }
}

GlideTMU::~GlideTMU()
{
    delete[] m_textureSlots;
    delete[] m_textureSlotPool;
}

x86::reg32 GlideTMU::textureMemStart() const
{
    return 0;
}

x86::reg32 GlideTMU::textureMemEnd() const
{
    return 4096*1024;
}

GlTextureSlot** GlideTMU::getTextureInfo(x86::reg32 address)
{
    return &m_textureMem[address];
}

GlTextureSlot* GlideTMU::allocateTextureSlot()
{
    GlTextureSlot* result = m_firstFreeTextureSlot;
    NFS2_ASSERT(result);
    m_firstFreeTextureSlot = result->next;
    return result;
}

void GlideTMU::freeTextureSlot(GlTextureSlot* slot)
{
    slot->next = m_firstFreeTextureSlot;
    m_firstFreeTextureSlot = slot;
}

void GlideTMU::breakdownTextureSlot(GlTextureSlot* slot)
{
    slot->lod++;
    x86::reg32 size = 256 >> slot->lod;
    slot->next = m_textureSlots[slot->lod];
    m_textureSlots[slot->lod] = slot;
    GlTextureSlot* s = allocateTextureSlot();
    s->lod = slot->lod;
    s->x = slot->x + size;
    s->y = slot->y;
    s->next = m_textureSlots[slot->lod];
    m_textureSlots[slot->lod] = s;
    s = allocateTextureSlot();
    s->lod = slot->lod;
    s->x = slot->x;
    s->y = slot->y + size;
    s->next = m_textureSlots[slot->lod];
    m_textureSlots[slot->lod] = s;
    s = allocateTextureSlot();
    s->lod = slot->lod;
    s->x = slot->x + size;
    s->y = slot->y + size;
    s->next = m_textureSlots[slot->lod];
    m_textureSlots[slot->lod] = s;
}

GlTextureSlot* GlideTMU::reserveTextureSlot(x86::reg32 lod)
{
    GlTextureSlot* result = m_textureSlots[lod];
    if (!result)
    {
        for (x86::sreg32 parentLod = lod-1; parentLod >= 0; --parentLod)
        {
            GlTextureSlot* parent = m_textureSlots[parentLod];
            if (parent)
            {
                m_textureSlots[parentLod] = parent->next;
                for (x86::reg32 childLod = parentLod; childLod < lod-1; ++childLod)
                {
                    breakdownTextureSlot(parent);
                    parent = m_textureSlots[childLod + 1];
                    m_textureSlots[childLod + 1] = parent->next;
                }
                breakdownTextureSlot(parent);
                break;
            }
        }
        result = m_textureSlots[lod];
        if (!result)
            return nullptr;
    }
    m_textureSlots[lod] = result->next;
    return result;
}

void GlideTMU::returnTextureSlot(GlTextureSlot* slot)
{
    /* join the four quarters of a block again when all of them are free, so that large textures still find room */
    while (slot->lod > 0)
    {
        const x86::reg32 size = 256 >> slot->lod;
        const x86::reg32 px = slot->x & ~(2 * size - 1);
        const x86::reg32 py = slot->y & ~(2 * size - 1);
        GlTextureSlot* quarters[3];
        int found = 0;
        for (GlTextureSlot* s = m_textureSlots[slot->lod]; s && found < 3; s = s->next)
        {
            if (s != slot && (s->x & ~(2 * size - 1)) == px && (s->y & ~(2 * size - 1)) == py)
                quarters[found++] = s;
        }
        if (found < 3)
            break;
        for (int i = 0; i < 3; ++i)
        {
            for (GlTextureSlot** link = &m_textureSlots[slot->lod]; *link; link = &(*link)->next)
            {
                if (*link == quarters[i])
                {
                    *link = quarters[i]->next;
                    break;
                }
            }
            freeTextureSlot(quarters[i]);
        }
        slot->lod--;
        slot->x = px;
        slot->y = py;
    }
    slot->next = m_textureSlots[slot->lod];
    m_textureSlots[slot->lod] = slot;
}

}
