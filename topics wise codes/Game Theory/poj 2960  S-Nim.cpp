#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include<bitset>
using namespace std;

int dp[10009],Set[109];
int k,mn;
int Grundy(int stones)
{
    if(stones<mn)
        return 0;

//    if(stones== 2 ||  stones==5)
//        return 1;

    if(dp[stones]!=-1) return dp[stones];



    bitset<10009>vec;
    for(int i=0; i<k; i++)
    {

        if(stones>=Set[i])
        {
            int t= Grundy(stones-Set[i]);
            vec[t]=true;
        }
    }


    int mex=0;
    for( mex=0;mex<=10005;mex++)
        if(vec[mex]==false)
            break;



    return dp[stones]=mex;

}

int main()
{


    while(1)
    {
        memset(dp,-1,sizeof dp);

        scanf("%d",&k);

        if(k==0) break;

        mn=1000000;
        for(int i=0; i<k; i++)
        {
            scanf("%d",&Set[i]);
            if(Set[i]<mn)
                mn=Set[i];
        }


        //cout<<Grundy(12)<<endl;

//        for(int i=0;i<k;i++)
//        {
//            printf("%d- > %d\n",Set[i], Grundy(Set[i]));
//        }

        int m;
        scanf("%d",&m);




        for(int mm=0; mm<m; mm++)
        {
            int l;
            scanf("%d",&l);

            int xorr=0,x=0;
            for(int i=0; i<l; i++)
            {
                scanf("%d",&x);
                xorr^=Grundy(x);
                //  printf("%d -> %d\n",x, Grundy(x));
            }

            if(xorr==0) printf("L");
            else printf("W");

        }

        puts("");
    }


    return 0;
}
