#include<iostream>
#include<algorithm>
#include<cassert>
#include<string>
#include<sstream>
#include<set>
#include<bitset>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<list>
#include<complex>
#include<functional>

using namespace std;
int a[2000], b[2000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
    int n,i,j,xsum=0;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a+1,a+n+1);
    b[0]= a[1]-1;
    i=1;
    for(i=1;i<n;i++)
    {
        b[i]=a[i+1]-a[i]-1;
    }



    for(j=i-1;j>=0;j-=2) { xsum^=b[j];  }

  //  printf("%d\n",xsum);

    if(xsum==0) printf("Bob will win\n");
    else printf("Georgia will win\n");
    }



    return 0;
}
