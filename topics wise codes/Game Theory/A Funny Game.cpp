#include<bits/stdc++.h>
using namespace std;

int n,mark[1001];
int f(int m,int turn)
{
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(mark[i]==1)
            cnt++;
    }

    if(cnt==n) return 0;

    int cnt2=0,t1=0,t2=0;
    for(int i=1; i<=n; i++)
    {
        if(mark[i]==0 && mark[(i+1)%n]==0)
        {
            mark[i]=1;
            mark[(i+1)%n]=1;

            t1=f(m-2,turn^1);

            mark[i]=0;
            mark[(i+1)%n]=0;

        }
        else if(mark[i]==0)
        {
            mark[i]=1;
            t2=f(m-1,turn^1);
            mark[i]=0;

        }

        cnt2+=t1+t2;

    }
    if(cnt2==0) return 1;
    else return 0;

}


int main()
{
    while(1){

    scanf("%d",&n);


    cout<<f(n,0)<<endl;

    memset(mark,0,sizeof mark);
    }

}
