#include<bits/stdc++.h>
using namespace std;
vector<int>v[50090];
int main()
{
    int t=0,test;
    cin>>test;
    while(t<test){
    int r,c,xsum=0,x,i,j;
    scanf("%d %d",&r,&c);

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&x);
            v[i].push_back(x);
        }
    }



    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if((r-i + c - j )%2==1)
            xsum^= v[i][j];
        }
    }

    printf("Case %d: ",++t);
    if(xsum==0) printf("lose\n");
    else printf("win\n");
    for(i=0;i<r;i++)
     v[i].clear();

    }
    return 0;
}
