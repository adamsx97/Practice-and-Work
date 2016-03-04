#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int n,b,h,w,pr,av,i,j,min;
    while (scanf("%d %d %d %d",&n,&b,&h,&w) != EOF) {
        min = 0xfffffff;
        for (i = 1; i <= h; i++) {
            scanf("%d",&pr);
            for (j = 1; j <= w; j++) {
                scanf("%d",&av);
                if (av >= n && pr * n <= b) {
                    min = min < pr * n ? min : pr * n;
                }
            }
        }
        if (min != 0xfffffff) {
            printf("%d\n",min);
        }
        else
            printf("stay home\n");
    }
    return 0;
}