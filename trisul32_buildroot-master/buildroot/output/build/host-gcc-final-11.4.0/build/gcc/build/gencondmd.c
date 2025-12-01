/* Generated automatically by the program `genconditions' from the target
   machine description file.  */

#define IN_TARGET_CODE 1
#include "bconfig.h"
#define INCLUDE_STRING
#include "system.h"

/* It is necessary, but not entirely safe, to include the headers below
   in a generator program.  As a defensive measure, don't do so when the
   table isn't going to have anything in it.  */
#if GCC_VERSION >= 3001

/* Do not allow checking to confuse the issue.  */
#undef CHECKING_P
#define CHECKING_P 0
#undef ENABLE_TREE_CHECKING
#undef ENABLE_RTL_CHECKING
#undef ENABLE_RTL_FLAG_CHECKING
#undef ENABLE_GC_CHECKING
#undef ENABLE_GC_ALWAYS_COLLECT
#define USE_ENUM_MODES

#include "coretypes.h"
#include "tm.h"
#include "insn-constants.h"
#include "rtl.h"
#include "memmodel.h"
#include "tm_p.h"
#include "hard-reg-set.h"
#include "function.h"
#include "emit-rtl.h"

/* Fake - insn-config.h doesn't exist yet.  */
#define MAX_RECOG_OPERANDS 10
#define MAX_DUP_OPERANDS 10
#define MAX_INSNS_PER_SPLIT 5

#include "regs.h"
#include "recog.h"
#include "output.h"
#include "flags.h"
#include "hard-reg-set.h"
#include "predict.h"
#include "basic-block.h"
#include "bitmap.h"
#include "df.h"
#include "resource.h"
#include "diagnostic-core.h"
#include "reload.h"
#include "tm-constrs.h"

#define HAVE_eh_return 1
#include "except.h"

/* Dummy external declarations.  */
extern rtx_insn *insn;
extern rtx ins1;
extern rtx operands[];

#endif /* gcc >= 3.0.1 */

/* Structure definition duplicated from gensupport.h rather than
   drag in that file and its dependencies.  */
struct c_test
{
  const char *expr;
  int value;
};

/* This table lists each condition found in the machine description.
   Each condition is mapped to its truth value (0 or 1), or -1 if that
   cannot be calculated at compile time.
   If we don't have __builtin_constant_p, or it's not acceptable in array
   initializers, fall back to assuming that all conditions potentially
   vary at run time.  It works in 3.0.1 and later; 3.0 only when not
   optimizing.  */

