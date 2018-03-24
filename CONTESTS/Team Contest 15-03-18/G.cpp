#include<bits/stdc++.h>
#define i64 long long
using namespace std;

i64 ara[1009][1009], cum[1009][1009];
int main()
{
    while(1)
    {
        i64 n,m;
        cin>>n>>m;

        for(i64 i=0; i<n; i++)
        {
            for(i64 j=1; j<=m; j++)
            {
                scanf("%lld",&ara[i][j]);

                if(i==0)
                    cum[0][j]=cum[0][j-1]+ara[i][j];
            }
        }


        printf("%lld",cum[0][m]);

        for(i64 i=1; i<n; i++)
        {
            i64 pre=2,now=1;
            i64 tot=ara[i-1][1];
//        cout<<tot<<endl;
//        cout<<ara[i-1][2]<<endl;
            i64 cnt=0;
            while(pre<=m && cnt++<20)
            {
                //printf("pre=%lld preV=%lld now=%lld  nowV=%lld\n",pre, ara[i-1][pre], now, ara[i][now]);
                if(ara[i][now]!=0 && ara[i-1][pre]!=0)
                {
                    i64 mn=min(ara[i][now], ara[i-1][pre]);

                    ara[i-1][pre]-=mn;
                    // printf("v1=%lld pre=%lld\n",ara[i-1][pre], pre);
                    if(ara[i-1][pre]==0) pre++;
                    // printf("v2=%lld pre=%lld\n",ara[i-1][pre], pre);

                    ara[i][now]-=mn;
                    tot+=mn;

                    // printf("mn= %lld\n",mn);

                    // printf("after:  %lld %lld\n",ara[])

                    if(ara[i][now]==0)
                    {
                        //   printf("now= %lld\n",now);
                        if(pre==now+1)
                        {
                            tot+=ara[i-1][pre];
                            pre++;
                        }
                        cum[i][now]=tot;
                        ara[i][now]=cum[i][now]-cum[i][now-1];
                        now++;
                    }
                }

            }

            while(now<=m)
            {
                tot+=ara[i][now];
                cum[i][now]=tot;
                ara[i][now]=cum[i][now]-cum[i][now-1];
                now++;
            }
//
//            for(int j=1; j<=m; j++)
//                printf("%lld ",ara[i][j]);
//            puts("");
            //printf("1st= %lld\n",ara[i][1]);

            if(i<n) printf(" ");
            printf("%lld",tot);
        }

        puts("");


        memset(ara,0,sizeof ara);
        memset(cum,0,sizeof cum);

    }




    return 0;
}
