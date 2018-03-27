#include<bits/stdc++.h>
using namespace std;
int a[2010], dp[2010];
pair<int, int> power_set[35];
int grundy(int n)
{
    if(n%2==0) return n/2;
    int dif;
    for(int i=1;i<=30;i++)
    {
        dif= n- power_set[i].first;
        if(dif% power_set[i].second==0)
            return dif/power_set[i].second;
    }


    return -1;

}


int pow1(int x,int n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        int num=pow1(x,n/2);
        return num*num;
    }
    return x*pow1(x,n-1);
}

int main()
{
    int i;

    for( i=1;i<=30;i++)
    {
        power_set[i].first= pow1(2,i)-1;

        power_set[i].second=pow1(2,i)*2;
    }

    //for(i=1;i<=30;i++) printf("%d %d\n",power_set[i].first , power_set[i].second);


    int t=0,test;
    cin>>test;

    while(t<test){
    int n,i,xsum=0;

    scanf("%d",&n);


    for(i=0;i<n;i++)  scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        xsum^=grundy(a[i]);
    }

    printf("Case %d: ",++t);
    if(xsum==0) printf("Bob\n");
    else printf("Alice\n");


    }
    return 0;

}
