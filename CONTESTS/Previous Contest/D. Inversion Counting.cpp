///https://vjudge.net/contest/149387#problem/J
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

int ara[1505];
int Inversion(int x, int y)
{
    int res=0;
    for(int i=x; i<=y; i++)
    {
        for(int j=i+1; j<=y; j++)
        {
            if(ara[i]>ara[j])
                {res++;
                // printf("%d %d\n",i,j);
                }
        }
    }
    return res;
}


int main()
{
    int n,m,x,y;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        scanf("%d",&ara[i]);



    int tot=Inversion(0,n-1);
    cout<<tot<<endl;

    scanf("%d",&m);


    while(m--)
    {

        scanf("%d %d",&x,&y);
        x--,y--;
        int f1=x-0;
        int f2=n-1-y;
        int inv=0;
        if(f1+f2<(y-x+1))
        {
            int t1=Inversion(0,x-1);
            int t2=Inversion(y+1,n-1);

            inv=tot-(t1+t2);
             printf("1= %d -> %d\n",m,inv);

        }
        else
        {
            inv=tot-Inversion(x,y);
            printf("2= %d -> %d\n",m,inv);

        }



        if(inv%2==0)
            printf("even\n");
        else printf("odd\n");

    }
}
