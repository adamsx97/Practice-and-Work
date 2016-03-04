/*
 * vis -- translate all characters into a visable form
 *
 * Usage: translate invisable characters like a tab to "\t" and so on visble forms.
 * Inputs: User enters a string.
 * Outputs: a translated string.
 * Exit Code: return 0
 *
 * written for ECS 030 assignment1, Fall 2015
 *
 * Chengeng Xiao, Oct. 15, 2015 ID: 913186040
 *  original program written
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;/*The ch should be integer, because there might be some wide character that can not be saved in char， which means that the input may be bigger than char max.*/
    
    while((ch = getchar()) != EOF){
        if (isprint(ch))
            putchar(ch);
        else switch (ch){
            case '\t':	printf("\\t"); break;
            case '\b':	printf("\\b"); break;
            case '\f':	printf("\\f"); break;
            case '\0':	printf("\\0"); break;
            case '\\':	printf("\\\\"); break;
            case '\v':	printf("\\v"); break;
            case '\r':	printf("\\r"); break;
            case '\a':	printf("\\a"); break;/*This line has a colon missing.*/
            case '\n':	/*The out put is wrong.
                         *The original command's out put is "\n" with a new line.
                         *original line was:
                         *"printf("\\n\n");"
                         */
                printf("\\n");
                /*
                 *Also here is a "break;" command missing.
                 */
                break;
            default:	printf("\\x%02x", ch); break;/*Hex is print in this form*/
        }
    }
    
    return(0);
}
