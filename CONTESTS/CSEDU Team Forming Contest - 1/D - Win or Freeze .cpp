#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 100000000000099
using namespace std;

ll ara[4000009];
int main()
{
    ll n,cnt=0,m;

    scanf("%lld",&n);
    m=n;

    ll root=sqrt(n);

    for(ll i=2;i<=root;i++)
    {
        if(n%i==0)
        {
           // int num=0;
            while(n%i==0)
            {
                cnt++;
                n/=i;
                ara[i]++;
            }
        }

        root=sqrt(n);
    }

    if(n!=1) cnt++;


    if(cnt==2) printf("2\n");
    else if(cnt==1 || m==1) printf("1\n0\n");
    else
    {
        printf("1\n");


        cnt-=2;
        ll flag=0,total=1;
        for(ll i=2;i<=sqrt(m) && flag==0;i++)
        {
            if(ara[i]!=0)
            {
                while(ara[i]!=0)
                {
                    total=total*i;
                    ara[i]--;
                    cnt--;

                    if(cnt==0) { flag=1; break; }


                }
            }
        }

        printf("%lld\n",m/total);

    }


    return 0;
}
