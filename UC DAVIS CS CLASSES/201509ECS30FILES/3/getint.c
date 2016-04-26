//
//  main.c
//  getint
//
//  Created by Chengeng Xiao on 11/9/15.
//  Copyright © 2015 Chengeng Xiao. All rights reserved.
//

/*
 * GETINTDRIVER -- program to call an integer reading function
 *
 * Compiling: put the getint function in getint.c, then say:
 *  gcc -ansi -pedantic -Wall -o getint getintdriver.c getint.c
 *
 * Usage: getint
 *
 * Inputs (from standard input)
 *      -- a line of text
 *      -- EOF to exit
 *      -- special handling of 2246, 2247, 2248, 2249
 * Outputs (to standard output)
 *  -- a prompt when it expects input
 *  -- outputs indicating the success or failure of the getint call
 *  -- if input is integer 2246, also indicate whether getint() handles
 *      a NULL first argument correctly
 *  -- if input is integer 2247, also indicate whether getint() handles
 *      a NULL second argument correctly
 *  -- if input is integer 2248, also indicate whether getint() handles
 *      a NULL third argument correctly
 *  -- if input is integer 2249, also indicate whether getint() handles
 *      a NULL dereferencing of the third argument correctly
 * Errors (to standard error)
 *  -- nothing printed
 *
 * Exit Code: 0
 *
 * written for ECS 030, Fall 2015
 *
 * Matt Bishop, Oct. 28, 2015
 *      original program written
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * macros
 *
 * how to test for bogus arguments
 */
#define BADARG1 2246        /* if read, test handling of NULL first arg */
#define BADARG2 2247        /* if read, test handling of NULL second arg */
#define BADARG3 2248        /* if read, test handling of NULL third arg */
#define BADARG4 2249        /* if read, test handling of NULL dereference for third arg */

/*
 *  prototypes
 */
int getint(char *buf, int *numread, char **nextch)  /* function to read an integer */
{
    if(buf == NULL || numread == NULL || nextch == NULL )
        return -1;
    int flag = 0,lnum = 0,flow = 0;
    char *row = buf;
    *numread = 0;
    /*flag value
     *1:positive number
     *2:negative number
     *3:with heading '+'
     *4:with heading '-'
     *-1: no number just strings
     *lnum: length of number read
     *flow value:
     *-1: underflow
     *0: in flow
     *1: overflow
     */
    while(*buf == ' ')
        buf++;
    if (*buf == '+'){
        flag = 3;
        buf++;
    }
    else if (*buf == '-'){
        flag = 4;
        buf++;
    }
    else if (((*buf >= 'a' && *buf <= 'z') || (*buf >= 'A' && *buf <= 'Z') || (*buf >= '0' && *buf <= '9')) == 0){
        *buf = row;
        return 0;
    }
    while (*buf != ' ' && *buf != '\0'){
        if (*buf != ' ' && *buf <= '9'){
            if (flag == 3 && lnum ==9)
                if (*numread > 214748364 || (*numread == 214748364 && *buf - '0' > 7))
                    flow =1;
            if (flag == 4 && lnum == 9)
                if (*numread > 214748364 || (*numread == 214748364 && *buf - '0' > 8))
                    flow = -1;
            if(*buf == '0' && *numread == 0 && lnum == 1)
                lnum--;
            *numread = *numread * 10 + *buf -'0';
            buf++;
            lnum++;
        }
        else if((*buf >= 'a' && *buf <='z') || (*buf >= 'A' && *buf <= 'Z')) {
            *nextch = row;
            return 0;
        }
        else if(!((*buf >= 'a' && *buf <='z') || (*buf >= 'A' && *buf <= 'Z') || (*buf >= '0' && *buf <= '9'))) {
            if(*buf == '.' && *(buf+1) != ' ' && *(buf+1) != '\0') {
                *nextch = row;
                return 0;
            }
            break;
        }
    }
    if(flag == 4) *numread *= -1;
    *nextch = buf;
    /* if no leading integer */
    *nextch = buf;
    if(lnum == 0) {
        *nextch = row;
        return 0;
    }
    /* if overflow return 2 */
    if (flow == 1)
        return 2;
    /* if underflow return 3 */
    if (flow == -1)
        return 3;
    /* if all's well return 1 */
    return 1;
}
/*
 * this function calls getint with various illegal parameters
 *
 * Parameter:   int number to trigger test (or not)
 *          numbers that do not trigger tests are ignored
 *          BADARG1     test NULL argument 1
 *          BADARG2     test NULL argument 2
 *          BADARG3     test NULL argument 3
 *          BADARG4     test argument 3 pointing to NULL
 * Returns: nothing
 * Exceptions:  none
 * Side Effects:    prints a 1-line message identifying the test run and
 *          giving the success or failure of the test
 */
