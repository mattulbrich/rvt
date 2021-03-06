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
short  chk0_gcd(short  a, short  b);
void  rvs0_simplify(short  *numerator_p, short  *denominator_p);
short  rvs0_main();
unsigned char  rvs0_Loop_gcd_while1(short  *rvp_a, short  *rvp_b, short  *rvp_rvretval);
unsigned char  rvs0_Loop_gcd_while1(short  *rvp_a, short  *rvp_b, short  *rvp_rvretval);
void  __CPROVER_assume(_Bool  rv_arg_4);

/*** global declarations side 1: ***/
short  rvs1_rv_div_short__short_(short  x, short  y);
short  rvs1_rv_mod_short__short_(short  x, short  y);
float  rvs1_rv_mult(float  x, float  y);
float  rvs1_rv_div(float  x, float  y);
int  rvs1_rv_mod(int  x, int  y);
int  rvs1_rv_getint();
char  rvs1_rv_getchar();
void  rvs1_swap(short  *a, short  *b);
short  chk1_gcd(short  a, short  b);
void  rvs1_simplify(short  *numerator_p, short  *denominator_p);
short  rvs1_main();
unsigned char  rvs1_Loop_gcd_while1(short  *rvp_a, short  *rvp_b, short  *rvp_rvretval);
unsigned char  rvs1_Loop_gcd_while1(short  *rvp_a, short  *rvp_b, short  *rvp_rvretval);
void  __CPROVER_assume(_Bool  rv_arg_5);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
void  rvs0_swap(short  *a, short  *b)
{
  short  tmp = *a;

  *a = *b;
  *b = tmp;
}

short  chk0_gcd(short  a, short  b)
{
  short  rvretval = 0;

  {
    rvs0_Loop_gcd_while1(&a,&b,&rvretval);
  }

  return b;
}


/*** Functions side 1: ***/
void  rvs1_swap(short  *a, short  *b)
{
  short  tmp = *a;

  *a = *b;
  *b = tmp;
}

short  chk1_gcd(short  a, short  b)
{
  short  rvretval = 0;

  {
    rvs1_Loop_gcd_while1(&a,&b,&rvretval);
  }

  return b - 1;
}


/* Implementations of the uninterpreted functions: */

  /* Declarations of the CBMC uninterpreted functions */
short  __CPROVER_uninterpreted_3_rvp_a(short , short , short );
short  __CPROVER_uninterpreted_3_rvp_b(short , short , short );
unsigned char  __CPROVER_uninterpreted_3_retval(short , short , short );

  /* CBMC-UF side 0: */ 
unsigned char  rvs0_Loop_gcd_while1(short  *rvp_a, short  *rvp_b, short  *rvp_rvretval)
{
  unsigned char  retval;

  /* Declarations: */
  short  rv_D16_0;	/* Generated by:  RVUFGen::gen_side0_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  short  rv_D17_0;	/* Generated by:  RVUFGen::gen_side0_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  short  rv_D18_0;	/* Generated by:  RVUFGen::gen_side0_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/

  /* Protecting pointers from being NULL-dereferenced: */
  if (rvp_a== 0) {
  rvp_a = &rv_D16_0;	/* Generated by:  RVUFGen::gen_side0_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  }
  if (rvp_b== 0) {
  rvp_b = &rv_D17_0;	/* Generated by:  RVUFGen::gen_side0_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  }
  if (rvp_rvretval== 0) {
  rvp_rvretval = &rv_D18_0;	/* Generated by:  RVUFGen::gen_side0_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  }

  /* Each output is assigned a UF:*/
  *rvp_a= __CPROVER_uninterpreted_3_rvp_a(*rvp_a, *rvp_b, *rvp_rvretval);
  *rvp_b= __CPROVER_uninterpreted_3_rvp_b(*rvp_a, *rvp_b, *rvp_rvretval);
  retval= __CPROVER_uninterpreted_3_retval(*rvp_a, *rvp_b, *rvp_rvretval);
__CPROVER_assume(1);
  return retval;
}


  /* CBMC-UF side 1: */ 
unsigned char  rvs1_Loop_gcd_while1(short  *rvp_a, short  *rvp_b, short  *rvp_rvretval)
{
  unsigned char  retval;

  /* Declarations: */
  short  rv_D19_0;	/* Generated by:  RVUFGen::gen_side1_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  short  rv_D20_0;	/* Generated by:  RVUFGen::gen_side1_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  short  rv_D21_0;	/* Generated by:  RVUFGen::gen_side1_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/

  /* Protecting pointers from being NULL-dereferenced: */
  if (rvp_a== 0) {
  rvp_a = &rv_D19_0;	/* Generated by:  RVUFGen::gen_side1_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  }
  if (rvp_b== 0) {
  rvp_b = &rv_D20_0;	/* Generated by:  RVUFGen::gen_side1_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  }
  if (rvp_rvretval== 0) {
  rvp_rvretval = &rv_D21_0;	/* Generated by:  RVUFGen::gen_side1_cbmc_uf(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)/ RVGen::protect_pointer [op=9](626)(392)(621)(626)(392)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  }

  /* Each output is assigned a UF:*/
  *rvp_a= __CPROVER_uninterpreted_3_rvp_a(*rvp_a, *rvp_b, *rvp_rvretval);
  *rvp_b= __CPROVER_uninterpreted_3_rvp_b(*rvp_a, *rvp_b, *rvp_rvretval);
  retval= __CPROVER_uninterpreted_3_retval(*rvp_a, *rvp_b, *rvp_rvretval);
__CPROVER_assume(1);
  return retval;
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  short  retval0;	/* Generated by:  RVTemp::gen_retval_declarations/ c:\newrvt\rv_temps.cpp:269*/
  short  retval1;	/* Generated by:  RVTemp::gen_retval_declarations/ c:\newrvt\rv_temps.cpp:269*/
  short  rvs0_a;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  short  rvs1_a;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  short  rvs0_b;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  short  rvs1_b;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/

  /* output: */
  /* output: */
  /* Allocations for side 0: */
  /* Allocations for side 1: */

  /* Assume input args are equal: */ 
  rvs0_a = rvs1_a;	/* Generated by:  RVMainGen::gen_args_equality(621)(626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  rvs0_b = rvs1_b;	/* Generated by:  RVMainGen::gen_args_equality(621)(626)(392)(306)(621)(626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/

  /* run each side's main() */
  retval0 = chk0_gcd(rvs0_a, rvs0_b);
  retval1 = chk1_gcd(rvs1_a, rvs1_b);
  /* Assertions: */

  /* Compare return values: */ 
  assert( retval0 == retval1 );	/* Generated by:  RVMainGen::gen_main(621)(626)(392)(322)/ c:\newrvt\rv_temps.cpp:352*/

  /* Compare output args: */ 


  return 0;
}
