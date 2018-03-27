#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a);
using namespace std;
int n=0;
int dir[1009], dp[1009];
struct data
{
    int weight, iq, index;
};
data input[1009];
vector<data>result;

bool compare1(data a, data b)
{
    if(a.weight==b.weight)
        return a.iq>b.iq;
    else return a.weight<b.weight;
}

bool compare2(data a, data b)
{
    return a.index<b.index;
}

int f(int u)
{
    int res=0, mx= 0;

    if(dp[u]!=-1) return dp[u];
    for(int i=u+1; i<n; i++)
    {
        if(input[u].iq>input[i].iq && input[u].weight<input[i].weight)
        {
            res= f(i);
            if(res>mx)
            {
                mx=res;
                dir[u]=i;
            }
        }
    }

    return dp[u]=1+mx;
}

void printLIS(int u)
{
    data temp;
    while(dir[u]!=-1)
    {
      //  printf("w=%d q=%d in=%d\n",input[u].weight, input[u].iq, input[u].index+1);
        printf("%d\n",input[u].index+1);



        u=dir[u];
    }

  //  printf("w=%d q=%d in=%d\n",input[u].weight, input[u].iq, input[u].index+1);
    printf("%d\n",input[u].index+1);



}

int main()
{
    ms(dir,-1);
    ms(dp,-1);
   // freopen("10131 - Is Bigger SmarterI.txt", "r", stdin);

    while(scanf("%d %d",&input[n].weight,&input[n].iq)!=EOF)
    {
        input[n].index=n;
        n++;
    }

    sort(input+0, input+n, compare1);



    int LIS=0,start;
    for(int i=0; i<n; i++)
    {
        if(f(i)>LIS)
        {
            LIS= f(i);
            start=i;
        }
    }

    printf("%d\n",LIS);


    printLIS(start);

    return 0;
}
