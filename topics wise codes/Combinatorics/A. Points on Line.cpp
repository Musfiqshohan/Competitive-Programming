#include<bits/stdc++.h>
using namespace std;

int a[100009];
int bsrc(int low, int high, int target)
{
    int i=0,mid;
    while(i<32)
    {
        mid= low+ (high-low)/2;

        if(a[mid]>target)  high=mid-1;
        else if(a[mid]<target) low= mid+1;
        else if(a[mid]==target)  low=mid;
        i++;
    }

    return mid;
}
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int nCr(int n, int r)
{
    if(n<r) return 0;
    if(r==0) return 1;

    int total=0;

    int a[40],b[40],i,j;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    for(i=0; i<r ;i++) a[i]=n--;

    for(i=0; r ; i++) b[i]=r--;

    for(i=0; b[i] ; i++)
    {
        for(j=0; a[j] ; j++)
        {
            int x= gcd(a[j], b[i]);
            a[j]/=x;
            b[i]/= x;
            if(b[i]==1) break;
        }
    }

    int sum=1;
    for(i=0; a[i] ; i++) sum*=a[i];

    return sum;

}


int main()
{
    int n,d,i,total=0,last,num,index,s1,s2;
    scanf("%d %d",&n,&d);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    last=-1;

    for(i=0;i<n;i++)
    {
        while(a[i]+d<= a[last]) i++;
        num=a[i]+d;
        printf("%d  ",num);
        index= bsrc(last+1, n-1, num);
        cout<<index<<endl;

        s1= last-i+1;
        s2= index-i+1;
        last=index;
        total+= nCr( s1+s2 ,3) - nCr(s1,3);

         printf("%d %d %d\n",s1,s2, total);
        if(last==n-1) break;

    }

    printf("%d\n",total);
    return 0;
}
