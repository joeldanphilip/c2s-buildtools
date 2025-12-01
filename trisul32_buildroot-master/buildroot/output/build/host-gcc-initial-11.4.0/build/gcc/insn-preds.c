/* Generated automatically by the program 'build/genpreds'
   from the machine description file '../../gcc/config/riscv/riscv.md'.  */

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
#include "insn-config.h"
#include "recog.h"
#include "output.h"
#include "flags.h"
#include "df.h"
#include "resource.h"
#include "diagnostic-core.h"
#include "reload.h"
#include "regs.h"
#include "emit-rtl.h"
#include "tm-constrs.h"
#include "target.h"

int
const_arith_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 24 "../../gcc/config/riscv/predicates.md"
(SMALL_OPERAND (INTVAL (op))));
}

int
arith_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_arith_operand (op, mode)) || (register_operand (op, mode));
}

int
lui_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 32 "../../gcc/config/riscv/predicates.md"
(LUI_OPERAND (INTVAL (op))));
}

int
sfb_alu_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (arith_operand (op, mode)) || (lui_operand (op, mode));
}

int
const_csr_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 40 "../../gcc/config/riscv/predicates.md"
(IN_RANGE (INTVAL (op), 0, 31)));
}

int
csr_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_csr_operand (op, mode)) || (register_operand (op, mode));
}

int
sle_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 48 "../../gcc/config/riscv/predicates.md"
(SMALL_OPERAND (INTVAL (op) + 1)));
}

int
sleu_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (sle_operand (op, mode)) && (
#line 52 "../../gcc/config/riscv/predicates.md"
(INTVAL (op) + 1 != 0));
}

int
const_0_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST_INT:
    case CONST_WIDE_INT:
    case CONST_DOUBLE:
    case CONST_VECTOR:
      break;
    default:
      return false;
    }
  return (
#line 56 "../../gcc/config/riscv/predicates.md"
(op == CONST0_RTX (GET_MODE (op)))) && (
(mode == VOIDmode || GET_MODE (op) == mode || GET_MODE (op) == VOIDmode));
}

int
reg_or_0_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (const_0_operand (op, mode)) || (register_operand (op, mode));
}

int
branch_on_bit_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
#line 65 "../../gcc/config/riscv/predicates.md"
(INTVAL (op) >= IMM_BITS - 1));
}

static inline int
splittable_const_int_operand_1 (rtx op ATTRIBUTE_UNUSED, machine_mode mode ATTRIBUTE_UNUSED)
#line 71 "../../gcc/config/riscv/predicates.md"
{
  /* Don't handle multi-word moves this way; we don't want to introduce
     the individual word-mode moves until after reload.  */
  if (GET_MODE_SIZE (mode) > UNITS_PER_WORD)
    return false;

  /* Otherwise check whether the constant can be loaded in a single
     instruction.  */
  return !LUI_OPERAND (INTVAL (op)) && !SMALL_OPERAND (INTVAL (op));
}

int
splittable_const_int_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
(splittable_const_int_operand_1 (op, mode)));
}

static inline int
p2m1_shift_operand_1 (rtx op ATTRIBUTE_UNUSED, machine_mode mode ATTRIBUTE_UNUSED)
#line 84 "../../gcc/config/riscv/predicates.md"
{
  int val = exact_log2 (INTVAL (op) + 1);
  if (val < 12)
    return false;
  return true;
 }

int
p2m1_shift_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
(p2m1_shift_operand_1 (op, mode)));
}

static inline int
high_mask_shift_operand_1 (rtx op ATTRIBUTE_UNUSED, machine_mode mode ATTRIBUTE_UNUSED)
#line 93 "../../gcc/config/riscv/predicates.md"
{
  int val1 = clz_hwi (~ INTVAL (op));
  int val0 = ctz_hwi (INTVAL (op));
  if ((val0 + val1 == BITS_PER_WORD)
      && val0 > 31 && val0 < 64)
    return true;
  return false;
}

int
high_mask_shift_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == CONST_INT) && (
(high_mask_shift_operand_1 (op, mode)));
}

