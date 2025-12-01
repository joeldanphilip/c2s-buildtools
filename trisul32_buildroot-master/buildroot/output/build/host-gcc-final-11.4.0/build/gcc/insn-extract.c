/* Generated automatically by the program `genextract'
   from the machine description file `md'.  */

#define IN_TARGET_CODE 1
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "insn-config.h"
#include "recog.h"
#include "diagnostic-core.h"

/* This variable is used as the "location" of any missing operand
   whose numbers are skipped by a given pattern.  */
static rtx junk ATTRIBUTE_UNUSED;

void
insn_extract (rtx_insn *insn)
{
  rtx *ro = recog_data.operand;
  rtx **ro_loc = recog_data.operand_loc;
  rtx pat = PATTERN (insn);
  int i ATTRIBUTE_UNUSED; /* only for peepholes */

  if (flag_checking)
    {
      memset (ro, 0xab, sizeof (*ro) * MAX_RECOG_OPERANDS);
      memset (ro_loc, 0xab, sizeof (*ro_loc) * MAX_RECOG_OPERANDS);
    }

  switch (INSN_CODE (insn))
    {
    default:
      /* Control reaches here if insn_extract has been called with an
         unrecognizable insn (code -1), or an insn whose INSN_CODE
         corresponds to a DEFINE_EXPAND in the machine description;
         either way, a bug.  */
      if (INSN_CODE (insn) < 0)
        fatal_insn ("unrecognizable insn:", insn);
      else
        fatal_insn ("insn with invalid code number:", insn);

    case 345:  /* *local_pic_store_sfdf */
    case 344:  /* *local_pic_store_sfsf */
    case 343:  /* *local_pic_store_sfdf */
    case 342:  /* *local_pic_store_sfsf */
    case 337:  /* *local_pic_storedf */
    case 336:  /* *local_pic_storesf */
    case 335:  /* *local_pic_storedf */
    case 334:  /* *local_pic_storesf */
    case 333:  /* *local_pic_storedi */
    case 332:  /* *local_pic_storesi */
    case 331:  /* *local_pic_storehi */
    case 330:  /* *local_pic_storeqi */
    case 329:  /* *local_pic_storedi */
    case 328:  /* *local_pic_storesi */
    case 327:  /* *local_pic_storehi */
    case 326:  /* *local_pic_storeqi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 341:  /* *local_pic_store_32ddf */
    case 340:  /* *local_pic_store_32dsf */
    case 339:  /* *local_pic_store_32ddf */
    case 338:  /* *local_pic_store_32dsf */
    case 323:  /* *local_pic_load_32ddf */
    case 322:  /* *local_pic_load_32dsf */
    case 321:  /* *local_pic_load_32ddf */
    case 320:  /* *local_pic_load_32dsf */
    case 319:  /* *local_pic_loaddf */
    case 318:  /* *local_pic_loadsf */
    case 317:  /* *local_pic_loaddf */
    case 316:  /* *local_pic_loadsf */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 293:  /* atomic_cas_value_strongdi */
    case 292:  /* atomic_cas_value_strongsi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XEXP (XVECEXP (pat, 0, 2), 0));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 291:  /* atomic_exchangedi */
    case 290:  /* atomic_exchangesi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 289:  /* atomic_fetch_anddi */
    case 288:  /* atomic_fetch_xordi */
    case 287:  /* atomic_fetch_ordi */
    case 286:  /* atomic_fetch_adddi */
    case 285:  /* atomic_fetch_andsi */
    case 284:  /* atomic_fetch_xorsi */
    case 283:  /* atomic_fetch_orsi */
    case 282:  /* atomic_fetch_addsi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0), 0);
      recog_data.dup_num[1] = 1;
      break;

    case 281:  /* atomic_anddi */
    case 280:  /* atomic_xordi */
    case 279:  /* atomic_ordi */
    case 278:  /* atomic_adddi */
    case 277:  /* atomic_andsi */
    case 276:  /* atomic_xorsi */
    case 275:  /* atomic_orsi */
    case 274:  /* atomic_addsi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 0);
      recog_data.dup_num[0] = 0;
      break;

    case 271:  /* mem_thread_fence_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (pat, 0, 1));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0);
      recog_data.dup_num[0] = 0;
      break;

    case 268:  /* stack_protect_set_di */
    case 267:  /* stack_protect_set_si */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 266:  /* stack_tiedi */
    case 265:  /* stack_tiesi */
      ro[0] = *(ro_loc[0] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 1));
      break;

    case 260:  /* riscv_frflags */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      break;

    case 261:  /* riscv_fsflags */
    case 258:  /* gpr_restore */
      ro[0] = *(ro_loc[0] = &XVECEXP (pat, 0, 0));
      break;

    case 257:  /* gpr_save */
      ro[0] = *(ro_loc[0] = &XVECEXP (XVECEXP (pat, 0, 0), 0, 0));
      ro[1] = *(ro_loc[1] = &PATTERN (insn));
      break;

    case 254:  /* call_value_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 253:  /* call_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      break;

    case 252:  /* sibcall_value_internal */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 251:  /* sibcall_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (pat, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (pat, 1));
      break;

    case 249:  /* eh_set_lr_di */
    case 248:  /* eh_set_lr_si */
      ro[0] = *(ro_loc[0] = &XVECEXP (XVECEXP (pat, 0, 0), 0, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 259:  /* gpr_restore_return */
    case 247:  /* simple_return_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 244:  /* tablejumpdi */
    case 243:  /* tablejumpsi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 1));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 0), 0));
      break;

    case 242:  /* indirect_jumpdi */
    case 241:  /* indirect_jumpsi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 1));
      break;

    case 240:  /* jump */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 270:  /* stack_protect_test_di */
    case 269:  /* stack_protect_test_si */
    case 209:  /* *fle_quietdfdi4_snan */
    case 208:  /* *flt_quietdfdi4_snan */
    case 207:  /* *fle_quietdfsi4_snan */
    case 206:  /* *flt_quietdfsi4_snan */
    case 205:  /* *fle_quietsfdi4_snan */
    case 204:  /* *flt_quietsfdi4_snan */
    case 203:  /* *fle_quietsfsi4_snan */
    case 202:  /* *flt_quietsfsi4_snan */
    case 201:  /* *fle_quietdfdi4_default */
    case 200:  /* *flt_quietdfdi4_default */
    case 199:  /* *fle_quietdfsi4_default */
    case 198:  /* *flt_quietdfsi4_default */
    case 197:  /* *fle_quietsfdi4_default */
    case 196:  /* *flt_quietsfdi4_default */
    case 195:  /* *fle_quietsfsi4_default */
    case 194:  /* *flt_quietsfsi4_default */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 193:  /* *cstoredfdi4 */
    case 192:  /* *cstoredfsi4 */
    case 191:  /* *cstoresfdi4 */
    case 190:  /* *cstoresfsi4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (pat, 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 189:  /* *branch_on_bit_rangedi */
    case 188:  /* *branch_on_bit_rangesi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 187:  /* *branch_on_bitdi */
    case 186:  /* *branch_on_bitsi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 185:  /* *movdidicc */
    case 184:  /* *movsidicc */
    case 183:  /* *movsisicc */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 182:  /* *branchdi */
    case 181:  /* *branchsi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      break;

    case 180:  /* zero_extendsidi2_shifted */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 176:  /* *lshrsi3_extend_mask_1 */
    case 175:  /* *ashrsi3_extend_mask_1 */
    case 174:  /* *ashlsi3_extend_mask_1 */
    case 173:  /* *lshrsi3_extend_mask */
    case 172:  /* *ashrsi3_extend_mask */
    case 171:  /* *ashlsi3_extend_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      break;

    case 167:  /* *lshrdi3_mask_1 */
    case 166:  /* *ashrdi3_mask_1 */
    case 165:  /* *ashldi3_mask_1 */
    case 164:  /* *lshrdi3_mask */
    case 163:  /* *ashrdi3_mask */
    case 162:  /* *ashldi3_mask */
    case 158:  /* *lshrsi3_mask_1 */
    case 157:  /* *ashrsi3_mask_1 */
    case 156:  /* *ashlsi3_mask_1 */
    case 155:  /* *lshrsi3_mask */
    case 154:  /* *ashrsi3_mask */
    case 153:  /* *ashlsi3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 264:  /* riscv_uret */
    case 263:  /* riscv_sret */
    case 262:  /* riscv_mret */
    case 256:  /* trap */
    case 255:  /* nop */
    case 250:  /* eh_return_internal */
    case 246:  /* simple_return */
    case 245:  /* blockage */
    case 149:  /* fence_i */
    case 148:  /* fence */
      break;

    case 147:  /* *movdf_softfloat */
    case 146:  /* *movdf_hardfloat_rv64 */
    case 145:  /* *movdf_hardfloat_rv32 */
    case 144:  /* *movsf_softfloat */
    case 143:  /* *movsf_hardfloat */
    case 142:  /* *movqi_internal */
    case 137:  /* *movhi_internal */
    case 136:  /* *movsi_internal */
    case 135:  /* *movdi_64bit */
    case 134:  /* *movdi_32bit */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (pat, 1));
      break;

    case 125:  /* tls_add_tp_ledi */
    case 124:  /* tls_add_tp_lesi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (pat, 1), 0, 2));
      break;

    case 129:  /* got_load_tls_iedi */
    case 128:  /* got_load_tls_iesi */
    case 127:  /* got_load_tls_gddi */
    case 126:  /* got_load_tls_gdsi */
    case 123:  /* got_loaddi */
    case 122:  /* got_loadsi */
    case 121:  /* lrounddfdi2 */
    case 120:  /* lrintdfdi2 */
    case 119:  /* lrounddfsi2 */
    case 118:  /* lrintdfsi2 */
    case 117:  /* lroundsfdi2 */
    case 116:  /* lrintsfdi2 */
    case 115:  /* lroundsfsi2 */
    case 114:  /* lrintsfsi2 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      break;

    case 273:  /* atomic_storedi */
    case 272:  /* atomic_storesi */
    case 131:  /* auipcdi */
    case 130:  /* auipcsi */
    case 64:  /* copysigndf3 */
    case 63:  /* copysignsf3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      break;

    case 60:  /* *fnmadf4 */
    case 59:  /* *fnmasf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      break;

    case 58:  /* *fnmsdf4 */
    case 57:  /* *fnmssf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      break;

    case 56:  /* *fmsdf4 */
    case 55:  /* *fmssf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      break;

    case 54:  /* *fmadf4 */
    case 53:  /* *fmasf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      break;

    case 52:  /* fnmadf4 */
    case 51:  /* fnmasf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 50:  /* fnmsdf4 */
    case 49:  /* fnmssf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 2), 0));
      break;

    case 48:  /* fmsdf4 */
    case 47:  /* fmssf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 2), 0));
      break;

    case 178:  /* *lshrsi3_zero_extend_2 */
    case 46:  /* fmadf4 */
    case 45:  /* fmasf4 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 28:  /* usmulsi3_highpart */
    case 27:  /* umulsi3_highpart */
    case 26:  /* mulsi3_highpart */
    case 25:  /* usmuldi3_highpart */
    case 24:  /* umuldi3_highpart */
    case 23:  /* muldi3_highpart */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0));
      break;

    case 16:  /* *negsi2_extended2 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 315:  /* *local_pic_load_usi */
    case 314:  /* *local_pic_load_usi */
    case 313:  /* *local_pic_load_usi */
    case 312:  /* *local_pic_load_uhi */
    case 311:  /* *local_pic_load_uhi */
    case 310:  /* *local_pic_load_uhi */
    case 309:  /* *local_pic_load_uqi */
    case 308:  /* *local_pic_load_uqi */
    case 307:  /* *local_pic_load_uqi */
    case 306:  /* *local_pic_load_ssi */
    case 305:  /* *local_pic_load_ssi */
    case 304:  /* *local_pic_load_ssi */
    case 303:  /* *local_pic_load_shi */
    case 302:  /* *local_pic_load_shi */
    case 301:  /* *local_pic_load_shi */
    case 300:  /* *local_pic_load_sqi */
    case 299:  /* *local_pic_load_sqi */
    case 298:  /* *local_pic_load_sqi */
    case 15:  /* *negsi2_extended */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      break;

    case 325:  /* *local_pic_load_sfdf */
    case 324:  /* *local_pic_load_sfsf */
    case 297:  /* *local_pic_loaddi */
    case 296:  /* *local_pic_loadsi */
    case 295:  /* *local_pic_loadhi */
    case 294:  /* *local_pic_loadqi */
    case 227:  /* *sgeu_didi */
    case 226:  /* *sge_didi */
    case 225:  /* *sgeu_disi */
    case 224:  /* *sge_disi */
    case 223:  /* *sgeu_sisi */
    case 222:  /* *sge_sisi */
    case 215:  /* *sne_zero_didi */
    case 214:  /* *sne_zero_disi */
    case 213:  /* *sne_zero_sisi */
    case 212:  /* *seq_zero_didi */
    case 211:  /* *seq_zero_disi */
    case 210:  /* *seq_zero_sisi */
    case 179:  /* *lshrsi3_zero_extend_3 */
    case 113:  /* floatunsdidf2 */
    case 112:  /* floatunssidf2 */
    case 111:  /* floatunsdisf2 */
    case 110:  /* floatunssisf2 */
    case 109:  /* floatdidf2 */
    case 108:  /* floatsidf2 */
    case 107:  /* floatdisf2 */
    case 106:  /* floatsisf2 */
    case 105:  /* fixuns_truncdfdi2 */
    case 104:  /* fixuns_truncdfsi2 */
    case 103:  /* fixuns_truncsfdi2 */
    case 102:  /* fixuns_truncsfsi2 */
    case 101:  /* fix_truncdfdi2 */
    case 100:  /* fix_truncdfsi2 */
    case 99:  /* fix_truncsfdi2 */
    case 98:  /* fix_truncsfsi2 */
    case 97:  /* extendsfdf2 */
    case 96:  /* extendhidi2 */
    case 95:  /* extendhisi2 */
    case 94:  /* extendhihi2 */
    case 93:  /* extendqidi2 */
    case 92:  /* extendqisi2 */
    case 91:  /* extendqihi2 */
    case 90:  /* extendsidi2 */
    case 89:  /* zero_extendqidi2 */
    case 88:  /* zero_extendqisi2 */
    case 87:  /* zero_extendqihi2 */
    case 86:  /* zero_extendhidi2 */
    case 85:  /* zero_extendhisi2 */
    case 84:  /* zero_extendsidi2 */
    case 83:  /* truncdfsf2 */
    case 82:  /* *one_cmplsi2_internal */
    case 81:  /* one_cmpldi2 */
    case 80:  /* one_cmplsi2 */
    case 66:  /* negdf2 */
    case 65:  /* negsf2 */
    case 62:  /* absdf2 */
    case 61:  /* abssf2 */
    case 44:  /* sqrtdf2 */
    case 43:  /* sqrtsf2 */
    case 14:  /* negsi2 */
    case 13:  /* negdi2 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 22:  /* *mulsi3_extended2 */
    case 12:  /* *subsi3_extended2 */
    case 6:  /* *addsi3_extended2 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 177:  /* *lshrsi3_zero_extend_1 */
    case 170:  /* *lshrsi3_extend */
    case 169:  /* *ashrsi3_extend */
    case 168:  /* *ashlsi3_extend */
    case 40:  /* *umodsi3_extended */
    case 39:  /* *modsi3_extended */
    case 38:  /* *udivsi3_extended */
    case 37:  /* *divsi3_extended */
    case 21:  /* *mulsi3_extended */
    case 11:  /* *subsi3_extended */
    case 5:  /* *addsi3_extended */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      break;

    case 239:  /* *sleu_didi */
    case 238:  /* *sle_didi */
    case 237:  /* *sleu_disi */
    case 236:  /* *sle_disi */
    case 235:  /* *sleu_sisi */
    case 234:  /* *sle_sisi */
    case 233:  /* *sltu_didi */
    case 232:  /* *slt_didi */
    case 231:  /* *sltu_disi */
    case 230:  /* *slt_disi */
    case 229:  /* *sltu_sisi */
    case 228:  /* *slt_sisi */
    case 221:  /* *sgtu_didi */
    case 220:  /* *sgt_didi */
    case 219:  /* *sgtu_disi */
    case 218:  /* *sgt_disi */
    case 217:  /* *sgtu_sisi */
    case 216:  /* *sgt_sisi */
    case 161:  /* lshrdi3 */
    case 160:  /* ashrdi3 */
    case 159:  /* ashldi3 */
    case 152:  /* lshrsi3 */
    case 151:  /* ashrsi3 */
    case 150:  /* ashlsi3 */
    case 141:  /* *xorsihi3 */
    case 140:  /* *xorhihi3 */
    case 139:  /* *addsihi3 */
    case 138:  /* *addhihi3 */
    case 133:  /* *lowdi */
    case 132:  /* *lowsi */
    case 79:  /* *xorsi3_internal */
    case 78:  /* *iorsi3_internal */
    case 77:  /* *andsi3_internal */
    case 76:  /* xordi3 */
    case 75:  /* iordi3 */
    case 74:  /* anddi3 */
    case 73:  /* xorsi3 */
    case 72:  /* iorsi3 */
    case 71:  /* andsi3 */
    case 70:  /* smaxdf3 */
    case 69:  /* smaxsf3 */
    case 68:  /* smindf3 */
    case 67:  /* sminsf3 */
    case 42:  /* divdf3 */
    case 41:  /* divsf3 */
    case 36:  /* umoddi3 */
    case 35:  /* moddi3 */
    case 34:  /* udivdi3 */
    case 33:  /* divdi3 */
    case 32:  /* umodsi3 */
    case 31:  /* modsi3 */
    case 30:  /* udivsi3 */
    case 29:  /* divsi3 */
    case 20:  /* muldi3 */
    case 19:  /* mulsi3 */
    case 18:  /* muldf3 */
    case 17:  /* mulsf3 */
    case 10:  /* subsi3 */
    case 9:  /* subdi3 */
    case 8:  /* subdf3 */
    case 7:  /* subsf3 */
    case 4:  /* adddi3 */
    case 3:  /* addsi3 */
    case 2:  /* adddf3 */
    case 1:  /* addsf3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      break;

    }
}
