#include<bits/stdc++.h>
using namespace std;


int N,S;
struct info
{
    int s,a,b;
} ara[100009];

struct data
{
    int p1,p2,h;
};


data add(data a, data b)
{
    return {a.p1+b.p1, a.p2+b.p2, a.h+b.h };
}

data compare(data a, data b)
{
    int slcs1=0, slcs2=0;
    slcs1+=ceil((a.p1*1.0)/S);

    slcs2+=ceil((b.p2*1.0)/S);

    if(slcs1<slcs2)
    {
        return a;
    }
    else if(slcs1>slcs2)
        return b;

    else
    {
        if(a.h>b.h)
            return a;
        else return b;
    }

}
data f(int pos)
{
    if(pos==N) return {0,0,0};


    data t1,t2;

    int si,ai,bi;
    si= ara[pos].s;
    ai=ara[pos].a;
    bi=ara[pos].b;

    t1= {si, 0, si*ai};

    data ret1= f(pos+1);
    t1= add(t1,ret1);

    t2= {0, si, si*bi};
    t2= add(t2,ret1);

    data rr= compare(t1,t2);


    return rr;


}
int main()
{

    scanf("%d %d",&N,&S);

    for(int i=0; i<N; i++)
    {
        scanf("%d %d %d",&ara[i].s, &ara[i].a, &ara[i].b);
    }


    data ret= f(0);
    cout<<ret.p1<<" "<<ret.p2<<" "<<ret.h<<endl;



    return 0;
}
