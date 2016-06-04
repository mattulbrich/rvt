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
unsigned char  rvs0_Loop_bubble_sort_for1(int  *a, int  sz, int  *rvp_i);
unsigned char  chk0_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j);
unsigned char  rvs0_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j);
void  __CPROVER_assume(_Bool  rv_arg_6);

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
unsigned char  rvs1_Loop_bubble_sort_for1(int  *a, int  sz, int  *rvp_i);
unsigned char  chk1_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j);
unsigned char  rvs1_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j);
void  __CPROVER_assume(_Bool  rv_arg_7);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
unsigned char  rvs0_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j);
unsigned char  chk0_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j)
{
  int  t;

  if (!(*rvp_j < i))
    return 0;
  {
    __CPROVER_assume(*rvp_j < 4 && *rvp_j >= 0);
    if (a[*rvp_j] < a[*rvp_j + 1])
    {
      t = a[*rvp_j];
      a[*rvp_j] = a[*rvp_j + 1];
      a[*rvp_j + 1] = t;
      a[*rvp_j] = a[*rvp_j];
    }

  }

  (*rvp_j)++;
  {
    return rvs0_Loop_bubble_sort_for1_for1(a,i,rvp_j);
  }

  return 0;
}


/*** Functions side 1: ***/
unsigned char  rvs1_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j);
unsigned char  chk1_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j)
{
  int  t;

  if (!(*rvp_j < i))
    return 0;
  {
    __CPROVER_assume(*rvp_j < 4 && *rvp_j >= 0);
    if (*(a + *rvp_j) < *(a + *rvp_j + 1))
    {
      t = *(a + *rvp_j);
      *(a + *rvp_j) = *(a + *rvp_j + 1);
      *(a + *rvp_j + 1) = t;
    }

    *rvp_j = *rvp_j + 1;
  }

  {
    return rvs1_Loop_bubble_sort_for1_for1(a,i,rvp_j);
  }

  return 0;
}


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
  int  rv_D0_0;	/* Generated by:  RVUFGen::gen_side0_cbmc_uf(621)(626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  int  rv_D1_0;	/* Generated by:  RVUFGen::gen_side0_cbmc_uf(621)(626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/

  /* Protecting pointers from being NULL-dereferenced: */
  if (a== 0) {
  a = &rv_D0_0;	/* Generated by:  RVUFGen::gen_side0_cbmc_uf(621)(626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  }
  if (rvp_j== 0) {
  rvp_j = &rv_D1_0;	/* Generated by:  RVUFGen::gen_side0_cbmc_uf(621)(626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
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
__CPROVER_assume( (!(i <= 2147483647 && -(i) <= 2147483648 ) || ( retval <= 255 && -(retval) <= 0)));
  return retval;
}


  /* CBMC-UF side 1: */ 
unsigned char  rvs1_Loop_bubble_sort_for1_for1(int  *a, int  i, int  *rvp_j)
{
  unsigned char  retval;

  /* Declarations: */
  int  rv_D2_0;	/* Generated by:  RVUFGen::gen_side1_cbmc_uf(621)(626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  int  rv_D3_0;	/* Generated by:  RVUFGen::gen_side1_cbmc_uf(621)(626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/

  /* Protecting pointers from being NULL-dereferenced: */
  if (a== 0) {
  a = &rv_D2_0;	/* Generated by:  RVUFGen::gen_side1_cbmc_uf(621)(626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  }
  if (rvp_j== 0) {
  rvp_j = &rv_D3_0;	/* Generated by:  RVUFGen::gen_side1_cbmc_uf(621)(626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
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
__CPROVER_assume( (!(i <= 2147483647 && -(i) <= 2147483648 ) || ( retval <= 255 && -(retval) <= 0)));
  return retval;
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  unsigned char  retval0;	/* Generated by:  RVTemp::gen_retval_declarations/ c:\newrvt\rv_temps.cpp:269*/
  unsigned char  retval1;	/* Generated by:  RVTemp::gen_retval_declarations/ c:\newrvt\rv_temps.cpp:269*/
  int  rvs0_a[5];	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  rvs1_a[5];	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  rvs0_i;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  rvs1_i;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  *rvs0_rvp_j;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  *rvs1_rvp_j;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  rv_D4_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  int  rv_D5_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/

  /* output: */
  /* output: */
  /* output: */
  int  rv_nd_RV_ARR_OUT_s0_a_0_0[5];
  int  rv_nd_RV_ARR_OUT_s1_a_0_0[5];
  __CPROVER_array_copy(RV_ARR_OUT_s0_a_0_0,  rv_nd_RV_ARR_OUT_s0_a_0_0);
  __CPROVER_array_copy(RV_ARR_OUT_s1_a_0_0,  rv_nd_RV_ARR_OUT_s1_a_0_0);
  /* Allocations for side 0: */
  rvs0_rvp_j = &rv_D4_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  /* Allocations for side 1: */
  rvs1_rvp_j = &rv_D5_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/

  /* Assume input args are equal: */ 
  RVT_COPY_ARRAY(rvs0_a,rvs1_a, 5);	/* Generated by:  RVMainGen::gen_args_equality(621)(626)(392)(302)/ c:\newrvt\rv_temps.cpp:368*/
  rvs0_i = rvs1_i;	/* Generated by:  RVMainGen::gen_args_equality(621)(626)(392)(302)(621)(626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  *rvs0_rvp_j = *rvs1_rvp_j;	/* Generated by:  RVMainGen::gen_args_equality(621)(626)(392)(302)(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/

  /* run each side's main() */
  retval0 = chk0_Loop_bubble_sort_for1_for1(rvs0_a, rvs0_i, rvs0_rvp_j);
  retval1 = chk1_Loop_bubble_sort_for1_for1(rvs1_a, rvs1_i, rvs1_rvp_j);
  /* Assertions: */

  /* Compare return values: */ 
  assert( retval0 == retval1 );	/* Generated by:  RVMainGen::gen_main(621)(626)(392)(322)/ c:\newrvt\rv_temps.cpp:352*/

  /* Compare output args: */ 
  RVT_ASSERT_EQ_ARRAY(rvs0_a,rvs1_a,5 );	/* Generated by:  RVMainGen::gen_args_equality(621)(626)(392)(316)/ c:\newrvt\rv_temps.cpp:404*/
  assert( *rvs0_rvp_j == *rvs1_rvp_j );	/* Generated by:  RVMainGen::gen_args_equality(621)(626)(392)(316)(621)/ RVGen::protect_pointer [op=6](626)(392)(322)/ c:\newrvt\rv_temps.cpp:352*/


  return 0;
}
