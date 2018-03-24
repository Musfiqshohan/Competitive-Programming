#include<bits/stdc++.h>
#define ll long long
using namespace std;

int cum[2009][2009],rcum[2009][2009],ara[2009];
int main()
{

    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        scanf("%d",&ara[i]);


    for(int j=0; j<n; j++)
    {
        int mx=0;
        for(int i=j; i<n; i++)
        {
            int cnt=0;
            while(ara[i]<=ara[i+1] && i+1<n)
            {
                cnt++;
                mx=max(mx,cnt);
                cum[j][i]=mx;
                printf("%d to %d = %d\n",j,i,cum[j][i]);
                i++;
            }
            cnt++;

            mx=max(mx,cnt);
            cum[j][i]=mx;
            printf("->%d to %d = %d\n",j,i,cum[j][i]);
            // cout<<cum[j][i]<<endl;
        }
    }


    for(int j=n-1; j>=0; j--)
    {
        int mx=0;
        for(int i=j; i>=0; i--)
        {
            int cnt=0;
            while(ara[i]<=ara[i-1] && i-1>=0)
            {
                cnt++;
                i--;
            }
            cnt++;

            mx=max(mx,cnt);
            rcum[j][i]=mx;
        }
    }


//    for(int i=0;i<n;i++)
//    {
//        for(int j=i;j<n;j++)
//        {
//            printf("%d to %d = %d  %d\n",i,j,cum[i][j],rcum[i][j]);
//        }
//    }

}
