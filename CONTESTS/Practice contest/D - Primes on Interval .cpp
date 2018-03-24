#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;


int ara[1000011];
void sieve()
{
    for(int i=4;i<=1000009;i+=2) ara[i]=1;
    ara[1]=1;

    for(int i=3;i<=1009;i++)
    {
        if(ara[i]==0)
        {
          //  printf("%d\n",i);
            for(int j=2; i*j<=1000009;j++)
                ara[i*j]=1;
        }
    }

    for(int i=1;i<=100;i++)
        {
            if(ara[i]==0) ara[i]=ara[i-1]+1;
            else ara[i]=ara[i-1];

        }



}

int a,b,k;
int f(int l)
{
    if(b<a) return -1;

    for(int i=a;i<= b-l +1 ; i++)
    {
        if(ara[i+l-1]-ara[i-1]<k) return -1;
    }

    return 1;
}


int main()
{
    sieve();


    scanf("%d %d %d",&a,&b,&k);

    int high=b-a+1, low=1, cnt=0, mid;

   // cout<<f(3)<<endl;

    while(cnt++<32)
    {
        mid= (low+high)/2;

        if(f(mid)>0) high=mid;
        else low=mid;

    }

    printf("%d %d\n",mid, f(mid+1));

    int l=mid;

    //if(b-a+1<k)
    if(f(mid)<0 && f(mid+1)>0 && mid+1<=b-a+1) {printf("%d\n",mid+1); }  //  if(b-l+1+1<a) printf("-1\n"); else
    else if(f(mid-1)>0 && mid-1>=1)  {  printf("%d\n",mid-1); }  // if(b-l<a) printf("-1\n"); else
    else if(f(mid)>0)  {    printf("%d\n",mid);  }  // if(b-l+1<a) printf("-1\n"); else
    else printf("-1\n");
    //cout<<mid<<endl;

    return 0;
}
