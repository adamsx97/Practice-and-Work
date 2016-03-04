#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int t,n,a,i,max;
    scanf("%d",&t);
    for (i = 1; i <= t; i++) {
        max=-1;
        scanf("%d",&n);
        while (n-->0) {
            scanf("%d",&a);
            if (a > max) {
                max = a;
            }
        }
        printf("Case %d: %d\n",i,max);
    }
    return 0;
}