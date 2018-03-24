#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ara[200009],cum[200009];
int main()
{

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%lld",&ara[i]);

    sort(ara,ara+n);


    cum[0]=ara[0];
    for(int i=1;i<n;i++)
    {
        cum[i]=cum[i-1]+ara[i];
    }


    ll tot1=0,tot2=0,cnt=0;
    for(int i=n-1;i>0;i--)
    {
        tot1+= cum[i];

        if(cnt%2==0)
            tot2+=cum[i];

        cnt++;


//        if(i-2>=0)
//            i--;

    }

    cout<<tot2<<endl;




    return 0;
}







//res=temp[i][j-1] ^ temp[i][j+1] ^  temp[i-1][j] ;





