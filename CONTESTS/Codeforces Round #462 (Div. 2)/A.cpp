#include<bits/stdc++.h>
#define i64 long long
#define pii pair<i64,i64>
using namespace std;


int main()
{
    string str;
    cin>>str;

    string str2=str;
    reverse(str2.begin(),str2.end());
    str=str+str2;
    cout<<str<<endl;

}
