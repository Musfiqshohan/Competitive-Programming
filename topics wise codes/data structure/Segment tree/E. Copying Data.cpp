#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;

struct info
{
    int val,indx, len   ;
}tree[100009*4];

void build(int node, int beg, int endd)
{
    if(beg==endd)
    {
        tree[node].val=b[beg];
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    build(left, beg, mid);
    build(right,mid+1, endd);
}

void push_down(int node, int beg,int endd)
{
    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    tree[left].indx=


}

void update(int node, int beg, int endd, int indx, int length, int target)
{
    if(endd-beg+1 == length)
    {
        tree[node].indx=target;
        tree[node].len=length;
        return;
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    if(indx<=mid && indx+length-1<=mid)
        update(left, beg, mid, indx, length,target);
    else if(indx<=mid && indx+length-1>mid)
    {
        update(left, beg, mid, indx,  mid-indx+1 ,target);
        update(right, mid+1, endd, mid+1, start+rem-1-mid, target);
    }
    else
        update(right, mid+1, endd, indx, length, target);

//    update(left, beg, mid, start,  mid-start+1);
//    update(right, mid+1, endd,  mid+1,  start+ rem -1 -mid);

}


int main()
{
    int n,m;

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);


    build(1,1,n);

    update(1,1,n, y, y+k-1, x,k);

    return 0;
}
