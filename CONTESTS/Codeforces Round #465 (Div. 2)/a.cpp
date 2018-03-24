#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define llu unsigned long long
#define pii pair<i64,i64>
#define inf 1000000000000000000
using namespace std;

int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        if((n-i)%i==0)
            cnt++;
    }

    cout<<cnt<<endl;
}
