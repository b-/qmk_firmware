#!/bin/bash -exo pipefail
#export QMK_ROOT="${HOME}/Documents/Projects/qmk_firmware"
export QMK_ROOT=$(pwd)
export QMK_KEEB="massdrop/alt"
export QMK_KEYMAP="b"
export QMK_JSON="$1"
function FLASH() {
  export MDLOADER="${HOME}/Documents/Projects/mdloader/build/mdloader"
  cd $(dirname ${MDLOADER})
  ${MDLOADER} -vfD "${QMK_OUTPUT}" --restart
}
#$1 is the keymap.json
cd ${QMK_ROOT}
[[ -n ${QMK_JSON} ]] && bin/qmk json2c -o keyboards/${QMK_KEEB}/keymaps/${QMK_KEYMAP}/keymap.c ${QMK_JSON}
bin/qmk compile -kb ${QMK_KEEB} -km ${QMK_KEYMAP}
export QMK_OUTPUT="${QMK_ROOT}/${QMK_KEEB//\//_}_${QMK_KEYMAP//\//_}.bin"
FLASH
