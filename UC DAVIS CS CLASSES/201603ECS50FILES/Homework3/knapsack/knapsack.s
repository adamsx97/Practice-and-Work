.global knapsack
.equ wordsize, 4

knapsack:

  push %ebp
  movl %esp, %ebp
  subl $2*wordsize, %esp

  #unsigned int i;
  .equ i, -1*wordsize
  #unsigned int best_value;
  .equ best_value, -2*wordsize
  #int* weights
  .equ weights, 2*wordsize
  #unsigned int* values
  .equ values, 3*wordsize
  #unsigned int num_items
  .equ num_items, 4*wordsize
  #int capacity
  .equ capacity, 5*wordsize
  #unsigned int cur_value
  .equ cur_value, 6*wordsize

  #best_value = cur_value;
  movl cur_value(%ebp), %eax
  movl %eax, best_value(%ebp)

  #for(i = 0; i < num_items; i++)
  movl $0, %esi
  #esi will hold i
  for_loop_start:

    cmpl %esi, num_items(%ebp)
    #i < num_items
    #num_items - i > 0
    jle for_loop_end

    #if(capacity - weights[i] >= 0 )
    if_start:

      movl capacity(%ebp), %ebx #ebx = capacity
      movl weights(%ebp), %ecx #ecx = weights
      subl (%ecx, %esi, wordsize), %ebx #capacity - weights[i]
      cmpl $0, %ebx
      jl if_end

      movl values(%ebp), %edx #edx = values

      #best_value = max(best_value, knapsack(weights + i + 1, values + i + 1, num_items - i - 1, 
      #               capacity - weights[i], cur_value + values[i]));
      recursion_start:

        #cur_value + values[i]
        movl cur_value(%ebp), %edi
        addl (%edx, %esi, wordsize), %edi
        push %edi

        #capacity - weights[i]
        movl capacity(%ebp), %edi
        subl (%ecx, %esi, wordsize), %edi
        push %edi

        #num_items - i - 1
        movl num_items(%ebp), %edi
        subl %esi, %edi
        decl %edi
        push %edi

        #values + i + 1
        movl values(%ebp), %edi
        leal (%edi, %esi, wordsize), %edi
        leal wordsize(%edi), %edi
        push %edi

        #weights + i + 1
        movl weights(%ebp), %edi
        leal (%edi, %esi, wordsize), %edi
        leal wordsize(%edi), %edi
        push %edi

        movl %esi, i(%ebp)
        call knapsack
        addl $5*wordsize, %esp

        movl i(%ebp), %esi #eax = i
        movl best_value(%ebp), %edi ############
        push %eax
        push %edi
        call max
        addl $2*wordsize, %esp
        movl %eax, best_value(%ebp)

    if_end:

      #i++
      incl %esi
      jmp for_loop_start

  for_loop_end:

    #done
    movl %ebp, %esp
    pop %ebp
    ret




max:
  
  push %ebp
  movl %esp, %ebp

  .equ a, 2*wordsize
  .equ b, 3*wordsize

  movl a(%ebp), %eax
  movl b(%ebp), %ebx

  #if(a > b) return a
  #else return b
  #a > b
  #a - b > 0
  cmpl b(%ebp), %eax
  jle b_larger
  jmp max_end

  b_larger:
    movl b(%ebp), %eax 
    jmp max_end

  max_end: 
    movl %ebp, %esp
    pop %ebp
    ret
