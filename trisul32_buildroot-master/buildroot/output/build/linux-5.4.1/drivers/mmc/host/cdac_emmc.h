#ifndef EMMC_H_
#define EMMC_H_

/***************************************************
* File Name			: emmc.h
* Version Number	:
* Project Code		:
* Project Mnemonic	:
* Product Name		:
* Module Name		:
* Description		:
* Author			:
* Revision History & 
* Date				:
* 					:
* Modified by whom &
* Reasons   		:
***************************************************/

/*  Include section
* 
*
***************************************************/

#include "cdac_globals.h"
#include "cdac_datatype.h"


/*  Define section
* 
*
***************************************************/

extern volatile UL *ch0GloCtrlReg ;
extern volatile UL *ch0GloStatReg;
extern volatile UL *ch0SrcReg;
extern volatile UL *ch0DstReg;
extern volatile UL *ch0LLIReg;
extern volatile UL *ch0CtrlReg;

typedef union
{
	struct
	{
		UL 	DEV_BUSY				: 1,
		 	CMD_SENT 				: 1,
			CMD_RCVD				: 1,
			RSVD_0					: 2,
			NR_WR_BLK_TXD			: 8,
			MUL_BLK_WR_CMPLT		: 1,
			MUL_BLK_RD_CMPLT		: 1,
			RD_BLK_RXD				: 8,
			SIN_BLK_WR_CMPLT		: 1,
			CRC7_ERR_RESP			: 1,
			CRC16_ERR_RESP			: 1,
			CMD_RESP_TOUT_ERR		: 1,
			WR_TOUT_ERR				: 1,
			RD_TOUT_ERR				: 1,
			SIN_BLK_RD_CMPLT		: 1,
			RSVD_1					: 1,
			CMD_RESP_TX_BIT_ERR 	: 1,
			CMD_RESP_END_BIT_ERR	: 1,
			RD_DATA_BLK_END_BIT_ERR	: 1,
			RD_DATA_FIFO_FULL		: 1,
			RD_DATA_FIFO_EMTY		: 1,
			WR_DATA_FIFO_FULL		: 1,
			WR_DATA_FIFO_EMTY		: 1,
			RD_FIFO_FULL_ERR		: 1,
			BOOT_FIFO_FULL			: 1,
			BOOT_FIFO_EMTY			: 1,
			NR_BLK_RXD_IN_BOOT_FIFO : 16,
			TEST_PATT_SEND			: 1,
			TEST_PATT_RESP_RXD		: 1,
			CSD_PGM_BIT_SENT		: 1,
			WR_PR_STATUS_RXD		: 1,
			WR_PR_TYPE_RXD			: 1,
			CMD0_WITH_ARG0_SENT		: 1,
			ONE_BLK_AVL_BOOT_FIFO	: 1;
	}Bits;
	UL Value;
}eMMCStatusType;



typedef union
{
	struct
	{
		UL 	CMD_INDEX			: 6,
			CMD_ARG 			: 32,
			CMD_TYPE			: 2,
			CMD_RESP_TYPE		: 2,
			RSVD_0				: 22;
	}Bits;
	UL  Value;
}eMMCCmdType;


typedef union
{
	struct
	{
		UL 	DATA_TRSFR_MODE		: 4,
			DATA_BUS_WIDTH 		: 4,
			RD_WR_BLK_LEN		: 16,
			NR_BLK_RD_WR		: 8,
			DEV_RST				: 1,
			BOOT_ACK_EN			: 1,
			CMD_LINE			: 1,
			CLR_WR_DATA_FIFO	: 1,
			CLR_RD_DATA_FIFO	: 1,
			CLR_BOOT_FIFO		: 1,
			OPEN_END_TRANS		: 1,
			CMD_LINE_VALID		: 1,
			ERROR_OVERRIDE		: 1,
			TOT_FRAMES_TO_INRPT	: 8,
			STOP_EMMC_CLK		: 1,
			RSVD_0				: 14;

	}Bits;
	UL  Value;
}eMMCOpModeType;

#define HALF_FILL_WR_BLK_NR	5
#define NO_OF_BLKS_TO_READ 4

#ifdef ENABLE_EMMC_PLIC
	#define NO_OF_FRAME_READ_BOOTFIFO	2 // for reading data in MB from USER area
	//#define NO_OF_FRAME_READ_FIFO	8	// For reading data from BOOT area
#else
	#define NO_OF_FRAME_READ_BOOTFIFO	1
	//#define NO_OF_FRAME_READ_FIFO	1
#endif

#define SET_BLK_LEN_512

