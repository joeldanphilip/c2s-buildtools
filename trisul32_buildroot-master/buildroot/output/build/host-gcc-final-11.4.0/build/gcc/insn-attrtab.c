/* Generated automatically by the program `genattrtab'
   from the machine description file `md'.  */

#define IN_TARGET_CODE 1
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "predict.h"
#include "tree.h"
#include "rtl.h"
#include "alias.h"
#include "options.h"
#include "varasm.h"
#include "stor-layout.h"
#include "calls.h"
#include "insn-attr.h"
#include "memmodel.h"
#include "tm_p.h"
#include "insn-config.h"
#include "recog.h"
#include "regs.h"
#include "real.h"
#include "output.h"
#include "toplev.h"
#include "flags.h"
#include "emit-rtl.h"

#define operands recog_data.operand

int
insn_current_length (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;
  enum attr_move_type cached_move_type ATTRIBUTE_UNUSED;
  enum attr_dword_mode cached_dword_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 182:  /* *branchdi */
    case 181:  /* *branchsi */
      extract_insn_cached (insn);
      if ((((INSN_ADDRESSES_SET_P () ? INSN_ADDRESSES (INSN_UID (GET_CODE (operands[0]) == LABEL_REF ? XEXP (operands[0], 0) : operands[0])) : 0) - (insn_current_reference_address (insn))) <= (4088)) && (((insn_current_reference_address (insn)) - (INSN_ADDRESSES_SET_P () ? INSN_ADDRESSES (INSN_UID (GET_CODE (operands[0]) == LABEL_REF ? XEXP (operands[0], 0) : operands[0])) : 0)) <= (4092)))
        {
	  return 4;
        }
      else
        {
	  return 8;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
      extract_insn_cached (insn);
      if (get_attr_type (insn) == TYPE_BRANCH)
        {
	  if ((((INSN_ADDRESSES_SET_P () ? INSN_ADDRESSES (INSN_UID (GET_CODE (operands[0]) == LABEL_REF ? XEXP (operands[0], 0) : operands[0])) : 0) - (insn_current_reference_address (insn))) <= (4088)) && (((insn_current_reference_address (insn)) - (INSN_ADDRESSES_SET_P () ? INSN_ADDRESSES (INSN_UID (GET_CODE (operands[0]) == LABEL_REF ? XEXP (operands[0], 0) : operands[0])) : 0)) <= (4092)))
	    {
	      return 4;
	    }
	  else
	    {
	      return 8;
	    }
        }
      else
        {
	  return 0;
        }

    default:
      return 0;

    }
}

int
insn_variable_length_p (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;
  enum attr_move_type cached_move_type ATTRIBUTE_UNUSED;
  enum attr_dword_mode cached_dword_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 182:  /* *branchdi */
    case 181:  /* *branchsi */
      return 1;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
      if (get_attr_type (insn) == TYPE_BRANCH)
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

    default:
      return 0;

    }
}

