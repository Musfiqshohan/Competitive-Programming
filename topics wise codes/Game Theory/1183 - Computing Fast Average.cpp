#include<bits/stdc++.h>
using namespace std;


int tree[4*100009], propflag[4*100009];

void propagate(int node,int beg, int endd)
{
    int left=node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    propflag[left]=propflag[node];
    tree[left]=propflag[node]*(mid-beg+1);


    propflag[right]= propflag[node];
    tree[right]= propflag[node]*(endd-mid);

    propflag[node]=-1;

}
void update(int node, int beg, int endd, int i , int j, int val)
{
    if(i>j) return;
    if(beg==i && endd==j)
    {
        propflag[node]=val;

        tree[node]=   val*(endd-beg+1);

        return;
    }



    int left=node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    if(propflag[node]>-1)
    {
        propagate(node,beg,endd);
    }

    update(left, beg,mid , i , min(mid,j) ,val);
    update(right, mid+1, endd, max(mid+1,i) , j  ,val );


    tree[node]=tree[left]+tree[right];
}

int query(int node, int beg, int endd, int i, int j)
{
    if(i>j)
        return 0;

    if(beg==i && endd==j)
    {
        return tree[node];
    }


    int left=node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    if(propflag[node]>-1)
    {

        propagate(node,beg,endd);
    }


    int l=query(left, beg,mid , i , min(mid,j));
    int r=query(right, mid+1, endd, max(mid+1,i) , j  );


    return l+r;


}

void print(int a, int b)
{
    int x= __gcd(a,b);
    a=a/x;
    b=b/x;

    printf("%d",a);
    if(b>1) printf("/%d",b);

    puts("");
}

int main()
{
    int t=0,test;
    scanf("%d",&test);

    while(t<test){

    memset(tree,0,sizeof tree);
    memset(propflag, -1 , sizeof propflag);
    printf("Case %d:\n",++t);

    int n,q,i,x,y,opt,val;
    scanf("%d %d",&n,&q);

    for(i=0;i<q;i++)
    {
        scanf("%d",&opt);

        if(opt==1){
        scanf("%d %d %d",&x,&y,&val);

        update(1,0,n-1,x,y,val);
        }
        else
        {
            scanf("%d %d",&x,&y);

            print(query(1,0,n-1,x,y), y-x+1);

        }
    }


    }

    return 0;

}
