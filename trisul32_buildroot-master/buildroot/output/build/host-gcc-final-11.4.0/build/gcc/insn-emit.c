/* Generated automatically by the program `genemit'
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
#include "varasm.h"
#include "stor-layout.h"
#include "calls.h"
#include "memmodel.h"
#include "tm_p.h"
#include "flags.h"
#include "insn-config.h"
#include "expmed.h"
#include "dojump.h"
#include "explow.h"
#include "emit-rtl.h"
#include "stmt.h"
#include "expr.h"
#include "insn-codes.h"
#include "optabs.h"
#include "dfp.h"
#include "output.h"
#include "recog.h"
#include "df.h"
#include "resource.h"
#include "reload.h"
#include "diagnostic-core.h"
#include "regs.h"
#include "tm-constrs.h"
#include "ggc.h"
#include "target.h"

/* ../../gcc/config/riscv/riscv.md:443 */
rtx
gen_addsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_PLUS (SFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:443 */
rtx
gen_adddf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_PLUS (DFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:452 */
rtx
gen_addsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_PLUS (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:461 */
rtx
gen_adddi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_PLUS (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:499 */
rtx
gen_subsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_MINUS (SFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:499 */
rtx
gen_subdf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_MINUS (DFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:508 */
rtx
gen_subdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_MINUS (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:517 */
rtx
gen_subsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_MINUS (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:547 */
rtx
gen_negdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_NEG (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:555 */
rtx
gen_negsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_NEG (SImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:590 */
rtx
gen_mulsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_MULT (SFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:590 */
rtx
gen_muldf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_MULT (DFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:599 */
rtx
gen_mulsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_MULT (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:608 */
rtx
gen_muldi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_MULT (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:664 */
rtx
gen_muldi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_SIGN_EXTEND (TImode,
	operand1),
	gen_rtx_SIGN_EXTEND (TImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)])));
}

/* ../../gcc/config/riscv/riscv.md:664 */
rtx
gen_umuldi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	operand1),
	gen_rtx_ZERO_EXTEND (TImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)])));
}

/* ../../gcc/config/riscv/riscv.md:695 */
rtx
gen_usmuldi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_TRUNCATE (DImode,
	gen_rtx_LSHIFTRT (TImode,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	operand1),
	gen_rtx_SIGN_EXTEND (TImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (64)])));
}

/* ../../gcc/config/riscv/riscv.md:725 */
rtx
gen_mulsi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
}

/* ../../gcc/config/riscv/riscv.md:725 */
rtx
gen_umulsi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_ZERO_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
}

/* ../../gcc/config/riscv/riscv.md:756 */
rtx
gen_usmulsi3_highpart (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_TRUNCATE (SImode,
	gen_rtx_LSHIFTRT (DImode,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2)),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
}

/* ../../gcc/config/riscv/riscv.md:778 */
rtx
gen_divsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_DIV (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:778 */
rtx
gen_udivsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UDIV (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:778 */
rtx
gen_modsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_MOD (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:778 */
rtx
gen_umodsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UMOD (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:787 */
rtx
gen_divdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_DIV (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:787 */
rtx
gen_udivdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UDIV (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:787 */
rtx
gen_moddi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_MOD (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:787 */
rtx
gen_umoddi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UMOD (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:806 */
rtx
gen_divsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_DIV (SFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:806 */
rtx
gen_divdf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_DIV (DFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:822 */
rtx
gen_sqrtsf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SQRT (SFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:822 */
rtx
gen_sqrtdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SQRT (DFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:835 */
rtx
gen_fmasf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FMA (SFmode,
	operand1,
	operand2,
	operand3));
}

/* ../../gcc/config/riscv/riscv.md:835 */
rtx
gen_fmadf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FMA (DFmode,
	operand1,
	operand2,
	operand3));
}

/* ../../gcc/config/riscv/riscv.md:846 */
rtx
gen_fmssf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FMA (SFmode,
	operand1,
	operand2,
	gen_rtx_NEG (SFmode,
	operand3)));
}

/* ../../gcc/config/riscv/riscv.md:846 */
rtx
gen_fmsdf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FMA (DFmode,
	operand1,
	operand2,
	gen_rtx_NEG (DFmode,
	operand3)));
}

/* ../../gcc/config/riscv/riscv.md:857 */
rtx
gen_fnmssf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FMA (SFmode,
	gen_rtx_NEG (SFmode,
	operand1),
	operand2,
	gen_rtx_NEG (SFmode,
	operand3)));
}

/* ../../gcc/config/riscv/riscv.md:857 */
rtx
gen_fnmsdf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FMA (DFmode,
	gen_rtx_NEG (DFmode,
	operand1),
	operand2,
	gen_rtx_NEG (DFmode,
	operand3)));
}

/* ../../gcc/config/riscv/riscv.md:869 */
rtx
gen_fnmasf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FMA (SFmode,
	gen_rtx_NEG (SFmode,
	operand1),
	operand2,
	operand3));
}

/* ../../gcc/config/riscv/riscv.md:869 */
rtx
gen_fnmadf4 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FMA (DFmode,
	gen_rtx_NEG (DFmode,
	operand1),
	operand2,
	operand3));
}

/* ../../gcc/config/riscv/riscv.md:939 */
rtx
gen_abssf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ABS (SFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:939 */
rtx
gen_absdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ABS (DFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:947 */
rtx
gen_copysignsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	11));
}

/* ../../gcc/config/riscv/riscv.md:947 */
rtx
gen_copysigndf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DFmode,
	gen_rtvec (2,
		operand1,
		operand2),
	11));
}

/* ../../gcc/config/riscv/riscv.md:957 */
rtx
gen_negsf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_NEG (SFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:957 */
rtx
gen_negdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_NEG (DFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:972 */
rtx
gen_sminsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SMIN (SFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:972 */
rtx
gen_smindf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SMIN (DFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:981 */
rtx
gen_smaxsf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SMAX (SFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:981 */
rtx
gen_smaxdf3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SMAX (DFmode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1001 */
rtx
gen_andsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_AND (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1001 */
rtx
gen_iorsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_IOR (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1001 */
rtx
gen_xorsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_XOR (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1001 */
rtx
gen_anddi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_AND (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1001 */
rtx
gen_iordi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_IOR (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1001 */
rtx
gen_xordi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_XOR (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1019 */
rtx
gen_one_cmplsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_NOT (SImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1019 */
rtx
gen_one_cmpldi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_NOT (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1042 */
rtx
gen_truncdfsf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FLOAT_TRUNCATE (SFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1060 */
rtx
gen_zero_extendsidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1079 */
rtx
gen_zero_extendhisi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ZERO_EXTEND (SImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1079 */
rtx
gen_zero_extendhidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1101 */
rtx
gen_zero_extendqihi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ZERO_EXTEND (HImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1101 */
rtx
gen_zero_extendqisi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ZERO_EXTEND (SImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1101 */
rtx
gen_zero_extendqidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1119 */
rtx
gen_extendsidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1130 */
rtx
gen_extendqihi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (HImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1130 */
rtx
gen_extendqisi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (SImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1130 */
rtx
gen_extendqidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1130 */
rtx
gen_extendhihi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (HImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1130 */
rtx
gen_extendhisi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (SImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1130 */
rtx
gen_extendhidi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1152 */
rtx
gen_extendsfdf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FLOAT_EXTEND (DFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1168 */
rtx
gen_fix_truncsfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FIX (SImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1168 */
rtx
gen_fix_truncsfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FIX (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1168 */
rtx
gen_fix_truncdfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FIX (SImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1168 */
rtx
gen_fix_truncdfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FIX (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1177 */
rtx
gen_fixuns_truncsfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSIGNED_FIX (SImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1177 */
rtx
gen_fixuns_truncsfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSIGNED_FIX (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1177 */
rtx
gen_fixuns_truncdfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSIGNED_FIX (SImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1177 */
rtx
gen_fixuns_truncdfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSIGNED_FIX (DImode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1186 */
rtx
gen_floatsisf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FLOAT (SFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1186 */
rtx
gen_floatdisf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FLOAT (SFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1186 */
rtx
gen_floatsidf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FLOAT (DFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1186 */
rtx
gen_floatdidf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_FLOAT (DFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1195 */
rtx
gen_floatunssisf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSIGNED_FLOAT (SFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1195 */
rtx
gen_floatunsdisf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSIGNED_FLOAT (SFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1195 */
rtx
gen_floatunssidf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSIGNED_FLOAT (DFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1195 */
rtx
gen_floatunsdidf2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSIGNED_FLOAT (DFmode,
	operand1));
}

/* ../../gcc/config/riscv/riscv.md:1204 */
rtx
gen_lrintsfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	12));
}

/* ../../gcc/config/riscv/riscv.md:1204 */
rtx
gen_lroundsfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	13));
}

/* ../../gcc/config/riscv/riscv.md:1204 */
rtx
gen_lrintsfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	12));
}

/* ../../gcc/config/riscv/riscv.md:1204 */
rtx
gen_lroundsfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	13));
}

/* ../../gcc/config/riscv/riscv.md:1204 */
rtx
gen_lrintdfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	12));
}

/* ../../gcc/config/riscv/riscv.md:1204 */
rtx
gen_lrounddfsi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	13));
}

/* ../../gcc/config/riscv/riscv.md:1204 */
rtx
gen_lrintdfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	12));
}

/* ../../gcc/config/riscv/riscv.md:1204 */
rtx
gen_lrounddfdi2 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	13));
}

/* ../../gcc/config/riscv/riscv.md:1225 */
rtx
gen_got_loadsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	3));
}

/* ../../gcc/config/riscv/riscv.md:1225 */
rtx
gen_got_loaddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	3));
}

/* ../../gcc/config/riscv/riscv.md:1235 */
rtx
gen_tls_add_tp_lesi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	5));
}

/* ../../gcc/config/riscv/riscv.md:1235 */
rtx
gen_tls_add_tp_ledi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		operand3),
	5));
}

