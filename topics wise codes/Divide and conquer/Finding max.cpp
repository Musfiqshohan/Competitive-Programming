#include<bits/stdc++.h>
using namespace std;

int f(int ara[], int n)
{

    if(n==2)
        return max(ara[0],ara[1]);
    if(n==1) return ara[0];

    int mid= n/2;
    int mx1= f(ara,mid);
    int mx2= f(ara+mid, n-mid);

    return max(mx1,mx2);

}

int main()
{
    int n;
    scanf("%d",&n);
    int ara[n+1];

    for(int i=0;i<n;i++)
        scanf("%d",&ara[i]);

    cout<<f(ara,n)<<endl;
}
