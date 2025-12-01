/* Generated automatically by the program `genoutput'
   from the machine description file `md'.  */

#define IN_TARGET_CODE 1
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "predict.h"
#include "tree.h"
#include "rtl.h"
#include "flags.h"
#include "alias.h"
#include "varasm.h"
#include "stor-layout.h"
#include "calls.h"
#include "insn-config.h"
#include "expmed.h"
#include "dojump.h"
#include "explow.h"
#include "memmodel.h"
#include "emit-rtl.h"
#include "stmt.h"
#include "expr.h"
#include "insn-codes.h"
#include "tm_p.h"
#include "regs.h"
#include "conditions.h"
#include "insn-attr.h"

#include "recog.h"

#include "diagnostic-core.h"
#include "output.h"
#include "target.h"
#include "tm-constrs.h"

static const char *
output_3 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 457 "../../gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "add%i2w\t%0,%1,%2" : "add%i2\t%0,%1,%2"; }
}

static const char *
output_10 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 522 "../../gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "subw\t%0,%z1,%2" : "sub\t%0,%z1,%2"; }
}

static const char *
output_14 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 559 "../../gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "negw\t%0,%1" : "neg\t%0,%1"; }
}

static const char *
output_19 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 604 "../../gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "mulw\t%0,%1,%2" : "mul\t%0,%1,%2"; }
}

static const char *
output_29 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 783 "../../gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "div%i2w\t%0,%1,%2" : "div%i2\t%0,%1,%2"; }
}

static const char *
output_30 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 783 "../../gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "divu%i2w\t%0,%1,%2" : "divu%i2\t%0,%1,%2"; }
}

static const char *
output_31 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 783 "../../gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "rem%i2w\t%0,%1,%2" : "rem%i2\t%0,%1,%2"; }
}

static const char *
output_32 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 783 "../../gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "remu%i2w\t%0,%1,%2" : "remu%i2\t%0,%1,%2"; }
}

static const char *
output_43 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 826 "../../gcc/config/riscv/riscv.md"
{
    return "fsqrt.s\t%0,%1";
}
}

static const char *
output_44 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 826 "../../gcc/config/riscv/riscv.md"
{
    return "fsqrt.d\t%0,%1";
}
}

static const char * const output_84[] = {
  "#",
  "lwu\t%0,%1",
};

static const char * const output_85[] = {
  "#",
  "lhu\t%0,%1",
};

static const char * const output_86[] = {
  "#",
  "lhu\t%0,%1",
};

static const char * const output_87[] = {
  "andi\t%0,%1,0xff",
  "lbu\t%0,%1",
};

static const char * const output_88[] = {
  "andi\t%0,%1,0xff",
  "lbu\t%0,%1",
};

static const char * const output_89[] = {
  "andi\t%0,%1,0xff",
  "lbu\t%0,%1",
};

static const char * const output_90[] = {
  "sext.w\t%0,%1",
  "lw\t%0,%1",
};

static const char * const output_91[] = {
  "#",
  "lb\t%0,%1",
};

static const char * const output_92[] = {
  "#",
  "lb\t%0,%1",
};

static const char * const output_93[] = {
  "#",
  "lb\t%0,%1",
};

static const char * const output_94[] = {
  "#",
  "lh\t%0,%1",
};

static const char * const output_95[] = {
  "#",
  "lh\t%0,%1",
};

static const char * const output_96[] = {
  "#",
  "lh\t%0,%1",
};

static const char *
output_134 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1335 "../../gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_135 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1345 "../../gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_136 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1365 "../../gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_137 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1390 "../../gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_138 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1403 "../../gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "add%i2w\t%0,%1,%2" : "add%i2\t%0,%1,%2"; }
}

static const char *
output_139 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1403 "../../gcc/config/riscv/riscv.md"
{ return TARGET_64BIT ? "add%i2w\t%0,%1,%2" : "add%i2\t%0,%1,%2"; }
}

static const char *
output_142 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1432 "../../gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_143 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1453 "../../gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_144 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1463 "../../gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_145 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1486 "../../gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_146 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1496 "../../gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_147 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1506 "../../gcc/config/riscv/riscv.md"
{ return riscv_output_move (operands[0], operands[1]); }
}

static const char *
output_150 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1580 "../../gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (SImode) - 1));

  return TARGET_64BIT ? "sll%i2w\t%0,%1,%2" : "sll%i2\t%0,%1,%2";
}
}

static const char *
output_151 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1580 "../../gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (SImode) - 1));

  return TARGET_64BIT ? "sra%i2w\t%0,%1,%2" : "sra%i2\t%0,%1,%2";
}
}

static const char *
output_152 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1580 "../../gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (SImode) - 1));

  return TARGET_64BIT ? "srl%i2w\t%0,%1,%2" : "srl%i2\t%0,%1,%2";
}
}

static const char *
output_159 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1635 "../../gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (DImode) - 1));

  return "sll%i2\t%0,%1,%2";
}
}

static const char *
output_160 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1635 "../../gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (DImode) - 1));

  return "sra%i2\t%0,%1,%2";
}
}

static const char *
output_161 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1635 "../../gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2])
			   & (GET_MODE_BITSIZE (DImode) - 1));

  return "srl%i2\t%0,%1,%2";
}
}

static const char *
output_168 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1691 "../../gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);

  return "sll%i2w\t%0,%1,%2";
}
}

static const char *
output_169 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1691 "../../gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);

  return "sra%i2w\t%0,%1,%2";
}
}

static const char *
output_170 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1691 "../../gcc/config/riscv/riscv.md"
{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);

  return "srl%i2w\t%0,%1,%2";
}
}

static const char *
output_177 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1752 "../../gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) & 0x1f);

  return "srliw\t%0,%1,%2";
}
}

static const char *
output_178 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1768 "../../gcc/config/riscv/riscv.md"
{
  return "srliw\t%0,%1,%3";
}
}

static const char *
output_179 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 1781 "../../gcc/config/riscv/riscv.md"
{
  return "srliw\t%0,%1,31";
}
}

static const char * const output_183[] = {
  "b%C5 %1,%z2,1f; mv %0,%z4; 1: # movcc",
  "b%C5 %1,%z2,1f; li %0,%4; 1: # movcc",
};

static const char * const output_184[] = {
  "b%C5 %1,%z2,1f; mv %0,%z4; 1: # movcc",
  "b%C5 %1,%z2,1f; li %0,%4; 1: # movcc",
};

static const char * const output_185[] = {
  "b%C5 %1,%z2,1f; mv %0,%z4; 1: # movcc",
  "b%C5 %1,%z2,1f; li %0,%4; 1: # movcc",
};

static const char *
output_234 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 2123 "../../gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt%i2\t%0,%1,%2";
}
}

static const char *
output_235 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 2123 "../../gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt%i2u\t%0,%1,%2";
}
}

static const char *
output_236 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 2123 "../../gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt%i2\t%0,%1,%2";
}
}

static const char *
output_237 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 2123 "../../gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt%i2u\t%0,%1,%2";
}
}

static const char *
output_238 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 2123 "../../gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt%i2\t%0,%1,%2";
}
}

static const char *
output_239 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 2123 "../../gcc/config/riscv/riscv.md"
{
  operands[2] = GEN_INT (INTVAL (operands[2]) + 1);
  return "slt%i2u\t%0,%1,%2";
}
}

