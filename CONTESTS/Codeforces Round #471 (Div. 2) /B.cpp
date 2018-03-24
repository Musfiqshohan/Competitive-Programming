#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a)
#define inf 100000000
using namespace std;

set<char>s;
set<char>:: iterator it;
vector<int>v;

int ara[10000];
int main()
{
    string str;
    cin>>str;

    for(int i=0;i<str.size();i++)
    {
        s.insert(str[i]);
        ara[str[i]-'a']++;
    }

    int l=s.size();

    for( it=s.begin(); it!=s.end(); it++){
         char c=*it;
         int t=c-'a';
        // printf("%c %d %d\n",c,t,ara[t]);
         v.push_back(ara[t]);
    }

    sort(v.begin(),v.end());

  //  printf("%d\n",v.size());


    if(l==1 || l>4 || str.size()<=3)
        printf("No\n");
    else
    {
        if(l==2)
        {
            if(v[0]>1)
                printf("Yes\n");
            else printf("No\n");
        }
        else if(l==3)
        {
            printf("Yes\n");
        }
        else
        {
             printf("Yes\n");
        }

    }



}