#define NO_OF_BLK_READ_IN_DMA_TRSFR_MAX		15 //(No of Blocks)
#define NO_OF_BLK_READ_IN_DMA_TRSFR		1 //(No of Blocks)
#define NO_OF_BLK_READ_IN_DMA_TRSFR_BOOTFIFO		NO_OF_FRAME_READ_BOOTFIFO //(No of Blocks)
#define EMMC_OP_WR_RD_BLK_LEN_512	 512 //(In Bytes)
#define EMMC_OP_WR_RD_BLK_LEN_4096	 4096 //(In Bytes)
#define EMMC_BLK_LEN	512 // in bytes
#define DUT_MAX_BLK_IN_ONE_TRSFR		8

#define ARG_RCA		(0x1000 << 16) // [31:16] RCA [15:0] stuff bits JEDEC Spec 4.5
#define eMMC_CMD_0 	0
#define eMMC_CMD_1 	1
#define eMMC_CMD_2 	2
#define eMMC_CMD_3 	3
#define eMMC_CMD_6 	6
#define eMMC_CMD_7 	7
#define eMMC_CMD_8 	8
#define eMMC_CMD_9 	9
#define eMMC_CMD_10 10

#define eMMC_CMD_12 12 // Stop Transmission
#define eMMC_CMD_13 13 // Send Status

#define eMMC_CMD_14 14 // Bus Width Test (Read)

#define eMMC_CMD_16 16 // Set Read/write blk len
#define eMMC_CMD_17 17 // Read single block
#define eMMC_CMD_18 18 // Read Multiple block

#define eMMC_CMD_19 19 // Bus Width Test (Write)

#define eMMC_CMD_23 23   // SET_BLOCK_COUNT (For multiple read/write)
#define eMMC_CMD_24 24   // Write block cmd
#define eMMC_CMD_25 25   // Write Multiple block cmd

#define eMMC_CMD_52 52   // Reserved CMD

#define eMMC_CMD_35 35   // ERASE_GROUP_START cmd
#define eMMC_CMD_36 36   // ERASE_GROUP_END cmd
#define eMMC_CMD_38 38   // ERASE cmd

#define eMMC_CMD_42 42   // LOCK_UNLOCK




#define EMMC_DMA_WRITE 	0
#define EMMC_DMA_READ	1
#define EMMC_BOOTMODE_READ	2

#define CMD12_BLK_READ	100
#define CMD12_BLK_WRITE	150


#define ARG_STUFF_BITS	 	0x00000000
#define ARG_IDLE_STATE 		0x00000000
#define ARG_BOOT_STATE		0xFFFFFFFA
#define ARG_PRE_IDLE_STATE  0xF0F0F0F0
#define ARG_CMD1_LT_2GB		0x00FF8080
#define ARG_CMD1_GT_2GB 	0x40FF8080
#define ARG_HSPEED_SDR		0x03B90100
#define ARG_BK_COMP_INT_TIM	0x03B90000
#define ARG_BUSWIDTH_1		0x03B70000
#define ARG_BUSWIDTH_8		0x03B70200
#define ARG_BLK_LEN_512		512 		// Length In Bytes
#define ARG_BLK_LEN_4096	4096 		// Length In Bytes
#define ARG_SING_BLK_ADDR	0x00000B00 	// Address
#define ARG_MUL_BLK_ADDR	0x00000B00 	// Address
#define ARG_BOOT_1_ACCESS	0x03B34100  // Write and read access for Boot 1 with ACK enabled
#define ARG_BOOT_2_ACCESS	0x03B34200  // Write and read access for Boot 2 with ACK enabled
#define ARG_BOOT_USER_AREA	0x03B37800
#define ARG_BOOT_AREA_1		0x03B34800	//0x03B34800 if ACK is enabled in DUT Bus Width 1
#define ARG_BOOT_AREA_1_NO_ACK		0x03B30800	//0x03B34800 if ACK is DISABLED in DUT Bus Width 1

#define ARG_BOOT_AREA_2		0x03B35000	//0x03B35000 if ACK is enabled in DUT Bus Width 1
#define ARG_USER_AREA		0x03B37800	//0x03B34800 if ACK is enabled in DUT

#define ARG_BOOT_BUS_W1		0x03B10000	//0x03B10000 if ACK is enabled in DUT Bus Width 1
#define ARG_BOOT_BUS_W8		0x03B10200	//0x03B10200 if ACK is enabled in DUT Bus Width 8



//#define BOOT_1_DATA			(UL)0x0000000075000000
//#define BOOT_1_DATA			(UL)0xFFFFFFFFFFFFFFFF
#define BOOT_1_DATA			    (UL)0x0000000075000000

#define BOOT_2_DATA			(UL)0x0000000096000000
#define WRITE_DATA			(UL)0x1234567812345600

#define ACCESS_AREA_1		1
#define ACCESS_AREA_2		2

