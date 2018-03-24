#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000000000000000
#define pii pair<ll,ll>
#define mod 1000000007
using namespace std;

int f(int a,int b, int i, int j)
{
     return (a*i+b*j) ^ (a*j+b*i);
}

void print(int n)
{
    bitset<8>bset(n);
    cout<<n<<" :"<<bset<<endl;
}

int main()
{
    while(1){
    int n,a,b;
    cin>>n>>a>>b;

    int mx=-1, mxx=-1,mxy=-1,res=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i&j==j)
            {
                int res=f(a,b,i,j);

               // printf("->res=%d  x=%d  y=%d\n",res,i,j);
                if(res>=mx)
                {
              //1  printf("res=%d  x=%d  y=%d\n",mx,mxx,mxy);
//                    print(res);
//                    print(mxx);
//                    print(mxy);
                    mx=res;
                    mxx=i;
                    mxy=j;
                }
            }
        }
    }

    //cout<<f(a,b,15,10)<<endl;

    printf("res=%d  x=%d  y=%d\n",mx,mxx,mxy);

    }

}
