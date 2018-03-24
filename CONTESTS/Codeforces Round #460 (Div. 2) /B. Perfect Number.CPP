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


i64 isOk(i64 n)
{
    i64 sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }

    return sum;

}
int main()
{
    int k;
    cin>>k;


    vector<int>vec= {9,1};
    int sum=10;
    k--;

    while(k)
    {

        int flag=0,sum=10;
        for(int i=0; i<vec.size(); i++)
        {

            sum-=vec[i];


            if(sum+vec[i]+1<10 && i>0)
            {
                vec[i]++;
                sum+=vec[i];
              //  printf("sum=%d %d %d\n",sum,i,vec[i]);
                int pos=i;
                vec[0]=10-sum;
                flag=1;
                break;
//            while(pos>=0)
//            {
//                vec[i]=
//            }
            }
            else
            {
                 vec[i]=0;
            }
        }

        if(flag==0)
        {
            vec.push_back(1);
            vec[0]=9;
        }

        k--;

    }


    reverse(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++)
        printf("%d",vec[i]);

    puts("");


}


