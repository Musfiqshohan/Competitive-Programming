#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t ,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    double total=1, n,i;
    cin>>n;


    for(i=n;  ;i--)
    {
        total= total* i/n;

        if(total<=0.5) { printf("Case %d: %d\n",t+1,(int)(n-i)); break; }
    }

    }
    return 0;
}
