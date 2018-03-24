#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

//int dp1[2009], dp2[2009],dp3[2009];

map<int, int>dp1;
//map<int, int>dp2;
//map<int, int>dp3;
int fib(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;

    if(dp1[n]!=0) return dp1[n];

    return dp1[n]=fib(n-1)+fib(n-2);
    //return fib(n-1)+fib(n-2);
}

int fib1(int n, int F0, int  F1)
{
    if(n==0) return F0;
    if(n==1) return F1;

    if(dp1[n]!=0) return dp1[n];
    return dp1[n]=fib1(n-1, F0,F1)+fib1(n-2, F0,F1);
   // return fib1(n-1, F0,F1)+fib1(n-2, F0,F1);

}

int fib3(int n, int F0, int  F1)
{
   // printf("%intd %intd %intd\n",n,F0,F1);
    if(n==0) return F0;
    if(n==1) return F1;

    if(dp1[n]!=0) return dp1[n];
    return dp1[n]=fib3(n+2, F0,F1)- fib3(n+1, F0,F1);
    //return fib3(n+2, F0,F1)- fib3(n+1, F0,F1);

}


int main()
{
//    ms(dp1,-1);
//    ms(dp2,-1);
//    ms(dp3,-1);

    int i,Fi, j ,Fj;
    int n;
    scanf("%d %d %d %d %d",&i,&Fi, &j, &Fj, &n);
   // scanf("%d %d",&j,&i);

   if(i>j) {swap(i,j);  swap(Fi,Fj); }
    int t1;
    t1= fib(j-i);

    //cout<<t1<<endl;

    int t2=fib(j-i+1);

    dp1.clear();

    int total=0;
    total= Fj- t2*Fi;

    total/=t1;

    if(n<i)
    {
        printf("%d\n",fib3(n-i+1,total,Fi));
    }
    else
    printf("%d\n",fib1(n-i+1, total, Fi ));

    return 0;
}
