#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<i64,i64>
#define inf 1000000000000000000
using namespace std;
vector<i64>vec;


double mn;
i64 mnsum,mnnum;





double dp(i64 pos, i64 sum, i64 num)
{

    if(pos==-1)
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
   // vec.push_back(0);
    for(i64 i=0; i<Q; i++)
    {

        scanf("%lld",&cs);
        if(cs==1)
        {
            scanf("%lld",&x);
            vec.push_back(x);

        }
        else
        {
            int l=vec.size()-1;

           // printf("left=%d size=%d\n",left,size);
            while(left+1<vec.size() && (1.0*(Ltot+vec[left+1]+vec.back())/(Lnum+2.0)) <= (1.0*(Ltot+vec.back())/(Lnum+1.0)) )
            {
                avg=1.0*(Ltot+vec[left+1]+vec.back())/(Lnum+2.0);
                printf("%lld %lld %lld %lld\n",Ltot,vec[left+1],vec.back(),Lnum);
                cout<<avg<<endl;
                Ltot+=vec[left+1];
                left++;
                Lnum++;
            }
//            double t1=1.0*(Ltot+vec.back())/(Lnum+1);
//            double t2=1.0*(Ltot+vec[left+1]+vec.back())/(Lnum+2);





            double res2=dp(l-1,vec[l],1);
           // double res2=ret.first*1.0 /ret.second;
            cout<<fixed<<setprecision(10)<<avg<<" "<<res2<<endl;
            cout<<fixed<<setprecision(10)<<vec.back()-avg<<endl;

        }


        //double res2=dp(l-1,vec[l],1);

    }



//
}
