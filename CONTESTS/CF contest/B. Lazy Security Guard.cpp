#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    scanf("%d",&n);

    int r= sqrt(n);

    int ex= n- r*r;
    int tot=0;


    tot= 2* r;

    if(ex==0) tot*=2;
    else if(ex<=r)
        tot+=2+r+r;
    else
        tot+= 2 + r  + 2+ r;


    cout<<tot<<endl;

}

