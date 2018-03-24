#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;
string str;
int K;
int findd(int i, int j)
{
    int cnt=0;
    for(int k=i; k<=j; k++)
    {
        if(str[k]=='1')
            cnt++;
    }

    printf("%d %d %d\n",i+1,j+1,cnt);
    if(cnt==K) return 1;
    else return 0;
}

int main()
{
    int n;
    scanf("%d %d",&n,&K);
    getchar();
    cin>>str;

    int l=str.length();
    cout<<l<<endl;
    int total=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            total+= findd(i,j);
        }
    }

    cout<<total<<endl;

    return 0;
}

