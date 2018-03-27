#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int>q;
    q.push(100);
    q.push(1002);
    q.push(1023);

    while( q.empty() ==0 )
    {
        cout<<q.front()<<endl;
        q.push(q.front());
        q.pop();
    }
}
