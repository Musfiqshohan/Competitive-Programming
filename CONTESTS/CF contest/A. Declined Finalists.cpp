#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);

    int x,mx=-1;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);

        mx= max(mx,x);
    }

    if(mx-25>0)
    cout<<mx-25<<endl;
    else printf("0\n");


}
