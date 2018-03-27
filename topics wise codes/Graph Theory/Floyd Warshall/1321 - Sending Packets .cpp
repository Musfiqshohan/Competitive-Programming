#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

double ara[101][101];

int main()
{

    int tt=0,test;
    cin>>test;

    while(tt<test) {
    ll n,m,s,k,u,v,w;
    scanf("%lld %lld %lld %lld",&n,&m,&s,&k);


    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ara[i][j]= 0; //(i==j)?  0:inf;


    for(int i=0; i<m; i++)
    {
        scanf("%lld %lld %lld",&u,&v,&w);

        ara[u][v]=w/100.0;
        ara[v][u]=w/100.0;
    }

    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(ara[i][k] * ara[k][j] > ara[i][j])
                {
                    //printf("%f *%f = %f  > %f\n",ara[i][k], ara[k][j], ara[i][k]*ara[k][j] , ara[i][j] );
                    ara[i][j]=ara[i][k]* ara[k][j];
                }

            }


       double res= ara[0][n-1];
       // cout<<res<<endl;

       res= 2*k*s/res;


       printf("Case %d: %.4f\n",++tt,res);
       // ms(ara,0);

    }

    return 0;
}
