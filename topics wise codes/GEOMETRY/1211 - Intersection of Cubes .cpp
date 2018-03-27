#include<bits/stdc++.h>
#define ll long long
#define pi acos(-1)
using namespace std;

int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        int n,x1,y1,z1,x2,y2,z2, mxx1,mnx2,mxy1,mny2,mxz1,mnz2;
        mxx1=mxy1=mxz1=0;
        mnx2=mny2=mnz2=1009;

        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            cin>>x1>>y1>>z1>>x2>>y2>>z2;

            mxx1=max(mxx1,x1);
            mnx2= min(mnx2,x2);
            mxy1=max(mxy1,y1);
            mny2= min(mny2,y2);
            mxz1=max(mxz1,z1);
            mnz2= min(mnz2,z2);

        }

        int res=(mnx2-mxx1)*(mny2-mxy1)*(mnz2-mxz1);
        if(res<0)
            res=0;
        printf("Case %d: %d\n",++tt,res);

    }
    return 0;
}
