// example2.c
//
// Second example in Smashing The Stack For Fun and Profit.
// Showing a trivial example of stack buffer overflow error.
// When executed leads to a segmentation fault (Abort Trap 6
// -- accessing memory that one does not own).
// 
// To compile: "gcc example2.c -o example2.exe"

#include <string.h>

void function(char *str) {
  char buffer[16];

  // Unsafe!! No bounds checking!!!!
  strcpy(buffer, str);
}

int main() {
  char large_string[128];
  int i;
  for (i = 0; i < 127; i++) {
    large_string[i] = 'A';
  }
  large_string[17] = '\0';

  function(large_string);
}
