// overflow1.c

char shellcode[] = "";

char large_string[128];

void main() {
  char buffer[96];
  int i;
  long *long_ptr = (long *) large_string;

  for (i = 0; i < 32; i++) {
    *(long_ptr + i) = (int) buffer;
  }

  for (i = 0; i < strlen(shellcode); i++) {
    large_string[i] = shellcode[i];
  }

  strcpy(buffer, large_string);
}