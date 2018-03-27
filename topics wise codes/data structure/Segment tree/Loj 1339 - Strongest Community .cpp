///http://www.lightoj.com/volume_showproblem.php?problem=1339
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define INF 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
const int MAXN=100009;
int ara[MAXN];
struct info
{
    int mx,Ln,Locr,Rn,Rocr;
} T[4*MAXN];


info Merge(info LC, info RC)
{

    if(LC.mx==-1) return RC;
    else if(RC.mx==-1) return LC;

    info r;
    int shroc=0;
    if(LC.Rn==RC.Ln)
    {
        shroc=LC.Rocr+RC.Locr;
    }

    r.mx= max(shroc, max(LC.mx, RC.mx));
    r.Ln=LC.Ln, r.Rn=RC.Rn;

    if(LC.Ln==RC.Ln)
        r.Locr=LC.Locr+RC.Locr;
    else r.Locr=LC.Locr;

    if(RC.Rn==LC.Rn)
        r.Rocr=RC.Rocr+LC.Rocr;
    else r.Rocr=RC.Rocr;

    return r;

}


void build(int nd, int b, int e)
{
    // printf("%d %d %d\n",nd,b,e);
    if(b==e)
    {
        int x=ara[b];
        T[nd]= {1,x,1,x,1};
        return ;
    }


    int mid=(b+e)/2;
    int lc=nd*2;
    int rc=(nd*2)+1;

    build(lc,b,mid);
    build(rc,mid+1,e);

    T[nd]=Merge(T[lc], T[rc]);
}


info query(int nd, int b, int e, int i, int j)
{
    if(b>j || e<i)
        return {-1,0,0,0,0};

    if(b>=i && e<=j)
    {
        return T[nd];
    }

    int mid=(b+e)/2;
    int lc=nd*2;
    int rc=(nd*2)+1;

    info t1=query(lc,b,mid,i,j);
    info t2=query(rc,mid+1,e,i,j);


    info ret= Merge(t1,t2);

    //  printf("%d %d,,  Ln=%d Locr=%d Rn=%d Rocr=%d mx=%d\n",b,e, ret.Ln, ret.Locr, ret.Rn, ret.Rocr, ret.mx);
    return ret;


}

int main()
{

    int tt=0,test;
    scanf("%d",&test);

    while(tt<test)
    {
        printf("Case %d:\n",++tt);
        int n,c,q,x,y;
        scanf("%d %d %d",&n,&c,&q);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&ara[i]);
        }

        build(1,1,n);

        while(q--)
        {
            scanf("%d %d",&x,&y);
            info res= query(1,1,n,x,y);


            printf("%d\n",res.mx);
        }

        ms(T,0);


    }
    return 0;
}
