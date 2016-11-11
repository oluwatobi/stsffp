// example1.c
//
// First example in Smashing The Stack For Fun and Profit
// Used as an example to see what a program does to prepare
// for function calls.
// Use the command "gcc -S -o example1.s example1.c" to see
// the assembly output.

void function(int a, int b, int c) {
  char buffer1[5];
  char buffer2[10];
}

int main() {
  function(1, 2, 3);
}
