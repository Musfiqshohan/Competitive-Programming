#include<bits/stdc++.h>
using namespace std;

int a[120000];

struct data
{
    int mx1,mx2;
};
data tree[120000*4+10];

data merg(data a, data b)
{
    int d[5];
    d[0]=a.mx1;
    d[1]=a.mx2;
    d[2]=b.mx1;
    d[3]=b.mx2;

    sort(d,d+4);


    data ret;
    ret.mx1=d[3];
    ret.mx2=d[2];

    return ret;

}
void init(int node, int beg, int endd)
{
    if(beg==endd)
    {
        tree[node].mx1= a[beg];
        tree[node].mx2=0 ;
        return;
    }

    int left= node*2;
    int right= node*2 +1;

    int mid=(beg+endd)/2;

    init(left,beg, mid);
    init(right, mid+1, endd);

    tree[node]= merg(tree[left], tree[right]);

}

void update(int node, int beg, int endd, int i, int val)
{
    if(beg==i && endd==i)
    {
        tree[node].mx1=val;
        tree[node].mx2=0;
        return;
    }

    int left= node*2;
    int right= node*2 +1;

    int mid=(beg+endd)/2;

    if(i<=mid)
    update(left,beg,mid,i,val);
    else
    update(right,mid+1, endd, i, val);

    tree[node]= merg(tree[left], tree[right]);

}

data query(int node, int beg, int endd, int i, int j)
{
    if(i>j) return {INT_MIN, INT_MIN};

    if(beg==i && endd==j)
    {
        return tree[node];
    }

    int left= node*2;
    int right= node*2 +1;

    int mid=(beg+endd)/2;

    data l= query(left,beg,mid, i,  min(mid,j));
    data r= query(right, mid+1, endd, max(mid+1,i), j);

    data ret= merg(l,r);
    return ret;

}
int main()
{
    int n,i,x,y;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);

    init(1,1,n);

    int q;
    scanf("%d",&q);
    getchar();
    for(i=0; i<q; i++)
    {

        char task;
        scanf("%c",&task);


        if(task=='Q')
        {

            scanf("%d %d",&x,&y);
            data temp= query(1,1,n,x,y);

            cout<<temp.mx1+temp.mx2<<endl;

        }
        else
        {
            scanf("%d %d",&x,&y);
            update(1,1,n,x,y);
        }
        getchar();


    }
    return 0;
}
