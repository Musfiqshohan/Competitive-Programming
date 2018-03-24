#include<bits/stdc++.h>
#define ll long long
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
ll ax,ay,bx,by,cx,cy,flag=0;

ll f(ll x1, ll y1, ll x2, ll y2)
{
    ll res= (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    return res;
}
//double f1(ll x1, ll y1, ll x2, ll y2)
//{
//    double res= (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
//    return sqrt(res);
//}

bool isColinear()
{

    ll res1= (by-ay)*(cx-bx);
    ll res2= (cy-by)*(bx-ax);

    if(res1==res2) return true;
    else return false;


}
int main()
{

    cin>>ax>>ay>>bx>>by>>cx>>cy;
    if(isColinear()==true) flag=0;
    else
    {

        ll dis1= f(ax,ay,bx,by);
        ll dis2= f(bx,by,cx,cy);

      //  cout<<dis1<<" "<<dis2<<endl;

        if(dis1==dis2)
            flag=1;
        else flag=0;
    }

    if(flag==1) printf("Yes\n");
    else printf("No\n");

}


/*
0 1000000000 1000000000 1000000000 1000000000 0
*/
