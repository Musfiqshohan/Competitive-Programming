#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector<double>v1;
vector<double>v2;

double f(double mine, double r1, double  others, double r2, double total, double r3)
{
    //printf("%f %f %f %f %f %f\n", mine, r1, others, r2, total, r3);
    for(int i=r1;i>=1;i--)
    {
        v1.push_back(mine/i);
        mine--;
    }

    for(int i=r2;i>=1;i--)
    {
        v1.push_back(others/i);
        others--;
    }

    for(int i=r3;i>=1;i--)
    {
        v2.push_back(total/i);
        total--;
    }

    double sum=1;



    for(int i=0;i<v1.size();i++)
    {
       // printf("%f %f\n",v1[i],v2[i]);
        sum*= v1[i]/v2[i];
    }

    v1.clear();
    v2.clear();
    return sum;

}
int main()
{
    int n,m,h,x,total=0,mine;

    scanf("%d %d %d",&n,&m,&h);

    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);

        total+=x;
        if(i==h) mine=x-1;
    }

    total--;
    n--;

    if(total<n)   { printf("-1\n"); return 0; }
    if(n==0 || mine==0)  { printf("0\n"); return 0; }
    double sum=0;
    for(int i=1;i<=mine ;i++)
    {
       // if(mine<=0 || total-mine<=0 || n-i<=0 || total<=0 || n<=0) { printf("-1\n"); }
        sum+= f(mine,i, total-mine, n-i, total,n);
    }

    printf("%f\n",sum);
    //cout<<f(4,1 , 12, 4, 16, 5)<<endl;

    return 0;
}
