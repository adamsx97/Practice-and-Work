#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * the main routine -- start here
 */
#define MAXLENGTH 105 /*define a max length of the words string*/
int main(void)
{
    char words[MAXLENGTH];	/* string of words to print */
    int lwords;	/* length of words */
    int i,t; /* i is a varible used for loops, t is a varible recording the rounds*/
    t = 0;
    while (fgets(words, MAXLENGTH, stdin) && words != EOF) {/* read the words -- read until EOF occurs */
        t++;    /*adding a round to t*/
        lwords = (int)strlen(words);    /* get the length of words and put it into lwords*/
        i = 0;
        while (i < lwords) {    /* go though all of the string and check the type of of each character*/
            if((words[i]>='0' && words[i] <= '9') || (words[i] >= 'a' && words[i] <= 'z') || (words[i] >= 'A' && words[i] <= 'Z')){
                printf("%d ",t); /* print the string number*/
                while(((words[i]>='0' && words[i] <= '9') || (words[i] >= 'a' && words[i] <= 'z') || (words[i] >= 'A' && words[i] <= 'Z')) && i < lwords){
                    printf("%c",words[i]);
                    i++;
                }
                printf("\n");
            }
            i++;
        }
        memset(words, 0, sizeof(words));    /*reset the string.*/
    }
    /*
     * say goodnight, Dick!地方
     */
    return(EXIT_SUCCESS);
}