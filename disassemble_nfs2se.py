import sys
sys.path.append('disasm')
from disasm import disassembler, dll


# addresses of the EA update exe (nfs2sen.ex_ from NFS2SE_U.ZIP, 1997-11-27)
DATA_SEGMENTS = [(0x401004, 0x401080),
                 (0x406090, 0x406100),
                 (0x40a160, 0x40a400),
                 (0x40ec80, 0x40ec90),
                 (0x411080, 0x411090),
                 (0x4119f0, 0x411c20),
                 (0x413220, 0x413230),
                 (0x414c20, 0x414d10),
                 (0x41a2d0, 0x41a360),
                 (0x41baf0, 0x41bc30),
                 (0x421a74, 0x421a90),
                 (0x424ef0, 0x424f30),
                 (0x426f40, 0x427010),
                 (0x42c560, 0x42c570),
                 (0x430b70, 0x430c60),
                 (0x439740, 0x4398a0),
                 (0x43d550, 0x43d570),
                 (0x449d20, 0x449d40),
                 (0x44d0a0, 0x44d100),
                 (0x44d780, 0x44d790),
                 (0x451e00, 0x451e60),
                 (0x461ae0, 0x461b00),
                 (0x462a40, 0x462a80),
                 (0x463d50, 0x463e00),
                 (0x465d80, 0x465da0),
                 (0x467a50, 0x467ac0),
                 (0x46b200, 0x46b2b0),
                 (0x46ba20, 0x46ba60),
                 (0x46fce0, 0x46fcf0),
                 (0x472a60, 0x472a70),
                 (0x4737d0, 0x473880),
                 (0x477ef0, 0x477ef4),
                 (0x4859db, 0x4859dc),
                 (0x490435, 0x4904a4),
                 (0x4a07c5, 0x4a07c6),
                 (0x4a6bd1, 0x4a6bd2),
                 (0x4b6630, 0x4b6998),
                 (0x4b6db8, 0x4d6e00),
    ]


KNOWN_SUBROUTINES = [
    ]


SPLIT_INSTRUCTIONS = [0x491118, 0x49114d, 0x49a9ea]


#THREAD_ROUTINES = [0x477b48, 0x4865cc]
#THREAD_SEGMENTS = [(0x485296, 0x4852b4)]
THREAD_ROUTINES = []
THREAD_SEGMENTS = [0x479c55, 0x47d79d, 0x4249a9, 0x478eae]

FUNCTION_NAMES = {
    0x4248b0: 'main_loop',
    0x4a3458: 'bresenham_texture_sampler',
    0x479e80: 'crt_exit',
    0x4ab4e0: 'strdup',
    0x49a013: 'malloc',
}

if __name__ == '__main__':
    application = disassembler.disassemble('nfs2se', 'nfs2se/nfs2sen.exe', DATA_SEGMENTS,
                                           KNOWN_SUBROUTINES, SPLIT_INSTRUCTIONS, THREAD_ROUTINES)
    eacsnd = disassembler.disassemble('eacsnd', 'nfs2se/eacsnd.dll', type=dll.DLL, rebase_after=application)
    application.write(THREAD_SEGMENTS, dlls=[eacsnd], function_names=FUNCTION_NAMES)
