#include<bits/stdc++.h>
using namespace std;

int flat[105], floorx[105];
int n,m;
int f(int x)
{
    for(int i=0; i<=m; i++)
    {
        int fl=flat[i];

        int flo=fl/x;
        if(fl%x!=0) flo++;

        //printf("%d %d %d\n",flat[i],flo,floorx[i]);

        if(flo>floorx[i]) return -1;
        if(flo<floorx[i]) return 1;
    }

    return 0;
}

void g(int x)
{
    int fl=n/x;
    if(n%x!=0)
        fl++;

    printf("%d\n",fl);
}

int main()
{

    scanf("%d %d",&n,&m);




    int mx=1;
    flat[0]=1;
    floorx[0]=1;
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d",&flat[i],&floorx[i]);

        if(n==flat[i])
        {
            printf("%d\n",floorx[i]);
            return 0;
        }

        if(floorx[i]==1)
            mx= max(mx,flat[i]);
    }

    if(n<=mx)
    {
        printf("1\n");
        return 0;
    }


    int low=1,high=501;

    int cnt=0,mid,flag=0;

    while(++cnt<=20)
    {
        mid= low+ (high-low)/2;

        // printf("%d %d %d\n",mid,low,high);

        if(f(mid)>0)
            high=mid;
        else low=mid;

    }

    // cout<<f(5)<<endl;

    if(f(mid)==0) flag++;
    if(f(mid+1)==0) flag++;
    if(mid>1 && f(mid-1)==0) flag++;

    if(flag>1) printf("-1\n");
    else if(f(mid)==0)  g(mid);
    else if(mid>1 && f(mid-1)==0) g(mid-1);
    else if(f(mid+1)==0) g(mid+1);

}
