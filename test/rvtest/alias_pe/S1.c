/* Headers for predefined outlined functions */
float rv_mult(float x, float y);
float rv_div(float x, float y);
int rv_mod (int x, int y);
# 1 ".//alias1.c"
# 1 "<command-line>"
# 1 ".//alias1.c"
# 1 "/cygdrive/c/NewRVT/debug/../tools/scripts/../ansi-c-lib/stdlib.h" 1



# 1 "/cygdrive/c/NewRVT/debug/../tools/scripts/../ansi-c-lib/sys/types.h" 1



typedef int pid_t;
typedef unsigned int size_t;
typedef unsigned char u_char;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;

typedef unsigned int off_t;
typedef unsigned int mode_t;
# 25 "/cygdrive/c/NewRVT/debug/../tools/scripts/../ansi-c-lib/sys/types.h"
typedef unsigned int u_int;

typedef int uid_t;
# 5 "/cygdrive/c/NewRVT/debug/../tools/scripts/../ansi-c-lib/stdlib.h" 2
# 14 "/cygdrive/c/NewRVT/debug/../tools/scripts/../ansi-c-lib/stdlib.h"
void exit(int status);
char *getenv(const char *name);
int system(const char *string);
void abort(void);

void *calloc(size_t nmemb, size_t size);
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);

int atoi(const char *nptr);
long atol(const char *nptr);
long long atoll(const char *nptr);
long long atoq(const char *nptr);

float atof(const char *nptr);

int rand(void);
void srand(unsigned int seed);

long int random(void);
void srandom(unsigned int seed);
char *initstate(unsigned int seed, char *state, size_t n);
char *setstate(char *state);

int mkstemp (const char* temp);

void qsort(void * base, size_t num, size_t width,
           int (*fncompare)(const void *, const void *) );
# 2 ".//alias1.c" 2


int F(int *n){
 if ( *n <= 0 ) return 1;
 *n = *n - 1;
 return 0;
}

int main(){
 int i, out = 0;
 int *p = (int *)malloc(sizeof(int));
 *p = 10;
 out = F(p);
 *p = 2;
 return out;
}
