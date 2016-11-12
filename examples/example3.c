// example3.c
//
// The third example in Smashing The Stack For Fun and Profit.
// Showing how to alter the return address through pointer manipulation.
//
// To compile: "gcc -o example3.exe example3.c -fno-stack-protector"

#include <stdio.h>

void function(int a, int b, int c) {
  char buffer1[5];
  char buffer2[10];
  int *ret = buffer1 + 24;
  (*ret) += 7;
}

int main() {
  int x;
  
  x = 0;
  function(1, 2, 3);
  x = 1;
  printf("%d\n", x);
}