static inline int
move_operand_1 (rtx op ATTRIBUTE_UNUSED, machine_mode mode ATTRIBUTE_UNUSED)
#line 104 "../../gcc/config/riscv/predicates.md"
{
  enum riscv_symbol_type symbol_type;

  /* The thinking here is as follows:

     (1) The move expanders should split complex load sequences into
	 individual instructions.  Those individual instructions can
	 then be optimized by all rtl passes.

     (2) The target of pre-reload load sequences should not be used
	 to store temporary results.  If the target register is only
	 assigned one value, reload can rematerialize that value
	 on demand, rather than spill it to the stack.

     (3) If we allowed pre-reload passes like combine and cse to recreate
	 complex load sequences, we would want to be able to split the
	 sequences before reload as well, so that the pre-reload scheduler
	 can see the individual instructions.  This falls foul of (2);
	 the splitter would be forced to reuse the target register for
	 intermediate results.

     (4) We want to define complex load splitters for combine.  These
	 splitters can request a temporary scratch register, which avoids
	 the problem in (2).  They allow things like:

	      (set (reg T1) (high SYM))
	      (set (reg T2) (low (reg T1) SYM))
	      (set (reg X) (plus (reg T2) (const_int OFFSET)))

	 to be combined into:

	      (set (reg T3) (high SYM+OFFSET))
	      (set (reg X) (lo_sum (reg T3) SYM+OFFSET))

	 if T2 is only used this once.  */
  switch (GET_CODE (op))
    {
    case CONST_INT:
      return !splittable_const_int_operand (op, mode);

    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      return riscv_symbolic_constant_p (op, &symbol_type)
	      && !riscv_split_symbol_type (symbol_type);

    case HIGH:
      op = XEXP (op, 0);
      return riscv_symbolic_constant_p (op, &symbol_type)
	      && riscv_split_symbol_type (symbol_type)
	      && symbol_type != SYMBOL_PCREL;

    default:
      return true;
    }
}

int
move_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (general_operand (op, mode)) && (
(move_operand_1 (op, mode)));
}

static inline int
symbolic_operand_1 (rtx op ATTRIBUTE_UNUSED, machine_mode mode ATTRIBUTE_UNUSED)
#line 163 "../../gcc/config/riscv/predicates.md"
{
  enum riscv_symbol_type type;
  return riscv_symbolic_constant_p (op, &type);
}

int
symbolic_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(symbolic_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode || GET_MODE (op) == VOIDmode));
}

static inline int
absolute_symbolic_operand_1 (rtx op ATTRIBUTE_UNUSED, machine_mode mode ATTRIBUTE_UNUSED)
#line 170 "../../gcc/config/riscv/predicates.md"
{
  enum riscv_symbol_type type;
  return (riscv_symbolic_constant_p (op, &type)
	  && (type == SYMBOL_ABSOLUTE || type == SYMBOL_PCREL));
}

int
absolute_symbolic_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(absolute_symbolic_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode || GET_MODE (op) == VOIDmode));
}

static inline int
plt_symbolic_operand_1 (rtx op ATTRIBUTE_UNUSED, machine_mode mode ATTRIBUTE_UNUSED)
#line 178 "../../gcc/config/riscv/predicates.md"
{
  enum riscv_symbol_type type;
  return (riscv_symbolic_constant_p (op, &type)
	  && type == SYMBOL_GOT_DISP && !SYMBOL_REF_WEAK (op) && TARGET_PLT);
}

int
plt_symbolic_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case CONST:
    case SYMBOL_REF:
    case LABEL_REF:
      break;
    default:
      return false;
    }
  return (
(plt_symbolic_operand_1 (op, mode))) && (
(mode == VOIDmode || GET_MODE (op) == mode || GET_MODE (op) == VOIDmode));
}

int
call_insn_operand (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (absolute_symbolic_operand (op, mode)) || ((plt_symbolic_operand (op, mode)) || (register_operand (op, mode)));
}

