import sys
sys.path.append('disasm')
from disasm import disassembler, dll

# NFS2SEA.EXE is the 3Dfx (Glide) build of Need for Speed II SE. It shares most code with NFS2SEN.EXE but is
# linked differently, so the addresses below are its own.
#
# The executable is the one of EA's update of 1997-11-27 (NFS2SE_U.ZIP: TCP network play, force feedback fix),
# not the one of the CD (1997-09-23). It needs the text.* files of that update.

# data inside the code section, given at the address where the linear sweep lands on it
DATA_SEGMENTS = [
                 (0x401004, 0x401080),
                 (0x405d40, 0x405dd4),
                 (0x409e10, 0x40a0b0),
                 (0x411990, 0x411bd0),
                 (0x4131a0, 0x4131c4),
                 (0x414ba0, 0x414cf0),
                 (0x419f40, 0x419fd0),
                 (0x41b790, 0x41b8d0),
                 (0x424e20, 0x424e60),
                 (0x42fd30, 0x42fe00),
                 (0x4382f0, 0x4383c0),
                 (0x441f20, 0x442010),
                 (0x475010, 0x475030),
                 (0x4760a0, 0x4760e0),
                 (0x4775d0, 0x477620),
                 (0x479450, 0x479510),
                 (0x47d350, 0x47d400),
                 (0x49faa5, 0x49fb14),
                 (0x4c4b50, 0x4c4eb8)
    ]


KNOWN_SUBROUTINES = [
    # a bare "ret": the no-op entry of the game's Glide function table at 0x4dae90, called through it every frame
    0x4976b4,
    ]


# jumps into the middle of an instruction (the "66 a9" prefix trick that hides a "mov edi, ecx")
SPLIT_INSTRUCTIONS = [0x49d252, 0x49d287, 0x4a6f24]


THREAD_ROUTINES = []
# busy-wait loops on the timer: the same four loops as in NFS2SEN.EXE
THREAD_SEGMENTS = [0x483ec5, 0x487e7d, 0x4243b6, 0x4833fe]

FUNCTION_NAMES = {
}

# diagnosis: functions whose entry is logged ("enter:" lines), see WinApplication::traceEntry
TRACE_FUNCTIONS = []

if __name__ == '__main__':
    application = disassembler.disassemble('nfs2sea', 'nfs2sea/nfs2sea.exe', DATA_SEGMENTS,
                                           KNOWN_SUBROUTINES, SPLIT_INSTRUCTIONS, THREAD_ROUTINES)
    eacsnd = disassembler.disassemble('eacsnd', 'nfs2sea/eacsnd.dll', type=dll.DLL, rebase_after=application)
    application.write(THREAD_SEGMENTS, dlls=[eacsnd], function_names=FUNCTION_NAMES, trace_functions=TRACE_FUNCTIONS)
