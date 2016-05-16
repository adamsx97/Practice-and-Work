.global _start
.data
a: .long 0

b: .long 0

.text
_start:

movl a, %eax
movl b. %ebx
movl $2, a
movl $5, b
movl a, %eax
movl b, %ebx
mul %ebx
push %eax

done:

movl %eax, %eax
pop %eax