static const char *
output_246 (rtx *operands ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
#line 2245 "../../gcc/config/riscv/riscv.md"
{
  return riscv_output_return ();
}
}

static const char * const output_251[] = {
  "jr\t%0",
  "tail\t%0",
  "tail\t%0@plt",
};

static const char * const output_252[] = {
  "jr\t%1",
  "tail\t%1",
  "tail\t%1@plt",
};

static const char * const output_253[] = {
  "jalr\t%0",
  "call\t%0",
  "call\t%0@plt",
};

static const char * const output_254[] = {
  "jalr\t%1",
  "call\t%1",
  "call\t%1@plt",
};

static const char * const output_316[] = {
  "flw\t%0,%1,%2",
  "lw\t%0,%1",
};

static const char * const output_317[] = {
  "fld\t%0,%1,%2",
  "ld\t%0,%1",
};

static const char * const output_318[] = {
  "flw\t%0,%1,%2",
  "lw\t%0,%1",
};

static const char * const output_319[] = {
  "fld\t%0,%1,%2",
  "ld\t%0,%1",
};

static const char * const output_334[] = {
  "fsw\t%1,%0,%2",
  "sw\t%1,%0,%2",
};

static const char * const output_335[] = {
  "fsd\t%1,%0,%2",
  "sd\t%1,%0,%2",
};

static const char * const output_336[] = {
  "fsw\t%1,%0,%2",
  "sw\t%1,%0,%2",
};

static const char * const output_337[] = {
  "fsd\t%1,%0,%2",
  "sd\t%1,%0,%2",
};



static const struct insn_operand_data operand_data[] = 
{
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,I",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,I",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,I",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,I",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    subreg_lowpart_operator,
    "",
    E_SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    subreg_lowpart_operator,
    "",
    E_SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    subreg_lowpart_operator,
    "",
    E_SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    subreg_lowpart_operator,
    "",
    E_SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,I",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "%r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,I",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    E_HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    E_HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    E_QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    E_QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    E_QImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "r,m",
    E_HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    symbolic_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,*f,*f,*r,*f,*m",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,i,m,r,*J*r,*m,*f,*f,*f",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,*f,*f,*r,*f,*m",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,T,m,rJ,*r*J,*m,*f,*f,*f",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,*f,*f,*r,*m",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,T,m,rJ,*r*J,*m,*f,*f",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,*f,*r",
    E_HImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,T,m,rJ,*r*J,*f",
    E_HImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r,r",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,I",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "r,I",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    nonimmediate_operand,
    "=r,r,r,m,*f,*r",
    E_QImode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "r,I,m,rJ,*r*J,*f",
    E_QImode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,f,f,m,m,*f,*r,*r,*r,*m",
    E_SFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "f,G,m,f,G,*r,*f,*G*r,*m,*r",
    E_SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,m",
    E_SFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "Gr,m,r",
    E_SFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,f,f,m,m,*r,*r,*m",
    E_DFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "f,G,m,f,G,*r*G,*m,*r",
    E_DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=f,f,f,m,m,*f,*r,*r,*r,*m",
    E_DFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "f,G,m,f,G,*r,*f,*r*G,*m,*r",
    E_DFmode,
    0,
    0,
    1,
    1
  },
  {
    nonimmediate_operand,
    "=r,r,m",
    E_DFmode,
    0,
    0,
    1,
    1
  },
  {
    move_operand,
    "rG,m,rG",
    E_DFmode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    subreg_lowpart_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    subreg_lowpart_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    subreg_lowpart_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    subreg_lowpart_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    subreg_lowpart_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    subreg_lowpart_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "I",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    immediate_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ,rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    sfb_alu_operand,
    "rJ,IL",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r,r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ,rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    sfb_alu_operand,
    "rJ,IL",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "=r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r,r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ,rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "0,0",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    sfb_alu_operand,
    "rJ,IL",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    equality_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    branch_on_bit_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    equality_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    branch_on_bit_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    fp_native_comparison,
    "",
    E_SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    fp_native_comparison,
    "",
    E_DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    fp_native_comparison,
    "",
    E_SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    fp_native_comparison,
    "",
    E_DImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    arith_operand,
    "rI",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    sle_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    sle_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    sle_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "l",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "l",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "l",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "l",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    pmode_register_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    call_insn_operand,
    "j,S,U",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "j,S,U",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    call_insn_operand,
    "l,S,U",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    gpr_save_operation,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    csr_operand,
    "rK",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=m",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    memory_operand,
    "=m",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "m",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "m",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    0,
    "",
    E_BLKmode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=A",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "=A",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    register_operand,
    "0",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=&r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=&r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=f,*r",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r,X",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f,*r",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r,X",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f,*r",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r,X",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f,*r",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r,X",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=f",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "=r",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "=r",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "rJ",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f,*r",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r,&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f,*r",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r,&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f,*r",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r,&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "f,*r",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=r,&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    absolute_symbolic_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "r",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "=&r",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    E_TImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_HImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    E_BLKmode,
    0,
    0,
    1,
    1
  },
  {
    general_operand,
    "",
    E_BLKmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    pmode_register_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    pmode_register_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    comparison_operator,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    sfb_alu_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    comparison_operator,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    sfb_alu_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    comparison_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    comparison_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    comparison_operator,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    fp_branch_comparison,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    fp_branch_comparison,
    "",
    E_VOIDmode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    E_SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    order_operator,
    "",
    E_SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    nonmemory_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    fp_scc_comparison,
    "",
    E_SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    fp_scc_comparison,
    "",
    E_SImode,
    0,
    1,
    0,
    0
  },
  {
    register_operand,
    "",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    E_SImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DFmode,
    0,
    0,
    1,
    0
  },
  {
    scratch_operand,
    "",
    E_DImode,
    0,
    0,
    0,
    0
  },
  {
    register_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    general_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    memory_operand,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    1
  },
  {
    0,
    "",
    E_VOIDmode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    1
  },
  {
    reg_or_0_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    reg_or_0_operand,
    "",
    E_DImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
  {
    register_operand,
    "",
    E_QImode,
    0,
    0,
    1,
    0
  },
  {
    memory_operand,
    "+A",
    E_QImode,
    0,
    0,
    1,
    1
  },
  {
    const_int_operand,
    "",
    E_SImode,
    0,
    0,
    1,
    0
  },
};


#if GCC_VERSION >= 2007
__extension__
#endif

