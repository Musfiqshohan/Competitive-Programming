#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a)
#define inf 100000000
using namespace std;

bool isPower(int x,int y)
{
    int res1 = log(y) / log(x);
    double res2 = log(y) / log(x);   // Note : this is double

    // compare to the result1 or result2 both are equal
    return (res1 == res2);

}

bool isOk(int n)
{

    for(int i=1; i<=sqrt(n); i++)
    {
        if(isPower(i,n)) { printf return true;}
    }
    return false;

}

int main()
{

    for(int i=1; i<=1000; i++)
    {
        if(isOk(i)==true){
            printf("%d\n",i);

        double r=log(i);
      //  printf("%.8f\n",r);
        }
    }

}
