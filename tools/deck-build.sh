#!/bin/bash
# Build HotPursuitNX for the Switch on the Steam Deck and copy the results to a network share.
#
#   tools/deck-build.sh <branch> <expected commit>
#   e.g. tools/deck-build.sh switch-controls-3dfx 1a2b3c4
#
# The share can be changed with HP_SHARE (default smb://192.168.1.11/Exchange/), for example
#   HP_SHARE=smb://name@192.168.1.11/Exchange/ tools/deck-build.sh ...

# run from a copy, because the checkout below may replace this file
if [ -z "$HP_BUILD_COPY" ]; then
    copy=$(mktemp /tmp/deck-build.XXXXXX.sh)
    cp "$0" "$copy"
    HP_BUILD_COPY=1 exec bash "$copy" "$@"
fi

set -e
branch=${1:?usage: tools/deck-build.sh <branch> <expected commit>}
expected=${2:?usage: tools/deck-build.sh <branch> <expected commit>}
share=${HP_SHARE:-smb://192.168.1.11/Exchange/}

cd "$(git rev-parse --show-toplevel)"
git fetch origin "$branch"
git checkout -B "$branch" FETCH_HEAD
actual=$(git log -1 --format=%h)
echo "Stand: $(git log --oneline -1)"
case "$(git rev-parse HEAD)" in
    "$expected"*) echo "Commit $expected bestaetigt." ;;
    *) echo "FEHLER: erwartet $expected, bekommen $actual. Abbruch."; exit 1 ;;
esac

podman run --rm -it -v "$PWD":/src:Z -w /src hp-build bash -c '
  cmake -B build-switch \
      -DCMAKE_TOOLCHAIN_FILE=cmake/toolchain-switch.cmake \
      -DCMAKE_BUILD_TYPE=Release &&
  cmake --build build-switch -j$(nproc)
'

kio=$(command -v kioclient || command -v kioclient5 || true)
if [ -z "$kio" ]; then
    echo "kioclient nicht gefunden: Dateien liegen in build-switch/"
    exit 0
fi
failed=0
for f in build-switch/*.nro build-switch/*.elf; do
    [ -e "$f" ] || continue
    if "$kio" --overwrite --noninteractive copy "$f" "$share"; then
        echo "kopiert: $f"
    else
        failed=1
    fi
done
[ $failed = 0 ] && echo "Fertig: $actual auf $share" || echo "Einige Dateien konnten nicht kopiert werden (siehe oben); sie liegen in build-switch/"
