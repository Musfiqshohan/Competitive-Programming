#include<bits/stdc++.h>
#include<math.h>
using namespace std;

bool check(int n, int pos)
{
    return (bool)(n & (1 << pos));
}
int setx(int n, int pos)
{
    return n= n| (1<<pos);
}

int a[10000009];
int b[10000009];
int c[10000009];
int N=100000009;

int fnd(int low, int high, int target)
{
    int mid;

    while(low<=high)
    {
        mid= low+ (high-low)/2;

        if(target > c[mid]) low=mid+1;
        else if(target< c[mid]) high= mid-1;
        else {   return b[mid];  }
    }


    return b[high];
}

int main()
{
    int i,j,root;
    root= sqrt(N);

    for(i=3; i<=root; i+=2)
    {
        if( check( a[i>>5], i & 31 )==false)
        {
            for(j=i*i; j<=N ; j+=2*i)
                a[j>>5]=  setx( a[j>>5], j&31);

        }
    }


    double n,cnt=1;


    b[0]=1;
    c[0]=2;
    j=1;
    for(i=3; i<=(int)N; i+=2)
    {
        if( check( a[i>>5], i&31 )==false)
        {
            cnt++;
            b[j]=cnt;
            c[j]=i;
            j++;

        }
    }

    while(1){

    cin>>n;
    if(n==0) return 0;
    if(n>=2) cnt=1;


    int cnt= fnd(0,j,n);

    printf("%d\n",cnt);

    double num=  n/ log(n);
    num = fabs(num- cnt);
    num= num/ cnt;
    num= num*100;
    printf("%.1f\n",num);

    }

    return 0;
}
