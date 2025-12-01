/*######################################################################
#
#
File Name:
#
########################################################################
#
# Project Name
:
#
# Project Code
:
#
# Created
:
#
# Purpose
:
#
# Description
:
#
# Author(s)
:
#
# Version No
:
#
# Revisions
:
#
# Remarks
:
#
# Copyright
######################################################################*/

#ifndef __DMAC_H
#define __DMAC_H

#include "cdac_datatype.h"


/*  Include section
*
***************************************************/

/*  Defines section
*
***************************************************/

#define DMAC_ROM_SRAM						1
#define DMAC_ROM_DDR						2
#define DMAC_DDR_SRAM					    3

#define DATA_LEN										256

#define DMAC_DISABLE 		0
#define DMAC_ENABLE 		1


#define CHANNEL0 		0
#define CHANNEL1 		1
#define CHANNEL2 		2
#define CHANNEL3 		3


#define DMAC_LLI_DISABLED 					0
#define DMAC_LLI_ENABLED 						1

#define DMAC_CH_INTR_DISABLE 			0
#define DMAC_CH_INTR_ENABLE 			1


#define SRC_DW_8 					0
#define SRC_DW_16 				1
#define SRC_DW_32 				2
#define SRC_DW_64 				3
#define SRC_DW_128 				4
#define SRC_DW_256 				5


#define DST_DW_8 					0
#define DST_DW_16 				1
#define DST_DW_32 				2
#define DST_DW_64 				3
#define DST_DW_128 			4

#define DST_CONFIG_ERROR_WIDTH 			5



#define LM_ACE 				0
#define LM_AXI 				1
#define LM_NO_MSEL	2

#define DMA_INACTIVE 	0
#define DMA_ACTIVE 		1

#define LLI_DISABLE 			0
#define LLI_ENABLE 			2


#define CIE_DISABLE 		    0
#define CIE_ENABLE 		    1

#define SAI_DISABLE 			0
#define SAI_ENABLE 		    1

#define DAI_DISABLE 		0
#define DAI_ENABLE 		    1

#define CBE_DISABLE 		0
#define CBE_ENABLE 		 1

#define DCE_DISABLE 		0
#define DCE_ENABLE 		1

#define DMA_INTR_DISABLE 		0
#define DMA_INTR_ENABLE 			1

#define CMS_ACE2ACE 		0
#define CMS_AXI2ACE  		1
#define CMS_ACE2AXI			2
#define CMS_AXI2AXI 		3


#define CTS_1						1
#define CTS_2						2
#define CTS_4    					4  // For 512 Bytes transfer
#define CTS_20    					20 // For 5 packt transfer via DMA
#define CTS_28    					28
#define CTS_32    					32 // For 4096 Bytes transfer
#define CTS_64    					64 // For 4096 Bytes transfer

#define CTS_40    					40

#define CTS_8 						8
#define CTS_16 						16
#define CTS_128 					128
#define CTS_255 					255

#define CTS_256 					256
#define CTS_512						512
#define CTS_1024					1024
#define CTS_2048					2048
#define CTS_4096					4096
#define CTS_8191					8191



#define CBS_DISABLED 		0
#define CBS_2 						1
#define CBS_4 						2
#define CBS_8 						3

#define NO_LLI													0
#define NO_NEXT_LLI									0

#define DMAC_BASE_ADDR 					0x10000B00UL

#define TABLE_NO_0									0
#define TABLE_NO_1									1
#define TABLE_NO_2 								2
#define TABLE_NO_3									3
#define TABLE_NO_4									4
#define TABLE_NO_5 								5

#define CHK_CH0_ENABLED					(1 << 10)
#define CHK_CH1_ENABLED					(1 << 11)
#define CHK_CH2_ENABLED					(1 << 12)
#define CHK_CH3_ENABLED					(1 << 13)

#define CHK_CH0_DTD								(1 << 1)
#define CHK_CH1_DTD								(1 << 2)
#define CHK_CH2_DTD								(1 << 3)
#define CHK_CH3_DTD								(1 << 4)



#define RESULT_ADDR 								0x91000000



/*  Defines section
*
***************************************************/

#define MEM_ADDR								0x25000UL
#define CH0_SRC_ADDR							MEM_ADDR
#define CH1_SRC_ADDR							MEM_ADDR
#define CH2_SRC_ADDR							MEM_ADDR
#define CH3_SRC_ADDR							MEM_ADDR

#define LLI_0_ADDRESS								0x2E000UL
#define LLI_1_ADDRESS								0x2B000UL
#define LLI_2_ADDRESS								0x2C000UL
#define LLI_3_ADDRESS								0x2D000UL


