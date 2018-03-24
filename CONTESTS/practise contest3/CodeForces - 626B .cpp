#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
struct info
{
    int r,g,b;
};

info dp[205][205][205];

info f(int r, int g, int b)
{

   // printf("r=%d g=%d b=%d\n",r,g,b);

    if(r<0 || g<0 || b<0)
    {
        //puts("end");
        return {0,0,0};
    }
    if(r==0 && g==0 && b==1)
    {
        //puts("Blue");
        return {0,0,1};
    }
    if(r==0 && b==0 && g==1)
    {
       // puts("Green");
        return {0,1,0};
    }
    if(g==0 && b==0 && r==1)
    {
        //puts("Red");
        return {1,0,0};
    }

    if(dp[r][g][b].b!=-1) return dp[r][g][b];

    info t[10]; //t1,t2,t3,t4,t5,t6,t7,t8,t9;
    //t1=t2=t3=t4=t5=t6=t7=t8=t9={0,0,0};
    for(int i=0;i<10;i++) t[i]={0,0,0};


    t[1]=f(r-1,g-1,b+1);
    t[2]=f(r-1,g+1,b-1);
    t[3]=f(r+1,g-1,b-1);

    if(r-2>=0)
        t[4]=f(r-1,g,b);
    if(g-2>=0)
        t[5]=f(r,g-1,b);
    if(b-2>=0)
        t[6]=f(r,g,b-1);
//    t[7]=f(r,g-1,b);
//    t[8]=f(r,g,b-1);
//    t[9]=f(r,g,b-1);


    info ret= {0,0,0};
    for(int i=1; i<=6; i++)
    {
        //printf("->%d %d %d\n",t[i].r, t[i].g, t[i].b);
        ret.r|=t[i].r;
        ret.g|=t[i].g;
        ret.b|=t[i].b;

    }

    return dp[r][g][b]=ret;
//    //vector<int>vec={t1,t2,t3,t4,t5,t6,t7,t8,t9};
//
//    info ret= {t1.r|t2.r|t3.r|t4.r|t5.r|t6.r|t7.r|t8.r|t9.r,
//               t1.g|t2.g|t3.g|t4.g|t5.g|t6.g|t7.g|t8.g|t9.g,
//               t1.b|t2.b|t3.b|t4.b|t5.b|t6.b|t7.b|t8.b|t9.b
//              };


}


int main()
{

    ms(dp,-1);
    int n;
    cin>>n;
    getchar();
    string str;
    cin>>str;

    int red=0, green=0, blue=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='B')
            blue++;
        else if(str[i]=='G')
            green++;
        else red++;
    }

    info ret=f(red,green,blue);
    if(ret.b==1) printf("B");
    if(ret.g==1) printf("G");
    if(ret.r==1) printf("R");

    puts("");
    //printf("====%d %d %d\n",ret.r, ret.g, ret.b);

}
