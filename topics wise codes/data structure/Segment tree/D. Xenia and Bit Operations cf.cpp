#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;
int mx;
int tree[4*140000];

int pow1(int x,int n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        int res=pow1(x,n/2);
        return res*res;
    }
    return x* pow1(x,n-1);
}

int f(int n)
{
    int cnt=0;
    while(n)
    {
        n/=2;
        cnt++;
    }
    return cnt;
}
void update(int node, int beg, int endd, int indx, int val)
{
    if(beg==indx && endd==indx)
    {
        tree[node]=val;
        return ;
    }

    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;

    if(indx<=mid)
        update(left,beg, mid, indx, val);
    else update(right, mid+1, endd, indx, val);

    if(f(endd-beg+1)%2==0) tree[node]= tree[left] | tree[right];
    else tree[node]= tree[left] ^ tree[right];
    //printf("%d %d %d\n",beg,endd, tree[node]);
}

int main()
{
    int n,m,x,val;
    scanf("%d %d",&n,&m);
    n=pow1(2,n);
    mx=n;

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        update(1,1,n,i,x);
    }

    // printf("%d\n",tree[1]);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&val);
        update(1,1,n,x,val);
        printf("%d\n",tree[1]);
    }

    return 0;
}
