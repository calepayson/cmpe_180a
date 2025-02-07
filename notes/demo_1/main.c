#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(int argc, char *argv[]) {
  printf("argc = %d\n", argc);
  printf("argc[0] = %s\n", argv[0]);

  if (argc < 2) {
    printf("Argument count should be 2 or larger\n");
    return 1;
  }

  int n = atoi(argv[1]);
  printf("factorial(%d) = %d\n", n, factorial(n));

  return 0;
}

int factorial(int n) {
  int f = 1;
  /* f(n) = n * (n-1) * (n-2)...1 */
  for (int i = 1; i <= n; i++) {
    f = f * i;
  }
  return f;
}
