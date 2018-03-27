#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;
struct info
{
    int sum, prop;
} tree[4*1024000];
string str;
void push_down(int node,int beg, int endd)
{
    int left=node*2;
    int right=node*2+1;
    int mid= (beg+endd)/2;
    if(tree[node].prop!=-1)
    {
        if(tree[node].prop==0)
        {
            tree[left].prop= tree[node].prop;
            tree[right].prop= tree[node].prop;
            tree[left].sum=0;
            tree[right].sum=0;
        }
        else if(tree[node].prop==1)
        {
            tree[left].prop= tree[node].prop;
            tree[right].prop= tree[node].prop;
            tree[left].sum=mid-beg+1;
            tree[right].sum= endd-mid;
        }
        else if(tree[node].prop==2)
        {
            if(tree[left].prop==1) tree[left].prop=0; else if(tree[left].prop==0) tree[left].prop=1;  else if( tree[left].prop==2)  tree[left].prop=-1; else tree[left].prop=2  ;
            if(tree[right].prop==1) tree[right].prop=0; else if(tree[right].prop==0) tree[right].prop=1;  else if(tree[right].prop==2) tree[right].prop=-1; else tree[right].prop=2;
            tree[left].sum= (mid-beg+1) - tree[left].sum;
            tree[right].sum= (endd-mid) -tree[right].sum;
        }
        tree[node].prop=-1;
    }
}
void update(int node, int beg, int endd, int i, int j, int turn)
{
    if(beg>j || endd<i) return;
    if(beg>=i && endd<=j)
    {
        if(turn==1)
        {
            tree[node].prop=1;
            tree[node].sum=endd-beg+1;
        }
        else if(turn==0)
        {
            tree[node].prop=0;
            tree[node].sum=0;
        }
        else
        {
            if(tree[node].prop==1) tree[node].prop=0;
            else if(tree[node].prop==0) tree[node].prop=1;
            else if(tree[node].prop==2) tree[node].prop=-1;
            else tree[node].prop=2;
            tree[node].sum=(endd-beg+1)- tree[node].sum;
        }
        return;
    }

    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    push_down(node, beg,endd);

    update(left, beg, mid, i, j, turn);
    update(right, mid+1, endd, i, j, turn);

    tree[node].sum= tree[left].sum + tree[right].sum;

}

int query(int node, int beg, int endd, int i, int j)
{

    if(beg>j || endd<i) return 0;

    if(beg>=i && endd<=j) return tree[node].sum;

    int left=node*2;
    int right=node*2+1;
    int mid= (beg+endd)/2;
    push_down(node, beg,endd);
    int t1= query(left, beg, mid, i, j);
    int t2= query(right, mid+1, endd, i, j);
    tree[node].sum= tree[left].sum + tree[right].sum;
    return t1+t2;

}

void build(int node, int beg, int endd)
{
    if(beg==endd)
    {
        tree[node].sum= str[beg]=='1'?  1:0;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid= (beg+endd)/2;

    build(left,beg,mid);
    build(right, mid+1, endd);
    tree[node].sum= tree[left].sum + tree[right].sum;
}
int main()
{
    int cs=0,cases;
    cin>>cases;
    while(cs<cases){
   printf("Case %d:\n",++cs);

    int m;
    scanf("%d",&m);

    string temp;
    for(int i=0; i<m; i++)
    {
        int x;
        scanf("%d",&x);
        getchar();
        cin>>temp;

        for(int j=0; j<x; j++)
            str+=temp;
    }

    int n=str.length(), T;
    for(int i=0; i<=4*n+5; i++) tree[i].prop=-1;
    build(1,0,n-1);

    scanf("%d",&T);
    getchar();
    int t=0;
    while(T--)
    {
        int x,y;
        char ch;
        scanf("%c %d %d",&ch, &x,&y);
        getchar();

        if(ch=='F')
        {
            update(1,0,n-1, x,y, 1);
        }
        else if(ch=='E')
            update(1,0,n-1, x,y,0);
        else if(ch=='I')
            update(1, 0,n-1, x,y, 2);
        else
        {
            printf("Q%d: %d\n", ++t, query(1,0,n-1,x,y) );
        }
    }
    ms(tree,0);
    str.clear();
     }
    return 0;
}
