#include <stdio.h>
#include <string.h>
int map[160][160],vis[160][160];
int n,m;  //原始长宽
int dd[9][2]={{0,0},{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
int max,flag,c,find;
void dfs(int x ,int y)
{
    int i;
    vis[x][y]=1;
    c++;//格子数计数
    if(x==1 || x==2*n || y==1 || y==2*m) find=0;
    //如果成环的话，一定不会到达矩阵的边界，因为一定有斜杆包围起来的，到了边界不可能有斜杆包围
    //虽然不是环但是不能就此返回，一定要把这个连通分量全部搜索完，仅仅是改变find表示这个连通分量不是一个环
    
    for(i=1; i<=8; i++)  //枚举8个可能的方向
    {
        int xx,yy;  //将要移向的格子的坐标
        xx=x+dd[i][0];
        yy=y+dd[i][1];
        if(!map[xx][yy] && !vis[xx][yy])  //新格子是可以到达的，而且没有被访问过的
        {
            if(i<=4)  //前四个方向是上下左右，不需要做什么特殊判断，直接递归
                dfs(xx,yy);
            else    //斜方向
            {
                if(i==5) //左上
                {
                    if( (map[x][y-1]&&map[x-1][y-2])&& (map[x][y+1]&&map[x-1][y])&& !(x&1)&&(y&1) ||
                       (map[x-1][y]&&map[x-2][y-1])&& (map[x+1][y]&&map[x][y-1])&& (x&1)&&!(y&1) )
                        dfs(xx,yy);
                }
                else if(i==6)  //右上
                {
                    if((map[x][y-1]&&map[x-1][y])&& (map[x][y+1]&&map[x-1][y+2])&& !(x&1)&&!(y&1) ||
                       (map[x-1][y]&&map[x-2][y+1])&& (map[x+1][y]&&map[x][y+1])&& (x&1)&&(y&1) )
                        dfs(xx,yy);
                }
                else if(i==7) //左下
                {
                    if( (map[x][y-1]&&map[x+1][y-2])&& (map[x][y+1]&&map[x+1][y])&& (x&1)&&(y&1)||
                       (map[x][y-1]&&map[x-1][y])&& (map[x+1][y]&&map[x+2][y-1])&& !(x&1)&&!(y&1))
                        dfs(xx,yy);
                }
                else   //右下
                {
                    if( (map[x][y-1]&&map[x+1][y])&& (map[x][y+1]&&map[x+1][y+2])&& (x&1)&& !(y&1) ||
                       (map[x-1][y]&&map[x][y+1])&& (map[x+1][y]&&map[x+2][y+1])&& !(x&1)&& (y&1) )
                        dfs(xx,yy);
                }
            }
        }
    }
    
    return ;
}
int main()
{
    int num=0,i,j;
    char s[160];
    while(scanf("%d %d",&m,&n) && n && m)  //先宽再长
    {
        memset(map,0,sizeof(map));
        memset(vis,0,sizeof(vis));
        for(i=0; i<=2*m+1; i++)  //翻倍后的迷宫的上下外围不能访问
            map[0][i]=map[2*n+1][i]=1;
        for(i=0; i<=2*n+1; i++)  //翻倍后的迷宫的左右外围不能访问
            map[i][0]=map[i][2*m+1]=1;
        for(i=1; i<=n; i++)  //原始迷宫的i行
        {
            scanf("%s",s+1);
            for(j=1; j<=m; j++)
                if(s[j]=='/')
                {
                    map[2*i][(2*j)-1]=1;
                    map[(2*i)-1][2*j]=1;
                }
                else
                {
                    map[2*i][2*j]=1;
                    map[(2*i)-1][(2*j)-1]=1;
                }
        }
        max=0;flag=0;
        for(i=1; i<=2*n; i++)
            for(j=1; j<2*m; j++)
                if(!map[i][j])
                    if(!vis[i][j])
                    {
                        c=0;
                        find=1;
                        dfs(i,j);
                        if(find)
                        {
                            flag++;
                            if(c>max) max=c;
                        }
                    }
        num++;
        printf("Maze #%d:\n",num);
        if(!flag)
            printf("There are no cycles.\n");
        else
            printf("%d Cycles; the longest has length %d.\n",flag,max);
        printf("\n");
    }
    return 0;
}