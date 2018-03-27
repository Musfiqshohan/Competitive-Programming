#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;
ll tree[3*4*200009];
void update(ll node ,ll beg, ll endd, ll indx, ll val)
{
    if(beg==indx && endd==indx)
    {
        tree[node]=val;

        return;
    }
    ll left=node*2;
    ll right=node*2+1;

    ll mid= (beg+endd)/2;

    if(indx<=mid) update(left,beg, mid, indx, val);
    else update(right,mid+1, endd, indx,val);

    tree[node] = min(tree[left], tree[right]);

}

int main()
{
    for(ll i=1;i<=3*4*200009;i++) tree[i]=INT_MAX;


    ll n,num,cnt=0;
    scanf("%lld",&n);
    getchar();
    string str;

    ll flag=0,keep=0;
    for(ll i=1;i<=2*n;i++)
    {
        cin>>str;


        if(str=="add")
        {
            scanf("%lld",&num);
            getchar();

            if(num>tree[1])  { keep=0; flag=1;  }
            else if(flag==1)  keep++;

            update(1,1,n,num,num);

           //printf("ans= %d\n",tree[1]);

        }
        else
        {
            if(flag==1 && keep==0) { cnt++; keep=0; flag=0; }
            update(1,1,n, tree[1], INT_MAX );
            keep--;
        }
    }

    cout<<cnt<<endl;
}
