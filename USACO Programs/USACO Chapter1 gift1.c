/*
 ID: nyyl1303
 LANG: C
 TASK: gift1
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
    char name[20];
    int money;
};

struct person persons[15];
struct person *giver;
struct person *receiver;

FILE *fin,*fout;

void getName(int nperson)
{
    int i;
    for (i = 1; i <=nperson; i++) {
        fscanf(fin, "%s",persons[i].name);
    }
    return ;
}
int locateName(char *nname,int nperson)
{
    int i;
    for (i = 1; i <=nperson; i++) {
        if (strcmp(persons[i].name,nname) == 0) {
            return i;
        }
    }
    return 0;
}
void calc(int nperson)
{
    int i,money,numreceiver,moneygive,moneyleft;
    char nname[15];
    fscanf(fin, "%s",nname);
    giver = &persons[locateName(nname,nperson)];
    fscanf(fin, "%d %d",&money,&numreceiver);
    if (numreceiver == 0)
        return ;
    giver->money -= money;
    moneyleft = money%numreceiver;
    money -= moneyleft;
    moneygive = money/numreceiver;
    giver->money += moneyleft;
    for (i = 1; i <= numreceiver; i++) {
        fscanf(fin, "%s",nname);
        receiver = &persons[locateName(nname,nperson)];
        receiver->money += moneygive;
    }
    return ;
}
void putAns(int nperson)
{
    int i;
    for (i = 1; i <= nperson; i++) {
        fprintf(fout, "%s %d\n",persons[i].name,persons[i].money);
    }
    return ;
}
int main(void)
{
    giver = (struct person*)malloc(sizeof(struct person));
    if (giver == NULL)
        fprintf(fout, "Fail to allocate.\n");
    receiver = (struct person*)malloc(sizeof(struct person));
    int i,nperson;
    fin = fopen("gift1.in","r");
    fout = fopen("gift1.out","w");
    fscanf(fin, "%d",&nperson);
    fprintf(fout, "n is %d\n",nperson);
    getName(nperson);
    for (i = 1; i <= nperson; i++)
        calc(nperson);
    putAns(nperson);
    fclose(fout);
    fclose(fin);
    exit (0);
}