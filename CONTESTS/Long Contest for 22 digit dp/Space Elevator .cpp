#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define llu unsigned long long
#define pii pair<i64,i64>
#define inf 1000000000000000000
using namespace std;

vector<llu>vec;

llu dp[20][2][2][2][20];
llu f(llu pos, llu isStart, llu isSmaller, llu isOne, llu l, llu sum)
{
    if(pos==l)
    {
        // cout<<sum<<endl;
        return 1;
    }

    if(dp[pos][isStart][isSmaller][isOne][l]!=-1) return dp[pos][isStart][isSmaller][isOne][l];

    llu st= isStart? 1:0;
    llu ses= isSmaller? 9:vec[pos];


    //prlluf("st=%llu ses=%llu\n",st,ses);

    llu tot=0;
    for(llu i=st; i<=ses; i++)
    {
        if(i==4) continue;
        if(i==3 && isOne==1) continue;
        tot+=f(pos+1, 0, isSmaller|i<ses, i==1,l, sum*10+i);
    }

    return dp[pos][isStart][isSmaller][isOne][l]=tot;

}



llu Solve(llu n)
{
    vec.clear();
    while(n)
    {
        vec.push_back(n%10);
        n/=10;
    }

    reverse(vec.begin(), vec.end());

    llu l=vec.size();

    ms(dp,-1);
    llu tot=f(0,1,0,0,l,0);
    while(l--)
    {
        if(l==0) break;
        // prlluf("l=%llu\n",l);
        tot+=f(0,1,1,0,l,0);
    }

    return tot;
    //cout<<tot<<endl ;

}


int main()
{
    llu n;
    while(scanf("%llu",&n)==1)
    {

//    cout<<Solve(n)<<endl;
//    return 0;

        llu low=1,high=1e19+5, mid ;
        llu cnt=100;

        while(cnt--)
        {

            mid=low;
            llu temp=(high-low)/2;
            mid+=temp;

            llu res=Solve(mid);

            // prlluf("low=%llu high=%llu res=%llu\n",low,high,res);

            if(res>=n)
                high=mid;
            else low=mid;
        }

        if(Solve(mid)<n)
            mid++;

        printf("%llu\n",mid);
    }

}
