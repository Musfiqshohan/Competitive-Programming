#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector<int>vec;
string str,temp;
ll n;
ll f(ll mid, char ch1, char ch2)
{
    ll i=0,j=mid, k=n-1;
    ll moves1=0, moves2=0;
    while(i<j)
    {
        while(temp[i]!=ch1 && i<j)
            i++;
        while(temp[j]!=ch2 && j>i)
            j--;


      // prllf("%d %d\n",i,j);
        if(i<j)
        {
            swap(temp[i],temp[j]);
            moves1++;

            i++;
            j++;

        }
    }

   // prllf("moves1=%d\n",moves1);
    j=mid;
    while(j<k)
    {
        while(temp[j]!=ch2 && j<k)
            j++;

        while(temp[k]!=ch1 && k>j)
            k--;

       // prllf("j=%d k=%d\n",j,k);
        if(j<k)
        {

            swap(temp[j],temp[k]);
            moves2++;

            j++;
            k--;
        }
    }

   // prllf("moves2=%d\n",moves2);
    return moves1+moves2;

}

int main()
{

    scanf("%lld",&n);

    getchar();
    cin>>str;
   // cout<<str<<endl;
    temp=str;

    ll x,mn=1000000000000;

//    while(1)
//    {
//        scanf("%d",&x);
//        cout<<f(x)<<endl;
//    }.

    for(ll i=0;i<n;i++)
    {
        if(str[i]=='T'){
        temp=str;
        mn= min(mn,f(i, 'T','H'));

        }
    }

    for(ll i=0;i<n;i++)
    {
        if(str[i]=='H'){
        temp=str;
        mn= min(mn,f(i, 'H','T'));

        }
    }

    for(int i=0;i<n;i++)


    printf("%lld\n",mn);


    return 0;
}
