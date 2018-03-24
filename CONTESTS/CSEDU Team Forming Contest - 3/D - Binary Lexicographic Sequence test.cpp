#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;


vector<int>v;
int cnt=1;
void f(int n)
{
    v.clear();
    while(n)
    {
        v.push_back(n%2);
        n=n/2;
        //printf("hello\n");
    }

    reverse(v.begin(), v.end());



    if(v.size()>1)
    {
        for(int i=0; i<v.size()-1; i++)
        {
            if(v[i]==1 && v[i+1]==1) return;
        }

    }

    printf("%d->",++cnt);
    for(int i=0; i<v.size(); i++) printf("%d",v[i]);
    puts("");



}

int main()
{
    int n;

    scanf("%d",&n);

    printf("1->0\n");
    for(int i=1; i<=n; i++)
    {
       // printf("%d-> ",i+1);
        f(i);
    }

    return 0;
}