int
insn_min_length (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;
  enum attr_move_type cached_move_type ATTRIBUTE_UNUSED;
  enum attr_dword_mode cached_dword_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 147:  /* *movdf_softfloat */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (which_alternative == 1)
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x3ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 146:  /* *movdf_hardfloat_rv64 */
      extract_constrain_insn_cached (insn);
      if ((((1ULL << which_alternative) & 0xe2ULL)) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (((1ULL << which_alternative) & 0x104ULL))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x1e7ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 145:  /* *movdf_hardfloat_rv32 */
      extract_constrain_insn_cached (insn);
      if ((((1ULL << which_alternative) & 0x22ULL)) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (((1ULL << which_alternative) & 0x44ULL))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x67ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 144:  /* *movsf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 1)
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x3ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 143:  /* *movsf_hardfloat */
      extract_constrain_insn_cached (insn);
      if (((1ULL << which_alternative) & 0x104ULL))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x1e7ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 142:  /* *movqi_internal */
    case 137:  /* *movhi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 2)
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (which_alternative == 3)
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 136:  /* *movsi_internal */
      extract_constrain_insn_cached (insn);
      if (((1ULL << which_alternative) & 0x24ULL))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x77ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 135:  /* *movdi_64bit */
    case 134:  /* *movdi_32bit */
      extract_constrain_insn_cached (insn);
      if ((((1ULL << which_alternative) & 0x51ULL)) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if ((which_alternative == 1) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 
#line 239 "../../gcc/config/riscv/riscv.md"
(riscv_split_const_insns (operands[1]) * 4);
        }
      else if (((1ULL << which_alternative) & 0x24ULL))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0xf7ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 90:  /* extendsidi2 */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (which_alternative != 0)
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 89:  /* zero_extendqidi2 */
    case 88:  /* zero_extendqisi2 */
    case 87:  /* zero_extendqihi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 96:  /* extendhidi2 */
    case 95:  /* extendhisi2 */
    case 94:  /* extendhihi2 */
    case 93:  /* extendqidi2 */
    case 92:  /* extendqisi2 */
    case 91:  /* extendqihi2 */
    case 86:  /* zero_extendhidi2 */
    case 85:  /* zero_extendhisi2 */
    case 84:  /* zero_extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return 8;
        }
      else
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }

    case 254:  /* call_value_internal */
    case 253:  /* call_internal */
    case 252:  /* sibcall_value_internal */
    case 251:  /* sibcall_internal */
    case 193:  /* *cstoredfdi4 */
    case 192:  /* *cstoredfsi4 */
    case 191:  /* *cstoresfdi4 */
    case 190:  /* *cstoresfsi4 */
    case 129:  /* got_load_tls_iedi */
    case 128:  /* got_load_tls_iesi */
    case 127:  /* got_load_tls_gddi */
    case 126:  /* got_load_tls_gdsi */
    case 123:  /* got_loaddi */
    case 122:  /* got_loadsi */
    case 345:  /* *local_pic_store_sfdf */
    case 344:  /* *local_pic_store_sfsf */
    case 343:  /* *local_pic_store_sfdf */
    case 342:  /* *local_pic_store_sfsf */
    case 341:  /* *local_pic_store_32ddf */
    case 340:  /* *local_pic_store_32dsf */
    case 339:  /* *local_pic_store_32ddf */
    case 338:  /* *local_pic_store_32dsf */
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
    case 325:  /* *local_pic_load_sfdf */
    case 324:  /* *local_pic_load_sfsf */
    case 323:  /* *local_pic_load_32ddf */
    case 322:  /* *local_pic_load_32dsf */
    case 321:  /* *local_pic_load_32ddf */
    case 320:  /* *local_pic_load_32dsf */
    case 319:  /* *local_pic_loaddf */
    case 318:  /* *local_pic_loadsf */
    case 317:  /* *local_pic_loaddf */
    case 316:  /* *local_pic_loadsf */
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
    case 297:  /* *local_pic_loaddi */
    case 296:  /* *local_pic_loadsi */
    case 295:  /* *local_pic_loadhi */
    case 294:  /* *local_pic_loadqi */
    case 291:  /* atomic_exchangedi */
    case 290:  /* atomic_exchangesi */
    case 289:  /* atomic_fetch_anddi */
    case 288:  /* atomic_fetch_xordi */
    case 287:  /* atomic_fetch_ordi */
    case 286:  /* atomic_fetch_adddi */
    case 285:  /* atomic_fetch_andsi */
    case 284:  /* atomic_fetch_xorsi */
    case 283:  /* atomic_fetch_orsi */
    case 282:  /* atomic_fetch_addsi */
    case 281:  /* atomic_anddi */
    case 280:  /* atomic_xordi */
    case 279:  /* atomic_ordi */
    case 278:  /* atomic_adddi */
    case 277:  /* atomic_andsi */
    case 276:  /* atomic_xorsi */
    case 275:  /* atomic_orsi */
    case 274:  /* atomic_addsi */
    case 273:  /* atomic_storedi */
    case 272:  /* atomic_storesi */
    case 185:  /* *movdidicc */
    case 184:  /* *movsidicc */
    case 183:  /* *movsisicc */
      return 8;

    case 293:  /* atomic_cas_value_strongdi */
    case 292:  /* atomic_cas_value_strongsi */
      return 20 /* 0x14 */;

    case 270:  /* stack_protect_test_di */
    case 269:  /* stack_protect_test_si */
    case 268:  /* stack_protect_set_di */
    case 267:  /* stack_protect_set_si */
    case 201:  /* *fle_quietdfdi4_default */
    case 200:  /* *flt_quietdfdi4_default */
    case 199:  /* *fle_quietdfsi4_default */
    case 198:  /* *flt_quietdfsi4_default */
    case 197:  /* *fle_quietsfdi4_default */
    case 196:  /* *flt_quietsfdi4_default */
    case 195:  /* *fle_quietsfsi4_default */
    case 194:  /* *flt_quietsfsi4_default */
      return 12 /* 0xc */;

    case 245:  /* blockage */
    case 266:  /* stack_tiedi */
    case 265:  /* stack_tiesi */
      return 0;

    case 209:  /* *fle_quietdfdi4_snan */
    case 208:  /* *flt_quietdfdi4_snan */
    case 207:  /* *fle_quietdfsi4_snan */
    case 206:  /* *flt_quietdfsi4_snan */
    case 205:  /* *fle_quietsfdi4_snan */
    case 204:  /* *flt_quietsfdi4_snan */
    case 203:  /* *fle_quietsfsi4_snan */
    case 202:  /* *flt_quietsfsi4_snan */
      return 16 /* 0x10 */;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
      extract_constrain_insn_cached (insn);
      if ((cached_type = get_attr_type (insn)) == TYPE_BRANCH)
        {
	  return 4;
        }
      else if (cached_type == TYPE_CALL)
        {
	  return 8;
        }
      else if (cached_type == TYPE_GHOST)
        {
	  return 0;
        }
      else if (get_attr_got (insn) == GOT_LOAD)
        {
	  return 8;
        }
      else if (cached_type == TYPE_FCMP)
        {
	  return 8;
        }
      else if ((cached_move_type = get_attr_move_type (insn)) == MOVE_TYPE_SHIFT_SHIFT)
        {
	  return 8;
        }
      else if (((cached_move_type == MOVE_TYPE_MTC) || (cached_move_type == MOVE_TYPE_MFC) || (cached_move_type == MOVE_TYPE_MOVE)) && ((cached_dword_mode = get_attr_dword_mode (insn)) == DWORD_MODE_YES))
        {
	  return 8;
        }
      else if ((cached_move_type == MOVE_TYPE_CONST) && ((cached_dword_mode = get_attr_dword_mode (insn)) == DWORD_MODE_YES))
        {
	  return 
#line 239 "../../gcc/config/riscv/riscv.md"
(riscv_split_const_insns (operands[1]) * 4);
        }
      else if ((cached_move_type == MOVE_TYPE_LOAD) || (cached_move_type == MOVE_TYPE_FPLOAD))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if ((cached_move_type == MOVE_TYPE_STORE) || (cached_move_type == MOVE_TYPE_FPSTORE))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    default:
      return 4;

    }
}

int
insn_default_length (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;
  enum attr_move_type cached_move_type ATTRIBUTE_UNUSED;
  enum attr_dword_mode cached_dword_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 147:  /* *movdf_softfloat */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (which_alternative == 1)
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x3ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 146:  /* *movdf_hardfloat_rv64 */
      extract_constrain_insn_cached (insn);
      if ((((1ULL << which_alternative) & 0xe2ULL)) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (((1ULL << which_alternative) & 0x104ULL))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x1e7ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 145:  /* *movdf_hardfloat_rv32 */
      extract_constrain_insn_cached (insn);
      if ((((1ULL << which_alternative) & 0x22ULL)) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (((1ULL << which_alternative) & 0x44ULL))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x67ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 144:  /* *movsf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 1)
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x3ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 143:  /* *movsf_hardfloat */
      extract_constrain_insn_cached (insn);
      if (((1ULL << which_alternative) & 0x104ULL))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x1e7ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 142:  /* *movqi_internal */
    case 137:  /* *movhi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 2)
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (which_alternative == 3)
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 136:  /* *movsi_internal */
      extract_constrain_insn_cached (insn);
      if (((1ULL << which_alternative) & 0x24ULL))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0x77ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 135:  /* *movdi_64bit */
    case 134:  /* *movdi_32bit */
      extract_constrain_insn_cached (insn);
      if ((((1ULL << which_alternative) & 0x51ULL)) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if ((which_alternative == 1) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 
#line 239 "../../gcc/config/riscv/riscv.md"
(riscv_split_const_insns (operands[1]) * 4);
        }
      else if (((1ULL << which_alternative) & 0x24ULL))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if (!((1ULL << which_alternative) & 0xf7ULL))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 90:  /* extendsidi2 */
      extract_constrain_insn_cached (insn);
      if ((which_alternative == 0) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return 8;
        }
      else if (which_alternative != 0)
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 89:  /* zero_extendqidi2 */
    case 88:  /* zero_extendqisi2 */
    case 87:  /* zero_extendqihi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else
        {
	  return 4;
        }

    case 96:  /* extendhidi2 */
    case 95:  /* extendhisi2 */
    case 94:  /* extendhihi2 */
    case 93:  /* extendqidi2 */
    case 92:  /* extendqisi2 */
    case 91:  /* extendqihi2 */
    case 86:  /* zero_extendhidi2 */
    case 85:  /* zero_extendhisi2 */
    case 84:  /* zero_extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return 8;
        }
      else
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }

    case 254:  /* call_value_internal */
    case 253:  /* call_internal */
    case 252:  /* sibcall_value_internal */
    case 251:  /* sibcall_internal */
    case 193:  /* *cstoredfdi4 */
    case 192:  /* *cstoredfsi4 */
    case 191:  /* *cstoresfdi4 */
    case 190:  /* *cstoresfsi4 */
    case 182:  /* *branchdi */
    case 181:  /* *branchsi */
    case 129:  /* got_load_tls_iedi */
    case 128:  /* got_load_tls_iesi */
    case 127:  /* got_load_tls_gddi */
    case 126:  /* got_load_tls_gdsi */
    case 123:  /* got_loaddi */
    case 122:  /* got_loadsi */
    case 345:  /* *local_pic_store_sfdf */
    case 344:  /* *local_pic_store_sfsf */
    case 343:  /* *local_pic_store_sfdf */
    case 342:  /* *local_pic_store_sfsf */
    case 341:  /* *local_pic_store_32ddf */
    case 340:  /* *local_pic_store_32dsf */
    case 339:  /* *local_pic_store_32ddf */
    case 338:  /* *local_pic_store_32dsf */
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
    case 325:  /* *local_pic_load_sfdf */
    case 324:  /* *local_pic_load_sfsf */
    case 323:  /* *local_pic_load_32ddf */
    case 322:  /* *local_pic_load_32dsf */
    case 321:  /* *local_pic_load_32ddf */
    case 320:  /* *local_pic_load_32dsf */
    case 319:  /* *local_pic_loaddf */
    case 318:  /* *local_pic_loadsf */
    case 317:  /* *local_pic_loaddf */
    case 316:  /* *local_pic_loadsf */
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
    case 297:  /* *local_pic_loaddi */
    case 296:  /* *local_pic_loadsi */
    case 295:  /* *local_pic_loadhi */
    case 294:  /* *local_pic_loadqi */
    case 291:  /* atomic_exchangedi */
    case 290:  /* atomic_exchangesi */
    case 289:  /* atomic_fetch_anddi */
    case 288:  /* atomic_fetch_xordi */
    case 287:  /* atomic_fetch_ordi */
    case 286:  /* atomic_fetch_adddi */
    case 285:  /* atomic_fetch_andsi */
    case 284:  /* atomic_fetch_xorsi */
    case 283:  /* atomic_fetch_orsi */
    case 282:  /* atomic_fetch_addsi */
    case 281:  /* atomic_anddi */
    case 280:  /* atomic_xordi */
    case 279:  /* atomic_ordi */
    case 278:  /* atomic_adddi */
    case 277:  /* atomic_andsi */
    case 276:  /* atomic_xorsi */
    case 275:  /* atomic_orsi */
    case 274:  /* atomic_addsi */
    case 273:  /* atomic_storedi */
    case 272:  /* atomic_storesi */
    case 185:  /* *movdidicc */
    case 184:  /* *movsidicc */
    case 183:  /* *movsisicc */
      return 8;

    case 293:  /* atomic_cas_value_strongdi */
    case 292:  /* atomic_cas_value_strongsi */
      return 20 /* 0x14 */;

    case 270:  /* stack_protect_test_di */
    case 269:  /* stack_protect_test_si */
    case 268:  /* stack_protect_set_di */
    case 267:  /* stack_protect_set_si */
    case 201:  /* *fle_quietdfdi4_default */
    case 200:  /* *flt_quietdfdi4_default */
    case 199:  /* *fle_quietdfsi4_default */
    case 198:  /* *flt_quietdfsi4_default */
    case 197:  /* *fle_quietsfdi4_default */
    case 196:  /* *flt_quietsfdi4_default */
    case 195:  /* *fle_quietsfsi4_default */
    case 194:  /* *flt_quietsfsi4_default */
      return 12 /* 0xc */;

    case 245:  /* blockage */
    case 266:  /* stack_tiedi */
    case 265:  /* stack_tiesi */
      return 0;

    case 209:  /* *fle_quietdfdi4_snan */
    case 208:  /* *flt_quietdfdi4_snan */
    case 207:  /* *fle_quietdfsi4_snan */
    case 206:  /* *flt_quietdfsi4_snan */
    case 205:  /* *fle_quietsfdi4_snan */
    case 204:  /* *flt_quietsfdi4_snan */
    case 203:  /* *fle_quietsfsi4_snan */
    case 202:  /* *flt_quietsfsi4_snan */
      return 16 /* 0x10 */;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
      extract_constrain_insn_cached (insn);
      if ((cached_type = get_attr_type (insn)) == TYPE_BRANCH)
        {
	  return 8;
        }
      else if (cached_type == TYPE_CALL)
        {
	  return 8;
        }
      else if (cached_type == TYPE_GHOST)
        {
	  return 0;
        }
      else if (get_attr_got (insn) == GOT_LOAD)
        {
	  return 8;
        }
      else if (cached_type == TYPE_FCMP)
        {
	  return 8;
        }
      else if ((cached_move_type = get_attr_move_type (insn)) == MOVE_TYPE_SHIFT_SHIFT)
        {
	  return 8;
        }
      else if (((cached_move_type == MOVE_TYPE_MTC) || (cached_move_type == MOVE_TYPE_MFC) || (cached_move_type == MOVE_TYPE_MOVE)) && ((cached_dword_mode = get_attr_dword_mode (insn)) == DWORD_MODE_YES))
        {
	  return 8;
        }
      else if ((cached_move_type == MOVE_TYPE_CONST) && ((cached_dword_mode = get_attr_dword_mode (insn)) == DWORD_MODE_YES))
        {
	  return 
#line 239 "../../gcc/config/riscv/riscv.md"
(riscv_split_const_insns (operands[1]) * 4);
        }
      else if ((cached_move_type == MOVE_TYPE_LOAD) || (cached_move_type == MOVE_TYPE_FPLOAD))
        {
	  return 
#line 244 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[1], insn) * 4);
        }
      else if ((cached_move_type == MOVE_TYPE_STORE) || (cached_move_type == MOVE_TYPE_FPSTORE))
        {
	  return 
#line 246 "../../gcc/config/riscv/riscv.md"
(riscv_load_store_insns (operands[0], insn) * 4);
        }
      else
        {
	  return 4;
        }

    default:
      return 4;

    }
}

int
bypass_p (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 145:  /* *movdf_hardfloat_rv32 */
      extract_constrain_insn_cached (insn);
      if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (((1ULL << which_alternative) & 0x63ULL)))
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

    case 147:  /* *movdf_softfloat */
    case 144:  /* *movsf_softfloat */
      extract_constrain_insn_cached (insn);
      if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (((1ULL << which_alternative) & 0x3ULL)))
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

    case 146:  /* *movdf_hardfloat_rv64 */
    case 143:  /* *movsf_hardfloat */
      extract_constrain_insn_cached (insn);
      if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (((1ULL << which_alternative) & 0x1e3ULL)))
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

    case 142:  /* *movqi_internal */
    case 137:  /* *movhi_internal */
      extract_constrain_insn_cached (insn);
      if (((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (((1ULL << which_alternative) & 0x15ULL))) || ((which_alternative == 5) && (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))))
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

    case 136:  /* *movsi_internal */
      extract_constrain_insn_cached (insn);
      if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (((1ULL << which_alternative) & 0x55ULL)))
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

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
      extract_constrain_insn_cached (insn);
      if (((which_alternative == 1) && (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))) || ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (which_alternative == 0)))
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

    case 255:  /* nop */
    case 254:  /* call_value_internal */
    case 253:  /* call_internal */
    case 252:  /* sibcall_value_internal */
    case 251:  /* sibcall_internal */
    case 247:  /* simple_return_internal */
    case 246:  /* simple_return */
    case 245:  /* blockage */
    case 244:  /* tablejumpdi */
    case 243:  /* tablejumpsi */
    case 242:  /* indirect_jumpdi */
    case 241:  /* indirect_jumpsi */
    case 240:  /* jump */
    case 182:  /* *branchdi */
    case 181:  /* *branchsi */
    case 131:  /* auipcdi */
    case 130:  /* auipcsi */
    case 60:  /* *fnmadf4 */
    case 59:  /* *fnmasf4 */
    case 58:  /* *fnmsdf4 */
    case 57:  /* *fnmssf4 */
    case 56:  /* *fmsdf4 */
    case 55:  /* *fmssf4 */
    case 54:  /* *fmadf4 */
    case 53:  /* *fmasf4 */
    case 52:  /* fnmadf4 */
    case 51:  /* fnmasf4 */
    case 50:  /* fnmsdf4 */
    case 49:  /* fnmssf4 */
    case 48:  /* fmsdf4 */
    case 47:  /* fmssf4 */
    case 46:  /* fmadf4 */
    case 45:  /* fmasf4 */
    case 44:  /* sqrtdf2 */
    case 43:  /* sqrtsf2 */
    case 42:  /* divdf3 */
    case 41:  /* divsf3 */
    case 40:  /* *umodsi3_extended */
    case 39:  /* *modsi3_extended */
    case 38:  /* *udivsi3_extended */
    case 37:  /* *divsi3_extended */
    case 36:  /* umoddi3 */
    case 35:  /* moddi3 */
    case 34:  /* udivdi3 */
    case 33:  /* divdi3 */
    case 32:  /* umodsi3 */
    case 31:  /* modsi3 */
    case 30:  /* udivsi3 */
    case 29:  /* divsi3 */
    case 18:  /* muldf3 */
    case 17:  /* mulsf3 */
    case 8:  /* subdf3 */
    case 7:  /* subsf3 */
    case 2:  /* adddf3 */
    case 1:  /* addsf3 */
      return 0;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
    case 134:  /* *movdi_32bit */
    case 135:  /* *movdi_64bit */
      if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type = get_attr_type (insn)) == TYPE_LOAD))
        {
	  return 1;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type = get_attr_type (insn)) == TYPE_SFB_ALU))
        {
	  return 1;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type = get_attr_type (insn)) == TYPE_IMUL))
        {
	  return 1;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (((cached_type = get_attr_type (insn)) == TYPE_UNKNOWN) || (cached_type == TYPE_ARITH) || (cached_type == TYPE_SHIFT) || (cached_type == TYPE_SLT) || (cached_type == TYPE_MULTI) || (cached_type == TYPE_LOGICAL) || (cached_type == TYPE_MOVE)))
        {
	  return 1;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (((cached_type = get_attr_type (insn)) == TYPE_FCVT) || (cached_type == TYPE_FCMP) || (cached_type == TYPE_FMOVE)))
        {
	  return 1;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type = get_attr_type (insn)) == TYPE_MTC))
        {
	  return 1;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type = get_attr_type (insn)) == TYPE_MFC))
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

    default:
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

    }
}

