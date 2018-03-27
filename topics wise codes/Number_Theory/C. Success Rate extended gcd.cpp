#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000;
using namespace std;
 int x,y,p,q;
int f(int n)
{
    printf("%d\n",n);

    int rhs,lhs;
    rhs= p*y- x*q + n*p;
    lhs= rhs/q;

    printf("%d %d\n",lhs, rhs);

    if(lhs*q<rhs) return -1;
    if(lhs*q>rhs) return 1;
    else return 0;
}

int main()
{


    scanf("%d %d %d %d",&x,&y,&p,&q);


    int low=0,high=100,cnt=0,mid;

    while(cnt++<100)
    {
        mid= low+ (high-low)/2;

        if(f(mid)>0)
        {
            high= mid-1;
        }
        else if(f(mid)<0)
        {
            low=mid+1;
        }
        else
            high=mid;

    }

    printf("%d\n",mid);


    return 0;
}
