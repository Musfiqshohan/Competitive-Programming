//segmented sieve

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int prime[110009], num[110009],a[110009], num2[110009];

bool Check(int N , int pos) { return (bool)(N & (1<<pos) ) ;}
int Set(int N, int pos) { return N=N| (1<<pos); }
void sieve()
{
    int i,j;

    for(i=3;i<=300;i+=2)
    {
        if( Check(a[i>>5] , i&31) == false){
        for(j=i*i; j<=50000; j+=2*i)
            a[j>>5]=Set( a[j>>5] ,  j&31 );
        }
    }

    prime[0]=2;
    j=1;
    for(i=3;i<=50000;i+=2)
    if(Check(a[i>>5] , i&31)==false ){
        prime[j]=i;
        j++;
    }
}


int main()
{
    sieve();

    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
   ll a,b,cnt=0,n,root;

    scanf("%lld %lld",&a,&b);
    ll j,i;

    n=b-a+1;

    j=0;

    for(i=a;i<=b;i++) {num[j]=i;  num2[j]=i;  j++; }



    root=sqrt(b);

    for(i=0; prime[i] <= root; i++)
    {
        j=(a/prime[i]  + (bool)(a%prime[i]!=0) ) * prime[i];


        for(  ; j<=b;  j+= prime[i])
            {
                if(j==prime[i] || j==1 ) continue;
                num2[j-a]=0;

            }

    }


    if(num2[0]==1) num2[0]=0;

    for(i=0;i<n; i++)
        if(num2[i]!=0) cnt++;

    printf("Case %d: %lld\n",t+1,cnt);

    }

    return 0;
}
