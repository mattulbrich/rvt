#include "rv_declarations.h"

/*** global declarations side 0: ***/
float  rvs0_rv_mult(float  x, float  y);
float  rvs0_rv_div(float  x, float  y);
int  rvs0_rv_mod(int  x, int  y);
void  __CPROVER_assume(_Bool  rv_arg_0);
void  assert(_Bool  rv_arg_1);
void  rvs0_bubble_sort(int  *a, int  sz);
int  rvs0_a[5];
void  rvs0_bubble_sort(int  *a, int  sz);
int  rvs0_init_array(int  n);
int  rvs0_main();
unsigned char  chk0_Loop_bubble_sort_for1(int  *a, int  sz, int  *rvp_i);
unsigned char  rvs0_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j);
unsigned char  rvs0_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j);
void  __CPROVER_assume(_Bool  rv_arg_8);

/*** global declarations side 1: ***/
float  rvs1_rv_mult(float  x, float  y);
float  rvs1_rv_div(float  x, float  y);
int  rvs1_rv_mod(int  x, int  y);
void  __CPROVER_assume(_Bool  rv_arg_2);
void  assert(_Bool  rv_arg_3);
void  rvs1_bubble_sort(int  *a, int  sz);
int  rvs1_a[5];
void  rvs1_bubble_sort(int  *a, int  sz);
int  rvs1_init_array(int  n);
int  rvs1_main();
unsigned char  chk1_Loop_bubble_sort_for1(int  *a, int  sz, int  *rvp_i);
unsigned char  rvs1_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j);
unsigned char  rvs1_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j);
void  __CPROVER_assume(_Bool  rv_arg_9);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
unsigned char  chk0_Loop_bubble_sort_for1(int  *a, int  sz, int  *rvp_i)
{
  int  j;
  int  t;

  if (!(*rvp_i > 0))
    return 0;
  {
    {
      unsigned char  rv_ltc_val;

      j = 0;
      rv_ltc_val = rvs0_Loop_bubble_sort_for1_for1(a,*rvp_i,&j);
    }

  }

  (*rvp_i)--;
  return 0;
}


/*** Functions side 1: ***/
unsigned char  chk1_Loop_bubble_sort_for1(int  *a, int  sz, int  *rvp_i)
{
  int  j;
  int  t;

  if (!(*rvp_i > 0))
    return 0;
  {
    {
      unsigned char  rv_ltc_val;

      j = 0;
      rv_ltc_val = rvs1_Loop_bubble_sort_for1_for1(a,*rvp_i,&j);
    }

    *rvp_i = *rvp_i - 1;
  }

  return 0;
}


/* Implementations of the uninterpreted functions: */

  /* Declarations of the CBMC uninterpreted functions */
  /* Globals for saving input arrays: */
int  RV_ARR_SAVE_a_0[5];

int  __CPROVER_uninterpreted_a(int , int , int );
int  __CPROVER_uninterpreted_rvp_j(int , int , int );
unsigned char  __CPROVER_uninterpreted_retval(int , int , int );
  /* For each array X side X record, an output array. */
int  RV_ARR_OUT_s0_a_0_0[5];
int  RV_ARR_OUT_s1_a_0_0[5];


  /* CBMC-UF side 0: */ 
