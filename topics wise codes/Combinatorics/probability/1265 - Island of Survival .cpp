#include<bits/stdc++.h>
using namespace std;

double dp[1009][1009];
int vis[1009][1009];
double f(int tiger, int deer)
{
    // cout<<t<<" "<<d<<endl;
    double t=tiger, d=deer;
    if(t<=0) return 1;
    if(d<0) return 0;

    if(vis[tiger][deer]!=-1) return dp[tiger][deer];
    vis[tiger][deer]=1;

    double tot= t+d+1;
    double deno= (tot*(tot-1))/2;   /// this is denominator

    double  rhs= d*(d-1)/(2*deno);    ///this is for , if i dont kill any deer, then i have to make some change in the equation
    double lhs= 1-rhs;

    double t1,t2,t3,t4;
    t1= (t*d)/deno * f(t,d-1);      ///for tiger and deer

    t2= d/deno  * f(t,d-1);     ///if i kill a deer
    t3= (t*(t-1))/(2*deno)  * f(t-2,d); /// if two tiger



    double ret2= (t1+t2+t3)/lhs;    /// this is when i dont kill a deer
    return dp[tiger][deer]=ret2;



}


int main()
{
    memset(vis,-1,sizeof vis);
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        int t,d;
        cin>>t>>d;

        printf("Case %d: %.10f\n",++tt,f(t,d));

    }

}
