#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

struct info
{
    string n1, n2;
    int t;

}peo[2000];

map<string, int>mp;
vector<string>vec;
int ara[2000][2000];
int main()
{



    int n,d;
    scanf("%d %d",&n,&d);

    getchar();
    string s1,s2;
    int time;
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2>>time;
        peo[i].n1=s1;
        peo[i].n2=s2;
        peo[i].t=time;
        getchar();

        if(mp.find(s1)==mp.end()) // till now
        {
            mp[s1]=cnt++;
        }
        if(mp.find(s2)==mp.end()) // till now
        {
            mp[s2]=cnt++;
        }


    }

    for(int i=1;i<=n;i++)
    {
        int t1= mp[peo[i].n1];
        int t2= mp[peo[i].n2];

        for(int j=i+1;j<=n;j++)
        {
            if(peo[j].n1 == peo[i].n2 && peo[j].n2== peo[i].n1 && peo[j].t-peo[i].t<=d && peo[j].t-peo[i].t>0)
            {
                if(ara[t1][t2]==0 && ara[t2][t1]==0)
                {
                    vec.push_back(peo[i].n1+" "+peo[i].n2);
                     ara[t1][t2]=100000000;
                     ara[t2][t1]=100000000;
                }

            }
        }
    }

    printf("%d\n",vec.size());

    for(int i=0;i<vec.size();i++) cout<<vec[i]<<endl;


    return 0;
}
