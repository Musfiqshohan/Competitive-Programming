#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int b_size, n,m;
ll u;
ll ara[300009];
struct item
{
    ll val;
    int indx;
};

vector<item>bucket[550];

bool cmp(item a, item b)
{
    return a.val<b.val;
}

void make_bucket()
{
    b_size=sqrt(n);
    int b_indx=-1;

    for(int i=0; i<n; i++)
    {
        if(i%b_size==0)
            b_indx++;

        bucket[b_indx].push_back({ara[i], i});
    }

    for(int i=0; i<=b_indx; i++)
        sort(bucket[i].begin(), bucket[i].end(),cmp);

//
//    puts("->");
//    for(int i=0; i<=b_indx; i++)
//    {
//        for(int j=0; j<bucket[i].size(); j++)
//            printf("%d ",bucket[i][j].val);
//
//        puts("");
//    }

}

void update(int indx, ll val)
{
    ///change the array and sort the vector

    int  v_indx;
    int cur=indx/b_size;

    for(int i=0; i< bucket[cur].size(); i++)
    {
        if(bucket[cur][i].indx==indx)
        {
            v_indx=i;
            break;
        }
    }


    ll init= ara[indx];
    ara[indx]=val;
    bucket[cur][v_indx].val=val;

    if(bucket[cur][v_indx].val>init)
    {
        while(v_indx+1<bucket[cur].size() && bucket[cur][v_indx].val > bucket[cur][v_indx+1].val)
        {
            swap(bucket[cur][v_indx],bucket[cur][v_indx+1]);
            v_indx++;
        }

    }
    else
    {
        while(v_indx-1>=0 && bucket[cur][v_indx].val < bucket[cur][v_indx-1].val)
        {
            swap(bucket[cur][v_indx],bucket[cur][v_indx-1]);
            v_indx--;
        }
    }

}


int b_src(int cur, ll target)
{
    int low=0, high=bucket[cur].size()-1;

    int cnt=20,mid;
    while(cnt--)
    {
        mid= low+ (high-low)/2;

        if(bucket[cur][mid].val>=target)
            high=mid-1;
        else low=mid;
    }

    if(mid+1<bucket[cur].size() && bucket[cur][mid+1].val<target) mid++;
    if(bucket[cur][mid].val>=target) return -1;

    return mid;
}

void query(int l, int r, ll v, int p)
{
    int k=0,l1=l,r1=r;

    while(l<r && l%b_size!=0)
    {
        if(ara[l]<v)
            k++;

        l++;
    }


    while(l+b_size<=r)
    {
        int cur= l/b_size;

        int ret=b_src(cur,  v);

        if(ret>=0) k+=(ret+1);

        l+=b_size;
    }



    while(l<=r)
    {
        if(ara[l]<v)
            k++;

        l++;
    }




   // printf("k= %d u=%d r=%d l= %d\n",k,u,r1,l1);

    ll val= (u *k) / (r1-l1+1);
   // printf("Val= %d\n",val);
    update(p,val);

}

int main()
{


    scanf("%d %d %lld",&n,&m,&u);
    for(int i=0; i<n; i++)
        scanf("%lld",&ara[i]);


    make_bucket();

    int l,r,p;
    ll v;
    rep(i,m)
    {
        scanf("%d %d %lld %d",&l,&r,&v,&p);

        query(l-1,r-1,v,p-1);

    }

    for(int i=0; i<n; i++)
        printf("%lld\n",ara[i]);




}
