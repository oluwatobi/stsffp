// example2.c
//
// Second example in Smashing The Stack For Fun and Profit.
// Showing a trivial example of stack buffer overflow error.
// When executed leads to a segmentation fault (Abort Trap 6
// -- accessing memory that one does not own).
// 
// To compile: "gcc example2.c -o example2.exe -fno-stack-protector"

#include <string.h>

void function(char *str) {
  char buffer[16];

  // Unsafe!! No bounds checking!!!!
  // Copies a string buffer until the end of the copied string
  // buffer is reached. Since there is no bounds checking what
  // we can end up completely over writting the locals section
  // of the stack and potentially end up attempting to accessing
  // memory that we do not own.
  strcpy(buffer, str);
}

int main() {
  // Buffer to be filled with values that are to be copied in
  // the array in function.
  char large_string[128];
  int i;
  for (i = 0; i < 127; i++) {
    large_string[i] = 'A';
  }

  function(large_string);
}
