#include<bits/stdc++.h>
#define i64 long long
#define pii pair<i64,i64>
using namespace std;

int ara[1000009][10];

int f(int n)
{
    if(n<10) return n;
    int res=1;
    while(n)
    {
        if(n%10!=0)
            res*=n%10;
        n/=10;
    }

   // printf("res=%d\n",res);
    return f(res);

}

int main()
{

   // cout<<f(999999)<<endl;

   // return 0;

    for(int i=1; i<=1000009; i++)
    {
        int ret=f(i);
        //  ara[i][ret]=ara[i-1][ret]+1;

        for(int j=1; j<=9; j++)
        {
            ara[i][j]=ara[i-1][j];
            if(j==ret)
                ara[i][j]++;
        }

        //printf("%d %d\n",ret,ara[i][4]);
    }


    int q,l,r,k;
    cin>>q;
    while(q--)
    {
        cin>>l>>r>>k;

        cout<<ara[r][k]-ara[l-1][k]<<endl;

    }


    return 0;

}
