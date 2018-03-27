#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;


int s,t,flag=0;
vector<int>vec;
int vis[1009],dis[1009],vis2[50];



void clearr()
{
    vec.clear();
    ms(vis,0);
    ms(dis,0);
    ms(vis2,0);
    flag=0;
}

void BFS(int src)
{
    queue<int>q;
    q.push(src);

    if(src==t) { flag=1; return; }

    vis[src]=1;
    dis[src]=0;

    while(!q.empty())
    {
        int n= q.front();
        q.pop();
        int u=n;

        vec.clear();
        for(int i=2; i<= sqrt(n); i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n/=i;
                }
                vec.push_back(i);
            }
        }

        if(n!=1) vec.push_back(n);

        if(n==u) vec.clear();



        for(int i=0; i<vec.size(); i++)
        {
            int node= u+vec[i];

            if(vis[node]==0 && node<=t)
            {
                // printf("%d->%d\n",u,node);

                vis[node]=1;

                dis[node]=dis[u]+1;

                if(node==t)
                {
                    flag=1;
                    return;
                }

                q.push(node);
            }
        }


    }

}


int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        cin>>s>>t;



        BFS(s);

        printf("Case %d: ",++tt);

        if(flag==0) printf("-1\n");
        else
            printf("%d\n",dis[t]);

        clearr();

    }

    return 0;
}
