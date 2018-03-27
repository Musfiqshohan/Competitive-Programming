#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

pair<int, int>p[200009];
vector<int>vec;
map<int,int>mp;
int ara[200009];
int tree[200009*4];

void clearr()
{
    mp.clear();
    vec.clear();
    ms(tree,0);
    ms(ara,0);
    ms(p,0);
}
void push_down(int node)
{
    int left= node*2;
    int right= node*2+1;

    if(tree[node]!=0){
    tree[left]=tree[node];
    tree[right]=tree[node];
    }

    tree[node]=0;
}

void update(int node, int beg, int endd, int i, int j, int post)
{

    if(beg>j || endd<i)
        return;

    if(beg>=i && endd<=j)
    {  // printf("beg=%d  endd=%d -> %d\n",beg,endd, post);
        tree[node]=post;
        return ;
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    push_down(node);

    update(left, beg, mid, i, j, post);
    update(right, mid+1,endd, i, j, post);
}

int query(int node, int beg, int endd, int indx)
{

    if(beg==indx && endd==indx)
    {
       // printf("indx=%d-> pos=%d\n",indx,tree[node]);
        return tree[node];
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    push_down(node);

    int t;
    if(indx<=mid)
        t= query(left, beg, mid, indx);
    else
        t=query(right,mid+1, endd, indx);

    return t;

}


int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){
    int n,total=0;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d %d",&p[i].first, &p[i].second);
        vec.push_back(p[i].first);
        vec.push_back(p[i].second);
    }

    sort(vec.begin(), vec.end());

    int cnt=1;
    for(int i=0;i<vec.size();i++)
    {
        if(mp.find(vec[i])==mp.end())  // not till now
        {
            mp[vec[i]]=cnt++;
        }
    }


    for(int i=1;i<=n;i++)
    {
        int x= mp[p[i].first];
        int y= mp[p[i].second];

       // printf("->%d %d\n",x,y);
        update(1, 1, cnt-1, x,y , i);
    }



    for(int i=1;i<cnt;i++)
    {
        int num= query(1,1,cnt-1, i);
        if(ara[num]==0) {total++; ara[num]=1; }
    }


   // for(int i=1;i<=30;i++) printf("%d ",tree[i]);

    printf("Case %d: %d\n",++t,total);

    clearr();

    }

    return 0;
}