int
num_delay_slots (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
    default:
      return 0;

    }
}

enum attr_cannot_copy
get_attr_cannot_copy (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case 130:  /* auipcsi */
    case 131:  /* auipcdi */
      return CANNOT_COPY_YES;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
    default:
      return CANNOT_COPY_NO;

    }
}

enum attr_dword_mode
get_attr_dword_mode (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  enum attr_mode cached_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 239:  /* *sleu_didi */
    case 238:  /* *sle_didi */
    case 237:  /* *sleu_disi */
    case 236:  /* *sle_disi */
    case 233:  /* *sltu_didi */
    case 232:  /* *slt_didi */
    case 231:  /* *sltu_disi */
    case 230:  /* *slt_disi */
    case 227:  /* *sgeu_didi */
    case 226:  /* *sge_didi */
    case 225:  /* *sgeu_disi */
    case 224:  /* *sge_disi */
    case 221:  /* *sgtu_didi */
    case 220:  /* *sgt_didi */
    case 219:  /* *sgtu_disi */
    case 218:  /* *sgt_disi */
    case 215:  /* *sne_zero_didi */
    case 214:  /* *sne_zero_disi */
    case 212:  /* *seq_zero_didi */
    case 211:  /* *seq_zero_disi */
    case 209:  /* *fle_quietdfdi4_snan */
    case 208:  /* *flt_quietdfdi4_snan */
    case 207:  /* *fle_quietdfsi4_snan */
    case 206:  /* *flt_quietdfsi4_snan */
    case 201:  /* *fle_quietdfdi4_default */
    case 200:  /* *flt_quietdfdi4_default */
    case 199:  /* *fle_quietdfsi4_default */
    case 198:  /* *flt_quietdfsi4_default */
    case 193:  /* *cstoredfdi4 */
    case 192:  /* *cstoredfsi4 */
    case 185:  /* *movdidicc */
    case 180:  /* zero_extendsidi2_shifted */
    case 167:  /* *lshrdi3_mask_1 */
    case 166:  /* *ashrdi3_mask_1 */
    case 165:  /* *ashldi3_mask_1 */
    case 164:  /* *lshrdi3_mask */
    case 163:  /* *ashrdi3_mask */
    case 162:  /* *ashldi3_mask */
    case 161:  /* lshrdi3 */
    case 160:  /* ashrdi3 */
    case 159:  /* ashldi3 */
    case 147:  /* *movdf_softfloat */
    case 146:  /* *movdf_hardfloat_rv64 */
    case 145:  /* *movdf_hardfloat_rv32 */
    case 135:  /* *movdi_64bit */
    case 134:  /* *movdi_32bit */
    case 133:  /* *lowdi */
    case 129:  /* got_load_tls_iedi */
    case 127:  /* got_load_tls_gddi */
    case 125:  /* tls_add_tp_ledi */
    case 123:  /* got_loaddi */
    case 121:  /* lrounddfdi2 */
    case 120:  /* lrintdfdi2 */
    case 119:  /* lrounddfsi2 */
    case 118:  /* lrintdfsi2 */
    case 113:  /* floatunsdidf2 */
    case 112:  /* floatunssidf2 */
    case 109:  /* floatdidf2 */
    case 108:  /* floatsidf2 */
    case 105:  /* fixuns_truncdfdi2 */
    case 104:  /* fixuns_truncdfsi2 */
    case 101:  /* fix_truncdfdi2 */
    case 100:  /* fix_truncdfsi2 */
    case 97:  /* extendsfdf2 */
    case 90:  /* extendsidi2 */
    case 89:  /* zero_extendqidi2 */
    case 86:  /* zero_extendhidi2 */
    case 84:  /* zero_extendsidi2 */
    case 81:  /* one_cmpldi2 */
    case 76:  /* xordi3 */
    case 75:  /* iordi3 */
    case 74:  /* anddi3 */
    case 70:  /* smaxdf3 */
    case 68:  /* smindf3 */
    case 66:  /* negdf2 */
    case 64:  /* copysigndf3 */
    case 62:  /* absdf2 */
    case 60:  /* *fnmadf4 */
    case 58:  /* *fnmsdf4 */
    case 56:  /* *fmsdf4 */
    case 54:  /* *fmadf4 */
    case 52:  /* fnmadf4 */
    case 50:  /* fnmsdf4 */
    case 48:  /* fmsdf4 */
    case 46:  /* fmadf4 */
    case 44:  /* sqrtdf2 */
    case 42:  /* divdf3 */
    case 40:  /* *umodsi3_extended */
    case 39:  /* *modsi3_extended */
    case 38:  /* *udivsi3_extended */
    case 37:  /* *divsi3_extended */
    case 36:  /* umoddi3 */
    case 35:  /* moddi3 */
    case 34:  /* udivdi3 */
    case 33:  /* divdi3 */
    case 25:  /* usmuldi3_highpart */
    case 24:  /* umuldi3_highpart */
    case 23:  /* muldi3_highpart */
    case 20:  /* muldi3 */
    case 18:  /* muldf3 */
    case 13:  /* negdi2 */
    case 9:  /* subdi3 */
    case 8:  /* subdf3 */
    case 4:  /* adddi3 */
    case 2:  /* adddf3 */
      extract_constrain_insn_cached (insn);
      if ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return DWORD_MODE_YES;
        }
      else
        {
	  return DWORD_MODE_NO;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
      extract_constrain_insn_cached (insn);
      if ((((cached_mode = get_attr_mode (insn)) == MODE_DI) || (cached_mode == MODE_DF)) && ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0)))
        {
	  return DWORD_MODE_YES;
        }
      else if (((cached_mode == MODE_TI) || (cached_mode == MODE_TF)) && ((
#line 137 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) != (0)))
        {
	  return DWORD_MODE_YES;
        }
      else
        {
	  return DWORD_MODE_NO;
        }

    default:
      return DWORD_MODE_NO;

    }
}

enum attr_got
get_attr_got (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case 122:  /* got_loadsi */
    case 123:  /* got_loaddi */
    case 126:  /* got_load_tls_gdsi */
    case 127:  /* got_load_tls_gddi */
    case 128:  /* got_load_tls_iesi */
    case 129:  /* got_load_tls_iedi */
      return GOT_LOAD;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
    default:
      return GOT_UNSET;

    }
}

