#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

vector<int>vec;
int main()
{
    int t=0,test;
    cin>>test;
    while(t<test)
    {

        int n,w,x,y;
        scanf("%d %d",&n,&w);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            vec.push_back(y);
        }

        sort(vec.begin(),vec.end());

        int cur=vec[0],cnt=1;
        for(int i=0; i<vec.size(); i++)
        {
            if(vec[i]>cur+w)
            {
                cnt++;
                cur=vec[i];
            }

        }

        printf("Case %d: %d\n",++t,cnt);
        vec.clear();
    }

    return 0;
}
