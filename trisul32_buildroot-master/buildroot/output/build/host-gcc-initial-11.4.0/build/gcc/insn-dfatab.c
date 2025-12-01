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
internal_dfa_insn_code (rtx_insn *insn ATTRIBUTE_UNUSED)
{
  enum attr_type cached_type ATTRIBUTE_UNUSED;
  enum attr_mode cached_mode ATTRIBUTE_UNUSED;

  switch (recog_memoized (insn))
    {
    case 245:  /* blockage */
      return 0;

    case 254:  /* call_value_internal */
    case 253:  /* call_internal */
    case 252:  /* sibcall_value_internal */
    case 251:  /* sibcall_internal */
    case 247:  /* simple_return_internal */
    case 246:  /* simple_return */
    case 244:  /* tablejumpdi */
    case 243:  /* tablejumpsi */
    case 242:  /* indirect_jumpdi */
    case 241:  /* indirect_jumpsi */
    case 240:  /* jump */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 5;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 19 /* 0x13 */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 185:  /* *movdidicc */
    case 184:  /* *movsidicc */
    case 183:  /* *movsisicc */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 18 /* 0x12 */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 182:  /* *branchdi */
    case 181:  /* *branchsi */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 5;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 17 /* 0x11 */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 255:  /* nop */
    case 131:  /* auipcdi */
    case 130:  /* auipcsi */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 1;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 23 /* 0x17 */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 129:  /* got_load_tls_iedi */
    case 128:  /* got_load_tls_iesi */
    case 127:  /* got_load_tls_gddi */
    case 126:  /* got_load_tls_gdsi */
    case 123:  /* got_loaddi */
    case 122:  /* got_loadsi */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 2;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 13 /* 0xd */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

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
    case 193:  /* *cstoredfdi4 */
    case 192:  /* *cstoredfsi4 */
    case 191:  /* *cstoresfdi4 */
    case 190:  /* *cstoresfsi4 */
    case 121:  /* lrounddfdi2 */
    case 120:  /* lrintdfdi2 */
    case 119:  /* lrounddfsi2 */
    case 118:  /* lrintdfsi2 */
    case 117:  /* lroundsfdi2 */
    case 116:  /* lrintsfdi2 */
    case 115:  /* lroundsfsi2 */
    case 114:  /* lrintsfsi2 */
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
    case 83:  /* truncdfsf2 */
    case 70:  /* smaxdf3 */
    case 69:  /* smaxsf3 */
    case 68:  /* smindf3 */
    case 67:  /* sminsf3 */
    case 66:  /* negdf2 */
    case 65:  /* negsf2 */
    case 64:  /* copysigndf3 */
    case 63:  /* copysignsf3 */
    case 62:  /* absdf2 */
    case 61:  /* abssf2 */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 4;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 26 /* 0x1a */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 44:  /* sqrtdf2 */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 12 /* 0xc */;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 28 /* 0x1c */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 43:  /* sqrtsf2 */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 12 /* 0xc */;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 27 /* 0x1b */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 42:  /* divdf3 */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 11 /* 0xb */;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 28 /* 0x1c */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 41:  /* divsf3 */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 11 /* 0xb */;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 27 /* 0x1b */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 40:  /* *umodsi3_extended */
    case 39:  /* *modsi3_extended */
    case 38:  /* *udivsi3_extended */
    case 37:  /* *divsi3_extended */
    case 36:  /* umoddi3 */
    case 35:  /* moddi3 */
    case 34:  /* udivdi3 */
    case 33:  /* divdi3 */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 8;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 21 /* 0x15 */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 32:  /* umodsi3 */
    case 31:  /* modsi3 */
    case 30:  /* udivsi3 */
    case 29:  /* divsi3 */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 7;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 21 /* 0x15 */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 28:  /* usmulsi3_highpart */
    case 27:  /* umulsi3_highpart */
    case 26:  /* mulsi3_highpart */
    case 25:  /* usmuldi3_highpart */
    case 24:  /* umuldi3_highpart */
    case 23:  /* muldi3_highpart */
    case 22:  /* *mulsi3_extended2 */
    case 21:  /* *mulsi3_extended */
    case 20:  /* muldi3 */
    case 19:  /* mulsi3 */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 6;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 20 /* 0x14 */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 60:  /* *fnmadf4 */
    case 58:  /* *fnmsdf4 */
    case 56:  /* *fmsdf4 */
    case 54:  /* *fmadf4 */
    case 52:  /* fnmadf4 */
    case 50:  /* fnmsdf4 */
    case 48:  /* fmsdf4 */
    case 46:  /* fmadf4 */
    case 18:  /* muldf3 */
    case 8:  /* subdf3 */
    case 2:  /* adddf3 */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 10 /* 0xa */;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 25 /* 0x19 */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case 59:  /* *fnmasf4 */
    case 57:  /* *fnmssf4 */
    case 55:  /* *fmssf4 */
    case 53:  /* *fmasf4 */
    case 51:  /* fnmasf4 */
    case 49:  /* fnmssf4 */
    case 47:  /* fmssf4 */
    case 45:  /* fmasf4 */
    case 17:  /* mulsf3 */
    case 7:  /* subsf3 */
    case 1:  /* addsf3 */
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 9;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 24 /* 0x18 */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      /* FALLTHRU */
    case 84:  /* zero_extendsidi2 */
    case 85:  /* zero_extendhisi2 */
    case 86:  /* zero_extendhidi2 */
    case 87:  /* zero_extendqihi2 */
    case 88:  /* zero_extendqisi2 */
    case 89:  /* zero_extendqidi2 */
    case 90:  /* extendsidi2 */
    case 91:  /* extendqihi2 */
    case 92:  /* extendqisi2 */
    case 93:  /* extendqidi2 */
    case 94:  /* extendhihi2 */
    case 95:  /* extendhisi2 */
    case 96:  /* extendhidi2 */
    case 134:  /* *movdi_32bit */
    case 135:  /* *movdi_64bit */
    case 136:  /* *movsi_internal */
    case 137:  /* *movhi_internal */
    case 142:  /* *movqi_internal */
    case 143:  /* *movsf_hardfloat */
    case 144:  /* *movsf_softfloat */
    case 145:  /* *movdf_hardfloat_rv32 */
    case 146:  /* *movdf_hardfloat_rv64 */
    case 147:  /* *movdf_softfloat */
      if ((cached_type = get_attr_type (insn)) == TYPE_GHOST)
        {
	  return 0;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && ((cached_type == TYPE_UNKNOWN) || (cached_type == TYPE_CONST) || (cached_type == TYPE_ARITH) || (cached_type == TYPE_SHIFT) || (cached_type == TYPE_SLT) || (cached_type == TYPE_MULTI) || (cached_type == TYPE_AUIPC) || (cached_type == TYPE_NOP) || (cached_type == TYPE_LOGICAL) || (cached_type == TYPE_MOVE)))
        {
	  return 1;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && ((cached_type == TYPE_LOAD) || (cached_type == TYPE_FPLOAD)))
        {
	  return 2;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && ((cached_type == TYPE_STORE) || (cached_type == TYPE_FPSTORE)))
        {
	  return 3;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && ((cached_type == TYPE_MFC) || (cached_type == TYPE_MTC) || (cached_type == TYPE_FCVT) || (cached_type == TYPE_FMOVE) || (cached_type == TYPE_FCMP)))
        {
	  return 4;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && ((cached_type == TYPE_BRANCH) || (cached_type == TYPE_JUMP) || (cached_type == TYPE_CALL)))
        {
	  return 5;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && (cached_type == TYPE_IMUL))
        {
	  return 6;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && (cached_type == TYPE_IDIV) && ((cached_mode = get_attr_mode (insn)) == MODE_SI))
        {
	  return 7;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && (cached_type == TYPE_IDIV) && ((cached_mode = get_attr_mode (insn)) == MODE_DI))
        {
	  return 8;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && ((cached_type == TYPE_FADD) || (cached_type == TYPE_FMUL) || (cached_type == TYPE_FMADD)) && ((cached_mode = get_attr_mode (insn)) == MODE_SF))
        {
	  return 9;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && ((cached_type == TYPE_FADD) || (cached_type == TYPE_FMUL) || (cached_type == TYPE_FMADD)) && ((cached_mode = get_attr_mode (insn)) == MODE_DF))
        {
	  return 10 /* 0xa */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && (cached_type == TYPE_FDIV))
        {
	  return 11 /* 0xb */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC)))) && (cached_type == TYPE_FSQRT))
        {
	  return 12 /* 0xc */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (cached_type == TYPE_LOAD))
        {
	  return 13 /* 0xd */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (cached_type == TYPE_FPLOAD))
        {
	  return 14 /* 0xe */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (cached_type == TYPE_STORE))
        {
	  return 15 /* 0xf */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (cached_type == TYPE_FPSTORE))
        {
	  return 16 /* 0x10 */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (cached_type == TYPE_BRANCH))
        {
	  return 17 /* 0x11 */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (cached_type == TYPE_SFB_ALU))
        {
	  return 18 /* 0x12 */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type == TYPE_JUMP) || (cached_type == TYPE_CALL)))
        {
	  return 19 /* 0x13 */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (cached_type == TYPE_IMUL))
        {
	  return 20 /* 0x14 */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (cached_type == TYPE_IDIV))
        {
	  return 21 /* 0x15 */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type == TYPE_UNKNOWN) || (cached_type == TYPE_ARITH) || (cached_type == TYPE_SHIFT) || (cached_type == TYPE_SLT) || (cached_type == TYPE_MULTI) || (cached_type == TYPE_LOGICAL) || (cached_type == TYPE_MOVE)))
        {
	  return 22 /* 0x16 */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type == TYPE_NOP) || (cached_type == TYPE_CONST) || (cached_type == TYPE_AUIPC)))
        {
	  return 23 /* 0x17 */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type == TYPE_FADD) || (cached_type == TYPE_FMUL) || (cached_type == TYPE_FMADD)) && ((cached_mode = get_attr_mode (insn)) == MODE_SF))
        {
	  return 24 /* 0x18 */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type == TYPE_FADD) || (cached_type == TYPE_FMUL) || (cached_type == TYPE_FMADD)) && ((cached_mode = get_attr_mode (insn)) == MODE_DF))
        {
	  return 25 /* 0x19 */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type == TYPE_FCVT) || (cached_type == TYPE_FCMP) || (cached_type == TYPE_FMOVE)))
        {
	  return 26 /* 0x1a */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type == TYPE_FDIV) || (cached_type == TYPE_FSQRT)) && ((cached_mode = get_attr_mode (insn)) == MODE_SF))
        {
	  return 27 /* 0x1b */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && ((cached_type == TYPE_FDIV) || (cached_type == TYPE_FSQRT)) && ((cached_mode = get_attr_mode (insn)) == MODE_DF))
        {
	  return 28 /* 0x1c */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (cached_type == TYPE_MTC))
        {
	  return 29 /* 0x1d */;
        }
      else if ((((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7)))) && (cached_type == TYPE_MFC))
        {
	  return 30 /* 0x1e */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    default:
      if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_GENERIC))))
        {
	  return 1;
        }
      else if (((
#line 256 "../../gcc/config/riscv/riscv.md"
(((enum attr_tune) riscv_microarchitecture))) == (
(TUNE_SIFIVE_7))))
        {
	  return 22 /* 0x16 */;
        }
      else
        {
	  return 32 /* 0x20 */;
        }

    }
}

