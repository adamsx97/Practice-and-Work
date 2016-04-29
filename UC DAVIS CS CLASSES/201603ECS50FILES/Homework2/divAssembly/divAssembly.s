.global _start
.data
dividend: .long 0

divisor: .long 0

quotient: .long 0

remaind: .long 0


.text
_start:

#  buf = divident;
movl dividend, %ecx
movl %ecx, buf

if_start:
#   if (buf < divisor)
    movl buf, %ecx
    cmpl %ecx, divisor
    # jump if divisor - buf <= 0
        jle if_end
    movl $0, quotient
    # quotient = 0;
    movl buf, %ecx
    movl %ecx, remaind
    # remaind = buf;

if_end:

else_if_start:
#   else if (buf == divisor)
    movl buf, %ecx
    cmpl %ecx, divisor
    # jump if divisor - buf != 0
        jnz else_if_end
    movl $1, quotient
    # quotient = 1;
    movl $0, remaind
    # remaind = 0;

else_if_end:

else_start:
#   else
    movl $0, quotient
    # quotient = 0;
    movl $0, remaind
    # remaind = 0;
    movl $0, %edx
    # edx will hold i
    
    for_loop_start:
        # for (int i = 0; i < 32; ++i)
        cmpl %edx, $32
        # jump if 32 - i <= 0
            jle for_loop_end

        shl quotient
        # quotient <<= 1;
        shl remaind
        # remaind <<= 1;

        #if ((buf & 0x80000000) != 0)
        movl buf, %ebx
        if_start1:
            and $0x80000000, %ebx
            # buf & 0x80000000
            cmpl %ebx, $0
                # jump if 0 - ebx != 0
                jnz if_end1
            add $1, remaind
            # remaind++;
        if_end1:

        if_start2:
        #   if (remaind >= divisor)
            movl remaind, %ecx
            cmpl %ecx, divisor
            # jump if divisor - remaind > 0
                jg if_end2
            movl divisor, %ecx
            sub %ecx, remaind
            # remaind -= divisor;
            add $1, quotient
            # quotient++;
        if_end2:

        shl buf
        # buf <<= 1;
    for_loop_end:
else_end:

done:

movl %eax, %eax
