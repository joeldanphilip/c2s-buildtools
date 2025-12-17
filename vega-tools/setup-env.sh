#-------------------------------------------------------------------- 
#Project Name		: MDP - Microprocessor Development Project
#Project Code		: HD083D
#Created		: 07-Jan-2020
#Filename		: setup-env.sh
#Purpose		: Environment script
#Description		: 
#Author(s)		: Premjith A V
#Email			: premjith@cdac.in
#--------------------------------------------------------------------    
#See LICENSE for license details.

#/bin/bash

VEGA_TOOLS=`pwd`

CONFIG_PATH=~/.config/vega-tools
mkdir -p $CONFIG_PATH

set_property(){
filename=$CONFIG_PATH/settings.mk

if ! grep -R "^[#]*\s*${1}=.*" $filename &> /dev/null; then
  #echo "APPENDING because '${1}' not found"
  echo "$1=$2" >> $filename 
else
  #echo "SETTING because '${1}' found already"
  sed -i "s|^[#]*\s*${1}=.*|$1=$2|" $filename
fi
}

get_property()
{
 filename=$CONFIG_PATH/settings.mk
 sed -rn "s/^${1}=([^\n]+)$/\1/p" $filename
}


# Check if libisl is installed
if ! ldconfig -p | grep -q libisl; then
  echo "libisl is not installed on this system."
  exit 1
fi

# Get the installed libisl version
ISL_VERSION=$(ldconfig -p | grep libisl | head -n 1 | awk '{print $4}')

if [ -z "$ISL_VERSION" ]; then
  echo "Unable to find the installed libisl version."
  exit 1
fi

# Define the target symbolic link for libisl.so.22
TARGET_DIR="/usr/lib/x86_64-linux-gnu"
LIBISL_TARGET="$TARGET_DIR/libisl.so.22"

# Create symbolic link if not already present
if [ -L "$LIBISL_TARGET" ]; then
  echo "Symbolic link for libisl.so.22 already exists."
else
  echo "Creating symbolic link from $ISL_VERSION to libisl.so.22..."
  sudo ln -sf "$ISL_VERSION" "$LIBISL_TARGET"
  echo "Symbolic link created: $LIBISL_TARGET -> $ISL_VERSION"
fi

# Verify the symbolic link
if [ -L "$LIBISL_TARGET" ]; then
  echo "Symbolic link for libisl.so.22 successfully created."
else
  echo "Failed to create symbolic link."
fi


echo "Setting up VEGA Tools environment"

set_property "VEGA_TOOLS" "$VEGA_TOOLS"
set_property "VEGA_TOOLCHAIN_PATH" "$VEGA_TOOLS/toolchain/bin"
set_property "CROSS_COMPILE" "riscv32-vega-elf"
set_property "RISCV_ARCH" "rv32ima_zicsr"

echo "VEGA Tools Environment added"



