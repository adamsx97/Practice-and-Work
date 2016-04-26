/*
//
//  main.c
//  c
//
//  Created by Chengeng Xiao on 11/17/15.
//  Copyright © 2015 Chengeng Xiao. All rights reserved.
//
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int t,la,queue[10005],stack[10005],head,tail,i;
char a[10005];
struct {
    int parent;
    int leftson;
    int rightson;
}tree[10005];

int main(void)
{
    int st,n;
    scanf("%d",&t);
    getchar();
    while (t--) {
        st = 0;
        n = 0;
        scanf("%s",a);
        la = (int) strlen(a);
        for ( i = 0; i < la; i++) {
            if (a[i] >= 'a' && a[i] <= 'z') {
                stack[st++] = n;
                tree[n].parent = a[i];
                tree[n].leftson = -1;
                tree[n].rightson = -1;
                n++;
            }
            else {
                tree[n].parent = a[i];
                tree[n].leftson = stack[st-2];
                tree[n].rightson = stack[st-1];
                st -= 2;
                stack[st++] = n;
                n++;
            }
        }
        head = 0;
        tail = 0;
        queue[tail++] = n-1;
        int x = 0;
        while (head != tail) {
            st = queue[head++];
            a[x++] = tree[st].parent;
            if (tree[st].leftson != -1) {
                queue[tail++] = tree[st].leftson;
            }
            if (tree[st].rightson != -1) {
                queue[tail++] = tree[st].rightson;
            }
        }
        for ( i = la-1; i >= 0; i--) {
            printf("%c",a[i]);
        }
        printf("\n");
    }
    return 0;
}