#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

pair<int,int>p[5];

void f(int a, int x, int i)
{
    if(a>x)
    {
        if((a-x)%2==0)
        {
            p[i].first= (a-x)/2;
        }
        else
        {
            p[i].first= (a-x+1)/2;
            p[i].second=-1;
        }

    }
    else
        p[i].second=-x;

}
int main()
{
    int a,b,c,x,y,z;
    cin>>a>>b>>c;
    cin>>x>>y>>z;

    f(a,x,1);
    f(b,y,2);
    f(c,z,3);

    for(int i=1; i<=3; i++) printf("%d %d\n",p[i].first, p[i].second);

    if(p[2].second<0)
    {
        p[2].second+= p[1].first;
        if(p[2].second>=0)
        {
            p[3].second+=p[2].second;
            p[2].second=0;
        }
    }
//    else
//    {
//        p[3].second+= p[1].first;
//        if(p[3].second>=0)
//        {
//            p[2].second+=p[3].second;
//            p[3].second=0;
//        }
//
//    }

    if(p[1].second<0)
    {
        p[1].second+=p[2].first;
        if(p[1].second>=0)
        {
            p[3].second+=p[1].second;
            p[1].second=0;
        }
    }
    else
    {
        p[3].second+=p[2].first;
        if(p[3].second>=0)
        {
            p[1].second+=p[3].second;
            p[3].second=0;
        }

    }

    if(p[1].second<0)
    {
        p[1].second+=p[3].first;
        if(p[1].second>=0)
        {
            p[2].second+=p[1].second;
            p[1].second=0;
        }

    }
    else
    {
        p[2].second+=p[3].first;
        if(p[2].second>=0)
        {
            p[1].second+=p[2].second;
            p[2].second=0;
        }
    }

    printf("%d %d %d\n",p[1].second, p[2].second, p[3].second);
    if(p[1].second ==0 && p[2].second==0 && p[3].second==0 ) printf("Yes\n");
    else printf("No\n");

    return 0;
}