/* ../../gcc/config/riscv/riscv.md:1247 */
rtx
gen_got_load_tls_gdsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	7));
}

/* ../../gcc/config/riscv/riscv.md:1247 */
rtx
gen_got_load_tls_gddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	7));
}

/* ../../gcc/config/riscv/riscv.md:1257 */
rtx
gen_got_load_tls_iesi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	6));
}

/* ../../gcc/config/riscv/riscv.md:1257 */
rtx
gen_got_load_tls_iedi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	6));
}

/* ../../gcc/config/riscv/riscv.md:1267 */
rtx
gen_auipcsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (3,
		operand1,
		operand2,
		pc_rtx),
	8));
}

/* ../../gcc/config/riscv/riscv.md:1267 */
rtx
gen_auipcdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (3,
		operand1,
		operand2,
		pc_rtx),
	8));
}

/* ../../gcc/config/riscv/riscv.md:1552 */
rtx
gen_fence (void)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	8);
}

/* ../../gcc/config/riscv/riscv.md:1557 */
rtx
gen_fence_i (void)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	9);
}

/* ../../gcc/config/riscv/riscv.md:1574 */
rtx
gen_ashlsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1574 */
rtx
gen_ashrsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ASHIFTRT (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1574 */
rtx
gen_lshrsi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_LSHIFTRT (SImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1629 */
rtx
gen_ashldi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1629 */
rtx
gen_ashrdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_ASHIFTRT (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1629 */
rtx
gen_lshrdi3 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_LSHIFTRT (DImode,
	operand1,
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:1830 */
rtx
gen_zero_extendsidi2_shifted (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_AND (DImode,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2),
	operand3)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* ../../gcc/config/riscv/riscv.md:2139 */
rtx
gen_jump (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (pc_rtx,
	gen_rtx_LABEL_REF (VOIDmode,
	operand0));
}

/* ../../gcc/config/riscv/riscv.md:2159 */
rtx
gen_indirect_jumpsi (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (pc_rtx,
	operand0);
}

/* ../../gcc/config/riscv/riscv.md:2159 */
rtx
gen_indirect_jumpdi (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (pc_rtx,
	operand0);
}

/* ../../gcc/config/riscv/riscv.md:2183 */
rtx
gen_tablejumpsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (pc_rtx,
	operand0),
		gen_rtx_USE (VOIDmode,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1))));
}

/* ../../gcc/config/riscv/riscv.md:2183 */
rtx
gen_tablejumpdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (pc_rtx,
	operand0),
		gen_rtx_USE (VOIDmode,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1))));
}

/* ../../gcc/config/riscv/riscv.md:2211 */
rtx
gen_blockage (void)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	7);
}

/* ../../gcc/config/riscv/riscv.md:2242 */
rtx
gen_simple_return (void)
{
  return simple_return_rtx;
}

/* ../../gcc/config/riscv/riscv.md:2253 */
rtx
gen_simple_return_internal (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		simple_return_rtx,
		gen_rtx_USE (VOIDmode,
	operand0)));
}

/* ../../gcc/config/riscv/riscv.md:2281 */
rtx
gen_eh_set_lr_si (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_UNSPEC (VOIDmode,
	gen_rtvec (1,
		operand0),
	0),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* ../../gcc/config/riscv/riscv.md:2287 */
rtx
gen_eh_set_lr_di (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_UNSPEC (VOIDmode,
	gen_rtvec (1,
		operand0),
	0),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* ../../gcc/config/riscv/riscv.md:2303 */
rtx
gen_eh_return_internal (void)
{
  return gen_rtx_EH_RETURN (VOIDmode);
}

/* ../../gcc/config/riscv/riscv.md:2330 */
rtx
gen_sibcall_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand0),
	operand1);
}

/* ../../gcc/config/riscv/riscv.md:2352 */
rtx
gen_sibcall_value_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2));
}

/* ../../gcc/config/riscv/riscv.md:2375 */
rtx
gen_call_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand0),
	operand1),
		gen_hard_reg_clobber (SImode, 1)));
}

/* ../../gcc/config/riscv/riscv.md:2398 */
rtx
gen_call_value_internal (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_CALL (VOIDmode,
	gen_rtx_MEM (SImode,
	operand1),
	operand2)),
		gen_hard_reg_clobber (SImode, 1)));
}

/* ../../gcc/config/riscv/riscv.md:2433 */
rtx
gen_nop (void)
{
  return const0_rtx;
}

/* ../../gcc/config/riscv/riscv.md:2440 */
rtx
gen_trap (void)
{
  return gen_rtx_TRAP_IF (VOIDmode,
	const1_rtx,
	const0_rtx);
}

/* ../../gcc/config/riscv/riscv.md:2449 */
rtx
gen_gpr_save (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return operand1;
}

/* ../../gcc/config/riscv/riscv.md:2456 */
rtx
gen_gpr_restore (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		operand0),
	1);
}

/* ../../gcc/config/riscv/riscv.md:2461 */
rtx
gen_gpr_restore_return (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		ret_rtx,
		gen_rtx_USE (VOIDmode,
	operand0),
		const0_rtx));
}

/* ../../gcc/config/riscv/riscv.md:2468 */
rtx
gen_riscv_frflags (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	2));
}

/* ../../gcc/config/riscv/riscv.md:2474 */
rtx
gen_riscv_fsflags (rtx operand0 ATTRIBUTE_UNUSED)
{
  return gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		operand0),
	3);
}

/* ../../gcc/config/riscv/riscv.md:2479 */
rtx
gen_riscv_mret (void)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		ret_rtx,
		gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	4)));
}

/* ../../gcc/config/riscv/riscv.md:2485 */
rtx
gen_riscv_sret (void)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		ret_rtx,
		gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	5)));
}

/* ../../gcc/config/riscv/riscv.md:2491 */
rtx
gen_riscv_uret (void)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		ret_rtx,
		gen_rtx_UNSPEC_VOLATILE (VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	6)));
}

/* ../../gcc/config/riscv/riscv.md:2497 */
rtx
gen_stack_tiesi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (gen_rtx_MEM (BLKmode,
	gen_rtx_SCRATCH (VOIDmode)),
	gen_rtx_UNSPEC (BLKmode,
	gen_rtvec (2,
		operand0,
		operand1),
	14));
}

