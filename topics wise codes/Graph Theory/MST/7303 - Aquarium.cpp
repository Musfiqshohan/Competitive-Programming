#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

char str[109][109];
ll cost[209][209];
ll r,c;
pii par[500][500];
struct edge
{

    pii u,v;
    ll w;
    bool operator <(const edge &n)const
    {
        return w<n.w;
    }

};
vector<edge>vec;

void clearr()
{
    vec.clear();
    ms(par,0);
    ms(cost,0);
    ms(str,0);

}


pii findd(pii r)
{

    return  par[r.first][r.second]= (par[r.first][r.second]==r)? r:  findd(par[r.first][r.second]);

}

//bool compare(edge a, edge b)
//{
//    return a.w<b.w;
//}



ll mst(ll n)
{
    sort(vec.begin(),vec.end());

    for(ll i=0;i<r;i++)
    {
        for(ll j=0;j<c;j++)
        {
            par[i][j]={i,j};
            par[i+200][j]={i+200,j};
        }
    }

    ll cnt=0,sum=0;
    for(ll i=0;i<vec.size();i++)
    {
        pii u= findd(vec[i].u);
        pii v= findd(vec[i].v);

        if(u!=v)
        {
            par[u.first][u.second]=v;
            cnt++;
            sum+= vec[i].w;

            if(cnt==n-1) break;

        }

    }


    return sum;



}

int main()
{

    ll tt=0,test;
    cin>>test;

    while(tt<test) {


    scanf("%lld %lld",&r,&c);
    getchar();

    for(ll i=0; i<r; i++)
    {
         scanf("%s",&str[i]);
    }

    for(ll i=0;i<r;i++)
        for(ll j=0;j<c;j++)
            scanf("%lld",&cost[i][j]);


    for(ll i=0; i<r; i++)
    {
        for(ll j=0; j<c; j++)
        {

            ll w= cost[i][j];
            vec.push_back({{i,j}, {i+200,j}, w});


            if(j+1<c)
            {
                if(str[i][j]=='/' && str[i][j+1]=='\\')
                    vec.push_back({{i,j}, {i,j+1}, 0});

                if(str[i][j]=='/' && str[i][j+1]=='/')
                    vec.push_back({{i,j}, {i+200,j+1}, 0});

                if(str[i][j]=='\\' && str[i][j+1]=='\\')
                    vec.push_back({{i+200,j}, {i,j+1}, 0 });

                if(str[i][j]=='\\' && str[i][j+1]=='/')
                    vec.push_back({{i+200,j}, {i+200,j+1}, 0 });
            }
            if(i+1<r)
            {
                if(str[i][j]=='/' && str[i+1][j]=='\\')
                    vec.push_back({{i,j}, {i+201,j}, 0});

                if(str[i][j]=='/' && str[i+1][j]=='/')
                    vec.push_back({{i,j},  {i+201,j}, 0});

                if(str[i][j]=='\\' && str[i+1][j] =='\\')
                    vec.push_back({{i,j}, { i+201, j}, 0});

                if(str[i][j]=='\\' && str[i+1][j]=='/')
                    vec.push_back({{i,j}, {i+201,j}});

            }


        }
    }




    //cout<<vec.size()<<endl;

//    for(ll i=0;i<vec.size();i++)
//    {
//        printf("%d,%d  <-> %d,%d  =%d\n",vec[i].u.first, vec[i].u.second, vec[i].v.first, vec[i].v.second, vec[i].w );
//    }

    printf("Case %lld: %lld\n",++tt,mst(r*c*2));

    clearr();

    }

    return 0;
}
