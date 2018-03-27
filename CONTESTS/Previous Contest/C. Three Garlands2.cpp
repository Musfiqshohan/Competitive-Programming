#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define INF 1000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

int isprime[20000], indc[20000];

void f(int k)
{
    for(int i=1;i<=100;i++)
    {
        isprime[i*k]=1;

       // printf("k->%d %d\n",k,i*k);

        indc[i*k]=k;
    }

}

int main()
{
    int k1,k2,k3;
    scanf("%d %d %d",&k1,&k2,&k3);
    f(k1);
    f(k2);
    f(k3);

    int res=max(k1,max(k2,k3))*100;
    for(int i=1;i<=res;i++)
    {
        if(isprime[i]==0)
            printf("found -> %d\n",i);

        printf("%d -> %d\n",i,indc[i]);
    }


}

