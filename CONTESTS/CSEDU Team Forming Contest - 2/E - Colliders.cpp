#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;
pair<int,int>prime[100009];
int ara[100009];
int keep(int n)
{
    int m=n;
    int root=sqrt(m);

    for(int i=2; i<=root; i++)
    {
        if(m%i==0)
        {
            int cnt=0;
            while(m%i==0)
            {
                m/=i;
                cnt++;
            }
            if(prime[i].first!=0)   return prime[i].second;

        }

        root=sqrt(m);
    }
    if(m!=1)
    {
        if(prime[m].first!=0)  return prime[m].second;
    }

    m=n;
    root=sqrt(m);
    for(int i=2; i<=root; i++)
    {
        if(m%i==0)
        {
            int cnt=0;
            while(m%i==0)
            {
                m/=i;
                cnt++;
            }
            prime[i].first=1;
            prime[i].second=n;

        }

        root=sqrt(m);
    }
    if(m!=1)
    {
        prime[m].first=1;
        prime[m].second=n;
    }

    return -1;
}

void decres(int n)
{
    int m=n;
    int root=sqrt(m);

    for(int i=2; i<=root; i++)
    {
        if(m%i==0)
        {
            int cnt=0;
            while(m%i==0)
            {
                m/=i;
                cnt++;
            }
            prime[i].first=0;
            prime[i].second=0;

        }

        root=sqrt(m);
    }
    if(m!=1)
    {
        prime[m].first=0;
        prime[m].second=0;
    }

}

void f(char sign, int num)
{
    if(sign=='+')
    {
        if(ara[num]==1) printf("Already on\n");
        else if(keep(num)==-1) { printf("Success\n");  ara[num]=1; }
        else printf("Conflict with %d\n", keep(num));
    }
    else
    {
        if(ara[num]==0) printf("Already off\n");
        else {decres(num);  printf("Success\n");  ara[num]=0; }
    }

}

int main()
{
    int n,m,num;
    char sign;
    scanf("%d %d",&n,&m);
    getchar();

    for(int i=0; i<m; i++)
    {
        scanf("%c %d",&sign, &num);
        getchar();

        f(sign, num);
    }

    return 0;
}
