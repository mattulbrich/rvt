
void  swap(short  *a, short  *b)
{
 short  tmp = *a;
 *a = *b;
 *b = tmp;
}

short  gcd(short  a, short  b)
{
 while (a != 0)
 {
  b = b%a;
  swap(&a,&b);  
 }

 return b;
}

short  main()
{
 short  a;
 short  b;
 gcd(a,b);
 return 0;
}
