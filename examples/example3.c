// example3.c
//
// The third example in Smashing The Stack For Fun and Profit.
// Showing how to alter the return address through pointer manipulation.
//
// To compile: "gcc -o example3.exe example3.c -fno-stack-protector"

#include <stdio.h>

void overflow(int a, int b, int c) {
  char buffer1[5];
  char buffer2[10];
  char *ret = buffer1 + 24;
  *ret += 35;
}

int main() {
  int x;

  x = 0;
  overflow(1, 89, 12);
  
  // The remainder of the main function is to practice
  // skipping around after returning from the "function"
  x = 1;
  goto foo;

 bar2:
  x = 2;
  goto foo;

 bar3:
  x = 3;
  goto foo;

 foo:
  printf("%d kjsdf;ak\n", x);
  
  if (x <= 1) {
    goto bar2;
  }
  if (x <= 2){
    goto bar3;
  }
}
