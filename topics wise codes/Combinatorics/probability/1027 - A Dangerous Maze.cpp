#include<bits/stdc++.h>

int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int t=0,test;
    scanf("%d",&test);
    while(t<test){
    int n,cnt=0,sum=0,i,x;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        sum+= abs(x);
        if(x>0) cnt++;
    }

    printf("Case %d: ",++t);
    if(cnt==0) printf("inf\n");
    else
    printf("%d/%d\n", sum/gcd(sum,cnt),  cnt/ gcd(sum,cnt));

    }

}
