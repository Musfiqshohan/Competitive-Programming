#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

vector<int>vec1,vec2;


void print(vector<int>vec)
{
    puts("Start");
    for(int i=0; i<vec.size(); i++)
        printf("%d ",vec[i]);

    puts("End");
}


int main()
{
    vec1.push_back(4);
    vec1.push_back(5);

    vector<int>temp(vec1.size()+vec2.size());
    print(temp);

    merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), temp.begin());

    print(temp);

}
