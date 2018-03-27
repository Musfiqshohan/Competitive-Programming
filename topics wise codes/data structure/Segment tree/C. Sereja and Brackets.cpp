#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;
string str;

struct info
{
    int unleft, unright, matched;
}tree[4*1000009];

info merged(info l, info r)
{
    info temp;


    int mn= min( l.unleft,  r.unright);
    temp.matched= mn + l.matched+ r.matched;

    temp.unleft= r.unleft + l.unleft - mn;
    temp.unright= l.unright+ r.unright - mn;

   // printf("%d %d  -> match=%d  ul=%d  ur=%d\n",beg,endd, tree[node].matched, tree[node].unleft, tree[node].unright);

   return temp;
}

void build(int node,int beg, int endd)
{

    if(beg==endd)
    {
        if(str[beg]=='(')
            tree[node].unleft=1;
        else tree[node].unright=1;

        //printf("%d %d %d\n",beg,  tree[node].unleft , tree[node].unright);

        return;
    }

    int left= node*2;
    int right= node*2+1;

    int mid=(beg+endd)/2;

    build(left, beg, mid);
    build(right, mid+1, endd);

    tree[node]=merged( tree[left], tree[right]);
}


info query(int node, int beg, int endd, int i, int j)
{
    if(beg>j || endd<i) return {0,0,0};

    if(beg>=i && endd<=j)
        return { tree[node].unleft, tree[node].unright, tree[node].matched };

    int left= node*2;
    int right= node*2+1;

    int mid=(beg+endd)/2;

    info t1= query(left, beg, mid , i,j);
    info t2= query(right, mid+1, endd,  i, j);

    return merged(t1,t2);

}

int main()
{

    cin>>str;
    int n=str.length();
    int m,x,y;

    build(1, 0, n-1);

   // cout<<query( 1, 0, n-1, 8-1 ,12-1).matched*2<<endl;
    //cout<<tree[1].matched<<endl;


    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        cout<<query( 1, 0, n-1, x-1,y-1).matched*2<<endl;
    }


}
