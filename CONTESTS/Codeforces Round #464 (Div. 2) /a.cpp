#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<int,int>
#define inf 100000000000

using namespace std;

int ara[5009];
int main()
{

    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>ara[i];
    }


    for(int i=1; i<=n; i++)
    {
        int x=ara[i];
        int y=ara[x];
        int z=ara[y];
        if(z==i)
        {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;

}
