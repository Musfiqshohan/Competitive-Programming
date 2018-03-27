#include<bits/stdc++.h>
using namespace std;

bool check(int n, int pos){  return (bool)(n& (1<<pos)); }
int setx(int n, int pos) {   return n=n| (1<<pos); }

int N=1000009;
int ara[101009],b[100009];
void sieve()
{
    int i,j;

    int root=sqrt(N);
    for(i=3; i<=root; i+=2)
    {
        if( check(ara[i>>5], i&31)==false)
        {
            for(j=i*i; j<=N; j+=2*i)
                ara[j>>5]=setx(ara[j>>5], j&31);
        }
    }

    b[0]=2;
    j=1;
    for(i=3; i<=1000009; i+=2)
        if(check( ara[i>>5], i&31 )==false)
        {
            b[j]=i;
            j++;
        }
}

bool division( string a, int n)
{
    int num=0,i=0;
    while(i< a.length())
    {
        while(num<n && i<a.length())
        {
            int x= a[i]-'0';
            num=num*10+x;
            i++;
        }


        num=num%n;
    }

    if(num==0) return true;
    else return false;

}

int main()
{
    int n,i;
    string a;

    sieve();


    while(1){
    cin>>a;
    scanf("%d",&n);

    if(a[0]=='0' && n==0) return 0;

    if(a[a.length()-1]%2==0 && n!=2 ) { printf("BAD 2\n"); }

    else
    {
        int flag=0;
        for(i=0; b[i] <n ; i++)
        {

            if( division(a, b[i])==true) {printf("BAD %d\n",b[i]); flag=1;  break;  }

        }

        if(flag==0) printf("GOOD\n");

    }

    }




    return 0;
}
