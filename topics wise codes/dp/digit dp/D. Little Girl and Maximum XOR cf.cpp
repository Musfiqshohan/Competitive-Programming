#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector<int>bits1;
vector<int>bits2;


int DP(int pos, int isSmaller1, int i int isGreater)
{
    int a[3],b[3];

    if(isGreater) {  a[0]=1; a[1]=1 } else  a[bits1[pos]]=1;
    if(isSmaller) {  b[0]=1; b[1]=1 } else  b[bits2[pos]]=1;


    if( a[0]==1 && b[1]==1  )
    {
        DP(pos+1, isSmaller ,   isGreater );
    }
    else if( a[1]==1 && b[0]==1 )
    {
        DP(pos+1, isSmaller,   isGreater);
    }
    else
    {

    }

}


int f(int l, int r)
{
    while(l || r)
    {
        bits1.push_back(l%2);
        l/=2;
        bits2.push_back(r%2);
        r/=2;
    }

    reverse(bits1.begin(), bits1.end());
    reverse(bits2.begin(), bits2.end());

    int lim= max( bits1.size(), bits2.size() );

    DP();

}

int main()
{
    int l,r;
    scanf("%d %d",&l,&r);

    f(l,r);
}
