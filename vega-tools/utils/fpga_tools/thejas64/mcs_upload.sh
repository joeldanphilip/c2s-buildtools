#!/bin/bash
if [ "${VEGA_VIVADO_PATH}" == "" ]; then
read -e -p "Enter the path to Vivado Lab tools installation: " VEGA_VIVADO_PATH
fi

export CUR_DIR=`pwd`
echo $CUR_DIR

echo ${VEGA_VIVADO_PATH}/*/bin
cd ${VEGA_VIVADO_PATH}/*/bin
./vivado_lab -mode tcl < $CUR_DIR/mcs_thejas_64.tcl


