#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;
string str;
char strr[1000009];

vector<int> vec[28];

int main()
{
    int n,k,x;
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++)
    {
        cin>>str>>k;

        for(int j=0; j<k; j++)
        {
            scanf("%d",&x);
            for(int s=0; s<str.length(); s++)
            {
                vec[str[s]-97].push_back(x++);
               // printf("->%d\n", str[s]-97);
            }

        }

        getchar();
    }

    int mx=0;

    for(int i=0; i<26; i++)
    {
        for(int j=0; j<vec[i].size(); j++)
           {
             strr[vec[i][j]]=i+97;
              // printf("%c\n",i+97);
           //   printf("%d ",vec[i][j]);
               mx= max(mx,vec[i][j]);
           }
    }


    for(int i=1;i<=mx;i++)
    {
        if(strr[i])
        printf("%c",strr[i]);
        else printf("a");
    }
    puts("");
    return 0;
}
