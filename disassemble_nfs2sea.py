import sys
sys.path.append('disasm')
from disasm import disassembler, dll

# NFS2SEA.EXE is the 3Dfx (Glide) build of Need for Speed II SE. It shares most code with NFS2SEN.EXE but is
# linked differently, so the addresses below are its own.

# data inside the code section, given at the address where the linear sweep lands on it
DATA_SEGMENTS = [
                 (0x401004, 0x401080),
                 (0x405d30, 0x405dc4),
                 (0x409e00, 0x40a0a0),
                 (0x4119a0, 0x411be0),
                 (0x4131b0, 0x4131d4),
                 (0x414bb0, 0x414d00),
                 (0x419f50, 0x419fe0),
                 (0x41b7a0, 0x41b8e0),
                 (0x423340, 0x423380),
                 (0x42e240, 0x42e310),
                 (0x436800, 0x4368d0),
                 (0x440430, 0x440520),
                 (0x4734c0, 0x4734e0),
                 (0x474550, 0x474590),
                 (0x475a80, 0x475ad0),
                 (0x477900, 0x4779c0),
                 (0x47b800, 0x47b8b0),
                 (0x49aa15, 0x49aa84),
                 (0x4c2bb0, 0x4c2f18)
    ]


KNOWN_SUBROUTINES = [
    ]


# jumps into the middle of an instruction (the "66 a9" prefix trick that hides a "mov edi, ecx")
SPLIT_INSTRUCTIONS = [0x4981c2, 0x4981f7, 0x4a2af0]


THREAD_ROUTINES = []
# busy-wait loops on the timer: the same four loops as in NFS2SEN.EXE
THREAD_SEGMENTS = [0x482335, 0x4862ed, 0x4228f6, 0x48186e]

FUNCTION_NAMES = {
}

if __name__ == '__main__':
    application = disassembler.disassemble('nfs2sea', 'nfs2sea/nfs2sea.exe', DATA_SEGMENTS,
                                           KNOWN_SUBROUTINES, SPLIT_INSTRUCTIONS, THREAD_ROUTINES)
    eacsnd = disassembler.disassemble('eacsnd', 'nfs2sea/eacsnd.dll', type=dll.DLL, rebase_after=application)
    application.write(THREAD_SEGMENTS, dlls=[eacsnd], function_names=FUNCTION_NAMES)
