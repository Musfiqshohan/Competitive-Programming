#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,ara[1009][1009],vis[1009][1009][6], dp[1009][1009][6];




int prepare(int num,int i)
{

    int cnt=0;
    while(num%i==0)
    {
        num/=i;
        cnt++;
    }

    return cnt;
}

int f(int r, int c, int turn)
{

    if(r==n-1 && c==n-1)
    {
        int temp= prepare(ara[r][c],turn);
        return temp;
    }

    if(r>=n || c>=n) return {10000000};



    if(vis[r][c][turn]==1) return dp[r][c][turn];
    vis[r][c][turn]=1;

    int t1,t2;

    t1= f(r+1,c,turn);
    t2= f(r,c+1,turn);

    int ret= min(t1,t2);

    int tt= prepare(ara[r][c],turn);

    return dp[r][c][turn]=ret+tt;


}



void print_path(int r, int c, int turn)
{

    if(r==n-1 && c==n-1) return;

    int t1= f(r+1,c,turn);
    int t2= f(r,c+1,turn);

    if(t1<t2)
    {
        printf("D");
        print_path(r+1,c,turn);
    }

    else
    {
        printf("R");
        print_path(r,c+1,turn);

    }
}


int main()
{

    scanf("%d",&n);
    int flag=0;

    int x,y;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d",&ara[i][j]);
            if(ara[i][j]==0)
            {
                flag=1;
                ara[i][j]=10;
                x=i,y=j;
            }
        }
    }


    int res1=f(0,0,2);
    int res2=f(0,0,5);

    int res= min(res1,res2);
    // puts("");
    // cout<<res1<<" "<<res2<<endl;

    if(flag==1 && flag<=res)
    {
        printf("%d\n",flag);

        for(int i=1; i<=x; i++)
            printf("D");

        for(int i=1; i<=y; i++)
            printf("R");
        for(int i=x+1; i<n;i++)
            printf("D");
        for(int i=y+1; i<n; i++)
            printf("R");

    }
    else
    {
        printf("%d\n",res);

        if(res1<res2)
            print_path(0,0,2);
        else print_path(0,0,5);

    }

    puts("");


    return 0;
}
