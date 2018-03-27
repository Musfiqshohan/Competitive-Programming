///http://www.spoj.com/problems/ZQUERY/en/

#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define loop(i,n) for(int i=0;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

int b_size;

pii store;

void preprocess()
{
    int b_no=(n+b_size-1)/b_size;

    for(int i=0;i<b_no;i++)
    {
        for(int j=i*b_size; j<n;j++)
        {
            int num=cum[j];
            if(isOn[num]==0)
            {   isOn[num]=j;
            }
            else if(isOn[num])
            prev[j]=
        }
    }

}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    b_size=sqrt(n);

    for(int i=0;i<n;i++)
        scanf("%d",&ara[i]);

    for(int i=1;i<n;i++)
        cum[i]=cum[i-1]+ara[i];

    preprocess();



    return 0;
}
