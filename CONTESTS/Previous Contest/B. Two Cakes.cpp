#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define INF 1000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
int n;
int f(int pos, int a, int b, int turn)
{
    printf("%d %d %d\n",pos,a,b);
    if(a<0 || b<0) return -10000000;

    if(pos==n)
    {
        if(a==0 && b==0)
            return 0;
        else return -10000000;
    }
    int t1,t2,t3,t4;
    t1=t2=t3=t4=-10000000;


    if(turn==0)
        t1=1+f(pos,a-1,b,0);

    if(turn==1)
        t2=1+f(pos,a,b-1,1);

    if(turn==0 || turn==1)
    {
        t3=max(0,f(pos+1,a,b,0));
        t4=max(0, f(pos+1,a,b,1));
        t3=max(t3,t4);
    }

    return max(t1,max(t2,t3));

}




int main()
{
    int a,b;
    scanf("%d %d %d",&n,&a,&b);

    cout<<max(f(0,a,b,0), f(0,a,b,1))<<endl;
}
