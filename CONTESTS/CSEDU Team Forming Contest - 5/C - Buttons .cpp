#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

int main()
{
   // for(int m=3;m<=100;m++) {

    int n;
   // printf("%d ->",m);
    scanf("%d",&n);

    if(n%3==0) printf("2\n");
    else if(n%4==0) printf("3\n");

    else
    {


        while(n%2==0)
            n/=2;

        while(n%3==0)
            n/=3;

        int root= sqrt(n);
        int flag=0;

        for(int i=5; i<=root; i++)
        {
            if(n%i==0)
            {
                printf("%d\n",i-1);
                flag=1;
                break;// return 0;
            }
            root=sqrt(n);
        }

        if(n!=1 && flag==0)
        {
            printf("%d\n",n-1);

        }

    }

    //}

    return 0;
}
