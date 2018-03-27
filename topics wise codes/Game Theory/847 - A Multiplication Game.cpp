#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,cnt=0;
    while(scanf("%lld",&n)!=EOF){

    cnt=1;
    while(n>1)
    {
        if(cnt%2==1){
            n=ceil(n*1.0/9);
            cnt=0;
        }
        else {
        n=ceil(n*1.0/2);
        cnt=1;
        }

   // printf("%d %d\n",n,cnt);

    }

    if(cnt==0) printf("Stan wins.\n");
    else printf("Ollie wins.\n");
    }

    return 0;
}
