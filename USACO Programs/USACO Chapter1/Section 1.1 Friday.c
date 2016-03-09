/*
 ID: nyyl1303
 LANG: C
 TASK: friday
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define isleap(a) (a%4 == 0 && (a%100 != 0 || a%400 == 0))?1:0
#define returnmonth(a) a==1?12:a-1

int main(void)
{
    int monthindex[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    FILE *fin = fopen("friday.in","r");
    FILE *fout = fopen("friday.out","w");
    int n,year,month,ans[7],LastWeek;
    memset(ans, 0, sizeof(ans));
    fscanf(fin, "%d",&n);
    LastWeek = 6;
    ans[LastWeek]++;
    for (year = 1900; year < 1900+n; year++) {
        if (isleap(year))
            monthindex[2] = 29;
        for (month = 1; month <= 12; month++) {
            if (year == 1900 && month == 1) {
                continue;
            }
            LastWeek=(LastWeek+monthindex[returnmonth(month)]%7)%7;
            ans[LastWeek]++;
        }
        monthindex[2] = 28;
    }
    fprintf(fout, "%d ", ans[6]);
    int i;
    for (i = 0; i < 5; i++)
        fprintf(fout, "%d ", ans[i]);
    fprintf(fout, "%d\n", ans[5]);
    fclose(fout);
    fclose(fin);
    exit (0);
}
