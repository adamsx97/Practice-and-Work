/*
 * ECS30
 * SID:913186040
 * Chengeng Xiao
 *
 * Calculate first n numbers of a Fibonacci number arrays in iterative and recursive two ways and record the running time.
 * Input: a number n, saved in varible fibnum
 * Output: the Fibonacci number arrays and the running time.
 *
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
struct timeval* gettime(void);
double timediff(struct timeval *t1, struct timeval *t2);
int recfib(int n)/* compute the n-th Fibonacci number recursively */
{
    /*if number is less than 2 we directly return them*/
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    /*or start recursing here*/
    return recfib(n-1)+recfib(n-2);
}
int iterfib(int n)/* compute the n-th Fibonacci number iteratively */
{
    /*if number is less than 2 we directly return them*/
    if (n == 1) {
        return 0;
    }
    else if (n == 2){
        return 1;
    }
    /*special process for the first two fib numbers*/
    int i,a[30];
    a[1] = 0;
    a[2] = 1;
    i=2;
    /*start iterating here*/
    while (++i<=n) {
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];
}
int main(int argc, char*argv[])
{
    struct timeval startiter,enditer,startrec,endrec;/* The structures time will be stored in*/
    
    
    int fibnum;/* The converted input*/
    
    if (!(argv[1][0]>='0' && argv[1][0]<='9'))/* Check if the input is an integer */
    {
        if(argv[1][0]=='-')
        {
            fprintf(stderr,"Argument must be a positive integer\n");
            exit(1);
        }
        
        fprintf(stderr, "%s not an integer\n", argv[1]);
        exit(1);
    }
    
    else if(argv[1][0]=='-'||argv[1][0]=='0')/* Check if the input is a positive integer*/
    {
        fprintf(stderr,"Argument must be a positive integer\n");
        exit(1);
    }
    
    if (argc>2) /*Check if there are multiple arguments*/
    {
        fprintf(stderr, "Usage: %s number\n", argv[0]);
        exit(1);
    }
    sscanf(argv[1], "%d", &fibnum); /* Read in the input*/
    
    int counter=1;/* Progress counter */
    
    printf("Iterative: ");
    
    startiter=*gettime();/* Record the time before the printing*/
    
    while(counter<=fibnum)/* compute the n-th Fibonacci number iteratively */
    {
        printf(" ");/* Print space between numbers*/
        
        printf("%d", iterfib(counter));
        
        counter++;
    }
    printf("\n");
    enditer=*gettime();/* Record the time after the printing*/
    counter=0;/* Set counter to 0 */
    printf("Recursive: ");
    startrec=*gettime(); /* Record the time before the printing*/
    while(counter<fibnum)/* compute the n-th Fibonacci number recursively */
    {
        printf(" ");
        printf("%d", recfib(counter));
        counter++;
    }
    endrec=*gettime();/* Record the time after the printing*/
    /*Print the time*/
    printf("\nIterative timing: %12.6f\n", timediff(&startiter, &enditer));
    printf("\nRecursive timing: %12.6f\n", timediff(&startrec, &endrec));
    return 0;
}