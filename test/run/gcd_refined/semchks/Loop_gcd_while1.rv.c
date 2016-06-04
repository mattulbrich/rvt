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
void  __CPROVER_assume(_Bool  rv_arg_2);

/*** global declarations side 1: ***/
int  rvs1_rv_getint();
char  rvs1_rv_getchar();
void  rvs1_swap(char  *a, char  *b);
char  rvs1_gcd(char  a, char  b);
void  rvs1_simplify(char  *numerator_p, char  *denominator_p);
char  rvs1_main();
unsigned char  chk1_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
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

unsigned char  chk0_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval)
{
  if (!(*rvp_a != 0))
    return 0;
  {
    *rvp_b = *rvp_b % *rvp_a;
    rvs0_swap(&*rvp_a,&*rvp_b);
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

unsigned char  chk1_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval)
{
  if (!(*rvp_a != 0))
    return 0;
  {
    *rvp_b = *rvp_b % *rvp_a;
    rvs1_swap(&*rvp_b,&*rvp_a);
    *rvp_a = *rvp_a;
  }

  return 0;
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  unsigned char  retval0;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  unsigned char  retval1;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  char  *rvs0_rvp_a;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  char  *rvs1_rvp_a;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  char  *rvs0_rvp_b;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  char  *rvs1_rvp_b;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  char  *rvs0_rvp_rvretval;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  char  *rvs1_rvp_rvretval;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  char  rv_D0_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  char  rv_D1_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  char  rv_D2_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  char  rv_D3_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  char  rv_D4_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  char  rv_D5_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/

  /* output: */
  /* output: */
  /* output: */
  /* Allocations for side 0: */
  rvs0_rvp_a = &rv_D0_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  rvs0_rvp_b = &rv_D1_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  rvs0_rvp_rvretval = &rv_D2_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  /* Allocations for side 1: */
  rvs1_rvp_a = &rv_D3_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  rvs1_rvp_b = &rv_D4_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  rvs1_rvp_rvretval = &rv_D5_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/

  /* Assume input args are equal: */ 
  *rvs0_rvp_a = *rvs1_rvp_a;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](613)(379)(293)/ rv_temps.cpp:362*/
  *rvs0_rvp_b = *rvs1_rvp_b;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](613)(379)(293)(608)/ protect_pointer [op=4](613)(379)(293)/ rv_temps.cpp:362*/
  *rvs0_rvp_rvretval = *rvs1_rvp_rvretval;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](613)(379)(293)(608)/ protect_pointer [op=4](613)(379)(293)(608)/ protect_pointer [op=4](613)(379)(293)/ rv_temps.cpp:362*/

  /* run each side's main() */
  retval0 = chk0_Loop_gcd_while1(rvs0_rvp_a, rvs0_rvp_b, rvs0_rvp_rvretval);
  retval1 = chk1_Loop_gcd_while1(rvs1_rvp_a, rvs1_rvp_b, rvs1_rvp_rvretval);
  /* Assertions: */

  /* Compare return values: */ 
  assert( retval0 == retval1 );	/* Generated by:  gen_main(608)(613)(379)(309)/ rv_temps.cpp:352*/

  /* Compare output args: */ 
  assert( *rvs0_rvp_a == *rvs1_rvp_a );	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=6](613)(379)(309)/ rv_temps.cpp:352*/
  assert( *rvs0_rvp_b == *rvs1_rvp_b );	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=6](613)(379)(309)(608)/ protect_pointer [op=6](613)(379)(309)/ rv_temps.cpp:352*/


  return 0;
}
