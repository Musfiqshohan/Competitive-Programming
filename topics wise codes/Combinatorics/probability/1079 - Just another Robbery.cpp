#include<bits/stdc++.h>
using namespace std;
int ammount[200];
double prob[200];
int n,MX=100000000;
double dp[30000][200];
int vis[30000][200];
double f(int i,  double px, int num )
{

    if(num<0) return 10;
    if(num==0)
    {
        return 0;
    }
    if(i==n)
    {

        return 5;

    }
    double total1,total2;


    total2= f(i+1,px, num);
    total2= f(i+1,px, num);

    total1= prob[i]*px;
    //num-= ammount[i];
    px=px*(1-prob[i]);
    total1+= f( i+1,  px, num- ammount[i]);

 //   cout<<num<<" "<<total1<<" "<<total2<<endl;
//    if(min(total1,total2)<=1 && min(total1,total2)>0)
//    {
//        vis[num][i]=1;
//        return dp[num][i]= min(total1,total2);
//    }

    if(total1<0 && total2>=0) return total2;
    else if(total2<0 && total1>=0) return total1;
    return min(total1,total2);


}
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){

    memset(vis,-1,sizeof(vis));
    double P,x;
    int i,mid;
    cin>>P>>n;

    for(i=0; i<n; i++)
    {
        cin>>ammount[i]>>prob[i];
    }


    int high=20000;
    int low=0;
    int cnt=64;
    while(cnt--)
    {
        mid=low+ (high-low)/2;
        x=f(0,1,mid);

        if(x>=P){
            if( x>=10 ) low=mid;

            high=mid;

           // cout<<"x-MX="<<x-MX<<endl;
            //if(x<INT_MAX) low=mid;
        }
        else low=mid;
    }
    printf("Case %d: ",t+1);
    cout<<mid<<endl;
    }

    return 0;

}
