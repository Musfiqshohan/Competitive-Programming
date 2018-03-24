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
string str;

int f(int pos, int sum)
{

    if(str[pos]=='('){
        f(pos+1,sum+1);
    }
    else if(str[pos]==')'){

        if(sum-1==0) t2=1;
        t2+=f(pos+1, sum-1);
    }
    else
    {
        t1=f(pos+1,sum+1);
        t2=f(pos+1,sum-1);

    }

}


int main()
{
    cin>>str;

    cout<<f(0,0)<<endl;


}
