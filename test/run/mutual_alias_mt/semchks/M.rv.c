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
void  rvs0_myempty();
int  rvs0_F(int  *n);
int  chk0_M(int  n);
int  rvs0_F(int  *n);
int  rvs0_G(int  n);
int  chk0_M(int  n);
int  rvs0_main();
int  rvs0_G(int  n);
unsigned char  rvs0_Loop_main_for1(int  *rvp_i, int  *rvp_out, int  **rvp_p, int  *rvp_rvretval);
unsigned char  rvs0_Loop_main_for2(int  *rvp_i, int  *rvp_rvretval);
void  __CPROVER_assume(_Bool  rv_arg_18);

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
void  rvs1_myempty();
int  rvs1_F(int  *n);
int  chk1_M(int  n);
int  rvs1_F(int  *n);
int  rvs1_G(int  n);
void  rvs1_plusone(int  *n);
int  chk1_M(int  n);
void  rvs1_H(int  i);
int  rvs1_main();
int  rvs1_G(int  n);
unsigned char  rvs1_Loop_main_for1(int  *rvp_i, int  *rvp_out, int  **rvp_p, int  *rvp_rvretval);
unsigned char  rvs1_Loop_main_for2(int  *rvp_i, int  *rvp_rvretval);
void  __CPROVER_assume(_Bool  rv_arg_19);

/*** end of global declarations side 1: ***/
/*** end of global declarations. ***/

/*** Functions side 0: ***/
int  chk0_M(int  n)
{
  if (n < 2)
    return 1;
  return n - rvs0_G(n);
}


/*** Functions side 1: ***/
void  rvs1_plusone(int  *n)
{
  *n = *n + 1;
}

int  chk1_M(int  n)
{
  if (n < 2)
    return 1;
  rvs1_plusone(&n);
  return n - 1 - rvs1_G(n - 1);
}


/* Implementations of the uninterpreted functions: */

typedef struct rv_UF_G_struct_tag {
  int  in_n;	/* Generated by:  gen_uf_item_decl(111)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  out_retval;	/* Generated by:  gen_uf_array(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  _Bool reach_equiv_flag;
} rv_UF_G_struct;
#define rv_UF_K_G 1 /* determined by RVT */
rv_UF_G_struct rv_UF_G_array[rv_UF_K_G];
int rv_UF_G_count[2] = {0,0};


 /*** uninterpreted function side 0: ***/ 
  /* Declarations: */


int  rvs0_G(int  n)
{
  int  retval;

  /* save values of input arguments: */
  rv_UF_G_array[rv_UF_G_count[0]].in_n = n;	/* Generated by:  gen_side0_uf(608)(613)(379)(293)/ rv_temps.cpp:362*/
  /* save values of input globals: */

  /* generate and save values of output arguments and globals: */
  rv_UF_G_array[rv_UF_G_count[0]].out_retval = retval = (int )nondet_long();	/* Generated by:  gen_side0_uf(608)(613)(379)(293)(608)(613)(379)(265)/ rv_temps.cpp:412*/
  rv_UF_G_count[0]++;

  return retval;
}


/*** uninterpreted function side 1: ***/ 
int  rvs1_G(int  n)
{
  int  retval;

  _Bool found = 0;
  _Bool equal = 1;
  int found_ind = -1;
  int rv_uf_ind = rv_UF_G_count[0]-1;
  for(; rv_uf_ind >= 0; rv_uf_ind--) {
    equal = (rv_UF_G_array[rv_uf_ind].in_n == n);	/* Generated by:  gen_side1_uf(608)(613)(379)(273)/ rv_temps.cpp:419*/
    if( equal ) { 
      found = 1;
      found_ind = rv_uf_ind;
      rv_UF_G_array[rv_uf_ind].reach_equiv_flag = 1;
    }
  }

  if( found ) /* input values were found among the saved values */
  {
   /* Sides 0 and 1 are partially equivalent.
    * Returning the results of side 0: */
  retval = rv_UF_G_array[found_ind].out_retval;	/* Generated by:  gen_input_found_case(608)(613)(379)(284)/ rv_temps.cpp:362*/

  } else {

    /* Assert reach-equivalence: side 0 and 1 inputs are equal.*/
    assert( 0 );

  }
  rv_UF_G_count[1]++;

  return retval;
}






void rv_init()
{
}


void rv_check()
{
  /* check reach-equivalence of the inputs for each uninterpreted function: */
  int i;

  /* checking reach-equivalence of all the inputs of array rv_UF_G_array : */
  for (i = rv_UF_G_count[0] - 1; i >= 0; --i)
    assert( rv_UF_G_array[i].reach_equiv_flag );
}

  /* now starting main */

int main()
{
  _Bool equal = 1;
  /* Declarations: */
  int  retval0;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  int  retval1;	/* Generated by:  gen_retval_declarations/ rv_temps.cpp:269*/
  int  rvs0_n;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/
  int  rvs1_n;	/* Generated by:  gen_arg_decl(107)/ gen_decl_low(148)(107)/ gen_decl_low(148)/ rv_temps.cpp:274*/


  /* output: */
  /* Allocations for side 0: */
  /* Allocations for side 1: */

  rv_init();

  /* Assume input args are equal: */ 
  rvs0_n = rvs1_n;	/* Generated by:  gen_args_equality(608)(613)(379)(293)/ rv_temps.cpp:362*/

  /* run each side's main() */
  retval0 = chk0_M(rvs0_n);
  retval1 = chk1_M(rvs1_n);

  rv_check();

  return 0;
}

