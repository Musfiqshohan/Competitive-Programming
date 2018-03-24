#include<bits/stdc++.h>
#define i64 long long
#define pii pair<i64,i64>
using namespace std;


vector<int>vec;

i64 dp[64][64][4][4][4];

i64 f(int pos, int lpos, int isStart, int isSmall_1, int isSmall_2)
{
   // printf("%d %d %d %d\n",pos,lpos,isStart,isSmall_1);
    if(pos>=lpos+1)
    {
        if(isSmall_1==0 && isSmall_2==0)
            return 0;
        return 1;
    }


    if(dp[pos][lpos][isStart][isSmall_1][isSmall_2]!=-1)  return dp[pos][lpos][isStart][isSmall_1][isSmall_2];

    int ses= isSmall_1? 9: vec[pos];
    i64 tot=0;
    int st=0;
    if(!isStart)
        st=0;
    else st=1;

    for(int i=st; i<=ses; i++)
    {
        int tflag=0;
        if(i<vec[lpos])
            tflag=1;
        else if(i==vec[lpos])
            tflag=isSmall_2;

        tot+= f(pos+1,lpos-1, 0, isSmall_1|i<ses, tflag);
    }

    return dp[pos][lpos][isStart][isSmall_1][isSmall_2]=tot;
}


i64 Solve(i64 n)
{
    if(n==0) return 1;
    if(n<0) return 0;
    i64 m=n;

    while(m)
    {
        vec.push_back(m%10);
        m/=10;
    }

    reverse(vec.begin(),vec.end());
    int l=vec.size();

    i64 tot=f(0,l-1,1,0,2);

    l--;
    while(l>0)
    {
        i64 res=f(0,l-1,1,1,1);
        tot+=res;
        l--;
    }

    return tot+1;

}
int main()
{

    int tt=0,test;
    scanf("%d",&test);

    while(tt<test)
    {
        i64 a,b;
        scanf("%lld %lld",&a,&b);
        if(a>b) swap(a,b);

        memset(dp,-1,sizeof dp);
        i64 t1=Solve(b);
        vec.clear();

        memset(dp,-1,sizeof dp);
        i64 t2=Solve(a-1);
        vec.clear();

     //   cout<<t1<<" "<<t2<<endl;

        i64 res= t1-t2;

        printf("Case %d: %lld\n",++tt,res);
    }

}
