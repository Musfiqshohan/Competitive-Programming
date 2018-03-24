#include<bits/stdc++.h>
#define ll long long
using namespace std;

priority_queue<ll, vector<ll>, greater<ll>>pq;
int main()
{

    ll n,x,tot=0,tot2=0;
    scanf("%lld",&n);


    if(n%2==0)
        pq.push(0);

    for(int i=0; i<n; i++)
    {
        scanf("%lld",&x);
        tot2+=x;
        pq.push(x);
    }

    if(n==1)
        tot=0;
    else if(n==2)
        tot=tot2;
    else
    {

        int cnt=0;
        while(pq.size()>1)
        {
            ll x=0,y=0,z=0;
            ll res=0;

            x=pq.top();
            pq.pop();

            y=pq.top();
            pq.pop();

            z=pq.top();
            pq.pop();

            res=x+y+z;
            tot+=res;
            // cout<<x<<" "<<y<<" "<<" "<<z<<" "<<pq.size()<<endl;
            pq.push(res);
        }
    }

    cout<<tot<<endl;

    return 0;
}
