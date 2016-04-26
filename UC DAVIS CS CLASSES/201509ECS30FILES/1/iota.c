/*
 * iota -- print number in line from a start number to an ending number with an increment.
 *
 * Usage: print a line of number in order
 * Inputs: User enters three integers for starting point, ending point and increment.
 * Outputs: numbers in a line from the start number to the ending number with an increment.
 * Exit Code: EXIT_SUCCESS (0) if valid integer entered
 *            EXIT_FAILURE (1) otherwise
 *
 * written for ECS 030 assignment1, Fall 2015
 *
 * Chengeng Xiao, Oct. 15, 2015 ID: 913186040
 *  original program written
 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int startingpoint=0;/*This is the starting point.*/
    int endingpoint=0;/*This is the ending point.*/
    int increment=0;/*This is the increment.*/
    int now=0;/*This is the value of the output in each turn of the loop.*/
    /*Input the numbers for the corresponding variables.*/
    printf ("Starting point: ");
    scanf ("%d",&startingpoint); /*input starting point*/
    printf ("Ending point: ");
    scanf ("%d",&endingpoint); /*input ending point*/
    printf ("Increment: ");
    scanf ("%d",&increment); /*input increment*/
    now = startingpoint;
    /*When starting point is smaller than the ending point and the increment is positive the output goes like this.*/
    if (startingpoint < endingpoint && increment > 0) {
        while (now <= endingpoint){
            if ((now + increment) <= endingpoint)
                printf("%d ", now);
            else
                printf("%d", now);
            now += increment;
        }
    }
    /*When starting point is smaller than the ending point but the increment is negative the counting can not happen, so output error information.*/
    else if (startingpoint < endingpoint && increment <= 0){
        fprintf(stderr, "Increment must be > 0 if begin < end\n");
        exit(EXIT_FAILURE);
    }
    /*When starting point is bigger than the ending point and the increment is negative the output goes like this.*/
    else if (startingpoint > endingpoint && increment < 0){
        while (now >= endingpoint){
            if ((now + increment) >= endingpoint)
                printf("%d ", now);
            else
                printf("%d", now);
            now += increment;
        }
    }
    /*When starting point is bigger than the ending point but the increment is positive the counting can not happen, so output error information.*/
    else if (startingpoint > endingpoint && increment >= 0){
        fprintf(stderr, "Increment must be < 0 if begin > end\n");
        exit(EXIT_FAILURE);
    }
    /*When starting point is equal to the ending point, there is only one number in output, no matter what the increment is.*/
    else
        printf("%d", now);
    printf("\n");
    exit(EXIT_SUCCESS);
    return 0;
}