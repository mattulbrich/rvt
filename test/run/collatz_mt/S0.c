# 1 "./collatz.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "./collatz.c"
int f(int a) {
 if (a > 1) {
  a = (a&1)? 3*a + 1 : a/2;
  return f(a);
 }
 return a;
}

int main() {
 int i, result;
 result = f(i);
}
