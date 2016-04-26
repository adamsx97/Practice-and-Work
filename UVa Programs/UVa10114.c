/*
//
//  main.c
//  c
//
//  Created by Chengeng Xiao on 9/26/15.
//  Copyright © 2015 Chengeng Xiao. All rights reserved.
//
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int dr,m,a;
float d,lo,b,dpr[105],car,pay;
int main() {
    int i;
    while(scanf("%d %f %f %d", &dr,&d,&lo,&m)&& dr >= 0) {
        memset(dpr, 0, sizeof(dpr));
        while (m--){
            scanf("%d %f",&a,&b);
            dpr[a]=b;
        }
        for(i=0;i<=100;i++)
            if(dpr[i]==0)
                dpr[i]=dpr[i-1];
        car=(lo+d)*(1-dpr[0]);
        if(lo <= car){
            printf("0 months\n");
            continue;
        }
        m=1;
        pay = lo / dr;
        while(lo > car){
            lo=lo-pay;
            car=car-dpr[m]*car;
            if(lo <= car) {
                if (m==1) {
                    printf("1 month\n");
                    break;
                }
                else{
                    printf("%d months\n",m);
                    break;
                }
            }
            m++;
        }
    }
    return 0;
}