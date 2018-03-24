#include<bits/stdc++.h>
#define pii pair<int,int>
#define inf 10000000000
#define i64 long long
using namespace std;


int main()
{
    int tt;
    cin>>tt;

    while(tt--)
    {
        int n,x;
        cin>>n;

        int mx1=0,mx2=0, s1=0,s2=0;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            s1+=x;
            mx1=max(mx1,x);
        }



        for(int j=0; j<n; j++)
        {
            cin>>x;
            s2+=x;
            mx2=max(mx2,x);
        }

        //cout<<s1-mx1<<" "<<mx2<<endl;


        if(s1-mx1<s2-mx2)
            printf("Alice\n");
        else if(s1-mx1>s2-mx2)
            printf("Bob\n");
        else printf("Draw\n");

    }

}
