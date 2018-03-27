#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
using namespace std;

vector<int>digs;
int ara[100];
int lim;

int dp[15][15][15][3][3];

int DP(int x, int y, int pos, int isSmaller, int isStart,int num)
{
    if(pos==digs.size() && isStart==1) return 0;
    if(pos==digs.size() )
    {
        // printf("num=%d\n",num);
        return 1;
    }

    ara[0]=x;
    ara[1]=y;

    //if(dp[x][y][pos][isSmaller][isStart]!=-1) return dp[x][y][pos][isSmaller][isStart];

    int ret=0;

    int ses= isSmaller? y:digs[pos];

    if(!isStart)
    {

        for(int i=0; ara[i]<=ses && i<=1; i++)
        {
            if(ara[1]==ara[0]) continue;
            if(ara[i]==11) continue;

            ret+= DP(x,y, pos+1, isSmaller| ara[i]< digs[pos], 0, num*10+ara[i] );
        }


    }
    else
    {

        for(int i=0; ara[i]<=ses && i<=1; i++)
        {
            //printf("%d %d\n",ara[1],ara[0]);
            if(ara[i]==0) continue;
            if(ara[1]==ara[0]) continue;
            if(ara[i]==11) continue;

            ret+= DP(x,y, pos+1, isSmaller| ara[i]< digs[pos],0,num*10+ara[i] );
        }

        // printf("hi\n");
        ret+= DP(x,y,pos+1,1,1, num);

    }

    //vis[x][y][pos][isSmaller][isStart]=1;
    return dp[x][y][pos][isSmaller][isStart]=ret;

}


void f(int n)
{
    digs.clear();

    while(n)
    {
        int rem=n%10;
        digs.push_back(rem);
        n=n/10;
    }

    reverse(digs.begin(), digs.end());
    lim= digs.size();

    int total=0;


    for(int i=0; i<=9; i++)
    {
        for(int j=i; j<=9; j++)
        {
            //if(vis[i][j][0][0][1]==0)
            // if(i==j) continue;
            if(i==j) continue;
            // printf("x=%d y=%d ans= %d\n",i,j,DP(i,j,0,0,1,0));
            total+=DP(i,j,0,0,1,0)- DP(i,11,0,0,1,0)- DP(j,11,0,0,1,0);
        }
    }

    for(int i=1; i<=9; i++) total+=DP(i,11,0,0,1,0);

    cout<<total<<endl;

    //cout<<"result"<< DP(2,2,0,0,1,0)<<endl;

    //    int t1=DP(1,3,0,0,1,0);
    //    puts("");
    //    int t2=DP(1,11,0,0,1,0);
    //    puts("");
    //    int t3=DP(3,11,0,0,1,0);
    //    puts("");
    //    printf("%d %d %d\n",t1,t2,t3);

}

int main()
{

    ms(dp,-1);
    int n;
    scanf("%d",&n);

    f(n);

}
