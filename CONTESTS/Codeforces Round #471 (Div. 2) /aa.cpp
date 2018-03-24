#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a)
#define inf 100000000
using namespace std;

int main()
{
    int hh,mm,H,D,C,N;
    cin>>hh>>mm;

    cin>>H>>D>>C>>N;

    int st=hh*60+mm;
    int last=20*60;

    int d=max(0,last-st);

    double r1=ceil(H*1.0/N)*C;
    double r2=ceil((H+D*d)*1.0/N)*C*.80;

    printf("%.6f\n",min(r1,r2));


}
