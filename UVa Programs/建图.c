#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int h,w,map[55][55],sx,sy,path,tr;/* h是高，w是宽，map是图，sx和sy是起点坐标，path是floyd路径，tr是宝藏个数*/
char p;
int main()
{
    int i,j;
    while (scanf("%d %d",&h,&w) && h != 0 && w != 0) {
        memset(map, -2, sizeof(map));
        for (i = 0; i < h; i++){
            for (j = 0; j < w; j++) {
                scanf("%c",&p);
                /*map中 -2是边界之外，-1是原住民，0是不能走的地方，1是沙地，2是宝藏，3是起点，map[][]>0就可以走*/
                if (p == '@') {
                    map[i][j] = 3;
                    sx = i;
                    sy = j;
                }
                else if (p == '~' || p == '#')
                    map[i][j] = 0;
                else if (p == '*'){
                    map[i][j] = -1;
                    map[i-1][j] = -1;
                    map[i+1][j] = -1;
                    map[i][j-1] = -1;
                    map[i][j+1] = -1;
                    map[i-1][j-1] = -1;
                    map[i-1][j+1] = -1;
                    map[i+1][j-1] = -1;
                    map[i+1][j+1] = -1;
                }
                else if (p == '.' && map[i][j] != -1)
                    map[i][j] = 1;
                else if (p == '!')
                    map[i][j] = 2;
            }
            getchar();
        }
    
    }
    return 0;
}