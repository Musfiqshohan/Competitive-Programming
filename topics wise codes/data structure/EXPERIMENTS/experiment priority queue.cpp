#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 100000000000099
using namespace std;

struct node
{
    int city,dist;


    bool operator < (const node &n) const
    {
        if(city==n.city)
            return dist < n.dist;
        return city>n.city;
    }

};

priority_queue <node> pq;

int main()
{
    int n,x,y;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&x,&y);
        pq.push({x,y});
    }

    while(!pq.empty())
    {
        node p=pq.top();
        pq.pop();

        printf("%d %d\n",p.city,p.dist);
    }
}
