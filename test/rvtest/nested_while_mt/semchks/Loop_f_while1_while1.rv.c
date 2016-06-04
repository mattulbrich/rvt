#include "rv_declarations.h"

/*** global declarations side 0: ***/
typedef int  (*rvs0_rvt_FuncPtrSubst_int__const_void_ptr_const_void_ptr)(void  *rv_arg_0, void  *rv_arg_1);
float  rvs0_rv_mult(float  x, float  y);
float  rvs0_rv_div(float  x, float  y);
int  rvs0_rv_mod(int  x, int  y);
typedef int  rvs0_pid_t;
typedef unsigned int  rvs0_size_t;
typedef unsigned char  rvs0_u_char;
typedef unsigned long  rvs0_ulong;
typedef unsigned short  rvs0_ushort;
typedef unsigned int  rvs0_uint;
typedef unsigned int  rvs0_off_t;
typedef unsigned int  rvs0_mode_t;
typedef unsigned int  rvs0_u_int;
typedef int  rvs0_uid_t;
void  rvs0_exit(int  status);
char  *rvs0_getenv(char  *name);
int  rvs0_system(char  *string);
void  rvs0_abort();
void  *calloc(rvs0_size_t  nmemb, rvs0_size_t  size);
void  *malloc(rvs0_size_t  size);
void  free(void  *ptr);
void  *realloc(void  *ptr, rvs0_size_t  size);
int  rvs0_atoi(char  *nptr);
long  rvs0_atol(char  *nptr);
long long  rvs0_atoll(char  *nptr);
long long  rvs0_atoq(char  *nptr);
float  rvs0_atof(char  *nptr);
int  rvs0_rand();
void  rvs0_srand(unsigned int  seed);
long  rvs0_random();
void  rvs0_srandom(unsigned int  seed);
char  *rvs0_initstate(unsigned int  seed, char  *state, rvs0_size_t  n);
char  *rvs0_setstate(char  *state);
int  rvs0_mkstemp(char  *temp);
void  rvs0_qsort(void  *base, rvs0_size_t  num, rvs0_size_t  width, rvs0_rvt_FuncPtrSubst_int__const_void_ptr_const_void_ptr  fncompare);
int  rvs0_g;
int  rvs0_f(int  x);
int  rvs0_main();
unsigned char  rvs0_Loop_f_while1(int  *rvp_i, int  *rvp_x, int  *rvp_rvretval);
unsigned char  chk0_Loop_f_while1_while1(int  i, int  *rvp_x, int  *rvp_rvretval);
unsigned char  rvs0_Loop_f_while1_while1(int  i, int  *rvp_x, int  *rvp_rvretval);
void  __CPROVER_assume(_Bool  rv_arg_6);

/*** global declarations side 1: ***/
typedef int  (*rvs1_rvt_FuncPtrSubst_int__const_void_ptr_const_void_ptr)(void  *rv_arg_2, void  *rv_arg_3);
float  rvs1_rv_mult(float  x, float  y);
float  rvs1_rv_div(float  x, float  y);
int  rvs1_rv_mod(int  x, int  y);
typedef int  rvs1_pid_t;
typedef unsigned int  rvs1_size_t;
typedef unsigned char  rvs1_u_char;
typedef unsigned long  rvs1_ulong;
typedef unsigned short  rvs1_ushort;
typedef unsigned int  rvs1_uint;
typedef unsigned int  rvs1_off_t;
typedef unsigned int  rvs1_mode_t;
typedef unsigned int  rvs1_u_int;
typedef int  rvs1_uid_t;
void  rvs1_exit(int  status);
char  *rvs1_getenv(char  *name);
int  rvs1_system(char  *string);
void  rvs1_abort();
void  *calloc(rvs1_size_t  nmemb, rvs1_size_t  size);
void  *malloc(rvs1_size_t  size);
void  free(void  *ptr);
void  *realloc(void  *ptr, rvs1_size_t  size);
int  rvs1_atoi(char  *nptr);
long  rvs1_atol(char  *nptr);
long long  rvs1_atoll(char  *nptr);
long long  rvs1_atoq(char  *nptr);
float  rvs1_atof(char  *nptr);
int  rvs1_rand();
void  rvs1_srand(unsigned int  seed);
long  rvs1_random();
void  rvs1_srandom(unsigned int  seed);
char  *rvs1_initstate(unsigned int  seed, char  *state, rvs1_size_t  n);
char  *rvs1_setstate(char  *state);
int  rvs1_mkstemp(char  *temp);
void  rvs1_qsort(void  *base, rvs1_size_t  num, rvs1_size_t  width, rvs1_rvt_FuncPtrSubst_int__const_void_ptr_const_void_ptr  fncompare);
int  rvs1_g;
int  rvs1_f(int  x);
int  rvs1_main();
unsigned char  rvs1_Loop_f_while1(int  *rvp_i, int  *rvp_x, int  *rvp_rvretval);
unsigned char  chk1_Loop_f_while1_while1(int  i, int  *rvp_x, int  *rvp_rvretval);
unsigned char  rvs1_Loop_f_while1_while1(int  i, int  *rvp_x, int  *rvp_rvretval);
void  __CPROVER_assume(_Bool  rv_arg_7);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
unsigned char  rvs0_Loop_f_while1_while1(int  i, int  *rvp_x, int  *rvp_rvretval);
unsigned char  chk0_Loop_f_while1_while1(int  i, int  *rvp_x, int  *rvp_rvretval)
{
  if (!(*rvp_x < i))
    return 0;
  {
    (*rvp_x)--;
    rvs0_g++;
    {
      *rvp_rvretval = rvs0_g;
      return 123;
    }

  }

  {
    return rvs0_Loop_f_while1_while1(i,rvp_x,rvp_rvretval);
  }

  return 0;
}


