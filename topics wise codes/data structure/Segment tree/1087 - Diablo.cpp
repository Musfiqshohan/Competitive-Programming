#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pr pair<int, int>
using namespace std;

struct info{

    int sum,id;
}tree[600209];


void update(int node, int beg, int endd, int indx, int id)
{
    //printf("%d %d %d\n",beg,endd,indx);
    if(beg==indx && endd== indx)
    {
        //printf("%d %d %d\n",beg,endd,indx);
        tree[node].sum=1;
        tree[node].id=id;

        return ;
    }


    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    if(indx<=mid)
        update(left, beg, mid, indx, id);
    else
        update(right, mid+1,endd, indx, id);

    tree[node].sum= tree[left].sum+tree[right].sum;

}

int query(int node, int beg, int endd, int target)
{
   // printf("%d %d %d\n",beg,endd,target);

    //tree[node].sum--;
    if(beg==endd)
    {

        tree[node].sum=0;
        return tree[node].id;
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    int res=0;
    if(tree[left].sum>=target)
    {
        res=query(left, beg, mid, target);
    }
    else
    {
        res= query(right,mid+1,endd, target-tree[left].sum);
    }

    tree[node].sum= tree[left].sum + tree[right].sum;

    return res;


}




int main()
{

    int t=0,test;
    cin>>test;

    while(t<test){

    printf("Case %d:\n",++t);
    int n,q,id,pos;




    scanf("%d %d",&n,&q);

    int lim=n+q;



    for(int i=1;i<=n;i++)
    {
        scanf("%d",&id);

        update(1,1,lim,i,id);

    }

    getchar();
    for(int i=0;i<q;i++)
    {
        char ch;
        scanf("%c",&ch);
        if(ch=='a')
        {
            scanf("%d",&id);
            update(1,1,lim, ++n, id );
        }
        else
        {
            scanf("%d",&pos);
            if(pos>tree[1].sum) printf("none\n");
            else printf("%d\n",query(1,1,lim,pos));
        }
        getchar();
    }


    ms(tree,0);

    }

    return 0;
}
