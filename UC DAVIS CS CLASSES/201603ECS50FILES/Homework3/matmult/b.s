.global matMult
matMult:

.equ wordsize, 4
.equ num_cols_b, 7*wordsize
.equ num_rows_b, 6*wordsize
.equ b, 5*wordsize
.equ num_cols_a, 4 * wordsize
.equ num_rows_a, 3 * wordsize
.equ a, 2 * wordsize
.equ c, -1*wordsize
.equ i, -2*wordsize
.equ j, -3*wordsize
.equ x, -4*wordsize
.equ sum, -5*wordsize

prologue:
  pushl %ebp
  movl %esp, %ebp
  
  .rept 7
  pushl $0
  .endr

begin:


  movl num_rows_a(%ebp), %eax
  .rept 2
  addl %eax, %eax
  .endr
  pushl %eax
  call malloc #eax holds a pointer to c which is a pointer to pointers
  movl %eax, c(%ebp)

#for loop
forone:
  movl num_rows_a(%ebp), %eax
  cmp i(%ebp), %eax #eax - i*%eax)
    jle doneone
  movl num_cols_b(%ebp), %eax
  .rept 2
  addl %eax, %eax
  .endr #numcols * 4
  push %eax
  call malloc
  #eax holds the address of the allocated space 
  
  movl c(%ebp), %edx

  .rept 4
  addl i(%ebp), %edx #gives &(c[i])
  .endr
  movl %eax, (%edx) #c[i] = the address to the space allocated
  incl i(%ebp)
  jmp forone

doneone:

movl $0, i(%ebp)
  
loopouter:
  #check
  movl i(%ebp), %eax
  cmp %eax, num_rows_a(%ebp)
  jle endloopouter
  #endcheck

loopmid:
  #check
  movl x(%ebp), %eax
  cmp %eax, num_cols_b(%ebp)
  jle endloopmid
  #endcheck

loopin:
  #check IF FALSE
  movl j(%ebp), %eax
  cmp %eax, num_rows_b(%ebp)
  jle endloopin
  #endcheck
  #body

  movl a(%ebp), %eax # &a[0]
  .rept 4
    addl i(%ebp), %eax
  .endr #&a[i]
  movl (%eax), %eax #a[i]
  .rept 4
  addl j(%ebp), %eax
  .endr #&a[i][j]

  movl (%eax), %eax #a[i][j]


  #setting scratch 2
  movl b(%ebp), %edx #&b[0]
        
  .rept 4
    addl j(%ebp), %edx
  .endr #&(b[i])

  movl (%edx), %edx #b[i] 
        
  .rept 4
    addl x(%ebp), %edx
  .endr #&(b[i][j])
  
  movl (%edx), %edx #b[i][j]
  mull %edx #%eax = a[i][j] * b[i][j]

  addl %eax, sum(%ebp) #sum += scratch1 * scratch2
      
  #endbody
      
  
  incl j(%ebp)
  jmp loopin

endloopin:
  movl $0, j(%ebp)
  movl c(%ebp), %eax #&c[0]
  .rept 4
    addl i(%ebp), %eax
  .endr #&(c[i])
  
  movl (%eax), %eax #c[i]
  
  .rept 4
    addl x(%ebp), %eax 
  .endr #&(c[i][j])

  movl sum(%ebp), %ecx
  movl %ecx, (%eax) #c[i][j] = sum
  movl $0, sum(%ebp)
  incl x(%ebp)

  jmp loopmid

endloopmid:

  movl $0, x(%ebp)  
  incl i(%ebp)
  jmp loopouter

endloopouter:
  movl c(%ebp), %eax #&(c[0])

epilogue: 
  movl %ebp,  %esp
  pop %ebp
  ret