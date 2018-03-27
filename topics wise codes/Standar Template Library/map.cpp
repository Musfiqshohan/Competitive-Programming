#include<bits/stdc++.h>
using namespace std;
int main()
{

    map<string, int>m;
    string name;
    while(cin>>name)
    {
        if(name=="Fairuz") break;

        m[name]++;
    }

    map<string , int > :: iterator it;

    for(it= m.begin(); it!=m.end();it++)
        cout<<it->first << " " << it->second <<endl;



    return 0;
}
