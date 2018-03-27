///https://vjudge.net/contest/149388#problem/C
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
const int MAXN =100009;

int tree[MAXN*4],waste[MAXN];

void build(int nd, int b, int e, int k)
{
    //printf("%d %d %d %d\n",nd, b,e,k);
    if(b==e)
    {
        tree[nd]=k;
        waste[b]=k;
        return;
    }

    int mid= (b+e)/2;

    int lc=nd*2;
    int rc=(nd*2)+1;

    build(lc,b,mid,k);
    build(rc,mid+1,e,k);

    tree[nd]=max(tree[lc],tree[rc]);
}


void update(int nd, int b, int e, int v)
{


    if(b==e)
    {
        tree[nd]-=v;
        waste[b]-=v;

       // printf("->%d %d at %d\n",tree[nd], waste[b],b);
        return ;
    }


    int mid= (b+e)/2;

    int lc=nd*2;
    int rc=(nd*2)+1;


    // printf("%d %d , %d %d\n",b,e,tree[lc], tree[rc]);


    if(v<=tree[lc])
        update(lc,b,mid,v);
    else
        update(rc,mid+1,e,v);

//    if((v<=tree[lc] && tree[lc]<=tree[rc]) ||(v<=tree[lc] && v>=tree[rc]))
//        update(lc,b,mid,v);
//    else update(rc,mid+1,e,v);


    tree[nd]=max(tree[lc],tree[rc]);

}



int  main()
{

    int T;
    scanf("%d",&T);

    while(T--)
    {
        int n,k;
        scanf("%d",&k);


        build(1,1,MAXN,k);

        scanf("%d",&n);


        int r,v;
        for(int i=0; i<n; i++)
        {
            string str;
            getchar();
            cin>>str;


            if(str[0]=='b')
            {
                scanf("%d %d",&r,&v);

                // cout<<r<<" "<<v<<endl;
//
                while(r--)
                {
                    i++;
                    update(1,1,MAXN,v);
                }
                i--;

            }
            else
            {
                stringstream geek(str);
                geek>>v;

                update(1,1,MAXN, v);
            }

        }

        puts("");
        int cnt=0,totwst=0;
        for(int i=1; i<=MAXN; i++)
        {
            if(waste[i]!=k)
            {
                totwst+=waste[i],cnt++;
               // printf("%d ",waste[i]);
            }

        }
       // puts("");

        printf("%d %d\n",cnt,totwst);

        ms(tree,0);
        ms(waste,0);

    }
}


/*
1
709 27
393
689
538
557
194
145
693
154
312
541
607
429
671
65
594
486
632
24
686
551
43
674
389
196
115
179
473

*/
