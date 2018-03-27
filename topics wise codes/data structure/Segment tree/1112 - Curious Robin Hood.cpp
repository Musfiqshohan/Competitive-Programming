#include<bits/stdc++.h>
using namespace std;

const int MAX=150100;
int n,a[MAX];
int tree[4*MAX];

void init(int node, int beg, int endd)
{
    if(beg==endd)
    {
        tree[node]=a[beg];
        return ;
    }


    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    init(left,beg,mid);
    init(right,mid+1,endd);

    tree[node]=tree[left]+ tree[right];
}

///beg,endd tree range
///x,y query range
int query(int node, int beg , int endd, int x , int y)
{
    if(x>y) return 0;
    if(beg==x && endd==y) return tree[node];

    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    int l= query(left,beg,mid, x, min(mid,y));
    int r= query(right, mid+1, endd,  max(mid+1,x),y);

    return l+r;
}

int  update(int node, int beg, int endd, int x, int val,int flag)
{

    int t=0;
    if(beg==x &&endd==x){
        if(flag==0){
            int temp=tree[node];

            tree[node]=0;
            return temp;
        }
        else{

        tree[node]+=val;

        return tree[node];

        }

    }

    int left=node*2;
    int right=node*2+1;

   int mid= (beg+endd)/2;

    if(x<=mid) t=update(left, beg, mid, x, val,flag);
    else t=update(right, mid+1, endd, x , val,flag);

    tree[node]=tree[left]+tree[right];


    return t;

}
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){

    printf("Case %d:\n",t+1);
    int q,i,task,x,y;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++) scanf("%d",&a[i]);

    init(1,0,n-1);


    for(i=0;i<q;i++)
    {

        scanf("%d",&task);
      //  printf("Query no %d\n",i);
        if(task==1)
        {
            scanf("%d",&x);
            printf("%d\n",update(1,0,n-1,x,0,0));
        }
        else if(task==2)
        {
            scanf("%d %d",&x,&y);
            x=update(1,0,n-1,x,y,1);
        }
        else if(task==3)
        {
           scanf("%d %d",&x,&y);
           printf("%d\n",query(1,0,n-1,x,y));
        }
    }

    }



    return 0;
}