void checkargs(int testno)
{
    char line[10];      /* array used for input line */
    int inpnum = 0;     /* space for the read number */
    char *nextch = line;    /* where the getint function leaves off */
    int rv;         /* return value from getint() */
    
    /*
     * just copy some characters into line
     */
    (void) strcpy(line, "987654321");
    
    /*
     * process any magic numbers (see above)
     */
    switch(testno){
        case BADARG1:       /* NULL first argument */
            if ((rv = getint(NULL, &inpnum, &nextch)) == -1)
                printf("Passed NULL first argument test\n");
            else
                printf("Failed NULL first argument test; returned %d\n", rv);
            break;
        case BADARG2:       /* NULL second argument */
            if ((rv = getint(line, NULL, &nextch)) == -1)
                printf("Passed NULL second argument test\n");
            else
                printf("Failed NULL second argument test; returned %d\n", rv);
            break;
        case BADARG3:       /* NULL third argument */
            if ((rv = getint(line, &inpnum, NULL)) == -1)
                printf("Passed NULL third argument test\n");
            else
                printf("Failed NULL third argument test; returned %d\n", rv);
            break;
        case BADARG4:       /* NULL dereference of third  argument */
            nextch = NULL;
            if ((rv = getint(line, &inpnum, &nextch)) == -1)
                printf("Passed NULL third argument dereference test\n");
            else
                printf("Failed NULL third argument dereference test; returned %d\n", rv);
            break;
        default:        /* ignore any other number */
            break;
    }
}

/*
 * it all starts at the main routine
 */
int main(void)
{
    char buf[1024];         /* input buffer */
    int numread;            /* number read from input */
    char *nextch;           /* where we left off */
    int rv;             /* return value of getint() */
    
    /*
     * loop until end of file
     * prompting the user for an input line
     */
    while(printf("> "), fgets(buf, 1024, stdin) != NULL){
        /* clobber any trailing newline */
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = '\0';
        /*
         * now process the line -- read the leading integer
         * and report if it is not an integer or if
         * it is too big or too small to represent
         */
        switch(rv = getint(buf, &numread, &nextch)){
            case -1:        /* illegal parameter */
                printf("Illegal call -- internal inconsistency\n");
                break;
            case 0:         /* no leading integer */
                printf("No number -- string is \"%s\"\n", nextch);
                if (buf != nextch)
                    printf("Note -- third arguent should point to first, but it doesn't\n");
                break;
            case 1:         /* read number, all's well */
                printf("Read integer %d; rest of string is \"%s\"\n", numread, nextch);
                break;
            case 2:         /* read number but it's too big */
                printf("Integer overflow (+ve) -- string is \"%s\"\n", nextch);
                break;
            case 3:         /* read number but it's too negative */
                printf("Integer underflow (-ve) -- string is \"%s\"\n", nextch);
                break;
            default:        /* huh? should never happen */
                printf("Unknown return value %d\n", rv);
                break;
        }
        /*
         * now check for illegal arguments
         */
        if (rv == 1)
            checkargs(numread);
    }
    
    /*
     * sweet dreams ...
     */
    return(0);
}
