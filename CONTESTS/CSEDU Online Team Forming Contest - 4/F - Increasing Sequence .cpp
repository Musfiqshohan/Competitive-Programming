#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

int ara[3000];

int main()
{
    int n,d;
    scanf("%d %d",&n,&d);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&ara[i]);
    }

    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(ara[i]<=ara[i-1])
        {
            int num= (ara[i-1]-ara[i])/d;
            cnt+=num;
            if( ara[i]+ num*d <=ara[i-1]) {ara[i]= ara[i]+ (num+1)*d; cnt++;  }
            else ara[i]=ara[i]+ num*d;
        }
    }

    printf("%d\n",cnt);
    return 0;
}
