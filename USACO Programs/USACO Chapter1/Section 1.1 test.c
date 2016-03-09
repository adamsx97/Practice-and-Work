/*
 ID: nyyl1303
 LANG: C
 TASK: test
 */
#include <stdio.h>

int a,b,c;

int main(void)
{
    FILE *fin = fopen("test.in","r");
    FILE *fout = fopen("test.out","w");
    fscanf(fin, "%d %d",&a,&b);
    c = a+b;
    fprintf(fout, "%d\n",c);
    fclose(fin);
    fclose(fout);
    return 0;
}