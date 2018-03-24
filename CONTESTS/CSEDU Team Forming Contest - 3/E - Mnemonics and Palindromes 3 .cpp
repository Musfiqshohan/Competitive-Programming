#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

char str[5];
int n;

int f(char c1, char c2,char c3)
{
    str[0]=c1;
    str[1]=c2;
    str[2]=c3;

    int cnt=0;
    while(cnt<n)
    {
        printf("%c",str[cnt%3]);
        cnt++;
      //  total++;

//        if(total>=100000)
//        {
//            printf("TOO LONG\n");
//            return 0;
//        }
//        //printf("%d %d %d\n",cnt,n, cnt%3);

    }

    puts("");
    return 1;

}

int main()
{

    scanf("%d",&n);

    if(n*6>=100000) printf("TOO LONG\n");
    else {

    if(f('a', 'b', 'c')==0)  return 0;
    if(n>1)
        if(f('a', 'c', 'b')==0)return 0;

    if(f('b', 'a', 'c')==0)return 0;
    if(n>1)
        if(f('b', 'c', 'a')==0)return 0;

    if(f('c', 'a', 'b')==0)return 0;
    if(n>1)
        if(f('c', 'b', 'a')==0)return 0;

    }


    return 0;

}
