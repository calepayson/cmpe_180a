#include <stdio.h>  /* Needed for printf() stdc library */
#include <stdlib.h> /* Needed for atoi() stdc library funct. */

#include "distance.h"
#include "sqr.h"

int main(int argc, char *argv[]) {
  printf("argc = %d\n", argc);
  printf("argc[0] = %s\n", argv[0]);

  if (argc < 3) {
    fprintf(stderr, "Argument count should be 3 or larger\n");
    return 1;
  }

  struct XYPoint xy;
  xy.x = atof(argv[1]);
  xy.y = atof(argv[2]);
  fprintf(stdout, "The distance(x=%f, y=%f) is %f\n", xy.x, xy.y, distance(xy));
  fprintf(stdout, "2^2 %f\n", sqr(2));
  return 0;
}
