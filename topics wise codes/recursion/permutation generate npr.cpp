#include<bits/stdc++.h>
using namespace std;

int ara[20],vis[20];
int n,r;


void f(int index)
{
    int i;
    if(index==r+1)
    {
        for(i=1;i<=r;i++)
            printf("%d ",ara[i]);
        puts("");
    }

    for(i=1;i<=n;i++){
     if(vis[i]==0)
        {
            vis[i]=1;
            ara[index]=i;
            f(index+1);
            vis[i]=0;
        }
    }

    return ;
}


int main()
{

    scanf("%d %d",&n,&r);

    f(1);
}

