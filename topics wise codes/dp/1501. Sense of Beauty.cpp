#include<bits/stdc++.h>
using namespace std;
int dp[1009][1009][3], vis[1009][1009][3];
string a,b;
int ara[20003];
int n;
int f(int first, int second,int num)
{
 //   printf("first=%d second=%d num=%d\n",first,second,num);
    int n1,n2,index;
    if(first>n || second>n || abs(num)>1) return -1;

    if(first==n && second==n && abs(num)<=1)
        return 1;

    if(vis[first][second][num]!=-1) return dp[first][second][num];

    if(a[first]=='0') n1=-1;
    else n1=1;

    if(b[second]=='0') n2=-1;
    else n2=1;

    index= first +second;
    if(f(first+1,second, num+n1)==1)
    {
        ara[index]=1;
      // printf("%s\n",str);
      vis[first][second][num]=1;
        return dp[first][second][num]=1;
    }

    if(f(first, second+1, num+n2)==1)
    {
        ara[index]=2;
      // printf("%s %d %c\n",str,index, str[index]);
      vis[first][second][num]=1;
        return dp[first][second][num]=1;
    }

    vis[first][second][num]=1;
    return dp[first][second][num]=-1;

}
int main()
{

    memset(vis,-1,sizeof vis);
    scanf("%d",&n);
    cin>>a>>b;

   if(f(0,0,0)==-1) { printf("Impossible\n"); return 0; }

   for(int i=0;i<2*n;i++)
    printf("%d",ara[i]);
    puts("");

    return 0;
}
