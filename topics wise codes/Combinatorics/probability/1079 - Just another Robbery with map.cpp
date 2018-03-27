#include<bits/stdc++.h>
#define ms(a,b) memset(a, b , sizeof a);
using namespace std;
int ammount[200];
double prob[200];
int n,MX=100000000;
double dp[200][10009];
int  vis[200][10009];


double f(int i,  int num )
{

    if(num==0)
    {
        return 0;
    }

    if(i==n)
    {
        if(num==0)
            return 0;
        else return 1000000.0;

    }

    if(vis[i][num]!=-1) return dp[i][num];
    vis[i][num]=1;

    double total1=100000,total2=100000;


    total2= f(i+1,num);

    if(num-ammount[i]>=0)
    {
        total1= f(i+1,num- ammount[i]);
        total1= total1 + (1.0-total1)*prob[i];
       // printf("->%.2f %d\n",total1,i);
    }

    return dp[i][num]=min(total1,total2);


}


int main()
{

    int t,test;
    scanf("%d",&test);
    for(t=0; t<test; t++)
    {
        ms(vis,-1);
        double P,x;
        int i,mid;

        scanf("%lf %d",&P,&n);



        int tot=0;

        for(i=0; i<n; i++)
        {
            scanf("%d %lf",&ammount[i],&prob[i]);
            //cin>>ammount[i]>>prob[i];
            tot+=ammount[i];

        }

        int sum=0;

        for(int i=tot;i>=0;i--)
        {
            double ret=f(0,i);

            if(ret<P)
            {
                sum=i;
                break;
            }
        }

        printf("Case %d: %d\n",t+1,sum);

    }

    return 0;

}

