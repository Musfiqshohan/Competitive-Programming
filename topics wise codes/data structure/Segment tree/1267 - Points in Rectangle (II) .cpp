#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
const i64 MAXN=50009;
struct info
{
    i64 x,y,isq;

};

struct query
{
    i64 x1,y1,x2,y2,isVis,val;
} qry[MAXN];
vector<info>vec;
vector<i64>ypts;
map<i64,i64>mp, sp;
pii poi64s[MAXN];

i64 T[MAXN*4];

bool cmp(info a, info b)
{
    if(a.x==b.x)
    {
        if(a.isq==b.isq)
            return a.y<b.y;
        return a.isq<b.isq;
    }
    return a.x<b.x;
}



void update(i64 nd, i64 beg, i64  endd, i64 idx)
{
    // pri64f("%lld %lld %lld\n",beg, endd, idx);

    if(beg==endd)
    {
        T[nd]++;
        return;
    }

    i64 lc=nd*2;
    i64 rc=nd*2+1;
    i64 mid=(beg+endd)/2;

    if(idx<=mid)
        update(lc,beg,mid,idx);
    else update(rc,mid+1,endd,idx);

    T[nd]=T[lc]+T[rc];
}


i64 query(i64 nd, i64 beg, i64 endd, i64 l, i64 r)
{

    if(beg>r || endd<l) return 0;

    if(beg>=l && endd<=r)
    {
        return T[nd];
    }

    i64 lc=nd*2;
    i64 rc=nd*2+1;
    i64 mid=(beg+endd)/2;

    i64 t1=query(lc, beg, mid, l,r);
    i64 t2=query(rc,mid+1,endd,l,r);

    return t1+t2;

}


int main()
{

    i64 tt=0,test;
    cin>>test;

    while(tt<test)
    {

        printf("Case %lld:\n",++tt);
        i64 p,q,x,y,x1,y1,x2,y2;
        scanf("%lld %lld",&p,&q);

        for(i64 i=0; i<p; i++)
        {
            scanf("%lld %lld",&x,&y);
            sp[x]++;
            ypts.push_back(y);
            poi64s[i]= {x,y};
            vec.push_back({x,y,0});
        }

        for(i64 i=0; i<q; i++)
        {
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
            ypts.push_back(y1);
            ypts.push_back(y2);
            qry[i]= {x1,y1,x2,y2,0,0};
            vec.push_back({x1,i,1});
            vec.push_back({x2,i,1});
        }

        sort(ypts.begin(),ypts.end());
        i64 cnt=0;
        for(i64 i=0; i<ypts.size(); i++)
        {
            i64 v=ypts[i];
            if(mp.find(v)==mp.end())
                mp[v]=cnt++;
        }

        sort(vec.begin(),vec.end(),cmp);



        for(i64 i=0; i<vec.size(); i++)
        {
            //pri64f("%lld %lld %lld\n",vec[i].x, vec[i].y, vec[i].isq);
            if(vec[i].isq==1)
            {
                i64 idx=vec[i].y;
                i64 y1=qry[idx].y1;
                i64 y2=qry[idx].y2;

                i64 res=query(1,0,cnt+1, mp[y1], mp[y2]);


                if(qry[idx].isVis==0)
                    qry[idx].val=(-res+sp[vec[i].x]),qry[idx].isVis=1;
                else
                    qry[idx].val+=res;
                // pri64f("qres=%lld, idx=%lld  , val=%lld\n",res,idx,qry[idx].val);
            }
            else
            {
                // pri64f("i=%lld ,y=%lld, yy=%lld\n",i,vec[i].y,mp[vec[i].y]);
                update(1,0,cnt+1, mp[vec[i].y]);

                // pri64f("qry=%lld\n",query(1,0,cnt+1, mp[0], mp[vec[i].y]));
            }
        }


        for(i64 i=0; i<q; i++)
            printf("%lld\n",qry[i].val);


        mp.clear();
        sp.clear();
        vec.clear();
        ypts.clear();
        ms(T,0);
        ms(qry,0);
        ms(poi64s,0);

    }
    return 0;
}