#define FRM_BOOT_AREA_1		1
#define FRM_BOOT_AREA_2		2
#define FRM_USER_AREA		3



#define TEST_PATT_WIDTH_1	0x01
#define TEST_PATT_WIDTH_8	0xAA55



#define OP_FREQ_400KHz	0
#define OP_FREQ_25MHz	1
#define OP_FREQ_50MHz	2



#define DBUS_WIDTH_1_BIT	0
#define DBUS_WIDTH_4_BIT	1
#define DBUS_WIDTH_8_BIT	2

#define BCAST_CMD		0 //bc
#define BCAST_CMD_RESP	1 //bcr
#define ADDRD_CMD		2 //ac
#define ADDRD_CMD_RESP	3 //adtc

//Command Response types
#define CMD_NO_RESP						0  // No response
#define CMD_RESP_LEN_48					1  // R1,R3,R5 (48  BIT RESPONSE)
#define CMD_RESP_LEN_48_WITH_BUSY		2  // R1b (48  BIT RESPONSE WITH BUSY)
#define CMD_RESP_LEN_136				3  // R2 (136 BIT)


#define 	DEV_BUSY		  			((UL)1 << 0)
#define 	CMD_SENT 		  			((UL)1 << 1)
#define 	CMD_RESP_RCVD				((UL)1 << 2)
#define 	RSVD_0						((UL)1 << 3)
#define 	NR_WR_BLK_TXD				((UL)1 << 5)
#define 	MUL_BLK_WR_CMPLT			((UL)1 << 13)
#define 	MUL_BLK_RD_CMPLT			((UL)1 << 14)
#define 	RD_BLK_RXD					((UL)1 << 15)
#define 	SIN_BLK_WR_CMPLT			((UL)1 << 23)
#define 	CRC7_ERR_RESP				((UL)1 << 24)
#define 	CRC16_ERR_RESP				((UL)1 << 25)
#define 	CMD_RESP_TOUT_ERR			((UL)1 << 26)
#define 	WR_TOUT_ERR					((UL)1 << 27)
#define 	RD_TOUT_ERR					((UL)1 << 28)
#define 	SIN_BLK_RD_CMPLT			((UL)1 << 29)
#define 	BLK_RCVD					((UL)1 << 30)
#define 	CMD_RESP_TX_BIT_ERR 		((UL)1 << 31)
#define 	CMD_RESP_END_BIT_ERR		((UL)1 << 32)
#define 	RD_DATA_BLK_END_BIT_ERR		((UL)1 << 33)
#define 	RD_DATA_FIFO_FULL			((UL)1 << 34)
#define 	RD_DATA_FIFO_EMPTY			((UL)1 << 35)
#define 	WR_DATA_FIFO_FULL			((UL)1 << 36)
#define 	WR_DATA_FIFO_EMPTY			((UL)1 << 37)
#define 	RD_FIFO_FULL_ERR			((UL)1 << 38)
#define 	BOOT_FIFO_FULL				((UL)1 << 39)
#define 	BOOT_FIFO_EMPTY				((UL)1 << 40)
#define 	NR_BLK_RXD_IN_BOOT_FIFO		((UL)1 << 41)
#define 	TEST_PATT_SENT				((UL)1 << 57)
#define 	TEST_PATT_RESP_RXD			((UL)1 << 58)
#define 	CSD_PGM_BIT_SENT			((UL)1 << 59)
#define 	WR_PR_STATUS_RXD			((UL)1 << 60)
#define 	WR_PR_TYPE_RXD				((UL)1 << 61)
#define 	CMD0_WITH_ARG0_SENT			((UL)1 << 62)
#define 	BOOT_1_BLK_AVL				((UL)1 << 63)

//EMMC INTR EN & INTR STATUS BITS

