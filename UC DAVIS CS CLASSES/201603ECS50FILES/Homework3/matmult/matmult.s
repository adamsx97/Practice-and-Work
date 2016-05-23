#int** matMult(int** a, int num_rows_a, int num_cols_a, int** b, int num_rows_b, int num_cols_b)
#{
#  int** c;
#  c = (int*)malloc(num_rows_a * sizeof(int*));
#
#  for (i = 0; i < num_rows_a; i++)
#    c[i] = (int**)malloc(num_cols_b * sizeof(int));
#
#  int i, j, k;
#  for (i = 0; i < num_rows_a; i++)
#  {
#    for (j = 0; j < num_cols_b; j++)
#      {
#      c[i][j] = 0;
#      for (k = 0; k < num_cols_a; k++)
#        c[i][j] = c[i][j] + a[i][k] * b[k][j];
#      }
#  }
#  return c;
#}


.global matMult

.equ wordsize, 4

matMult:

# prologue
  push %ebp
  movl %esp, %ebp

  .equ a, 2*wordsize #(%ebp)
  .equ b, 3*wordsize #(%ebp)
  .equ num_rows_a, 4*wordsize #(%ebp)
  .equ num_cols_a, 5*wordsize #(%ebp)
  .equ num_rows_b, 6*wordsize #(%ebp)
  .equ num_cols_b, 7*wordsize #(%ebp)
  .equ c, -1*wordsize #(%ebp)
  .equ i, -2*wordsize #(%ebp)
  .equ j, -3*wordsize #(%ebp)
  .equ k, -4*wordsize #(%ebp)
  .equ sum, -5*wordsize #(%ebp)
  subl $20, %esp # make space

  #EAX is c
  #EBX is a
  #ECX is i
  #EDX is b

  push %ebx

  # c = (int*)malloc(num_rows_a * sizeof(int*));
  movl num_rows_a(%ebp), %eax # get rows
  shll $2, %eax # num_rows * sizeof(int *)
  pushl %eax # give malloc its argument
  call malloc # Call malloc
  addl $wordsize, %esp

  # save c
  movl %eax, c(%ebp)

  movl $0, i(%ebp)
  # i = 0

  malloc_c_for_loop_start:
    #  for(i = 0; i < num_rows_a; i++)
    movl i(%ebp), %edx
    cmpl num_rows_a(%ebp), %edx
      # jump if ecx - num_rows_a > 0
      jge malloc_c_for_loop_end

    movl num_cols_b(%ebp), %ebx
    # malloc(num_cols_b * sizeof(int))
    shll $2, %ebx
    push %ebx
    call malloc
    addl $wordsize, %esp

    # c[i] = (int**)malloc(num_cols_b * sizeof(int));
    movl c(%ebp), %edx #restore C
    movl i(%ebp), %ebx
    movl %eax, (%edx, %ebx, wordsize)

    incl i(%ebp) # i++
    jmp malloc_c_for_loop_start

  malloc_c_for_loop_end:

  movl $0, i(%ebp)
  movl $0, j(%ebp)
  movl $0, k(%ebp)
  for_num_rows_a_loop_start:
    #for (i = 0; i < num_rows_a; i++)
    movl i(%ebp), %ecx
    cmpl num_rows_a(%ebp), %ecx
      jge for_num_rows_a_loop_end

    movl $0, j(%ebp)
    for_num_cols_b_loop_start:
      #for (j = 0; j < num_cols_b; j++)
      movl j(%ebp), %ecx
      cmpl num_cols_b(%ebp), %ecx
        jge for_num_cols_b_loop_end

      movl $0, k(%ebp)
      movl $0, sum(%ebp) #c[i][j] = 0;
      for_add_loop_start:
      #for (k = 0; k < num_cols_a; k++)
        movl k(%ebp), %ecx
        cmpl num_cols_a(%ebp), %ecx
          jge for_add_loop_end

        movl a(%ebp), %ebx # get a
        #.rept 4
        #  addl i(%ebp), %ebx  # get *a[i]
        #.endr
        movl i(%ebp), %ecx
        movl (%ebx, %ecx, wordsize), %ebx
        #movl (%ebx), %ebx # get a[i]
        #.rept 4
        #  addl k(%ebp), %ebx  # get *a[i][k]
        #.endr
        movl k(%ebp), %ecx
        movl (%ebx, %ecx, wordsize), %ebx
        #movl (%ebx), %ebx # get a[i][k]

        movl b(%ebp), %edx # get b
        #.rept 4
        #  addl k(%ebp), %edx  # get *b[k]
        #.endr
        movl k(%ebp), %ecx
        movl (%edx, %ecx, wordsize), %edx
        #movl (%edx), %edx # get b[k]
        #.rept 4
        #  addl j(%ebp), %edx  # get *b[k][j]
        #.endr
        movl j(%ebp), %ecx
        movl (%edx, %ecx, wordsize), %edx
        #movl (%edx), %edx # get b[k][j]

        movl %ebx, %eax # put a[i][k] into %eax for multiplication
        mull %edx # a[i][k] * b[k][j]
        addl %eax, sum(%ebp) # c[i][j] + a[i][k] * b[k][j];

        incl k(%ebp) # k++
        jmp for_add_loop_start

      for_add_loop_end:

      movl c(%ebp), %eax # Get c
      #.rept 4
      #  addl i(%ebp), %eax  # get *c[i]
      #.endr
      movl i(%ebp), %ecx
      movl (%eax, %ecx, wordsize), %eax
      #movl (%eax), %eax # get c[i]
      #.rept 4
      #  addl j(%ebp), %eax  # get *c[i][j]
      #.endr
      movl j(%ebp), %ecx
      movl sum(%ebp), %ebx
      movl %ebx, (%eax, %ecx, wordsize)
      #movl %ebx, (%eax)  c[i][j] = c[i][j] + a[i][k] * b[k][j];

      incl j(%ebp)
      jmp for_num_cols_b_loop_start
    for_num_cols_b_loop_end:

    incl i(%ebp)
    jmp for_num_rows_a_loop_start
  for_num_rows_a_loop_end:

  movl c(%ebp), %eax

epilogue:
  movl %ebp,  %esp
  pop %ebp
  ret
