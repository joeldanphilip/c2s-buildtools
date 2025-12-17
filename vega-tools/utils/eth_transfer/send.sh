#-------------------------------------------------------------------- 
#Project Name		: MDP - Microprocessor Development Project
#Project Code		: HD083D
#Created		: 07-Jan-2020
#Filename		: send script
#Purpose		: Send the program to board
#Author(s)		: Premjith A V
#Email			: premjith@cdac.in
#--------------------------------------------------------------------  
#!/bin/bash
CONFIG_PATH=~/.config/vega-tools

get_property()
{
 filename=$CONFIG_PATH/settings.mk
 sed -rn "s/^${1}=([^\n]+)$/\1/p" $filename
}
DIR=$(get_property "VEGA_TOOLS")

set_property(){
filename=$DIR/utils/eth_transfer/env.txt

if ! grep -R "^[#]*\s*${1}=.*" $filename > /dev/null; then
#  echo "APPENDING because '${1}' not found"
  echo "$1=$2" >> $filename 
else
#  echo "SETTING because '${1}' found already"
  sed -i "s|^[#]*\s*${1}=.*|$1=$2|" $filename
fi
}
set_property "files" "$#"

cd $DIR/utils/eth_transfer
#cp $1 $DIR/utils/eth_transfer
#file1=$(basename $1)
#echo $DIR
#if [ -f "/dev/ttyuSB0" ]; then
#	sudo ./reset_fpga /dev/ttyUSB0
#else
#	echo "ttyUSB0 uart not connected"
#fi
sleep 2
#sudo -i date
/usr/bin/dtc -O dtb -o riscv.dtb riscv.dts
IFACE=$(nmcli device | awk '$2=="ethernet" && ($3=="connecting" || $3=="connected") {print $1}')

if [ -z "$IFACE" ]; then
	echo "Please connect the board to ethernet interface of PC"
else 
	if [ ! -z "$1" ] || [ ! -z "$2" ] || [ ! -z "$3" ] || [ ! -z "$4" ] || [ ! -z "$5" ]; then
		echo "sudo ./ether $IFACE $1 $2 $3 $4 $5"
		sudo ./ether $IFACE $1 $2 $3 $4 $5 
	else
		echo "No files to send"
	fi
fi 
