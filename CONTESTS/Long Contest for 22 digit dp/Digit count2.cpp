#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<i64,i64>
#define inf 1000000000000000000
using namespace std;

vector<int>vec,digs1, digs2;

int ara[15];


int dp[11][2][2][11][11];
bool vis[11][2][2][11][11];
int f(int pos, int isStart, int isSmaller, int n, int tar)
{
    if(pos==n)
    {
        return 0;
    }

    if(vis[pos][isStart][isSmaller][n][tar]==1) return dp[pos][isStart][isSmaller][n][tar];
    vis[pos][isStart][isSmaller][n][tar]=1;
    int st= isStart? 1:0;
    int ses= isSmaller? 9: vec[pos];

    int tot=0;
    for(int i=st; i<=ses; i++)
    {

        int ret=f(pos+1,0, isSmaller| i<ses,n,tar);

        int L=vec.size();

        if(i==tar)
        {
            if(isSmaller| i<ses)
                ret+=digs2[L-n+pos+1];
            else
                ret+=digs1[L-n+pos+1];
        }

        tot+=ret;
    }

    return dp[pos][isStart][isSmaller][n][tar]=tot;
}

void Solve(int n, int sign)
{

    vec.clear();
    digs1.clear();
    digs2.clear();
    int tot1=0,tot2=1, d=1;
    while(n)
    {
        vec.push_back(n%10);

        tot1=(n%10*d)+tot1;
        d*=10;
        tot2*=10;
        digs1.push_back(tot1+1);
        digs2.push_back(tot2);

        n/=10;
    }

    reverse(vec.begin(),vec.end());
    reverse(digs1.begin(),digs1.end());
    reverse(digs2.begin(),digs2.end());

    digs1.push_back(1);  ///changed here
    digs2.push_back(1);




    for(int i=0; i<10; i++)
    {
        int l=vec.size();
        // memset(vis,0,sizeof vis);
        int tot=f(0,1,0,l,i);

        while(l--)
        {
            //  memset(vis,0,sizeof vis);
            int ret=f(0,1,1,l,i);
            tot+=ret;
        }
        ara[i]+=tot*sign;
    }


}


void count_dig(int n)
{
    int ara[15];
    memset(ara,0,sizeof ara);
    for(int i=0; i<=n; i++)
    {
        int m=i;
        while(m)
        {
            ara[m%10]++;
            m/=10;
        }
        // printf("%d\n",i);
    }

    for(int i=0; i<10; i++)
        printf("%d ",ara[i]);
    puts("");

}



int main()
{
    while(1)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a==0 && b==0) break;
        // scanf("%d",&a);

        memset(ara,0,sizeof ara);
        memset(vis,0,sizeof vis);
        Solve(b,1);
        memset(vis,0,sizeof vis);
        Solve(a-1,-1);

        //count_dig(a);

        for(int i=0; i<10; i++)
        {
            if(i) printf(" ");
            printf("%d",ara[i]);
        }
        puts("");

    }


}