/* ../../gcc/config/riscv/riscv.md:2497 */
rtx
gen_stack_tiedi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (gen_rtx_MEM (BLKmode,
	gen_rtx_SCRATCH (VOIDmode)),
	gen_rtx_UNSPEC (BLKmode,
	gen_rtvec (2,
		operand0,
		operand1),
	14));
}

/* ../../gcc/config/riscv/riscv.md:2555 */
rtx
gen_stack_protect_set_si (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (1,
		operand1),
	10)),
		gen_rtx_SET (gen_rtx_SCRATCH (SImode),
	const0_rtx)));
}

/* ../../gcc/config/riscv/riscv.md:2555 */
rtx
gen_stack_protect_set_di (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (1,
		operand1),
	10)),
		gen_rtx_SET (gen_rtx_SCRATCH (DImode),
	const0_rtx)));
}

/* ../../gcc/config/riscv/riscv.md:2597 */
rtx
gen_stack_protect_test_si (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	11)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* ../../gcc/config/riscv/riscv.md:2597 */
rtx
gen_stack_protect_test_di (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	11)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* ../../gcc/config/riscv/sync.md:51 */
rtx
gen_mem_thread_fence_1 (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (BLKmode,
	gen_rtvec (1,
		copy_rtx (operand0)),
	19)),
		operand1));
}

/* ../../gcc/config/riscv/sync.md:61 */
rtx
gen_atomic_storesi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	18));
}

/* ../../gcc/config/riscv/sync.md:61 */
rtx
gen_atomic_storedi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	18));
}

/* ../../gcc/config/riscv/sync.md:71 */
rtx
gen_atomic_addsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_PLUS (SImode,
	operand0,
	operand1),
		operand2),
	16));
}

/* ../../gcc/config/riscv/sync.md:71 */
rtx
gen_atomic_orsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_IOR (SImode,
	operand0,
	operand1),
		operand2),
	16));
}

/* ../../gcc/config/riscv/sync.md:71 */
rtx
gen_atomic_xorsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_XOR (SImode,
	operand0,
	operand1),
		operand2),
	16));
}

/* ../../gcc/config/riscv/sync.md:71 */
rtx
gen_atomic_andsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_AND (SImode,
	operand0,
	operand1),
		operand2),
	16));
}

/* ../../gcc/config/riscv/sync.md:71 */
rtx
gen_atomic_adddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_PLUS (DImode,
	operand0,
	operand1),
		operand2),
	16));
}

/* ../../gcc/config/riscv/sync.md:71 */
rtx
gen_atomic_ordi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_IOR (DImode,
	operand0,
	operand1),
		operand2),
	16));
}

/* ../../gcc/config/riscv/sync.md:71 */
rtx
gen_atomic_xordi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_XOR (DImode,
	operand0,
	operand1),
		operand2),
	16));
}

/* ../../gcc/config/riscv/sync.md:71 */
rtx
gen_atomic_anddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED)
{
  return gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_AND (DImode,
	operand0,
	operand1),
		operand2),
	16));
}

/* ../../gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_fetch_addsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_SET (copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_PLUS (SImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	16))));
}

/* ../../gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_fetch_orsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_SET (copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_IOR (SImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	16))));
}

/* ../../gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_fetch_xorsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_SET (copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_XOR (SImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	16))));
}

/* ../../gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_fetch_andsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_SET (copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		gen_rtx_AND (SImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	16))));
}

/* ../../gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_fetch_adddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_SET (copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_PLUS (DImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	16))));
}

/* ../../gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_fetch_ordi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_SET (copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_IOR (DImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	16))));
}

/* ../../gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_fetch_xordi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_SET (copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_XOR (DImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	16))));
}

/* ../../gcc/config/riscv/sync.md:82 */
rtx
gen_atomic_fetch_anddi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_SET (copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		gen_rtx_AND (DImode,
	copy_rtx (operand1),
	operand2),
		operand3),
	16))));
}

/* ../../gcc/config/riscv/sync.md:95 */
rtx
gen_atomic_exchangesi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (2,
		operand1,
		operand3),
	17)),
		gen_rtx_SET (copy_rtx (operand1),
	operand2)));
}

/* ../../gcc/config/riscv/sync.md:95 */
rtx
gen_atomic_exchangedi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (2,
		operand1,
		operand3),
	17)),
		gen_rtx_SET (copy_rtx (operand1),
	operand2)));
}

