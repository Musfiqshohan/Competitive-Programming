#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;


int cnt=0;
double f1(int a, int b)
{
    if(a==b)
    {
        return 0.5;
    }
    if(cnt>=1000) return 0;

    cnt++;
    double ret=0;
    if(a>b)
    {
        ret=1;
        ret+= f1(a-b, b*2);
    }
    else
        ret+= f1(a*2, b-a);

    return 0.5*ret;
}


double f2(int a, int b)
{
    if(a==b) return 1;

    if(cnt>=1000) return 0;
    cnt++;

    double ret=0;

    ret= 1;
    if(a>b)
        ret+= 0.5 * f2(a-b, b*2);
    else ret+= 0.5* f2(a*2, b-a);


    return ret;


}

int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        cnt=0;
        double rhs=f1(a,b);



        cnt=0;
        double expmoves= f2(a,b);


        printf("Case %d: %.6f %.6f\n",++tt,expmoves, rhs);

    }

}
