# Hot Pursuit NX

Hot Pursuit NX is a port of nfs-recompiled, a static recompilation of **Need for Speed II: Special Edition** and **Need for Speed III: Hot Pursuit**.

<a href="screenshots/nfsiise-1.png"><img src="screenshots/nfsiise-1.png" alt="nfs2 intro video" width="50%"></a>

<a href="screenshots/nfsiise-2.png"><img src="screenshots/nfsiise-2.png" alt="nfs2 menu" width="50%"></a>

<a href="screenshots/nfsiise-3.png"><img src="screenshots/nfsiise-3.png" alt="nfs2 gameplay" width="50%"></a>

<a href="screenshots/nfsiiihp-1.png"><img src="screenshots/nfsiiihp-1.png" alt="nfs3 menu" width="50%"></a>

<a href="screenshots/nfsiiihp-2.png"><img src="screenshots/nfsiiihp-2.png" alt="nfs3 gameplay" width="50%"></a>

## Setup

### 1. Game Data

You need the original game files.

1.  **Install the game** from your original CD (or mount the iso).
    On Linux, install the game from the CD-ROM through Wine, e.g. `WINEARCH=win32 WINEPREFIX=/opt/win98 wine /mnt/AUTORUN.EXE`
    Note that Wine's WOW64 mode will not work for this as both games are 16-bit executables.
    I found that a Windows 7 VM was the easiest way to extract the files.
2.  **Copy CD data**: The game expects certain files to be on the CD. To run without the CD, copy the `Fedata` and `GameData` folders from the CD-ROM into your game installation directory (merging with existing folders).

### 2. Running

Both `nfs2se.nro` and `nfs3hp.nro` are provided on the releases page. Place
`nfs2se.nro` in `sdmc:/switch/nfs2se/` and `nfs3hp.nro` in
`sdmc:/switch/nfs3hp/`.

Also, be sure to place your extracted game data (see step 1) in `sdmc:/switch/nfs2se/`
and `sdmc:/switch/nfs3hp/` for their respective games. (The FeData and Gamedata
folders should be beside the nro in that folder).

## Controls

The Switch controls are mapped to the original keyboard commands used by both games.

| Switch control | Action |
| --- | --- |
| Left stick / D-pad | Steering / menu navigation |
| ZR | Accelerate |
| ZL | Brake / reverse |
| B | Handbrake |
| A | Nitrous / Confirm (menus) |
| X | Weapons / Equipment: Spike strip (NFS3) / Cycle camera (NFS2) |
| Y | Weapons / Equipment: Horn / siren |
| Right stick click (R3) | Change camera view |
| Right stick down / R | Look behind |
| Left stick click (L3) | Reset car |
| Plus (+) | Pause menu / back (Esc) |
| L | Free key (Q), assignable in the controls menu |
| Left stick | Arrow keys; in a race steering is proportional to the stick deflection (menus: plain arrows) |
| Right stick up / left / right | Free keys U / J / M, assignable |
| Minus (-) | Shift down (manual) |

### Force feedback

The game's force feedback effects are turned into rumble of the controller (the strength follows the running effects; spring, damper and friction forces have no equivalent and are ignored). The game only offers force feedback if the controller has rumble motors.

### Mouse in the menus

The game is operated with a mouse cursor in its menus. On the Switch:

- **Touch screen**: touching the screen puts the cursor at that spot and presses the left mouse button; dragging drags (sliders).
- **Right stick** moves the cursor (the further you push, the faster it goes), **a click on the right stick (R3) or ZR** is the left mouse button. In a race the right stick keeps its key functions.

### Joystick (DirectInput)

The Switch controller is also offered to the game as a DirectInput joystick with analog axes (left stick = X/Y, right stick = Rx/Ry). If you choose the joystick as the controller in the game's controls menu, steering is smooth and uses the real stick position. While the game reads the joystick, the stick-to-key conversion is switched off. The Switch buttons are also joystick buttons (0 = A, 1 = B, 2 = X, 3 = Y, 4 = L3, 5 = R3, 6 = L, 7 = R, 8 = ZL, 9 = ZR, 10 = +, 11 = -, 12-15 = D-pad), so every action can be assigned to the joystick in the controls menu. The menus still get their keys (Enter, Esc, arrows) from A, B and the D-pad.

## Building from source

### Prerequisites

- CMake ≥ 3.16
- Git
- pkg-config
- A devkitPro installation containing devkitA64, libnx, and switch-tools
- nxvk-gl installed in the Switch portlibs prefix

### Build Instructions

Configure and build both NROs with:

```bash
cmake -B build-switch \
    -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-switch.cmake \
    -DCMAKE_BUILD_TYPE=Release
cmake --build build-switch -j$(nproc)
```

The build artefacts are written to `build-switch/nfs2se.nro` and
`build-switch/nfs3hp.nro`.

### Menu and race

The game tells menus and races apart by what it loads (track data starts a race, the front end ends it). A is Enter in both. B goes back (Esc) in menus and is the handbrake (Space) in a race. Plus is Esc (pause / back). Enter and Esc are what the controls menu itself uses, so A, B and Plus cannot be assigned there; every other button can.

### Name entry / keyboard

The Switch keyboard opens by itself when the game starts a text field (the driver name). The text you enter replaces the current content. L3 and R3 pressed together open it by hand; a single click of L3 or R3 acts when released.
