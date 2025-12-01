/* Generated automatically by the program `genrecog' from the target
   machine description file.  */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "predict.h"
#include "rtl.h"
#include "memmodel.h"
#include "tm_p.h"
#include "emit-rtl.h"
#include "insn-config.h"
#include "recog.h"
#include "output.h"
#include "flags.h"
#include "df.h"
#include "resource.h"
#include "diagnostic-core.h"
#include "reload.h"
#include "regs.h"
#include "tm-constrs.h"



/* `recog' contains a decision tree that recognizes whether the rtx
   X0 is a valid instruction.

   recog returns -1 if the rtx is not valid.  If the rtx is valid, recog
   returns a nonnegative number which is the insn code number for the
   pattern that matched.  This is the same as the order in the machine
   description of the entry that matched.  This number can be used as an
   index into `insn_data' and other tables.

   The third parameter to recog is an optional pointer to an int.  If
   present, recog will accept a pattern if it matches except for missing
   CLOBBER expressions at the end.  In that case, the value pointed to by
   the optional pointer will be set to the number of CLOBBERs that need
   to be added (it should be initialized to zero by the caller).  If it
   is set nonzero, the caller should allocate a PARALLEL of the
   appropriate size, copy the initial entries, and call add_clobbers
   (found in insn-emit.c) to fill in the CLOBBERs.


   The function split_insns returns 0 if the rtl could not
   be split or the split rtl as an INSN list if it can be.

   The function peephole2_insns returns 0 if the rtl could not
   be matched. If there was a match, the new rtl is returned in an INSN list,
   and LAST_INSN will point to the last recognized insn in the old sequence.
*/


extern rtx_insn *gen_split_1 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_2 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_3 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_4 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_5 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_6 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_7 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_8 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_9 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_10 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_11 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_12 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_13 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_14 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_15 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_16 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_17 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_18 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_19 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_20 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_21 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_22 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_23 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_24 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_25 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_26 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_27 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_28 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_29 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_30 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_31 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_32 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_33 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_34 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_35 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_36 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_37 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_38 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_39 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_40 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_41 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_42 (rtx_insn *, rtx *);
extern rtx_insn *gen_split_43 (rtx_insn *, rtx *);
extern rtx_insn *gen_peephole2_1 (rtx_insn *, rtx *);




static int
pattern0 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern1 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  x5 = XEXP (x3, 1);
  operands[2] = x5;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      return pattern0 (x3, E_SImode); /* [-1, 0] */

    case E_DImode:
      if (pattern0 (x3, E_DImode) != 0)
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern2 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  switch (GET_MODE (operands[0]))
    {
    case E_SFmode:
      if (!register_operand (operands[0], E_SFmode)
          || GET_MODE (x3) != E_SFmode
          || !register_operand (operands[1], E_SFmode))
        return -1;
      return 0;

    case E_DFmode:
      if (!register_operand (operands[0], E_DFmode)
          || GET_MODE (x3) != E_DFmode
          || !register_operand (operands[1], E_DFmode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern3 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  x5 = XEXP (x3, 1);
  operands[2] = x5;
  switch (GET_MODE (operands[0]))
    {
    case E_SFmode:
      return pattern0 (x3, E_SFmode); /* [-1, 0] */

    case E_DFmode:
      if (pattern0 (x3, E_DFmode) != 0)
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern4 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  switch (GET_MODE (operands[1]))
    {
    case E_SFmode:
      if (!register_operand (operands[1], E_SFmode))
        return -1;
      return 0;

    case E_DFmode:
      if (!register_operand (operands[1], E_DFmode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern5 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      return pattern4 (x3, E_SImode); /* [-1, 1] */

    case E_DImode:
      res = pattern4 (x3, E_DImode);
      if (res >= 0)
        return res + 2; /* [2, 3] */
      return -1;

    default:
      return -1;
    }
}

static int
pattern6 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  switch (GET_MODE (operands[0]))
    {
    case E_SFmode:
      if (!register_operand (operands[0], E_SFmode)
          || GET_MODE (x3) != E_SFmode)
        return -1;
      return 0;

    case E_DFmode:
      if (!register_operand (operands[0], E_DFmode)
          || GET_MODE (x3) != E_DFmode)
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern7 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) != E_DImode)
    return -1;
  x3 = XEXP (x1, 0);
  operands[0] = x3;
  if (!register_operand (operands[0], E_DImode))
    return -1;
  x4 = XEXP (x2, 0);
  operands[1] = x4;
  if (!register_operand (operands[1], E_DImode))
    return -1;
  x5 = XEXP (x2, 1);
  operands[2] = x5;
  if (!const_int_operand (operands[2], E_VOIDmode))
    return -1;
  return 0;
}

static int
pattern8 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      if (!register_operand (operands[0], E_SImode)
          || GET_MODE (x1) != E_SImode)
        return -1;
      switch (GET_MODE (operands[1]))
        {
        case E_SImode:
          if (!register_operand (operands[1], E_SImode))
            return -1;
          return 0;

        case E_DImode:
          if (!register_operand (operands[1], E_DImode))
            return -1;
          return 1;

        default:
          return -1;
        }

    case E_DImode:
      if (!register_operand (operands[0], E_DImode)
          || GET_MODE (x1) != E_DImode
          || !register_operand (operands[1], E_DImode))
        return -1;
      return 2;

    default:
      return -1;
    }
}

static int
pattern9 (rtx x1, int i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  if (x3 != const_int_rtx[MAX_SAVED_CONST_INT + i1])
    return -1;
  x4 = XEXP (x1, 0);
  operands[0] = x4;
  x5 = XEXP (x2, 0);
  operands[1] = x5;
  return pattern8 (x2); /* [-1, 2] */
}

static int
pattern10 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !register_operand (operands[1], i1)
      || !arith_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern11 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[1] = x2;
  x3 = XEXP (x1, 1);
  operands[2] = x3;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      return pattern10 (x1, E_SImode); /* [-1, 0] */

    case E_DImode:
      if (pattern10 (x1, E_DImode) != 0)
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern12 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3;
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !register_operand (operands[1], i1))
    return -1;
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case E_SImode:
      if (!register_operand (operands[2], E_SImode))
        return -1;
      return 0;

    case E_DImode:
      if (!register_operand (operands[2], E_DImode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern13 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 0);
  operands[2] = x4;
  x5 = XEXP (x3, 1);
  operands[3] = x5;
  if (!const_int_operand (operands[3], E_VOIDmode))
    return -1;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      return pattern12 (x1, E_SImode); /* [-1, 1] */

    case E_DImode:
      res = pattern12 (x1, E_DImode);
      if (res >= 0)
        return res + 2; /* [2, 3] */
      return -1;

    default:
      return -1;
    }
}

static int
pattern14 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  if (!subreg_lowpart_operator (x2, E_VOIDmode))
    return -1;
  operands[4] = x2;
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) != AND)
    return -1;
  x4 = XEXP (x1, 0);
  operands[1] = x4;
  return pattern13 (x1); /* [-1, 3] */
}

static int
pattern15 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != i1
      || !register_operand (operands[0], E_DImode)
      || GET_MODE (x1) != E_DImode)
    return -1;
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  if (!register_operand (operands[1], i1))
    return -1;
  x4 = XEXP (x2, 1);
  operands[2] = x4;
  return 0;
}

static int
pattern16 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != E_SImode
      || !register_operand (operands[0], E_DImode)
      || GET_MODE (x1) != E_DImode)
    return -1;
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  if (!register_operand (operands[1], E_SImode))
    return -1;
  return 0;
}

static int
pattern17 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != E_SImode
      || !register_operand (operands[0], E_DImode)
      || GET_MODE (x1) != E_DImode)
    return -1;
  x3 = XEXP (x2, 0);
  operands[1] = x3;
  if (!register_operand (operands[1], E_SImode))
    return -1;
  x4 = XEXP (x2, 1);
  operands[2] = x4;
  if (!register_operand (operands[2], E_SImode))
    return -1;
  return 0;
}

static int
pattern18 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  switch (GET_MODE (operands[1]))
    {
    case E_SFmode:
      if (!register_operand (operands[1], E_SFmode)
          || !register_operand (operands[2], E_SFmode))
        return -1;
      return 0;

    case E_DFmode:
      if (!register_operand (operands[1], E_DFmode)
          || !register_operand (operands[2], E_DFmode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern19 (rtx x1, int *pnum_clobbers)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  if (pnum_clobbers == NULL)
    return -1;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XVECEXP (x3, 0, 0);
  operands[1] = x4;
  x5 = XVECEXP (x3, 0, 1);
  operands[2] = x5;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      return pattern18 (x3, E_SImode); /* [-1, 1] */

    case E_DImode:
      res = pattern18 (x3, E_DImode);
      if (res >= 0)
        return res + 2; /* [2, 3] */
      return -1;

    default:
      return -1;
    }
}

static int
pattern20 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      if (!register_operand (operands[0], E_SImode)
          || GET_MODE (x1) != E_SImode
          || !register_operand (operands[1], E_SImode))
        return -1;
      return 0;

    case E_DImode:
      if (!register_operand (operands[0], E_DImode)
          || GET_MODE (x1) != E_DImode
          || !register_operand (operands[1], E_DImode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern21 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  operands[2] = x2;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      if (!register_operand (operands[0], E_SImode)
          || GET_MODE (x1) != E_SImode)
        return -1;
      switch (GET_MODE (operands[1]))
        {
        case E_SImode:
          if (!register_operand (operands[1], E_SImode)
              || !reg_or_0_operand (operands[2], E_SImode))
            return -1;
          return 0;

        case E_DImode:
          if (!register_operand (operands[1], E_DImode)
              || !reg_or_0_operand (operands[2], E_DImode))
            return -1;
          return 1;

        default:
          return -1;
        }

    case E_DImode:
      if (!register_operand (operands[0], E_DImode)
          || GET_MODE (x1) != E_DImode
          || !register_operand (operands[1], E_DImode)
          || !reg_or_0_operand (operands[2], E_DImode))
        return -1;
      return 2;

    default:
      return -1;
    }
}

static int
pattern22 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  operands[2] = x2;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      if (!register_operand (operands[0], E_SImode)
          || GET_MODE (x1) != E_SImode)
        return -1;
      switch (GET_MODE (operands[1]))
        {
        case E_SImode:
          if (!register_operand (operands[1], E_SImode)
              || !sle_operand (operands[2], E_SImode))
            return -1;
          return 0;

        case E_DImode:
          if (!register_operand (operands[1], E_DImode)
              || !sle_operand (operands[2], E_DImode))
            return -1;
          return 1;

        default:
          return -1;
        }

    case E_DImode:
      if (!register_operand (operands[0], E_DImode)
          || GET_MODE (x1) != E_DImode
          || !register_operand (operands[1], E_DImode)
          || !sle_operand (operands[2], E_DImode))
        return -1;
      return 2;

    default:
      return -1;
    }
}

static int
pattern23 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  if (!equality_operator (x3, E_VOIDmode))
    return -1;
  operands[0] = x3;
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) != ZERO_EXTRACT)
    return -1;
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) != CONST_INT)
    return -1;
  x6 = XEXP (x3, 1);
  if (x6 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
    return -1;
  x7 = XEXP (x2, 1);
  if (GET_CODE (x7) != LABEL_REF)
    return -1;
  x8 = XEXP (x2, 2);
  if (GET_CODE (x8) != PC)
    return -1;
  x9 = XEXP (x1, 0);
  if (GET_CODE (x9) != PC)
    return -1;
  return 0;
}

static int
pattern24 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[2] = x2;
  x3 = XEXP (x1, 1);
  operands[3] = x3;
  if (!const_int_operand (operands[3], E_VOIDmode))
    return -1;
  switch (GET_MODE (x1))
    {
    case E_SImode:
      if (!register_operand (operands[2], E_SImode))
        return -1;
      return 0;

    case E_DImode:
      if (!register_operand (operands[2], E_DImode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern25 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != E_SImode)
    return -1;
  x3 = XEXP (x2, 1);
  if (!subreg_lowpart_operator (x3, E_VOIDmode))
    return -1;
  operands[4] = x3;
  x4 = XEXP (x3, 0);
  if (GET_CODE (x4) != AND
      || !register_operand (operands[0], E_DImode)
      || GET_MODE (x1) != E_DImode)
    return -1;
  x5 = XEXP (x2, 0);
  operands[1] = x5;
  if (!register_operand (operands[1], E_SImode))
    return -1;
  return pattern24 (x4); /* [-1, 1] */
}

static int
pattern26 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  operands[4] = x2;
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) != AND)
    return -1;
  return pattern13 (x1); /* [-1, 3] */
}

static int
pattern27 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      if (!register_operand (operands[0], E_SImode)
          || GET_MODE (x1) != E_SImode)
        return -1;
      switch (GET_MODE (operands[1]))
        {
        case E_SImode:
          if (!register_operand (operands[1], E_SImode)
              || !arith_operand (operands[2], E_SImode))
            return -1;
          return 0;

        case E_DImode:
          if (!register_operand (operands[1], E_DImode)
              || !arith_operand (operands[2], E_DImode))
            return -1;
          return 1;

        default:
          return -1;
        }

    case E_DImode:
      if (pattern10 (x1, E_DImode) != 0)
        return -1;
      return 2;

    default:
      return -1;
    }
}

static int
pattern28 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  if (GET_CODE (x1) != CLOBBER)
    return -1;
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) != REG
      || REGNO (x2) != 1
      || GET_MODE (x2) != E_SImode)
    return -1;
  return 0;
}

static int
pattern29 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], E_HImode)
      || GET_MODE (x1) != E_HImode)
    return -1;
  switch (GET_MODE (operands[1]))
    {
    case E_HImode:
      if (!register_operand (operands[1], E_HImode)
          || !arith_operand (operands[2], E_HImode))
        return -1;
      return 0;

    case E_SImode:
      if (!register_operand (operands[1], E_SImode)
          || !arith_operand (operands[2], E_SImode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern30 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  switch (GET_MODE (operands[1]))
    {
    case E_QImode:
      if (!nonimmediate_operand (operands[1], E_QImode))
        return -1;
      return 0;

    case E_HImode:
      if (!nonimmediate_operand (operands[1], E_HImode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern31 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !reg_or_0_operand (operands[1], i1)
      || !register_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern32 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      if (!register_operand (operands[0], E_SImode)
          || GET_MODE (x1) != E_SImode
          || !symbolic_operand (operands[1], E_SImode))
        return -1;
      return 0;

    case E_DImode:
      if (!register_operand (operands[0], E_DImode)
          || GET_MODE (x1) != E_DImode
          || !symbolic_operand (operands[1], E_DImode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern33 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !register_operand (operands[1], i1)
      || !symbolic_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern34 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  switch (GET_MODE (operands[1]))
    {
    case E_SFmode:
      if (!register_operand (operands[1], E_SFmode))
        return -1;
      return 0;

    case E_DFmode:
      if (!register_operand (operands[1], E_DFmode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern35 (machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || !fp_native_comparison (operands[1], i1))
    return -1;
  switch (GET_MODE (operands[2]))
    {
    case E_SFmode:
      if (!register_operand (operands[2], E_SFmode)
          || !register_operand (operands[3], E_SFmode))
        return -1;
      return 0;

    case E_DFmode:
      if (!register_operand (operands[2], E_DFmode)
          || !register_operand (operands[3], E_DFmode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern36 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern37 (rtx x1, int *pnum_clobbers, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (pnum_clobbers == NULL
      || !register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !memory_operand (operands[1], i1)
      || !memory_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern38 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  if (!memory_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) != i1
      || !reg_or_0_operand (operands[1], i1))
    return -1;
  return 0;
}

static int
pattern39 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  x2 = XVECEXP (x1, 0, 0);
  x3 = XEXP (x2, 1);
  operands[1] = x3;
  x4 = XEXP (x2, 0);
  if (!rtx_equal_p (x4, operands[0]))
    return -1;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      return pattern38 (x1, E_SImode); /* [-1, 0] */

    case E_DImode:
      if (pattern38 (x1, E_DImode) != 0)
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern40 (rtx x1, machine_mode i1, machine_mode i2)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != i2)
    return -1;
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) != i2)
    return -1;
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) != i2
      || !register_operand (operands[1], i1))
    return -1;
  x5 = XEXP (x3, 1);
  if (GET_MODE (x5) != i2
      || !register_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern41 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  x3 = XEXP (x2, 0);
  x4 = XEXP (x3, 1);
  x5 = XEXP (x4, 0);
  operands[2] = x5;
  x6 = XEXP (x2, 1);
  switch (XWINT (x6, 0))
    {
    case 64L:
      return pattern40 (x1, E_DImode, E_TImode); /* [-1, 0] */

    case 32L:
      if (pattern40 (x1, E_SImode, E_DImode) != 0)
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern42 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1)
      || !register_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
pattern43 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1))
    return -1;
  x2 = XEXP (x1, 2);
  if (GET_MODE (x2) != i1
      || !register_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
pattern44 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3;
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1))
    return -1;
  x3 = XEXP (x1, 2);
  if (GET_MODE (x3) != i1
      || !register_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
pattern45 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1)
      || !register_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
pattern46 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1)
      || !symbolic_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
pattern47 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !symbolic_operand (operands[1], i1)
      || !const_int_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern48 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  operands[4] = x1;
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) != AND)
    return -1;
  return pattern24 (x2); /* [-1, 1] */
}

static int
pattern49 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != i1)
    return -1;
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1))
    return -1;
  x4 = XEXP (x2, 2);
  if (GET_MODE (x4) != i1
      || !register_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
pattern50 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3;
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != i1)
    return -1;
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1)
      || !register_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
