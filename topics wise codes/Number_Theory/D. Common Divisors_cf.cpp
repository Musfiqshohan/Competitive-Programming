#include<bits/stdc++.h>
using namespace std;
char s3[10000];
void remainder( char s1[], char s2[])
{

    int start,i,j;
    memset(s3,0,sizeof(s3));
    start=strlen(s1);
    for(i=0,j=0; s1[i] ; i++,j++)
    {


        if(j== strlen(s2))
        {
            start=i;
            j=0;
        }

    }

    printf("j1= %d  ",j);
    if(j== strlen(s2) && (i)%(j)==0)
    {
        start=i;
        j=0;
    }


    printf("j2=%d  ",j);
    j=0;
    for(i=start; s1[i]; i++)
    {
        s3[j]=s1[i];
        j++;
    }
    printf("%s %s %s\n",s1,s2,s3);

}

void f(char s1[], char s2[], int i)
{
    int j;
    for(j=0; j<i; j++) s2[j]=s1[j];
    remainder(s1,s2);


}
int main()
{
    char s1[1000],s2[1000];
    int i,j,start;
    scanf("%s",&s1);
    scanf("%s",&s2);

    if(strlen(s2)>strlen(s1))
    {
        char temp[100];
        strcpy(temp,s1);
        strcpy(s1,s2);
        strcpy(s2,temp);
    }

    while(strlen(s2)!=0)
    {
        remainder(s1,s2);
        strcpy(s1,s2);
        strcpy(s2,s3);
    }



    int l=strlen(s1);
    int root= sqrt(l);
    int cnt=0;
   // printf("%s %d\n",s1,l);
    for(i=1; i<=root; i++)
    {
        if(l%i==0)
        {
            memset(s2,0,sizeof(s2));

            memset(s3,0,sizeof(s3));
            printf("Fuck1 ");
            f(s1,s2,i);
            if(strlen(s3)==0)  cnt++;


            if(i!=l/i){
            memset(s3,0,sizeof(s3));
            printf("Fuck2 ");
            f(s1,s2,l/i);
            if(strlen(s3)==0)  cnt++;

            }

        }

    }

    printf("%d\n",cnt);

    return 0;

}

