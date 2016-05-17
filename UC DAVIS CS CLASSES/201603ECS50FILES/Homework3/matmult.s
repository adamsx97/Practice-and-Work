/*
int** matMult(int** mat_a, int rows_mat_a, int cols_mat_a, int** mat_b, int rows_mat_b, int cols_mat_b)
{
  int** mat_c;
  mat_c = (int*)malloc(rows_mat_a * sizeof(int*));

  int i, j, k;
  for (i = 0; i < rows_mat_a; i++)
  {
    mat_c[i] = (int**)malloc(cols_mat_b * sizeof(int));
    for (j = 0; j < cols_mat_b; j++)
      {
      mat_c[i][j] = 0;
      for (k = 0; k < cols_mat_a; k++)
        mat_c[i][j] = mat_c[i][j] + mat_a[i][k] * mat_b[k][j];
      }
  }
  return mat_c;
}
*/

.global matMult

.equ wordsize, 4

matMult:

# prologue
  push %ebp
  movl %esp, %ebp
  subl $3 * wordsize, %esp

  .equ mat_a, 2*wordsize #(%ebp)
  .equ mat_b, 3*wordsize #(%ebp)
  .equ rows_mat_a, 4*wordsize #(%ebp)
  .equ cols_mat_a, 5*wordsize #(%ebp)
  .equ rows_mat_b, 6*wordsize #(%ebp)
  .equ cols_mat_b, 7*wordsize #(%ebp)
  .equ mat_c, -1*wordsize #(%ebp)
  .equ i, -2*wordsize #(%ebp)
  .equ j, -3 wordsize #(%ebp)
  .equ k, -4 wordsize #(%ebp)

  push %ebx #save ebx
  push %esi #save esi

  #EAX is mat_c
  #ECX is i
  #EDX is j
  #EDI is k

# mat_c = (int*)malloc(rows_mat_a * sizeof(int*));
movl rows_mat_a(%ebp), %eax # get rows
shll $2, %eax # num_rows * sizeof(int *)
push %eax # give malloc its argument
call malloc # Call malloc
addl $1*wordsize, %esp # remove arguments from stack

# save mat_c
movl %eax, mat_c(%ebp)

movl $0, %ecx
# i = 0

rows_for_loop_start:
  #  for(i = 0; i < rows_mat_a; i++)
  cmpl rows_mat_a(%ebp), %ecx
    # jump if ecx - rows_mat_a > 0
    jge rows_for_loop_end

  # save i
  movl %ecx, i(%ebp)

  # malloc(cols_mat_b * sizeof(int))
  call malloc

  # mat_c[i] = (int**)malloc(cols_mat_b * sizeof(int));
  movl mat_c(%ebp), %edx #restore C
  movl i(%ebp), %ecx #restore i
  movl %eax, (%edx, %ecx, wordsize)
  movl %edx, eax #restoring C still

  movl $0, %edx
  # j = 0

  cols_for_loop_start:
    # for (j = 0; j < cols_mat_b; j++)
    cmpl cols_mat_b(%ebp), %edx
      # jump if edx - cols_mat_b > 0
      jge cols_for_loop_end

    

  cols_for_loop_end:

  incl %ecx # i++
  jmp rows_for_loop_start

rows_for_loop_end:

epilogue:
  