pattern51 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1)
      || !register_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
pattern52 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3;
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != i1
      || !register_operand (operands[1], i1)
      || !register_operand (operands[2], i1))
    return -1;
  x3 = XEXP (x2, 2);
  if (GET_MODE (x3) != i1
      || !register_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
pattern53 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  int res ATTRIBUTE_UNUSED;
  x2 = XVECEXP (x1, 0, 0);
  x3 = XEXP (x2, 1);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  operands[1] = x5;
  if (!register_operand (operands[1], E_DImode))
    return -1;
  x6 = XEXP (x4, 1);
  operands[2] = x6;
  if (!immediate_operand (operands[2], E_QImode))
    return -1;
  x7 = XEXP (x3, 1);
  operands[3] = x7;
  if (!immediate_operand (operands[3], E_VOIDmode))
    return -1;
  x8 = XVECEXP (x1, 0, 1);
  x9 = XEXP (x8, 0);
  operands[4] = x9;
  if (!scratch_operand (operands[4], E_DImode))
    return -1;
  return 0;
}

static int
pattern54 (machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!reg_or_0_operand (operands[1], i1))
    return -1;
  switch (GET_MODE (operands[2]))
    {
    case E_SImode:
      if (!scratch_operand (operands[2], E_SImode))
        return -1;
      return 0;

    case E_DImode:
      if (!scratch_operand (operands[2], E_DImode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern55 (machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[1], i1))
    return -1;
  switch (GET_MODE (operands[2]))
    {
    case E_SImode:
      if (!scratch_operand (operands[2], E_SImode))
        return -1;
      return 0;

    case E_DImode:
      if (!scratch_operand (operands[2], E_DImode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern56 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1)
    return -1;
  switch (GET_MODE (operands[2]))
    {
    case E_SImode:
      if (!scratch_operand (operands[2], E_SImode))
        return -1;
      return 0;

    case E_DImode:
      if (!scratch_operand (operands[2], E_DImode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern57 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !scratch_operand (operands[3], i1))
    return -1;
  switch (GET_MODE (operands[1]))
    {
    case E_SFmode:
      if (!register_operand (operands[1], E_SFmode)
          || !register_operand (operands[2], E_SFmode))
        return -1;
      return 0;

    case E_DFmode:
      if (!register_operand (operands[1], E_DFmode)
          || !register_operand (operands[2], E_DFmode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern58 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !memory_operand (operands[1], i1)
      || !memory_operand (operands[2], i1)
      || !scratch_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
pattern59 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!memory_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !memory_operand (operands[1], i1)
      || !scratch_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern60 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || GET_MODE (x1) != i1
      || !memory_operand (operands[1], i1)
      || !register_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern61 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || !memory_operand (operands[1], i1)
      || GET_MODE (x1) != i1)
    return -1;
  x2 = XVECEXP (x1, 0, 0);
  if (GET_MODE (x2) != i1
      || !reg_or_0_operand (operands[2], i1))
    return -1;
  return 0;
}

static int
pattern62 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  x2 = XVECEXP (x1, 0, 0);
  x3 = XEXP (x2, 1);
  operands[2] = x3;
  x4 = XEXP (x2, 0);
  if (!rtx_equal_p (x4, operands[1]))
    return -1;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      return pattern61 (x1, E_SImode); /* [-1, 0] */

    case E_DImode:
      if (pattern61 (x1, E_DImode) != 0)
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern63 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  switch (GET_MODE (x1))
    {
    case E_SImode:
      if (!register_operand (operands[2], E_SImode)
          || !scratch_operand (operands[4], E_SImode))
        return -1;
      return 0;

    case E_DImode:
      if (!register_operand (operands[2], E_DImode)
          || !scratch_operand (operands[4], E_DImode))
        return -1;
      return 1;

    default:
      return -1;
    }
}

static int
pattern64 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 2);
  operands[3] = x2;
  if (!branch_on_bit_operand (operands[3], E_VOIDmode))
    return -1;
  return pattern63 (x1); /* [-1, 1] */
}

static int
pattern65 (rtx x1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  operands[3] = x2;
  if (!branch_on_bit_operand (operands[3], E_VOIDmode))
    return -1;
  return pattern63 (x1); /* [-1, 1] */
}

static int
pattern66 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || !memory_operand (operands[1], i1)
      || GET_MODE (x1) != i1
      || !reg_or_0_operand (operands[2], i1)
      || !reg_or_0_operand (operands[3], i1)
      || !scratch_operand (operands[6], i1))
    return -1;
  return 0;
}

static int
pattern67 (rtx x1, machine_mode i1)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  int res ATTRIBUTE_UNUSED;
  if (!register_operand (operands[0], i1)
      || !memory_operand (operands[1], i1)
      || GET_MODE (x1) != i1
      || !reg_or_0_operand (operands[2], i1)
      || !reg_or_0_operand (operands[3], i1))
    return -1;
  return 0;
}

static int
recog_1 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  if (!subreg_lowpart_operator (x3, E_SImode)
      || !register_operand (operands[0], E_DImode)
      || GET_MODE (x2) != E_DImode)
    return -1;
  x4 = XEXP (x3, 0);
  if (GET_MODE (x4) != E_DImode)
    return -1;
  switch (GET_CODE (x4))
    {
    case PLUS:
      operands[3] = x3;
      x5 = XEXP (x4, 0);
      operands[1] = x5;
      if (!register_operand (operands[1], E_DImode))
        return -1;
      x6 = XEXP (x4, 1);
      operands[2] = x6;
      if (!arith_operand (operands[2], E_DImode)
          || !
#line 486 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return -1;
      return 6; /* *addsi3_extended2 */

    case MINUS:
      operands[3] = x3;
      x5 = XEXP (x4, 0);
      operands[1] = x5;
      if (!reg_or_0_operand (operands[1], E_DImode))
        return -1;
      x6 = XEXP (x4, 1);
      operands[2] = x6;
      if (!register_operand (operands[2], E_DImode)
          || !
#line 542 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return -1;
      return 12; /* *subsi3_extended2 */

    case NEG:
      operands[2] = x3;
      x5 = XEXP (x4, 0);
      operands[1] = x5;
      if (!register_operand (operands[1], E_DImode)
          || !
#line 577 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return -1;
      return 16; /* *negsi2_extended2 */

    case MULT:
      operands[3] = x3;
      x5 = XEXP (x4, 0);
      operands[1] = x5;
      if (!register_operand (operands[1], E_DImode))
        return -1;
      x6 = XEXP (x4, 1);
      operands[2] = x6;
      if (!register_operand (operands[2], E_DImode)
          || !
#line 633 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && TARGET_64BIT))
        return -1;
      return 22; /* *mulsi3_extended2 */

    default:
      return -1;
    }
}

static int
recog_2 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  operands[1] = x3;
  switch (GET_MODE (operands[0]))
    {
    case E_DImode:
      if (nonimmediate_operand (operands[0], E_DImode)
          && move_operand (operands[1], E_DImode))
        {
          if (
#line 1332 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode))))
            return 134; /* *movdi_32bit */
          if (
#line 1342 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (register_operand (operands[0], DImode)
       || reg_or_0_operand (operands[1], DImode))))
            return 135; /* *movdi_64bit */
        }
      break;

    case E_SImode:
      if (nonimmediate_operand (operands[0], E_SImode)
          && move_operand (operands[1], E_SImode)
          && 
#line 1363 "../../gcc/config/riscv/riscv.md"
((register_operand (operands[0], SImode)
    || reg_or_0_operand (operands[1], SImode))))
        return 136; /* *movsi_internal */
      break;

    case E_HImode:
      if (nonimmediate_operand (operands[0], E_HImode)
          && move_operand (operands[1], E_HImode)
          && 
#line 1388 "../../gcc/config/riscv/riscv.md"
((register_operand (operands[0], HImode)
    || reg_or_0_operand (operands[1], HImode))))
        return 137; /* *movhi_internal */
      break;

    case E_QImode:
      if (nonimmediate_operand (operands[0], E_QImode)
          && move_operand (operands[1], E_QImode)
          && 
#line 1430 "../../gcc/config/riscv/riscv.md"
((register_operand (operands[0], QImode)
    || reg_or_0_operand (operands[1], QImode))))
        return 142; /* *movqi_internal */
      break;

    case E_SFmode:
      if (nonimmediate_operand (operands[0], E_SFmode)
          && move_operand (operands[1], E_SFmode))
        {
          if (
#line 1450 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode))))
            return 143; /* *movsf_hardfloat */
          if (
#line 1460 "../../gcc/config/riscv/riscv.md"
(!TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || reg_or_0_operand (operands[1], SFmode))))
            return 144; /* *movsf_softfloat */
        }
      break;

    case E_DFmode:
      if (nonimmediate_operand (operands[0], E_DFmode)
          && move_operand (operands[1], E_DFmode))
        {
          if (
#line 1483 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT && TARGET_DOUBLE_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode))))
            return 145; /* *movdf_hardfloat_rv32 */
          if (
#line 1493 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT && TARGET_DOUBLE_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode))))
            return 146; /* *movdf_hardfloat_rv64 */
          if (
#line 1503 "../../gcc/config/riscv/riscv.md"
(!TARGET_DOUBLE_FLOAT
   && (register_operand (operands[0], DFmode)
       || reg_or_0_operand (operands[1], DFmode))))
            return 147; /* *movdf_softfloat */
        }
      break;

    default:
      break;
    }
  if (pnum_clobbers == NULL
      || GET_CODE (x2) != MEM)
    return -1;
  x4 = XEXP (x2, 0);
  operands[0] = x4;
  if (!absolute_symbolic_operand (operands[0], E_VOIDmode))
    return -1;
  operands[1] = x3;
  switch (GET_MODE (x2))
    {
    case E_QImode:
      if (!reg_or_0_operand (operands[1], E_QImode))
        return -1;
      if ((
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
        {
          *pnum_clobbers = 1;
          return 326; /* *local_pic_storeqi */
        }
      if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
        return -1;
      *pnum_clobbers = 1;
      return 330; /* *local_pic_storeqi */

    case E_HImode:
      if (!reg_or_0_operand (operands[1], E_HImode))
        return -1;
      if ((
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
        {
          *pnum_clobbers = 1;
          return 327; /* *local_pic_storehi */
        }
      if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
        return -1;
      *pnum_clobbers = 1;
      return 331; /* *local_pic_storehi */

    case E_SImode:
      if (!reg_or_0_operand (operands[1], E_SImode))
        return -1;
      if ((
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
        {
          *pnum_clobbers = 1;
          return 328; /* *local_pic_storesi */
        }
      if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
        return -1;
      *pnum_clobbers = 1;
      return 332; /* *local_pic_storesi */

    case E_DImode:
      if (!reg_or_0_operand (operands[1], E_DImode))
        return -1;
      if ((
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 296 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
        {
          *pnum_clobbers = 1;
          return 329; /* *local_pic_storedi */
        }
      if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 296 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
        return -1;
      *pnum_clobbers = 1;
      return 333; /* *local_pic_storedi */

    case E_SFmode:
      if (!register_operand (operands[1], E_SFmode))
        return -1;
      if ((
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
        {
          *pnum_clobbers = 1;
          return 334; /* *local_pic_storesf */
        }
      if ((
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
        {
          *pnum_clobbers = 1;
          return 336; /* *local_pic_storesf */
        }
      if ((
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
        {
          *pnum_clobbers = 1;
          return 342; /* *local_pic_store_sfsf */
        }
      if (!(
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
        return -1;
      *pnum_clobbers = 1;
      return 344; /* *local_pic_store_sfsf */

    case E_DFmode:
      if (!register_operand (operands[1], E_DFmode))
        return -1;
      if ((
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
        {
          *pnum_clobbers = 1;
          return 335; /* *local_pic_storedf */
        }
      if ((
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
        {
          *pnum_clobbers = 1;
          return 337; /* *local_pic_storedf */
        }
      if ((
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
        {
          *pnum_clobbers = 1;
          return 343; /* *local_pic_store_sfdf */
        }
      if (!(
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
        return -1;
      *pnum_clobbers = 1;
      return 345; /* *local_pic_store_sfdf */

    default:
      return -1;
    }
}

static int
recog_3 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      x4 = XEXP (x2, 2);
      if (GET_CODE (x4) != PC)
        return -1;
      x5 = XEXP (x1, 0);
      if (GET_CODE (x5) != PC)
        return -1;
      x6 = XEXP (x2, 0);
      operands[1] = x6;
      x7 = XEXP (x6, 0);
      operands[2] = x7;
      x8 = XEXP (x6, 1);
      operands[3] = x8;
      x9 = XEXP (x3, 0);
      operands[0] = x9;
      switch (GET_MODE (operands[2]))
        {
        case E_SImode:
          if (!register_operand (operands[2], E_SImode)
              || !reg_or_0_operand (operands[3], E_SImode)
              || !
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return -1;
          return 181; /* *branchsi */

        case E_DImode:
          if (!register_operand (operands[2], E_DImode)
              || !reg_or_0_operand (operands[3], E_DImode)
              || !
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 182; /* *branchdi */

        default:
          return -1;
        }

    case REG:
    case SUBREG:
      operands[3] = x3;
      x5 = XEXP (x1, 0);
      operands[0] = x5;
      x6 = XEXP (x2, 0);
      operands[5] = x6;
      x7 = XEXP (x6, 0);
      operands[1] = x7;
      x8 = XEXP (x6, 1);
      operands[2] = x8;
      x4 = XEXP (x2, 2);
      operands[4] = x4;
      switch (GET_MODE (operands[0]))
        {
        case E_SImode:
          if (!register_operand (operands[0], E_SImode)
              || GET_MODE (x2) != E_SImode
              || !register_operand (operands[3], E_SImode)
              || !sfb_alu_operand (operands[4], E_SImode))
            return -1;
          switch (GET_MODE (operands[1]))
            {
            case E_SImode:
              if (!register_operand (operands[1], E_SImode)
                  || !reg_or_0_operand (operands[2], E_SImode)
                  || !(
#line 1896 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
                return -1;
              return 183; /* *movsisicc */

            case E_DImode:
              if (!register_operand (operands[1], E_DImode)
                  || !reg_or_0_operand (operands[2], E_DImode)
                  || !(
#line 1896 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 184; /* *movsidicc */

            default:
              return -1;
            }

        case E_DImode:
          if (!register_operand (operands[0], E_DImode)
              || GET_MODE (x2) != E_DImode
              || !register_operand (operands[1], E_DImode)
              || !reg_or_0_operand (operands[2], E_DImode)
              || !register_operand (operands[3], E_DImode)
              || !sfb_alu_operand (operands[4], E_DImode)
              || !(
#line 1896 "../../gcc/config/riscv/riscv.md"
(TARGET_SFB_ALU) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
            return -1;
          return 185; /* *movdidicc */

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_4 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XEXP (x3, 0);
  switch (GET_CODE (x4))
    {
    case PLUS:
      if (pattern15 (x3, E_SImode) != 0
          || !arith_operand (operands[2], E_SImode)
          || !
#line 475 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return -1;
      return 5; /* *addsi3_extended */

    case REG:
    case SUBREG:
    case MEM:
    case TRUNCATE:
      switch (GET_CODE (x4))
        {
        case SUBREG:
        case TRUNCATE:
          res = recog_1 (x1, insn, pnum_clobbers);
          if (res >= 0)
            return res;
          break;

        case MEM:
          if (GET_MODE (x4) == E_SImode)
            {
              x5 = XEXP (x4, 0);
              operands[1] = x5;
              if (absolute_symbolic_operand (operands[1], E_VOIDmode))
                {
                  switch (GET_MODE (operands[0]))
                    {
                    case E_HImode:
                      if (register_operand (operands[0], E_HImode)
                          && GET_MODE (x3) == E_HImode
                          && (
#line 35 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 293 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                        return 304; /* *local_pic_load_ssi */
                      break;

                    case E_SImode:
                      if (register_operand (operands[0], E_SImode)
                          && GET_MODE (x3) == E_SImode
                          && (
#line 35 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 293 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                        return 305; /* *local_pic_load_ssi */
                      break;

                    default:
                      break;
                    }
                }
            }
          break;

        default:
          break;
        }
      operands[1] = x4;
      switch (GET_MODE (operands[0]))
        {
        case E_DImode:
          if (register_operand (operands[0], E_DImode)
              && GET_MODE (x3) == E_DImode)
            {
              switch (GET_MODE (operands[1]))
                {
                case E_SImode:
                  if (nonimmediate_operand (operands[1], E_SImode)
                      && 
#line 1123 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                    return 90; /* extendsidi2 */
                  break;

                case E_QImode:
                  if (nonimmediate_operand (operands[1], E_QImode)
                      && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                    return 93; /* extendqidi2 */
                  break;

                case E_HImode:
                  if (nonimmediate_operand (operands[1], E_HImode)
                      && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                    return 96; /* extendhidi2 */
                  break;

                default:
                  break;
                }
            }
          break;

        case E_HImode:
          switch (pattern30 (x3, E_HImode))
            {
            case 0:
              return 91; /* extendqihi2 */

            case 1:
              return 94; /* extendhihi2 */

            default:
              break;
            }
          break;

        case E_SImode:
          switch (pattern30 (x3, E_SImode))
            {
            case 0:
              return 92; /* extendqisi2 */

            case 1:
              return 95; /* extendhisi2 */

            default:
              break;
            }
          break;

        default:
          break;
        }
      if (GET_CODE (x4) != MEM)
        return -1;
      x5 = XEXP (x4, 0);
      operands[1] = x5;
      if (!absolute_symbolic_operand (operands[1], E_VOIDmode))
        return -1;
      switch (GET_MODE (operands[0]))
        {
        case E_HImode:
          if (!register_operand (operands[0], E_HImode)
              || GET_MODE (x3) != E_HImode)
            return -1;
          switch (GET_MODE (x4))
            {
            case E_QImode:
              if (!
#line 35 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
                return -1;
              return 298; /* *local_pic_load_sqi */

            case E_HImode:
              if (!
#line 35 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
                return -1;
              return 301; /* *local_pic_load_shi */

            default:
              return -1;
            }

        case E_SImode:
          if (!register_operand (operands[0], E_SImode)
              || GET_MODE (x3) != E_SImode)
            return -1;
          switch (GET_MODE (x4))
            {
            case E_QImode:
              if (!
#line 35 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
                return -1;
              return 299; /* *local_pic_load_sqi */

            case E_HImode:
              if (!
#line 35 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
                return -1;
              return 302; /* *local_pic_load_shi */

            default:
              return -1;
            }

        case E_DImode:
          if (!register_operand (operands[0], E_DImode)
              || GET_MODE (x3) != E_DImode)
            return -1;
          switch (GET_MODE (x4))
            {
            case E_QImode:
              if (!(
#line 35 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 300; /* *local_pic_load_sqi */

            case E_HImode:
              if (!(
#line 35 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 303; /* *local_pic_load_shi */

            case E_SImode:
              if (!(
#line 35 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 306; /* *local_pic_load_ssi */

            default:
              return -1;
            }

        default:
          return -1;
        }

    case MINUS:
      if (GET_MODE (x4) != E_SImode
          || !register_operand (operands[0], E_DImode)
          || GET_MODE (x3) != E_DImode)
        return -1;
      x5 = XEXP (x4, 0);
      operands[1] = x5;
      if (!reg_or_0_operand (operands[1], E_SImode))
        return -1;
      x6 = XEXP (x4, 1);
      operands[2] = x6;
      if (!register_operand (operands[2], E_SImode)
          || !
#line 531 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return -1;
      return 11; /* *subsi3_extended */

    case NEG:
      if (pattern16 (x3) != 0
          || !
#line 567 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return -1;
      return 15; /* *negsi2_extended */

    case MULT:
      if (pattern17 (x3) != 0
          || !
#line 622 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && TARGET_64BIT))
        return -1;
      return 21; /* *mulsi3_extended */

    case DIV:
      if (pattern17 (x3) != 0
          || !
#line 801 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV && TARGET_64BIT))
        return -1;
      return 37; /* *divsi3_extended */

    case UDIV:
      if (pattern17 (x3) != 0
          || !
#line 801 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV && TARGET_64BIT))
        return -1;
      return 38; /* *udivsi3_extended */

    case MOD:
      if (pattern17 (x3) != 0
          || !
#line 801 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV && TARGET_64BIT))
        return -1;
      return 39; /* *modsi3_extended */

    case UMOD:
      if (pattern17 (x3) != 0
          || !
#line 801 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV && TARGET_64BIT))
        return -1;
      return 40; /* *umodsi3_extended */

    case ASHIFT:
      if (pattern16 (x3) != 0)
        return -1;
      x6 = XEXP (x4, 1);
      operands[2] = x6;
      if (arith_operand (operands[2], E_QImode)
          && 
#line 1690 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return 168; /* *ashlsi3_extend */
      if (!subreg_lowpart_operator (x6, E_VOIDmode))
        return -1;
      switch (pattern48 (x6))
        {
        case 0:
          if (!
#line 1709 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 171; /* *ashlsi3_extend_mask */

        case 1:
          if (!
#line 1731 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 174; /* *ashlsi3_extend_mask_1 */

        default:
          return -1;
        }

    case ASHIFTRT:
      if (pattern16 (x3) != 0)
        return -1;
      x6 = XEXP (x4, 1);
      operands[2] = x6;
      if (arith_operand (operands[2], E_QImode)
          && 
#line 1690 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return 169; /* *ashrsi3_extend */
      if (!subreg_lowpart_operator (x6, E_VOIDmode))
        return -1;
      switch (pattern48 (x6))
        {
        case 0:
          if (!
#line 1709 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 172; /* *ashrsi3_extend_mask */

        case 1:
          if (!
#line 1731 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 175; /* *ashrsi3_extend_mask_1 */

        default:
          return -1;
        }

    case LSHIFTRT:
      if (pattern16 (x3) != 0)
        return -1;
      x6 = XEXP (x4, 1);
      operands[2] = x6;
      if (arith_operand (operands[2], E_QImode)
          && 
#line 1690 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return 170; /* *lshrsi3_extend */
      if (!subreg_lowpart_operator (x6, E_VOIDmode))
        return -1;
      switch (pattern48 (x6))
        {
        case 0:
          if (!
#line 1709 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 173; /* *lshrsi3_extend_mask */

        case 1:
          if (!
#line 1731 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 176; /* *lshrsi3_extend_mask_1 */

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_5 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  switch (XVECLEN (x2, 0))
    {
    case 2:
      switch (XINT (x2, 1))
        {
        case 11:
          x3 = XEXP (x1, 0);
          operands[0] = x3;
          x4 = XVECEXP (x2, 0, 0);
          operands[1] = x4;
          x5 = XVECEXP (x2, 0, 1);
          operands[2] = x5;
          switch (GET_MODE (operands[0]))
            {
            case E_SFmode:
              if (pattern36 (x2, E_SFmode) != 0
                  || !
#line 952 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
                return -1;
              return 63; /* copysignsf3 */

            case E_DFmode:
              if (pattern36 (x2, E_DFmode) != 0
                  || !(
#line 952 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                return -1;
              return 64; /* copysigndf3 */

            case E_SImode:
              if (pattern37 (x2, pnum_clobbers, E_SImode) != 0)
                return -1;
              *pnum_clobbers = 1;
              return 269; /* stack_protect_test_si */

            case E_DImode:
              if (pattern37 (x2, pnum_clobbers, E_DImode) != 0
                  || !
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return -1;
              *pnum_clobbers = 1;
              return 270; /* stack_protect_test_di */

            default:
              return -1;
            }

        case 9:
          switch (pattern19 (x1, pnum_clobbers))
            {
            case 0:
              if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                {
                  *pnum_clobbers = 1;
                  return 194; /* *flt_quietsfsi4_default */
                }
              if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                return -1;
              *pnum_clobbers = 1;
              return 202; /* *flt_quietsfsi4_snan */

            case 1:
              if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                {
                  *pnum_clobbers = 1;
                  return 198; /* *flt_quietdfsi4_default */
                }
              if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                return -1;
              *pnum_clobbers = 1;
              return 206; /* *flt_quietdfsi4_snan */

            case 2:
              if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                {
                  *pnum_clobbers = 1;
                  return 196; /* *flt_quietsfdi4_default */
                }
              if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                return -1;
              *pnum_clobbers = 1;
              return 204; /* *flt_quietsfdi4_snan */

            case 3:
              if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                {
                  *pnum_clobbers = 1;
                  return 200; /* *flt_quietdfdi4_default */
                }
              if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                return -1;
              *pnum_clobbers = 1;
              return 208; /* *flt_quietdfdi4_snan */

            default:
              return -1;
            }

        case 10:
          switch (pattern19 (x1, pnum_clobbers))
            {
            case 0:
              if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                {
                  *pnum_clobbers = 1;
                  return 195; /* *fle_quietsfsi4_default */
                }
              if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                return -1;
              *pnum_clobbers = 1;
              return 203; /* *fle_quietsfsi4_snan */

            case 1:
              if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                {
                  *pnum_clobbers = 1;
                  return 199; /* *fle_quietdfsi4_default */
                }
              if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                return -1;
              *pnum_clobbers = 1;
              return 207; /* *fle_quietdfsi4_snan */

            case 2:
              if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                {
                  *pnum_clobbers = 1;
                  return 197; /* *fle_quietsfdi4_default */
                }
              if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                return -1;
              *pnum_clobbers = 1;
              return 205; /* *fle_quietsfdi4_snan */

            case 3:
              if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                {
                  *pnum_clobbers = 1;
                  return 201; /* *fle_quietdfdi4_default */
                }
              if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                return -1;
              *pnum_clobbers = 1;
              return 209; /* *fle_quietdfdi4_snan */

            default:
              return -1;
            }

        case 14:
          if (GET_MODE (x2) != E_BLKmode)
            return -1;
          x3 = XEXP (x1, 0);
          if (GET_CODE (x3) != MEM
              || GET_MODE (x3) != E_BLKmode)
            return -1;
          x6 = XEXP (x3, 0);
          if (GET_CODE (x6) != SCRATCH)
            return -1;
          x4 = XVECEXP (x2, 0, 0);
          operands[0] = x4;
          x5 = XVECEXP (x2, 0, 1);
          operands[1] = x5;
          switch (GET_MODE (operands[0]))
            {
            case E_SImode:
              if (!register_operand (operands[0], E_SImode)
                  || !register_operand (operands[1], E_SImode)
                  || !
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
                return -1;
              return 265; /* stack_tiesi */

            case E_DImode:
              if (!register_operand (operands[0], E_DImode)
                  || !register_operand (operands[1], E_DImode)
                  || !
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return -1;
              return 266; /* stack_tiedi */

            default:
              return -1;
            }

        default:
          return -1;
        }

    case 1:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XVECEXP (x2, 0, 0);
      operands[1] = x4;
      switch (XINT (x2, 1))
        {
        case 12:
          switch (GET_MODE (operands[0]))
            {
            case E_SImode:
              switch (pattern34 (x2, E_SImode))
                {
                case 0:
                  if (!
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
                    return -1;
                  return 114; /* lrintsfsi2 */

                case 1:
                  if (!(
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                    return -1;
                  return 118; /* lrintdfsi2 */

                default:
                  return -1;
                }

            case E_DImode:
              switch (pattern34 (x2, E_DImode))
                {
                case 0:
                  if (!(
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))))
                    return -1;
                  return 116; /* lrintsfdi2 */

                case 1:
                  if (!(
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))))
                    return -1;
                  return 120; /* lrintdfdi2 */

                default:
                  return -1;
                }

            default:
              return -1;
            }

        case 13:
          switch (GET_MODE (operands[0]))
            {
            case E_SImode:
              switch (pattern34 (x2, E_SImode))
                {
                case 0:
                  if (!
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
                    return -1;
                  return 115; /* lroundsfsi2 */

                case 1:
                  if (!(
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                    return -1;
                  return 119; /* lrounddfsi2 */

                default:
                  return -1;
                }

            case E_DImode:
              switch (pattern34 (x2, E_DImode))
                {
                case 0:
                  if (!(
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))))
                    return -1;
                  return 117; /* lroundsfdi2 */

                case 1:
                  if (!(
#line 1209 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))))
                    return -1;
                  return 121; /* lrounddfdi2 */

                default:
                  return -1;
                }

            default:
              return -1;
            }

        case 3:
          switch (pattern32 (x2))
            {
            case 0:
              if (!
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
                return -1;
              return 122; /* got_loadsi */

            case 1:
              if (!
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
                return -1;
              return 123; /* got_loaddi */

            default:
              return -1;
            }

        case 7:
          switch (pattern32 (x2))
            {
            case 0:
              if (!
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
                return -1;
              return 126; /* got_load_tls_gdsi */

            case 1:
              if (!
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
                return -1;
              return 127; /* got_load_tls_gddi */

            default:
              return -1;
            }

        case 6:
          switch (pattern32 (x2))
            {
            case 0:
              if (!
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
                return -1;
              return 128; /* got_load_tls_iesi */

            case 1:
              if (!
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
                return -1;
              return 129; /* got_load_tls_iedi */

            default:
              return -1;
            }

        default:
          return -1;
        }

    case 3:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XVECEXP (x2, 0, 0);
      operands[1] = x4;
      x5 = XVECEXP (x2, 0, 1);
      operands[2] = x5;
      switch (XINT (x2, 1))
        {
        case 5:
          x7 = XVECEXP (x2, 0, 2);
          operands[3] = x7;
          switch (GET_MODE (operands[0]))
            {
            case E_SImode:
              if (pattern46 (x2, E_SImode) != 0
                  || !
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
                return -1;
              return 124; /* tls_add_tp_lesi */

            case E_DImode:
              if (pattern46 (x2, E_DImode) != 0
                  || !
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
                return -1;
              return 125; /* tls_add_tp_ledi */

            default:
              return -1;
            }

        case 8:
          x7 = XVECEXP (x2, 0, 2);
          if (GET_CODE (x7) != PC)
            return -1;
          switch (GET_MODE (operands[0]))
            {
            case E_SImode:
              if (pattern47 (x2, E_SImode) != 0
                  || !
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
                return -1;
              return 130; /* auipcsi */

            case E_DImode:
              if (pattern47 (x2, E_DImode) != 0
                  || !
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
                return -1;
              return 131; /* auipcdi */

            default:
              return -1;
            }

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_6 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  switch (GET_CODE (x2))
    {
    case REG:
    case SUBREG:
    case MEM:
      res = recog_2 (x1, insn, pnum_clobbers);
      if (res >= 0)
        return res;
      break;

    case PC:
      x3 = XEXP (x1, 1);
      operands[0] = x3;
      switch (GET_MODE (operands[0]))
        {
        case E_SImode:
          if (register_operand (operands[0], E_SImode)
              && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
            return 241; /* indirect_jumpsi */
          break;

        case E_DImode:
          if (register_operand (operands[0], E_DImode)
              && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
            return 242; /* indirect_jumpdi */
          break;

        default:
          break;
        }
      break;

    default:
      break;
    }
  x3 = XEXP (x1, 1);
  switch (GET_CODE (x3))
    {
    case LABEL_REF:
      if (GET_CODE (x2) != PC)
        return -1;
      x4 = XEXP (x3, 0);
      operands[0] = x4;
      return 240; /* jump */

    case MEM:
      operands[0] = x2;
      x4 = XEXP (x3, 0);
      operands[1] = x4;
      if (!absolute_symbolic_operand (operands[1], E_VOIDmode))
        return -1;
      switch (GET_MODE (operands[0]))
        {
        case E_QImode:
          if (!register_operand (operands[0], E_QImode)
              || GET_MODE (x3) != E_QImode
              || !
#line 28 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
            return -1;
          return 294; /* *local_pic_loadqi */

        case E_HImode:
          if (!register_operand (operands[0], E_HImode)
              || GET_MODE (x3) != E_HImode
              || !
#line 28 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
            return -1;
          return 295; /* *local_pic_loadhi */

        case E_SImode:
          if (!register_operand (operands[0], E_SImode)
              || GET_MODE (x3) != E_SImode
              || !
#line 28 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
            return -1;
          return 296; /* *local_pic_loadsi */

        case E_DImode:
          if (!register_operand (operands[0], E_DImode)
              || GET_MODE (x3) != E_DImode
              || !(
#line 28 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 296 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
            return -1;
          return 297; /* *local_pic_loaddi */

        case E_SFmode:
          if (!register_operand (operands[0], E_SFmode)
              || GET_MODE (x3) != E_SFmode)
            return -1;
          if (pnum_clobbers != NULL)
            {
              if ((
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
                {
                  *pnum_clobbers = 1;
                  return 316; /* *local_pic_loadsf */
                }
              if ((
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
                {
                  *pnum_clobbers = 1;
                  return 318; /* *local_pic_loadsf */
                }
              if ((
#line 68 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
                {
                  *pnum_clobbers = 1;
                  return 320; /* *local_pic_load_32dsf */
                }
              if ((
#line 68 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
                {
                  *pnum_clobbers = 1;
                  return 322; /* *local_pic_load_32dsf */
                }
            }
          if (
#line 76 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])))
            return 324; /* *local_pic_load_sfsf */
          if (pnum_clobbers == NULL)
            return -1;
          if ((
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
            {
              *pnum_clobbers = 1;
              return 338; /* *local_pic_store_32dsf */
            }
          if (!(
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
            return -1;
          *pnum_clobbers = 1;
          return 340; /* *local_pic_store_32dsf */

        case E_DFmode:
          if (!register_operand (operands[0], E_DFmode)
              || GET_MODE (x3) != E_DFmode)
            return -1;
          if (pnum_clobbers != NULL)
            {
              if ((
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
                {
                  *pnum_clobbers = 1;
                  return 317; /* *local_pic_loaddf */
                }
              if ((
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
                {
                  *pnum_clobbers = 1;
                  return 319; /* *local_pic_loaddf */
                }
              if ((
#line 68 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
                {
                  *pnum_clobbers = 1;
                  return 321; /* *local_pic_load_32ddf */
                }
              if ((
#line 68 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
                {
                  *pnum_clobbers = 1;
                  return 323; /* *local_pic_load_32ddf */
                }
            }
          if ((
#line 76 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
            return 325; /* *local_pic_load_sfdf */
          if (pnum_clobbers == NULL)
            return -1;
          if ((
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
            {
              *pnum_clobbers = 1;
              return 339; /* *local_pic_store_32ddf */
            }
          if (!(
#line 110 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
            return -1;
          *pnum_clobbers = 1;
          return 341; /* *local_pic_store_32ddf */

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_7 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XEXP (x3, 0);
  switch (GET_CODE (x4))
    {
    case REG:
    case SUBREG:
    case MEM:
      operands[1] = x4;
      switch (GET_MODE (operands[0]))
        {
        case E_DImode:
          if (register_operand (operands[0], E_DImode)
              && GET_MODE (x3) == E_DImode)
            {
              switch (GET_MODE (operands[1]))
                {
                case E_SImode:
                  if (nonimmediate_operand (operands[1], E_SImode)
                      && 
#line 1064 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                    return 84; /* zero_extendsidi2 */
                  break;

                case E_HImode:
                  if (nonimmediate_operand (operands[1], E_HImode)
                      && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                    return 86; /* zero_extendhidi2 */
                  break;

                case E_QImode:
                  if (nonimmediate_operand (operands[1], E_QImode)
                      && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                    return 89; /* zero_extendqidi2 */
                  break;

                default:
                  break;
                }
            }
          break;

        case E_SImode:
          if (register_operand (operands[0], E_SImode)
              && GET_MODE (x3) == E_SImode)
            {
              switch (GET_MODE (operands[1]))
                {
                case E_HImode:
                  if (nonimmediate_operand (operands[1], E_HImode))
                    return 85; /* zero_extendhisi2 */
                  break;

                case E_QImode:
                  if (nonimmediate_operand (operands[1], E_QImode))
                    return 88; /* zero_extendqisi2 */
                  break;

                default:
                  break;
                }
            }
          break;

        case E_HImode:
          if (register_operand (operands[0], E_HImode)
              && GET_MODE (x3) == E_HImode
              && nonimmediate_operand (operands[1], E_QImode))
            return 87; /* zero_extendqihi2 */
          break;

        default:
          break;
        }
      if (GET_CODE (x4) != MEM)
        return -1;
      x5 = XEXP (x4, 0);
      operands[1] = x5;
      if (!absolute_symbolic_operand (operands[1], E_VOIDmode))
        return -1;
      switch (GET_MODE (operands[0]))
        {
        case E_HImode:
          if (!register_operand (operands[0], E_HImode)
              || GET_MODE (x3) != E_HImode)
            return -1;
          switch (GET_MODE (x4))
            {
            case E_QImode:
              if (!
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
                return -1;
              return 307; /* *local_pic_load_uqi */

            case E_HImode:
              if (!
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
                return -1;
              return 310; /* *local_pic_load_uhi */

            case E_SImode:
              if (!(
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 293 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 313; /* *local_pic_load_usi */

            default:
              return -1;
            }

        case E_SImode:
          if (!register_operand (operands[0], E_SImode)
              || GET_MODE (x3) != E_SImode)
            return -1;
          switch (GET_MODE (x4))
            {
            case E_QImode:
              if (!
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
                return -1;
              return 308; /* *local_pic_load_uqi */

            case E_HImode:
              if (!
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])))
                return -1;
              return 311; /* *local_pic_load_uhi */

            case E_SImode:
              if (!(
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 293 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 314; /* *local_pic_load_usi */

            default:
              return -1;
            }

        case E_DImode:
          if (!register_operand (operands[0], E_DImode)
              || GET_MODE (x3) != E_DImode)
            return -1;
          switch (GET_MODE (x4))
            {
            case E_QImode:
              if (!(
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 309; /* *local_pic_load_uqi */

            case E_HImode:
              if (!(
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 312; /* *local_pic_load_uhi */

            case E_SImode:
              if (!(
#line 42 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[1])) && 
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 315; /* *local_pic_load_usi */

            default:
              return -1;
            }

        default:
          return -1;
        }

    case LSHIFTRT:
      if (pattern15 (x3, E_SImode) != 0
          || !const_int_operand (operands[2], E_VOIDmode)
          || !
#line 1751 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT && (INTVAL (operands[2]) & 0x1f) > 0))
        return -1;
      return 177; /* *lshrsi3_zero_extend_1 */

    default:
      return -1;
    }
}

static int
recog_8 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XEXP (x3, 0);
  switch (GET_CODE (x4))
    {
    case REG:
    case SUBREG:
      operands[1] = x4;
      switch (GET_MODE (operands[0]))
        {
        case E_DImode:
          if (!register_operand (operands[0], E_DImode)
              || GET_MODE (x3) != E_DImode
              || !register_operand (operands[1], E_DImode)
              || !
#line 550 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 13; /* negdi2 */

        case E_SImode:
          if (!register_operand (operands[0], E_SImode)
              || GET_MODE (x3) != E_SImode
              || !register_operand (operands[1], E_SImode))
            return -1;
          return 14; /* negsi2 */

        case E_SFmode:
          if (!register_operand (operands[0], E_SFmode)
              || GET_MODE (x3) != E_SFmode
              || !register_operand (operands[1], E_SFmode)
              || !
#line 960 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return -1;
          return 65; /* negsf2 */

        case E_DFmode:
          if (!register_operand (operands[0], E_DFmode)
              || GET_MODE (x3) != E_DFmode
              || !register_operand (operands[1], E_DFmode)
              || !(
#line 960 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 66; /* negdf2 */

        default:
          return -1;
        }

    case FMA:
      x5 = XEXP (x4, 1);
      operands[2] = x5;
      x6 = XEXP (x4, 0);
      switch (GET_CODE (x6))
        {
        case NEG:
          x7 = XEXP (x6, 0);
          operands[1] = x7;
          x8 = XEXP (x4, 2);
          switch (GET_CODE (x8))
            {
            case NEG:
              x9 = XEXP (x8, 0);
              operands[3] = x9;
              switch (GET_MODE (operands[0]))
                {
                case E_SFmode:
                  if (pattern49 (x3, E_SFmode) != 0
                      || !(
#line 888 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
                    return -1;
                  return 53; /* *fmasf4 */

                case E_DFmode:
                  if (pattern49 (x3, E_DFmode) != 0
                      || !(
#line 888 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                    return -1;
                  return 54; /* *fmadf4 */

                default:
                  return -1;
                }

            case REG:
            case SUBREG:
              operands[3] = x8;
              switch (GET_MODE (operands[0]))
                {
                case E_SFmode:
                  if (pattern50 (x3, E_SFmode) != 0
                      || !(
#line 901 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
                    return -1;
                  return 55; /* *fmssf4 */

                case E_DFmode:
                  if (pattern50 (x3, E_DFmode) != 0
                      || !(
#line 901 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                    return -1;
                  return 56; /* *fmsdf4 */

                default:
                  return -1;
                }

            default:
              return -1;
            }

        case REG:
        case SUBREG:
          operands[1] = x6;
          x8 = XEXP (x4, 2);
          switch (GET_CODE (x8))
            {
            case REG:
            case SUBREG:
              operands[3] = x8;
              switch (GET_MODE (operands[0]))
                {
                case E_SFmode:
                  if (pattern51 (x3, E_SFmode) != 0
                      || !(
#line 914 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
                    return -1;
                  return 57; /* *fnmssf4 */

                case E_DFmode:
                  if (pattern51 (x3, E_DFmode) != 0
                      || !(
#line 914 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                    return -1;
                  return 58; /* *fnmsdf4 */

                default:
                  return -1;
                }

            case NEG:
              x9 = XEXP (x8, 0);
              operands[3] = x9;
              switch (GET_MODE (operands[0]))
                {
                case E_SFmode:
                  if (pattern52 (x3, E_SFmode) != 0
                      || !(
#line 927 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (SFmode)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
                    return -1;
                  return 59; /* *fnmasf4 */

                case E_DFmode:
                  if (pattern52 (x3, E_DFmode) != 0
                      || !(
#line 927 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && !HONOR_SIGNED_ZEROS (DFmode)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                    return -1;
                  return 60; /* *fnmadf4 */

                default:
                  return -1;
                }

            default:
              return -1;
            }

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_9 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XEXP (x3, 0);
  operands[1] = x4;
  switch (GET_CODE (x3))
    {
    case LT:
      if (GET_MODE (x3) == E_DImode)
        {
          x5 = XEXP (x3, 1);
          if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + 0]
              && register_operand (operands[0], E_DImode)
              && register_operand (operands[1], E_SImode)
              && 
#line 1780 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return 179; /* *lshrsi3_zero_extend_3 */
        }
      x5 = XEXP (x3, 1);
      operands[2] = x5;
      switch (pattern27 (x3))
        {
        case 0:
          if (
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return 228; /* *slt_sisi */
          break;

        case 1:
          if (
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return 230; /* *slt_disi */
          break;

        case 2:
          if (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return 232; /* *slt_didi */
          break;

        default:
          break;
        }
      break;

    case EQ:
      x5 = XEXP (x3, 1);
      if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + 0])
        {
          switch (pattern8 (x3))
            {
            case 0:
              if (
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
                return 210; /* *seq_zero_sisi */
              break;

            case 1:
              if (
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return 211; /* *seq_zero_disi */
              break;

            case 2:
              if (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return 212; /* *seq_zero_didi */
              break;

            default:
              break;
            }
        }
      break;

    case GT:
      switch (pattern21 (x3))
        {
        case 0:
          if (
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return 216; /* *sgt_sisi */
          break;

        case 1:
          if (
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return 218; /* *sgt_disi */
          break;

        case 2:
          if (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return 220; /* *sgt_didi */
          break;

        default:
          break;
        }
      break;

    case GE:
      x5 = XEXP (x3, 1);
      if (x5 == const_int_rtx[MAX_SAVED_CONST_INT + 1])
        {
          switch (pattern8 (x3))
            {
            case 0:
              if (
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
                return 222; /* *sge_sisi */
              break;

            case 1:
              if (
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return 224; /* *sge_disi */
              break;

            case 2:
              if (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return 226; /* *sge_didi */
              break;

            default:
              break;
            }
        }
      break;

    case LE:
      switch (pattern22 (x3))
        {
        case 0:
          if (
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return 234; /* *sle_sisi */
          break;

        case 1:
          if (
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return 236; /* *sle_disi */
          break;

        case 2:
          if (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return 238; /* *sle_didi */
          break;

        default:
          break;
        }
      break;

    default:
      break;
    }
  operands[1] = x3;
  operands[2] = x4;
  x5 = XEXP (x3, 1);
  operands[3] = x5;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      switch (pattern35 (E_SImode))
        {
        case 0:
          if (!(
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))))
            return -1;
          return 190; /* *cstoresfsi4 */

        case 1:
          if (!(
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))))
            return -1;
          return 192; /* *cstoredfsi4 */

        default:
          return -1;
        }

    case E_DImode:
      switch (pattern35 (E_DImode))
        {
        case 0:
          if (!(
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))))
            return -1;
          return 191; /* *cstoresfdi4 */

        case 1:
          if (!(
#line 2033 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && ((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))))
            return -1;
          return 193; /* *cstoredfdi4 */

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_10 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  switch (XVECLEN (x3, 0))
    {
    case 1:
      if (XINT (x3, 1) != 2)
        return -1;
      x4 = XVECEXP (x3, 0, 0);
      if (x4 != const_int_rtx[MAX_SAVED_CONST_INT + 0]
          || !register_operand (operands[0], E_SImode)
          || !
#line 2471 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
        return -1;
      return 260; /* riscv_frflags */

    case 2:
      x5 = XVECEXP (x3, 0, 1);
      operands[2] = x5;
      if (!const_int_operand (operands[2], E_SImode))
        return -1;
      switch (XINT (x3, 1))
        {
        case 18:
          x4 = XVECEXP (x3, 0, 0);
          operands[1] = x4;
          switch (GET_MODE (operands[0]))
            {
            case E_SImode:
              if (!memory_operand (operands[0], E_SImode)
                  || GET_MODE (x3) != E_SImode
                  || !reg_or_0_operand (operands[1], E_SImode)
                  || !
#line 67 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
                return -1;
              return 272; /* atomic_storesi */

            case E_DImode:
              if (!memory_operand (operands[0], E_DImode)
                  || GET_MODE (x3) != E_DImode
                  || !reg_or_0_operand (operands[1], E_DImode)
                  || !(
#line 67 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 273; /* atomic_storedi */

            default:
              return -1;
            }

        case 16:
          x4 = XVECEXP (x3, 0, 0);
          switch (GET_CODE (x4))
            {
            case PLUS:
              switch (pattern39 (x3))
                {
                case 0:
                  if (!
#line 78 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
                    return -1;
                  return 274; /* atomic_addsi */

                case 1:
                  if (!(
#line 78 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                    return -1;
                  return 278; /* atomic_adddi */

                default:
                  return -1;
                }

            case IOR:
              switch (pattern39 (x3))
                {
                case 0:
                  if (!
#line 78 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
                    return -1;
                  return 275; /* atomic_orsi */

                case 1:
                  if (!(
#line 78 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                    return -1;
                  return 279; /* atomic_ordi */

                default:
                  return -1;
                }

            case XOR:
              switch (pattern39 (x3))
                {
                case 0:
                  if (!
#line 78 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
                    return -1;
                  return 276; /* atomic_xorsi */

                case 1:
                  if (!(
#line 78 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                    return -1;
                  return 280; /* atomic_xordi */

                default:
                  return -1;
                }

            case AND:
              switch (pattern39 (x3))
                {
                case 0:
                  if (!
#line 78 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
                    return -1;
                  return 277; /* atomic_andsi */

                case 1:
                  if (!(
#line 78 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                    return -1;
                  return 281; /* atomic_anddi */

                default:
                  return -1;
                }

            default:
              return -1;
            }

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_11 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  rtx x10, x11, x12;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  switch (GET_CODE (x3))
    {
    case NE:
    case EQ:
    case GE:
    case GT:
    case LE:
    case LT:
    case GEU:
    case GTU:
    case LEU:
    case LTU:
      if (order_operator (x3, E_VOIDmode))
        {
          res = recog_3 (x1, insn, pnum_clobbers);
          if (res >= 0)
            return res;
        }
      if (pnum_clobbers == NULL
          || !equality_operator (x3, E_VOIDmode))
        return -1;
      operands[0] = x3;
      x4 = XEXP (x3, 0);
      if (GET_CODE (x4) != ZERO_EXTRACT)
        return -1;
      x5 = XEXP (x4, 1);
      if (GET_CODE (x5) != CONST_INT)
        return -1;
      x6 = XEXP (x3, 1);
      if (x6 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
        return -1;
      x7 = XEXP (x2, 1);
      if (GET_CODE (x7) != LABEL_REF)
        return -1;
      x8 = XEXP (x2, 2);
      if (GET_CODE (x8) != PC)
        return -1;
      x9 = XEXP (x1, 0);
      if (GET_CODE (x9) != PC)
        return -1;
      x10 = XEXP (x4, 0);
      operands[2] = x10;
      x11 = XEXP (x7, 0);
      operands[1] = x11;
      if (XWINT (x5, 0) == 1L)
        {
          x12 = XEXP (x4, 2);
          operands[3] = x12;
          if (branch_on_bit_operand (operands[3], E_VOIDmode))
            {
              switch (GET_MODE (x4))
                {
                case E_SImode:
                  if (register_operand (operands[2], E_SImode)
                      && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
                    {
                      *pnum_clobbers = 1;
                      return 186; /* *branch_on_bitsi */
                    }
                  break;

                case E_DImode:
                  if (register_operand (operands[2], E_DImode)
                      && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                    {
                      *pnum_clobbers = 1;
                      return 187; /* *branch_on_bitdi */
                    }
                  break;

                default:
                  break;
                }
            }
        }
      x12 = XEXP (x4, 2);
      if (x12 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
        return -1;
      operands[3] = x5;
      if (!branch_on_bit_operand (operands[3], E_VOIDmode))
        return -1;
      switch (GET_MODE (x4))
        {
        case E_SImode:
          if (!register_operand (operands[2], E_SImode)
              || !
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return -1;
          *pnum_clobbers = 1;
          return 188; /* *branch_on_bit_rangesi */

        case E_DImode:
          if (!register_operand (operands[2], E_DImode)
              || !
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          *pnum_clobbers = 1;
          return 189; /* *branch_on_bit_rangedi */

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_12 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 0);
  operands[0] = x2;
  x3 = XEXP (x1, 1);
  x4 = XEXP (x3, 1);
  operands[2] = x4;
  x5 = XEXP (x3, 0);
  switch (GET_CODE (x5))
    {
    case REG:
    case SUBREG:
      operands[1] = x5;
      x6 = XEXP (x3, 2);
      switch (GET_CODE (x6))
        {
        case REG:
        case SUBREG:
          operands[3] = x6;
          switch (GET_MODE (operands[0]))
            {
            case E_SFmode:
              if (pattern42 (x3, E_SFmode) != 0
                  || !
#line 840 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
                return -1;
              return 45; /* fmasf4 */

            case E_DFmode:
              if (pattern42 (x3, E_DFmode) != 0
                  || !(
#line 840 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                return -1;
              return 46; /* fmadf4 */

            default:
              return -1;
            }

        case NEG:
          x7 = XEXP (x6, 0);
          operands[3] = x7;
          switch (GET_MODE (operands[0]))
            {
            case E_SFmode:
              if (pattern43 (x3, E_SFmode) != 0
                  || !
#line 851 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
                return -1;
              return 47; /* fmssf4 */

            case E_DFmode:
              if (pattern43 (x3, E_DFmode) != 0
                  || !(
#line 851 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                return -1;
              return 48; /* fmsdf4 */

            default:
              return -1;
            }

        default:
          return -1;
        }

    case NEG:
      x8 = XEXP (x5, 0);
      operands[1] = x8;
      x6 = XEXP (x3, 2);
      switch (GET_CODE (x6))
        {
        case NEG:
          x7 = XEXP (x6, 0);
          operands[3] = x7;
          switch (GET_MODE (operands[0]))
            {
            case E_SFmode:
              if (pattern44 (x3, E_SFmode) != 0
                  || !
#line 863 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
                return -1;
              return 49; /* fnmssf4 */

            case E_DFmode:
              if (pattern44 (x3, E_DFmode) != 0
                  || !(
#line 863 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                return -1;
              return 50; /* fnmsdf4 */

            default:
              return -1;
            }

        case REG:
        case SUBREG:
          operands[3] = x6;
          switch (GET_MODE (operands[0]))
            {
            case E_SFmode:
              if (pattern45 (x3, E_SFmode) != 0
                  || !
#line 875 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
                return -1;
              return 51; /* fnmasf4 */

            case E_DFmode:
              if (pattern45 (x3, E_DFmode) != 0
                  || !(
#line 875 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
                return -1;
              return 52; /* fnmadf4 */

            default:
              return -1;
            }

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_13 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6;
  int res ATTRIBUTE_UNUSED;
  x2 = XVECEXP (x1, 0, 1);
  if (GET_CODE (x2) != USE)
    return -1;
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) != LABEL_REF)
    return -1;
  x4 = XVECEXP (x1, 0, 0);
  x5 = XEXP (x4, 1);
  operands[0] = x5;
  x6 = XEXP (x3, 0);
  operands[1] = x6;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      if (!register_operand (operands[0], E_SImode))
        return -1;
      return 243; /* tablejumpsi */

    case E_DImode:
      if (!register_operand (operands[0], E_DImode)
          || !
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return -1;
      return 244; /* tablejumpdi */

    default:
      return -1;
    }
}

static int
recog_14 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  rtx x10, x11;
  int res ATTRIBUTE_UNUSED;
  x2 = XVECEXP (x1, 0, 0);
  x3 = XEXP (x2, 0);
  operands[0] = x3;
  x4 = XVECEXP (x1, 0, 1);
  if (GET_CODE (x4) != SET)
    return -1;
  x5 = XEXP (x4, 1);
  if (GET_CODE (x5) != UNSPEC_VOLATILE)
    return -1;
  x6 = XEXP (x2, 1);
  operands[1] = x6;
  x7 = XEXP (x4, 0);
  if (!rtx_equal_p (x7, operands[1]))
    return -1;
  switch (XVECLEN (x5, 0))
    {
    case 2:
      if (XINT (x5, 1) != 16)
        return -1;
      x8 = XVECEXP (x5, 0, 1);
      operands[3] = x8;
      if (!const_int_operand (operands[3], E_SImode))
        return -1;
      x9 = XVECEXP (x5, 0, 0);
      switch (GET_CODE (x9))
        {
        case PLUS:
          switch (pattern62 (x5))
            {
            case 0:
              if (!
#line 91 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
                return -1;
              return 282; /* atomic_fetch_addsi */

            case 1:
              if (!(
#line 91 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 286; /* atomic_fetch_adddi */

            default:
              return -1;
            }

        case IOR:
          switch (pattern62 (x5))
            {
            case 0:
              if (!
#line 91 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
                return -1;
              return 283; /* atomic_fetch_orsi */

            case 1:
              if (!(
#line 91 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 287; /* atomic_fetch_ordi */

            default:
              return -1;
            }

        case XOR:
          switch (pattern62 (x5))
            {
            case 0:
              if (!
#line 91 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
                return -1;
              return 284; /* atomic_fetch_xorsi */

            case 1:
              if (!(
#line 91 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 288; /* atomic_fetch_xordi */

            default:
              return -1;
            }

        case AND:
          switch (pattern62 (x5))
            {
            case 0:
              if (!
#line 91 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
                return -1;
              return 285; /* atomic_fetch_andsi */

            case 1:
              if (!(
#line 91 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 289; /* atomic_fetch_anddi */

            default:
              return -1;
            }

        default:
          return -1;
        }

    case 4:
      if (pnum_clobbers == NULL
          || XINT (x5, 1) != 15)
        return -1;
      x9 = XVECEXP (x5, 0, 0);
      operands[2] = x9;
      x8 = XVECEXP (x5, 0, 1);
      operands[3] = x8;
      x10 = XVECEXP (x5, 0, 2);
      operands[4] = x10;
      if (!const_int_operand (operands[4], E_SImode))
        return -1;
      x11 = XVECEXP (x5, 0, 3);
      operands[5] = x11;
      if (!const_int_operand (operands[5], E_SImode))
        return -1;
      switch (GET_MODE (operands[0]))
        {
        case E_SImode:
          if (pattern67 (x5, E_SImode) != 0
              || !
#line 117 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
            return -1;
          *pnum_clobbers = 1;
          return 292; /* atomic_cas_value_strongsi */

        case E_DImode:
          if (pattern67 (x5, E_DImode) != 0
              || !(
#line 117 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
            return -1;
          *pnum_clobbers = 1;
          return 293; /* atomic_cas_value_strongdi */

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_15 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7;
  int res ATTRIBUTE_UNUSED;
  x2 = XVECEXP (x1, 0, 1);
  if (GET_CODE (x2) != CLOBBER)
    return -1;
  x3 = XVECEXP (x1, 0, 0);
  x4 = XEXP (x3, 0);
  x5 = XEXP (x4, 0);
  operands[0] = x5;
  if (!absolute_symbolic_operand (operands[0], E_VOIDmode))
    return -1;
  x6 = XEXP (x3, 1);
  operands[1] = x6;
  x7 = XEXP (x2, 0);
  operands[2] = x7;
  switch (GET_MODE (x4))
    {
    case E_QImode:
      switch (pattern54 (E_QImode))
        {
        case 0:
          if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
            return -1;
          return 326; /* *local_pic_storeqi */

        case 1:
          if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
            return -1;
          return 330; /* *local_pic_storeqi */

        default:
          return -1;
        }

    case E_HImode:
      switch (pattern54 (E_HImode))
        {
        case 0:
          if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
            return -1;
          return 327; /* *local_pic_storehi */

        case 1:
          if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
            return -1;
          return 331; /* *local_pic_storehi */

        default:
          return -1;
        }

    case E_SImode:
      switch (pattern54 (E_SImode))
        {
        case 0:
          if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
            return -1;
          return 328; /* *local_pic_storesi */

        case 1:
          if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
            return -1;
          return 332; /* *local_pic_storesi */

        default:
          return -1;
        }

    case E_DImode:
      switch (pattern54 (E_DImode))
        {
        case 0:
          if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 296 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
            return -1;
          return 329; /* *local_pic_storedi */

        case 1:
          if (!(
#line 87 "../../gcc/config/riscv/pic.md"
(USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 296 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
            return -1;
          return 333; /* *local_pic_storedi */

        default:
          return -1;
        }

    case E_SFmode:
      switch (pattern55 (E_SFmode))
        {
        case 0:
          if ((
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
            return 334; /* *local_pic_storesf */
          if (!(
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
            return -1;
          return 342; /* *local_pic_store_sfsf */

        case 1:
          if ((
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
            return 336; /* *local_pic_storesf */
          if (!(
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
            return -1;
          return 344; /* *local_pic_store_sfsf */

        default:
          return -1;
        }

    case E_DFmode:
      switch (pattern55 (E_DFmode))
        {
        case 0:
          if ((
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
            return 335; /* *local_pic_storedf */
          if (!(
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
            return -1;
          return 343; /* *local_pic_store_sfdf */

        case 1:
          if ((
#line 95 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
            return 337; /* *local_pic_storedf */
          if (!(
#line 119 "../../gcc/config/riscv/pic.md"
(!TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[0])) && (
#line 303 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
            return -1;
          return 345; /* *local_pic_store_sfdf */

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_16 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  rtx x10, x11, x12, x13, x14, x15, x16, x17;
  rtx x18, x19;
  int res ATTRIBUTE_UNUSED;
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_CODE (x2))
    {
    case SET:
      x3 = XEXP (x2, 1);
      switch (GET_CODE (x3))
        {
        case AND:
          if (GET_MODE (x3) != E_DImode)
            return -1;
          x4 = XEXP (x3, 0);
          if (GET_CODE (x4) != ASHIFT
              || GET_MODE (x4) != E_DImode)
            return -1;
          x5 = XVECEXP (x1, 0, 1);
          if (GET_CODE (x5) != CLOBBER)
            return -1;
          x6 = XEXP (x2, 0);
          operands[0] = x6;
          if (!register_operand (operands[0], E_DImode)
              || pattern53 (x1) != 0
              || !
#line 1836 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && ((INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff)))
            return -1;
          return 180; /* zero_extendsidi2_shifted */

        case IF_THEN_ELSE:
          if (pattern23 (x2) != 0)
            return -1;
          x5 = XVECEXP (x1, 0, 1);
          if (GET_CODE (x5) != CLOBBER)
            return -1;
          x4 = XEXP (x3, 0);
          x7 = XEXP (x4, 0);
          x8 = XEXP (x7, 0);
          operands[2] = x8;
          x9 = XEXP (x3, 1);
          x10 = XEXP (x9, 0);
          operands[1] = x10;
          x11 = XEXP (x5, 0);
          operands[4] = x11;
          x12 = XEXP (x7, 1);
          if (XWINT (x12, 0) == 1L)
            {
              switch (pattern64 (x7))
                {
                case 0:
                  if (
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
                    return 186; /* *branch_on_bitsi */
                  break;

                case 1:
                  if (
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                    return 187; /* *branch_on_bitdi */
                  break;

                default:
                  break;
                }
            }
          x13 = XEXP (x7, 2);
          if (x13 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
            return -1;
          switch (pattern65 (x7))
            {
            case 0:
              if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
                return -1;
              return 188; /* *branch_on_bit_rangesi */

            case 1:
              if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return -1;
              return 189; /* *branch_on_bit_rangedi */

            default:
              return -1;
            }

        case UNSPEC:
          x6 = XEXP (x2, 0);
          operands[0] = x6;
          switch (XVECLEN (x3, 0))
            {
            case 2:
              x5 = XVECEXP (x1, 0, 1);
              if (GET_CODE (x5) != CLOBBER)
                return -1;
              x14 = XVECEXP (x3, 0, 0);
              operands[1] = x14;
              x15 = XVECEXP (x3, 0, 1);
              operands[2] = x15;
              x11 = XEXP (x5, 0);
              operands[3] = x11;
              switch (XINT (x3, 1))
                {
                case 9:
                  switch (GET_MODE (operands[0]))
                    {
                    case E_SImode:
                      switch (pattern57 (x3, E_SImode))
                        {
                        case 0:
                          if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                            return 194; /* *flt_quietsfsi4_default */
                          if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                            return -1;
                          return 202; /* *flt_quietsfsi4_snan */

                        case 1:
                          if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                            return 198; /* *flt_quietdfsi4_default */
                          if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                            return -1;
                          return 206; /* *flt_quietdfsi4_snan */

                        default:
                          return -1;
                        }

                    case E_DImode:
                      switch (pattern57 (x3, E_DImode))
                        {
                        case 0:
                          if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                            return 196; /* *flt_quietsfdi4_default */
                          if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                            return -1;
                          return 204; /* *flt_quietsfdi4_snan */

                        case 1:
                          if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                            return 200; /* *flt_quietdfdi4_default */
                          if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                            return -1;
                          return 208; /* *flt_quietdfdi4_snan */

                        default:
                          return -1;
                        }

                    default:
                      return -1;
                    }

                case 10:
                  switch (GET_MODE (operands[0]))
                    {
                    case E_SImode:
                      switch (pattern57 (x3, E_SImode))
                        {
                        case 0:
                          if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                            return 195; /* *fle_quietsfsi4_default */
                          if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                            return -1;
                          return 203; /* *fle_quietsfsi4_snan */

                        case 1:
                          if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                            return 199; /* *fle_quietdfsi4_default */
                          if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))))
                            return -1;
                          return 207; /* *fle_quietdfsi4_snan */

                        default:
                          return -1;
                        }

                    case E_DImode:
                      switch (pattern57 (x3, E_DImode))
                        {
                        case 0:
                          if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                            return 197; /* *fle_quietsfdi4_default */
                          if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (SFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                            return -1;
                          return 205; /* *fle_quietsfdi4_snan */

                        case 1:
                          if ((
#line 2054 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && ! HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                            return 201; /* *fle_quietdfdi4_default */
                          if (!(
#line 2067 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && HONOR_SNANS (DFmode)) && (((
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
                            return -1;
                          return 209; /* *fle_quietdfdi4_snan */

                        default:
                          return -1;
                        }

                    default:
                      return -1;
                    }

                case 11:
                  switch (GET_MODE (operands[0]))
                    {
                    case E_SImode:
                      if (pattern58 (x3, E_SImode) != 0)
                        return -1;
                      return 269; /* stack_protect_test_si */

                    case E_DImode:
                      if (pattern58 (x3, E_DImode) != 0
                          || !
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                        return -1;
                      return 270; /* stack_protect_test_di */

                    default:
                      return -1;
                    }

                default:
                  return -1;
                }

            case 1:
              switch (XINT (x3, 1))
                {
                case 10:
                  x5 = XVECEXP (x1, 0, 1);
                  if (GET_CODE (x5) != SET)
                    return -1;
                  x16 = XEXP (x5, 1);
                  if (x16 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
                    return -1;
                  x14 = XVECEXP (x3, 0, 0);
                  operands[1] = x14;
                  x11 = XEXP (x5, 0);
                  operands[2] = x11;
                  switch (GET_MODE (operands[0]))
                    {
                    case E_SImode:
                      if (pattern59 (x3, E_SImode) != 0)
                        return -1;
                      return 267; /* stack_protect_set_si */

                    case E_DImode:
                      if (pattern59 (x3, E_DImode) != 0
                          || !
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                        return -1;
                      return 268; /* stack_protect_set_di */

                    default:
                      return -1;
                    }

                case 19:
                  if (GET_MODE (x3) != E_BLKmode)
                    return -1;
                  x5 = XVECEXP (x1, 0, 1);
                  operands[1] = x5;
                  if (!const_int_operand (operands[1], E_SImode))
                    return -1;
                  x14 = XVECEXP (x3, 0, 0);
                  if (!rtx_equal_p (x14, operands[0]))
                    return -1;
                  return 271; /* mem_thread_fence_1 */

                default:
                  return -1;
                }

            default:
              return -1;
            }

        case CONST_INT:
        case CONST_WIDE_INT:
        case CONST_DOUBLE:
        case CONST_VECTOR:
        case REG:
        case SUBREG:
        case MEM:
          x6 = XEXP (x2, 0);
          switch (GET_CODE (x6))
            {
            case PC:
              res = recog_13 (x1, insn, pnum_clobbers);
              if (res >= 0)
                return res;
              break;

            case REG:
            case SUBREG:
              res = recog_14 (x1, insn, pnum_clobbers);
              if (res >= 0)
                return res;
              break;

            case MEM:
              res = recog_15 (x1, insn, pnum_clobbers);
              if (res >= 0)
                return res;
              break;

            default:
              break;
            }
          if (GET_CODE (x3) != MEM)
            return -1;
          x5 = XVECEXP (x1, 0, 1);
          if (GET_CODE (x5) != CLOBBER)
            return -1;
          operands[0] = x6;
          x4 = XEXP (x3, 0);
          operands[1] = x4;
          if (!absolute_symbolic_operand (operands[1], E_VOIDmode))
            return -1;
          x11 = XEXP (x5, 0);
          operands[2] = x11;
          switch (GET_MODE (operands[0]))
            {
            case E_SFmode:
              switch (pattern56 (x3, E_SFmode))
                {
                case 0:
                  if ((
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
                    return 316; /* *local_pic_loadsf */
                  if (!(
#line 68 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
                    return -1;
                  return 320; /* *local_pic_load_32dsf */

                case 1:
                  if ((
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
                    return 318; /* *local_pic_loadsf */
                  if (!(
#line 68 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
                    return -1;
                  return 322; /* *local_pic_load_32dsf */

                default:
                  return -1;
                }

            case E_DFmode:
              switch (pattern56 (x3, E_DFmode))
                {
                case 0:
                  if ((
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
                    return 317; /* *local_pic_loaddf */
                  if (!(
#line 68 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))))
                    return -1;
                  return 321; /* *local_pic_load_32ddf */

                case 1:
                  if ((
#line 53 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (!TARGET_DOUBLE_FLOAT || TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
                    return 319; /* *local_pic_loaddf */
                  if (!(
#line 68 "../../gcc/config/riscv/pic.md"
(TARGET_HARD_FLOAT && USE_LOAD_ADDRESS_MACRO (operands[1])
   && (TARGET_DOUBLE_FLOAT && !TARGET_64BIT)) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))))
                    return -1;
                  return 323; /* *local_pic_load_32ddf */

                default:
                  return -1;
                }

            default:
              return -1;
            }

        case CALL:
          x4 = XEXP (x3, 0);
          if (GET_CODE (x4) != MEM
              || GET_MODE (x4) != E_SImode)
            return -1;
          x5 = XVECEXP (x1, 0, 1);
          if (pattern28 (x5) != 0)
            return -1;
          x6 = XEXP (x2, 0);
          operands[0] = x6;
          x7 = XEXP (x4, 0);
          operands[1] = x7;
          if (!call_insn_operand (operands[1], E_VOIDmode))
            return -1;
          x9 = XEXP (x3, 1);
          operands[2] = x9;
          return 254; /* call_value_internal */

        case UNSPEC_VOLATILE:
          if (XVECLEN (x3, 0) != 2
              || XINT (x3, 1) != 17)
            return -1;
          x5 = XVECEXP (x1, 0, 1);
          if (GET_CODE (x5) != SET)
            return -1;
          x6 = XEXP (x2, 0);
          operands[0] = x6;
          x14 = XVECEXP (x3, 0, 0);
          operands[1] = x14;
          x15 = XVECEXP (x3, 0, 1);
          operands[3] = x15;
          if (!const_int_operand (operands[3], E_SImode))
            return -1;
          x16 = XEXP (x5, 1);
          operands[2] = x16;
          x11 = XEXP (x5, 0);
          if (!rtx_equal_p (x11, operands[1]))
            return -1;
          switch (GET_MODE (operands[0]))
            {
            case E_SImode:
              if (pattern60 (x3, E_SImode) != 0
                  || !
#line 103 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
                return -1;
              return 290; /* atomic_exchangesi */

            case E_DImode:
              if (pattern60 (x3, E_DImode) != 0
                  || !(
#line 103 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                return -1;
              return 291; /* atomic_exchangedi */

            default:
              return -1;
            }

        default:
          return -1;
        }

    case SIMPLE_RETURN:
      x5 = XVECEXP (x1, 0, 1);
      if (GET_CODE (x5) != USE)
        return -1;
      x11 = XEXP (x5, 0);
      operands[0] = x11;
      if (!pmode_register_operand (operands[0], E_VOIDmode))
        return -1;
      return 247; /* simple_return_internal */

    case UNSPEC:
      if (XVECLEN (x2, 0) != 1
          || XINT (x2, 1) != 0)
        return -1;
      x5 = XVECEXP (x1, 0, 1);
      if (GET_CODE (x5) != CLOBBER)
        return -1;
      x17 = XVECEXP (x2, 0, 0);
      operands[0] = x17;
      x11 = XEXP (x5, 0);
      operands[1] = x11;
      switch (GET_MODE (operands[0]))
        {
        case E_SImode:
          if (!register_operand (operands[0], E_SImode)
              || !scratch_operand (operands[1], E_SImode)
              || !
#line 2284 "../../gcc/config/riscv/riscv.md"
(! TARGET_64BIT))
            return -1;
          return 248; /* eh_set_lr_si */

        case E_DImode:
          if (!register_operand (operands[0], E_DImode)
              || !scratch_operand (operands[1], E_DImode)
              || !
#line 2290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 249; /* eh_set_lr_di */

        default:
          return -1;
        }

    case CALL:
      x6 = XEXP (x2, 0);
      if (GET_CODE (x6) != MEM
          || GET_MODE (x6) != E_SImode)
        return -1;
      x5 = XVECEXP (x1, 0, 1);
      if (pattern28 (x5) != 0)
        return -1;
      x18 = XEXP (x6, 0);
      operands[0] = x18;
      if (!call_insn_operand (operands[0], E_VOIDmode))
        return -1;
      x3 = XEXP (x2, 1);
      operands[1] = x3;
      return 253; /* call_internal */

    case RETURN:
      x5 = XVECEXP (x1, 0, 1);
      if (GET_CODE (x5) != UNSPEC_VOLATILE
          || XVECLEN (x5, 0) != 1)
        return -1;
      x19 = XVECEXP (x5, 0, 0);
      if (x19 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
        return -1;
      switch (XINT (x5, 1))
        {
        case 4:
          return 262; /* riscv_mret */

        case 5:
          return 263; /* riscv_sret */

        case 6:
          return 264; /* riscv_uret */

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_17 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  rtx x10, x11, x12, x13;
  int res ATTRIBUTE_UNUSED;
  x2 = XVECEXP (x1, 0, 0);
  switch (GET_CODE (x2))
    {
    case RETURN:
      x3 = XVECEXP (x1, 0, 1);
      if (GET_CODE (x3) != USE)
        return -1;
      x4 = XVECEXP (x1, 0, 2);
      if (x4 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
        return -1;
      x5 = XEXP (x3, 0);
      operands[0] = x5;
      if (!pmode_register_operand (operands[0], E_VOIDmode))
        return -1;
      return 259; /* gpr_restore_return */

    case SET:
      x3 = XVECEXP (x1, 0, 1);
      if (GET_CODE (x3) != SET)
        return -1;
      x6 = XEXP (x3, 1);
      if (GET_CODE (x6) != UNSPEC_VOLATILE
          || XVECLEN (x6, 0) != 4
          || XINT (x6, 1) != 15)
        return -1;
      x4 = XVECEXP (x1, 0, 2);
      if (GET_CODE (x4) != CLOBBER)
        return -1;
      x7 = XEXP (x2, 0);
      operands[0] = x7;
      x8 = XEXP (x2, 1);
      operands[1] = x8;
      x9 = XVECEXP (x6, 0, 0);
      operands[2] = x9;
      x10 = XVECEXP (x6, 0, 1);
      operands[3] = x10;
      x11 = XVECEXP (x6, 0, 2);
      operands[4] = x11;
      if (!const_int_operand (operands[4], E_SImode))
        return -1;
      x12 = XVECEXP (x6, 0, 3);
      operands[5] = x12;
      if (!const_int_operand (operands[5], E_SImode))
        return -1;
      x13 = XEXP (x4, 0);
      operands[6] = x13;
      x5 = XEXP (x3, 0);
      if (!rtx_equal_p (x5, operands[1]))
        return -1;
      switch (GET_MODE (operands[0]))
        {
        case E_SImode:
          if (pattern66 (x6, E_SImode) != 0
              || !
#line 117 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC))
            return -1;
          return 292; /* atomic_cas_value_strongsi */

        case E_DImode:
          if (pattern66 (x6, E_DImode) != 0
              || !(
#line 117 "../../gcc/config/riscv/sync.md"
(TARGET_ATOMIC) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
            return -1;
          return 293; /* atomic_cas_value_strongdi */

        default:
          return -1;
        }

    default:
      return -1;
    }
}

static int
recog_18 (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  rtx x10, x11;
  int res ATTRIBUTE_UNUSED;
  x2 = XEXP (x1, 1);
  switch (GET_CODE (x2))
    {
    case PLUS:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      switch (GET_MODE (operands[0]))
        {
        case E_SFmode:
          if (pattern0 (x2, E_SFmode) != 0
              || !
#line 447 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return -1;
          return 1; /* addsf3 */

        case E_DFmode:
          if (pattern0 (x2, E_DFmode) != 0
              || !(
#line 447 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 2; /* adddf3 */

        case E_SImode:
          if (pattern10 (x2, E_SImode) != 0)
            return -1;
          return 3; /* addsi3 */

        case E_DImode:
          if (pattern10 (x2, E_DImode) != 0
              || !
#line 465 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 4; /* adddi3 */

        case E_HImode:
          switch (pattern29 (x2))
            {
            case 0:
              return 138; /* *addhihi3 */

            case 1:
              return 139; /* *addsihi3 */

            default:
              return -1;
            }

        default:
          return -1;
        }

    case SIGN_EXTEND:
      return recog_4 (x1, insn, pnum_clobbers);

    case MINUS:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      switch (GET_MODE (operands[0]))
        {
        case E_SFmode:
          if (pattern0 (x2, E_SFmode) != 0
              || !
#line 503 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return -1;
          return 7; /* subsf3 */

        case E_DFmode:
          if (pattern0 (x2, E_DFmode) != 0
              || !(
#line 503 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 8; /* subdf3 */

        case E_DImode:
          if (pattern31 (x2, E_DImode) != 0
              || !
#line 512 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 9; /* subdi3 */

        case E_SImode:
          if (pattern31 (x2, E_SImode) != 0)
            return -1;
          return 10; /* subsi3 */

        default:
          return -1;
        }

    case NEG:
      return recog_8 (x1, insn, pnum_clobbers);

    case MULT:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      switch (GET_MODE (operands[0]))
        {
        case E_SFmode:
          if (pattern0 (x2, E_SFmode) != 0
              || !
#line 594 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return -1;
          return 17; /* mulsf3 */

        case E_DFmode:
          if (pattern0 (x2, E_DFmode) != 0
              || !(
#line 594 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 18; /* muldf3 */

        case E_SImode:
          if (pattern0 (x2, E_SImode) != 0
              || !
#line 603 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL))
            return -1;
          return 19; /* mulsi3 */

        case E_DImode:
          if (pattern0 (x2, E_DImode) != 0
              || !
#line 612 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && TARGET_64BIT))
            return -1;
          return 20; /* muldi3 */

        default:
          return -1;
        }

    case TRUNCATE:
      x4 = XEXP (x2, 0);
      if (GET_CODE (x4) != LSHIFTRT)
        return -1;
      x6 = XEXP (x4, 0);
      if (GET_CODE (x6) != MULT)
        return -1;
      x7 = XEXP (x4, 1);
      if (GET_CODE (x7) != CONST_INT)
        return -1;
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x8 = XEXP (x6, 0);
      switch (GET_CODE (x8))
        {
        case SIGN_EXTEND:
          x9 = XEXP (x6, 1);
          if (GET_CODE (x9) != SIGN_EXTEND)
            return -1;
          x10 = XEXP (x8, 0);
          operands[1] = x10;
          switch (pattern41 (x2))
            {
            case 0:
              if (!
#line 673 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && TARGET_64BIT))
                return -1;
              return 23; /* muldi3_highpart */

            case 1:
              if (!
#line 734 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && !TARGET_64BIT))
                return -1;
              return 26; /* mulsi3_highpart */

            default:
              return -1;
            }

        case ZERO_EXTEND:
          x10 = XEXP (x8, 0);
          operands[1] = x10;
          x9 = XEXP (x6, 1);
          switch (GET_CODE (x9))
            {
            case ZERO_EXTEND:
              switch (pattern41 (x2))
                {
                case 0:
                  if (!
#line 673 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && TARGET_64BIT))
                    return -1;
                  return 24; /* umuldi3_highpart */

                case 1:
                  if (!
#line 734 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && !TARGET_64BIT))
                    return -1;
                  return 27; /* umulsi3_highpart */

                default:
                  return -1;
                }

            case SIGN_EXTEND:
              switch (pattern41 (x2))
                {
                case 0:
                  if (!
#line 704 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && TARGET_64BIT))
                    return -1;
                  return 25; /* usmuldi3_highpart */

                case 1:
                  if (!
#line 765 "../../gcc/config/riscv/riscv.md"
(TARGET_MUL && !TARGET_64BIT))
                    return -1;
                  return 28; /* usmulsi3_highpart */

                default:
                  return -1;
                }

            default:
              return -1;
            }

        default:
          return -1;
        }

    case DIV:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      switch (GET_MODE (operands[0]))
        {
        case E_SImode:
          if (pattern0 (x2, E_SImode) != 0
              || !
#line 782 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV))
            return -1;
          return 29; /* divsi3 */

        case E_DImode:
          if (pattern0 (x2, E_DImode) != 0
              || !
#line 791 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV && TARGET_64BIT))
            return -1;
          return 33; /* divdi3 */

        case E_SFmode:
          if (pattern0 (x2, E_SFmode) != 0
              || !(
#line 810 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
            return -1;
          return 41; /* divsf3 */

        case E_DFmode:
          if (pattern0 (x2, E_DFmode) != 0
              || !(
#line 810 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 42; /* divdf3 */

        default:
          return -1;
        }

    case UDIV:
      switch (pattern1 (x1))
        {
        case 0:
          if (!
#line 782 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV))
            return -1;
          return 30; /* udivsi3 */

        case 1:
          if (!
#line 791 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV && TARGET_64BIT))
            return -1;
          return 34; /* udivdi3 */

        default:
          return -1;
        }

    case MOD:
      switch (pattern1 (x1))
        {
        case 0:
          if (!
#line 782 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV))
            return -1;
          return 31; /* modsi3 */

        case 1:
          if (!
#line 791 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV && TARGET_64BIT))
            return -1;
          return 35; /* moddi3 */

        default:
          return -1;
        }

    case UMOD:
      switch (pattern1 (x1))
        {
        case 0:
          if (!
#line 782 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV))
            return -1;
          return 32; /* umodsi3 */

        case 1:
          if (!
#line 791 "../../gcc/config/riscv/riscv.md"
(TARGET_DIV && TARGET_64BIT))
            return -1;
          return 36; /* umoddi3 */

        default:
          return -1;
        }

    case SQRT:
      switch (pattern2 (x1))
        {
        case 0:
          if (!(
#line 825 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT)))
            return -1;
          return 43; /* sqrtsf2 */

        case 1:
          if (!(
#line 825 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT && TARGET_FDIV) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 44; /* sqrtdf2 */

        default:
          return -1;
        }

    case FMA:
      return recog_12 (x1, insn, pnum_clobbers);

    case ABS:
      switch (pattern2 (x1))
        {
        case 0:
          if (!
#line 942 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return -1;
          return 61; /* abssf2 */

        case 1:
          if (!(
#line 942 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 62; /* absdf2 */

        default:
          return -1;
        }

    case UNSPEC:
      return recog_5 (x1, insn, pnum_clobbers);

    case SMIN:
      switch (pattern3 (x1))
        {
        case 0:
          if (!
#line 976 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return -1;
          return 67; /* sminsf3 */

        case 1:
          if (!(
#line 976 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 68; /* smindf3 */

        default:
          return -1;
        }

    case SMAX:
      switch (pattern3 (x1))
        {
        case 0:
          if (!
#line 985 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return -1;
          return 69; /* smaxsf3 */

        case 1:
          if (!(
#line 985 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 70; /* smaxdf3 */

        default:
          return -1;
        }

    case AND:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      switch (GET_CODE (x4))
        {
        case REG:
        case SUBREG:
          switch (pattern11 (x2))
            {
            case 0:
              if (
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
                return 71; /* andsi3 */
              if (!
#line 1014 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return -1;
              return 77; /* *andsi3_internal */

            case 1:
              if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return -1;
              return 74; /* anddi3 */

            default:
              return -1;
            }

        case ASHIFT:
          if (pnum_clobbers == NULL
              || pattern15 (x2, E_DImode) != 0
              || !immediate_operand (operands[2], E_QImode))
            return -1;
          x5 = XEXP (x2, 1);
          operands[3] = x5;
          if (!immediate_operand (operands[3], E_VOIDmode)
              || !
#line 1836 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && ((INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff)))
            return -1;
          *pnum_clobbers = 1;
          return 180; /* zero_extendsidi2_shifted */

        default:
          return -1;
        }

    case IOR:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      switch (pattern11 (x2))
        {
        case 0:
          if (
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return 72; /* iorsi3 */
          if (!
#line 1014 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 78; /* *iorsi3_internal */

        case 1:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 75; /* iordi3 */

        default:
          return -1;
        }

    case XOR:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      switch (GET_MODE (operands[0]))
        {
        case E_SImode:
          if (pattern10 (x2, E_SImode) != 0)
            return -1;
          if (
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return 73; /* xorsi3 */
          if (!
#line 1014 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 79; /* *xorsi3_internal */

        case E_DImode:
          if (pattern10 (x2, E_DImode) != 0
              || !
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 76; /* xordi3 */

        case E_HImode:
          switch (pattern29 (x2))
            {
            case 0:
              return 140; /* *xorhihi3 */

            case 1:
              return 141; /* *xorsihi3 */

            default:
              return -1;
            }

        default:
          return -1;
        }

    case NOT:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      switch (pattern20 (x2))
        {
        case 0:
          if (
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return 80; /* one_cmplsi2 */
          if (!
#line 1030 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 82; /* *one_cmplsi2_internal */

        case 1:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 81; /* one_cmpldi2 */

        default:
          return -1;
        }

    case FLOAT_TRUNCATE:
      if (GET_MODE (x2) != E_SFmode)
        return -1;
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      if (!register_operand (operands[0], E_SFmode))
        return -1;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      if (!register_operand (operands[1], E_DFmode)
          || !
#line 1046 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))
        return -1;
      return 83; /* truncdfsf2 */

    case ZERO_EXTEND:
      return recog_7 (x1, insn, pnum_clobbers);

    case FLOAT_EXTEND:
      if (GET_MODE (x2) != E_DFmode)
        return -1;
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      if (!register_operand (operands[0], E_DFmode))
        return -1;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      if (!register_operand (operands[1], E_SFmode)
          || !
#line 1156 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))
        return -1;
      return 97; /* extendsfdf2 */

    case FIX:
      switch (pattern5 (x1))
        {
        case 0:
          if (!
#line 1172 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return -1;
          return 98; /* fix_truncsfsi2 */

        case 1:
          if (!(
#line 1172 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 100; /* fix_truncdfsi2 */

        case 2:
          if (!(
#line 1172 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))))
            return -1;
          return 99; /* fix_truncsfdi2 */

        case 3:
          if (!(
#line 1172 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))))
            return -1;
          return 101; /* fix_truncdfdi2 */

        default:
          return -1;
        }

    case UNSIGNED_FIX:
      switch (pattern5 (x1))
        {
        case 0:
          if (!
#line 1181 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return -1;
          return 102; /* fixuns_truncsfsi2 */

        case 1:
          if (!(
#line 1181 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return -1;
          return 104; /* fixuns_truncdfsi2 */

        case 2:
          if (!(
#line 1181 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))))
            return -1;
          return 103; /* fixuns_truncsfdi2 */

        case 3:
          if (!(
#line 1181 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT))))
            return -1;
          return 105; /* fixuns_truncdfdi2 */

        default:
          return -1;
        }

    case FLOAT:
      switch (pattern6 (x1))
        {
        case 0:
          if (reg_or_0_operand (operands[1], E_SImode)
              && 
#line 1190 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return 106; /* floatsisf2 */
          if (!reg_or_0_operand (operands[1], E_DImode)
              || !(
#line 1190 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
            return -1;
          return 107; /* floatdisf2 */

        case 1:
          if (reg_or_0_operand (operands[1], E_SImode)
              && (
#line 1190 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return 108; /* floatsidf2 */
          if (!reg_or_0_operand (operands[1], E_DImode)
              || !(
#line 1190 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
            return -1;
          return 109; /* floatdidf2 */

        default:
          return -1;
        }

    case UNSIGNED_FLOAT:
      switch (pattern6 (x1))
        {
        case 0:
          if (reg_or_0_operand (operands[1], E_SImode)
              && 
#line 1199 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return 110; /* floatunssisf2 */
          if (!reg_or_0_operand (operands[1], E_DImode)
              || !(
#line 1199 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 299 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
            return -1;
          return 111; /* floatunsdisf2 */

        case 1:
          if (reg_or_0_operand (operands[1], E_SImode)
              && (
#line 1199 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && 
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT)))
            return 112; /* floatunssidf2 */
          if (!reg_or_0_operand (operands[1], E_DImode)
              || !(
#line 1199 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT) && (
#line 300 "../../gcc/config/riscv/riscv.md"
(TARGET_DOUBLE_FLOAT) && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))))
            return -1;
          return 113; /* floatunsdidf2 */

        default:
          return -1;
        }

    case LO_SUM:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      switch (GET_MODE (operands[0]))
        {
        case E_SImode:
          if (pattern33 (x2, E_SImode) != 0
              || !
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode))
            return -1;
          return 132; /* *lowsi */

        case E_DImode:
          if (pattern33 (x2, E_DImode) != 0
              || !
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode))
            return -1;
          return 133; /* *lowdi */

        default:
          return -1;
        }

    case CONST_INT:
    case CONST_WIDE_INT:
    case CONST_POLY_INT:
    case CONST_FIXED:
    case CONST_DOUBLE:
    case CONST_VECTOR:
    case CONST:
    case REG:
    case SUBREG:
    case MEM:
    case LABEL_REF:
    case SYMBOL_REF:
    case HIGH:
      return recog_6 (x1, insn, pnum_clobbers);

    case ASHIFT:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      if (arith_operand (operands[2], E_QImode))
        {
          switch (pattern20 (x2))
            {
            case 0:
              return 150; /* ashlsi3 */

            case 1:
              if (
#line 1634 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return 159; /* ashldi3 */
              break;

            default:
              break;
            }
        }
      if (!subreg_lowpart_operator (x5, E_VOIDmode))
        return -1;
      switch (pattern26 (x2))
        {
        case 0:
          if (!
#line 1598 "../../gcc/config/riscv/riscv.md"
((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
   == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 153; /* *ashlsi3_mask */

        case 1:
          if (!
#line 1617 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 156; /* *ashlsi3_mask_1 */

        case 2:
          if (!
#line 1653 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1))
            return -1;
          return 162; /* *ashldi3_mask */

        case 3:
          if (!
#line 1673 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1))
            return -1;
          return 165; /* *ashldi3_mask_1 */

        default:
          return -1;
        }

    case ASHIFTRT:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      if (arith_operand (operands[2], E_QImode))
        {
          switch (pattern20 (x2))
            {
            case 0:
              return 151; /* ashrsi3 */

            case 1:
              if (
#line 1634 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return 160; /* ashrdi3 */
              break;

            default:
              break;
            }
        }
      if (!subreg_lowpart_operator (x5, E_VOIDmode))
        return -1;
      switch (pattern26 (x2))
        {
        case 0:
          if (!
#line 1598 "../../gcc/config/riscv/riscv.md"
((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
   == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 154; /* *ashrsi3_mask */

        case 1:
          if (!
#line 1617 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 157; /* *ashrsi3_mask_1 */

        case 2:
          if (!
#line 1653 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1))
            return -1;
          return 163; /* *ashrdi3_mask */

        case 3:
          if (!
#line 1673 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1))
            return -1;
          return 166; /* *ashrdi3_mask_1 */

        default:
          return -1;
        }

    case LSHIFTRT:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      if (arith_operand (operands[2], E_QImode))
        {
          switch (pattern20 (x2))
            {
            case 0:
              return 152; /* lshrsi3 */

            case 1:
              if (
#line 1634 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                return 161; /* lshrdi3 */
              break;

            default:
              break;
            }
        }
      if (!subreg_lowpart_operator (x5, E_VOIDmode))
        return -1;
      switch (pattern26 (x2))
        {
        case 0:
          if (!
#line 1598 "../../gcc/config/riscv/riscv.md"
((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
   == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 155; /* *lshrsi3_mask */

        case 1:
          if (!
#line 1617 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1))
            return -1;
          return 158; /* *lshrsi3_mask_1 */

        case 2:
          if (!
#line 1653 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1))
            return -1;
          return 164; /* *lshrdi3_mask */

        case 3:
          if (!
#line 1673 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1))
            return -1;
          return 167; /* *lshrdi3_mask_1 */

        default:
          return -1;
        }

    case ZERO_EXTRACT:
      if (pattern7 (x1) != 0)
        return -1;
      x11 = XEXP (x2, 2);
      operands[3] = x11;
      if (!const_int_operand (operands[3], E_VOIDmode)
          || !
#line 1766 "../../gcc/config/riscv/riscv.md"
((TARGET_64BIT && (INTVAL (operands[3]) > 0)
    && (INTVAL (operands[2]) + INTVAL (operands[3]) == 32))))
        return -1;
      return 178; /* *lshrsi3_zero_extend_2 */

    case EQ:
    case GE:
    case GT:
    case LE:
    case LT:
      return recog_9 (x1, insn, pnum_clobbers);

    case IF_THEN_ELSE:
      return recog_11 (x1, insn, pnum_clobbers);

    case NE:
      switch (pattern9 (x1, 0))
        {
        case 0:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return -1;
          return 213; /* *sne_zero_sisi */

        case 1:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 214; /* *sne_zero_disi */

        case 2:
          if (!
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 215; /* *sne_zero_didi */

        default:
          return -1;
        }

    case GTU:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      switch (pattern21 (x2))
        {
        case 0:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return -1;
          return 217; /* *sgtu_sisi */

        case 1:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 219; /* *sgtu_disi */

        case 2:
          if (!
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 221; /* *sgtu_didi */

        default:
          return -1;
        }

    case GEU:
      switch (pattern9 (x1, 1))
        {
        case 0:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return -1;
          return 223; /* *sgeu_sisi */

        case 1:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 225; /* *sgeu_disi */

        case 2:
          if (!
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 227; /* *sgeu_didi */

        default:
          return -1;
        }

    case LTU:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      switch (pattern27 (x2))
        {
        case 0:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return -1;
          return 229; /* *sltu_sisi */

        case 1:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 231; /* *sltu_disi */

        case 2:
          if (!
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 233; /* *sltu_didi */

        default:
          return -1;
        }

    case LEU:
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x4 = XEXP (x2, 0);
      operands[1] = x4;
      switch (pattern22 (x2))
        {
        case 0:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT))
            return -1;
          return 235; /* *sleu_sisi */

        case 1:
          if (!
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 237; /* *sleu_disi */

        case 2:
          if (!
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          return 239; /* *sleu_didi */

        default:
          return -1;
        }

    case CALL:
      x4 = XEXP (x2, 0);
      if (GET_CODE (x4) != MEM
          || GET_MODE (x4) != E_SImode)
        return -1;
      x3 = XEXP (x1, 0);
      operands[0] = x3;
      x6 = XEXP (x4, 0);
      operands[1] = x6;
      if (!call_insn_operand (operands[1], E_VOIDmode))
        return -1;
      x5 = XEXP (x2, 1);
      operands[2] = x5;
      if (
#line 2356 "../../gcc/config/riscv/riscv.md"
(SIBLING_CALL_P (insn)))
        return 252; /* sibcall_value_internal */
      if (pnum_clobbers == NULL)
        return -1;
      *pnum_clobbers = 1;
      return 254; /* call_value_internal */

    case UNSPEC_VOLATILE:
      return recog_10 (x1, insn, pnum_clobbers);

    default:
      return -1;
    }
}

int
recog (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pnum_clobbers ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6;
  int res ATTRIBUTE_UNUSED;
  recog_data.insn = NULL;
  switch (GET_CODE (x1))
    {
    case SET:
      return recog_18 (x1, insn, pnum_clobbers);

    case UNSPEC_VOLATILE:
      if (XVECLEN (x1, 0) != 1)
        return -1;
      switch (XINT (x1, 1))
        {
        case 8:
          x2 = XVECEXP (x1, 0, 0);
          if (x2 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
            return -1;
          return 148; /* fence */

        case 9:
          x2 = XVECEXP (x1, 0, 0);
          if (x2 != const_int_rtx[MAX_SAVED_CONST_INT + 0]
              || !
#line 1559 "../../gcc/config/riscv/riscv.md"
(TARGET_ZIFENCEI))
            return -1;
          return 149; /* fence_i */

        case 7:
          x2 = XVECEXP (x1, 0, 0);
          if (x2 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
            return -1;
          return 245; /* blockage */

        case 1:
          x2 = XVECEXP (x1, 0, 0);
          operands[0] = x2;
          if (!const_int_operand (operands[0], E_VOIDmode))
            return -1;
          return 258; /* gpr_restore */

        case 3:
          x2 = XVECEXP (x1, 0, 0);
          operands[0] = x2;
          if (!csr_operand (operands[0], E_SImode)
              || !
#line 2476 "../../gcc/config/riscv/riscv.md"
(TARGET_HARD_FLOAT))
            return -1;
          return 261; /* riscv_fsflags */

        default:
          return -1;
        }

    case PARALLEL:
      switch (XVECLEN (x1, 0))
        {
        case 2:
          res = recog_16 (x1, insn, pnum_clobbers);
          if (res >= 0)
            return res;
          break;

        case 3:
          res = recog_17 (x1, insn, pnum_clobbers);
          if (res >= 0)
            return res;
          break;

        default:
          break;
        }
      if (XVECLEN (x1, 0) < 1)
        return -1;
      operands[1] = x1;
      if (!gpr_save_operation (operands[1], E_VOIDmode))
        return -1;
      x2 = XVECEXP (x1, 0, 0);
      if (GET_CODE (x2) != UNSPEC_VOLATILE
          || XVECLEN (x2, 0) != 1
          || XINT (x2, 1) != 0)
        return -1;
      x3 = XVECEXP (x2, 0, 0);
      operands[0] = x3;
      if (!const_int_operand (operands[0], E_VOIDmode))
        return -1;
      return 257; /* gpr_save */

    case SIMPLE_RETURN:
      return 246; /* simple_return */

    case UNSPEC:
      if (pnum_clobbers == NULL
          || XVECLEN (x1, 0) != 1
          || XINT (x1, 1) != 0)
        return -1;
      x2 = XVECEXP (x1, 0, 0);
      operands[0] = x2;
      switch (GET_MODE (operands[0]))
        {
        case E_SImode:
          if (!register_operand (operands[0], E_SImode)
              || !
#line 2284 "../../gcc/config/riscv/riscv.md"
(! TARGET_64BIT))
            return -1;
          *pnum_clobbers = 1;
          return 248; /* eh_set_lr_si */

        case E_DImode:
          if (!register_operand (operands[0], E_DImode)
              || !
#line 2290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
            return -1;
          *pnum_clobbers = 1;
          return 249; /* eh_set_lr_di */

        default:
          return -1;
        }

    case EH_RETURN:
      return 250; /* eh_return_internal */

    case CALL:
      x4 = XEXP (x1, 0);
      if (GET_CODE (x4) != MEM
          || GET_MODE (x4) != E_SImode)
        return -1;
      x5 = XEXP (x4, 0);
      operands[0] = x5;
      if (!call_insn_operand (operands[0], E_VOIDmode))
        return -1;
      x6 = XEXP (x1, 1);
      operands[1] = x6;
      if (
#line 2333 "../../gcc/config/riscv/riscv.md"
(SIBLING_CALL_P (insn)))
        return 251; /* sibcall_internal */
      if (pnum_clobbers == NULL)
        return -1;
      *pnum_clobbers = 1;
      return 253; /* call_internal */

    case CONST_INT:
      if (XWINT (x1, 0) != 0L)
        return -1;
      return 255; /* nop */

    case TRAP_IF:
      x4 = XEXP (x1, 0);
      if (x4 != const_int_rtx[MAX_SAVED_CONST_INT + 1])
        return -1;
      x6 = XEXP (x1, 1);
      if (x6 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
        return -1;
      return 256; /* trap */

    default:
      return -1;
    }
}

static rtx_insn *
split_1 (rtx x1 ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5;
  rtx_insn *res ATTRIBUTE_UNUSED;
  x2 = XVECEXP (x1, 0, 0);
  x3 = XEXP (x2, 1);
  operands[1] = x3;
  x4 = XVECEXP (x1, 0, 1);
  x5 = XEXP (x4, 0);
  operands[2] = x5;
  switch (GET_MODE (operands[0]))
    {
    case E_SImode:
      if (!register_operand (operands[0], E_SImode)
          || !register_operand (operands[2], E_SImode))
        return NULL;
      if (splittable_const_int_operand (operands[1], E_SImode))
        return gen_split_10 (insn, operands);
      if (!(
#line 1311 "../../gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL, TRUE)) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == SImode)))
        return NULL;
      return gen_split_12 (insn, operands);

    case E_DImode:
      if (!register_operand (operands[0], E_DImode)
          || !register_operand (operands[2], E_DImode))
        return NULL;
      if (splittable_const_int_operand (operands[1], E_DImode)
          && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
        return gen_split_11 (insn, operands);
      if (!(
#line 1311 "../../gcc/config/riscv/riscv.md"
(riscv_split_symbol (operands[2], operands[1], MAX_MACHINE_MODE, NULL, TRUE)) && 
#line 268 "../../gcc/config/riscv/riscv.md"
(Pmode == DImode)))
        return NULL;
      return gen_split_13 (insn, operands);

    default:
      return NULL;
    }
}

rtx_insn *
split_insns (rtx x1 ATTRIBUTE_UNUSED, rtx_insn *insn ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  rtx x10, x11, x12, x13, x14, x15, x16, x17;
  rtx_insn *res ATTRIBUTE_UNUSED;
  recog_data.insn = NULL;
  switch (GET_CODE (x1))
    {
    case SET:
      x2 = XEXP (x1, 0);
      operands[0] = x2;
      x3 = XEXP (x1, 1);
      switch (GET_CODE (x3))
        {
        case ZERO_EXTEND:
          x4 = XEXP (x3, 0);
          operands[1] = x4;
          switch (GET_MODE (operands[0]))
            {
            case E_DImode:
              if (!register_operand (operands[0], E_DImode)
                  || GET_MODE (x3) != E_DImode)
                return NULL;
              switch (GET_MODE (operands[1]))
                {
                case E_SImode:
                  if (!nonimmediate_operand (operands[1], E_SImode)
                      || !(
#line 1064 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1068 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0]))))
                    return NULL;
                  return gen_split_1 (insn, operands);

                case E_HImode:
                  if (!nonimmediate_operand (operands[1], E_HImode)
                      || !(
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1087 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0]))))
                    return NULL;
                  return gen_split_3 (insn, operands);

                default:
                  return NULL;
                }

            case E_SImode:
              if (!register_operand (operands[0], E_SImode)
                  || GET_MODE (x3) != E_SImode
                  || !nonimmediate_operand (operands[1], E_HImode)
                  || !
#line 1087 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0])))
                return NULL;
              return gen_split_2 (insn, operands);

            default:
              return NULL;
            }

        case SIGN_EXTEND:
          x4 = XEXP (x3, 0);
          switch (GET_CODE (x4))
            {
            case REG:
            case SUBREG:
            case MEM:
              operands[1] = x4;
              switch (GET_MODE (operands[0]))
                {
                case E_HImode:
                  switch (pattern30 (x3, E_HImode))
                    {
                    case 0:
                      if (!
#line 1138 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0])))
                        return NULL;
                      return gen_split_4 (insn, operands);

                    case 1:
                      if (!
#line 1138 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0])))
                        return NULL;
                      return gen_split_7 (insn, operands);

                    default:
                      return NULL;
                    }

                case E_SImode:
                  switch (pattern30 (x3, E_SImode))
                    {
                    case 0:
                      if (!
#line 1138 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0])))
                        return NULL;
                      return gen_split_5 (insn, operands);

                    case 1:
                      if (!
#line 1138 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0])))
                        return NULL;
                      return gen_split_8 (insn, operands);

                    default:
                      return NULL;
                    }

                case E_DImode:
                  switch (pattern30 (x3, E_DImode))
                    {
                    case 0:
                      if (!(
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1138 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0]))))
                        return NULL;
                      return gen_split_6 (insn, operands);

                    case 1:
                      if (!(
#line 290 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT) && 
#line 1138 "../../gcc/config/riscv/riscv.md"
( reload_completed
   && REG_P (operands[1])
   && !paradoxical_subreg_p (operands[0]))))
                        return NULL;
                      return gen_split_9 (insn, operands);

                    default:
                      return NULL;
                    }

                default:
                  return NULL;
                }

            case ASHIFT:
              switch (pattern25 (x3))
                {
                case 0:
                  if (!(
#line 1709 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1713 "../../gcc/config/riscv/riscv.md"
( 1)))
                    return NULL;
                  return gen_split_28 (insn, operands);

                case 1:
                  if (!(
#line 1731 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1735 "../../gcc/config/riscv/riscv.md"
( 1)))
                    return NULL;
                  return gen_split_31 (insn, operands);

                default:
                  return NULL;
                }

            case ASHIFTRT:
              switch (pattern25 (x3))
                {
                case 0:
                  if (!(
#line 1709 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1713 "../../gcc/config/riscv/riscv.md"
( 1)))
                    return NULL;
                  return gen_split_29 (insn, operands);

                case 1:
                  if (!(
#line 1731 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1735 "../../gcc/config/riscv/riscv.md"
( 1)))
                    return NULL;
                  return gen_split_32 (insn, operands);

                default:
                  return NULL;
                }

            case LSHIFTRT:
              switch (pattern25 (x3))
                {
                case 0:
                  if (!(
#line 1709 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1713 "../../gcc/config/riscv/riscv.md"
( 1)))
                    return NULL;
                  return gen_split_30 (insn, operands);

                case 1:
                  if (!(
#line 1731 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1735 "../../gcc/config/riscv/riscv.md"
( 1)))
                    return NULL;
                  return gen_split_33 (insn, operands);

                default:
                  return NULL;
                }

            default:
              return NULL;
            }

        case CONST_INT:
        case CONST_WIDE_INT:
        case CONST_POLY_INT:
        case CONST_FIXED:
        case CONST_DOUBLE:
        case CONST_VECTOR:
        case CONST:
        case REG:
        case SUBREG:
        case MEM:
        case LABEL_REF:
        case SYMBOL_REF:
        case HIGH:
          operands[1] = x3;
          switch (GET_MODE (operands[0]))
            {
            case E_DImode:
              if (!nonimmediate_operand (operands[0], E_DImode)
                  || !move_operand (operands[1], E_DImode)
                  || !
#line 1513 "../../gcc/config/riscv/riscv.md"
(reload_completed
   && riscv_split_64bit_move_p (operands[0], operands[1])))
                return NULL;
              return gen_split_14 (insn, operands);

            case E_DFmode:
              if (!nonimmediate_operand (operands[0], E_DFmode)
                  || !move_operand (operands[1], E_DFmode)
                  || !
#line 1513 "../../gcc/config/riscv/riscv.md"
(reload_completed
   && riscv_split_64bit_move_p (operands[0], operands[1])))
                return NULL;
              return gen_split_15 (insn, operands);

            default:
              return NULL;
            }

        case ASHIFT:
          switch (pattern14 (x3))
            {
            case 0:
              if (!(
#line 1598 "../../gcc/config/riscv/riscv.md"
((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
   == GET_MODE_BITSIZE (SImode)-1) && 
#line 1601 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_16 (insn, operands);

            case 1:
              if (!(
#line 1617 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1621 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_19 (insn, operands);

            case 2:
              if (!(
#line 1653 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1) && 
#line 1657 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_22 (insn, operands);

            case 3:
              if (!(
#line 1673 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1) && 
#line 1677 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_25 (insn, operands);

            default:
              return NULL;
            }

        case ASHIFTRT:
          switch (pattern14 (x3))
            {
            case 0:
              if (!(
#line 1598 "../../gcc/config/riscv/riscv.md"
((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
   == GET_MODE_BITSIZE (SImode)-1) && 
#line 1601 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_17 (insn, operands);

            case 1:
              if (!(
#line 1617 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1621 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_20 (insn, operands);

            case 2:
              if (!(
#line 1653 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1) && 
#line 1657 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_23 (insn, operands);

            case 3:
              if (!(
#line 1673 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1) && 
#line 1677 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_26 (insn, operands);

            default:
              return NULL;
            }

        case LSHIFTRT:
          switch (pattern14 (x3))
            {
            case 0:
              if (!(
#line 1598 "../../gcc/config/riscv/riscv.md"
((INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
   == GET_MODE_BITSIZE (SImode)-1) && 
#line 1601 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_18 (insn, operands);

            case 1:
              if (!(
#line 1617 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (SImode)-1))
       == GET_MODE_BITSIZE (SImode)-1) && 
#line 1621 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_21 (insn, operands);

            case 2:
              if (!(
#line 1653 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1) && 
#line 1657 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_24 (insn, operands);

            case 3:
              if (!(
#line 1673 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && (INTVAL (operands[3]) & (GET_MODE_BITSIZE (DImode)-1))
       == GET_MODE_BITSIZE (DImode)-1) && 
#line 1677 "../../gcc/config/riscv/riscv.md"
( 1)))
                return NULL;
              return gen_split_27 (insn, operands);

            default:
              return NULL;
            }

        default:
          return NULL;
        }

    case PARALLEL:
      if (XVECLEN (x1, 0) != 2)
        return NULL;
      x5 = XVECEXP (x1, 0, 1);
      if (GET_CODE (x5) != CLOBBER)
        return NULL;
      x6 = XVECEXP (x1, 0, 0);
      switch (GET_CODE (x6))
        {
        case SET:
          x7 = XEXP (x6, 0);
          operands[0] = x7;
          res = split_1 (x1, insn);
          if (res != NULL_RTX)
            return res;
          x8 = XEXP (x6, 1);
          switch (GET_CODE (x8))
            {
            case AND:
              operands[0] = x7;
              x9 = XEXP (x8, 0);
              switch (GET_CODE (x9))
                {
                case REG:
                case SUBREG:
                  operands[1] = x9;
                  x10 = XEXP (x8, 1);
                  operands[2] = x10;
                  x11 = XEXP (x5, 0);
                  operands[3] = x11;
                  switch (GET_MODE (operands[0]))
                    {
                    case E_SImode:
                      if (!register_operand (operands[0], E_SImode)
                          || GET_MODE (x8) != E_SImode
                          || !register_operand (operands[1], E_SImode)
                          || !p2m1_shift_operand (operands[2], E_SImode)
                          || !register_operand (operands[3], E_SImode))
                        return NULL;
                      return gen_split_34 (insn, operands);

                    case E_DImode:
                      if (!register_operand (operands[0], E_DImode)
                          || GET_MODE (x8) != E_DImode
                          || !register_operand (operands[1], E_DImode)
                          || !register_operand (operands[3], E_DImode))
                        return NULL;
                      if (p2m1_shift_operand (operands[2], E_DImode)
                          && 
#line 264 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                        return gen_split_35 (insn, operands);
                      if (!high_mask_shift_operand (operands[2], E_DImode)
                          || !
#line 1817 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT))
                        return NULL;
                      return gen_split_36 (insn, operands);

                    default:
                      return NULL;
                    }

                case ASHIFT:
                  if (GET_MODE (x9) != E_DImode
                      || !register_operand (operands[0], E_DImode)
                      || GET_MODE (x8) != E_DImode
                      || pattern53 (x1) != 0
                      || !(
#line 1836 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT
   && ((INTVAL (operands[3]) >> INTVAL (operands[2])) == 0xffffffff)) && 
#line 1839 "../../gcc/config/riscv/riscv.md"
( reload_completed)))
                    return NULL;
                  return gen_split_37 (insn, operands);

                default:
                  return NULL;
                }

            case IF_THEN_ELSE:
              if (pattern23 (x6) != 0)
                return NULL;
              x9 = XEXP (x8, 0);
              x12 = XEXP (x9, 0);
              x13 = XEXP (x12, 0);
              operands[2] = x13;
              x10 = XEXP (x8, 1);
              x14 = XEXP (x10, 0);
              operands[1] = x14;
              x11 = XEXP (x5, 0);
              operands[4] = x11;
              x15 = XEXP (x12, 1);
              if (XWINT (x15, 0) == 1L)
                {
                  switch (pattern64 (x12))
                    {
                    case 0:
                      if ((
#line 1952 "../../gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
                        return gen_split_38 (insn, operands);
                      break;

                    case 1:
                      if ((
#line 1952 "../../gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                        return gen_split_39 (insn, operands);
                      break;

                    default:
                      break;
                    }
                }
              x16 = XEXP (x12, 2);
              if (x16 != const_int_rtx[MAX_SAVED_CONST_INT + 0])
                return NULL;
              switch (pattern65 (x12))
                {
                case 0:
                  if (!(
#line 1983 "../../gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(!TARGET_64BIT)))
                    return NULL;
                  return gen_split_40 (insn, operands);

                case 1:
                  if (!(
#line 1983 "../../gcc/config/riscv/riscv.md"
(reload_completed) && 
#line 271 "../../gcc/config/riscv/riscv.md"
(TARGET_64BIT)))
                    return NULL;
                  return gen_split_41 (insn, operands);

                default:
                  return NULL;
                }

            default:
              return NULL;
            }

        case UNSPEC:
          if (XVECLEN (x6, 0) != 1
              || XINT (x6, 1) != 0)
            return NULL;
          x17 = XVECEXP (x6, 0, 0);
          operands[0] = x17;
          if (!register_operand (operands[0], E_VOIDmode))
            return NULL;
          x11 = XEXP (x5, 0);
          operands[1] = x11;
          if (!scratch_operand (operands[1], E_VOIDmode)
              || !
#line 2296 "../../gcc/config/riscv/riscv.md"
(reload_completed))
            return NULL;
          return gen_split_42 (insn, operands);

        default:
          return NULL;
        }

    case EH_RETURN:
      if (!
#line 2307 "../../gcc/config/riscv/riscv.md"
(epilogue_completed))
        return NULL;
      return gen_split_43 (insn, operands);

    default:
      return NULL;
    }
}

rtx_insn *
peephole2_insns (rtx x1 ATTRIBUTE_UNUSED,
	rtx_insn *insn ATTRIBUTE_UNUSED,
	int *pmatch_len_ ATTRIBUTE_UNUSED)
{
  rtx * const operands ATTRIBUTE_UNUSED = &recog_data.operand[0];
  rtx x2, x3, x4, x5, x6, x7, x8, x9;
  rtx x10, x11, x12;
  rtx_insn *res ATTRIBUTE_UNUSED;
  recog_data.insn = NULL;
  if (peep2_current_count < 2
      || peep2_current_count < 3
      || GET_CODE (x1) != SET)
    return NULL;
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) != ASHIFT
      || pattern7 (x1) != 0)
    return NULL;
  x3 = PATTERN (peep2_next_insn (1));
  if (GET_CODE (x3) != SET)
    return NULL;
  x4 = XEXP (x3, 1);
  if (GET_CODE (x4) != LSHIFTRT
      || GET_MODE (x4) != E_DImode)
    return NULL;
  x5 = XEXP (x3, 0);
  operands[3] = x5;
  if (!register_operand (operands[3], E_DImode))
    return NULL;
  x6 = XEXP (x4, 0);
  if (!rtx_equal_p (x6, operands[0]))
    return NULL;
  x7 = XEXP (x4, 1);
  if (!rtx_equal_p (x7, operands[2]))
    return NULL;
  x8 = PATTERN (peep2_next_insn (2));
  if (GET_CODE (x8) != SET)
    return NULL;
  x9 = XEXP (x8, 1);
  if (GET_CODE (x9) != ASHIFT
      || GET_MODE (x9) != E_DImode)
    return NULL;
  x10 = XEXP (x8, 0);
  operands[4] = x10;
  if (!register_operand (operands[4], E_DImode))
    return NULL;
  x11 = XEXP (x9, 1);
  operands[5] = x11;
  if (!const_int_operand (operands[5], E_VOIDmode))
    return NULL;
  x12 = XEXP (x9, 0);
  if (!rtx_equal_p (x12, operands[3])
      || !
#line 30 "../../gcc/config/riscv/peephole.md"
(TARGET_64BIT
   && INTVAL (operands[5]) < INTVAL (operands[2])
   && (REGNO (operands[3]) == REGNO (operands[4])
       || peep2_reg_dead_p (3, operands[3]))))
    return NULL;
  *pmatch_len_ = 2;
  return gen_peephole2_1 (insn, operands);
}
