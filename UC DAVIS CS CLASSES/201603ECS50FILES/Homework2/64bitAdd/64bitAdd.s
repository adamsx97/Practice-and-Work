.global _start

.data
num1:
    num1upper: .long 0
    num1lower: .long 0

num2:
    num2upper: .long 0
    num2lower: .long 0

.text

_start:
#eax will hold the lower 32 bits of the sum
#edx will hold the upper 32 bits of the sum
    movl $0, %eax
    movl $0, %edx

    movl num1lower, %eax
    movl num1upper, %edx

    addl num2lower, %eax
    adcl num2upper, %edx

done:
    movl %eax, %eax
