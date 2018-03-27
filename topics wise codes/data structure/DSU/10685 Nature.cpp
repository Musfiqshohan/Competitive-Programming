#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

map<string, int >mp;
int nodes[5009],par[5009];
int mx=0;
int findd(int r)
{
    if(par[r]==r) return r;

    return par[r]= findd(par[r]);
}

void unionn(int a,int b)
{
    int u=findd(a);
    int v= findd(b);

    if(u!=v)
    {

        par[u]=v;
        nodes[v]+=nodes[u];

        mx= max(mx,nodes[v]);
    }
}

int main()
{
    int c,r;

    while(1)
    {
        scanf("%d %d",&c,&r);
        if(c==0 && r==0) break;

        string s,s2;
        mx=1;
        for(int i=0; i<c; i++)
        {
            cin>>s;
            mp[s]=i;

            par[i]=i;
            nodes[i]=1;
        }

        for(int i=0; i<r; i++)
        {
            cin>>s>>s2;
            unionn(mp[s], mp[s2]);
        }

        cout<<mx<<endl;
        mp.clear();
    }

    return 0;
}
