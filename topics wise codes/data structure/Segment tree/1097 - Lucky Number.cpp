#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;
int mx=1429500;

int tree[4*1429500],res[100009];
void build(int node, int beg, int endd)
{
    if(beg==endd)
    {
        tree[node]= beg & 1;
        return;
    }

    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    build(left, beg,mid);
    build(right, mid+1, endd);

    tree[node]= tree[left]+ tree[right];

    //printf("%d %d %d %d\n",node, beg, endd, tree[node]);

}

void update(int node, int beg,int endd, int nth)
{
  //  printf("%d %d %d %d %d\n",node, beg, endd, tree[node] ,nth);
    if(beg==endd)
    {
       // printf(" deleted =%d\n",beg);
        tree[node]=0;
        return;
    }

    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    if(tree[left]>=nth)
        update(left, beg, mid, nth);
    else update(right, mid+1, endd, nth-tree[left]);

    tree[node]=tree[left]+tree[right];

}

int query(int node , int beg, int endd, int nth)
{
   // printf("%d %d %d %d %d\n",node, beg, endd, tree[node], nth);
    if(beg==endd)
    {
        return beg;
    }

    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;
    int t;

    if(tree[left]>=nth)
        t= query(left, beg, mid, nth);
    else t= query(right, mid+1, endd, nth-tree[left]);

}

int main()
{

    build(1,1,mx);



    res[1]=1;
    for(int i=2;i<=100009;i++)
    {
        res[i]= query(1,1,mx,i);
      //  printf("res=%d\n",res[i]);
        int last= (mx/res[i])*res[i];
        for(int j=last; j>=res[i];j-=res[i])
            {
                //printf(" ith=%d %d ",res[i],j);
                update(1,1,mx, j);
              //  puts("");

            }
    }

    sort(res+1,res+100009);

    int t=0,test,n;
    cin>>test;

    while(t<test)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",++t,res[n]);
    }

    return 0;
}
