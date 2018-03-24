#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;



int main()
{
    int n;
    cin>>n;

    ll tot=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int xorr=i^j;
            int k=xorr;
            vector<int>vec;

            vec.push_back(i);
            vec.push_back(j);
            vec.push_back(k);
            sort(vec.begin(),vec.end());

            if(vec[0]+vec[1]>vec[2] && k<=n && k>=i && k>=j){
                    //printf("%d %d %d\n",i,j,k);
                tot++;
            }

        }
    }

    cout<<tot<<endl;

}
