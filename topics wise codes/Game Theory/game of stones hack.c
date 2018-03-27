#include<stdio.h>

int dp[200];
 int main()
 {
     int n,t,i;
     dp[0]=0;
     dp[1]=0;
     dp[2]=1;
     dp[3]=1;
     dp[4]=1;
     dp[5]=1;

     for(i=6;i<103;i++)
     {
         if(dp[i-2]==0 || dp[i-3]==0 || dp[i-5]==0)
            dp[i]=1;
         else dp[i]=0;
     }



     scanf("%d",&t);
     while(t--){
     scanf("%d",&n);

     if(dp[n]) printf("First\n");
     else printf("Second\n");
     }

 }
