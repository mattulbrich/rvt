#include "rv_declarations.h"

/*** global declarations side 0: ***/
float  rvs0_rv_mult(float  x, float  y);
float  rvs0_rv_div(float  x, float  y);
int  rvs0_rv_mod(int  x, int  y);
int  chk0_A(int  m, int  n);
int  rvs0_main();
int  rvs0_A(int  m, int  n);
void  __CPROVER_assume(_Bool  rv_arg_2);

/*** global declarations side 1: ***/
float  rvs1_rv_mult(float  x, float  y);
float  rvs1_rv_div(float  x, float  y);
int  rvs1_rv_mod(int  x, int  y);
int  chk1_A(int  m, int  n);
int  rvs1_main();
int  rvs1_A(int  m, int  n);
void  __CPROVER_assume(_Bool  rv_arg_3);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
int  rvs0_A(int  m, int  n);
int  chk0_A(int  m, int  n)
{
  if (m == 0)
    return n + 1;
  if (m > 0 && n == 0)
    return rvs0_A(m - 1,1);
  return rvs0_A(m - 1,rvs0_A(m,n - 1));
}


/*** Functions side 1: ***/
int  rvs1_A(int  m, int  n);
int  chk1_A(int  m, int  n)
{
  if (m > 0 && n == 0)
    return rvs1_A(m - 1,1);
  if (m == 0)
    return n + 1;
  return rvs1_A(m - 1,rvs1_A(m,n - 1));
}


typedef struct rv_UF_A_struct_tag {
  int  in_m;	/* Generated by:  gen_uf_item_decl(111)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  in_n;	/* Generated by:  gen_uf_item_decl(111)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  out_retval;	/* Generated by:  gen_uf_array(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  _Bool reach_equiv_flag;
} rv_UF_A_struct;
#define rv_UF_K_A 2 /* determined by RVT */
rv_UF_A_struct rv_UF_A_array[rv_UF_K_A];
int rv_UF_A_count[2] = {0,0};


 /*** uninterpreted function side 0: ***/ 
  /* Declarations: */


int  rvs0_A(int  m, int  n)
{
  int  retval;

  /* save values of input arguments: */
  rv_UF_A_array[rv_UF_A_count[0]].in_m = m;	/* Generated by:  gen_side0_uf(608)(613)(379)(293)/ rv_temps.cpp:362*/
  rv_UF_A_array[rv_UF_A_count[0]].in_n = n;	/* Generated by:  gen_side0_uf(608)(613)(379)(293)(608)(613)(379)(293)/ rv_temps.cpp:362*/
  /* save values of input globals: */

  /* generate and save values of output arguments and globals: */
  rv_UF_A_array[rv_UF_A_count[0]].out_retval = retval = (int )nondet_long();	/* Generated by:  gen_side0_uf(608)(613)(379)(293)(608)(613)(379)(293)(608)(613)(379)(265)/ rv_temps.cpp:412*/
  rv_UF_A_count[0]++;

  return retval;
}


/*** uninterpreted function side 1: ***/ 
int  rvs1_A(int  m, int  n)
{
  int  retval;

  _Bool found = 0;
  _Bool equal = 1;
  int found_ind = -1;
  int rv_uf_ind = rv_UF_A_count[0]-1;
  for(; rv_uf_ind >= 0; rv_uf_ind--) {
    equal = (rv_UF_A_array[rv_uf_ind].in_m == m);	/* Generated by:  gen_side1_uf(608)(613)(379)(273)/ rv_temps.cpp:419*/
    equal = equal && (rv_UF_A_array[rv_uf_ind].in_n == n);	/* Generated by:  gen_side1_uf(608)(613)(379)(273)(608)(613)(379)(273)/ rv_temps.cpp:419*/
    if( equal ) { 
      found = 1;
      found_ind = rv_uf_ind;
      rv_UF_A_array[rv_uf_ind].reach_equiv_flag = 1;
    }
  }

  if( found ) /* input values were found among the saved values */
  {
   /* Sides 0 and 1 are partially equivalent.
    * Returning the results of side 0: */
  retval = rv_UF_A_array[found_ind].out_retval;	/* Generated by:  gen_input_found_case(608)(613)(379)(284)/ rv_temps.cpp:362*/

  } else {

    /* Assert reach-equivalence: side 0 and 1 inputs are equal.*/
    assert( 0 );

  }
  rv_UF_A_count[1]++;

  return retval;
}






void rv_init()
{
}


void rv_check()
{
  /* check reach-equivalence of the inputs for each uninterpreted function: */
  int i;

  /* checking reach-equivalence of all the inputs of array rv_UF_A_array : */
  for (i = rv_UF_A_count[0] - 1; i >= 0; --i)
    assert( rv_UF_A_array[i].reach_equiv_flag );
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  int  retval0;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  int  retval1;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  int  rvs0_m;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  rvs1_m;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  rvs0_n;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  rvs1_n;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/


  /* output: */
  /* output: */
  /* Allocations for side 0: */
  /* Allocations for side 1: */

  rv_init();

  /* Assume input args are equal: */ 
  rvs0_m = rvs1_m;	/* Generated by:  gen_args_equality(608)(613)(379)(293)/ rv_temps.cpp:362*/
  rvs0_n = rvs1_n;	/* Generated by:  gen_args_equality(608)(613)(379)(293)(608)(613)(379)(293)/ rv_temps.cpp:362*/

  /* run each side's main() */
  retval0 = chk0_A(rvs0_m, rvs0_n);
  retval1 = chk1_A(rvs1_m, rvs1_n);

  rv_check();

  return 0;
}

