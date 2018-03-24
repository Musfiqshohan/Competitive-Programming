#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define llu unsigned long long
#define pii pair<i64,i64>
#define inf 1000000000000000000
using namespace std;

vector<llu>vec;

llu dp[20][2][2][2][20],vis[20][2][2][2][20];
llu f(llu pos, llu isStart, llu isSmall, llu isOne, llu l)
{
    if(pos==l)
        return 1;

    if(vis[pos][isStart][isSmall][isOne][l]==1) return  dp[pos][isStart][isSmall][isOne][l];
    vis[pos][isStart][isSmall][isOne][l]=1;


    llu st= isStart? 1:0;
    llu ses= isSmall? 9:vec[pos];

    llu tot=0;

    for(llu i=st; i<=ses; i++)
    {
        if(isOne==1 && i==3) continue;

        tot+= f(pos+1, 0, i<ses| isSmall, i==1, l);
    }
    return dp[pos][isStart][isSmall][isOne][l]=tot;
}

llu Solve(llu n)
{
    ms(vis,0);
    vec.clear();
    while(n)
    {
        vec.push_back(n%10);
        n/=10;
    }
    reverse(vec.begin(),vec.end());

    llu l=vec.size();

    llu tot=f(0,1,0,0,l);

    while(l--)
    {
        if(l==0) break;
        tot+=f(0,1,1,0,l);
    }

    return tot;

}

int main()
{

    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    llu tt;
    cin>>tt;
    while(tt--)
    {
        llu n;
        cin>>n;
        // cout<<Solve(n)<<endl;

        llu low=1,high= 1e19+5, mid,cnt=100; //

        while(cnt--)
        {
            mid=low;
            mid+= (high-low)/2;

            llu res=Solve(mid);

         //   cout<<mid<<" "<<res<<endl;

            if(res>=n)
                high=mid;
            else low=mid;
        }

        if(Solve(mid)<n) mid++;

        cout<<mid<<endl;

    }
}
