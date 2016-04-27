.global _start
.data
dividend:
  .long 0

divisor:
  .long 0

quotient:
  .long 0

remaind:
  .long 0

buf:
  .long 0

.text
_start:

movl dividend, buf
if_start:
    cmpl buf, divisor
    # buf < divisor
    # divisor - fub > 0
        jl if_end
    movl $0, quotient
    movl buf, remaind

if_end:

else_if_start:
    cmpl buf, divisor
    # buf == divisor
        jnz else_if_end
    movl $1, quotient
    movl $0, remaind

else_if_end:

else_start:
    movl $0, quotient
    movl $0, remaind
    movl $0, %edx # edx will hold i
    for_loop_start:
        # i < 32
        # 32 - i > 0
        cmpl %edx, $32
        jl for_loop_end

    shl quotient
    shl remaind
    movl $0, %ebx
      if_start1:
        and buf , $0x80000000
        cmpl buf, $0
          jz if_end1
        add $1, remaind
      if_end1:

      if_start2:
        cmpl remaind, divisor
        # remaind >= divisor
        # divisor - remaind <= 0
        jle if_end2
        sub divisor, remaind
        add $1, quotient
      if_end2:
    shl buf
else_end:
done:

movl %eax, %eax
