#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int idx;
int n,m,C;
int ara[55*55],mat[55][55];

void update(int row)
{

    if(row%2==1)
    {
        for(int i=1; i<=m; i++)
        {
            mat[row][i]=idx;
            ara[idx]--;

            if(ara[idx]==0 && idx<=C)
                idx++;
        }
    }
    else
    {
        for(int i=m; i>=1; i--)
        {
            mat[row][i]=idx;
            ara[idx]--;

            if(ara[idx]==0 && idx<=C)
                idx++;
        }

    }



}

int main()
{

    int tt;
    cin>>tt;

    while(tt--)
    {
        cin>>n>>m>>C;

        for(int i=1; i<=C; i++)
        {
            scanf("%d",&ara[i]);
        }


        idx=1;
        for(int i=1; i<=n; i++)
        {
            update(i);
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(j>1) printf(" ");
                printf("%d",mat[i][j]);
            }
            puts("");
        }
        ms(mat,0);
        ms(ara,0);

    }


    return 0;
}