enum attr_mode
get_attr_mode (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case 2:  /* adddf3 */
    case 8:  /* subdf3 */
    case 18:  /* muldf3 */
    case 42:  /* divdf3 */
    case 44:  /* sqrtdf2 */
    case 46:  /* fmadf4 */
    case 48:  /* fmsdf4 */
    case 50:  /* fnmsdf4 */
    case 52:  /* fnmadf4 */
    case 54:  /* *fmadf4 */
    case 56:  /* *fmsdf4 */
    case 58:  /* *fnmsdf4 */
    case 60:  /* *fnmadf4 */
    case 62:  /* absdf2 */
    case 64:  /* copysigndf3 */
    case 66:  /* negdf2 */
    case 68:  /* smindf3 */
    case 70:  /* smaxdf3 */
    case 97:  /* extendsfdf2 */
    case 100:  /* fix_truncdfsi2 */
    case 101:  /* fix_truncdfdi2 */
    case 104:  /* fixuns_truncdfsi2 */
    case 105:  /* fixuns_truncdfdi2 */
    case 108:  /* floatsidf2 */
    case 109:  /* floatdidf2 */
    case 112:  /* floatunssidf2 */
    case 113:  /* floatunsdidf2 */
    case 118:  /* lrintdfsi2 */
    case 119:  /* lrounddfsi2 */
    case 120:  /* lrintdfdi2 */
    case 121:  /* lrounddfdi2 */
    case 145:  /* *movdf_hardfloat_rv32 */
    case 146:  /* *movdf_hardfloat_rv64 */
    case 147:  /* *movdf_softfloat */
    case 192:  /* *cstoredfsi4 */
    case 193:  /* *cstoredfdi4 */
    case 198:  /* *flt_quietdfsi4_default */
    case 199:  /* *fle_quietdfsi4_default */
    case 200:  /* *flt_quietdfdi4_default */
    case 201:  /* *fle_quietdfdi4_default */
    case 206:  /* *flt_quietdfsi4_snan */
    case 207:  /* *fle_quietdfsi4_snan */
    case 208:  /* *flt_quietdfdi4_snan */
    case 209:  /* *fle_quietdfdi4_snan */
      return MODE_DF;

    case 1:  /* addsf3 */
    case 7:  /* subsf3 */
    case 17:  /* mulsf3 */
    case 41:  /* divsf3 */
    case 43:  /* sqrtsf2 */
    case 45:  /* fmasf4 */
    case 47:  /* fmssf4 */
    case 49:  /* fnmssf4 */
    case 51:  /* fnmasf4 */
    case 53:  /* *fmasf4 */
    case 55:  /* *fmssf4 */
    case 57:  /* *fnmssf4 */
    case 59:  /* *fnmasf4 */
    case 61:  /* abssf2 */
    case 63:  /* copysignsf3 */
    case 65:  /* negsf2 */
    case 67:  /* sminsf3 */
    case 69:  /* smaxsf3 */
    case 83:  /* truncdfsf2 */
    case 98:  /* fix_truncsfsi2 */
    case 99:  /* fix_truncsfdi2 */
    case 102:  /* fixuns_truncsfsi2 */
    case 103:  /* fixuns_truncsfdi2 */
    case 106:  /* floatsisf2 */
    case 107:  /* floatdisf2 */
    case 110:  /* floatunssisf2 */
    case 111:  /* floatunsdisf2 */
    case 114:  /* lrintsfsi2 */
    case 115:  /* lroundsfsi2 */
    case 116:  /* lrintsfdi2 */
    case 117:  /* lroundsfdi2 */
    case 143:  /* *movsf_hardfloat */
    case 144:  /* *movsf_softfloat */
    case 190:  /* *cstoresfsi4 */
    case 191:  /* *cstoresfdi4 */
    case 194:  /* *flt_quietsfsi4_default */
    case 195:  /* *fle_quietsfsi4_default */
    case 196:  /* *flt_quietsfdi4_default */
    case 197:  /* *fle_quietsfdi4_default */
    case 202:  /* *flt_quietsfsi4_snan */
    case 203:  /* *fle_quietsfsi4_snan */
    case 204:  /* *flt_quietsfdi4_snan */
    case 205:  /* *fle_quietsfdi4_snan */
      return MODE_SF;

    case 4:  /* adddi3 */
    case 9:  /* subdi3 */
    case 13:  /* negdi2 */
    case 20:  /* muldi3 */
    case 23:  /* muldi3_highpart */
    case 24:  /* umuldi3_highpart */
    case 25:  /* usmuldi3_highpart */
    case 33:  /* divdi3 */
    case 34:  /* udivdi3 */
    case 35:  /* moddi3 */
    case 36:  /* umoddi3 */
    case 37:  /* *divsi3_extended */
    case 38:  /* *udivsi3_extended */
    case 39:  /* *modsi3_extended */
    case 40:  /* *umodsi3_extended */
    case 74:  /* anddi3 */
    case 75:  /* iordi3 */
    case 76:  /* xordi3 */
    case 81:  /* one_cmpldi2 */
    case 84:  /* zero_extendsidi2 */
    case 86:  /* zero_extendhidi2 */
    case 89:  /* zero_extendqidi2 */
    case 90:  /* extendsidi2 */
    case 123:  /* got_loaddi */
    case 125:  /* tls_add_tp_ledi */
    case 127:  /* got_load_tls_gddi */
    case 129:  /* got_load_tls_iedi */
    case 133:  /* *lowdi */
    case 134:  /* *movdi_32bit */
    case 135:  /* *movdi_64bit */
    case 159:  /* ashldi3 */
    case 160:  /* ashrdi3 */
    case 161:  /* lshrdi3 */
    case 162:  /* *ashldi3_mask */
    case 163:  /* *ashrdi3_mask */
    case 164:  /* *lshrdi3_mask */
    case 165:  /* *ashldi3_mask_1 */
    case 166:  /* *ashrdi3_mask_1 */
    case 167:  /* *lshrdi3_mask_1 */
    case 180:  /* zero_extendsidi2_shifted */
    case 185:  /* *movdidicc */
    case 211:  /* *seq_zero_disi */
    case 212:  /* *seq_zero_didi */
    case 214:  /* *sne_zero_disi */
    case 215:  /* *sne_zero_didi */
    case 218:  /* *sgt_disi */
    case 219:  /* *sgtu_disi */
    case 220:  /* *sgt_didi */
    case 221:  /* *sgtu_didi */
    case 224:  /* *sge_disi */
    case 225:  /* *sgeu_disi */
    case 226:  /* *sge_didi */
    case 227:  /* *sgeu_didi */
    case 230:  /* *slt_disi */
    case 231:  /* *sltu_disi */
    case 232:  /* *slt_didi */
    case 233:  /* *sltu_didi */
    case 236:  /* *sle_disi */
    case 237:  /* *sleu_disi */
    case 238:  /* *sle_didi */
    case 239:  /* *sleu_didi */
      return MODE_DI;

    case 3:  /* addsi3 */
    case 5:  /* *addsi3_extended */
    case 6:  /* *addsi3_extended2 */
    case 10:  /* subsi3 */
    case 11:  /* *subsi3_extended */
    case 12:  /* *subsi3_extended2 */
    case 14:  /* negsi2 */
    case 15:  /* *negsi2_extended */
    case 16:  /* *negsi2_extended2 */
    case 19:  /* mulsi3 */
    case 21:  /* *mulsi3_extended */
    case 22:  /* *mulsi3_extended2 */
    case 26:  /* mulsi3_highpart */
    case 27:  /* umulsi3_highpart */
    case 28:  /* usmulsi3_highpart */
    case 29:  /* divsi3 */
    case 30:  /* udivsi3 */
    case 31:  /* modsi3 */
    case 32:  /* umodsi3 */
    case 71:  /* andsi3 */
    case 72:  /* iorsi3 */
    case 73:  /* xorsi3 */
    case 77:  /* *andsi3_internal */
    case 78:  /* *iorsi3_internal */
    case 79:  /* *xorsi3_internal */
    case 80:  /* one_cmplsi2 */
    case 82:  /* *one_cmplsi2_internal */
    case 85:  /* zero_extendhisi2 */
    case 88:  /* zero_extendqisi2 */
    case 91:  /* extendqihi2 */
    case 92:  /* extendqisi2 */
    case 93:  /* extendqidi2 */
    case 94:  /* extendhihi2 */
    case 95:  /* extendhisi2 */
    case 96:  /* extendhidi2 */
    case 122:  /* got_loadsi */
    case 124:  /* tls_add_tp_lesi */
    case 126:  /* got_load_tls_gdsi */
    case 128:  /* got_load_tls_iesi */
    case 132:  /* *lowsi */
    case 136:  /* *movsi_internal */
    case 150:  /* ashlsi3 */
    case 151:  /* ashrsi3 */
    case 152:  /* lshrsi3 */
    case 153:  /* *ashlsi3_mask */
    case 154:  /* *ashrsi3_mask */
    case 155:  /* *lshrsi3_mask */
    case 156:  /* *ashlsi3_mask_1 */
    case 157:  /* *ashrsi3_mask_1 */
    case 158:  /* *lshrsi3_mask_1 */
    case 168:  /* *ashlsi3_extend */
    case 169:  /* *ashrsi3_extend */
    case 170:  /* *lshrsi3_extend */
    case 171:  /* *ashlsi3_extend_mask */
    case 172:  /* *ashrsi3_extend_mask */
    case 173:  /* *lshrsi3_extend_mask */
    case 174:  /* *ashlsi3_extend_mask_1 */
    case 175:  /* *ashrsi3_extend_mask_1 */
    case 176:  /* *lshrsi3_extend_mask_1 */
    case 177:  /* *lshrsi3_zero_extend_1 */
    case 178:  /* *lshrsi3_zero_extend_2 */
    case 179:  /* *lshrsi3_zero_extend_3 */
    case 183:  /* *movsisicc */
    case 184:  /* *movsidicc */
    case 210:  /* *seq_zero_sisi */
    case 213:  /* *sne_zero_sisi */
    case 216:  /* *sgt_sisi */
    case 217:  /* *sgtu_sisi */
    case 222:  /* *sge_sisi */
    case 223:  /* *sgeu_sisi */
    case 228:  /* *slt_sisi */
    case 229:  /* *sltu_sisi */
    case 234:  /* *sle_sisi */
    case 235:  /* *sleu_sisi */
      return MODE_SI;

    case 87:  /* zero_extendqihi2 */
    case 137:  /* *movhi_internal */
    case 138:  /* *addhihi3 */
    case 139:  /* *addsihi3 */
    case 140:  /* *xorhihi3 */
    case 141:  /* *xorsihi3 */
      return MODE_HI;

    case 142:  /* *movqi_internal */
      return MODE_QI;

    case 181:  /* *branchsi */
    case 182:  /* *branchdi */
    case 240:  /* jump */
    case 241:  /* indirect_jumpsi */
    case 242:  /* indirect_jumpdi */
    case 243:  /* tablejumpsi */
    case 244:  /* tablejumpdi */
    case 245:  /* blockage */
    case 246:  /* simple_return */
    case 247:  /* simple_return_internal */
    case 255:  /* nop */
      return MODE_NONE;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
    default:
      return MODE_UNKNOWN;

    }
}

