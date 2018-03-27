#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;

    stack<char>st;
    cin>>s;
    int i,cnt=0;

    for(i=0;i<s.size();i++)
    {
        if(st.empty()==false && st.top() =='(' && s[i]==')')
        {
            st.pop();
            cnt++;
        }
        else st.push(s[i]);
    }

    printf("%d\n",cnt*2);

    return 0;
}
