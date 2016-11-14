char shellcode[] = "";

void main() {
  int *ret;
  ret = (int *) &ret + 4;
  (*ret) = (int) shellcode;
}