int
modular_operator (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case PLUS:
    case MINUS:
    case MULT:
    case ASHIFT:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
equality_operator (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case EQ:
    case NE:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
order_operator (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case EQ:
    case NE:
    case LT:
    case LTU:
    case LE:
    case LEU:
    case GE:
    case GEU:
    case GT:
    case GTU:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
signed_order_operator (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case EQ:
    case NE:
    case LT:
    case LE:
    case GE:
    case GT:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
subreg_lowpart_operator (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return ((GET_CODE (op) == TRUNCATE) || ((GET_CODE (op) == SUBREG) && (
#line 204 "../../gcc/config/riscv/predicates.md"
(subreg_lowpart_p (op))))) && (
(mode == VOIDmode || GET_MODE (op) == mode));
}

int
fp_native_comparison (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case EQ:
    case LT:
    case LE:
    case GT:
    case GE:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
fp_scc_comparison (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case UNORDERED:
    case ORDERED:
    case UNLT:
    case UNGE:
    case UNLE:
    case UNGT:
    case LTGT:
    case NE:
    case EQ:
    case LT:
    case LE:
    case GT:
    case GE:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

int
fp_branch_comparison (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  switch (GET_CODE (op))
    {
    case UNORDERED:
    case ORDERED:
    case UNLT:
    case UNGE:
    case UNLE:
    case UNGT:
    case UNEQ:
    case LTGT:
    case NE:
    case EQ:
    case LT:
    case LE:
    case GT:
    case GE:
      break;
    default:
      return false;
    }
  return 
(mode == VOIDmode || GET_MODE (op) == mode);
}

static inline int
gpr_save_operation_1 (rtx op ATTRIBUTE_UNUSED, machine_mode mode ATTRIBUTE_UNUSED)
#line 217 "../../gcc/config/riscv/predicates.md"
{
  return riscv_gpr_save_operation_p (op);
}

int
gpr_save_operation (rtx op, machine_mode mode ATTRIBUTE_UNUSED)
{
  return (GET_CODE (op) == PARALLEL) && (
(gpr_save_operation_1 (op, mode)));
}

enum constraint_num
lookup_constraint_1 (const char *str)
{
  switch (str[0])
    {
    case '<':
      return CONSTRAINT__l;
    case '>':
      return CONSTRAINT__g;
    case 'A':
      return CONSTRAINT_A;
    case 'E':
      return CONSTRAINT_E;
    case 'F':
      return CONSTRAINT_F;
    case 'G':
      return CONSTRAINT_G;
    case 'I':
      return CONSTRAINT_I;
    case 'J':
      return CONSTRAINT_J;
    case 'K':
      return CONSTRAINT_K;
    case 'L':
      return CONSTRAINT_L;
    case 'S':
      return CONSTRAINT_S;
    case 'T':
      return CONSTRAINT_T;
    case 'U':
      return CONSTRAINT_U;
    case 'V':
      return CONSTRAINT_V;
    case 'X':
      return CONSTRAINT_X;
    case 'f':
      return CONSTRAINT_f;
    case 'i':
      return CONSTRAINT_i;
    case 'j':
      return CONSTRAINT_j;
    case 'l':
      return CONSTRAINT_l;
    case 'm':
      return CONSTRAINT_m;
    case 'n':
      return CONSTRAINT_n;
    case 'o':
      return CONSTRAINT_o;
    case 'p':
      return CONSTRAINT_p;
    case 'r':
      return CONSTRAINT_r;
    case 's':
      return CONSTRAINT_s;
    default: break;
    }
  return CONSTRAINT__UNKNOWN;
}

const unsigned char lookup_constraint_array[] = {
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT__l, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT__g, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT_A, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT_E, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_F, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_G, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT_I, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_J, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_K, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_L, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT_S, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_T, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_U, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_V, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT_X, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT_f, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT_i, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_j, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT_l, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_m, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_n, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_o, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_p, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  MIN ((int) CONSTRAINT_r, (int) UCHAR_MAX),
  MIN ((int) CONSTRAINT_s, (int) UCHAR_MAX),
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN,
  CONSTRAINT__UNKNOWN
};

enum reg_class
reg_class_for_constraint_1 (enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_r: return GENERAL_REGS;
    case CONSTRAINT_f: return TARGET_HARD_FLOAT ? FP_REGS : NO_REGS;
    case CONSTRAINT_j: return SIBCALL_REGS;
    case CONSTRAINT_l: return JALR_REGS;
    default: break;
    }
  return NO_REGS;
}

bool (*constraint_satisfied_p_array[]) (rtx) = {
  satisfies_constraint_I,
  satisfies_constraint_J,
  satisfies_constraint_K,
  satisfies_constraint_L,
  satisfies_constraint_m,
  satisfies_constraint_o,
  satisfies_constraint_A,
  satisfies_constraint_p,
  satisfies_constraint_G,
  satisfies_constraint_S,
  satisfies_constraint_U,
  satisfies_constraint_V,
  satisfies_constraint__l,
  satisfies_constraint__g,
  satisfies_constraint_i,
  satisfies_constraint_s,
  satisfies_constraint_n,
  satisfies_constraint_E,
  satisfies_constraint_F,
  satisfies_constraint_X,
  satisfies_constraint_T
};

bool
insn_const_int_ok_for_constraint (HOST_WIDE_INT ival, enum constraint_num c)
{
  switch (c)
    {
    case CONSTRAINT_I:
      return 
#line 40 "../../gcc/config/riscv/constraints.md"
(SMALL_OPERAND (ival));

    case CONSTRAINT_J:
      return 
#line 45 "../../gcc/config/riscv/constraints.md"
(ival == 0);

    case CONSTRAINT_K:
      return 
#line 50 "../../gcc/config/riscv/constraints.md"
(IN_RANGE (ival, 0, 31));

    case CONSTRAINT_L:
      return 
#line 55 "../../gcc/config/riscv/constraints.md"
(LUI_OPERAND (ival));

    default: break;
    }
  return false;
}

