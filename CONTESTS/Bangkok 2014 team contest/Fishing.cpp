#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a)
#define inf 100000000
using namespace std;

int R,C;
int feed[105][105];
int dp1[105][105][105];
int dp2[105][105][105];
int f1(int r, int c,int k)
{
    //printf("r=%d c=%d k=%d\n",r,c,k);
    if(k==0) return 0;
    if(r+1>R || c+1>C) return inf;

    if(dp1[r][c][k]!=-1) return dp1[r][c][k];

    int mn=inf,t1,t2,t3,t4;
    t1=f1(r+1,c+1, k);
    t2=f1(r, c+1, k);
    mn=min(t1,t2);
    t3=f1(r+1,c,k);
    mn=min(mn,t3);

    t4=feed[r+1][c+1]+f1(r+1,c+1, k-1);
    mn=min(mn,t4);

    return dp1[r][c][k]=mn;
}

int f2(int r, int c,int k)
{
    // printf("r=%d c=%d k=%d\n",r,c);
    if(k==0) return 0;
    if(r+1>R || c+1>C) return -inf;

    if(dp2[r][c][k]!=-1) return dp2[r][c][k];

    int mx=-inf,t1,t2,t3,t4;
    t1=f2(r+1,c+1, k);
    t2=f2(r, c+1,  k);
    mx=max(t1,t2);
    t3=f2(r+1,c, k);
    mx=max(mx,t3);

    t4=feed[r+1][c+1]+f2(r+1,c+1,  k-1);
    mx=max(mx,t4);

    return dp2[r][c][k]=mx;
}


int main()
{

    int tt;
    cin>>tt;

    while(tt--)
    {

        ms(dp1,-1);
        ms(dp2,-1);

        int n,m;
        cin>>n>>m;

        R=n,C=m;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&feed[i][j]);
            }
        }




        //cout<<f2(0,0,2)<<endl;

        int mx=0;
        for(int i=0; i<=min(n,m)/2+1; i++)
        {

            int r1=f1(0,0,i*2);
            int r2=f2(0,0,i);

            //  printf("%d %d\n",r1,r2);

            mx= max(mx,r2-r1);
        }

        cout<<mx<<endl;




    }




}

