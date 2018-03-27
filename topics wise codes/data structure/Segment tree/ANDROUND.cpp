///http://www.spoj.com/problems/ANDROUND/en/
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;


int tree[20009*4], ara[20009];

void build(int node, int b, int e)
{
    //printf("%d %d %d\n",node, b,e);
    if(b==e)
    {
        tree[node]=ara[b];
        //printf("node= %d  val=%d\n",node, tree[node]);
        return;
    }

    int mid=(b+e)/2;

    int left=node*2;
    int right=node*2+1;

    build(left,b,mid);
    build(right, mid+1,e);
    tree[node]=tree[left] & tree[right];

}


int query(int node,  int b, int e, int i, int  j)
{
    static int cnt=0;

    //if(++cnt>12) return 0;
    //printf("%d %d %d %d %d\n",node, b,e,i,j);
    if(i>e || j<b )
        return (1<<31) -1;

    if(b>=i && e<=j)
    {
       // printf("node=%d  leaf= %d\n",node, tree[node]);
        return tree[node];

    }

    int mid = (b+e)/2;

    int l= node*2;
    int r= node*2+1;


    int t1=-1,t2=-1;
    // if(mid>=b)
    t1= query(l, b, mid, i, j);

    // if(mid+1<=e)
    t2= query(r, mid+1, e, i,j );

//    int res=0;
//    if(t1!=-1) res=t1;
//    if(t2!=-1) res&=t2;
//    printf("ret= %d\n",res);
//    return res;

 //   printf("t1= %d t2= %d res= %d\n",t1,t2, t1&t2);

    return t1&t2;

}


int main()
{
    int tt=0;
    cin>>tt;

    while(tt--)
    {
        int n,k;
        scanf("%d %d",&n,&k);

        for(int i=1; i<= n; i++)
        {
            scanf("%d",&ara[i]);
        }


        build(1,1,n);

        //return 0;

        if(k>=n/2)
        {
            int sum=ara[1];
            for(int i=2; i<=n; i++) sum&=ara[i];

            for(int i=1; i<=n; i++)
            {
                if(i>1) printf(" ");
                printf("%d",sum);
            }
            puts("");
        }
        else
        {
            vector<int>vec;
            for(int i=1; i<=n; i++)
            {

                int sum=0,r1,r2;
                if(i-k<=0)
                {
                    r1= query(1,1,n,1,i);
                    r2= query(1,1,n,n-(k-i), n);

                    sum=r1&r2;
                }
                else
                {
                    //printf("hi %d\n",i);
                    sum=query(1,1,n, i-k, i);


                }

                if(i+k >n)
                {
                    if(i+1<=n)
                        r1= query(1,1,n, i+1,n);

                    int rem= k-(n-i);
                    r2=query(1,1,n, 1, rem );

                    sum=sum&r1&r2;
                }
                else
                    sum&=query(1,1,n,i+1,i+k);

                vec.push_back(sum);
            }

            for(int i=0; i<vec.size(); i++)
            {
                if(i) printf(" ");
                printf("%d",vec[i]);
            }
            puts("");


            ms(tree,0);
            ms(ara,0);
        }


    }

    return 0;
}
