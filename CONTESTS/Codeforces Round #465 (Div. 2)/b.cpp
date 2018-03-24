#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define llu unsigned long long
#define pii pair<i64,i64>
#define inf 1000000000000000000
using namespace std;

struct point
{
    int x,y;
};
vector<point>vec;
int main()
{
    int n,x=0,y=0;
    cin>>n;
    string str;

    cin>>str;

    int cnt=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='U')
            y++;
        if(str[i]=='R')
            x++;

        vec.push_back({x,y});
       // printf("%d %d i=%d\n",x,y,i);

        if(i>=2 && vec[i-1].x==vec[i-1].y)
        {
           // printf("->%d %d i=%d\n",x,y,i);
            if(vec[i-2].x<vec[i].x && vec[i-2].y==vec[i].y)
                cnt++;
            if(vec[i-2].y<vec[i].y && vec[i-2].x==vec[i].x)
                cnt++;
        }

    }

    cout<<cnt<<endl;
}
