#include "rv_declarations.h"
#define RV_MAX_INPUTS 2
#include "rv_inputs.c"
/*** global declarations side 0: ***/
short  rvs0_rv_div_short__short_(short  x, short  y);
short  rvs0_rv_mod_short__short_(short  x, short  y);
float  rvs0_rv_mult(float  x, float  y);
float  rvs0_rv_div(float  x, float  y);
int  rvs0_rv_mod(int  x, int  y);
int  rvs0_rv_getint();
char  rvs0_rv_getchar();
void  rvs0_swap(short  *a, short  *b);
short  rvs0_gcd(short  a, short  b);
void  rvs0_simplify(short  *numerator_p, short  *denominator_p);
short  chk0_main();
unsigned char  rvs0_Loop_gcd_while1(short  *rvp_a, short  *rvp_b, short  *rvp_rvretval);
void  rvs0_simplify(short  *numerator_p, short  *denominator_p);
void  __CPROVER_assume(_Bool  rv_arg_8);

/*** global declarations side 1: ***/
short  rvs1_rv_div_short__short_(short  x, short  y);
short  rvs1_rv_mod_short__short_(short  x, short  y);
float  rvs1_rv_mult(float  x, float  y);
float  rvs1_rv_div(float  x, float  y);
int  rvs1_rv_mod(int  x, int  y);
int  rvs1_rv_getint();
char  rvs1_rv_getchar();
void  rvs1_swap(short  *a, short  *b);
short  rvs1_gcd(short  a, short  b);
void  rvs1_simplify(short  *numerator_p, short  *denominator_p);
short  chk1_main();
unsigned char  rvs1_Loop_gcd_while1(short  *rvp_a, short  *rvp_b, short  *rvp_rvretval);
void  rvs1_simplify(short  *numerator_p, short  *denominator_p);
void  __CPROVER_assume(_Bool  rv_arg_9);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
short  chk0_main()
{
  short  a;
  short  b;

  a = rvs0_rv_getint();
  b = rvs0_rv_getint();
  rvs0_simplify(&a,&b);
  return 0;
}


/*** Functions side 1: ***/
short  chk1_main()
{
  short  a;
  short  b;

  a = rvs1_rv_getint() + 0;
  b = rvs1_rv_getint();
  rvs1_simplify(&a,&b);
  return 0;
}


/* Implementations of the uninterpreted functions: */

  /* Declarations of the CBMC uninterpreted functions */
short  __CPROVER_uninterpreted_5_numerator_p(short , short );
short  __CPROVER_uninterpreted_5_denominator_p(short , short );

  /* CBMC-UF side 0: */ 
void  rvs0_simplify(short  *numerator_p, short  *denominator_p)
{
  /* Declarations: */
  short  rv_D22_0;	/* Generated by:  gen_side0_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  short  rv_D23_0;	/* Generated by:  gen_side0_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/

  /* Protecting pointers from being NULL-dereferenced: */
  if (numerator_p== 0) {
  numerator_p = &rv_D22_0;	/* Generated by:  gen_side0_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }
  if (denominator_p== 0) {
  denominator_p = &rv_D23_0;	/* Generated by:  gen_side0_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }

  /* Each output is assigned a UF:*/
  *numerator_p= __CPROVER_uninterpreted_5_numerator_p(*numerator_p, *denominator_p);
  *denominator_p= __CPROVER_uninterpreted_5_denominator_p(*numerator_p, *denominator_p);

}


  /* CBMC-UF side 1: */ 
void  rvs1_simplify(short  *numerator_p, short  *denominator_p)
{
  /* Declarations: */
  short  rv_D24_0;	/* Generated by:  gen_side1_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  short  rv_D25_0;	/* Generated by:  gen_side1_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/

  /* Protecting pointers from being NULL-dereferenced: */
  if (numerator_p== 0) {
  numerator_p = &rv_D24_0;	/* Generated by:  gen_side1_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }
  if (denominator_p== 0) {
  denominator_p = &rv_D25_0;	/* Generated by:  gen_side1_cbmc_uf(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(608)/ protect_pointer [op=9](613)(379)(601)(326)/ gen_safe_alloc(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  }

  /* Each output is assigned a UF:*/
  *numerator_p= __CPROVER_uninterpreted_5_numerator_p(*numerator_p, *denominator_p);
  *denominator_p= __CPROVER_uninterpreted_5_denominator_p(*numerator_p, *denominator_p);

}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  short  retval0;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  short  retval1;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/


  /* Assume input args are equal: */ 

  /* run each side's main() */
  retval0 = chk0_main();
  retval1 = chk1_main();
  /* Assertions: */

  /* Compare return values: */ 
  assert( retval0 == retval1 );	/* Generated by:  gen_main(608)(613)(379)(309)/ rv_temps.cpp:352*/

  /* Compare output args: */ 


  return 0;
}
