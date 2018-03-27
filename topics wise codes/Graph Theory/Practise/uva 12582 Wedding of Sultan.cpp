#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

string str;
vector<int>vec;
set<int>Set;

int trails[28];
int pos;

void dfs(int pr)
{

    //printf("%d %d\n",pos, pr);
    int start=pos;
    pos++;
    trails[pr]=1;
    while(vec[pos]!=vec[start])
    {
        trails[pr]++;
        int node= vec[pos];
        dfs(node);
        pos++;
    }
}


int main()
{
    int test,t=0;
    cin>>test;

    while(t<test)
    {
        printf("Case %d\n",++t);

        pos=0;

        cin>>str;
        for(int i=0; i<str.length(); i++)
        {
            int x= str[i]-'A';
            Set.insert(x);
            vec.push_back(x);
        }


        dfs(vec[0]);

        set<int>::iterator it;
        for(it=Set.begin(); it!=Set.end(); it++)
        {
            int x= (*it);
            if(x==vec[0])
                trails[x]--;

            printf("%c = %d\n",x+'A', trails[x]);
        }

        vec.clear();
        Set.clear();
        memset(trails,0,sizeof trails);


    }

}
