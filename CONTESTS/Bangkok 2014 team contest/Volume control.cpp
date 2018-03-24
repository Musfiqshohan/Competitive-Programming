#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a)
#define inf 100000000
using namespace std;

int ara[30009];
const int  MAXN=900000005;
int mark[MAXN/32+4];
int main()
{


    int maxN=30005,cnt=0;
    for(int i=1;i<=maxN;i++)
    {
        for(int j=i,r=i;j--; r+=i)
        {
            int pos=r/32;
            int rem=r%32;
         //   printf("pos=%d rem=%d\n",pos,rem);
            if((mark[pos]&(1<<rem))==0)
                cnt++,mark[pos]|=(1<<rem);

         //   printf("%d * %d  = %d\n",i,j, r);
            ara[i]=cnt+1;
           // printf("i=%d  cnt=%d\n",i,ara[i]);
        }
    }

  //  printf("done\n");


    int tt;
    scanf("%d",&tt);

    while(tt--)
    {
        int n;
        scanf("%d",&n);

        printf("%d\n",ara[n]);



    }


}
