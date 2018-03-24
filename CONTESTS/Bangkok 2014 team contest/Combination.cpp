#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a)
#define inf 100000000
using namespace std;

int idx[100]={0,4,8,12,16,20,24,28,32};
 int f(int st, int en)
 {
     printf("%d %d\n",st,en);
     if(st==en)
        return 9;

     int t=0;

     int inc=(en-st)/4;
     t=f(st,st+inc)  +2*f(st+inc, st=2*inc) +2*f(st+2*inc, st+3*inc) + 4*f(st+3*inc, 4*inc);
     return t;
 }


  int f2(int st, int en)
 {
     printf("%d %d\n",st,en);
     if(st==en)
        return 9;

     int t=0;

     int inc=(en-st)/4;
     t=f(st,st+inc)  +2*f(st+inc, st=2*inc) +2*f(st+2*inc, st+3*inc) + 4*f(st+3*inc, 4*inc);
     return t;
 }


int main()
{
    int n;
   // cin>>n;
   // cout<<f(0,4)<<endl;
    cout<<f2(0,4)<<endl;

}
