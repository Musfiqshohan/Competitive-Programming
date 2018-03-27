#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define d 256
#define mod 1000000009
using namespace std;
string str;
vector<int>vec;
ll hash_value[1000009];
void prepare_hashing()
{
    int len=str.length();

    ll p=0,t=0,currBase=1;

    for(int i=0,j=len-1; i<str.size()-1; i++,j--)
    {
        p=(p*d + str[i])%mod;
        hash_value[i]=p;

        t=( (str[j]*currBase)%mod  + t )%mod;

        currBase*=d;
        currBase%=mod;

        if(p==t)
            vec.push_back(i+1);
    }
    return ;
}

ll power[1000009];

int how_many_times(int len)
{
    ll p=0,t=0;
    p=t=hash_value[len-1];


    ll h=power[len-1];

    for(int i=0; i+len<str.length()-1; i++)
    {
        ll new_val=(t - (str[i]*h)%mod);
        new_val= (new_val+mod)%mod;

        t= (d*new_val)+ str[i+len];
        t%=mod;

        if(t==p)
            return 1;
    }

    return -1;

}

class TimeTracker {
    clock_t start,end;
public:
    TimeTracker()
    {
            start=clock();
    }
    ~TimeTracker(){
        end=clock();
        fprintf(stderr, "%.3lf s\n",(double)(end-start)/CLOCKS_PER_SEC);
    }

};
int main()
{

    cin>>str;

    prepare_hashing();

    if(str.length()<=2 || vec.size()==0)
    { printf("Just a legend\n");return 0; }

    power[0]=1;
     for(int i=1;i<=vec.back();i++)
        power[i]=(power[i-1]*d)%mod;

    int low=0,high=vec.size()-1,cnt=20,mid=0;


    TimeTracker obj;
    new TimeTracker();
    while(cnt--)
    {
        mid= low+ (high-low)/2;

        int ret= how_many_times(vec[mid]);

        if(ret==+1)
            low=mid;
        else high=mid;

    }
    //~TimeTracker();

    if(mid+1<vec.size() && how_many_times(vec[mid+1])==+1)
        mid++;

    if(how_many_times(vec[mid])==-1)
        printf("Just a legend\n");
    else
    {
        int leng=vec[mid];
        for(int i=0; i<leng; i++)
            printf("%c",str[i]);
        puts("");
    }



    return 0;
}