#if GCC_VERSION >= 3001
static const struct c_test insn_conditions[] = {

  { "(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && ((((!TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)) && (!TARGET_64BIT))",
    __builtin_constant_p (
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    ? (int) (
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    : -1 },
  { "(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && ((((TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)) && (TARGET_64BIT))",
    __builtin_constant_p (
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    ? (int) (
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    : -1 },
#line 1156 "../../gcc/config/riscv/riscv.md"
  { "TARGET_DOUBLE_FLOAT",
    __builtin_constant_p 
#line 1156 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)
    ? (int) 
#line 1156 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)
    : -1 },
  { "(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 927 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 927 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])\n\
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && ((TARGET_HARD_FLOAT) && (Pmode == DImode))",
    __builtin_constant_p (
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    ? (int) (
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])\n\
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && ((TARGET_DOUBLE_FLOAT) && (Pmode == SImode))",
    __builtin_constant_p (
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    ? (int) (
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    : -1 },
#line 801 "../../gcc/config/riscv/riscv.md"
  { "TARGET_DIV && TARGET_64BIT",
    __builtin_constant_p 
#line 801 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV && TARGET_64BIT)
    ? (int) 
#line 801 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV && TARGET_64BIT)
    : -1 },
#line 1342 "../../gcc/config/riscv/riscv.md"
  { "TARGET_64BIT\n\
   && (register_operand (operands[0], DImode)\n\
       || reg_or_0_operand (operands[1], DImode))",
    __builtin_constant_p 
#line 1342 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    ? (int) 
#line 1342 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    : -1 },
  { "(USE_LOAD_ADDRESS_MACRO (operands[0])) && ((TARGET_64BIT) && (Pmode == SImode))",
    __builtin_constant_p (
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 296 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    ? (int) (
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 296 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    : -1 },
  { "(TARGET_HARD_FLOAT) && ((TARGET_64BIT) && (TARGET_HARD_FLOAT))",
    __builtin_constant_p (
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    ? (int) (
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    : -1 },
#line 268 "../../gcc/config/riscv/riscv.md"
  { "Pmode == DImode",
    __builtin_constant_p 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)
    ? (int) 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)
    : -1 },
  { "(TARGET_HARD_FLOAT) && (((!TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT))",
    __builtin_constant_p (
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    ? (int) (
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    : -1 },
  { "(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && (TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 927 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 927 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))
    : -1 },
#line 1388 "../../gcc/config/riscv/riscv.md"
  { "(register_operand (operands[0], HImode)\n\
    || reg_or_0_operand (operands[1], HImode))",
    __builtin_constant_p 
#line 1388 "../../gcc/config/riscv/riscv.md"
((register_operand (operands[0], HImode)
    || reg_or_0_operand (operands[1], HImode)))
    ? (int) 
#line 1388 "../../gcc/config/riscv/riscv.md"
((register_operand (operands[0], HImode)
    || reg_or_0_operand (operands[1], HImode)))
    : -1 },
  { "(USE_LOAD_ADDRESS_MACRO (operands[0])) && (Pmode == DImode)",
    __builtin_constant_p (
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
    ? (int) (
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])\n\
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && ((TARGET_DOUBLE_FLOAT) && (Pmode == DImode))",
    __builtin_constant_p (
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    ? (int) (
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    : -1 },
#line 1503 "../../gcc/config/riscv/riscv.md"
  { "!TARGET_DOUBLE_FLOAT\n\
   && (register_operand (operands[0], DFmode)\n\
       || reg_or_0_operand (operands[1], DFmode))",
    __builtin_constant_p 
#line 1503 "../../gcc/config/riscv/riscv.md"
(!TARGET_DOUBLE_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    ? (int) 
#line 1503 "../../gcc/config/riscv/riscv.md"
(!TARGET_DOUBLE_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])\n\
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && ((TARGET_DOUBLE_FLOAT) && (Pmode == SImode))",
    __builtin_constant_p (
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    ? (int) (
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    : -1 },
  { "(TARGET_HARD_FLOAT) && ((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT))",
    __builtin_constant_p (
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
    ? (int) (
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
    : -1 },
#line 1483 "../../gcc/config/riscv/riscv.md"
  { "!TARGET_64BIT && TARGET_DOUBLE_FLOAT\n\
   && (register_operand (operands[0], DFmode)\n\
       || reg_or_0_operand (operands[1], DFmode))",
    __builtin_constant_p 
#line 1483 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT && TARGET_DOUBLE_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    ? (int) 
#line 1483 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT && TARGET_DOUBLE_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    : -1 },
#line 1138 "../../gcc/config/riscv/riscv.md"
  { " reload_completed\n\
   && REG_P (operands[1])\n\
   && !paradoxical_subreg_p (operands[0])",
    __builtin_constant_p 
#line 1138 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0]))
    ? (int) 
#line 1138 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0]))
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])\n\
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && ((TARGET_HARD_FLOAT) && (Pmode == DImode))",
    __builtin_constant_p (
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    ? (int) (
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    : -1 },
#line 782 "../../gcc/config/riscv/riscv.md"
  { "TARGET_DIV",
    __builtin_constant_p 
#line 782 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV)
    ? (int) 
#line 782 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV)
    : -1 },
  { "(TARGET_64BIT\n\
   && ((INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff)) && ( reload_completed)",
    __builtin_constant_p (
#line 1836 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && ((INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff)) && 
#line 1839 "../../gcc/config/riscv/riscv.md"
( reload_completed))
    ? (int) (
#line 1836 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && ((INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff)) && 
#line 1839 "../../gcc/config/riscv/riscv.md"
( reload_completed))
    : -1 },
  { "(USE_LOAD_ADDRESS_MACRO (operands[1])) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
#line 1460 "../../gcc/config/riscv/riscv.md"
  { "!TARGET_HARD_FLOAT\n\
   && (register_operand (operands[0], SFmode)\n\
       || reg_or_0_operand (operands[1], SFmode))",
    __builtin_constant_p 
#line 1460 "../../gcc/config/riscv/riscv.md"
(!TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    ? (int) 
#line 1460 "../../gcc/config/riscv/riscv.md"
(!TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    : -1 },
#line 603 "../../gcc/config/riscv/riscv.md"
  { "TARGET_MUL",
    __builtin_constant_p 
#line 603 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL)
    ? (int) 
#line 603 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL)
    : -1 },
#line 2284 "../../gcc/config/riscv/riscv.md"
  { "! TARGET_64BIT",
    __builtin_constant_p 
#line 2284 "../../gcc/config/riscv/riscv.md"
(! TARGET_64BIT)
    ? (int) 
#line 2284 "../../gcc/config/riscv/riscv.md"
(! TARGET_64BIT)
    : -1 },
#line 42 "../../gcc/config/riscv/pic.md"
  { "USE_LOAD_ADDRESS_MACRO (operands[1])",
    __builtin_constant_p 
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1]))
    ? (int) 
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1]))
    : -1 },
#line 1493 "../../gcc/config/riscv/riscv.md"
  { "TARGET_64BIT && TARGET_DOUBLE_FLOAT\n\
   && (register_operand (operands[0], DFmode)\n\
       || reg_or_0_operand (operands[1], DFmode))",
    __builtin_constant_p 
#line 1493 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT && TARGET_DOUBLE_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    ? (int) 
#line 1493 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT && TARGET_DOUBLE_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode)))
    : -1 },
  { "(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 76 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 76 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])\n\
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && ((TARGET_DOUBLE_FLOAT) && (Pmode == SImode))",
    __builtin_constant_p (
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    ? (int) (
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    : -1 },
  { "(TARGET_HARD_FLOAT) && ((((TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)) && (TARGET_64BIT))",
    __builtin_constant_p (
#line 2045 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    ? (int) (
#line 2045 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    : -1 },
#line 682 "../../gcc/config/riscv/riscv.md"
  { "TARGET_MUL && TARGET_64BIT",
    __builtin_constant_p 
#line 682 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && TARGET_64BIT)
    ? (int) 
#line 682 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && TARGET_64BIT)
    : -1 },
  { "(TARGET_HARD_FLOAT) && (((!TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT))",
    __builtin_constant_p (
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
    ? (int) (
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
    : -1 },
#line 1751 "../../gcc/config/riscv/riscv.md"
  { "TARGET_64BIT && (INTVAL (operands[2]) & 0x1f) > 0",
    __builtin_constant_p 
#line 1751 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT && (INTVAL (operands[2]) & 0x1f) > 0)
    ? (int) 
#line 1751 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT && (INTVAL (operands[2]) & 0x1f) > 0)
    : -1 },
#line 271 "../../gcc/config/riscv/riscv.md"
  { "!TARGET_64BIT",
    __builtin_constant_p 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)
    ? (int) 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)
    : -1 },
  { "(TARGET_HARD_FLOAT) && ((TARGET_HARD_FLOAT) && (TARGET_64BIT))",
    __builtin_constant_p (
#line 1199 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    ? (int) (
#line 1199 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    : -1 },
#line 1877 "../../gcc/config/riscv/riscv.md"
  { "TARGET_SFB_ALU",
    __builtin_constant_p 
#line 1877 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU)
    ? (int) 
#line 1877 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU)
    : -1 },
  { "(TARGET_HARD_FLOAT) && ((((!TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT)) && (!TARGET_64BIT))",
    __builtin_constant_p (
#line 2045 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    ? (int) (
#line 2045 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    : -1 },
#line 159 "../../gcc/config/riscv/sync.md"
  { "TARGET_ATOMIC",
    __builtin_constant_p 
#line 159 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC)
    ? (int) 
#line 159 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC)
    : -1 },
  { "(TARGET_HARD_FLOAT) && (TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 2021 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 2021 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))
    : -1 },
#line 1836 "../../gcc/config/riscv/riscv.md"
  { "TARGET_64BIT\n\
   && ((INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff)",
    __builtin_constant_p 
#line 1836 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && ((INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff))
    ? (int) 
#line 1836 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && ((INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff))
    : -1 },
#line 1731 "../../gcc/config/riscv/riscv.md"
  { "TARGET_64BIT\n\
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))\n\
       == GET_MODE_BITSIZE (SImode)-1",
    __builtin_constant_p 
#line 1731 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1)
    ? (int) 
#line 1731 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1)
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])\n\
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && ((TARGET_HARD_FLOAT) && (Pmode == SImode))",
    __builtin_constant_p (
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    ? (int) (
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    : -1 },
  { "(USE_LOAD_ADDRESS_MACRO (operands[0])) && (Pmode == SImode)",
    __builtin_constant_p (
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
    ? (int) (
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
    : -1 },
  { "(TARGET_SFB_ALU) && (!TARGET_64BIT)",
    __builtin_constant_p (
#line 1896 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
    ? (int) (
#line 1896 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
    : -1 },
  { "(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && ((TARGET_64BIT) && (Pmode == DImode))",
    __builtin_constant_p (
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    ? (int) (
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    : -1 },
  { "(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && ((((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT)) && (TARGET_64BIT))",
    __builtin_constant_p (
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    ? (int) (
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    : -1 },
#line 2307 "../../gcc/config/riscv/riscv.md"
  { "epilogue_completed",
    __builtin_constant_p 
#line 2307 "../../gcc/config/riscv/riscv.md"
(epilogue_completed)
    ? (int) 
#line 2307 "../../gcc/config/riscv/riscv.md"
(epilogue_completed)
    : -1 },
  { "(TARGET_HARD_FLOAT) && ((((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT)) && (TARGET_64BIT))",
    __builtin_constant_p (
#line 2045 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    ? (int) (
#line 2045 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    : -1 },
  { "(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL, TRUE)) && (Pmode == DImode)",
    __builtin_constant_p (
#line 1311 "../../gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL, TRUE)) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
    ? (int) (
#line 1311 "../../gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL, TRUE)) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
    : -1 },
  { "(TARGET_HARD_FLOAT) && (((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT))",
    __builtin_constant_p (
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
    ? (int) (
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])\n\
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && ((TARGET_HARD_FLOAT) && (Pmode == SImode))",
    __builtin_constant_p (
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    ? (int) (
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    : -1 },
#line 30 "../../gcc/config/riscv/peephole.md"
  { "TARGET_64BIT\n\
   && INTVAL (operands[5]) < INTVAL (operands[2])\n\
   && (REGNO (operands[3]) == REGNO (operands[4])\n\
       || peep2_reg_dead_p (3, operands[3]))",
    __builtin_constant_p 
#line 30 "../../gcc/config/riscv/peephole.md"
(TARGET_64BIT
   && INTVAL (operands[5]) < INTVAL (operands[2])
   && (REGNO (operands[3]) == REGNO (operands[4])
       || peep2_reg_dead_p (3, operands[3])))
    ? (int) 
#line 30 "../../gcc/config/riscv/peephole.md"
(TARGET_64BIT
   && INTVAL (operands[5]) < INTVAL (operands[2])
   && (REGNO (operands[3]) == REGNO (operands[4])
       || peep2_reg_dead_p (3, operands[3])))
    : -1 },
  { "(reload_completed) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 1983 "../../gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 1983 "../../gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])\n\
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && ((TARGET_DOUBLE_FLOAT) && (Pmode == DImode))",
    __builtin_constant_p (
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    ? (int) (
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    : -1 },
  { "(TARGET_SFB_ALU) && (((((TARGET_64BIT) && (!TARGET_64BIT)) && (!TARGET_64BIT)) && (TARGET_64BIT)) && (TARGET_64BIT))",
    __builtin_constant_p (
#line 1896 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU) && ((((
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    ? (int) (
#line 1896 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU) && ((((
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    : -1 },
  { "(TARGET_64BIT\n\
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))\n\
       == GET_MODE_BITSIZE (DImode)-1) && ( 1)",
    __builtin_constant_p (
#line 1673 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1) && 
#line 1677 "../../gcc/config/riscv/riscv.md"
( 1))
    ? (int) (
#line 1673 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1) && 
#line 1677 "../../gcc/config/riscv/riscv.md"
( 1))
    : -1 },
  { "(TARGET_HARD_FLOAT && TARGET_FDIV) && (TARGET_DOUBLE_FLOAT)",
    __builtin_constant_p (
#line 825 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))
    ? (int) (
#line 825 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])\n\
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && ((TARGET_HARD_FLOAT) && (Pmode == DImode))",
    __builtin_constant_p (
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    ? (int) (
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    : -1 },
#line 2021 "../../gcc/config/riscv/riscv.md"
  { "TARGET_HARD_FLOAT",
    __builtin_constant_p 
#line 2021 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)
    ? (int) 
#line 2021 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)
    : -1 },
  { "(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL, TRUE)) && (Pmode == SImode)",
    __builtin_constant_p (
#line 1311 "../../gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL, TRUE)) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
    ? (int) (
#line 1311 "../../gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL, TRUE)) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
    : -1 },
  { "(TARGET_64BIT\n\
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))\n\
       == GET_MODE_BITSIZE (SImode)-1) && ( 1)",
    __builtin_constant_p (
#line 1731 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1735 "../../gcc/config/riscv/riscv.md"
( 1))
    ? (int) (
#line 1731 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1735 "../../gcc/config/riscv/riscv.md"
( 1))
    : -1 },
#line 1673 "../../gcc/config/riscv/riscv.md"
  { "TARGET_64BIT\n\
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))\n\
       == GET_MODE_BITSIZE (DImode)-1",
    __builtin_constant_p 
#line 1673 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1)
    ? (int) 
#line 1673 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1)
    : -1 },
#line 1766 "../../gcc/config/riscv/riscv.md"
  { "(TARGET_64BIT && (INTVAL (operands[3]) > 0)\n\
    && (INTVAL (operands[2]) + INTVAL (operands[3]) == 32))",
    __builtin_constant_p 
#line 1766 "../../gcc/config/riscv/riscv.md"
((TARGET_64BIT && (INTVAL (operands[3]) > 0)
    && (INTVAL (operands[2]) + INTVAL (operands[3]) == 32)))
    ? (int) 
#line 1766 "../../gcc/config/riscv/riscv.md"
((TARGET_64BIT && (INTVAL (operands[3]) > 0)
    && (INTVAL (operands[2]) + INTVAL (operands[3]) == 32)))
    : -1 },
#line 2356 "../../gcc/config/riscv/riscv.md"
  { "SIBLING_CALL_P (insn)",
    __builtin_constant_p 
#line 2356 "../../gcc/config/riscv/riscv.md"
(SIBLING_CALL_P (insn))
    ? (int) 
#line 2356 "../../gcc/config/riscv/riscv.md"
(SIBLING_CALL_P (insn))
    : -1 },
  { "(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && ((((!TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT)) && (!TARGET_64BIT))",
    __builtin_constant_p (
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    ? (int) (
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    : -1 },
#line 1559 "../../gcc/config/riscv/riscv.md"
  { "TARGET_ZIFENCEI",
    __builtin_constant_p 
#line 1559 "../../gcc/config/riscv/riscv.md"
(TARGET_ZIFENCEI)
    ? (int) 
#line 1559 "../../gcc/config/riscv/riscv.md"
(TARGET_ZIFENCEI)
    : -1 },
  { "(TARGET_ATOMIC) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 130 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 130 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
  { "(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && ((((!TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT)) && (!TARGET_64BIT))",
    __builtin_constant_p (
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    ? (int) (
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    : -1 },
  { "(TARGET_64BIT) && (!TARGET_64BIT)",
    __builtin_constant_p (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
    ? (int) (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
    : -1 },
#line 1513 "../../gcc/config/riscv/riscv.md"
  { "reload_completed\n\
   && riscv_split_64bit_move_p (operands[0], operands[1])",
    __builtin_constant_p 
#line 1513 "../../gcc/config/riscv/riscv.md"
(reload_completed
   && riscv_split_64bit_move_p (operands[0], operands[1]))
    ? (int) 
#line 1513 "../../gcc/config/riscv/riscv.md"
(reload_completed
   && riscv_split_64bit_move_p (operands[0], operands[1]))
    : -1 },
  { "(USE_LOAD_ADDRESS_MACRO (operands[0])) && ((TARGET_64BIT) && (Pmode == DImode))",
    __builtin_constant_p (
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 296 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    ? (int) (
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 296 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    : -1 },
#line 1450 "../../gcc/config/riscv/riscv.md"
  { "TARGET_HARD_FLOAT\n\
   && (register_operand (operands[0], SFmode)\n\
       || reg_or_0_operand (operands[1], SFmode))",
    __builtin_constant_p 
#line 1450 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    ? (int) 
#line 1450 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode)))
    : -1 },
#line 746 "../../gcc/config/riscv/riscv.md"
  { "TARGET_MUL && !TARGET_64BIT",
    __builtin_constant_p 
#line 746 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && !TARGET_64BIT)
    ? (int) 
#line 746 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && !TARGET_64BIT)
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])\n\
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && ((TARGET_HARD_FLOAT) && (Pmode == SImode))",
    __builtin_constant_p (
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    ? (int) (
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    : -1 },
  { "(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && (Pmode == DImode)",
    __builtin_constant_p (
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
    ? (int) (
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
    : -1 },
#line 1363 "../../gcc/config/riscv/riscv.md"
  { "(register_operand (operands[0], SImode)\n\
    || reg_or_0_operand (operands[1], SImode))",
    __builtin_constant_p 
#line 1363 "../../gcc/config/riscv/riscv.md"
((register_operand (operands[0], SImode)
    || reg_or_0_operand (operands[1], SImode)))
    ? (int) 
#line 1363 "../../gcc/config/riscv/riscv.md"
((register_operand (operands[0], SImode)
    || reg_or_0_operand (operands[1], SImode)))
    : -1 },
  { "(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])\n\
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && ((TARGET_DOUBLE_FLOAT) && (Pmode == DImode))",
    __builtin_constant_p (
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    ? (int) (
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
    : -1 },
#line 1430 "../../gcc/config/riscv/riscv.md"
  { "(register_operand (operands[0], QImode)\n\
    || reg_or_0_operand (operands[1], QImode))",
    __builtin_constant_p 
#line 1430 "../../gcc/config/riscv/riscv.md"
((register_operand (operands[0], QImode)
    || reg_or_0_operand (operands[1], QImode)))
    ? (int) 
#line 1430 "../../gcc/config/riscv/riscv.md"
((register_operand (operands[0], QImode)
    || reg_or_0_operand (operands[1], QImode)))
    : -1 },
  { "(TARGET_HARD_FLOAT) && (((TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT))",
    __builtin_constant_p (
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    ? (int) (
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
    : -1 },
#line 268 "../../gcc/config/riscv/riscv.md"
  { "Pmode == SImode",
    __builtin_constant_p 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)
    ? (int) 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)
    : -1 },
#line 1332 "../../gcc/config/riscv/riscv.md"
  { "!TARGET_64BIT\n\
   && (register_operand (operands[0], DImode)\n\
       || reg_or_0_operand (operands[1], DImode))",
    __builtin_constant_p 
#line 1332 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    ? (int) 
#line 1332 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode)))
    : -1 },
  { "(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && ((((TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)) && (TARGET_64BIT))",
    __builtin_constant_p (
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    ? (int) (
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    : -1 },
  { "(TARGET_HARD_FLOAT && TARGET_FDIV) && (TARGET_HARD_FLOAT)",
    __builtin_constant_p (
#line 825 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    ? (int) (
#line 825 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
    : -1 },
  { "(TARGET_HARD_FLOAT) && ((((!TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)) && (!TARGET_64BIT))",
    __builtin_constant_p (
#line 2045 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    ? (int) (
#line 2045 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    : -1 },
  { "(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && ((((TARGET_64BIT) && (TARGET_DOUBLE_FLOAT)) && (TARGET_DOUBLE_FLOAT)) && (TARGET_64BIT))",
    __builtin_constant_p (
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    ? (int) (
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    : -1 },
#line 1598 "../../gcc/config/riscv/riscv.md"
  { "(INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))\n\
   == GET_MODE_BITSIZE (SImode)-1",
    __builtin_constant_p 
#line 1598 "../../gcc/config/riscv/riscv.md"
((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
   == GET_MODE_BITSIZE (SImode)-1)
    ? (int) 
#line 1598 "../../gcc/config/riscv/riscv.md"
((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
   == GET_MODE_BITSIZE (SImode)-1)
    : -1 },
  { "((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))\n\
   == GET_MODE_BITSIZE (SImode)-1) && ( 1)",
    __builtin_constant_p (
#line 1598 "../../gcc/config/riscv/riscv.md"
((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
   == GET_MODE_BITSIZE (SImode)-1) && 
#line 1601 "../../gcc/config/riscv/riscv.md"
( 1))
    ? (int) (
#line 1598 "../../gcc/config/riscv/riscv.md"
((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
   == GET_MODE_BITSIZE (SImode)-1) && 
#line 1601 "../../gcc/config/riscv/riscv.md"
( 1))
    : -1 },
#line 2239 "../../gcc/config/riscv/riscv.md"
  { "riscv_can_use_return_insn ()",
    __builtin_constant_p 
#line 2239 "../../gcc/config/riscv/riscv.md"
(riscv_can_use_return_insn ())
    ? (int) 
#line 2239 "../../gcc/config/riscv/riscv.md"
(riscv_can_use_return_insn ())
    : -1 },
  { "(TARGET_64BIT) && ( reload_completed\n\
   && REG_P (operands[1])\n\
   && !paradoxical_subreg_p (operands[0]))",
    __builtin_constant_p (
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1138 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0])))
    ? (int) (
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1138 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0])))
    : -1 },
  { "(TARGET_SFB_ALU) && (TARGET_64BIT)",
    __builtin_constant_p (
#line 1877 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    ? (int) (
#line 1877 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
    : -1 },
  { "(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && ((((!TARGET_64BIT) && (TARGET_HARD_FLOAT)) && (TARGET_HARD_FLOAT)) && (!TARGET_64BIT))",
    __builtin_constant_p (
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    ? (int) (
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
    : -1 },
#line 2296 "../../gcc/config/riscv/riscv.md"
  { "reload_completed",
    __builtin_constant_p 
#line 2296 "../../gcc/config/riscv/riscv.md"
(reload_completed)
    ? (int) 
#line 2296 "../../gcc/config/riscv/riscv.md"
(reload_completed)
    : -1 },
#line 264 "../../gcc/config/riscv/riscv.md"
  { "TARGET_64BIT",
    __builtin_constant_p 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)
    ? (int) 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)
    : -1 },
  { "(TARGET_HARD_FLOAT) && ((TARGET_DOUBLE_FLOAT) && (TARGET_64BIT))",
    __builtin_constant_p (
#line 1199 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    ? (int) (
#line 1199 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
    : -1 },
  { "((TARGET_64BIT) && (!TARGET_64BIT)) && (!TARGET_64BIT)",
    __builtin_constant_p ((
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
    ? (int) ((
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
    : -1 },
  { "(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && (Pmode == SImode)",
    __builtin_constant_p (
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
    ? (int) (
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
    : -1 },
#line 76 "../../gcc/config/riscv/pic.md"
  { "!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])",
    __builtin_constant_p 
#line 76 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1]))
    ? (int) 
#line 76 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1]))
    : -1 },
  { "(reload_completed) && (!TARGET_64BIT)",
    __builtin_constant_p (
#line 1983 "../../gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
    ? (int) (
#line 1983 "../../gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
    : -1 },
  { "(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && ((TARGET_64BIT) && (Pmode == SImode))",
    __builtin_constant_p (
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    ? (int) (
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
    : -1 },

};
#endif /* gcc >= 3.0.1 */

int
main(void)
{
  unsigned int i;
  const char *p;
  puts ("(define_conditions [");
#if GCC_VERSION >= 3001
  for (i = 0; i < ARRAY_SIZE (insn_conditions); i++)
    {
      printf ("  (%d \"", insn_conditions[i].value);
      for (p = insn_conditions[i].expr; *p; p++)
        {
          switch (*p)
	     {
	     case '\\':
	     case '\"': putchar ('\\'); break;
	     default: break;
	     }
          putchar (*p);
        }
      puts ("\")");
    }
#endif /* gcc >= 3.0.1 */
  puts ("])");
  fflush (stdout);
return ferror (stdout) != 0 ? FATAL_EXIT_CODE : SUCCESS_EXIT_CODE;
}
