#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

int ara[109][109];

int main()
{

//    in("10048I.txt");
//    out("10048O.txt");
    int test=0;
    while(1)
    {


        int C,S,Q,u,v,w;
        scanf("%d %d %d",&C,&S,&Q);

        if(C==0 && S==0 && Q==0)
            break;

        if(test) puts("");
        test++;
        for(int i=1; i<=C; i++)
            for(int j=1; j<=C; j++)
                ara[i][j]=100000000;

        for(int i=0; i<S; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            ara[u][v]=w;
            ara[v][u]=w;
        }

        for(int k=1; k<=C; k++)
            for(int i=1; i<=C; i++)
                for(int j=1; j<=C; j++)
                {
                    if( max(ara[i][k],ara[k][j])  < ara[i][j]  && max(ara[i][k],ara[k][j]) !=100000000 )
                    {
                        ara[i][j]= max(ara[i][k],ara[k][j]);
                    }
                }

        printf("Case #%d\n",test);
        for(int i=0; i<Q; i++)
        {
            scanf("%d %d",&u,&v);
            if(ara[u][v]==100000000) printf("no path\n");
            else
            printf("%d\n",ara[u][v]);
        }
      //  puts("End");

        ms(ara,0);
    }

   // puts("last");

    return 0;
}
