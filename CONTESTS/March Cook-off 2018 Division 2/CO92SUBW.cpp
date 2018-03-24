#include<bits/stdc++.h>
#define pii pair<int,int>
#define inf 10000000000
#define i64 long long
using namespace std;


int main()
{

    int tt;
    cin>>tt;

    while(tt--){

    i64 n,tot1=0,tot2=0;
    cin>>n;

    i64 sum1=0,sum2=0,sum=1,cs1,cs2;
    for( int i=2;i<=100000;i++)
    {
        if(sum+i>n){
            sum1=sum;
            cs1=i-1;

            sum2=sum+i;
            cs2=i;
            break;
        }
        sum=sum+i;
    }



    tot1+=cs1;
    i64 rem1=n-sum1;
    tot1+=rem1;


    tot2+=cs2;
    i64 rem2=sum2-n;
    tot2+=rem2;
    //printf("%lld %lld %lld\n",cs2,rem2,sum2);


   // printf("1=%lld 2=%lld\n",tot1,tot2);

    cout<<min(tot1,tot2)<<endl;

    }

    return 0;

}
