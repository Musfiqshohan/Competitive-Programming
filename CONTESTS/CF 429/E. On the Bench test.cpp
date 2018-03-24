#include<bits/stdc++.h>
using namespace std;

int ara[20],vis[20];
int n;

void f(int index);
void loop(int i, int index);
void f(int index)
{
    int i;
    if(index==n)
    {
        for(i=0;i<n;i++)
            printf("%d ",ara[i]);
        puts("");
    }

    loop(n,index);

    return ;
}
void loop(int i,int index)
{
    if(i==0) return;

    loop(i-1,index);
    if(vis[bar[i]]==0)
        {
            vis[i]=1;
            ara[index]=bar[i];
            f(index+1);
            vis[bar[i]]=0;
        }


    return;
}


int main()
{

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&bar[i]);
    }

    f(0);
}
