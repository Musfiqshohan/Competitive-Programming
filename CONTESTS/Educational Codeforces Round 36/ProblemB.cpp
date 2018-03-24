#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

int n,pos,l,r;
int f1( )
{
    int tot=0;
    int left=l-1;
    int right=n-r;

    if(left!=0 && right!=0)
        {tot= r-l + min(r-pos, pos-l)+2;
           // cout<<tot<<endl;
        }
    else if(left==0 && right==0)
        tot=0;
    else if(left==0)
        tot=r-pos+1;
    else
        tot=pos-l+1;

    return tot;
}

int f2()
{
    int tot=0;
    int left=l-1;
    tot=pos-r+1;

    if(left>0)
    {
        //cout<<tot<<endl;
        tot+=r-l+1;
   // cout<<tot<<endl;
    }


    return tot;
}

int f3()
{
    int tot=0;
    int right=n-r;
    tot=l-pos+1;

    if(right>0)
    {
        //cout<<tot<<endl;
        tot+=r-l+1;
        //cout<<tot<<endl;
    }

    return tot;

}

int main()
{

    cin>>n>>pos>>l>>r;

    int res;
    if(pos>=l && pos<=r)
        res=f1();

    else if(pos>r)
        res= f2();
    else res=f3();


    cout<<res<<endl;

}
