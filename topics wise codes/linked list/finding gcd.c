#include<stdio.h>

int gcd(int a,int b)
{
    if(b==0) return  a;

   // rem=a%b;
   // a=b;
   // b=rem;
    return gcd(b,a%b);
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    printf("%d\n",gcd(a,b));

}
