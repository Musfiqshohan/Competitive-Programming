#include<bits/stdc++.h>
#define ll long long
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int main()
{
    int n,k,t;
    scanf("%d %d %d",&n,&k,&t);

    int tot=0;

    if(t<=k) { printf("%d\n",t);  }
    else
    {
        if(t>k && t<=n)
        {
            tot=k;
        }
        else
            tot= k-(t-n);

        printf("%d\n",tot);
    }


}