#define DMAC_CH0_LLI_BASE_ADDR				   LLI_0_ADDRESS
#define DMAC_CH1_LLI_BASE_ADDR				   LLI_1_ADDRESS
#define DMAC_CH2_LLI_BASE_ADDR				   LLI_2_ADDRESS
#define DMAC_CH3_LLI_BASE_ADDR				   LLI_3_ADDRESS

#define DMAC_CH0_LLI_Table(n) 				(*((volatile DMAC_CH0_LLI_TABLE_C *)(DMAC_CH0_LLI_BASE_ADDR + (n * 32))))
#define DMAC_CH1_LLI_Table(n) 				(*((volatile DMAC_CH1_LLI_TABLE_C *)(DMAC_CH1_LLI_BASE_ADDR + (n * 32))))
#define DMAC_CH2_LLI_Table(n) 				(*((volatile DMAC_CH2_LLI_TABLE_C *)(DMAC_CH2_LLI_BASE_ADDR + (n * 32))))
#define DMAC_CH3_LLI_Table(n) 				(*((volatile DMAC_CH3_LLI_TABLE_C *)(DMAC_CH3_LLI_BASE_ADDR + (n * 32))))


//unsigned long  Read_DMAC_Global_Status_Reg_sram_to_sram(void);

typedef struct dmac_transfer		//DMA Channel parameters
{
	UL SrcAddr;
	UL DestAddr;
	union
	{
			struct
			{
				unsigned long int	DCE 	: 1,			// DMA CHANNEL ENABLE
					CIE 			: 1, 			// CHANNEL INTERRUPT ENABLE
					SRC_DW 	: 3, 			//SOURCE DATA WIDTH
					DST_DW : 3, 			//DESTINATION DATA WIDTH
					DAI 			: 1,		 	//DESTINATION ADDRESS INCREMENT
					SAI 			: 1, 			//SOURCE ADDRESS INCREMENT
					CBE			: 1,			//CHANNEL BURST ENABLE
					CMS			: 2,     		//CHANNEL MASTER SELECTOR
					CTS 			: 13,		//CHANNEL TRANSFER SIZE
					CIC 			: 3, 			//CHANNEL INTERRUPT CAUSE
					CBS			: 3,			 //CHANNEL BURST SIZE
					Rsrvd		:32;		// RESERVED
			}__attribute__((packed)) Bits;
			UL dword;
		}Control;

		union
		{
			struct
			{
				unsigned long int 	LM	: 1, //AHB master select for loading the next LLI
					LE 			: 1,
					ZERO	: 1,
				   NEXT_ADDR		:61;		// RESERVED
			}__attribute__((packed)) LLIBits;
			UL dword;
		}LLI;


}DMAtransfer_Type;

typedef	struct dmac_global_reg				//DMA GLOBAL CONTROL REGISTER
{
			UL CtrlReg;
			UL StatusReg;
}DMAC_GLOBAL_REG_TYPE; // 0x00


typedef union
{
	struct dmac_global_ctrl_reg				//DMA GLOBAL CONTROL REGISTER
	{
				unsigned long int	DE 	: 1,			// DMA ENABLE
				DIE : 1, 				// DMA INTERRUPT ENABLE
				Rsrvd :62;		// RESERVED
	}__attribute__((packed)) Bits;
	UL  dword;
}DMAC_GlobalCtrl_Type;



typedef union
{
	struct dmac_global_status_reg			//DMA GLOBAL STATUS REGISTER
	{
				unsigned long int	DA 	: 1,			// DMA ACTIVE
				DTD: 4, 			// DMA TRANSFER DONE
				Rsrvd0 	: 1, 				//Reserved
				DCIS :4,			// DMA CHANNEL INTERRUPT STATUS
				DEC :4,				// DMA ENABLED CHANNELS
				Rsrvd :50;		// RESERVED
	}__attribute__((packed)) Bits;
	UL  dword;
}DMAC_GlobalStatus_Type;


typedef union
{
	struct
	{
		unsigned long int 	LM	: 1, 	//AHB master select for loading the next LLI
			LE 			: 1,
			ZERO	: 1,
		   NEXT_ADDR		:61;		// RESERVED
	}__attribute__((packed)) Bits;
	UL  dword;
} DMAC_Ch_LLI_REG_Type;


typedef struct DMAC_CH0_LLI
{
	UL  CH_LLI_SrcAddr;
	UL  CH_LLI_DstAddr;
	UL  CH_next_level_LLI;
	UL  CH_Ctrl_Word;
}DMAC_CH0_LLI_TABLE_C;

typedef struct DMAC_CH1_LLI
{
	UL  CH_LLI_SrcAddr;
	UL  CH_LLI_DstAddr;
	UL  CH_next_level_LLI;
	UL  CH_Ctrl_Word;
}DMAC_CH1_LLI_TABLE_C;

