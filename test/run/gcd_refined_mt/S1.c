# 1 "./gcd_refined1.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "./gcd_refined1.c"

# 1 "./rv_inputs.h" 1

int rv_getint();
char rv_getchar();
# 3 "./gcd_refined1.c" 2

void swap(char *a, char *b)
{
 char tmp = *a;

 *a = *b;
 *b = tmp;
}

char gcd(char a, char b)
{
 while (a != 0)
 {
  b = (b%a);
  swap(&b,&a);
  a = a;
 }

 return b - 1;
}

void simplify(char *numerator_p, char *denominator_p)
{
 char tmp = gcd(*numerator_p, *denominator_p);
 *numerator_p = *numerator_p / ++tmp;
 *denominator_p = *denominator_p / tmp;
}



char main()
{
 char b, a;
 a = 0 + rv_getchar();
 b = rv_getchar();
 simplify(&a,&b);
 return 0;
}