unsigned char  rvs0_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j)
{
  unsigned char  retval;

  /* Declarations: */
  int  rv_D2_0;	/* Generated by:  gen_side0_cbmc_uf(608)(613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  int  rv_D3_0;	/* Generated by:  gen_side0_cbmc_uf(608)(613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/

  /* Protecting pointers from being NULL-dereferenced: */
  if (a== 0) {
  a = &rv_D2_0;	/* Generated by:  gen_side0_cbmc_uf(608)(613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }
  if (rvp_j== 0) {
  rvp_j = &rv_D3_0;	/* Generated by:  gen_side0_cbmc_uf(608)(613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }

  static unsigned char rv_call_counter = 0;
  int *RV_ARR_P_s0_a;
  int *RV_ARR_P_s1_a;
  switch(rv_call_counter) {
    case 0:RV_ARR_P_s0_a = RV_ARR_OUT_s0_a_0_0; RV_ARR_P_s1_a = RV_ARR_OUT_s1_a_0_0; RVT_COPY_ARRAY(RV_ARR_SAVE_a_0, a, 5); break;
    default: assert(0);
  }
  rv_call_counter++;
  /* Each output is assigned a UF:*/
  if (__CPROVER_uninterpreted_a(1, i, *rvp_j))
  {RVT_COPY_ARRAY(a, RV_ARR_P_s0_a, 5);}
  else
  {RVT_COPY_ARRAY(a, RV_ARR_P_s1_a, 5);}
  *rvp_j= __CPROVER_uninterpreted_rvp_j(1, i, *rvp_j);
  retval= __CPROVER_uninterpreted_retval(1, i, *rvp_j);

  return retval;
}


  /* CBMC-UF side 1: */ 
unsigned char  rvs1_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j)
{
  unsigned char  retval;

  /* Declarations: */
  int  rv_D4_0;	/* Generated by:  gen_side1_cbmc_uf(608)(613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  int  rv_D5_0;	/* Generated by:  gen_side1_cbmc_uf(608)(613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/

  /* Protecting pointers from being NULL-dereferenced: */
  if (a== 0) {
  a = &rv_D4_0;	/* Generated by:  gen_side1_cbmc_uf(608)(613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }
  if (rvp_j== 0) {
  rvp_j = &rv_D5_0;	/* Generated by:  gen_side1_cbmc_uf(608)(613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }

  _Bool RV_ARR_EQ_a;
  static unsigned char rv_call_counter = 0;
  int *RV_ARR_P_s0_a;
  int *RV_ARR_P_s1_a;
  switch(rv_call_counter) {
    case 0:RV_ARR_P_s0_a = RV_ARR_OUT_s0_a_0_0; RV_ARR_P_s1_a = RV_ARR_OUT_s1_a_0_0;   RV_ARR_EQ_a = __CPROVER_array_equal(a,RV_ARR_SAVE_a_0);  break;
    default: assert(0);
  }
  rv_call_counter++;
  /* Each output is assigned a UF:*/
  if (__CPROVER_uninterpreted_a(RV_ARR_EQ_a, i, *rvp_j))
  {RVT_COPY_ARRAY(a, RV_ARR_P_s0_a, 5);}
  else
  {RVT_COPY_ARRAY(a, RV_ARR_P_s1_a, 5);}
  *rvp_j= __CPROVER_uninterpreted_rvp_j(RV_ARR_EQ_a, i, *rvp_j);
  retval= __CPROVER_uninterpreted_retval(RV_ARR_EQ_a, i, *rvp_j);

  return retval;
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  unsigned char  retval0;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  unsigned char  retval1;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  int  rvs0_a[5];	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  rvs1_a[5];	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  rvs0_sz;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  rvs1_sz;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  *rvs0_rvp_i;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  *rvs1_rvp_i;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  rv_D6_0;	/* Generated by:  gen_arg_alloc_side(601)(601)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  int  rv_D7_0;	/* Generated by:  gen_arg_alloc_side(601)(601)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/

  /* output: */
  /* output: */
  /* output: */
  int  rv_nd_RV_ARR_OUT_s0_a_0_0[5];
  int  rv_nd_RV_ARR_OUT_s1_a_0_0[5];
  __CPROVER_array_copy(RV_ARR_OUT_s0_a_0_0,  rv_nd_RV_ARR_OUT_s0_a_0_0);
  __CPROVER_array_copy(RV_ARR_OUT_s1_a_0_0,  rv_nd_RV_ARR_OUT_s1_a_0_0);
  /* Allocations for side 0: */
  rvs0_rvp_i = &rv_D6_0;	/* Generated by:  gen_arg_alloc_side(601)(601)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  /* Allocations for side 1: */
  rvs1_rvp_i = &rv_D7_0;	/* Generated by:  gen_arg_alloc_side(601)(601)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/

  /* Assume input args are equal: */ 
  RVT_COPY_ARRAY(rvs0_a,rvs1_a, 5);	/* Generated by:  gen_args_equality(608)(613)(379)(289)/ rv_temps.cpp:368*/
  rvs0_sz = rvs1_sz;	/* Generated by:  gen_args_equality(608)(613)(379)(289)(608)(613)(379)(293)/ rv_temps.cpp:362*/
  *rvs0_rvp_i = *rvs1_rvp_i;	/* Generated by:  gen_args_equality(608)(613)(379)(289)(608)(613)(379)(293)(608)/ protect_pointer [op=4](613)(379)(293)/ rv_temps.cpp:362*/

  /* run each side's main() */
  retval0 = chk0_Loop_bubble_sort_for1(rvs0_a, rvs0_sz, rvs0_rvp_i);
  retval1 = chk1_Loop_bubble_sort_for1(rvs1_a, rvs1_sz, rvs1_rvp_i);
  /* Assertions: */

  /* Compare return values: */ 
  assert( retval0 == retval1 );	/* Generated by:  gen_main(608)(613)(379)(309)/ rv_temps.cpp:352*/

  /* Compare output args: */ 
  RVT_ASSERT_EQ_ARRAY(rvs0_a,rvs1_a,5 );	/* Generated by:  gen_args_equality(608)(613)(379)(303)/ rv_temps.cpp:404*/
  assert( *rvs0_rvp_i == *rvs1_rvp_i );	/* Generated by:  gen_args_equality(608)(613)(379)(303)(608)/ protect_pointer [op=6](613)(379)(309)/ rv_temps.cpp:352*/


  return 0;
}
