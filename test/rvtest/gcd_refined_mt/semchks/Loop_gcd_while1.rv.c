#include "rv_declarations.h"
#define RV_MAX_INPUTS 2
#include "rv_inputs.c"
/*** global declarations side 0: ***/
int  rvs0_rv_getint();
char  rvs0_rv_getchar();
void  rvs0_swap(char  *a, char  *b);
char  rvs0_gcd(char  a, char  b);
void  rvs0_simplify(char  *numerator_p, char  *denominator_p);
char  rvs0_main();
unsigned char  chk0_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
unsigned char  rvs0_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
void  __CPROVER_assume(_Bool  rv_arg_2);

/*** global declarations side 1: ***/
int  rvs1_rv_getint();
char  rvs1_rv_getchar();
void  rvs1_swap(char  *a, char  *b);
char  rvs1_gcd(char  a, char  b);
void  rvs1_simplify(char  *numerator_p, char  *denominator_p);
char  rvs1_main();
unsigned char  chk1_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
unsigned char  rvs1_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
void  __CPROVER_assume(_Bool  rv_arg_3);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
void  rvs0_swap(char  *a, char  *b)
{
  char  tmp = *a;

  *a = *b;
  *b = tmp;
}

unsigned char  rvs0_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
unsigned char  chk0_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval)
{
  if (!(*rvp_a != 0))
    return 0;
  {
    *rvp_b = *rvp_b % *rvp_a;
    rvs0_swap(&*rvp_a,&*rvp_b);
  }

  {
    return rvs0_Loop_gcd_while1(rvp_a,rvp_b,rvp_rvretval);
  }

  return 0;
}


/*** Functions side 1: ***/
void  rvs1_swap(char  *a, char  *b)
{
  char  tmp = *a;

  *a = *b;
  *b = tmp;
}

unsigned char  rvs1_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
unsigned char  chk1_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval)
{
  if (!(*rvp_a != 0))
    return 0;
  {
    *rvp_b = *rvp_b % *rvp_a;
    rvs1_swap(&*rvp_b,&*rvp_a);
    *rvp_a = *rvp_a;
  }

  {
    return rvs1_Loop_gcd_while1(rvp_a,rvp_b,rvp_rvretval);
  }

  return 0;
}


typedef struct rv_UF_Loop_gcd_while1_struct_tag {
  char  *in_rvp_a;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  char  *out_rvp_a;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  char  *in_rvp_b;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  char  *out_rvp_b;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  char  *in_rvp_rvretval;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  unsigned char  out_retval;	/* Generated by:  RVUFGen::gen_uf_array(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  _Bool reach_equiv_flag;
} rv_UF_Loop_gcd_while1_struct;
#define rv_UF_K_Loop_gcd_while1 5
rv_UF_Loop_gcd_while1_struct rv_UF_Loop_gcd_while1_array[rv_UF_K_Loop_gcd_while1];
int rv_UF_Loop_gcd_while1_count[2] = {0,0};


 /*** uninterpreted function side 0: ***/ 
  /* Declarations: */


unsigned char  rvs0_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval)
{
  unsigned char  retval;

  /* save values of input arguments: */
  *rv_UF_Loop_gcd_while1_array[rv_UF_Loop_gcd_while1_count[0]]. = *rvp_a;	/* Generated by:  RVUFGen::gen_side0_uf(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  *rv_UF_Loop_gcd_while1_array[rv_UF_Loop_gcd_while1_count[0]].in_rvp_b = *rvp_b;	/* Generated by:  RVUFGen::gen_side0_uf(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  *rv_UF_Loop_gcd_while1_array[rv_UF_Loop_gcd_while1_count[0]].in_rvp_rvretval = *rvp_rvretval;	/* Generated by:  RVUFGen::gen_side0_uf(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  /* save values of input globals: */

  /* generate and save values of output arguments and globals: */
  *rv_UF_Loop_gcd_while1_array[rv_UF_Loop_gcd_while1_count[0]]. = *rvp_a = (char )nondet_int();	/* Generated by:  RVUFGen::gen_side0_uf(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)/ c:\newrvt\rv_temps.cpp:412*/
  *rv_UF_Loop_gcd_while1_array[rv_UF_Loop_gcd_while1_count[0]].out_rvp_b = *rvp_b = (char )nondet_int();	/* Generated by:  RVUFGen::gen_side0_uf(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)/ c:\newrvt\rv_temps.cpp:412*/
  rv_UF_Loop_gcd_while1_array[rv_UF_Loop_gcd_while1_count[0]]. = retval = (unsigned char )nondet_int();	/* Generated by:  RVUFGen::gen_side0_uf(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)(621)(626)(392)(276)/ c:\newrvt\rv_temps.cpp:412*/
  rv_UF_Loop_gcd_while1_count[0]++;

  return retval;
}


