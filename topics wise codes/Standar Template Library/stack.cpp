#include<bits/stdc++.h>
using namespace std;

int main()
{
        stack <int> st;
        st.push(100);
        st.push(200);

        while( !st.empty() )
        {
            cout<<st.top() <<endl;
            st.pop();
        }

        stack<string>ss;

        ss.push("Hi");
        ss.push("my");
        ss.push("name");

        while(!ss.empty())
        {
            cout<<ss.top()<<endl;
            ss.pop();
        }
}