enum attr_move_type
get_attr_move_type (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  switch (recog_memoized (insn))
    {
    case 87:  /* zero_extendqihi2 */
    case 88:  /* zero_extendqisi2 */
    case 89:  /* zero_extendqidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_ANDI;
        }
      else
        {
	  return MOVE_TYPE_LOAD;
        }

    case 90:  /* extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MOVE;
        }
      else
        {
	  return MOVE_TYPE_LOAD;
        }

    case 84:  /* zero_extendsidi2 */
    case 85:  /* zero_extendhisi2 */
    case 86:  /* zero_extendhidi2 */
    case 91:  /* extendqihi2 */
    case 92:  /* extendqisi2 */
    case 93:  /* extendqidi2 */
    case 94:  /* extendhihi2 */
    case 95:  /* extendhisi2 */
    case 96:  /* extendhidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_SHIFT_SHIFT;
        }
      else
        {
	  return MOVE_TYPE_LOAD;
        }

    case 134:  /* *movdi_32bit */
    case 135:  /* *movdi_64bit */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_CONST;
        }
      else if (which_alternative == 2)
        {
	  return MOVE_TYPE_LOAD;
        }
      else if (which_alternative == 3)
        {
	  return MOVE_TYPE_STORE;
        }
      else if (which_alternative == 4)
        {
	  return MOVE_TYPE_MTC;
        }
      else if (which_alternative == 5)
        {
	  return MOVE_TYPE_FPLOAD;
        }
      else if (which_alternative == 6)
        {
	  return MOVE_TYPE_MFC;
        }
      else if (which_alternative == 7)
        {
	  return MOVE_TYPE_FMOVE;
        }
      else
        {
	  return MOVE_TYPE_FPSTORE;
        }

    case 136:  /* *movsi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_CONST;
        }
      else if (which_alternative == 2)
        {
	  return MOVE_TYPE_LOAD;
        }
      else if (which_alternative == 3)
        {
	  return MOVE_TYPE_STORE;
        }
      else if (which_alternative == 4)
        {
	  return MOVE_TYPE_MTC;
        }
      else if (which_alternative == 5)
        {
	  return MOVE_TYPE_FPLOAD;
        }
      else if (which_alternative == 6)
        {
	  return MOVE_TYPE_MFC;
        }
      else
        {
	  return MOVE_TYPE_FPSTORE;
        }

    case 137:  /* *movhi_internal */
    case 142:  /* *movqi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_CONST;
        }
      else if (which_alternative == 2)
        {
	  return MOVE_TYPE_LOAD;
        }
      else if (which_alternative == 3)
        {
	  return MOVE_TYPE_STORE;
        }
      else if (which_alternative == 4)
        {
	  return MOVE_TYPE_MTC;
        }
      else
        {
	  return MOVE_TYPE_MFC;
        }

    case 145:  /* *movdf_hardfloat_rv32 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_FMOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_MTC;
        }
      else if (which_alternative == 2)
        {
	  return MOVE_TYPE_FPLOAD;
        }
      else if (which_alternative == 3)
        {
	  return MOVE_TYPE_FPSTORE;
        }
      else if (which_alternative == 4)
        {
	  return MOVE_TYPE_STORE;
        }
      else if (which_alternative == 5)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 6)
        {
	  return MOVE_TYPE_LOAD;
        }
      else
        {
	  return MOVE_TYPE_STORE;
        }

    case 143:  /* *movsf_hardfloat */
    case 146:  /* *movdf_hardfloat_rv64 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_FMOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_MTC;
        }
      else if (which_alternative == 2)
        {
	  return MOVE_TYPE_FPLOAD;
        }
      else if (which_alternative == 3)
        {
	  return MOVE_TYPE_FPSTORE;
        }
      else if (which_alternative == 4)
        {
	  return MOVE_TYPE_STORE;
        }
      else if (which_alternative == 5)
        {
	  return MOVE_TYPE_MTC;
        }
      else if (which_alternative == 6)
        {
	  return MOVE_TYPE_MFC;
        }
      else if (which_alternative == 7)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 8)
        {
	  return MOVE_TYPE_LOAD;
        }
      else
        {
	  return MOVE_TYPE_STORE;
        }

    case 144:  /* *movsf_softfloat */
    case 147:  /* *movdf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 0)
        {
	  return MOVE_TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return MOVE_TYPE_LOAD;
        }
      else
        {
	  return MOVE_TYPE_STORE;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
    default:
      return MOVE_TYPE_UNKNOWN;

    }
}

enum attr_type
get_attr_type (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  enum attr_move_type cached_move_type ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 147:  /* *movdf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 1)
        {
	  return TYPE_LOAD;
        }
      else if (!((1ULL << which_alternative) & 0x3ULL))
        {
	  return TYPE_STORE;
        }
      else if ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return TYPE_MULTI;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 146:  /* *movdf_hardfloat_rv64 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 8)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 2)
        {
	  return TYPE_FPLOAD;
        }
      else if (!((1ULL << which_alternative) & 0x1efULL))
        {
	  return TYPE_STORE;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_FPSTORE;
        }
      else if (((1ULL << which_alternative) & 0x22ULL))
        {
	  return TYPE_MTC;
        }
      else if (which_alternative == 6)
        {
	  return TYPE_MFC;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_FMOVE;
        }
      else if ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return TYPE_MULTI;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 145:  /* *movdf_hardfloat_rv32 */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 6)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 2)
        {
	  return TYPE_FPLOAD;
        }
      else if (!((1ULL << which_alternative) & 0x6fULL))
        {
	  return TYPE_STORE;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_FPSTORE;
        }
      else if (which_alternative == 1)
        {
	  return TYPE_MTC;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_FMOVE;
        }
      else if ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return TYPE_MULTI;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 144:  /* *movsf_softfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 1)
        {
	  return TYPE_LOAD;
        }
      else if (!((1ULL << which_alternative) & 0x3ULL))
        {
	  return TYPE_STORE;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 143:  /* *movsf_hardfloat */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 8)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 2)
        {
	  return TYPE_FPLOAD;
        }
      else if (!((1ULL << which_alternative) & 0x1efULL))
        {
	  return TYPE_STORE;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_FPSTORE;
        }
      else if (((1ULL << which_alternative) & 0x22ULL))
        {
	  return TYPE_MTC;
        }
      else if (which_alternative == 6)
        {
	  return TYPE_MFC;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_FMOVE;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 142:  /* *movqi_internal */
    case 137:  /* *movhi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 2)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_STORE;
        }
      else if (which_alternative == 4)
        {
	  return TYPE_MTC;
        }
      else if (!((1ULL << which_alternative) & 0x1fULL))
        {
	  return TYPE_MFC;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else
        {
	  return TYPE_CONST;
        }

    case 136:  /* *movsi_internal */
      extract_constrain_insn_cached (insn);
      if (which_alternative == 2)
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 5)
        {
	  return TYPE_FPLOAD;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_STORE;
        }
      else if (!((1ULL << which_alternative) & 0x7fULL))
        {
	  return TYPE_FPSTORE;
        }
      else if (which_alternative == 4)
        {
	  return TYPE_MTC;
        }
      else if (which_alternative == 6)
        {
	  return TYPE_MFC;
        }
      else if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else
        {
	  return TYPE_CONST;
        }

    case 90:  /* extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return TYPE_LOAD;
        }
      else if ((
#line 133 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) == (0))
        {
	  return TYPE_MULTI;
        }
      else
        {
	  return TYPE_MOVE;
        }

    case 89:  /* zero_extendqidi2 */
    case 88:  /* zero_extendqisi2 */
    case 87:  /* zero_extendqihi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return TYPE_LOAD;
        }
      else
        {
	  return TYPE_LOGICAL;
        }

    case 96:  /* extendhidi2 */
    case 95:  /* extendhisi2 */
    case 94:  /* extendhihi2 */
    case 93:  /* extendqidi2 */
    case 92:  /* extendqisi2 */
    case 91:  /* extendqihi2 */
    case 86:  /* zero_extendhidi2 */
    case 85:  /* zero_extendhisi2 */
    case 84:  /* zero_extendsidi2 */
      extract_constrain_insn_cached (insn);
      if (which_alternative != 0)
        {
	  return TYPE_LOAD;
        }
      else
        {
	  return TYPE_MULTI;
        }

    case 134:  /* *movdi_32bit */
    case 135:  /* *movdi_64bit */
      if (get_attr_got (insn) == GOT_LOAD)
        {
	  return TYPE_LOAD;
        }
      else if ((cached_move_type = get_attr_move_type (insn)) == MOVE_TYPE_LOAD)
        {
	  return TYPE_LOAD;
        }
      else if (cached_move_type == MOVE_TYPE_FPLOAD)
        {
	  return TYPE_FPLOAD;
        }
      else if (cached_move_type == MOVE_TYPE_STORE)
        {
	  return TYPE_STORE;
        }
      else if (cached_move_type == MOVE_TYPE_FPSTORE)
        {
	  return TYPE_FPSTORE;
        }
      else if (cached_move_type == MOVE_TYPE_MTC)
        {
	  return TYPE_MTC;
        }
      else if (cached_move_type == MOVE_TYPE_MFC)
        {
	  return TYPE_MFC;
        }
      else if (cached_move_type == MOVE_TYPE_FMOVE)
        {
	  return TYPE_FMOVE;
        }
      else if (cached_move_type == MOVE_TYPE_ARITH)
        {
	  return TYPE_ARITH;
        }
      else if (cached_move_type == MOVE_TYPE_LOGICAL)
        {
	  return TYPE_LOGICAL;
        }
      else if (cached_move_type == MOVE_TYPE_ANDI)
        {
	  return TYPE_LOGICAL;
        }
      else if (cached_move_type == MOVE_TYPE_SHIFT_SHIFT)
        {
	  return TYPE_MULTI;
        }
      else if (((cached_move_type == MOVE_TYPE_MOVE) || (cached_move_type == MOVE_TYPE_CONST)) && (get_attr_dword_mode (insn) == DWORD_MODE_YES))
        {
	  return TYPE_MULTI;
        }
      else if (cached_move_type == MOVE_TYPE_MOVE)
        {
	  return TYPE_MOVE;
        }
      else if (cached_move_type == MOVE_TYPE_CONST)
        {
	  return TYPE_CONST;
        }
      else
        {
	  return TYPE_UNKNOWN;
        }

    case 245:  /* blockage */
      return TYPE_GHOST;

    case 255:  /* nop */
      return TYPE_NOP;

    case 183:  /* *movsisicc */
    case 184:  /* *movsidicc */
    case 185:  /* *movdidicc */
      return TYPE_SFB_ALU;

    case 130:  /* auipcsi */
    case 131:  /* auipcdi */
      return TYPE_AUIPC;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
      return TYPE_MULTI;

    case 43:  /* sqrtsf2 */
    case 44:  /* sqrtdf2 */
      return TYPE_FSQRT;

    case 83:  /* truncdfsf2 */
    case 97:  /* extendsfdf2 */
    case 98:  /* fix_truncsfsi2 */
    case 99:  /* fix_truncsfdi2 */
    case 100:  /* fix_truncdfsi2 */
    case 101:  /* fix_truncdfdi2 */
    case 102:  /* fixuns_truncsfsi2 */
    case 103:  /* fixuns_truncsfdi2 */
    case 104:  /* fixuns_truncdfsi2 */
    case 105:  /* fixuns_truncdfdi2 */
    case 106:  /* floatsisf2 */
    case 107:  /* floatdisf2 */
    case 108:  /* floatsidf2 */
    case 109:  /* floatdidf2 */
    case 110:  /* floatunssisf2 */
    case 111:  /* floatunsdisf2 */
    case 112:  /* floatunssidf2 */
    case 113:  /* floatunsdidf2 */
    case 114:  /* lrintsfsi2 */
    case 115:  /* lroundsfsi2 */
    case 116:  /* lrintsfdi2 */
    case 117:  /* lroundsfdi2 */
    case 118:  /* lrintdfsi2 */
    case 119:  /* lrounddfsi2 */
    case 120:  /* lrintdfdi2 */
    case 121:  /* lrounddfdi2 */
      return TYPE_FCVT;

    case 190:  /* *cstoresfsi4 */
    case 191:  /* *cstoresfdi4 */
    case 192:  /* *cstoredfsi4 */
    case 193:  /* *cstoredfdi4 */
    case 194:  /* *flt_quietsfsi4_default */
    case 195:  /* *fle_quietsfsi4_default */
    case 196:  /* *flt_quietsfdi4_default */
    case 197:  /* *fle_quietsfdi4_default */
    case 198:  /* *flt_quietdfsi4_default */
    case 199:  /* *fle_quietdfsi4_default */
    case 200:  /* *flt_quietdfdi4_default */
    case 201:  /* *fle_quietdfdi4_default */
    case 202:  /* *flt_quietsfsi4_snan */
    case 203:  /* *fle_quietsfsi4_snan */
    case 204:  /* *flt_quietsfdi4_snan */
    case 205:  /* *fle_quietsfdi4_snan */
    case 206:  /* *flt_quietdfsi4_snan */
    case 207:  /* *fle_quietdfsi4_snan */
    case 208:  /* *flt_quietdfdi4_snan */
    case 209:  /* *fle_quietdfdi4_snan */
      return TYPE_FCMP;

    case 41:  /* divsf3 */
    case 42:  /* divdf3 */
      return TYPE_FDIV;

    case 45:  /* fmasf4 */
    case 46:  /* fmadf4 */
    case 47:  /* fmssf4 */
    case 48:  /* fmsdf4 */
    case 49:  /* fnmssf4 */
    case 50:  /* fnmsdf4 */
    case 51:  /* fnmasf4 */
    case 52:  /* fnmadf4 */
    case 53:  /* *fmasf4 */
    case 54:  /* *fmadf4 */
    case 55:  /* *fmssf4 */
    case 56:  /* *fmsdf4 */
    case 57:  /* *fnmssf4 */
    case 58:  /* *fnmsdf4 */
    case 59:  /* *fnmasf4 */
    case 60:  /* *fnmadf4 */
      return TYPE_FMADD;

    case 17:  /* mulsf3 */
    case 18:  /* muldf3 */
      return TYPE_FMUL;

    case 1:  /* addsf3 */
    case 2:  /* adddf3 */
    case 7:  /* subsf3 */
    case 8:  /* subdf3 */
      return TYPE_FADD;

    case 61:  /* abssf2 */
    case 62:  /* absdf2 */
    case 63:  /* copysignsf3 */
    case 64:  /* copysigndf3 */
    case 65:  /* negsf2 */
    case 66:  /* negdf2 */
    case 67:  /* sminsf3 */
    case 68:  /* smindf3 */
    case 69:  /* smaxsf3 */
    case 70:  /* smaxdf3 */
      return TYPE_FMOVE;

    case 29:  /* divsi3 */
    case 30:  /* udivsi3 */
    case 31:  /* modsi3 */
    case 32:  /* umodsi3 */
    case 33:  /* divdi3 */
    case 34:  /* udivdi3 */
    case 35:  /* moddi3 */
    case 36:  /* umoddi3 */
    case 37:  /* *divsi3_extended */
    case 38:  /* *udivsi3_extended */
    case 39:  /* *modsi3_extended */
    case 40:  /* *umodsi3_extended */
      return TYPE_IDIV;

    case 19:  /* mulsi3 */
    case 20:  /* muldi3 */
    case 21:  /* *mulsi3_extended */
    case 22:  /* *mulsi3_extended2 */
    case 23:  /* muldi3_highpart */
    case 24:  /* umuldi3_highpart */
    case 25:  /* usmuldi3_highpart */
    case 26:  /* mulsi3_highpart */
    case 27:  /* umulsi3_highpart */
    case 28:  /* usmulsi3_highpart */
      return TYPE_IMUL;

    case 210:  /* *seq_zero_sisi */
    case 211:  /* *seq_zero_disi */
    case 212:  /* *seq_zero_didi */
    case 213:  /* *sne_zero_sisi */
    case 214:  /* *sne_zero_disi */
    case 215:  /* *sne_zero_didi */
    case 216:  /* *sgt_sisi */
    case 217:  /* *sgtu_sisi */
    case 218:  /* *sgt_disi */
    case 219:  /* *sgtu_disi */
    case 220:  /* *sgt_didi */
    case 221:  /* *sgtu_didi */
    case 222:  /* *sge_sisi */
    case 223:  /* *sgeu_sisi */
    case 224:  /* *sge_disi */
    case 225:  /* *sgeu_disi */
    case 226:  /* *sge_didi */
    case 227:  /* *sgeu_didi */
    case 228:  /* *slt_sisi */
    case 229:  /* *sltu_sisi */
    case 230:  /* *slt_disi */
    case 231:  /* *sltu_disi */
    case 232:  /* *slt_didi */
    case 233:  /* *sltu_didi */
    case 234:  /* *sle_sisi */
    case 235:  /* *sleu_sisi */
    case 236:  /* *sle_disi */
    case 237:  /* *sleu_disi */
    case 238:  /* *sle_didi */
    case 239:  /* *sleu_didi */
      return TYPE_SLT;

    case 150:  /* ashlsi3 */
    case 151:  /* ashrsi3 */
    case 152:  /* lshrsi3 */
    case 153:  /* *ashlsi3_mask */
    case 154:  /* *ashrsi3_mask */
    case 155:  /* *lshrsi3_mask */
    case 156:  /* *ashlsi3_mask_1 */
    case 157:  /* *ashrsi3_mask_1 */
    case 158:  /* *lshrsi3_mask_1 */
    case 159:  /* ashldi3 */
    case 160:  /* ashrdi3 */
    case 161:  /* lshrdi3 */
    case 162:  /* *ashldi3_mask */
    case 163:  /* *ashrdi3_mask */
    case 164:  /* *lshrdi3_mask */
    case 165:  /* *ashldi3_mask_1 */
    case 166:  /* *ashrdi3_mask_1 */
    case 167:  /* *lshrdi3_mask_1 */
    case 168:  /* *ashlsi3_extend */
    case 169:  /* *ashrsi3_extend */
    case 170:  /* *lshrsi3_extend */
    case 171:  /* *ashlsi3_extend_mask */
    case 172:  /* *ashrsi3_extend_mask */
    case 173:  /* *lshrsi3_extend_mask */
    case 174:  /* *ashlsi3_extend_mask_1 */
    case 175:  /* *ashrsi3_extend_mask_1 */
    case 176:  /* *lshrsi3_extend_mask_1 */
    case 177:  /* *lshrsi3_zero_extend_1 */
    case 178:  /* *lshrsi3_zero_extend_2 */
    case 179:  /* *lshrsi3_zero_extend_3 */
    case 180:  /* zero_extendsidi2_shifted */
      return TYPE_SHIFT;

    case 71:  /* andsi3 */
    case 72:  /* iorsi3 */
    case 73:  /* xorsi3 */
    case 74:  /* anddi3 */
    case 75:  /* iordi3 */
    case 76:  /* xordi3 */
    case 77:  /* *andsi3_internal */
    case 78:  /* *iorsi3_internal */
    case 79:  /* *xorsi3_internal */
    case 80:  /* one_cmplsi2 */
    case 81:  /* one_cmpldi2 */
    case 82:  /* *one_cmplsi2_internal */
    case 140:  /* *xorhihi3 */
    case 141:  /* *xorsihi3 */
      return TYPE_LOGICAL;

    case 3:  /* addsi3 */
    case 4:  /* adddi3 */
    case 5:  /* *addsi3_extended */
    case 6:  /* *addsi3_extended2 */
    case 9:  /* subdi3 */
    case 10:  /* subsi3 */
    case 11:  /* *subsi3_extended */
    case 12:  /* *subsi3_extended2 */
    case 13:  /* negdi2 */
    case 14:  /* negsi2 */
    case 15:  /* *negsi2_extended */
    case 16:  /* *negsi2_extended2 */
    case 124:  /* tls_add_tp_lesi */
    case 125:  /* tls_add_tp_ledi */
    case 132:  /* *lowsi */
    case 133:  /* *lowdi */
    case 138:  /* *addhihi3 */
    case 139:  /* *addsihi3 */
      return TYPE_ARITH;

    case 129:  /* got_load_tls_iedi */
    case 128:  /* got_load_tls_iesi */
    case 127:  /* got_load_tls_gddi */
    case 126:  /* got_load_tls_gdsi */
    case 123:  /* got_loaddi */
    case 122:  /* got_loadsi */
      return TYPE_LOAD;

    case 251:  /* sibcall_internal */
    case 252:  /* sibcall_value_internal */
    case 253:  /* call_internal */
    case 254:  /* call_value_internal */
      return TYPE_CALL;

    case 240:  /* jump */
    case 241:  /* indirect_jumpsi */
    case 242:  /* indirect_jumpdi */
    case 243:  /* tablejumpsi */
    case 244:  /* tablejumpdi */
    case 246:  /* simple_return */
    case 247:  /* simple_return_internal */
      return TYPE_JUMP;

    case 181:  /* *branchsi */
    case 182:  /* *branchdi */
      return TYPE_BRANCH;

    default:
      return TYPE_UNKNOWN;

    }
}