/*** uninterpreted function side 1: ***/ 
unsigned char  rvs1_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval)
{
  unsigned char  retval;

  _Bool found = 0;
  _Bool equal = 1;
  int found_ind = -1;
  int rv_uf_ind = rv_UF_Loop_gcd_while1_count[0]-1;
  for(; rv_uf_ind >= 0; rv_uf_ind--) {
    equal = (*rv_UF_Loop_gcd_while1_array[rv_uf_ind]. == *rvp_a);	/* Generated by:  RVUFGen::gen_side1_uf(621)/ RVGen::protect_pointer [op=3](626)(392)(285)/ c:\newrvt\rv_temps.cpp:427*/
    equal = equal && (*rv_UF_Loop_gcd_while1_array[rv_uf_ind].in_rvp_b == *rvp_b);	/* Generated by:  RVUFGen::gen_side1_uf(621)/ RVGen::protect_pointer [op=3](626)(392)(285)(621)/ RVGen::protect_pointer [op=3](626)(392)(285)/ c:\newrvt\rv_temps.cpp:427*/
    equal = equal && (*rv_UF_Loop_gcd_while1_array[rv_uf_ind].in_rvp_rvretval == *rvp_rvretval);	/* Generated by:  RVUFGen::gen_side1_uf(621)/ RVGen::protect_pointer [op=3](626)(392)(285)(621)/ RVGen::protect_pointer [op=3](626)(392)(285)(621)/ RVGen::protect_pointer [op=3](626)(392)(285)/ c:\newrvt\rv_temps.cpp:427*/
    if( equal ) { 
      found = 1;
      found_ind = rv_uf_ind;
		      rv_UF_Loop_gcd_while1_array[rv_uf_ind].reach_equiv_flag = 1;
    }
		equal = 1;
  }

  if( found ) /* input values were found among the saved values */
  {
   /* Sides 0 and 1 are partially equivalent.
    * Returning the results of side 0: */
  *rvp_a = *rv_UF_Loop_gcd_while1_array[found_ind].;	/* Generated by:  RVUFGen::gen_input_found_case(621)/ RVGen::protect_pointer [op=5](626)(392)(296)/ c:\newrvt\rv_temps.cpp:362*/
  *rvp_b = *rv_UF_Loop_gcd_while1_array[found_ind].out_rvp_b;	/* Generated by:  RVUFGen::gen_input_found_case(621)/ RVGen::protect_pointer [op=5](626)(392)(296)(621)/ RVGen::protect_pointer [op=5](626)(392)(296)/ c:\newrvt\rv_temps.cpp:362*/
  retval = rv_UF_Loop_gcd_while1_array[found_ind].;	/* Generated by:  RVUFGen::gen_input_found_case(621)/ RVGen::protect_pointer [op=5](626)(392)(296)(621)/ RVGen::protect_pointer [op=5](626)(392)(296)(621)(626)(392)(296)/ c:\newrvt\rv_temps.cpp:362*/

  } else {

    /* Assert reach-equivalence: side 0 and 1 inputs are equal.*/
    assert( 0 );

  }
  rv_UF_Loop_gcd_while1_count[1]++;

  return retval;
}

void rvt_token_initialize_mutual_termination_tokens_Loop_gcd_while1(){
	int rvt_token_i = 0;
		for (rvt_token_i = 0 ; rvt_token_i < rv_UF_K_Loop_gcd_while1 ; rvt_token_i++){
			rvt_token_Loop_gcd_while1_call_mark_array0[rvt_token_i] = 0;
			rvt_token_Loop_gcd_while1_call_mark_array1[rvt_token_i] = 0;
		}
		rvt_token_Loop_gcd_while1_count = 0;
		rvt_token_Loop_gcd_while1_first_call_to_uf_flag = 0;

}





void rv_init()
{
}


void rv_check()
{
  /* check reach-equivalence of the inputs for each uninterpreted function: */
  int i;

  /* checking reach-equivalence of all the inputs of array rv_UF_Loop_gcd_while1_array : */
  for (i = rv_UF_Loop_gcd_while1_count[0] - 1; i >= 0; --i)
    assert( rv_UF_Loop_gcd_while1_array[i].reach_equiv_flag );
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  unsigned char  retval0;	/* Generated by:  RVTemp::gen_retval_declarations/ c:\newrvt\rv_temps.cpp:269*/
  unsigned char  retval1;	/* Generated by:  RVTemp::gen_retval_declarations/ c:\newrvt\rv_temps.cpp:269*/
  char  *rvs0_rvp_a;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  char  *rvs1_rvp_a;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  char  *rvs0_rvp_b;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  char  *rvs1_rvp_b;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  char  *rvs0_rvp_rvretval;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  char  *rvs1_rvp_rvretval;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  char  rv_D0_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  char  rv_D1_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  char  rv_D2_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  char  rv_D3_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  char  rv_D4_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  char  rv_D5_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/


  /* output: */
  /* output: */
  /* output: */
  /* Allocations for side 0: */
  rvs0_rvp_a = &rv_D0_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  rvs0_rvp_b = &rv_D1_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  rvs0_rvp_rvretval = &rv_D2_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  /* Allocations for side 1: */
  rvs1_rvp_a = &rv_D3_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  rvs1_rvp_b = &rv_D4_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  rvs1_rvp_rvretval = &rv_D5_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/

  rv_init();

  /* Assume input args are equal: */ 
  *rvs0_rvp_a = *rvs1_rvp_a;	/* Generated by:  RVMainGen::gen_args_equality(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  *rvs0_rvp_b = *rvs1_rvp_b;	/* Generated by:  RVMainGen::gen_args_equality(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  *rvs0_rvp_rvretval = *rvs1_rvp_rvretval;	/* Generated by:  RVMainGen::gen_args_equality(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/

  /* run each side's main() */
  retval0 = chk0_Loop_gcd_while1(rvs0_rvp_a, rvs0_rvp_b, rvs0_rvp_rvretval);
  retval1 = chk1_Loop_gcd_while1(rvs1_rvp_a, rvs1_rvp_b, rvs1_rvp_rvretval);

  rv_check();

  return 0;
}
