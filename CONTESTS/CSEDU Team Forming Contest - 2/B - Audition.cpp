#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

struct tripple
{
    ll left,right,  sum;
}ara[1000009];

string str,str1;
ll n,K;
ll srch1(ll low, ll high, ll targ)
{
    ll mid, cnt=0;
    while(cnt++<=32)
    {

         mid= low+ (high-low)/2;
        if(ara[mid].sum>=targ)
            high=mid;
        else
            low=mid+1;
    }

    if(ara[mid-1].sum==targ) return mid-1;
    return mid;

}


ll Get()
{

    ll total=0,start=1;

    while(start+K-1<=ara[n].sum)
    {
        ll beg,endd;
        if(K>1){
         beg= srch1(1,n,start);
         endd=srch1(1,n,start+K-1);


         //printf("%lld %lld %lld %lld\n",beg,endd, ara[beg].left, ara[endd].right);
          total+= (ara[beg].left* ara[endd].right);



        }
        else
        {
            beg=srch1(1,n,start);
            endd=beg;

            if(K==1)
             total+= (ara[beg].left* ara[endd].right);
             else{
                ll num=ara[beg].left;
                num= num* (num-1);
                num/=2;

                total+=num;
             }
        }


//        if(K>1)
//        start=start+K-1;
         start++;
    }



    return total;
}

int main()
{
    int t=0,test;
    cin>>test;

    while(t++<test){

    scanf("%lld %lld",&n,&K);
    getchar();
    cin>>str1;
    str='A';
    str+=str1;

    str+='1';
    ll index=0,i;
    for( i=1;i<=n+1;i++)
    {
        if(str[i]=='1')
        {

            ara[i].left=i-index;
            ara[index].right=i-index;
            index=i;
        }
    }




    ll cons=0;
    for(ll i=1;i<=n;i++)
    {
        if(str[i]=='1'){
            cons++;
        }
            ara[i].sum= cons;
    }


    cout<<Get()<<endl;


    }

    return 0;
}