int
eligible_for_delay (rtx_insn *delay_insn ATTRIBUTE_UNUSED, int slot, 
		   rtx_insn *candidate_insn, int flags ATTRIBUTE_UNUSED)
{
  rtx_insn *insn ATTRIBUTE_UNUSED;

  if (num_delay_slots (delay_insn) == 0)
    return 0;
  gcc_assert (slot < 0);

  if (!INSN_P (candidate_insn))
    return 0;

  insn = candidate_insn;
  switch (slot)
    {
    default:
      gcc_unreachable ();
    }
}

int
eligible_for_annul_true (rtx_insn *delay_insn ATTRIBUTE_UNUSED,
    int slot ATTRIBUTE_UNUSED,
    rtx_insn *candidate_insn ATTRIBUTE_UNUSED,
    int flags ATTRIBUTE_UNUSED)
{
  return 0;
}

int
eligible_for_annul_false (rtx_insn *delay_insn ATTRIBUTE_UNUSED,
    int slot ATTRIBUTE_UNUSED,
    rtx_insn *candidate_insn ATTRIBUTE_UNUSED,
    int flags ATTRIBUTE_UNUSED)
{
  return 0;
}

int
const_num_delay_slots (rtx_insn *insn)
{
  switch (recog_memoized (insn))
    {
    default:
      return 1;
    }
}

EXPORTED_CONST int length_unit_log = 0;
