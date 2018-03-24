#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<i64,i64>
#define inf 1000000000000000000
using namespace std;
vector<i64>vec;


double mn;
i64 mnsum,mnnum;


double ara[500009];


double dp(i64 pos, i64 sum, i64 num)
{

    if(pos==0)
    {
        double rr=(sum*1.0)/num;
        // cout<<rr<< "-->"<<mn<<endl;
        if(rr<mn)
        {
            // printf("sum=%lld %lld %.3lf\n",sum,num,sum*1.0/num);
            mn=(sum*1.0)/num;
            mnsum=sum;
            mnnum=num;
        }
        return sum*1.0/num;
    }

    double t1=dp(pos-1, sum+vec[pos], num+1);
    double t2=dp(pos-1, sum, num);

    return min(t1,t2);

}


int main()
{
    i64 Q,x,cs;
    cin>>Q;
    mn=1000000.0;


    int left=-1,Ltot=0,Lnum=0;
    double avg=100000;
    vec.push_back(0);
    for(i64 i=0; i<Q; i++)
    {

        scanf("%lld",&cs);
        if(cs==1)
        {
            scanf("%lld",&x);
            vec.push_back(x);
            int l=vec.size()-1;

            ara[l]= l-1>=0?ara[l-1]+x: x;

        }
        else
        {
            double avg1=(ara[left]+vec.back())/(left+1);
            double avg2=(ara[left+1]+vec.back())/(left+2);

            while(avg1>avg2)
            {
                avg1=avg2;
                if(left+1<vec.size()-1)
                    left++;
                else break;
                avg2=(ara[left+1]+vec.back())/(left+2);
            }


            avg=avg1;

            int l=vec.size()-1;
            cout<<fixed<<setprecision(10)<<vec.back()-avg<<endl;

        }


    }



//
}
