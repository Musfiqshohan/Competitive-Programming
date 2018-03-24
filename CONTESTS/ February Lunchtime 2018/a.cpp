#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

int ara[105];
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,u,d;
        cin>>n>>u>>d;

        for(int i=0; i<n; i++)
            scanf("%d",&ara[i]);

        int tot=1,flag=0;
        for(int i=1; i<n; i++)
        {

            if(ara[i]>=ara[i-1] && ara[i]-ara[i-1]<=u){
              //  cout<<ara[i]-ara[i-1]<<endl;
                tot++;
            }
            else if(ara[i-1]>=ara[i] && ara[i-1]-ara[i]<=d)
                tot++;
            else if(ara[i-1]>ara[i])
            {
                if(flag==0)
                {
                    flag=1;
                    tot++;
                }
                else break;
            }
            else break;
        }

        cout<<tot<<endl;

    }
}

