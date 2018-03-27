#include<bits/stdc++.h>
using namespace std;

int a[200000],tree[800000];
void init(int node, int beg, int endd)
{
    if(beg==endd)
    {
        tree[node]=a[beg];
        return;
    }

    int left= node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    init(left,beg,mid);
    init(right,mid+1,endd);

    tree[node]= min(tree[left] , tree[right]);

}
int query(int node, int beg, int endd, int i, int j)
{
    if(i>j) return INT_MAX;

    if(beg==i && endd==j)
        return tree[node];

    int left= node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;
    int l= query(left,beg,mid,i, min(j,mid));
    int r= query(right,mid+1,endd,max(i, mid+1),j);

    return min(l,r);
}

int main()
{
    int t=0,test;
    scanf("%d",&test);
    while(t<test){

    printf("Case %d:\n",++t);
    int n,q,x,y,i;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    init(1,1,n);



    for(i=0;i<q;i++)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n", query(1,1,n,x,y));
    }

    }
    return 0;
}
