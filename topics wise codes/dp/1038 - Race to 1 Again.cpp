#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a);
using namespace std;

int vis[100009];
double dp[100009];

double f(int n)
{
    //cout<<n<<endl;

    if(n==1) return 0;

    if(vis[n]!=-1) return dp[n];
   // if(dp[n]!=-1) return dp[n];

    int cnt=0;
    double sum=0;
    int root= sqrt(n);

    for(int i=2;i<=root;i++)
    {
        if(n%i==0)
        {

            if(i!=n/i)
            {
                sum+= f(i)  + f(n/i);
                cnt+=2;
            }
            else
            {
                sum+= f(i);
                cnt++;
            }
        }
    }

    cnt+=2 ;

   // printf("%d-> %d\n",n,cnt);
    sum+=cnt;
    sum= sum/(cnt-1);

    vis[n]=1;
    return dp[n]=sum;

}


int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){
    ms(vis,-1);
    ms(dp,0);
    double n;
    cin>>n;
    printf("Case %d: %.10f\n",++t,f(n));

    }

    return 0;
}
