#include<bits/stdc++.h>
using namespace std;
#define ll long long
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}


pair < int, int > p[4000000];
map< double, int > m;
map<  double, int > ::iterator it;

int main()
{


    int n,i,x,y,j,flag=0,num;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d %d",&p[i].first, &p[i].second);
        if(p[i].first==0 && p[i].second==0) flag=1;
    }

    puts(" ");
    for(i=0; i<n; i++)
    {
        if(p[i].first==-1000000) continue;

        for(j=i+1; j<n; j++)
        {
            double numx;
            int y= p[j].second-p[i].second;
            int x= p[j].first- p[i].first;

            if(x==0 ) numx=100000;
            else
            numx= (y*1.0)/x;

            cout<<numx<<endl;
            m[numx]++;


        }

    }

    ll total=0;
    num=n;
    total= (num*(num-1)*(num-2) )/6;


    for(it= m.begin() ; it!=m.end(); it++)
    {
        num=0;
        printf("%f =%d\n", it->first, it->second);

        if(it->second>2)
            num=it->second;


        total=total- (num*(num-1)*(num-2) )/6;
    }

    printf("%lld\n",total);
    return 0;

}

