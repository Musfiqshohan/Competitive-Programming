#include<bits/stdc++.h>
using namespace std;

int tree[4*100000];
void init(int node, int beg, int endd)
{
    if(beg==endd)
    {
        tree[node]=a[beg];
        return ;
    }


    int left=node*2;
    int right=node*2+1;

    int mid=(beg+endd)/2;

    init(left, beg, mid);
    init(right, mid+1, endd);

}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);

    for(i=1;i<=n;i++) scanf("%d",&a[i]);

    init(1,1,n);

    return 0;
}
