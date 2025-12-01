/*
 * globals.h
 *
 *  Created on: 10-Mar-2020
 *      Author: hdg
 */

#ifndef INCLUDE_GLOBALS_H_
#define INCLUDE_GLOBALS_H_

#include "cdac_dmac.h"
#include "cdac_datatype.h"


//#define SINGLE_CORE_EMMC

#define DUAL_CORE_EMMC

#define ENABLE_EMMC_PLIC


//#define DISP_EMMC_LOG


//DMAC_PERIPH_GBL_VAR_BEGINS
//DMAC-SRAM-SRAM
extern volatile UC gReadCompareFlag,gCMD12ReadDone;
extern  DMAtransfer_Type gDMAtransfer;
extern volatile UL gDMATestNumber,gDataWidth,gDst_addr,gSrc_addr, gxFactor;
extern volatile UC g_sdw, g_ddw,g_adj,gReadStatusOnce,gNormalTest;
//extern volatile ch0_trans_done,ch1_trans_done,ch2_trans_done,ch3_trans_done;
extern volatile int gTransferDone;
extern volatile UL gSImulDestAddr1,gSImulDestAddr2,gSImulDestAddr3,gSImulDestAddr4,gSImulDestAddr5,gSImulDestAddr6,gSImulDestAddr7,gSImulDestAddr8;
extern volatile UC gLLI_dataCompare,gN_LLI_N_flag;
extern volatile UL gLLIDestAddr;
extern volatile UC gch0_test5,gch0_test6,gch0_test7,gch0_test8;
extern volatile UL glli0_address,glli1_address,glli2_address,glli3_address;
extern volatile UC gDMAC_Intr_generated;
extern volatile UC d8_flg,d9_flg,d10_flg,d11_flg,d12_flg,d13_flg,d14_flg,d15_flg,d16_flg,d17_flg,d18_flg;
extern volatile UC gAddrMisalignErr,gSlaveResponseErr,gConfigErr,gSRC_SlaveErr_test,gDST_SlaveErr_test,gSimulCase,gNormalCase;
//DMAC-SRAM-SRAM
//DMAC_PERIPH_GBL_VAR_ENDS




//#define SIMULATE

//#define   EMMC_ALTERNATE_BOOT_MODE  // Makes cmd line to ZERO

//#define EMMC_READ_EXT_CSD_REG // using command 8


#define WRITE_DATA 0x11
#define READ_DATA 	WRITE_DATA
#define MUL_BLK_NUM 0xFFFF



#define write_csr(reg, val) ({ \
  asm volatile ("csrw " #reg ", %0" :: "rK"(val)); })

extern volatile UL gread_cycle_start, ginst_retired_start;
extern volatile UL gread_cycle_end, ginst_retired_end;
extern volatile UL gEmmcIntrEnReg,gEmmcIntrStatusReg,gwTempCtrlRegVal,gWrData,gEmmcIntrBits;
extern volatile UL greadcyc_diff, ginst_retired_diff,gips,gTempCount;
extern volatile UC gSDHC_Plic_Mode;


extern volatile UC gIntr_id,gCMD_1_sent,gCRC7_err;


extern volatile UC gBusWidthTest_1,gBusWidthTest_8,gTestBootAccess,\
gTestAlternateBootMode,gWriteSingleBlk,gReadSingleBlk,gReadMultiBlk,gWriteMultiBlk,gReadExtCSDReg,gErrResp,\
gSetBusWidth_8,gSetBusWidth_1,gEmmcEraseBlkData,gIssueCMD12,gCMD12Sent,gExtCSDRegRead,gOCRdisplay,gCIDdisplay,gCSDdisplay,\
gBootBusWidth_1,gBootBusWidth_8,gErrRecover,gMuLBlkReadIntr,gSetPassWord,gUnlockDevice,gPassLen,gPassword[16],g8FrameSpaceAvlIntrEn,gTransfer8Frames,gEmmcStopClkEn;


extern volatile UI gNoBootBlk,gWriteSinBlkAddr,gReadSinBlkAddr,gWriteMulBlkAddr,gReadMulBlkAddr,gDMAFrameCount,gTTempCount,gNoOfBlkToRead,wgNoOfBlks;
extern volatile UC gCmdLineLowBoot,gBootData,gDMASingleBlkRead,gDispDevReg,gCmdCheck,gBootBlkReadErr,gCMD25sentFlg;
extern volatile US gDMA_cts;

extern volatile UC gBootData_400khz,gBootData_50Mhz,CmdLineLowBoot,gSkip,gTest,gtrsfrComplete;






#endif /* INCLUDE_GLOBALS_H_ */
