#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n;
pii dp[60009];


int calc(int a, int m)
{
    printf("Inf =%d %d\n",a,m);
    int sum= 2*a + m-1;
    sum= (sum*m)/2;

    printf("Inf res= %d\n",sum);
    return sum;
}
pii f(int pos)
{
    if(pos==n+1)  return {0,0};
    if(dp[pos].first!=-1) return dp[pos];

    pii ret=f(pos+1);
    pii t1= {pos+ret.first, ret.second};
    pii t2= {ret.first, pos+ret.second};

   // printf("%d %d  or %d %d\n",t1.first, t1.second, t2.first, t2.second);

    pii res;
    if(abs(t1.first-t1.second) < abs(t2.first- t2.second))
        res= t1;
    else res= t2;

    return dp[pos]=res;

}

vector<int>vec;
void print(int pos)
{
    if(pos==n+1)  return;

    pii ret=f(pos+1);
    pii t1= {pos+ret.first, ret.second};
    pii t2= {ret.first, pos+ret.second};

   // printf("%d %d  or %d %d\n",t1.first, t1.second, t2.first, t2.second);

    pii res;
    if(abs(t1.first-t1.second) < abs(t2.first- t2.second))
        vec.push_back(pos);


    print(pos+1);

}

int main()
{
    ms(dp,-1);
    scanf("%d",&n);


    pii tot= f(1);


    //cout<<tot.first<<" "<<tot.second<<endl;

    printf("%d\n",abs(tot.first-tot.second));

    print(1);

    printf("%d ",vec.size());

    for(int i=0;i<vec.size();i++) { if(i) printf(" "); printf("%d",vec[i]);  }

    puts("");
}
