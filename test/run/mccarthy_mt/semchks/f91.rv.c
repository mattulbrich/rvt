#include "rv_declarations.h"

/*** global declarations side 0: ***/
float  rvs0_rv_mult(float  x, float  y);
float  rvs0_rv_div(float  x, float  y);
int  rvs0_rv_mod(int  x, int  y);
int  chk0_f91(int  a);
int  rvs0_main();
int  rvs0_f91(int  a);
void  __CPROVER_assume(_Bool  rv_arg_2);

/*** global declarations side 1: ***/
float  rvs1_rv_mult(float  x, float  y);
float  rvs1_rv_div(float  x, float  y);
int  rvs1_rv_mod(int  x, int  y);
int  chk1_f91(int  x);
int  rvs1_main();
int  rvs1_f91(int  x);
void  __CPROVER_assume(_Bool  rv_arg_3);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
int  rvs0_f91(int  a);
int  chk0_f91(int  a)
{
  if (a > 100)
    return a - 10;
  return rvs0_f91(rvs0_f91(a + 11));
}


/*** Functions side 1: ***/
int  rvs1_f91(int  x);
int  chk1_f91(int  x)
{
  if (x < 101)
    return rvs1_f91(rvs1_f91(11 + x));
  return x - 10;
}


typedef struct rv_UF_f91_struct_tag {
  int  in_a;	/* Generated by:  gen_uf_item_decl(111)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  out_retval;	/* Generated by:  gen_uf_array(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  _Bool reach_equiv_flag;
} rv_UF_f91_struct;
#define rv_UF_K_f91 2 /* determined by RVT */
rv_UF_f91_struct rv_UF_f91_array[rv_UF_K_f91];
int rv_UF_f91_count[2] = {0,0};


 /*** uninterpreted function side 0: ***/ 
  /* Declarations: */


int  rvs0_f91(int  a)
{
  int  retval;

  /* save values of input arguments: */
  rv_UF_f91_array[rv_UF_f91_count[0]].in_a = a;	/* Generated by:  gen_side0_uf(608)(613)(379)(293)/ rv_temps.cpp:362*/
  /* save values of input globals: */

  /* generate and save values of output arguments and globals: */
  rv_UF_f91_array[rv_UF_f91_count[0]].out_retval = retval = (int )nondet_long();	/* Generated by:  gen_side0_uf(608)(613)(379)(293)(608)(613)(379)(265)/ rv_temps.cpp:412*/
  rv_UF_f91_count[0]++;

  return retval;
}


/*** uninterpreted function side 1: ***/ 
int  rvs1_f91(int  x)
{
  int  retval;

  _Bool found = 0;
  _Bool equal = 1;
  int found_ind = -1;
  int rv_uf_ind = rv_UF_f91_count[0]-1;
  for(; rv_uf_ind >= 0; rv_uf_ind--) {
    equal = (rv_UF_f91_array[rv_uf_ind].in_a == x);	/* Generated by:  gen_side1_uf(608)(613)(379)(273)/ rv_temps.cpp:419*/
    if( equal ) { 
      found = 1;
      found_ind = rv_uf_ind;
      rv_UF_f91_array[rv_uf_ind].reach_equiv_flag = 1;
    }
  }

  if( found ) /* input values were found among the saved values */
  {
   /* Sides 0 and 1 are partially equivalent.
    * Returning the results of side 0: */
  retval = rv_UF_f91_array[found_ind].out_retval;	/* Generated by:  gen_input_found_case(608)(613)(379)(284)/ rv_temps.cpp:362*/

  } else {

    /* Assert reach-equivalence: side 0 and 1 inputs are equal.*/
    assert( 0 );

  }
  rv_UF_f91_count[1]++;

  return retval;
}






void rv_init()
{
}


void rv_check()
{
  /* check reach-equivalence of the inputs for each uninterpreted function: */
  int i;

  /* checking reach-equivalence of all the inputs of array rv_UF_f91_array : */
  for (i = rv_UF_f91_count[0] - 1; i >= 0; --i)
    assert( rv_UF_f91_array[i].reach_equiv_flag );
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  int  retval0;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  int  retval1;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  int  rvs0_a;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  rvs1_x;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/


  /* output: */
  /* Allocations for side 0: */
  /* Allocations for side 1: */

  rv_init();

  /* Assume input args are equal: */ 
  rvs0_a = rvs1_x;	/* Generated by:  gen_args_equality(608)(613)(379)(293)/ rv_temps.cpp:362*/

  /* run each side's main() */
  retval0 = chk0_f91(rvs0_a);
  retval1 = chk1_f91(rvs1_x);

  rv_check();

  return 0;
}

