#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

struct info{

    int lights, prop;

}tree[4*100009];

void push_down(int node, int beg, int endd)
{
    int left= node*2;
    int right= node*2+1;

    int mid=(beg+endd)/2;

    tree[left].prop^=tree[node].prop;
    tree[right].prop^=tree[node].prop;

    tree[left].lights=  (tree[node].prop==1)?  (mid-beg+1)-tree[left].lights : tree[left].lights;
    tree[right].lights=  (tree[node].prop==1)?  (endd-mid)-tree[right].lights : tree[right].lights;

    tree[node].prop=0;

}


void update(int node, int beg, int endd , int i, int j)
{
    if(beg>j || endd<i) return;

    if(beg>=i && endd<=j)
    {
        tree[node].prop^=1;
        tree[node].lights= (endd-beg+1) -tree[node].lights ;

        return;
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    push_down(node,beg,endd);

    update(left, beg, mid, i,j);
    update(right, mid+1, endd, i, j);

    tree[node].lights= tree[left].lights + tree[right].lights;

}

int query(int node, int beg, int endd, int i , int j)
{
    if(beg>j || endd<i) return 0;

    if(beg>=i && endd<=j)
    {

        return tree[node].lights;
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    push_down(node,beg,endd);

    int t1= query(left, beg, mid, i, j);
    int t2= query(right, mid+1, endd, i, j);

    return t1+t2;

}


int main()
{
    int n,m,cs,x,y;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&cs,&x,&y);

        if(cs==0)
        {
            update(1,1,n, x,y);
        }
        else
        {
            printf("%d\n",query(1,1,n, x,y));

        }

    }

    return 0;
}
