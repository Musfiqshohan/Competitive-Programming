#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

char s[5];
int components=0;
int par[30];
int n;

int findd(int r)
{
    if(par[r]==r) return r;
    return par[r]=findd(par[r]);
}

void unionn(int a,int b)
{
    int u=findd(a);
    int v= findd(b);

    if(u!=v)
    {
        par[u]=v;
        components--;
    }
}


int main()
{
    int t=0;
    cin>>t;
    scanf("\n");

    while(t--)
    {

        gets(s);
        n=s[0]-'A'+1;


        for(char i=0; i<n; i++)
            par[i]=i;

        components=n;

        while(gets(s) && s[0])
        {
            unionn(s[0]-'A', s[1]-'A');
        }

        cout<<components<<endl;
        if(t) cout<<endl;

    }

    return 0;
}