const struct insn_data_d insn_data[] = 
{
  /* <internal>:0 */
  {
    "*placeholder_for_nothing",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { 0 },
    &operand_data[0],
    0,
    0,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:443 */
  {
    "addsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fadd.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_addsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:443 */
  {
    "adddf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fadd.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_adddf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:452 */
  {
    "addsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_3 },
#else
    { 0, 0, output_3 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_addsi3 },
    &operand_data[7],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:461 */
  {
    "adddi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_adddi3 },
    &operand_data[10],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:470 */
  {
    "*addsi3_extended",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add%i2w\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[13],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:480 */
  {
    "*addsi3_extended2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add%i2w\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[16],
    4,
    4,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:499 */
  {
    "subsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsub.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_subsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:499 */
  {
    "subdf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsub.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_subdf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:508 */
  {
    "subdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sub\t%0,%z1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_subdi3 },
    &operand_data[20],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:517 */
  {
    "subsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_10 },
#else
    { 0, 0, output_10 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_subsi3 },
    &operand_data[23],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:526 */
  {
    "*subsi3_extended",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "subw\t%0,%z1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[26],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:536 */
  {
    "*subsi3_extended2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "subw\t%0,%z1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[29],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:547 */
  {
    "negdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "neg\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_negdi2 },
    &operand_data[33],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:555 */
  {
    "negsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_14 },
#else
    { 0, 0, output_14 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_negsi2 },
    &operand_data[35],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:563 */
  {
    "*negsi2_extended",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "negw\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[37],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:572 */
  {
    "*negsi2_extended2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "negw\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[39],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:590 */
  {
    "mulsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmul.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mulsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:590 */
  {
    "muldf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmul.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_muldf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:599 */
  {
    "mulsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_19 },
#else
    { 0, 0, output_19 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mulsi3 },
    &operand_data[42],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:608 */
  {
    "muldi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mul\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_muldi3 },
    &operand_data[45],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:617 */
  {
    "*mulsi3_extended",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[48],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:627 */
  {
    "*mulsi3_extended2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[51],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:664 */
  {
    "muldi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulh\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_muldi3_highpart },
    &operand_data[45],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:664 */
  {
    "umuldi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulhu\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umuldi3_highpart },
    &operand_data[45],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:695 */
  {
    "usmuldi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulhsu\t%0,%2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_usmuldi3_highpart },
    &operand_data[45],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:725 */
  {
    "mulsi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulh\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mulsi3_highpart },
    &operand_data[42],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:725 */
  {
    "umulsi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulhu\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umulsi3_highpart },
    &operand_data[42],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:756 */
  {
    "usmulsi3_highpart",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mulhsu\t%0,%2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_usmulsi3_highpart },
    &operand_data[42],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:778 */
  {
    "divsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_29 },
#else
    { 0, 0, output_29 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_divsi3 },
    &operand_data[42],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:778 */
  {
    "udivsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_30 },
#else
    { 0, 0, output_30 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_udivsi3 },
    &operand_data[42],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:778 */
  {
    "modsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_31 },
#else
    { 0, 0, output_31 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_modsi3 },
    &operand_data[42],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:778 */
  {
    "umodsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_32 },
#else
    { 0, 0, output_32 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umodsi3 },
    &operand_data[42],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:787 */
  {
    "divdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "div%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_divdi3 },
    &operand_data[45],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:787 */
  {
    "udivdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "divu%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_udivdi3 },
    &operand_data[45],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:787 */
  {
    "moddi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "rem%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_moddi3 },
    &operand_data[45],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:787 */
  {
    "umoddi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "remu%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umoddi3 },
    &operand_data[45],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:796 */
  {
    "*divsi3_extended",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "div%i2w\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[48],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:796 */
  {
    "*udivsi3_extended",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "divu%i2w\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[48],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:796 */
  {
    "*modsi3_extended",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "rem%i2w\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[48],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:796 */
  {
    "*umodsi3_extended",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "remu%i2w\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[48],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:806 */
  {
    "divsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fdiv.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_divsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:806 */
  {
    "divdf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fdiv.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_divdf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:822 */
  {
    "sqrtsf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_43 },
#else
    { 0, 0, output_43 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sqrtsf2 },
    &operand_data[1],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:822 */
  {
    "sqrtdf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_44 },
#else
    { 0, 0, output_44 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sqrtdf2 },
    &operand_data[4],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:835 */
  {
    "fmasf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmadd.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fmasf4 },
    &operand_data[55],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:835 */
  {
    "fmadf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmadd.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fmadf4 },
    &operand_data[59],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:846 */
  {
    "fmssf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmsub.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fmssf4 },
    &operand_data[55],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:846 */
  {
    "fmsdf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmsub.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fmsdf4 },
    &operand_data[59],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:857 */
  {
    "fnmssf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmadd.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fnmssf4 },
    &operand_data[55],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:857 */
  {
    "fnmsdf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmadd.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fnmsdf4 },
    &operand_data[59],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:869 */
  {
    "fnmasf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmsub.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fnmasf4 },
    &operand_data[55],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:869 */
  {
    "fnmadf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmsub.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fnmadf4 },
    &operand_data[59],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:881 */
  {
    "*fmasf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmadd.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[55],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:881 */
  {
    "*fmadf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmadd.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[59],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:894 */
  {
    "*fmssf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmsub.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[55],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:894 */
  {
    "*fmsdf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmsub.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[59],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:907 */
  {
    "*fnmssf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmadd.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[55],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:907 */
  {
    "*fnmsdf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmadd.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[59],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:920 */
  {
    "*fnmasf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmsub.s\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[55],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:920 */
  {
    "*fnmadf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fnmsub.d\t%0,%1,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[59],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:939 */
  {
    "abssf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs.s\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_abssf2 },
    &operand_data[1],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:939 */
  {
    "absdf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fabs.d\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_absdf2 },
    &operand_data[4],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:947 */
  {
    "copysignsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsgnj.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_copysignsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:947 */
  {
    "copysigndf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsgnj.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_copysigndf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:957 */
  {
    "negsf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fneg.s\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_negsf2 },
    &operand_data[1],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:957 */
  {
    "negdf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fneg.d\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_negdf2 },
    &operand_data[4],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:972 */
  {
    "sminsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmin.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sminsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:972 */
  {
    "smindf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmin.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_smindf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:981 */
  {
    "smaxsf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmax.s\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_smaxsf3 },
    &operand_data[1],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:981 */
  {
    "smaxdf3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fmax.d\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_smaxdf3 },
    &operand_data[4],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1001 */
  {
    "andsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_andsi3 },
    &operand_data[63],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1001 */
  {
    "iorsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_iorsi3 },
    &operand_data[63],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1001 */
  {
    "xorsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_xorsi3 },
    &operand_data[63],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1001 */
  {
    "anddi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_anddi3 },
    &operand_data[66],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1001 */
  {
    "iordi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_iordi3 },
    &operand_data[66],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1001 */
  {
    "xordi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_xordi3 },
    &operand_data[66],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1010 */
  {
    "*andsi3_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "and%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[63],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1010 */
  {
    "*iorsi3_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "or%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[63],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1010 */
  {
    "*xorsi3_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[63],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1019 */
  {
    "one_cmplsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "not\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_one_cmplsi2 },
    &operand_data[35],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1019 */
  {
    "one_cmpldi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "not\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_one_cmpldi2 },
    &operand_data[33],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1027 */
  {
    "*one_cmplsi2_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "not\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[35],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1042 */
  {
    "truncdfsf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.s.d\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_truncdfsf2 },
    &operand_data[69],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1060 */
  {
    "zero_extendsidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_84 },
#else
    { 0, output_84, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendsidi2 },
    &operand_data[71],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1079 */
  {
    "zero_extendhisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_85 },
#else
    { 0, output_85, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendhisi2 },
    &operand_data[73],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1079 */
  {
    "zero_extendhidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_86 },
#else
    { 0, output_86, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendhidi2 },
    &operand_data[75],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1101 */
  {
    "zero_extendqihi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_87 },
#else
    { 0, output_87, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendqihi2 },
    &operand_data[77],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1101 */
  {
    "zero_extendqisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_88 },
#else
    { 0, output_88, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendqisi2 },
    &operand_data[79],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1101 */
  {
    "zero_extendqidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_89 },
#else
    { 0, output_89, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendqidi2 },
    &operand_data[81],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1119 */
  {
    "extendsidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_90 },
#else
    { 0, output_90, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendsidi2 },
    &operand_data[71],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1130 */
  {
    "extendqihi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_91 },
#else
    { 0, output_91, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendqihi2 },
    &operand_data[77],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1130 */
  {
    "extendqisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_92 },
#else
    { 0, output_92, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendqisi2 },
    &operand_data[79],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1130 */
  {
    "extendqidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_93 },
#else
    { 0, output_93, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendqidi2 },
    &operand_data[81],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1130 */
  {
    "extendhihi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_94 },
#else
    { 0, output_94, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendhihi2 },
    &operand_data[83],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1130 */
  {
    "extendhisi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_95 },
#else
    { 0, output_95, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendhisi2 },
    &operand_data[73],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1130 */
  {
    "extendhidi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_96 },
#else
    { 0, output_96, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendhidi2 },
    &operand_data[75],
    2,
    2,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1152 */
  {
    "extendsfdf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.d.s\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_extendsfdf2 },
    &operand_data[85],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1168 */
  {
    "fix_truncsfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.w.s %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fix_truncsfsi2 },
    &operand_data[87],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1168 */
  {
    "fix_truncsfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.l.s %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fix_truncsfdi2 },
    &operand_data[89],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1168 */
  {
    "fix_truncdfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.w.d %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fix_truncdfsi2 },
    &operand_data[91],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1168 */
  {
    "fix_truncdfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.l.d %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fix_truncdfdi2 },
    &operand_data[93],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1177 */
  {
    "fixuns_truncsfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.wu.s %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fixuns_truncsfsi2 },
    &operand_data[87],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1177 */
  {
    "fixuns_truncsfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.lu.s %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fixuns_truncsfdi2 },
    &operand_data[89],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1177 */
  {
    "fixuns_truncdfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.wu.d %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fixuns_truncdfsi2 },
    &operand_data[91],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1177 */
  {
    "fixuns_truncdfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.lu.d %0,%1,rtz",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fixuns_truncdfdi2 },
    &operand_data[93],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1186 */
  {
    "floatsisf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.s.w\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatsisf2 },
    &operand_data[95],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1186 */
  {
    "floatdisf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.s.l\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatdisf2 },
    &operand_data[97],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1186 */
  {
    "floatsidf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.d.w\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatsidf2 },
    &operand_data[99],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1186 */
  {
    "floatdidf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.d.l\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatdidf2 },
    &operand_data[101],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1195 */
  {
    "floatunssisf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.s.wu\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatunssisf2 },
    &operand_data[95],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1195 */
  {
    "floatunsdisf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.s.lu\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatunsdisf2 },
    &operand_data[97],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1195 */
  {
    "floatunssidf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.d.wu\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatunssidf2 },
    &operand_data[99],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1195 */
  {
    "floatunsdidf2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.d.lu\t%0,%z1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_floatunsdidf2 },
    &operand_data[101],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1204 */
  {
    "lrintsfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.w.s %0,%1,dyn",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lrintsfsi2 },
    &operand_data[87],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1204 */
  {
    "lroundsfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.w.s %0,%1,rmm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lroundsfsi2 },
    &operand_data[87],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1204 */
  {
    "lrintsfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.l.s %0,%1,dyn",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lrintsfdi2 },
    &operand_data[89],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1204 */
  {
    "lroundsfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.l.s %0,%1,rmm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lroundsfdi2 },
    &operand_data[89],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1204 */
  {
    "lrintdfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.w.d %0,%1,dyn",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lrintdfsi2 },
    &operand_data[91],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1204 */
  {
    "lrounddfsi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.w.d %0,%1,rmm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lrounddfsi2 },
    &operand_data[91],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1204 */
  {
    "lrintdfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.l.d %0,%1,dyn",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lrintdfdi2 },
    &operand_data[93],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1204 */
  {
    "lrounddfdi2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fcvt.l.d %0,%1,rmm",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lrounddfdi2 },
    &operand_data[93],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1225 */
  {
    "got_loadsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_loadsi },
    &operand_data[103],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1225 */
  {
    "got_loaddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_loaddi },
    &operand_data[105],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1235 */
  {
    "tls_add_tp_lesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add\t%0,%1,%2,%%tprel_add(%3)",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_tls_add_tp_lesi },
    &operand_data[107],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1235 */
  {
    "tls_add_tp_ledi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "add\t%0,%1,%2,%%tprel_add(%3)",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_tls_add_tp_ledi },
    &operand_data[111],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1247 */
  {
    "got_load_tls_gdsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la.tls.gd\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_load_tls_gdsi },
    &operand_data[103],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1247 */
  {
    "got_load_tls_gddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la.tls.gd\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_load_tls_gddi },
    &operand_data[105],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1257 */
  {
    "got_load_tls_iesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la.tls.ie\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_load_tls_iesi },
    &operand_data[103],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1257 */
  {
    "got_load_tls_iedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "la.tls.ie\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_got_load_tls_iedi },
    &operand_data[105],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1267 */
  {
    "auipcsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    ".LA%2: auipc\t%0,%h1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_auipcsi },
    &operand_data[115],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1267 */
  {
    "auipcdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    ".LA%2: auipc\t%0,%h1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_auipcdi },
    &operand_data[118],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1283 */
  {
    "*lowsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "addi\t%0,%1,%R2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[121],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1283 */
  {
    "*lowdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "addi\t%0,%1,%R2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[124],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1329 */
  {
    "*movdi_32bit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_134 },
#else
    { 0, 0, output_134 },
#endif
    { 0 },
    &operand_data[127],
    2,
    2,
    0,
    9,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1339 */
  {
    "*movdi_64bit",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_135 },
#else
    { 0, 0, output_135 },
#endif
    { 0 },
    &operand_data[129],
    2,
    2,
    0,
    9,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1360 */
  {
    "*movsi_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_136 },
#else
    { 0, 0, output_136 },
#endif
    { 0 },
    &operand_data[131],
    2,
    2,
    0,
    8,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1385 */
  {
    "*movhi_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_137 },
#else
    { 0, 0, output_137 },
#endif
    { 0 },
    &operand_data[133],
    2,
    2,
    0,
    6,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1398 */
  {
    "*addhihi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_138 },
#else
    { 0, 0, output_138 },
#endif
    { 0 },
    &operand_data[135],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1398 */
  {
    "*addsihi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_139 },
#else
    { 0, 0, output_139 },
#endif
    { 0 },
    &operand_data[138],
    3,
    3,
    0,
    2,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1407 */
  {
    "*xorhihi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[135],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1407 */
  {
    "*xorsihi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "xor%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[138],
    3,
    3,
    0,
    2,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1427 */
  {
    "*movqi_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_142 },
#else
    { 0, 0, output_142 },
#endif
    { 0 },
    &operand_data[141],
    2,
    2,
    0,
    6,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1447 */
  {
    "*movsf_hardfloat",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_143 },
#else
    { 0, 0, output_143 },
#endif
    { 0 },
    &operand_data[143],
    2,
    2,
    0,
    10,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1457 */
  {
    "*movsf_softfloat",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_144 },
#else
    { 0, 0, output_144 },
#endif
    { 0 },
    &operand_data[145],
    2,
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1480 */
  {
    "*movdf_hardfloat_rv32",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_145 },
#else
    { 0, 0, output_145 },
#endif
    { 0 },
    &operand_data[147],
    2,
    2,
    0,
    8,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1490 */
  {
    "*movdf_hardfloat_rv64",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_146 },
#else
    { 0, 0, output_146 },
#endif
    { 0 },
    &operand_data[149],
    2,
    2,
    0,
    10,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1500 */
  {
    "*movdf_softfloat",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_147 },
#else
    { 0, 0, output_147 },
#endif
    { 0 },
    &operand_data[151],
    2,
    2,
    0,
    3,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1552 */
  {
    "fence",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%|fence%-",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fence },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1557 */
  {
    "fence_i",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fence.i",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fence_i },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1574 */
  {
    "ashlsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_150 },
#else
    { 0, 0, output_150 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_ashlsi3 },
    &operand_data[153],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1574 */
  {
    "ashrsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_151 },
#else
    { 0, 0, output_151 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_ashrsi3 },
    &operand_data[153],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1574 */
  {
    "lshrsi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_152 },
#else
    { 0, 0, output_152 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lshrsi3 },
    &operand_data[153],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1590 */
  {
    "*ashlsi3_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[156],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1590 */
  {
    "*ashrsi3_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[156],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1590 */
  {
    "*lshrsi3_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[156],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1609 */
  {
    "*ashlsi3_mask_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[161],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1609 */
  {
    "*ashrsi3_mask_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[161],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1609 */
  {
    "*lshrsi3_mask_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[161],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1629 */
  {
    "ashldi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_159 },
#else
    { 0, 0, output_159 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_ashldi3 },
    &operand_data[166],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1629 */
  {
    "ashrdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_160 },
#else
    { 0, 0, output_160 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_ashrdi3 },
    &operand_data[166],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1629 */
  {
    "lshrdi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_161 },
#else
    { 0, 0, output_161 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_lshrdi3 },
    &operand_data[166],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1645 */
  {
    "*ashldi3_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[169],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1645 */
  {
    "*ashrdi3_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[169],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1645 */
  {
    "*lshrdi3_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[169],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1665 */
  {
    "*ashldi3_mask_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[174],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1665 */
  {
    "*ashrdi3_mask_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[174],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1665 */
  {
    "*lshrdi3_mask_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[174],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1685 */
  {
    "*ashlsi3_extend",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_168 },
#else
    { 0, 0, output_168 },
#endif
    { 0 },
    &operand_data[179],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1685 */
  {
    "*ashrsi3_extend",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_169 },
#else
    { 0, 0, output_169 },
#endif
    { 0 },
    &operand_data[179],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1685 */
  {
    "*lshrsi3_extend",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_170 },
#else
    { 0, 0, output_170 },
#endif
    { 0 },
    &operand_data[179],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1700 */
  {
    "*ashlsi3_extend_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[182],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1700 */
  {
    "*ashrsi3_extend_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[182],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1700 */
  {
    "*lshrsi3_extend_mask",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[182],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1722 */
  {
    "*ashlsi3_extend_mask_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[187],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1722 */
  {
    "*ashrsi3_extend_mask_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[187],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1722 */
  {
    "*lshrsi3_extend_mask_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[187],
    5,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1746 */
  {
    "*lshrsi3_zero_extend_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_177 },
#else
    { 0, 0, output_177 },
#endif
    { 0 },
    &operand_data[192],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1761 */
  {
    "*lshrsi3_zero_extend_2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_178 },
#else
    { 0, 0, output_178 },
#endif
    { 0 },
    &operand_data[195],
    4,
    4,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1776 */
  {
    "*lshrsi3_zero_extend_3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_179 },
#else
    { 0, 0, output_179 },
#endif
    { 0 },
    &operand_data[37],
    2,
    2,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:1830 */
  {
    "zero_extendsidi2_shifted",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_zero_extendsidi2_shifted },
    &operand_data[199],
    4,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1857 */
  {
    "*branchsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "b%C1\t%2,%z3,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[204],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1857 */
  {
    "*branchdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "b%C1\t%2,%z3,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[208],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1888 */
  {
    "*movsisicc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_183 },
#else
    { 0, output_183, 0 },
#endif
    { 0 },
    &operand_data[212],
    6,
    6,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1888 */
  {
    "*movsidicc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_184 },
#else
    { 0, output_184, 0 },
#endif
    { 0 },
    &operand_data[218],
    6,
    6,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1888 */
  {
    "*movdidicc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_185 },
#else
    { 0, output_185, 0 },
#endif
    { 0 },
    &operand_data[224],
    6,
    6,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:1939 */
  {
    "*branch_on_bitsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[230],
    4,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1939 */
  {
    "*branch_on_bitdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[235],
    4,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1970 */
  {
    "*branch_on_bit_rangesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[230],
    4,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:1970 */
  {
    "*branch_on_bit_rangedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[235],
    4,
    5,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2028 */
  {
    "*cstoresfsi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "f%C1.s\t%0,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[240],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2028 */
  {
    "*cstoresfdi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "f%C1.s\t%0,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[244],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2028 */
  {
    "*cstoredfsi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "f%C1.d\t%0,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[248],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2028 */
  {
    "*cstoredfdi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "f%C1.d\t%0,%2,%3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[252],
    4,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2047 */
  {
    "*flt_quietsfsi4_default",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tflt.s\t%0,%1,%2\n\tfsflags %3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[256],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2047 */
  {
    "*fle_quietsfsi4_default",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tfle.s\t%0,%1,%2\n\tfsflags %3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[256],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2047 */
  {
    "*flt_quietsfdi4_default",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tflt.s\t%0,%1,%2\n\tfsflags %3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[260],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2047 */
  {
    "*fle_quietsfdi4_default",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tfle.s\t%0,%1,%2\n\tfsflags %3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[260],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2047 */
  {
    "*flt_quietdfsi4_default",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tflt.d\t%0,%1,%2\n\tfsflags %3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[264],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2047 */
  {
    "*fle_quietdfsi4_default",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tfle.d\t%0,%1,%2\n\tfsflags %3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[264],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2047 */
  {
    "*flt_quietdfdi4_default",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tflt.d\t%0,%1,%2\n\tfsflags %3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[268],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2047 */
  {
    "*fle_quietdfdi4_default",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tfle.d\t%0,%1,%2\n\tfsflags %3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[268],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2060 */
  {
    "*flt_quietsfsi4_snan",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tflt.s\t%0,%1,%2\n\tfsflags %3\n\tfeq.s\tzero,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[256],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2060 */
  {
    "*fle_quietsfsi4_snan",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tfle.s\t%0,%1,%2\n\tfsflags %3\n\tfeq.s\tzero,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[256],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2060 */
  {
    "*flt_quietsfdi4_snan",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tflt.s\t%0,%1,%2\n\tfsflags %3\n\tfeq.s\tzero,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[260],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2060 */
  {
    "*fle_quietsfdi4_snan",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tfle.s\t%0,%1,%2\n\tfsflags %3\n\tfeq.s\tzero,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[260],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2060 */
  {
    "*flt_quietdfsi4_snan",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tflt.d\t%0,%1,%2\n\tfsflags %3\n\tfeq.d\tzero,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[264],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2060 */
  {
    "*fle_quietdfsi4_snan",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tfle.d\t%0,%1,%2\n\tfsflags %3\n\tfeq.d\tzero,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[264],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2060 */
  {
    "*flt_quietdfdi4_snan",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tflt.d\t%0,%1,%2\n\tfsflags %3\n\tfeq.d\tzero,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[268],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2060 */
  {
    "*fle_quietdfdi4_snan",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%3\n\tfle.d\t%0,%1,%2\n\tfsflags %3\n\tfeq.d\tzero,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[268],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2073 */
  {
    "*seq_zero_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "seqz\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[35],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2073 */
  {
    "*seq_zero_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "seqz\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[272],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2073 */
  {
    "*seq_zero_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "seqz\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[33],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2082 */
  {
    "*sne_zero_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "snez\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[35],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2082 */
  {
    "*sne_zero_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "snez\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[272],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2082 */
  {
    "*sne_zero_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "snez\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[33],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2091 */
  {
    "*sgt_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sgt\t%0,%1,%z2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[274],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2091 */
  {
    "*sgtu_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sgtu\t%0,%1,%z2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[274],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2091 */
  {
    "*sgt_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sgt\t%0,%1,%z2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[277],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2091 */
  {
    "*sgtu_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sgtu\t%0,%1,%z2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[277],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2091 */
  {
    "*sgt_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sgt\t%0,%1,%z2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[280],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2091 */
  {
    "*sgtu_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sgtu\t%0,%1,%z2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[280],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2100 */
  {
    "*sge_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[35],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2100 */
  {
    "*sgeu_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2u\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[35],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2100 */
  {
    "*sge_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[272],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2100 */
  {
    "*sgeu_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2u\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[272],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2100 */
  {
    "*sge_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[33],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2100 */
  {
    "*sgeu_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2u\t%0,zero,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[33],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2109 */
  {
    "*slt_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[283],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2109 */
  {
    "*sltu_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2u\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[283],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2109 */
  {
    "*slt_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[286],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2109 */
  {
    "*sltu_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2u\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[286],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2109 */
  {
    "*slt_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[289],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2109 */
  {
    "*sltu_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "slt%i2u\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[289],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2118 */
  {
    "*sle_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_234 },
#else
    { 0, 0, output_234 },
#endif
    { 0 },
    &operand_data[292],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:2118 */
  {
    "*sleu_sisi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_235 },
#else
    { 0, 0, output_235 },
#endif
    { 0 },
    &operand_data[292],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:2118 */
  {
    "*sle_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_236 },
#else
    { 0, 0, output_236 },
#endif
    { 0 },
    &operand_data[295],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:2118 */
  {
    "*sleu_disi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_237 },
#else
    { 0, 0, output_237 },
#endif
    { 0 },
    &operand_data[295],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:2118 */
  {
    "*sle_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_238 },
#else
    { 0, 0, output_238 },
#endif
    { 0 },
    &operand_data[298],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:2118 */
  {
    "*sleu_didi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_239 },
#else
    { 0, 0, output_239 },
#endif
    { 0 },
    &operand_data[298],
    3,
    3,
    0,
    1,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:2139 */
  {
    "jump",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "j\t%l0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_jump },
    &operand_data[204],
    1,
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2159 */
  {
    "indirect_jumpsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "jr\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_indirect_jumpsi },
    &operand_data[301],
    1,
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2159 */
  {
    "indirect_jumpdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "jr\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_indirect_jumpdi },
    &operand_data[302],
    1,
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2183 */
  {
    "tablejumpsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "jr\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_tablejumpsi },
    &operand_data[303],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2183 */
  {
    "tablejumpdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "jr\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_tablejumpdi },
    &operand_data[305],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2211 */
  {
    "blockage",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_blockage },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2242 */
  {
    "simple_return",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .function = output_246 },
#else
    { 0, 0, output_246 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_simple_return },
    &operand_data[0],
    0,
    0,
    0,
    0,
    3
  },
  /* ../../gcc/config/riscv/riscv.md:2253 */
  {
    "simple_return_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "jr\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_simple_return_internal },
    &operand_data[307],
    1,
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2281 */
  {
    "eh_set_lr_si",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_eh_set_lr_si },
    &operand_data[308],
    1,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2287 */
  {
    "eh_set_lr_di",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_eh_set_lr_di },
    &operand_data[310],
    1,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2303 */
  {
    "eh_return_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "#",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_eh_return_internal },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2330 */
  {
    "sibcall_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_251 },
#else
    { 0, output_251, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall_internal },
    &operand_data[312],
    2,
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:2352 */
  {
    "sibcall_value_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_252 },
#else
    { 0, output_252, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall_value_internal },
    &operand_data[313],
    3,
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:2375 */
  {
    "call_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_253 },
#else
    { 0, output_253, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_call_internal },
    &operand_data[316],
    2,
    2,
    0,
    3,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:2398 */
  {
    "call_value_internal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_254 },
#else
    { 0, output_254, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_call_value_internal },
    &operand_data[315],
    3,
    3,
    0,
    3,
    2
  },
  /* ../../gcc/config/riscv/riscv.md:2433 */
  {
    "nop",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "nop",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_nop },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2440 */
  {
    "trap",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "ebreak",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_trap },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2449 */
  {
    "gpr_save",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "call\tt0,__riscv_save_%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_gpr_save },
    &operand_data[318],
    2,
    2,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2456 */
  {
    "gpr_restore",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "tail\t__riscv_restore_%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_gpr_restore },
    &operand_data[159],
    1,
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2461 */
  {
    "gpr_restore_return",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_gpr_restore_return },
    &operand_data[307],
    1,
    1,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2468 */
  {
    "riscv_frflags",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "frflags\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_riscv_frflags },
    &operand_data[23],
    1,
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2474 */
  {
    "riscv_fsflags",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsflags\t%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_riscv_fsflags },
    &operand_data[320],
    1,
    1,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2479 */
  {
    "riscv_mret",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "mret",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_riscv_mret },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2485 */
  {
    "riscv_sret",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sret",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_riscv_sret },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2491 */
  {
    "riscv_uret",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "uret",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_riscv_uret },
    &operand_data[0],
    0,
    0,
    0,
    0,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2497 */
  {
    "stack_tiesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_stack_tiesi },
    &operand_data[43],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2497 */
  {
    "stack_tiedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_stack_tiedi },
    &operand_data[46],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2555 */
  {
    "stack_protect_set_si",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lw\t%2, %1\n\tsw\t%2, %0\n\tli\t%2, 0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_stack_protect_set_si },
    &operand_data[321],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2555 */
  {
    "stack_protect_set_di",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "ld\t%2, %1\n\tsd\t%2, %0\n\tli\t%2, 0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_stack_protect_set_di },
    &operand_data[324],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2597 */
  {
    "stack_protect_test_si",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lw\t%3, %1\n\tlw\t%0, %2\n\txor\t%0, %3, %0\n\tli\t%3, 0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_stack_protect_test_si },
    &operand_data[327],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:2597 */
  {
    "stack_protect_test_di",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "ld\t%3, %1\n\tld\t%0, %2\n\txor\t%0, %3, %0\n\tli\t%3, 0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_stack_protect_test_di },
    &operand_data[331],
    3,
    4,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:51 */
  {
    "mem_thread_fence_1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fence\tiorw,iorw",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mem_thread_fence_1 },
    &operand_data[335],
    2,
    2,
    1,
    0,
    1
  },
  /* ../../gcc/config/riscv/sync.md:61 */
  {
    "atomic_storesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F2amoswap.w%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_storesi },
    &operand_data[337],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:61 */
  {
    "atomic_storedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F2amoswap.d%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_storedi },
    &operand_data[340],
    3,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:71 */
  {
    "atomic_addsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F2amoadd.w%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_addsi },
    &operand_data[343],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:71 */
  {
    "atomic_orsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F2amoor.w%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_orsi },
    &operand_data[343],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:71 */
  {
    "atomic_xorsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F2amoxor.w%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_xorsi },
    &operand_data[343],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:71 */
  {
    "atomic_andsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F2amoand.w%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_andsi },
    &operand_data[343],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:71 */
  {
    "atomic_adddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F2amoadd.d%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_adddi },
    &operand_data[346],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:71 */
  {
    "atomic_ordi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F2amoor.d%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_ordi },
    &operand_data[346],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:71 */
  {
    "atomic_xordi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F2amoxor.d%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_xordi },
    &operand_data[346],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:71 */
  {
    "atomic_anddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F2amoand.d%A2 zero,%z1,%0",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_anddi },
    &operand_data[346],
    3,
    3,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:82 */
  {
    "atomic_fetch_addsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F3amoadd.w%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_addsi },
    &operand_data[349],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:82 */
  {
    "atomic_fetch_orsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F3amoor.w%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_orsi },
    &operand_data[349],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:82 */
  {
    "atomic_fetch_xorsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F3amoxor.w%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_xorsi },
    &operand_data[349],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:82 */
  {
    "atomic_fetch_andsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F3amoand.w%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_andsi },
    &operand_data[349],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:82 */
  {
    "atomic_fetch_adddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F3amoadd.d%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_adddi },
    &operand_data[353],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:82 */
  {
    "atomic_fetch_ordi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F3amoor.d%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_ordi },
    &operand_data[353],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:82 */
  {
    "atomic_fetch_xordi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F3amoxor.d%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_xordi },
    &operand_data[353],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:82 */
  {
    "atomic_fetch_anddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F3amoand.d%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_fetch_anddi },
    &operand_data[353],
    4,
    4,
    2,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:95 */
  {
    "atomic_exchangesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F3amoswap.w%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_exchangesi },
    &operand_data[357],
    4,
    4,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:95 */
  {
    "atomic_exchangedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F3amoswap.d%A3 %0,%z2,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_exchangedi },
    &operand_data[361],
    4,
    4,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:107 */
  {
    "atomic_cas_value_strongsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F5 1: lr.w%A5 %0,%1; bne %0,%z2,1f; sc.w%A4 %6,%z3,%1; bnez %6,1b; 1:",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_cas_value_strongsi },
    &operand_data[365],
    6,
    7,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/sync.md:107 */
  {
    "atomic_cas_value_strongdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "%F5 1: lr.d%A5 %0,%1; bne %0,%z2,1f; sc.d%A4 %6,%z3,%1; bnez %6,1b; 1:",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_cas_value_strongdi },
    &operand_data[372],
    6,
    7,
    1,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:25 */
  {
    "*local_pic_loadqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[379],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:25 */
  {
    "*local_pic_loadhi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lhu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[381],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:25 */
  {
    "*local_pic_loadsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lw\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[383],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:25 */
  {
    "*local_pic_loaddi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "ld\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[385],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:32 */
  {
    "*local_pic_load_sqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lb\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[381],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:32 */
  {
    "*local_pic_load_sqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lb\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[383],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:32 */
  {
    "*local_pic_load_sqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lb\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[385],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:32 */
  {
    "*local_pic_load_shi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lh\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[381],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:32 */
  {
    "*local_pic_load_shi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lh\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[383],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:32 */
  {
    "*local_pic_load_shi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lh\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[385],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:32 */
  {
    "*local_pic_load_ssi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lw\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[381],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:32 */
  {
    "*local_pic_load_ssi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lw\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[383],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:32 */
  {
    "*local_pic_load_ssi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lw\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[385],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:39 */
  {
    "*local_pic_load_uqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[381],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:39 */
  {
    "*local_pic_load_uqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[383],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:39 */
  {
    "*local_pic_load_uqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lbu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[385],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:39 */
  {
    "*local_pic_load_uhi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lhu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[381],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:39 */
  {
    "*local_pic_load_uhi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lhu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[383],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:39 */
  {
    "*local_pic_load_uhi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lhu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[385],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:39 */
  {
    "*local_pic_load_usi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[381],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:39 */
  {
    "*local_pic_load_usi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[383],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:39 */
  {
    "*local_pic_load_usi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lwu\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[385],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:49 */
  {
    "*local_pic_loadsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_316 },
#else
    { 0, output_316, 0 },
#endif
    { 0 },
    &operand_data[387],
    2,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/pic.md:49 */
  {
    "*local_pic_loaddf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_317 },
#else
    { 0, output_317, 0 },
#endif
    { 0 },
    &operand_data[390],
    2,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/pic.md:49 */
  {
    "*local_pic_loadsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_318 },
#else
    { 0, output_318, 0 },
#endif
    { 0 },
    &operand_data[393],
    2,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/pic.md:49 */
  {
    "*local_pic_loaddf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_319 },
#else
    { 0, output_319, 0 },
#endif
    { 0 },
    &operand_data[396],
    2,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/pic.md:64 */
  {
    "*local_pic_load_32dsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "flw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[399],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:64 */
  {
    "*local_pic_load_32ddf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fld\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[402],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:64 */
  {
    "*local_pic_load_32dsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "flw\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[405],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:64 */
  {
    "*local_pic_load_32ddf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fld\t%0,%1,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[408],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:73 */
  {
    "*local_pic_load_sfsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "lw\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[411],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:73 */
  {
    "*local_pic_load_sfdf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "ld\t%0,%1",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[413],
    2,
    2,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:83 */
  {
    "*local_pic_storeqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sb\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[414],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:83 */
  {
    "*local_pic_storehi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sh\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[417],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:83 */
  {
    "*local_pic_storesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sw\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[420],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:83 */
  {
    "*local_pic_storedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sd\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[423],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:83 */
  {
    "*local_pic_storeqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sb\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[426],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:83 */
  {
    "*local_pic_storehi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sh\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[429],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:83 */
  {
    "*local_pic_storesi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sw\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[432],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:83 */
  {
    "*local_pic_storedi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sd\t%z1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[435],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:91 */
  {
    "*local_pic_storesf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_334 },
#else
    { 0, output_334, 0 },
#endif
    { 0 },
    &operand_data[438],
    2,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/pic.md:91 */
  {
    "*local_pic_storedf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_335 },
#else
    { 0, output_335, 0 },
#endif
    { 0 },
    &operand_data[441],
    2,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/pic.md:91 */
  {
    "*local_pic_storesf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_336 },
#else
    { 0, output_336, 0 },
#endif
    { 0 },
    &operand_data[444],
    2,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/pic.md:91 */
  {
    "*local_pic_storedf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .multi = output_337 },
#else
    { 0, output_337, 0 },
#endif
    { 0 },
    &operand_data[447],
    2,
    3,
    0,
    2,
    2
  },
  /* ../../gcc/config/riscv/pic.md:106 */
  {
    "*local_pic_store_32dsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsw\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[399],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:106 */
  {
    "*local_pic_store_32ddf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsd\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[402],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:106 */
  {
    "*local_pic_store_32dsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsw\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[405],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:106 */
  {
    "*local_pic_store_32ddf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "fsd\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[408],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:115 */
  {
    "*local_pic_store_sfsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sw\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[450],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:115 */
  {
    "*local_pic_store_sfdf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sd\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[453],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:115 */
  {
    "*local_pic_store_sfsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sw\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[456],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/pic.md:115 */
  {
    "*local_pic_store_sfdf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { .single =
#else
    {
#endif
    "sd\t%1,%0,%2",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    },
#else
    0, 0 },
#endif
    { 0 },
    &operand_data[459],
    2,
    3,
    0,
    1,
    1
  },
  /* ../../gcc/config/riscv/riscv.md:647 */
  {
    "mulditi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mulditi3 },
    &operand_data[462],
    3,
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:647 */
  {
    "umulditi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umulditi3 },
    &operand_data[462],
    3,
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:678 */
  {
    "usmulditi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_usmulditi3 },
    &operand_data[462],
    3,
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:709 */
  {
    "mulsidi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mulsidi3 },
    &operand_data[48],
    3,
    3,
    0,
    1,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:709 */
  {
    "umulsidi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_umulsidi3 },
    &operand_data[48],
    3,
    3,
    0,
    1,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:740 */
  {
    "usmulsidi3",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_usmulsidi3 },
    &operand_data[48],
    3,
    3,
    0,
    1,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1320 */
  {
    "movdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movdi },
    &operand_data[465],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1351 */
  {
    "movsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movsi },
    &operand_data[467],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1376 */
  {
    "movhi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movhi },
    &operand_data[469],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1418 */
  {
    "movqi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movqi },
    &operand_data[471],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1438 */
  {
    "movsf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movsf },
    &operand_data[473],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1469 */
  {
    "movdf",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movdf },
    &operand_data[475],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1521 */
  {
    "cpymemsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cpymemsi },
    &operand_data[477],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1536 */
  {
    "clear_cache",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_clear_cache },
    &operand_data[481],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1872 */
  {
    "movsicc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movsicc },
    &operand_data[483],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1872 */
  {
    "movdicc",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_movdicc },
    &operand_data[487],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1905 */
  {
    "condjump",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_condjump },
    &operand_data[491],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1911 */
  {
    "cbranchqi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cbranchqi4 },
    &operand_data[493],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1911 */
  {
    "cbranchsi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cbranchsi4 },
    &operand_data[497],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1911 */
  {
    "cbranchdi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cbranchdi4 },
    &operand_data[501],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1925 */
  {
    "cbranchsf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cbranchsf4 },
    &operand_data[505],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:1925 */
  {
    "cbranchdf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cbranchdf4 },
    &operand_data[509],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2004 */
  {
    "cstoresi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cstoresi4 },
    &operand_data[513],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2004 */
  {
    "cstoredi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cstoredi4 },
    &operand_data[517],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2016 */
  {
    "cstoresf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cstoresf4 },
    &operand_data[521],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2016 */
  {
    "cstoredf4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_cstoredf4 },
    &operand_data[525],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2038 */
  {
    "flt_quietsfsi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_flt_quietsfsi4 },
    &operand_data[529],
    3,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2038 */
  {
    "fle_quietsfsi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fle_quietsfsi4 },
    &operand_data[529],
    3,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2038 */
  {
    "flt_quietsfdi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_flt_quietsfdi4 },
    &operand_data[533],
    3,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2038 */
  {
    "fle_quietsfdi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fle_quietsfdi4 },
    &operand_data[533],
    3,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2038 */
  {
    "flt_quietdfsi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_flt_quietdfsi4 },
    &operand_data[537],
    3,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2038 */
  {
    "fle_quietdfsi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fle_quietdfsi4 },
    &operand_data[537],
    3,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2038 */
  {
    "flt_quietdfdi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_flt_quietdfdi4 },
    &operand_data[541],
    3,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2038 */
  {
    "fle_quietdfdi4",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_fle_quietdfdi4 },
    &operand_data[541],
    3,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2147 */
  {
    "indirect_jump",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_indirect_jump },
    &operand_data[545],
    1,
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2166 */
  {
    "tablejump",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_tablejump },
    &operand_data[545],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2199 */
  {
    "prologue",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_prologue },
    &operand_data[0],
    0,
    0,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2218 */
  {
    "epilogue",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_epilogue },
    &operand_data[0],
    0,
    0,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2226 */
  {
    "sibcall_epilogue",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall_epilogue },
    &operand_data[0],
    0,
    0,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2237 */
  {
    "return",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_return },
    &operand_data[0],
    0,
    0,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2262 */
  {
    "eh_return",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_eh_return },
    &operand_data[547],
    1,
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2318 */
  {
    "sibcall",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall },
    &operand_data[548],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2340 */
  {
    "sibcall_value",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_sibcall_value },
    &operand_data[548],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2363 */
  {
    "call",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_call },
    &operand_data[548],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2386 */
  {
    "call_value",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_call_value },
    &operand_data[548],
    4,
    4,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2412 */
  {
    "untyped_call",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_untyped_call },
    &operand_data[548],
    3,
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2512 */
  {
    "restore_stack_nonlocal",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_restore_stack_nonlocal },
    &operand_data[552],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2525 */
  {
    "get_thread_pointersi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_get_thread_pointersi },
    &operand_data[23],
    1,
    1,
    0,
    1,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2525 */
  {
    "get_thread_pointerdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_get_thread_pointerdi },
    &operand_data[20],
    1,
    1,
    0,
    1,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2533 */
  {
    "stack_protect_set",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_stack_protect_set },
    &operand_data[553],
    2,
    2,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/riscv.md:2564 */
  {
    "stack_protect_test",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_stack_protect_test },
    &operand_data[553],
    3,
    3,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/sync.md:36 */
  {
    "mem_thread_fence",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_mem_thread_fence },
    &operand_data[117],
    1,
    1,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/sync.md:121 */
  {
    "atomic_compare_and_swapsi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_compare_and_swapsi },
    &operand_data[556],
    8,
    8,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/sync.md:121 */
  {
    "atomic_compare_and_swapdi",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_compare_and_swapdi },
    &operand_data[564],
    8,
    8,
    0,
    0,
    0
  },
  /* ../../gcc/config/riscv/sync.md:155 */
  {
    "atomic_test_and_set",
#if HAVE_DESIGNATED_UNION_INITIALIZERS
    { 0 },
#else
    { 0, 0, 0 },
#endif
    { (insn_gen_fn::stored_funcptr) gen_atomic_test_and_set },
    &operand_data[572],
    3,
    3,
    0,
    1,
    0
  },
};


const char *
get_insn_name (int code)
{
  if (code == NOOP_MOVE_INSN_CODE)
    return "NOOP_MOVE";
  else
    return insn_data[code].name;
}
