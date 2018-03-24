#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

struct tripple
{
    int first,second, indx, num;
}ara[100009];
int n,u;
int srch(int low, int high, int targ)
{
    int mid,cnt=0;
    while(cnt++<=10)
    {
        mid= low + (high-low)/2;
         //printf("%d %d %d\n",mid, ara[mid].first , targ);

        if(ara[mid].first<=targ)
            low=mid;
        else
            high=mid-1;
    }

    if(ara[mid+1].first<=targ && mid+1<=n) return mid+1;
    if(ara[mid].first>targ) return mid-1;
    return mid;

}

int tree[4*100009];
void update(int node, int beg ,int endd, int indx, int val)
{
    //printf("%d %d %d %d\n",node,beg,endd,indx);
    if(beg==indx && endd ==indx)
    {
        tree[node]=val;
       // printf("%d %d %d\n",beg, node, tree[node]);
       //puts("");
        return ;
    }
    int left=node*2;
    int right=node*2+1;

    int mid=(beg+endd)/2;

    if(indx<=mid)
        update(left,beg,mid, indx, val);
    else
        update(right,mid+1,endd,indx,val);

    tree[node]=max(tree[left], tree[right]);
}

int query(int node, int beg, int endd, int i, int j)
{
    //printf("%d %d %d %d %d\n",node,beg,endd,i,j);
    if(beg>j || endd<i) return 0;

    if(beg>=i && endd<=j)
    {
        //printf("%d %d %d\n",beg,endd,tree[node]);
        return tree[node];
    }

    int left=node*2;
    int right=node*2+1;

    int mid=(beg+endd)/2;

    int l= query(left,beg, mid, i, j);
    int r= query(right,mid+1,endd, i, j);

    return max(l,r);


}

bool compare1(tripple a, tripple b)
{
    return a.first<b.first;
}
bool compare2(tripple a, tripple b)
{
    return a.indx<b.indx;
}
int main()
{

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&ara[i].first, &ara[i].second);
        ara[i].indx=i;

    }

    sort(ara+1,ara+n+1, compare1);

    for(int i=1;i<=n;i++)
    {
        update(1,1,n, i, ara[i].first+ara[i].second-1);
    }


    int total=0;

    for(int i=n;i>=1;i--)
    {
        int dis= ara[i].first+ara[i].second-1;
        int indx= srch(i,n,dis);

        int h=query(1,1,n,i,indx);

       // printf("%d %d %d\n",dis, indx, h);
        int indx2= srch(i,n, h);

        total= indx2-i+1;

       // printf("%d\n",total);
        ara[i].num=total;
    }

     sort(ara+1,ara+n+1, compare2);

    for(int i=1;i<=n;i++) printf("%d ",ara[i].num);
    puts("");
    return 0;
}
