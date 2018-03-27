#include<bits/stdc++.h>
using namespace std;
int main()
{
    int hh,mm;
    scanf("%d:%d",&hh,&mm);

    int mintangle= mm*6;

    if(hh>=12)
        hh-=12;

    int totmint=hh*60+mm;

 //   cout<<totmint<<endl;
    cout<<totmint*0.5<<" "<<mintangle<<endl;


    return 0;
}
