#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pr pair<int, int>
using namespace std;

int par[300009],nextt[300009];
int n;

int getNext(int r)
{
    //printf("%d %d\n",nextt[r],r);
    if(nextt[r]==r) return r;

    return nextt[r]= getNext(nextt[r]);
}


void f(int l, int r, int x)
{
    int cur= getNext(l);

    while(cur<=r)
    {
        if(cur==x)
        {
            cur++;
        }
        else
        {
            par[cur]=x;
            nextt[cur]=cur+1;

        }

        //if(cur<=n)
        cur=getNext(cur);
    }
}
int main()
{

    int m,x,y,z;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n+1;i++) nextt[i]=i;

    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        f(x,y,z);
    }

    for(int i=1;i<=n;i++) printf("%d ",par[i]);
    puts("");

    return 0;
}
