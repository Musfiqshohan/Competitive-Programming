#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
vector<i64>vec1, vec2;
i64 dif;

void calc(i64 a,i64 b)
{
    while(a)
    {
        vec1.push_back(a%10);
        a/=10;
    }

    while(b)
    {
        vec2.push_back(b%10);
        b/=10;
    }

    sort(vec1.begin(), vec1.end());
    reverse(vec1.begin(), vec1.end());

    dif=vec2.size()-vec1.size();
//   // pri64f("dif=%d\n",dif);
//    //i64 dif2=-dif;
//    while(dif<0)
//    {
//        vec2.push_back(0);
//        dif++;
//      //  puts("hi");
//    }

    reverse(vec2.begin(), vec2.end());
}

int main()
{
    i64 a,b;

    cin>>a>>b;


    calc(a,b);

    i64 flag=0;
    if(dif==0)
    {

        for(i64 i=0; i<vec1.size(); i++)
        {
            i64 pre=vec2[i];
            i64 mx=-1,mxi=-1;

            for(i64 j=i; j<vec1.size(); j++)
            {
                if(vec1[j]>=mx && (vec1[j]<=pre||flag==1))
                {
                    mx=vec1[j];
                    mxi=j;
                }
            }

            printf("%lld %lld\n",pre,mx);
           // cout<<mx<<endl;
            if(mx<pre) flag=1;

            for(i64 j=mxi; j>i; j--)
                swap(vec1[j],vec1[j-1]);

        }


    }

    i64 st=0;

    while(vec1[st]==0)
        st++;

    for(i64 i=st; i<vec1.size(); i++)
        printf("%lld",vec1[i]);

    puts("");

}
