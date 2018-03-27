#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

map<string,int>mp;

int par[100009],nodes[100009];
int findd(int r)
{
    if(par[r]==r) return r;

    return par[r]=findd(par[r]);
}

void unionn(int a,int b)
{
    int u=findd(a);
    int v=findd(b);

    if(u!=v)
    {
        par[u]=v;
        nodes[v]+=nodes[u];
        cout<<nodes[v]<<endl;

       // printf("%d->%d %d->%d\n",a,u,b,v);
    }
    else cout<<nodes[v]<<endl;
}

int main()
{
    int t;
    cin>>t;

    getchar();
    while(t--)
    {
        int f;
        cin>>f;

        string s1,s2;
        int cnt=1;
        for(int i=0; i<f; i++)
        {
            cin>>s1>>s2;

            if(mp[s1]==0)
            {
                mp[s1]=cnt;
                par[cnt]=cnt;
                nodes[cnt]=1;
                cnt++;
            }

            if(mp[s2]==0)
            {
                mp[s2]=cnt;
                par[cnt]=cnt;
                nodes[cnt]=1;
                cnt++;
            }

            unionn(mp[s1],mp[s2]);
        }

        mp.clear();

    }

    return 0;
}
