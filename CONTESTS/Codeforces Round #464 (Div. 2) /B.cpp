#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<int,int>
#define inf 1000000000000000000

using namespace std;

int main()
{
    i64 n,x;
    int k;
    cin>>n>>k;

    i64 mn=inf,num=0,resi=0;
    for(int i=0;i<k;i++)
    {
        cin>>x;

        if(n%x<mn)
        {
            mn=n%x;
            num=(n/x);
            resi=i+1;
        }

    }

    cout<<resi<<" "<<num<<endl;


}
