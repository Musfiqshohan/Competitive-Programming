/** https://vjudge.net/contest/212042#problem/G   -tfc22
Here 1 4 12 , here i will sell 1 to 4 to gain +3, now i can assure that i cant gain more profit than +3 by selling
1 to any number less than 4, so its optimal. Now If this is 1 in disguise of 4. later if I get 12 , I will sell the fake
4 (means I have sold 1 to 12 and gain more 8 , total +3+8=+11) again, this is fake 4, but I should also consider
about real 4, so push it again.

**/

#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ll n,x;
    cin>>n;

    priority_queue<ll, vector<ll> , greater<ll>>pq;
    pq.push(INT_MAX);
    ll tot=0;
    for(ll i=0;i<n;i++)
    {
        cin>>x;

        ll q=pq.top();

       // prllf("%d %d\n",x,q);
        if(q<x){
            tot+=(x-q);
            pq.pop();
            pq.push(x);
        }

        pq.push(x);
    }

    cout<<tot<<endl;
}
