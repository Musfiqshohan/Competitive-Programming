#include<bits/stdc++.h>
using namespace std;
struct data
{
    int  propflag=0;
    int a[3];
};
data tree[4*100009];

data merger(data x, data y)
{
    data xtra;
    xtra.propflag=0;
    xtra.a[0]=x.a[0]+y.a[0];
    xtra.a[1]=x.a[1]+ y.a[1];
    xtra.a[2]= x.a[2]+y.a[2];
    return xtra;
}

void init(int node,  int  beg, int endd)
{
    if(beg==endd)
    {
        tree[node].a[0]=1;
        return ;
    }
    int left= node*2;
    int right= node*2+1;
    int mid= (beg+endd)/2;
    init(left, beg, mid);
    init(right, mid+1, endd);
    tree[node] = merger(tree[left], tree[right]);
}

void change(int node, int times)
{
    if(times%3==1)
    {
        swap(tree[node].a[0],tree[node].a[2]);
        swap(tree[node].a[1], tree[node].a[2]);
    }
    else if(times%3==2)
    {
        swap(tree[node].a[0],tree[node].a[1]);
        swap(tree[node].a[1],tree[node].a[2]);
    }
}
void propagate(int node)
{
    int left= node*2;
    int right= node*2+1;

    change(left, tree[node].propflag );
    tree[left].propflag+=tree[node].propflag;

    change(right, tree[node].propflag );
    tree[right].propflag+=tree[node].propflag;

    tree[node].propflag=0;
}

void update(int node, int beg, int endd, int i, int j)
{
    if(i>j) return;

    if(beg==i && endd ==j)
    {
        tree[node].propflag++;
        change(node,1);
        return ;
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    if(tree[node].propflag) propagate(node);

    update(left, beg,mid, i, min(mid,j) );
    update(right, mid+1, endd,  max(i,mid+1), j);

    tree[node].a[0]= tree[left].a[0]+ tree[right].a[0];
    tree[node].a[1]= tree[left].a[1]+ tree[right].a[1];
    tree[node].a[2]= tree[left].a[2]+ tree[right].a[2];

}

data query(int node, int beg, int endd,int i, int j)
{
    if(i>j)
    {
        data temp;
        temp.a[0]=temp.a[1]= temp.a[2]=0;
        return temp;
    }
    if(beg==i && endd ==j)
    {
        return tree[node];
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;


    if(tree[node].propflag)
    {
        propagate(node);
    }

    data l= query(left, beg, mid,  i, min(mid,j));
    data r= query(right, mid+1, endd,  max(mid+1,i), j);

    return merger(l,r);

}

int main()
{
    int t=0,test;
    cin>>test;

    while(t<test)
    {
        memset(tree, 0, sizeof tree);

        printf("Case %d:\n",++t);
        int n,q,i,cs,x,y;
        scanf("%d %d",&n,&q);
        init(1,1,n);

        for(i=0; i<q; i++)
        {
            scanf("%d %d %d",&cs,&x,&y);

            if(cs==0)
            {
                update(1,1,n,x+1,y+1);
            }
            else
            {
                data temp=query(1,1,n,x+1,y+1);

                printf("%d\n",temp.a[0]);

            }


        }
    }


    return 0;
}




