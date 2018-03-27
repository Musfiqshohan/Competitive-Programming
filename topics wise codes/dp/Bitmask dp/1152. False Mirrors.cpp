#include<bits/stdc++.h>
using namespace std;
int n;

int dp[(1<<20)+5], w[25];
bool check(int N,int pos) { return  N&(1<<pos); }
int Set(int N ,int pos) { N=N|(1<<pos);   N=N|(1<<(pos+1)%n);  N= N|(1<<(pos+2)%n);  return N; }

int f(int mask)
{

    if(mask==(1<<n)-1) return 0;

    if(dp[mask]!=-1) return dp[mask];
    int mn=INT_MAX,i,j;
    for(i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            int damage=0;
                for(j=0;j<n;j++)
                {
                    if(j!=i && j!=(i+1)%n && j!=(i+2)%n && check(mask,j)==0)
                        damage+=w[j];

                }



            mn=min(mn,damage+f(Set(mask,i)));

        }
    }

    return dp[mask]=mn;
}

int main()
{
    memset(dp,-1,sizeof dp);
    int i,j;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&w[i]);

    printf("%d\n",f(0));
}
