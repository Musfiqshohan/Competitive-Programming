#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define pii pair<ll,ll>
#define ll long long
using namespace std;

string s1,s2;
int a1[300009], a2[300009];
int main()
{
    cin>>s1;
    getchar();
    cin>>s2;


    for(int i=0;i<s1.length(); i++)
        a1[s1[i]]++;

    for(int i=0;i<s2.length();i++)
        a2[s2[i]]++;

    int mn;
    int t1=0;

    for(int i=65;i<=122;i++)
    {
        if(i>90 && i<97) continue;
        if(a1[i]>0){
        mn= min(a1[i],a2[i]);
        t1+=mn;
        a1[i]-=mn;
        a2[i]-=mn;
        }
    }

    int t2=0;
    for(int i=65;i<=122;i++)
    {

        if(i>90 && i<97) continue;
        if(a1[i]>0)
        {
            if(i<=90)
            mn= min(a1[i], a2[i+32]);
            else
                mn= min(a1[i], a2[i-32]);

            t2+=mn;
        }

    }

    cout<<t1<<" "<<t2<<endl;
    return 0;
}