/*** Functions side 1: ***/
unsigned char  rvs1_Loop_f_while1_while1(int  i, int  *rvp_x, int  *rvp_rvretval);
unsigned char  chk1_Loop_f_while1_while1(int  i, int  *rvp_x, int  *rvp_rvretval)
{
  if (!(*rvp_x < i))
    return 0;
  {
    (*rvp_x)--;
    rvs1_g = rvs1_g + 1;
    {
      *rvp_rvretval = rvs1_g;
      return 123;
    }

  }

  {
    return rvs1_Loop_f_while1_while1(i,rvp_x,rvp_rvretval);
  }

  return 0;
}


typedef struct rv_UF_Loop_f_while1_while1_struct_tag {
  int  in_i;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  *in_rvp_x;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  *out_rvp_x;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  *in_rvp_rvretval;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  *out_rvp_rvretval;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  in_g;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  out_g;	/* Generated by:  RVUFGen::gen_uf_item_decl(114)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  unsigned char  out_retval;	/* Generated by:  RVUFGen::gen_uf_array(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  _Bool reach_equiv_flag;
} rv_UF_Loop_f_while1_while1_struct;
#define rv_UF_K_Loop_f_while1_while1 5
rv_UF_Loop_f_while1_while1_struct rv_UF_Loop_f_while1_while1_array[rv_UF_K_Loop_f_while1_while1];
int rv_UF_Loop_f_while1_while1_count[2] = {0,0};


 /*** uninterpreted function side 0: ***/ 
  /* Declarations: */


unsigned char  rvs0_Loop_f_while1_while1(int  i, int  *rvp_x, int  *rvp_rvretval)
{
  unsigned char  retval;

  /* save values of input arguments: */
  rv_UF_Loop_f_while1_while1_array[rv_UF_Loop_f_while1_while1_count[0]]. = i;	/* Generated by:  RVUFGen::gen_side0_uf(621)(626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  *rv_UF_Loop_f_while1_while1_array[rv_UF_Loop_f_while1_while1_count[0]].in_rvp_x = *rvp_x;	/* Generated by:  RVUFGen::gen_side0_uf(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  *rv_UF_Loop_f_while1_while1_array[rv_UF_Loop_f_while1_while1_count[0]].in_rvp_rvretval = *rvp_rvretval;	/* Generated by:  RVUFGen::gen_side0_uf(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  /* save values of input globals: */
  rv_UF_Loop_f_while1_while1_array[rv_UF_Loop_f_while1_while1_count[0]]. = rvs0_g;	/* Generated by:  RVUFGen::gen_side0_uf(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)(626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/

  /* generate and save values of output arguments and globals: */
  *rv_UF_Loop_f_while1_while1_array[rv_UF_Loop_f_while1_while1_count[0]]. = *rvp_x = (int )nondet_long();	/* Generated by:  RVUFGen::gen_side0_uf(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)/ c:\newrvt\rv_temps.cpp:412*/
  *rv_UF_Loop_f_while1_while1_array[rv_UF_Loop_f_while1_while1_count[0]].out_rvp_rvretval = *rvp_rvretval = (int )nondet_long();	/* Generated by:  RVUFGen::gen_side0_uf(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)/ c:\newrvt\rv_temps.cpp:412*/
  rv_UF_Loop_f_while1_while1_array[rv_UF_Loop_f_while1_while1_count[0]]. = rvs0_g = (int )nondet_long();	/* Generated by:  RVUFGen::gen_side0_uf(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)(621)(626)(392)(276)/ c:\newrvt\rv_temps.cpp:412*/
  rv_UF_Loop_f_while1_while1_array[rv_UF_Loop_f_while1_while1_count[0]]. = retval = (unsigned char )nondet_int();	/* Generated by:  RVUFGen::gen_side0_uf(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)(621)/ RVGen::protect_pointer [op=2](626)(392)(276)(621)(626)(392)(276)(621)(626)(392)(276)/ c:\newrvt\rv_temps.cpp:412*/
  rv_UF_Loop_f_while1_while1_count[0]++;

  return retval;
}


/*** uninterpreted function side 1: ***/ 
unsigned char  rvs1_Loop_f_while1_while1(int  i, int  *rvp_x, int  *rvp_rvretval)
{
  unsigned char  retval;

  _Bool found = 0;
  _Bool equal = 1;
  int found_ind = -1;
  int rv_uf_ind = rv_UF_Loop_f_while1_while1_count[0]-1;
  for(; rv_uf_ind >= 0; rv_uf_ind--) {
    equal = (rv_UF_Loop_f_while1_while1_array[rv_uf_ind]. == i);	/* Generated by:  RVUFGen::gen_side1_uf(621)(626)(392)(285)/ c:\newrvt\rv_temps.cpp:427*/
    equal = equal && (*rv_UF_Loop_f_while1_while1_array[rv_uf_ind].in_rvp_x == *rvp_x);	/* Generated by:  RVUFGen::gen_side1_uf(621)(626)(392)(285)(621)/ RVGen::protect_pointer [op=3](626)(392)(285)/ c:\newrvt\rv_temps.cpp:427*/
    equal = equal && (*rv_UF_Loop_f_while1_while1_array[rv_uf_ind].in_rvp_rvretval == *rvp_rvretval);	/* Generated by:  RVUFGen::gen_side1_uf(621)(626)(392)(285)(621)/ RVGen::protect_pointer [op=3](626)(392)(285)(621)/ RVGen::protect_pointer [op=3](626)(392)(285)/ c:\newrvt\rv_temps.cpp:427*/
    equal = equal && (rv_UF_Loop_f_while1_while1_array[rv_uf_ind]. == rvs1_g);	/* Generated by:  RVUFGen::gen_side1_uf(621)(626)(392)(285)(621)/ RVGen::protect_pointer [op=3](626)(392)(285)(621)/ RVGen::protect_pointer [op=3](626)(392)(285)(621)(626)(392)(285)/ c:\newrvt\rv_temps.cpp:427*/
    if( equal ) { 
      found = 1;
      found_ind = rv_uf_ind;
		      rv_UF_Loop_f_while1_while1_array[rv_uf_ind].reach_equiv_flag = 1;
    }
		equal = 1;
  }

  if( found ) /* input values were found among the saved values */
  {
   /* Sides 0 and 1 are not known to be partially equivalent.
    * Returning some results unrelated to the side 0: */
  int  rv_D0_0;	/* Generated by:  RVUFGen::gen_input_not_found_case(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  rvp_x = &rv_D0_0;	/* Generated by:  RVUFGen::gen_input_not_found_case(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  *rvp_x = (int )nondet_long();	/* Generated by:  RVUFGen::gen_input_not_found_case(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc(626)(392)(256)/ c:\newrvt\rv_temps.cpp:383*/
  int  rv_D1_0;	/* Generated by:  RVUFGen::gen_input_not_found_case(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc(626)(392)(256)(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  rvp_rvretval = &rv_D1_0;	/* Generated by:  RVUFGen::gen_input_not_found_case(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc(626)(392)(256)(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  *rvp_rvretval = (int )nondet_long();	/* Generated by:  RVUFGen::gen_input_not_found_case(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc(626)(392)(256)(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc(626)(392)(256)/ c:\newrvt\rv_temps.cpp:383*/
  rvs1_g = (int )nondet_long();	/* Generated by:  RVUFGen::gen_input_not_found_case(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc(626)(392)(256)(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc(626)(392)(256)(621)(626)(392)(256)/ c:\newrvt\rv_temps.cpp:383*/
  retval = (unsigned char )nondet_int();	/* Generated by:  RVUFGen::gen_input_not_found_case(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc(626)(392)(256)(621)/ RVGen::protect_pointer [op=1](486)/ RVTemp::gen_safe_alloc(626)(392)(256)(621)(626)(392)(256)(621)(626)(392)(256)/ c:\newrvt\rv_temps.cpp:383*/

  } else {

    /* Assert reach-equivalence: side 0 and 1 inputs are equal.*/
    assert( 0 );

  }
  rv_UF_Loop_f_while1_while1_count[1]++;

  return retval;
}

void rvt_token_initialize_mutual_termination_tokens_Loop_f_while1_while1(){
	int rvt_token_i = 0;
		for (rvt_token_i = 0 ; rvt_token_i < rv_UF_K_Loop_f_while1_while1 ; rvt_token_i++){
			rvt_token_Loop_f_while1_while1_call_mark_array0[rvt_token_i] = 0;
			rvt_token_Loop_f_while1_while1_call_mark_array1[rvt_token_i] = 0;
		}
		rvt_token_Loop_f_while1_while1_count = 0;
		rvt_token_Loop_f_while1_while1_first_call_to_uf_flag = 0;

}





void rv_init()
{
}


void rv_check()
{
  /* check reach-equivalence of the inputs for each uninterpreted function: */
  int i;

  /* checking reach-equivalence of all the inputs of array rv_UF_Loop_f_while1_while1_array : */
  for (i = rv_UF_Loop_f_while1_while1_count[0] - 1; i >= 0; --i)
    assert( rv_UF_Loop_f_while1_while1_array[i].reach_equiv_flag );
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  unsigned char  retval0;	/* Generated by:  RVTemp::gen_retval_declarations/ c:\newrvt\rv_temps.cpp:269*/
  unsigned char  retval1;	/* Generated by:  RVTemp::gen_retval_declarations/ c:\newrvt\rv_temps.cpp:269*/
  int  rvs0_i;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  rvs1_i;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  *rvs0_rvp_x;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  *rvs1_rvp_x;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  *rvs0_rvp_rvretval;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  *rvs1_rvp_rvretval;	/* Generated by:  RVMainGen::gen_arg_decl(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)(110)/ RVGen::gen_decl_low(151)/ c:\newrvt\rv_temps.cpp:274*/
  int  rv_D2_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  int  rv_D3_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  int  rv_D4_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/
  int  rv_D5_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:327*/


  /* output: */
  /* output: */
  /* output: */
  /* Allocations for side 0: */
  rvs0_rvp_x = &rv_D2_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  rvs0_rvp_rvretval = &rv_D3_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  /* Allocations for side 1: */
  rvs1_rvp_x = &rv_D4_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/
  rvs1_rvp_rvretval = &rv_D5_0;	/* Generated by:  RVMainGen::gen_arg_alloc_side(614)(614)(339)/ RVTemp::gen_safe_alloc(614)(339)/ RVTemp::gen_safe_alloc/ c:\newrvt\rv_temps.cpp:332*/

  rv_init();

  /* Assume input args are equal: */ 
  rvs0_i = rvs1_i;	/* Generated by:  RVMainGen::gen_args_equality(621)(626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  *rvs0_rvp_x = *rvs1_rvp_x;	/* Generated by:  RVMainGen::gen_args_equality(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/
  *rvs0_rvp_rvretval = *rvs1_rvp_rvretval;	/* Generated by:  RVMainGen::gen_args_equality(621)(626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)(621)/ RVGen::protect_pointer [op=4](626)(392)(306)/ c:\newrvt\rv_temps.cpp:362*/

  /* Begin: Assume globals are equal: */ 
//nondet values for side 0:
  rvs0_g = (int )nondet_long();	/* Generated by:  RVMainGen::gen_equal_nondet_globals(621)(626)(392)(256)/ c:\newrvt\rv_temps.cpp:383*/
//alloc for side 1:
//copy leaves from side 0 to 1:
  rvs1_g = rvs0_g;	/* Generated by:  RVMainGen::gen_equal_nondet_globals(621)(626)(392)(256)(614)(621)(626)(392)(296)/ c:\newrvt\rv_temps.cpp:362*/
//until here

  /* End: Assume globals are equal: */ 

  /* run each side's main() */
  retval0 = chk0_Loop_f_while1_while1(rvs0_i, rvs0_rvp_x, rvs0_rvp_rvretval);
  retval1 = chk1_Loop_f_while1_while1(rvs1_i, rvs1_rvp_x, rvs1_rvp_rvretval);

  rv_check();

  return 0;
}