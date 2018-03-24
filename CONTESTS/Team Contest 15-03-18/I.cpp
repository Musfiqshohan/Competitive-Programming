#include<bits/stdc++.h>
#define pii pair<string,int>
using namespace std;

vector<pii>v;

bool cmp(pii a, pii b)
{
    return a.second<b.second;
}
int main()
{
    int n;
    cin>>n;
    string s1,s2;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>s1>>s2;
        if(s1[0]<65)
        num=stoi(s1)/2, s1=s2;
        else num=stoi(s2);

        v.push_back({s1,num});
    }


    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++)
        cout<<v[i].first<<endl;
}
