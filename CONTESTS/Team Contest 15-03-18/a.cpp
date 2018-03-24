#include<bits/stdc++.h>
#define i64 long long
#define ms(a,b) memset(a,b,sizeof a)
#define pii pair<int,int>

using namespace std;
int main()
{
    int x,y,n;
    cin>>x>>y>>n;

    for(int i=1;i<=n;i++)
    {
        if(i%x==0)
            printf("Fizz");
        if(i%y==0)
            printf("Buzz");

        if(i%x!=0 && i%y!=0)
        printf("%d",i);
        puts("");
    }
}

