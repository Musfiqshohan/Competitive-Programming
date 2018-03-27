#include<bits/stdc++.h>
using namespace std;

int Set(int N, int pos)
{
    return N= N| (1<<pos);
}
bool Check(int N, int pos)
{
    return (bool)(N&(1<<pos));
}

int Reset(int N, int pos)
{
    return N= N&~(1<<pos);
}


char ara[22][22];
int m,n;
int dp[16][(1<<16) +10];
int tot_points;
struct point
{
    int x,y;
} root;
vector<point>points;

int get_distance(point a, point b)
{
    int dify= abs(a.y-b.y);
    int difx= abs(a.x-b.x);

    //  cout<<difx<<" "<<dify<<endl;

    int mn= min(difx, dify);

    int tot= (difx-mn) + (dify-mn) + mn;

    return tot;

}

int f(int pos,int mask)
{

   // cout<<mask<<endl;
   if(dp[pos][mask]!=-1) return dp[pos][mask];

    int mn=10000000;
    for(int i=0; i<tot_points; i++)
    {
        if(Check(mask,i)) continue;

        int temp_mask= Set(mask,i);

        int len= get_distance( points[pos], points[i])  ;


        if(__builtin_popcount(temp_mask)==tot_points)
        {
           // puts("hello\n");
            len += get_distance(points[i],root);

        }
        else
        {
            len+= f(i,temp_mask);
        }

        mn= min(mn,len);

    }

     if(__builtin_popcount(mask)==tot_points)
        {
           // puts("hello\n");
            int len = get_distance(points[pos],root);
            mn= min(mn,len);

        }

    return dp[pos][mask]=mn;

}

int main()
{
    int t=0,test;
    cin>>test;

    while(t<test) {

    memset(dp,-1,sizeof dp);

    scanf("%d %d",&m,&n);

    for(int i=0; i<m; i++)
    {
        scanf("%s",&ara[i]);
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(ara[i][j]=='x')
                root= {i,j};

            if(ara[i][j]=='g')
                points.push_back({i,j});
        }
    }

    tot_points= points.size();


    int mn=10000000;

    for(int i=0; i<tot_points; i++)
    {
        int mask= Set(0,i);
        int ret= get_distance(root,points[i]) + f(i,mask);

        mn= min(mn,ret);
    }

    if(mn==10000000) mn=0;
    printf("Case %d: %d\n",++t, mn);
    points.clear();

    }

    return 0;
}
