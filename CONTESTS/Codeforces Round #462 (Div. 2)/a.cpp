#include<bits/stdc++.h>
#define ll long long
using namespace std;

int ara[55];
int main()
{
    int n,m,x,mx=INT_MIN;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
    }


    sort(ara,ara+n);

    for(int i=0;i<m;i++)
    {
        cin>>x;
        mx=max(mx,x);
    }



    ll res=(ll)mx*ara[n-2];
    cout<<res<<endl;
}
