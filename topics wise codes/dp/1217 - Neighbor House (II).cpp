    #include<bits/stdc++.h>
    using namespace std;

    int ara[1009], dp[1009][2][2];
    int n;
    int f(int pos, int prevTaken, int isFirst)
    {
        if(pos==n-1)
        {
            if(prevTaken==0)
                {
                    if(isFirst==1)
                        return 0;
                    else
                    return ara[pos];

                }

            return 0;

        }

        if(dp[pos][prevTaken][isFirst]!=-1) return dp[pos][prevTaken][isFirst];

        int t1=0,t2=0;

        if(prevTaken==0)
        t1= ara[pos]+ f(pos+1,1,isFirst);

        t2= f(pos+1,0,isFirst);

        return dp[pos][prevTaken][isFirst]=max(t1,t2);

    }


    int main()
    {

        int tt=0,test;
        cin>>test;
        while(tt<test) {

        memset(dp,-1,sizeof dp);

        scanf("%d",&n);

        for(int i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }

        int mx1=f(1,0,0);
        int mx2=f(1,1,1)+ara[0];

       printf("Case %d: %d\n",++tt,max(mx1,mx2));

        }

        return 0;
    }
