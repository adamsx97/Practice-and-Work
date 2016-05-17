.global get_combs
.equ wordsize, 4

get_combs:

  push %ebp
  movl %esp, %ebp
  subl $5*wordsize, %esp

  #int* items
  .equ items, 2*wordsize
  #int k
  .equ k, 3*wordsize
  #int len
  .equ len, 4*wordsize
  #int i = 0;
  .equ i, -1*wordsize
  #int* curr;
  .equ curr, -2*wordsize
  #int** combs;
  .equ combs, -3*wordsize
  #int comb_count = 0;
  .equ comb_count, -4*wordsize
  movl $0, comb_count(%ebp)
  #int numofcombs = num_combs(len, k);
  .equ numofcombs, -5*wordsize

  push k(%ebp)
  push len(%ebp)
  call num_combs
  addl $2*wordsize, %esp
  movl %eax, numofcombs(%ebp)
  #combs = malloc(numofcombs * sizeof(int*));
  shll $2, %eax
  push %eax
  call malloc
  addl $1*wordsize, %esp
  movl %eax, combs(%ebp)

  #curr = malloc(k * sizeof(int));
  movl k(%ebp), %ebx
  shll $2, %ebx
  push %ebx
  call malloc
  #addl $1*wordsize, %esp
  movl %eax, curr(%ebp)

  #for(i = 0; i < numofcombs; i++)
  movl $0, %ecx #ecx = i
  #i < numofcombs
  #numofcombs - i > 0
  for_loop_start:

    cmpl %ecx, numofcombs(%ebp)
    jle for_loop_end

    movl %ecx, i(%ebp)
    call malloc
    movl i(%ebp), %ecx
    movl combs(%ebp), %ebx

    #combs[i] = malloc(k * sizeof(int));
    movl %eax, (%ebx, %ecx, wordsize)
    incl %ecx
    jmp for_loop_start


  for_loop_end:

    addl $(1*wordsize), %esp

# store(items, combs, curr, &comb_count, k, len, k, 0);
  movl %ecx, i(%ebp)
  push $0 
  push k(%ebp)
  push len(%ebp)
  push k(%ebp)
  leal comb_count(%ebp), %ebx
  push %ebx
  push curr(%ebp) 
  push combs(%ebp)
  push items(%ebp) 
  call store_combs
  addl $(8*wordsize), %esp 
  movl i(%ebp), %ecx
  movl combs(%ebp), %eax 

get_combs_done:

  movl %ebp, %esp
  pop %ebp
  ret


store_combs:

  push %ebp
  movl %esp, %ebp
  subl $1*wordsize, %esp

  #int* items
  .equ items, 2*wordsize
  #int** combs
  .equ combs, 3*wordsize
  #int* curr
  .equ curr, 4*wordsize
  #int* comb_count
  .equ comb_count, 5*wordsize
  #const int k
  .equ k, 6*wordsize
  #const int len
  .equ len, 7*wordsize
  #int count
  .equ count, 8*wordsize
  #int start
  .equ start, 9*wordsize
  #int i;
  .equ i, -1*wordsize
  movl start(%ebp), %ecx


  if_for_start:

    #if(count == 0)
    cmpl $0, count(%ebp)
    jnz else_for_start

    #memcpy(combs[*comb_count], curr, k * sizeof(int));
    movl k(%ebp), %ebx
    shll $2, %ebx
    push %ebx
    push curr(%ebp)

    movl combs(%ebp), %edx
    movl comb_count(%ebp), %esi
    movl (%esi), %eax
    movl (%edx, %eax, wordsize), %edx
    push %edx
    call memcpy
    #(*comb_count) ++;
    movl comb_count(%ebp), %esi
    incl (%esi)
    #return;
    jmp store_combs_done


  else_for_start:

    #for(i = start; i < len; i++)
    cmpl %ecx, len(%ebp)
    #i < len
    #len - i > 0
    jle store_combs_done

elsefor: 

    #esi = items
    movl items(%ebp), %esi
    #esi = items[i]
    movl (%esi, %ecx, wordsize), %esi
    movl %ecx, i(%ebp)

    movl k(%ebp), %edx
    subl count(%ebp), %edx
    movl curr(%ebp), %edi

    #curr[k - count] = items[i];
    movl %esi, (%edi, %edx, wordsize)

    movl %ecx, i(%ebp)

    #store_combs(items, combs, curr, comb_count, k, len, count - 1, i + 1);
    incl %ecx
    push %ecx

    movl count(%ebp), %ebx 
    decl %ebx 
    push %ebx
    push len(%ebp)
    push k(%ebp)
    push comb_count(%ebp)
    push curr(%ebp)
    push combs(%ebp)
    push items(%ebp)
    call store_combs
    addl $8*wordsize, %esp

    movl i(%ebp), %ecx
    incl %ecx
    jmp else_for_start

store_combs_done:

  movl %ebp, %esp
  pop %ebp
  ret
