#include "rv_declarations.h"
#define RV_MAX_INPUTS 2
#include "rv_inputs.c"
/*** global declarations side 0: ***/
int  rvs0_rv_getint();
char  rvs0_rv_getchar();
void  rvs0_swap(char  *a, char  *b);
char  rvs0_gcd(char  a, char  b);
void  chk0_simplify(char  *numerator_p, char  *denominator_p);
char  rvs0_main();
unsigned char  rvs0_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
unsigned char  rvs0_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
void  __CPROVER_assume(_Bool  rv_arg_6);

/*** global declarations side 1: ***/
int  rvs1_rv_getint();
char  rvs1_rv_getchar();
void  rvs1_swap(char  *a, char  *b);
char  rvs1_gcd(char  a, char  b);
void  chk1_simplify(char  *numerator_p, char  *denominator_p);
char  rvs1_main();
unsigned char  rvs1_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
unsigned char  rvs1_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval);
void  __CPROVER_assume(_Bool  rv_arg_7);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
char  rvs0_gcd(char  a, char  b)
{
  char  rvretval = 0;

  {
    rvs0_Loop_gcd_while1(&a,&b,&rvretval);
  }

  return b;
}

void  chk0_simplify(char  *numerator_p, char  *denominator_p)
{
  char  tmp = rvs0_gcd(*numerator_p,*denominator_p);

  *numerator_p = *numerator_p / tmp;
  *denominator_p = *denominator_p / tmp;
}


/*** Functions side 1: ***/
char  rvs1_gcd(char  a, char  b)
{
  char  rvretval = 0;

  {
    rvs1_Loop_gcd_while1(&a,&b,&rvretval);
  }

  return b - 1;
}

void  chk1_simplify(char  *numerator_p, char  *denominator_p)
{
  char  tmp = rvs1_gcd(*numerator_p,*denominator_p);

  *numerator_p = *numerator_p / ++tmp;
  *denominator_p = *denominator_p / tmp;
}


/* Implementations of the uninterpreted functions: */

  /* Declarations of the CBMC uninterpreted functions */
char  __CPROVER_uninterpreted_1_rvp_a(char , char );
char  __CPROVER_uninterpreted_1_rvp_b(char , char );
unsigned char  __CPROVER_uninterpreted_1_retval(char , char );

  /* CBMC-UF side 0: */ 
unsigned char  rvs0_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval)
{
  unsigned char  retval;

  /* Declarations: */
  char  rv_D10_0;	/* Generated by:  gen_side0_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  char  rv_D11_0;	/* Generated by:  gen_side0_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/

  /* Protecting pointers from being NULL-dereferenced: */
  if (rvp_a== 0) {
  rvp_a = &rv_D10_0;	/* Generated by:  gen_side0_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }
  if (rvp_b== 0) {
  rvp_b = &rv_D11_0;	/* Generated by:  gen_side0_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }

  /* Each output is assigned a UF:*/
  *rvp_a= __CPROVER_uninterpreted_1_rvp_a(*rvp_a, *rvp_b);
  *rvp_b= __CPROVER_uninterpreted_1_rvp_b(*rvp_a, *rvp_b);
  retval= __CPROVER_uninterpreted_1_retval(*rvp_a, *rvp_b);

  return retval;
}


  /* CBMC-UF side 1: */ 
unsigned char  rvs1_Loop_gcd_while1(char  *rvp_a, char  *rvp_b, char  *rvp_rvretval)
{
  unsigned char  retval;

  /* Declarations: */
  char  rv_D12_0;	/* Generated by:  gen_side1_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  char  rv_D13_0;	/* Generated by:  gen_side1_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/

  /* Protecting pointers from being NULL-dereferenced: */
  if (rvp_a== 0) {
  rvp_a = &rv_D12_0;	/* Generated by:  gen_side1_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }
  if (rvp_b== 0) {
  rvp_b = &rv_D13_0;	/* Generated by:  gen_side1_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)(613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }

  /* Each output is assigned a UF:*/
  *rvp_a= __CPROVER_uninterpreted_1_rvp_a(*rvp_a, *rvp_b);
  *rvp_b= __CPROVER_uninterpreted_1_rvp_b(*rvp_a, *rvp_b);
  retval= __CPROVER_uninterpreted_1_retval(*rvp_a, *rvp_b);

  return retval;
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  char  *rvs0_numerator_p;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  char  *rvs1_numerator_p;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  char  *rvs0_denominator_p;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  char  *rvs1_denominator_p;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  char  rv_D14_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  char  rv_D15_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  char  rv_D16_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  char  rv_D17_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/

  /* output: */
  /* output: */
  /* Allocations for side 0: */
  rvs0_numerator_p = &rv_D14_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  rvs0_denominator_p = &rv_D15_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  /* Allocations for side 1: */
  rvs1_numerator_p = &rv_D16_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  rvs1_denominator_p = &rv_D17_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/

  /* Assume input args are equal: */ 
  *rvs0_numerator_p = *rvs1_numerator_p;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](613)(379)(293)/ rv_temps.cpp:362*/
  *rvs0_denominator_p = *rvs1_denominator_p;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](613)(379)(293)(608)/ protect_pointer [op=4](613)(379)(293)/ rv_temps.cpp:362*/

  /* run each side's main() */
  chk0_simplify(rvs0_numerator_p, rvs0_denominator_p);
  chk1_simplify(rvs1_numerator_p, rvs1_denominator_p);
  /* Assertions: */

  /* Compare output args: */ 
  assert( *rvs0_numerator_p == *rvs1_numerator_p );	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=6](613)(379)(309)/ rv_temps.cpp:352*/
  assert( *rvs0_denominator_p == *rvs1_denominator_p );	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=6](613)(379)(309)(608)/ protect_pointer [op=6](613)(379)(309)/ rv_temps.cpp:352*/


  return 0;
}
