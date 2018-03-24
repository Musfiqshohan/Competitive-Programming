#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    scanf("%d",&n);

    int r= sqrt(n);
    int p=r;

    int tot=0;
    if(r*r==n)
        tot=4*p;
    else{

        if( p*(p+1)>=n)
            tot= 2*(2*p+1);
        else tot=4*(p+1);
    }


    cout<<tot<<endl;

}