/* ../../gcc/config/riscv/sync.md:107 */
rtx
gen_atomic_cas_value_strongsi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED,
	rtx operand4 ATTRIBUTE_UNUSED,
	rtx operand5 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_SET (copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (SImode,
	gen_rtvec (4,
		operand2,
		operand3,
		operand4,
		operand5),
	15)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* ../../gcc/config/riscv/sync.md:107 */
rtx
gen_atomic_cas_value_strongdi (rtx operand0 ATTRIBUTE_UNUSED,
	rtx operand1 ATTRIBUTE_UNUSED,
	rtx operand2 ATTRIBUTE_UNUSED,
	rtx operand3 ATTRIBUTE_UNUSED,
	rtx operand4 ATTRIBUTE_UNUSED,
	rtx operand5 ATTRIBUTE_UNUSED)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_SET (copy_rtx (operand1),
	gen_rtx_UNSPEC_VOLATILE (DImode,
	gen_rtvec (4,
		operand2,
		operand3,
		operand4,
		operand5),
	15)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* ../../gcc/config/riscv/riscv.md:647 */
rtx
gen_mulditi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 652 "../../gcc/config/riscv/riscv.md"
{
  rtx low = gen_reg_rtx (DImode);
  emit_insn (gen_muldi3 (low, operands[1], operands[2]));

  rtx high = gen_reg_rtx (DImode);
  emit_insn (gen_muldi3_highpart (high, operands[1], operands[2]));

  emit_move_insn (gen_lowpart (DImode, operands[0]), low);
  emit_move_insn (gen_highpart (DImode, operands[0]), high);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_MULT (TImode,
	gen_rtx_SIGN_EXTEND (TImode,
	operand1),
	gen_rtx_SIGN_EXTEND (TImode,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:647 */
rtx
gen_umulditi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 652 "../../gcc/config/riscv/riscv.md"
{
  rtx low = gen_reg_rtx (DImode);
  emit_insn (gen_muldi3 (low, operands[1], operands[2]));

  rtx high = gen_reg_rtx (DImode);
  emit_insn (gen_umuldi3_highpart (high, operands[1], operands[2]));

  emit_move_insn (gen_lowpart (DImode, operands[0]), low);
  emit_move_insn (gen_highpart (DImode, operands[0]), high);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	operand1),
	gen_rtx_ZERO_EXTEND (TImode,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:678 */
rtx
gen_usmulditi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 683 "../../gcc/config/riscv/riscv.md"
{
  rtx low = gen_reg_rtx (DImode);
  emit_insn (gen_muldi3 (low, operands[1], operands[2]));

  rtx high = gen_reg_rtx (DImode);
  emit_insn (gen_usmuldi3_highpart (high, operands[1], operands[2]));

  emit_move_insn (gen_lowpart (DImode, operands[0]), low);
  emit_move_insn (gen_highpart (DImode, operands[0]), high);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_MULT (TImode,
	gen_rtx_ZERO_EXTEND (TImode,
	operand1),
	gen_rtx_SIGN_EXTEND (TImode,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:709 */
rtx
gen_mulsidi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 716 "../../gcc/config/riscv/riscv.md"
{
  rtx temp = gen_reg_rtx (SImode);
  emit_insn (gen_mulsi3 (temp, operands[1], operands[2]));
  emit_insn (gen_mulsi3_highpart (riscv_subword (operands[0], true),
				     operands[1], operands[2]));
  emit_insn (gen_movsi (riscv_subword (operands[0], false), temp));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_SIGN_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:709 */
rtx
gen_umulsidi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 716 "../../gcc/config/riscv/riscv.md"
{
  rtx temp = gen_reg_rtx (SImode);
  emit_insn (gen_mulsi3 (temp, operands[1], operands[2]));
  emit_insn (gen_umulsi3_highpart (riscv_subword (operands[0], true),
				     operands[1], operands[2]));
  emit_insn (gen_movsi (riscv_subword (operands[0], false), temp));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_ZERO_EXTEND (DImode,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:740 */
rtx
gen_usmulsidi3 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 747 "../../gcc/config/riscv/riscv.md"
{
  rtx temp = gen_reg_rtx (SImode);
  emit_insn (gen_mulsi3 (temp, operands[1], operands[2]));
  emit_insn (gen_usmulsi3_highpart (riscv_subword (operands[0], true),
				     operands[1], operands[2]));
  emit_insn (gen_movsi (riscv_subword (operands[0], false), temp));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_MULT (DImode,
	gen_rtx_ZERO_EXTEND (DImode,
	operand1),
	gen_rtx_SIGN_EXTEND (DImode,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1060 */
extern rtx_insn *gen_split_1 (rtx_insn *, rtx *);
rtx_insn *
gen_split_1 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_1 (riscv.md:1060)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1075 "../../gcc/config/riscv/riscv.md"
{ operands[1] = gen_lowpart (DImode, operands[1]); }
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (copy_rtx (operand0),
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand0),
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1079 */
extern rtx_insn *gen_split_2 (rtx_insn *, rtx *);
rtx_insn *
gen_split_2 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_2 (riscv.md:1079)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1094 "../../gcc/config/riscv/riscv.md"
{
    operands[1] = gen_lowpart (SImode, operands[1]);
    operands[2] = GEN_INT(GET_MODE_BITSIZE(SImode) - 16);
  }
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (copy_rtx (operand0),
	gen_rtx_LSHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1079 */
extern rtx_insn *gen_split_3 (rtx_insn *, rtx *);
rtx_insn *
gen_split_3 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_3 (riscv.md:1079)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1094 "../../gcc/config/riscv/riscv.md"
{
    operands[1] = gen_lowpart (DImode, operands[1]);
    operands[2] = GEN_INT(GET_MODE_BITSIZE(DImode) - 16);
  }
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (copy_rtx (operand0),
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1130 */
extern rtx_insn *gen_split_4 (rtx_insn *, rtx *);
rtx_insn *
gen_split_4 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_4 (riscv.md:1130)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1143 "../../gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (QImode));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1130 */
extern rtx_insn *gen_split_5 (rtx_insn *, rtx *);
rtx_insn *
gen_split_5 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_5 (riscv.md:1130)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1143 "../../gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (QImode));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1130 */
extern rtx_insn *gen_split_6 (rtx_insn *, rtx *);
rtx_insn *
gen_split_6 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_6 (riscv.md:1130)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1143 "../../gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (QImode));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1130 */
extern rtx_insn *gen_split_7 (rtx_insn *, rtx *);
rtx_insn *
gen_split_7 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_7 (riscv.md:1130)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1143 "../../gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (HImode));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1130 */
extern rtx_insn *gen_split_8 (rtx_insn *, rtx *);
rtx_insn *
gen_split_8 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_8 (riscv.md:1130)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1143 "../../gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (HImode));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1130 */
extern rtx_insn *gen_split_9 (rtx_insn *, rtx *);
rtx_insn *
gen_split_9 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_9 (riscv.md:1130)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1143 "../../gcc/config/riscv/riscv.md"
{
  operands[0] = gen_lowpart (SImode, operands[0]);
  operands[1] = gen_lowpart (SImode, operands[1]);
  operands[2] = GEN_INT (GET_MODE_BITSIZE (SImode)
			 - GET_MODE_BITSIZE (HImode));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (copy_rtx (operand0),
	gen_rtx_ASHIFTRT (SImode,
	copy_rtx (operand0),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1294 */
extern rtx_insn *gen_split_10 (rtx_insn *, rtx *);
rtx_insn *
gen_split_10 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_10 (riscv.md:1294)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1300 "../../gcc/config/riscv/riscv.md"
{
  riscv_move_integer (operands[2], operands[0], INTVAL (operands[1]),
		      SImode, TRUE);
  DONE;
}
#undef DONE
#undef FAIL
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1294 */
extern rtx_insn *gen_split_11 (rtx_insn *, rtx *);
rtx_insn *
gen_split_11 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_11 (riscv.md:1294)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1300 "../../gcc/config/riscv/riscv.md"
{
  riscv_move_integer (operands[2], operands[0], INTVAL (operands[1]),
		      DImode, TRUE);
  DONE;
}
#undef DONE
#undef FAIL
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1307 */
extern rtx_insn *gen_split_12 (rtx_insn *, rtx *);
rtx_insn *
gen_split_12 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_12 (riscv.md:1307)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1313 "../../gcc/config/riscv/riscv.md"
{
  riscv_split_symbol (operands[2], operands[1],
		      MAX_MACHINE_MODE, &operands[3], TRUE);
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  emit_insn (gen_rtx_SET (operand0,
	operand3));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1307 */
extern rtx_insn *gen_split_13 (rtx_insn *, rtx *);
rtx_insn *
gen_split_13 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_13 (riscv.md:1307)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1313 "../../gcc/config/riscv/riscv.md"
{
  riscv_split_symbol (operands[2], operands[1],
		      MAX_MACHINE_MODE, &operands[3], TRUE);
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  emit_insn (gen_rtx_SET (operand0,
	operand3));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1320 */
rtx
gen_movdi (rtx operand0,
	rtx operand1)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1324 "../../gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (DImode, operands[0], operands[1]))
    DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1351 */
rtx
gen_movsi (rtx operand0,
	rtx operand1)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1355 "../../gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (SImode, operands[0], operands[1]))
    DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1376 */
rtx
gen_movhi (rtx operand0,
	rtx operand1)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1380 "../../gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (HImode, operands[0], operands[1]))
    DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1418 */
rtx
gen_movqi (rtx operand0,
	rtx operand1)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1422 "../../gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (QImode, operands[0], operands[1]))
    DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1438 */
rtx
gen_movsf (rtx operand0,
	rtx operand1)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1442 "../../gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (SFmode, operands[0], operands[1]))
    DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1469 */
rtx
gen_movdf (rtx operand0,
	rtx operand1)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1473 "../../gcc/config/riscv/riscv.md"
{
  if (riscv_legitimize_move (DFmode, operands[0], operands[1]))
    DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_insn (gen_rtx_SET (operand0,
	operand1));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1510 */
extern rtx_insn *gen_split_14 (rtx_insn *, rtx *);
rtx_insn *
gen_split_14 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_14 (riscv.md:1510)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1516 "../../gcc/config/riscv/riscv.md"
{
  riscv_split_doubleword_move (operands[0], operands[1]);
  DONE;
}
#undef DONE
#undef FAIL
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1510 */
extern rtx_insn *gen_split_15 (rtx_insn *, rtx *);
rtx_insn *
gen_split_15 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_15 (riscv.md:1510)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1516 "../../gcc/config/riscv/riscv.md"
{
  riscv_split_doubleword_move (operands[0], operands[1]);
  DONE;
}
#undef DONE
#undef FAIL
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1521 */
rtx
gen_cpymemsi (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1527 "../../gcc/config/riscv/riscv.md"
{
  if (riscv_expand_block_move (operands[0], operands[1], operands[2]))
    DONE;
  else
    FAIL;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_SET (operand0,
	operand1),
		gen_rtx_USE (VOIDmode,
	operand2),
		gen_rtx_USE (VOIDmode,
	operand3))), false);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1536 */
rtx
gen_clear_cache (rtx operand0,
	rtx operand1)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1540 "../../gcc/config/riscv/riscv.md"
{
#ifdef ICACHE_FLUSH_FUNC
  emit_library_call (gen_rtx_SYMBOL_REF (Pmode, ICACHE_FLUSH_FUNC),
		     LCT_NORMAL, VOIDmode, operands[0], Pmode,
		     operands[1], Pmode, const0_rtx, Pmode);
#else
  if (TARGET_ZIFENCEI)
    emit_insn (gen_fence_i ());
#endif
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit (operand0, true);
  emit (operand1, false);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1590 */
extern rtx_insn *gen_split_16 (rtx_insn *, rtx *);
rtx_insn *
gen_split_16 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_16 (riscv.md:1590)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1605 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1590 */
extern rtx_insn *gen_split_17 (rtx_insn *, rtx *);
rtx_insn *
gen_split_17 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_17 (riscv.md:1590)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1605 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFTRT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1590 */
extern rtx_insn *gen_split_18 (rtx_insn *, rtx *);
rtx_insn *
gen_split_18 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_18 (riscv.md:1590)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1605 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_LSHIFTRT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1609 */
extern rtx_insn *gen_split_19 (rtx_insn *, rtx *);
rtx_insn *
gen_split_19 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_19 (riscv.md:1609)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1625 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1609 */
extern rtx_insn *gen_split_20 (rtx_insn *, rtx *);
rtx_insn *
gen_split_20 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_20 (riscv.md:1609)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1625 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFTRT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1609 */
extern rtx_insn *gen_split_21 (rtx_insn *, rtx *);
rtx_insn *
gen_split_21 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_21 (riscv.md:1609)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1625 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_LSHIFTRT (SImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1645 */
extern rtx_insn *gen_split_22 (rtx_insn *, rtx *);
rtx_insn *
gen_split_22 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_22 (riscv.md:1645)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1661 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1645 */
extern rtx_insn *gen_split_23 (rtx_insn *, rtx *);
rtx_insn *
gen_split_23 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_23 (riscv.md:1645)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1661 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFTRT (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1645 */
extern rtx_insn *gen_split_24 (rtx_insn *, rtx *);
rtx_insn *
gen_split_24 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_24 (riscv.md:1645)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1661 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_LSHIFTRT (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1665 */
extern rtx_insn *gen_split_25 (rtx_insn *, rtx *);
rtx_insn *
gen_split_25 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_25 (riscv.md:1665)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1681 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1665 */
extern rtx_insn *gen_split_26 (rtx_insn *, rtx *);
rtx_insn *
gen_split_26 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_26 (riscv.md:1665)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1681 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFTRT (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1665 */
extern rtx_insn *gen_split_27 (rtx_insn *, rtx *);
rtx_insn *
gen_split_27 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_27 (riscv.md:1665)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1681 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_LSHIFTRT (DImode,
	operand1,
	operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1700 */
extern rtx_insn *gen_split_28 (rtx_insn *, rtx *);
rtx_insn *
gen_split_28 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_28 (riscv.md:1700)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1718 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1700 */
extern rtx_insn *gen_split_29 (rtx_insn *, rtx *);
rtx_insn *
gen_split_29 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_29 (riscv.md:1700)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1718 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_ASHIFTRT (SImode,
	operand1,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1700 */
extern rtx_insn *gen_split_30 (rtx_insn *, rtx *);
rtx_insn *
gen_split_30 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_30 (riscv.md:1700)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1718 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_LSHIFTRT (SImode,
	operand1,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1722 */
extern rtx_insn *gen_split_31 (rtx_insn *, rtx *);
rtx_insn *
gen_split_31 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_31 (riscv.md:1722)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1740 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1722 */
extern rtx_insn *gen_split_32 (rtx_insn *, rtx *);
rtx_insn *
gen_split_32 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_32 (riscv.md:1722)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1740 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_ASHIFTRT (SImode,
	operand1,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1722 */
extern rtx_insn *gen_split_33 (rtx_insn *, rtx *);
rtx_insn *
gen_split_33 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_33 (riscv.md:1722)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1740 "../../gcc/config/riscv/riscv.md"
operands[2] = gen_lowpart (QImode, operands[2]);
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_SIGN_EXTEND (DImode,
	gen_rtx_LSHIFTRT (SImode,
	operand1,
	operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1794 */
extern rtx_insn *gen_split_34 (rtx_insn *, rtx *);
rtx_insn *
gen_split_34 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_34 (riscv.md:1794)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1804 "../../gcc/config/riscv/riscv.md"
{
  /* Op2 is a VOIDmode constant, so get the mode size from op1.  */
  operands[2] = GEN_INT (GET_MODE_BITSIZE (GET_MODE (operands[1]))
			 - exact_log2 (INTVAL (operands[2]) + 1));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  emit_insn (gen_rtx_SET (operand3,
	gen_rtx_ASHIFT (SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_LSHIFTRT (SImode,
	copy_rtx (operand3),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1794 */
extern rtx_insn *gen_split_35 (rtx_insn *, rtx *);
rtx_insn *
gen_split_35 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_35 (riscv.md:1794)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1804 "../../gcc/config/riscv/riscv.md"
{
  /* Op2 is a VOIDmode constant, so get the mode size from op1.  */
  operands[2] = GEN_INT (GET_MODE_BITSIZE (GET_MODE (operands[1]))
			 - exact_log2 (INTVAL (operands[2]) + 1));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  emit_insn (gen_rtx_SET (operand3,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand3),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1812 */
extern rtx_insn *gen_split_36 (rtx_insn *, rtx *);
rtx_insn *
gen_split_36 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_36 (riscv.md:1812)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1822 "../../gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (ctz_hwi (INTVAL (operands[2])));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  emit_insn (gen_rtx_SET (operand3,
	gen_rtx_LSHIFTRT (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (DImode,
	copy_rtx (operand3),
	copy_rtx (operand2))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1830 */
extern rtx_insn *gen_split_37 (rtx_insn *, rtx *);
rtx_insn *
gen_split_37 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_37 (riscv.md:1830)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1844 "../../gcc/config/riscv/riscv.md"
operands[5] = GEN_INT (32 - (INTVAL (operands [2])));
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  operand5 = operands[5];
  (void) operand5;
  emit_insn (gen_rtx_SET (operand4,
	gen_rtx_ASHIFT (DImode,
	operand1,
	const_int_rtx[MAX_SAVED_CONST_INT + (32)])));
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand4),
	operand5)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1872 */
rtx
gen_movsicc (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1878 "../../gcc/config/riscv/riscv.md"
{
  rtx cmp = operands[1];
  /* We only handle word mode integer compares for now.  */
  if (GET_MODE (XEXP (cmp, 0)) != word_mode)
    FAIL;
  riscv_expand_conditional_move (operands[0], operands[2], operands[3],
				 GET_CODE (cmp), XEXP (cmp, 0), XEXP (cmp, 1));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_IF_THEN_ELSE (SImode,
	operand1,
	operand2,
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1872 */
rtx
gen_movdicc (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1878 "../../gcc/config/riscv/riscv.md"
{
  rtx cmp = operands[1];
  /* We only handle word mode integer compares for now.  */
  if (GET_MODE (XEXP (cmp, 0)) != word_mode)
    FAIL;
  riscv_expand_conditional_move (operands[0], operands[2], operands[3],
				 GET_CODE (cmp), XEXP (cmp, 0), XEXP (cmp, 1));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_IF_THEN_ELSE (DImode,
	operand1,
	operand2,
	operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1905 */
rtx
gen_condjump (rtx operand0,
	rtx operand1)
{
  return gen_rtx_SET (pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	operand0,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx));
}

/* ../../gcc/config/riscv/riscv.md:1911 */
rtx
gen_cbranchqi4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1919 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_conditional_branch (operands[3], GET_CODE (operands[0]),
				   operands[1], operands[2]);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), VOIDmode,
		operand1,
		operand2),
	gen_rtx_LABEL_REF (VOIDmode,
	operand3),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1911 */
rtx
gen_cbranchsi4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1919 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_conditional_branch (operands[3], GET_CODE (operands[0]),
				   operands[1], operands[2]);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), VOIDmode,
		operand1,
		operand2),
	gen_rtx_LABEL_REF (VOIDmode,
	operand3),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1911 */
rtx
gen_cbranchdi4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1919 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_conditional_branch (operands[3], GET_CODE (operands[0]),
				   operands[1], operands[2]);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), VOIDmode,
		operand1,
		operand2),
	gen_rtx_LABEL_REF (VOIDmode,
	operand3),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1925 */
rtx
gen_cbranchsf4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1933 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_conditional_branch (operands[3], GET_CODE (operands[0]),
				   operands[1], operands[2]);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), VOIDmode,
		operand1,
		operand2),
	gen_rtx_LABEL_REF (VOIDmode,
	operand3),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1925 */
rtx
gen_cbranchdf4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1933 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_conditional_branch (operands[3], GET_CODE (operands[0]),
				   operands[1], operands[2]);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), VOIDmode,
		operand1,
		operand2),
	gen_rtx_LABEL_REF (VOIDmode,
	operand3),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1939 */
extern rtx_insn *gen_split_38 (rtx_insn *, rtx *);
rtx_insn *
gen_split_38 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_38 (riscv.md:1939)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1960 "../../gcc/config/riscv/riscv.md"
{
  int shift = GET_MODE_BITSIZE (SImode) - 1 - INTVAL (operands[3]);
  operands[3] = GEN_INT (shift);

  if (GET_CODE (operands[0]) == EQ)
    operands[0] = gen_rtx_GE (SImode, operands[4], const0_rtx);
  else
    operands[0] = gen_rtx_LT (SImode, operands[4], const0_rtx);
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (operand4,
	gen_rtx_ASHIFT (SImode,
	operand2,
	operand3)));
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), GET_MODE (operand0),
		copy_rtx (operand4),
		const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1939 */
extern rtx_insn *gen_split_39 (rtx_insn *, rtx *);
rtx_insn *
gen_split_39 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_39 (riscv.md:1939)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1960 "../../gcc/config/riscv/riscv.md"
{
  int shift = GET_MODE_BITSIZE (DImode) - 1 - INTVAL (operands[3]);
  operands[3] = GEN_INT (shift);

  if (GET_CODE (operands[0]) == EQ)
    operands[0] = gen_rtx_GE (DImode, operands[4], const0_rtx);
  else
    operands[0] = gen_rtx_LT (DImode, operands[4], const0_rtx);
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (operand4,
	gen_rtx_ASHIFT (DImode,
	operand2,
	operand3)));
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), GET_MODE (operand0),
		copy_rtx (operand4),
		const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1970 */
extern rtx_insn *gen_split_40 (rtx_insn *, rtx *);
rtx_insn *
gen_split_40 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_40 (riscv.md:1970)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1991 "../../gcc/config/riscv/riscv.md"
{
  operands[3] = GEN_INT (GET_MODE_BITSIZE (SImode) - INTVAL (operands[3]));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (operand4,
	gen_rtx_ASHIFT (SImode,
	operand2,
	operand3)));
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), GET_MODE (operand0),
		copy_rtx (operand4),
		const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:1970 */
extern rtx_insn *gen_split_41 (rtx_insn *, rtx *);
rtx_insn *
gen_split_41 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_41 (riscv.md:1970)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 1991 "../../gcc/config/riscv/riscv.md"
{
  operands[3] = GEN_INT (GET_MODE_BITSIZE (DImode) - INTVAL (operands[3]));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  emit_insn (gen_rtx_SET (operand4,
	gen_rtx_ASHIFT (DImode,
	operand2,
	operand3)));
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	gen_rtx_IF_THEN_ELSE (VOIDmode,
	gen_rtx_fmt_ee (GET_CODE (operand0), GET_MODE (operand0),
		copy_rtx (operand4),
		const0_rtx),
	gen_rtx_LABEL_REF (VOIDmode,
	operand1),
	pc_rtx)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2004 */
rtx
gen_cstoresi4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2010 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_int_scc (operands[0], GET_CODE (operands[1]), operands[2],
			operands[3]);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_fmt_ee (GET_CODE (operand1), SImode,
		operand2,
		operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2004 */
rtx
gen_cstoredi4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2010 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_int_scc (operands[0], GET_CODE (operands[1]), operands[2],
			operands[3]);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_fmt_ee (GET_CODE (operand1), SImode,
		operand2,
		operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2016 */
rtx
gen_cstoresf4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2022 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_float_scc (operands[0], GET_CODE (operands[1]), operands[2],
			  operands[3]);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_fmt_ee (GET_CODE (operand1), SImode,
		operand2,
		operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2016 */
rtx
gen_cstoredf4 (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2022 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_float_scc (operands[0], GET_CODE (operands[1]), operands[2],
			  operands[3]);
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_fmt_ee (GET_CODE (operand1), SImode,
		operand2,
		operand3)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2038 */
rtx
gen_flt_quietsfsi4 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	9)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* ../../gcc/config/riscv/riscv.md:2038 */
rtx
gen_fle_quietsfsi4 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	10)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* ../../gcc/config/riscv/riscv.md:2038 */
rtx
gen_flt_quietsfdi4 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	9)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* ../../gcc/config/riscv/riscv.md:2038 */
rtx
gen_fle_quietsfdi4 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	10)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* ../../gcc/config/riscv/riscv.md:2038 */
rtx
gen_flt_quietdfsi4 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	9)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* ../../gcc/config/riscv/riscv.md:2038 */
rtx
gen_fle_quietdfsi4 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (SImode,
	gen_rtvec (2,
		operand1,
		operand2),
	10)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode))));
}

/* ../../gcc/config/riscv/riscv.md:2038 */
rtx
gen_flt_quietdfdi4 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	9)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* ../../gcc/config/riscv/riscv.md:2038 */
rtx
gen_fle_quietdfdi4 (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  return gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_UNSPEC (DImode,
	gen_rtvec (2,
		operand1,
		operand2),
	10)),
		gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode))));
}

/* ../../gcc/config/riscv/riscv.md:2147 */
rtx
gen_indirect_jump (rtx operand0)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2150 "../../gcc/config/riscv/riscv.md"
{
  operands[0] = force_reg (Pmode, operands[0]);
  if (Pmode == SImode)
    emit_jump_insn (gen_indirect_jumpsi (operands[0]));
  else
    emit_jump_insn (gen_indirect_jumpdi (operands[0]));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
  }
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	operand0));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2166 */
rtx
gen_tablejump (rtx operand0,
	rtx operand1)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2170 "../../gcc/config/riscv/riscv.md"
{
  if (CASE_VECTOR_PC_RELATIVE)
      operands[0] = expand_simple_binop (Pmode, PLUS, operands[0],
					 gen_rtx_LABEL_REF (Pmode, operands[1]),
					 NULL_RTX, 0, OPTAB_DIRECT);

  if (CASE_VECTOR_PC_RELATIVE && Pmode == DImode)
    emit_jump_insn (gen_tablejumpdi (operands[0], operands[1]));
  else
    emit_jump_insn (gen_tablejumpsi (operands[0], operands[1]));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit_jump_insn (gen_rtx_SET (pc_rtx,
	operand0));
  emit_insn (gen_rtx_USE (VOIDmode,
	gen_rtx_LABEL_REF (VOIDmode,
	operand1)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2199 */
rtx
gen_prologue (void)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2202 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_prologue ();
  DONE;
}
#undef DONE
#undef FAIL
  }
  emit_insn (const1_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2218 */
rtx
gen_epilogue (void)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2221 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_epilogue (NORMAL_RETURN);
  DONE;
}
#undef DONE
#undef FAIL
  }
  emit_insn (const_int_rtx[MAX_SAVED_CONST_INT + (2)]);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2226 */
rtx
gen_sibcall_epilogue (void)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2229 "../../gcc/config/riscv/riscv.md"
{
  riscv_expand_epilogue (SIBCALL_RETURN);
  DONE;
}
#undef DONE
#undef FAIL
  }
  emit_insn (const_int_rtx[MAX_SAVED_CONST_INT + (2)]);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2237 */
rtx
gen_return (void)
{
  return simple_return_rtx;
}

/* ../../gcc/config/riscv/riscv.md:2262 */
rtx
gen_eh_return (rtx operand0)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2265 "../../gcc/config/riscv/riscv.md"
{
  if (GET_MODE (operands[0]) != word_mode)
    operands[0] = convert_to_mode (word_mode, operands[0], 0);
  if (TARGET_64BIT)
    emit_insn (gen_eh_set_lr_di (operands[0]));
  else
    emit_insn (gen_eh_set_lr_si (operands[0]));

  emit_jump_insn (gen_eh_return_internal ());
  emit_barrier ();
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
  }
  emit_insn (gen_rtx_USE (VOIDmode,
	operand0));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2293 */
extern rtx_insn *gen_split_42 (rtx_insn *, rtx *);
rtx_insn *
gen_split_42 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_42 (riscv.md:2293)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2298 "../../gcc/config/riscv/riscv.md"
{
  riscv_set_return_address (operands[0], operands[1]);
  DONE;
}
#undef DONE
#undef FAIL
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2303 */
extern rtx_insn *gen_split_43 (rtx_insn *, rtx *);
rtx_insn *
gen_split_43 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands ATTRIBUTE_UNUSED)
{
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_split_43 (riscv.md:2303)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2309 "../../gcc/config/riscv/riscv.md"
riscv_expand_epilogue (EXCEPTION_RETURN); DONE;
#undef DONE
#undef FAIL
  emit_insn (const0_rtx);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2318 */
rtx
gen_sibcall (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2324 "../../gcc/config/riscv/riscv.md"
{
  rtx target = riscv_legitimize_call_address (XEXP (operands[0], 0));
  emit_call_insn (gen_sibcall_internal (target, operands[1]));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_CALL (VOIDmode,
	operand0,
	operand1),
		gen_rtx_USE (VOIDmode,
	operand2),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2340 */
rtx
gen_sibcall_value (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2346 "../../gcc/config/riscv/riscv.md"
{
  rtx target = riscv_legitimize_call_address (XEXP (operands[1], 0));
  emit_call_insn (gen_sibcall_value_internal (operands[0], target, operands[2]));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_CALL (VOIDmode,
	operand1,
	operand2)),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2363 */
rtx
gen_call (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2369 "../../gcc/config/riscv/riscv.md"
{
  rtx target = riscv_legitimize_call_address (XEXP (operands[0], 0));
  emit_call_insn (gen_call_internal (target, operands[1]));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_CALL (VOIDmode,
	operand0,
	operand1),
		gen_rtx_USE (VOIDmode,
	operand2),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2386 */
rtx
gen_call_value (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[4];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2392 "../../gcc/config/riscv/riscv.md"
{
  rtx target = riscv_legitimize_call_address (XEXP (operands[1], 0));
  emit_call_insn (gen_call_value_internal (operands[0], target, operands[2]));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (2,
		gen_rtx_SET (operand0,
	gen_rtx_CALL (VOIDmode,
	operand1,
	operand2)),
		gen_rtx_USE (VOIDmode,
	operand3))));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2412 */
rtx
gen_untyped_call (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2418 "../../gcc/config/riscv/riscv.md"
{
  int i;

  emit_call_insn (gen_call (operands[0], const0_rtx, NULL, const0_rtx));

  for (i = 0; i < XVECLEN (operands[2], 0); i++)
    {
      rtx set = XVECEXP (operands[2], 0, i);
      riscv_emit_move (SET_DEST (set), SET_SRC (set));
    }

  emit_insn (gen_blockage ());
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit_call_insn (gen_rtx_PARALLEL (VOIDmode,
	gen_rtvec (3,
		gen_rtx_CALL (VOIDmode,
	operand0,
	const0_rtx),
		operand1,
		operand2)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2512 */
rtx
gen_restore_stack_nonlocal (rtx operand0,
	rtx operand1)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2516 "../../gcc/config/riscv/riscv.md"
{
  emit_move_insn (operands[0], operands[1]);
  /* Prevent the following hard fp restore from being moved before the move
     insn above which uses a copy of the soft fp reg.  */
  emit_clobber (gen_rtx_MEM (BLKmode, hard_frame_pointer_rtx));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit (operand0, true);
  emit (operand1, false);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2525 */
rtx
gen_get_thread_pointersi (rtx operand0)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2529 "../../gcc/config/riscv/riscv.md"
{}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_REG (SImode,
	4)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2525 */
rtx
gen_get_thread_pointerdi (rtx operand0)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2529 "../../gcc/config/riscv/riscv.md"
{}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
  }
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_REG (DImode,
	4)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2533 */
rtx
gen_stack_protect_set (rtx operand0,
	rtx operand1)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[2];
    operands[0] = operand0;
    operands[1] = operand1;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2537 "../../gcc/config/riscv/riscv.md"
{
  machine_mode mode = GET_MODE (operands[0]);
  if (riscv_stack_protector_guard == SSP_TLS)
  {
    rtx reg = gen_rtx_REG (Pmode, riscv_stack_protector_guard_reg);
    rtx offset = GEN_INT (riscv_stack_protector_guard_offset);
    rtx addr = gen_rtx_PLUS (Pmode, reg, offset);
    operands[1] = gen_rtx_MEM (Pmode, addr);
  }

  emit_insn ((mode == DImode
	      ? gen_stack_protect_set_di
	      : gen_stack_protect_set_si) (operands[0], operands[1]));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
  }
  emit (operand0, true);
  emit (operand1, false);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/riscv.md:2564 */
rtx
gen_stack_protect_test (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 2569 "../../gcc/config/riscv/riscv.md"
{
  rtx result;
  machine_mode mode = GET_MODE (operands[0]);

  result = gen_reg_rtx(mode);
  if (riscv_stack_protector_guard == SSP_TLS)
  {
      rtx reg = gen_rtx_REG (Pmode, riscv_stack_protector_guard_reg);
      rtx offset = GEN_INT (riscv_stack_protector_guard_offset);
      rtx addr = gen_rtx_PLUS (Pmode, reg, offset);
      operands[1] = gen_rtx_MEM (Pmode, addr);
  }
  emit_insn ((mode == DImode
		  ? gen_stack_protect_test_di
		  : gen_stack_protect_test_si) (result,
					        operands[0],
					        operands[1]));

  if (mode == DImode)
    emit_jump_insn (gen_cbranchdi4 (gen_rtx_EQ (VOIDmode, result, const0_rtx),
				    result, const0_rtx, operands[2]));
  else
    emit_jump_insn (gen_cbranchsi4 (gen_rtx_EQ (VOIDmode, result, const0_rtx),
				    result, const0_rtx, operands[2]));

  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit (operand0, true);
  emit (operand1, true);
  emit (operand2, false);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/sync.md:36 */
rtx
gen_mem_thread_fence (rtx operand0)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[1];
    operands[0] = operand0;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 39 "../../gcc/config/riscv/sync.md"
{
  if (INTVAL (operands[0]) != MEMMODEL_RELAXED)
    {
      rtx mem = gen_rtx_MEM (BLKmode, gen_rtx_SCRATCH (Pmode));
      MEM_VOLATILE_P (mem) = 1;
      emit_insn (gen_mem_thread_fence_1 (mem, operands[0]));
    }
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
  }
  emit (operand0, false);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/sync.md:121 */
rtx
gen_atomic_compare_and_swapsi (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3,
	rtx operand4,
	rtx operand5,
	rtx operand6,
	rtx operand7)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[8];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
    operands[4] = operand4;
    operands[5] = operand5;
    operands[6] = operand6;
    operands[7] = operand7;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 131 "../../gcc/config/riscv/sync.md"
{
  emit_insn (gen_atomic_cas_value_strongsi (operands[1], operands[2],
						operands[3], operands[4],
						operands[6], operands[7]));

  rtx compare = operands[1];
  if (operands[3] != const0_rtx)
    {
      rtx difference = gen_rtx_MINUS (SImode, operands[1], operands[3]);
      compare = gen_reg_rtx (SImode);
      emit_insn (gen_rtx_SET (compare, difference));
    }

  if (word_mode != SImode)
    {
      rtx reg = gen_reg_rtx (word_mode);
      emit_insn (gen_rtx_SET (reg, gen_rtx_SIGN_EXTEND (word_mode, compare)));
      compare = reg;
    }

  emit_insn (gen_rtx_SET (operands[0], gen_rtx_EQ (SImode, compare, const0_rtx)));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
    operand4 = operands[4];
    (void) operand4;
    operand5 = operands[5];
    (void) operand5;
    operand6 = operands[6];
    (void) operand6;
    operand7 = operands[7];
    (void) operand7;
  }
  emit (operand0, true);
  emit (operand1, true);
  emit (operand2, true);
  emit (operand3, true);
  emit (operand4, true);
  emit (operand5, true);
  emit (operand6, true);
  emit (operand7, false);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/sync.md:121 */
rtx
gen_atomic_compare_and_swapdi (rtx operand0,
	rtx operand1,
	rtx operand2,
	rtx operand3,
	rtx operand4,
	rtx operand5,
	rtx operand6,
	rtx operand7)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[8];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
    operands[3] = operand3;
    operands[4] = operand4;
    operands[5] = operand5;
    operands[6] = operand6;
    operands[7] = operand7;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 131 "../../gcc/config/riscv/sync.md"
{
  emit_insn (gen_atomic_cas_value_strongdi (operands[1], operands[2],
						operands[3], operands[4],
						operands[6], operands[7]));

  rtx compare = operands[1];
  if (operands[3] != const0_rtx)
    {
      rtx difference = gen_rtx_MINUS (DImode, operands[1], operands[3]);
      compare = gen_reg_rtx (DImode);
      emit_insn (gen_rtx_SET (compare, difference));
    }

  if (word_mode != DImode)
    {
      rtx reg = gen_reg_rtx (word_mode);
      emit_insn (gen_rtx_SET (reg, gen_rtx_SIGN_EXTEND (word_mode, compare)));
      compare = reg;
    }

  emit_insn (gen_rtx_SET (operands[0], gen_rtx_EQ (SImode, compare, const0_rtx)));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
    operand3 = operands[3];
    (void) operand3;
    operand4 = operands[4];
    (void) operand4;
    operand5 = operands[5];
    (void) operand5;
    operand6 = operands[6];
    (void) operand6;
    operand7 = operands[7];
    (void) operand7;
  }
  emit (operand0, true);
  emit (operand1, true);
  emit (operand2, true);
  emit (operand3, true);
  emit (operand4, true);
  emit (operand5, true);
  emit (operand6, true);
  emit (operand7, false);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/sync.md:155 */
rtx
gen_atomic_test_and_set (rtx operand0,
	rtx operand1,
	rtx operand2)
{
  rtx_insn *_val = 0;
  start_sequence ();
  {
    rtx operands[3];
    operands[0] = operand0;
    operands[1] = operand1;
    operands[2] = operand2;
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 160 "../../gcc/config/riscv/sync.md"
{
  /* We have no QImode atomics, so use the address LSBs to form a mask,
     then use an aligned SImode atomic. */
  rtx result = operands[0];
  rtx mem = operands[1];
  rtx model = operands[2];
  rtx addr = force_reg (Pmode, XEXP (mem, 0));

  rtx aligned_addr = gen_reg_rtx (Pmode);
  emit_move_insn (aligned_addr, gen_rtx_AND (Pmode, addr, GEN_INT (-4)));

  rtx aligned_mem = change_address (mem, SImode, aligned_addr);
  set_mem_alias_set (aligned_mem, 0);

  rtx offset = gen_reg_rtx (SImode);
  emit_move_insn (offset, gen_rtx_AND (SImode, gen_lowpart (SImode, addr),
				       GEN_INT (3)));

  rtx tmp = gen_reg_rtx (SImode);
  emit_move_insn (tmp, GEN_INT (1));

  rtx shmt = gen_reg_rtx (SImode);
  emit_move_insn (shmt, gen_rtx_ASHIFT (SImode, offset, GEN_INT (3)));

  rtx word = gen_reg_rtx (SImode);
  emit_move_insn (word, gen_rtx_ASHIFT (SImode, tmp,
					gen_lowpart (QImode, shmt)));

  tmp = gen_reg_rtx (SImode);
  emit_insn (gen_atomic_fetch_orsi (tmp, aligned_mem, word, model));

  emit_move_insn (gen_lowpart (SImode, result),
		  gen_rtx_LSHIFTRT (SImode, tmp,
				    gen_lowpart (QImode, shmt)));
  DONE;
}
#undef DONE
#undef FAIL
    operand0 = operands[0];
    (void) operand0;
    operand1 = operands[1];
    (void) operand1;
    operand2 = operands[2];
    (void) operand2;
  }
  emit (operand0, true);
  emit (operand1, true);
  emit (operand2, false);
  _val = get_insns ();
  end_sequence ();
  return _val;
}

/* ../../gcc/config/riscv/peephole.md:22 */
extern rtx_insn *gen_peephole2_1 (rtx_insn *, rtx *);
rtx_insn *
gen_peephole2_1 (rtx_insn *curr_insn ATTRIBUTE_UNUSED, rtx *operands)
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx_insn *_val = NULL;
  if (dump_file)
    fprintf (dump_file, "Splitting with gen_peephole2_1 (peephole.md:22)\n");
  start_sequence ();
#define FAIL return (end_sequence (), _val)
#define DONE return (_val = get_insns (), end_sequence (), _val)
#line 38 "../../gcc/config/riscv/peephole.md"
{
  operands[5] = GEN_INT (INTVAL (operands[2]) - INTVAL (operands[5]));
}
#undef DONE
#undef FAIL
  operand0 = operands[0];
  (void) operand0;
  operand1 = operands[1];
  (void) operand1;
  operand2 = operands[2];
  (void) operand2;
  operand3 = operands[3];
  (void) operand3;
  operand4 = operands[4];
  (void) operand4;
  operand5 = operands[5];
  (void) operand5;
  emit_insn (gen_rtx_SET (operand0,
	gen_rtx_ASHIFT (DImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx_SET (operand4,
	gen_rtx_LSHIFTRT (DImode,
	copy_rtx (operand0),
	operand5)));
  _val = get_insns ();
  end_sequence ();
  return _val;
}



void
add_clobbers (rtx pattern ATTRIBUTE_UNUSED, int insn_code_number)
{
  switch (insn_code_number)
    {
    case 293:
      XVECEXP (pattern, 0, 2) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode));
      break;

    case 292:
      XVECEXP (pattern, 0, 2) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      break;

    case 254:
    case 253:
      XVECEXP (pattern, 0, 1) = gen_hard_reg_clobber (SImode, 1);
      break;

    case 343:
    case 342:
    case 339:
    case 338:
    case 335:
    case 334:
    case 329:
    case 328:
    case 327:
    case 326:
    case 321:
    case 320:
    case 317:
    case 316:
    case 269:
    case 248:
    case 207:
    case 206:
    case 203:
    case 202:
    case 199:
    case 198:
    case 195:
    case 194:
    case 188:
    case 186:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (SImode));
      break;

    case 345:
    case 344:
    case 341:
    case 340:
    case 337:
    case 336:
    case 333:
    case 332:
    case 331:
    case 330:
    case 323:
    case 322:
    case 319:
    case 318:
    case 270:
    case 249:
    case 209:
    case 208:
    case 205:
    case 204:
    case 201:
    case 200:
    case 197:
    case 196:
    case 189:
    case 187:
    case 180:
      XVECEXP (pattern, 0, 1) = gen_rtx_CLOBBER (VOIDmode,
	gen_rtx_SCRATCH (DImode));
      break;

    default:
      gcc_unreachable ();
    }
}


int
added_clobbers_hard_reg_p (int insn_code_number)
{
  switch (insn_code_number)
    {
    case 293:
    case 292:
    case 343:
    case 342:
    case 339:
    case 338:
    case 335:
    case 334:
    case 329:
    case 328:
    case 327:
    case 326:
    case 321:
    case 320:
    case 317:
    case 316:
    case 269:
    case 248:
    case 207:
    case 206:
    case 203:
    case 202:
    case 199:
    case 198:
    case 195:
    case 194:
    case 188:
    case 186:
    case 345:
    case 344:
    case 341:
    case 340:
    case 337:
    case 336:
    case 333:
    case 332:
    case 331:
    case 330:
    case 323:
    case 322:
    case 319:
    case 318:
    case 270:
    case 249:
    case 209:
    case 208:
    case 205:
    case 204:
    case 201:
    case 200:
    case 197:
    case 196:
    case 189:
    case 187:
    case 180:
      return 0;

    case 254:
    case 253:
      return 1;

    default:
      gcc_unreachable ();
    }
}
