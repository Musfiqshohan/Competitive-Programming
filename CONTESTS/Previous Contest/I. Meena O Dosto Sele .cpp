#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 30000000999
#define pii pair<ll,ll>

using namespace std;

int pow1(int x , int n)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        int ret= pow1(x,n/2);
        return ret*ret;
    }

    return x*pow1(x,n-1);
}

int mx=0;
int f(int N)
{

   // printf("Came with %d\n",N);
    mx= max(mx,N);

    for(int k=0; ; k++)
    {
        int M=N ;//+ pow1(2,k);

        // pow1(2,k+2) <=N


        if(pow1(2,k+2)>M) break;

      //  printf("%d + %d = %d   >= %d\n",N, pow1(2,k), M, pow1(2,k+2));

        if(M%pow1(2,k+2)>= pow1(2,k)  &&  M%pow1(2,k+2) < pow1(2,k+1))
        {

      //  printf("%d mod %d >= %d  and %d mod %d < %d\n",M,pow1(2,k+2), pow1(2,k), M, pow1(2,k+2), pow1(2,k+1));

            int ret= f(M+ pow1(2,k));

           // printf("%d the person gets return  %d\n",turn, ret);

            if(ret==0)
                return 1;
        }

    }


    return 0;
}

int main()
{
    int t=0,test;
    cin>>test;
    while(++t<test) {
    int n;
   // scanf("%d",&n);

   n=t;


    int res= f(n);

    printf("%d -> %d\n",n,mx);
    mx=0;
    //cout<<f(n,0)<<endl;
    }


}
