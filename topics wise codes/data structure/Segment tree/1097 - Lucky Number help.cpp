#include <bits/stdc++.h>
using namespace std;

/*------- Constants---- */
#define LMT             100
#define ll              long long
#define ull             unsigned long long
#define mod             1000000007
#define MEMSET_INF      63
#define MEM_VAL         1061109567
#define FOR(i,n)            for( int i=0 ; i < n ; i++ )
#define mp(i,j)         make_pair(i,j)
#define lop(i,a,b)      for( int i = (a) ; i < (b) ; i++)
#define pb(a)           push_back((a))
#define gc              getchar_unlocked
#define PI              acos(-1.0)
#define inf             1<<30
#define lc              ((n)<<1)
#define rc              ((n)<<1 |1)
#define msg(x)          cout<<x<<endl;

/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))


const int MAC = 2097152;
const int IM = 1429500;
int seg[3*IM];

int ans[100005];

void build(int n,int b,int e)
{
    if( b == e) {
        seg[n] = b & 1;
        return;
    }

    int mid = (b+e)>>1;
    build(lc, b, mid);
    build(rc, mid+1, e);
    seg[n] = seg[lc] + seg[rc];
}


void updt (int n,int b,int e,int fr )
{
    if(b == e) {
        seg[n] = 0;
        return;
    }

    int mid = (b+e) >> 1;
    if( seg[lc] >= fr ) updt(lc, b, mid, fr);
    else updt(rc, mid + 1, e, fr - seg[lc]);

    seg[n] = seg[lc] + seg[rc];
}


int  query(int n,int b,int e ,int fre)
{

    if(b==e) return b; // b is the fre th element of the current list
    int mid = (b+e)/2;

    if(seg[lc] >= fre) return query(lc, b, mid, fre);
    else return query(rc, mid + 1, e, fre - seg[lc]);
}


void init()
{
    build(1,1,IM);
    cout<<query(1,1, IM, 2)<<endl;
//    ans[1] = 1;
//    for(int i = 2; i < 100001 ; i ++ ) {
//
//        int ithElement = query(1, 1, IM, i) ;
//
//        ans[i] = ithElement;
//
//        int j = (IM / ithElement) * ithElement;
//
//        for( ; j >= ithElement ; j -= ithElement ){
//            updt(1, 1, IM, j);
//        }
//    }

}
int main()
{
    init();
    int tc , n ,cs = 0 ;

//    sc(tc);
//    while (tc -- ) {
       // sc(n);
       // printf("Case %d: %d\n", ++cs , ans[n]);
  //  }

    return 0;
}
