/*
 * FIBDRIVER -- program to call a Fibonacci printing function
 *
 * Compiling: put the Fibonacci function in fib.c, then say:
 * 	gcc -ansi -pedantic -Wall -o fib fibdriver.c fib.c
 *
 * Usage: fib`
 *
 * Inputs (from standard input)
 *      -- a non-negative integer
 * Outputs (to standard output)
 * 	-- a single line of the first n Fibonacci numbers, separated by
 * 	   blanks
 * Errors (to standard error)
 * 	-- "Need an integer\n" -- input isn't an EOF or integer
 * 	-- "Cannot print a negative number of Fibonacci numbers\n" --
 * 		input is a negative integer
 *
 * Exit Code: 0 if all is well, 1 on error
 *
 * written for ECS 030, Fall 2015
 * 
 * Matt Bishop, Oct. 11, 2015
 *      original program written
 */

#include <stdio.h>
#include <stdlib.h>

/*
 *  prototypes
 */

int fib(int n){         /* function to print Fibonacci numbers */
    if (n < 0)         /* Check wheather it is a valid integer to print, if n is invalid return 0*/
        return 0;
    int i = 1,a[3];
    a[0] = 1;
    a[1] = 0;         /* generate first two number into the fibonacci array */
    while (i <= n) {         /* print and updating fibonacci array*/
        printf("%d ",a[i%2]);
        a[(i+1)%2]+=a[i%2];
        i++;
    }
    printf("\n");         /* get a new line after the array printed*/
    return 1;         /* since the number to print is valid, return 1*/
}

/*
 * the main routine -- start here
 */
int main(void)
{
    int count;	/* number of Fibonacci numbers to print */
    int nread;	/* return value of reading */
    
    /*
     * read the number -- we hope! Handle errors or EOF
     */
    if ((nread = scanf("%d", &count)) == EOF)
        return(EXIT_SUCCESS);
    else if (nread != 1){
        /* oops ... not an integer */
        fprintf(stderr, "Need an integer\n");
        return(EXIT_FAILURE);
    }
    
    /*
     * got a number -- fib checks its validity
     * if we skip the if body, all went well
     * otherwise, not
     */
    if (!fib(count)){
        fprintf(stderr,"Cannot print a negative number of Fibonacci numbers\n");
        return(EXIT_FAILURE);
    }
    
    /*
     * say goodnight, Dick!
     */
    return(EXIT_SUCCESS);
}
