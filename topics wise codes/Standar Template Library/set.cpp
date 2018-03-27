#include<bits/stdc++.h>
using namespace std;
int main()
{

    set<int>s;
    s.insert(5);
    s.insert(10);
    s.insert(2);
    s.insert(10);

    set<int> ::iterator it;

    for(it=s.begin(); it!=s.end() ;it++)
        cout<<*it<<endl;

}