#define 	CMD_CPLT_INTR			((UL)1 << 0)
#define 	CMD_SENT_INTR			((UL)1 << 1)
#define 	CMD_RESP_RXD_INTR		((UL)1 << 2)
#define 	SIN_BLK_WR_CPLT_INTR		((UL)1 << 3)
#define 	SIN_BLK_RD_CPLT_INTR		((UL)1 << 4)
#define 	ONE_BLK_AVL_RDFIFO_INTR	((UL)1 << 5) // Read Fifo
#define 	ONE_BLK_AVL_BTFIFO_INTR	((UL)1 << 6) // Boot Fifo
#define 	MUL_BLK_RD_CPLT_INTR		((UL)1 << 7)
#define 	MUL_BLK_WR_CPLT_INTR		((UL)1 << 8)
#define 	CRC7_ERR_INTR			((UL)1 << 9)
#define 	CRC16_ERR_INTR			((UL)1 << 10)
#define 	CMD_RESP_TOUT_ERR_INTR	((UL)1 << 11)
#define 	WR_TRANS_TOUT_ERR_INTR	((UL)1 << 12)
#define 	RD_TRANS_TOUT_ERR_INTR	((UL)1 << 13)
#define 	CMD_RESP_EBIT_ERR_INTR	((UL)1 << 14) // end bit
#define 	DATA_RESP_EBIT_ERR_INTR	((UL)1 << 15) // end bit
#define 	RD_DATA_FIFO_FULL_INTR	((UL)1 << 16)
#define 	WR_DATA_FIFO_FULL_INTR	((UL)1 << 17)
#define 	BOOT_DATA_FIFO_FULL_INTR	((UL)1 << 18)
#define 	WR_BLK_TXD_INTR			((UL)1 << 19)
#define 	RD_BLK_RXD_INTR			((UL)1 << 20)
#define 	BOOT_BLK_RXD_INTR		((UL)1 << 21)
#define 	TEST_PATT_SENT_INTR		((UL)1 << 22)
#define 	TEST_PATT_RXD_INTR		((UL)1 << 23)
#define 	BOOT_ACK_ERR_INTR		((UL)1 << 24)
#define 	NO_BLK_AVL_R_FIFO_INTR	((UL)1 << 25) // No of blocks available in Read FIFO
#define 	NO_BLK_AVL_B_FIFO_INTR	((UL)1 << 26) // No of blocks available in Read FIFO
#define 	EIGHT_FRAME_SPACE_AVL_INTR		((UL)1 << 27)







#define 	EHC_BASE_ADDRESS			  0x20040000

#define EHC_STATUS_REG                (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x00)))
#define EHC_LWR_RESP_REG          	  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x08)))
#define EHC_UPR_RESP_REG          	  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x10)))
#define EHC_CMD_REG                   (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x18)))
#define EHC_OPR_MODE_REG       		  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x20)))
#define EHC_OPR_FREQ_REG			  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x28)))
#define EHC_RESP_TOUT_REG             (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x30)))
#define EHC_WR_TRANS_TOUT_REG         (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x38)))
#define EHC_RD_TRANS_TOUT_REG         (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x40)))

#define EHC_RSVD_REG 		          (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x48)))

#define EHC_LWR_CSD_REG          	  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x50)))
#define EHC_UPR_CSD_REG          	  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x58)))
#define EHC_WR_TEST_REG          	  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x60)))
#define EHC_RD_TEST_REG          	  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x68)))
#define EHC_WR_PROT_REG          	  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x70)))
#define EHC_WR_PROT_TYPE_REG          (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x78)))

#define EHC_INTR_EN_REG          	  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x80)))
#define EHC_INTR_STATUS_REG           (*(( volatile UL * )(EHC_BASE_ADDRESS + 0x88)))

#define EHC_BOOT_FIFO          		  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0xD0)))
//#define EHC_RD_DATA_FIFO          	  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0xD0))) // Boot fifo and Read Data fifo are same.
#define EHC_WR_DATA_FIFO          	  (*(( volatile UL * )(EHC_BASE_ADDRESS + 0xF0)))

// EMMC Function Declarations

void eMMC_Reset_Global_Var(void);
UL eMMC_Chk_Status_Reg(UL bChkStatus);
UL eMMC_Read_Response(UC bCommand);
void eMMC_Validate_Command_Response(UC bCommand);
void eMMC_Primary_Init_HostController(void);
void eMMC_Secondary_Init_HostController(void);
void eMMC_Send_Command(UC bCommand,UI wCmdArg, UC bCmdType, UC bCmdResp);
void eMMC_BusWidthTest(UL testval);
void eMMC_ReadBootData(void);
void eMMC_AlternateReadBootData(void);
void eMMC_Initialize_Device(void);
void eMMC_Set_Operating_Frequency(UL wFreq);
UC eMMC_Nr_WriteBlocks_Txd(void);
UC eMMC_Nr_ReadBlocks_Rxd(void);
void eMMC_DisplayReadData(UI noOfBlks);
void eMMC_DisplayExtCSDdata(UI noOfBlks);
UC eMMC_Read_Single_Block(UI noOfBlks);
UC eMMC_Read_Multi_Block(UI noOfBlks);
UC eMMC_Write_Single_Block(UI noOfBlks);
void eMMC_ChkReadDataErr(void);
void eMMC_Chk_Data_Transfer_Error(void);
UC eMMC_Write_Multi_Block(UI noOfBlks);
UC eMMC_Write_Multi_Block_modified(void);
UC eMMC_Read_Multi_Block_modified(void);
void eMMC_ReadEXTCSD_data(void);
UC eMMC_EraseBlockData(void);
void eMMC_Read_EXTCSDReg(void);

#endif /*EMMC_H_*/