typedef struct DMAC_CH2_LLI
{
	UL  CH_LLI_SrcAddr;
	UL  CH_LLI_DstAddr;
	UL  CH_next_level_LLI;
	UL  CH_Ctrl_Word;
}DMAC_CH2_LLI_TABLE_C;

typedef struct DMAC_CH3_LLI
{
	UL  CH_LLI_SrcAddr;
	UL  CH_LLI_DstAddr;
	UL  CH_next_level_LLI;
	UL  CH_Ctrl_Word;
}DMAC_CH3_LLI_TABLE_C;


typedef struct dmac_channel_regs			//DMA Channel registers
{
	UL SrcAddrReg;
	UL DestAddrReg;
	UL ChannelLLIReg;
	UL ChannelCtrlReg;
}DMAC_CHANNEL_REG_TYPE;


#define DMAC_globalReg			 			(*((volatile DMAC_GLOBAL_REG_TYPE *)(DMAC_BASE_ADDR + 0x00)))
#define DMAC_channelReg(n) 				(*((volatile DMAC_CHANNEL_REG_TYPE *)(DMAC_BASE_ADDR + 0x10 + (n * 0x20))))

void WriteDatatoMemory(void);
//void Enable_DMAC(UC en_dis_intr);
//unsigned long Read_DMAC_Global_Status_Reg(void);
//void  Check_DMAC_transferDone(UC channelNum);
//UC  Check_DMAC_transferDone_simultaneous(void);
//void Check_DMAC_transferDone(struct cdac_mmc_host *host,UC channelNum);
void  Configure_DMAC_Channel(void);
void Set_DMAC_LLI_Addr(UC channel_num,UL next_lli_addr,UC lli_master_select);
void Config_Channel_Ctrl_Status_reg(UC channel);
void  ReadCompareData(UC channel,unsigned long int src_addr ,unsigned long int ch_dst_addr,unsigned long int dataLen );
void Configure_CH_LLI_Table(UC channel_num,DMAtransfer_Type pTransfer);
//void Init_DMA_Ch_CtrlReg_params(UC dce, UC cie,UL src_data_width, UL dst_data_width, UC dai, UC sai, UC cbe, UC cms, US cts, UC cbs);
void create_CH0_LLI_Table(UC table_num, UL lli_src_addr, UL lli_dst_addr, UL next_level_LLIptr,UL cWord,UC msel_LLI);
void DMAC_testCase(UL test_num,UC dce, UC cie,UL src_data_width, UL dst_data_width, UC dai,UC sai, UC cbe, UC cms, US cts, UC cbs,
		UC channel,UL ch_source_addr,UL ch_dest_addr,	UC lli_master_select, UL next_lli_addr);

void ReadCompareData_8_new(unsigned long int ch_src_addr ,unsigned long int ch_dst_addr,unsigned long int dataLen,UC dai,UC sai);
void ReadCompareData_16_new(unsigned long int ch_src_addr ,unsigned long int ch_dst_addr,unsigned long int dataLen,UC dai,UC sai);
void ReadCompareData_32_new(unsigned long int ch_src_addr ,unsigned long int ch_dst_addr,unsigned long int dataLen,UC dai,UC sai);
void ReadCompareData_64_new(unsigned long int ch_src_addr ,unsigned long int ch_dst_addr,unsigned long int dataLen,UC dai,UC sai);
void ReadCompareData_128_new(unsigned long int ch_src_addr ,unsigned long int ch_dst_addr,unsigned long int dataLen,UC dai,UC sai);
void DMAC_Test(UL src_dw,UL dst_dw,UC master_clk);
US  Find_new_CTS(UL src_data_width,UL dst_data_width, US cts);
void TestResult(void);
void Compare_data_simulataneously(UL src_data_width,UL dst_data_width,US cts, UC cbs,UC dai,UC sai);
void DMAC_Basic_Test(void);
void DMAC_Multilevel_LLI_Test(void);
void DMAC_Normal_Single_LLI(UL test_num,UC dce, UC cie,UL src_data_width, UL dst_data_width, UC dai,UC sai, UC cbe, UC cms, US cts, UC cbs,
		UC channel,UL ch_source_addr,UL ch_dest_addr,	UC lli_master_select, UL next_lli_addr);
void DMAC_LLI_All_Channels_test(void);
void DMAC_Normal_LLI_Normal_Test(void);
void Compare_data_simulataneously_all(UL src_data_width,UL dst_data_width);
void disp_LLITable_params(UC channel_no,UC table_num);


/*******************************************/


void Init_DMA_Ch_CtrlReg_params_sram_to_sram(UC dce, UC cie,UL src_data_width, UL dst_data_width, UC dai, UC sai, UC cbe, UC cms, US cts, UC cbs);

#endif /*__DMAC_H*/


