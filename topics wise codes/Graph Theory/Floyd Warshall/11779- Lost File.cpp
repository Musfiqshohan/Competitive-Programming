#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

vector<int>vec[55];
int ara[55][55];


void print(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d ",ara[i][j]);
        }
        puts("");
    }
}
int main()
{
    int t=0,test;
    scanf("%d",&test);

    while(t<test) {

    int n,k,u,v,w;
    scanf("%d %d",&n,&k);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ara[i][j]=0;


    for(int i=0; i<k; i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        ara[u][v]=w;
    }

//    for(int k=0; k<n; k++)
//        for(int i=0; i<n; i++ )
//            for(int j=0; j<n; j++)
//            {
//                ara[i][j]+=ara[i][k]* ara[k][j];
//            }
//
//
//    puts("Here");
//    print(n);


    for(int k=0; k<n; k++)
        for(int i=0; i<n; i++ )
            for(int j=0; j<n; j++)
            {
                ara[i][j]-= ara[i][k] * ara[k][j];
            }


   // print(n);


    int cnt=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ara[i][j]==1)
                {vec[i].push_back(j);
                 cnt++;
                }
        }
        sort(vec[i].begin(),vec[i].end());
    }


    printf("Case %d: %d %d\n",++t, n,cnt);

    for(int i=0;i<n;i++)
    {
        printf("%d",vec[i].size());

        for(int j=0;j<vec[i].size();j++)
            printf(" %d",vec[i][j]);

        puts("");
    }

    ms(ara,0);

    for(int i=0;i<n;i++) vec[i].clear();

    }

    return 0;
}
