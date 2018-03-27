#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int, char> > q;

    q.push(make_pair(50, 'A'));
    q.push(make_pair(100, 'B'));
    q.push(make_pair(150, 'C'));
    q.push(make_pair(100, 'A'));



    cout<<q.top().first<<" "<<q.top().second<<endl;
    q.pop();
    cout<<q.top().first<<" "<<q.top().second<<endl;
    q.pop();
//  q.pop();
    cout<<q.top().first<<" "<<q.top().second<<endl;
//    q.push(100);
//    q.push(200);
//    q.push(42);
//
//    while(q.empty()==0 )
//    {
//        cout<<q.top()<<endl;
//        q.pop();
//    }

}

