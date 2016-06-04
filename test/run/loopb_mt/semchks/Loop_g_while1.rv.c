#include "rv_declarations.h"

/*** global declarations side 0: ***/
float  rvs0_rv_mult(float  x, float  y);
float  rvs0_rv_div(float  x, float  y);
int  rvs0_rv_mod(int  x, int  y);
typedef struct rvs0_B {
  int  a;
  struct rvs0_B  *next;
} rvs0_B_t;
void  rvs0_g(rvs0_B_t  *pb, rvs0_B_t  *src, int  c);
int  rvs0_main();
unsigned char  chk0_Loop_g_while1(rvs0_B_t  **rvp_cur, rvs0_B_t  **rvp_pb);
void  __CPROVER_assume(_Bool  rv_arg_2);

/*** global declarations side 1: ***/
float  rvs1_rv_mult(float  x, float  y);
float  rvs1_rv_div(float  x, float  y);
int  rvs1_rv_mod(int  x, int  y);
typedef struct rvs1_B {
  int  a;
  struct rvs1_B  *next;
} rvs1_B_t;
void  rvs1_g(rvs1_B_t  *pb, rvs1_B_t  *src, int  c);
int  rvs1_main();
unsigned char  chk1_Loop_g_while1(rvs1_B_t  **rvp_cur, rvs1_B_t  **rvp_pb);
void  __CPROVER_assume(_Bool  rv_arg_3);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
unsigned char  chk0_Loop_g_while1(rvs0_B_t  **rvp_cur, rvs0_B_t  **rvp_pb)
{
  if (!((*rvp_cur)->a != 0))
    return 0;
  {
    (*rvp_pb)->a += 1;
    *rvp_cur = (*rvp_cur)->next;
  }

  return 0;
}


/*** Functions side 1: ***/
unsigned char  chk1_Loop_g_while1(rvs1_B_t  **rvp_cur, rvs1_B_t  **rvp_pb)
{
  if (!((*rvp_cur)->a != 0))
    return 0;
  {
    (*rvp_pb)->a += 2;
    *rvp_cur = (*rvp_cur)->next;
  }

  return 0;
}






void rv_init()
{
}


