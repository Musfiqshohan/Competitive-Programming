#include<bits/stdc++.h>
using namespace std;

double dp[501][501][2];
int vis[501][501][2];
double f(int R, int B, int turn)
{

   if(B==0)
       return 0;


    if(R==0)
        return 1;


    if(vis[R][B][turn]!=-1)
        return dp[R][B][turn];

    vis[R][B][turn]=1;


    double t1=0,t2=0,t3=0;

    if(turn ==1)
    {
        t1= R*( (1.0/(R+B) ) * f(R-1,B,2) );
        t2= B*( (1.0/(R+B) ) *f(R,B-1,2)  );
    }
    else
    {

        t3= B* ((1.0/(B*1.0))*f(R,B-1,1));
    }


    return dp[R][B][turn]=t1+t2+t3;

}

int main()
{
    memset(vis,-1,sizeof vis);
    int tt=0,test;
    cin>>test;
    while(tt<test) {
    int R,B;
    scanf("%d %d",&R,&B);

    printf("Case %d: %.10f\n",++tt, f(R,B,1));

    }
}
