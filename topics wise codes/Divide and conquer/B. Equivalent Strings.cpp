#include<bits/stdc++.h>
using namespace std;
#define d1 256
#define d2 232

bool isEqual(char pat[], char txt[])
{

    int M=strlen(pat);
    int N=strlen(txt);

    int p1=0,p2=0;
    int t1=0,t2=0;
    int h1=1,h2=0;
    int i,j,q1=7907,q2=7919;

    for(i=0; i<M-1; i++)
    {
        h1= (h1*d1)%q1;
        h2= (h2*d2)%q2;
    }

    for(i=0; i<M; i++)
    {
        p1=(d1*p1+pat[i])%q1;
        t1=(d1*t1+txt[i])%q1;

        p2=(d2*p2+pat[i])%q2;
        t2=(d2*t2+txt[i])%q2;
    }

    i=0;
    if(p1==t1 && p2==t2)
    {
        for(j=0; j<M; j++)
        {
            if(txt[i+j]!=pat[j])
                return false;
        }

        if(j==M)
           return true;
    }
    return false;

}

bool divide(char str1[], char str2[], int len)
{
    //printf("s1=%s  s2=%s l=%d\n",str1,str2,len);


    if(isEqual(str1,str2)==true)
        return true;

    if(len & 1) return false;


    int mid=len/2;
    // cout<<mid<<endl;

    char arg1[mid],arg2[mid];  /// preparing for sending as argument
    int i;
    for(i=0; i<mid; i++)
        arg1[i]=str1[i];
    arg1[i]='\0';

    for(i=0; i<mid; i++)
        arg2[i]=str2[i];
    arg2[i]='\0';


    int r1=0,r2=0;
    r1+= divide(arg1,arg2,mid);
    r1+= divide(str1+mid,str2+mid, mid);

    if(r1==2) return true;

    r2+= divide(arg1, str2+mid, mid);
    r2+=divide(str1+mid, arg2, mid);

    if(r2==2) return true;

    return false;
}

int main()
{
    char str1[200009], str2[200009];
    scanf("%s",&str1);
    scanf("%s",&str2);


//    if(strcmp(str1,str2)==0)
//        printf("YES\n");
//    else printf("NO\n");


    if(divide(str1, str2, strlen(str1))==true) printf("YES\n");
    else printf("NO\n");

}