void rv_check()
{
  /* check reach-equivalence of the inputs for each uninterpreted function: */
  int i;
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  unsigned char  retval0;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  unsigned char  retval1;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  rvs0_B_t  **rvs0_rvp_cur;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  rvs1_B_t  **rvs1_rvp_cur;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  rvs0_B_t  **rvs0_rvp_pb;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  rvs1_B_t  **rvs1_rvp_pb;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  rvs0_B_t  rv_D0_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs0_B_t  *rv_D0_1;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs0_B_t  rv_D1_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs0_B_t *local0rvs0_rvp_cur_1;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:344*/
  struct rvs0_B  rv_D2_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  struct rvs0_B *local0next_2;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:344*/
  rvs0_B_t  rv_D3_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs0_B_t  *rv_D3_1;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs0_B_t  rv_D4_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs0_B_t *local0rvs0_rvp_pb_3;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:344*/
  struct rvs0_B  rv_D5_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  struct rvs0_B *local0next_4;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:344*/
  rvs1_B_t  rv_D6_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs1_B_t  *rv_D6_1;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs1_B_t  rv_D7_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs1_B_t *local1rvs1_rvp_cur_5;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:344*/
  struct rvs1_B  rv_D8_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  struct rvs1_B *local1next_6;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:344*/
  rvs1_B_t  rv_D9_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs1_B_t  *rv_D9_1;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs1_B_t  rv_D10_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  rvs1_B_t *local1rvs1_rvp_pb_7;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:344*/
  struct rvs1_B  rv_D11_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:327*/
  struct rvs1_B *local1next_8;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:344*/
  rvs0_B_t **local0rvp_cur_9;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:344*/
  rvs0_B_t *local0rvp_cur_9_10;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:344*/
  rvs1_B_t *local1rvs1_rvp_cur_11;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)/ rv_temps.cpp:344*/
  struct rvs0_B *local0next_12;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:344*/
  struct rvs1_B *local1next_13;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)/ rv_temps.cpp:344*/
  rvs0_B_t **local0rvp_pb_14;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:344*/
  rvs0_B_t *local0rvp_pb_14_15;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:344*/
  rvs1_B_t *local1rvs1_rvp_pb_16;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)/ rv_temps.cpp:344*/
  struct rvs0_B *local0next_17;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:344*/
  struct rvs1_B *local1next_18;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)/ rv_temps.cpp:344*/


  /* output: */
  /* output: */
  /* Allocations for side 0: */
  rv_D0_1 = &rv_D0_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:329*/
  rvs0_rvp_cur = &rv_D0_1;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  *rvs0_rvp_cur = &rv_D1_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  local0rvs0_rvp_cur_1 = *rvs0_rvp_cur;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:345*/
  local0rvs0_rvp_cur_1->next = &rv_D2_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  local0next_2 = local0rvs0_rvp_cur_1->next;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:345*/
  local0next_2->next = (void*)0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)/ rv_temps.cpp:357*/
  rv_D3_1 = &rv_D3_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:329*/
  rvs0_rvp_pb = &rv_D3_1;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  *rvs0_rvp_pb = &rv_D4_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  local0rvs0_rvp_pb_3 = *rvs0_rvp_pb;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:345*/
  local0rvs0_rvp_pb_3->next = &rv_D5_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  local0next_4 = local0rvs0_rvp_pb_3->next;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:345*/
  local0next_4->next = (void*)0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)/ rv_temps.cpp:357*/
  /* Allocations for side 1: */
  rv_D6_1 = &rv_D6_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:329*/
  rvs1_rvp_cur = &rv_D6_1;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  *rvs1_rvp_cur = &rv_D7_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  local1rvs1_rvp_cur_5 = *rvs1_rvp_cur;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:345*/
  local1rvs1_rvp_cur_5->next = &rv_D8_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  local1next_6 = local1rvs1_rvp_cur_5->next;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:345*/
  local1next_6->next = (void*)0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)/ rv_temps.cpp:357*/
  rv_D9_1 = &rv_D9_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:329*/
  rvs1_rvp_pb = &rv_D9_1;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  *rvs1_rvp_pb = &rv_D10_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  local1rvs1_rvp_pb_7 = *rvs1_rvp_pb;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:345*/
  local1rvs1_rvp_pb_7->next = &rv_D11_0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc/ rv_temps.cpp:332*/
  local1next_8 = local1rvs1_rvp_pb_7->next;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)/ rv_temps.cpp:345*/
  local1next_8->next = (void*)0;	/* Generated by:  gen_arg_alloc_side(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](613)(371)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(601)(326)/ gen_safe_alloc(608)/ protect_pointer [op=8](475)(612)(2281)(407)(601)(407)(600)(315)/ rv_temps.cpp:357*/

  rv_init();

  /* Assume input args are equal: */ 
  local0rvp_cur_9 = rvs0_rvp_cur;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:345*/
  local0rvp_cur_9_10 = *local0rvp_cur_9;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:345*/
  local1rvs1_rvp_cur_11 = *rvs1_rvp_cur;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)/ rv_temps.cpp:345*/
  local0rvp_cur_9_10->a = local1rvs1_rvp_cur_11->a;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)/ rv_temps.cpp:362*/
  local0next_12 = local0rvp_cur_9_10->next;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:345*/
  local1next_13 = local1rvs1_rvp_cur_11->next;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)/ rv_temps.cpp:345*/
  local0next_12->a = local1next_13->a;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)/ rv_temps.cpp:362*/
  local0rvp_pb_14 = rvs0_rvp_pb;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:345*/
  local0rvp_pb_14_15 = *local0rvp_pb_14;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:345*/
  local1rvs1_rvp_pb_16 = *rvs1_rvp_pb;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)/ rv_temps.cpp:345*/
  local0rvp_pb_14_15->a = local1rvs1_rvp_pb_16->a;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)/ rv_temps.cpp:362*/
  local0next_17 = local0rvp_pb_14_15->next;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)/ rv_temps.cpp:345*/
  local1next_18 = local1rvs1_rvp_pb_16->next;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)/ rv_temps.cpp:345*/
  local0next_17->a = local1next_18->a;	/* Generated by:  gen_args_equality(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(613)(371)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)(407)(608)/ protect_pointer [op=4](475)(475)(612)(2281)(407)(608)(613)(379)(293)/ rv_temps.cpp:362*/

  /* run each side's main() */
  retval0 = chk0_Loop_g_while1(rvs0_rvp_cur, rvs0_rvp_pb);
  retval1 = chk1_Loop_g_while1(rvs1_rvp_cur, rvs1_rvp_pb);

  rv_check();

  return 0;
}
