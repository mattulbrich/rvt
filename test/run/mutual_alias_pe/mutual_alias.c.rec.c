

typedef int  (*rvt_FuncPtrSubst_int__const_void_ptr_const_void_ptr)(void  *rv_arg_0, void  *rv_arg_1);
float  rv_mult(float  x, float  y);
float  rv_div(float  x, float  y);
int  rv_mod(int  x, int  y);
typedef int  pid_t;
typedef unsigned int  size_t;
typedef unsigned char  u_char;
typedef unsigned long  ulong;
typedef unsigned short  ushort;
typedef unsigned int  uint;
typedef unsigned int  off_t;
typedef unsigned int  mode_t;
typedef unsigned int  u_int;
typedef int  uid_t;
void  exit(int  status);
char  *getenv(char  *name);
int  system(char  *string);
void  abort();
void  *calloc(size_t  nmemb, size_t  size);
void  *malloc(size_t  size);
void  free(void  *ptr);
void  *realloc(void  *ptr, size_t  size);
int  atoi(char  *nptr);
long  atol(char  *nptr);
long long  atoll(char  *nptr);
long long  atoq(char  *nptr);
float  atof(char  *nptr);
int  rand();
void  srand(unsigned int  seed);
long  random();
void  srandom(unsigned int  seed);
char  *initstate(unsigned int  seed, char  *state, size_t  n);
char  *setstate(char  *state);
int  mkstemp(char  *temp);
void  qsort(void  *base, size_t  num, size_t  width, rvt_FuncPtrSubst_int__const_void_ptr_const_void_ptr  fncompare);
void  myempty();

int  F(int  *n);
int  M(int  n);
int  F(int  *n);

int  G(int  n);

int  M(int  n);

int  main();

void  myempty()
{
}


int  F(int  *n)
{
  int  *p = (int *) (malloc(sizeof(int ) ));

  *p = *n - 1;
  if (*n <= 0)
    return 1;
  if (*n == 1)
    return F(p);
  return *n - M(*n);
}


int  G(int  n)
{
  int  *p = (int *) (malloc(sizeof(int ) ));

  *p = n - 1;
  return F(p);
}


int  M(int  n)
{
  if (n < 2)
    return 1;
  return n - G(n);
}


unsigned char  Loop_main_for1(int  *rvp_i, int  *rvp_out, int  **rvp_p, int  *rvp_rvretval);

unsigned char  Loop_main_for2(int  *rvp_i, int  *rvp_rvretval);


int  main()
{
  int  rvretval = 0;
  int  i;
  int  out = 0;
  int  *p = (int *) (malloc(sizeof(int ) ));

  {
    i = 0;
    Loop_main_for1(&i,&out,&p,&rvretval);
  }

  {
    i = 0;
    Loop_main_for2(&i,&rvretval);
  }

  return out;
}

unsigned char  Loop_main_for1(int  *rvp_i, int  *rvp_out, int  **rvp_p, int  *rvp_rvretval)
{
  if( !(*rvp_i < 20) )
    return 0;

  {
    **rvp_p = *rvp_i;
    *rvp_out += F(*rvp_p);
  }

  (*rvp_i)++;
  return 0;
}

unsigned char  Loop_main_for2(int  *rvp_i, int  *rvp_rvretval)
{
  if( !(*rvp_i < 20) )
    return 0;

  {
    myempty();
  }

  (*rvp_i)++;
  return 0;
}




void __CPROVER_assume(_Bool);

/* Hub functions for indirect function calls: */
