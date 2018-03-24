#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

int ara[32], C[32][22][3], dp[32][303][303];
int n;
int f(int pos, int T1, int T2)
{
    if(pos==n+1 && T1==0 && T2==0) return 0;
    if(T1<0 || T2<0) return 1000000;


    if(dp[pos][T1][T2]!=-1) return dp[pos][T1][T2];

    int total=100000,t;
    for(int i=0; i<=ara[pos]; i++)
    {
        t= C[pos][i][1] + C[pos][ara[pos]-i][2] +  f(pos+1, T1-i, T2- ara[pos]+i );

        total= min(total,t);
    }

    return dp[pos][T1][T2]=total;

}


void print(int pos, int T1, int T2)
{
    //printf("->%d %d %d\n",pos,T1,T2);

    if(pos==n+1 && T1==0 && T2==0)
    {
        return ;
    }


    int mn=100000,mni=0,t;
    for(int i=0; i<=ara[pos]; i++)
    {
        t= C[pos][i][1] + C[pos][ara[pos]-i][2] +   f(pos+1, T1-i, T2- ara[pos]+i );

        if(t<mn)
        {
            mn=t;
            mni=i;
        }
    }

    printf("%d",mni);
    if(pos<n) printf(" ");

    print(pos+1,T1-mni, T2- ara[pos]+mni);

}
int main()
{


    while(1)
    {
        ms(dp,-1);
        int T1,T2;

        scanf("%d %d",&T1,&T2);
        if(T1==0 && T2==0) break;
        scanf("%d",&n);

        for(int k=1; k<=n; k++)
        {

            scanf("%d",&ara[k]);

            for(int j=1; j<=2; j++)
            {
                for(int i=1; i<=ara[k]; i++)
                    scanf("%d",&C[k][i][j]);
            }

        }


        cout<<f(1,T1,T2)<<endl;
        print(1,T1,T2);
        puts("");

    }
    return 0;
}
