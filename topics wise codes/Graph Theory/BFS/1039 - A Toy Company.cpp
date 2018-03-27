#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

vector<string>rest[60];
map<string, int > mp;
int n;

void clearr()
{
    for(int i=0;i<n;i++)
        rest[i].clear();

    mp.clear();

}
int findd(char c, string str)
{
    if( str.find_first_of(c) != string::npos )
        return 1;

    return 0;
}

int check(string s)
{
    for(int i=0; i<n; i++)
    {
        if( findd(s[0],rest[i][0]) ==1 &&  findd(s[1],rest[i][1]) ==1 && findd(s[2],rest[i][2]) ==1 )
            return 1;
    }

    return 0;
}


void BFS(string src)
{
    queue<string>q;
    q.push(src);
    mp[src]=0;

    while(!q.empty())
    {
        string temp=q.front();
        q.pop();

        for(int i=0; i<3; i++)
        {
            string node= temp;

            node[i]= (((node[i]-'a')-1+26)%26 ) +'a';

            if( mp[node]==0 && check(node)==0)
            {
                // cout<<node<<endl;
                mp[node]=mp[temp]+1;
                q.push(node);

            }

        }

        for(int i=0; i<3; i++)
        {
            string node= temp;

            node[i]= (((node[i]-'a')+1+26)%26 ) +'a';

            if( mp[node]==0 && check(node)==0)
            {
                //   cout<<node<<endl;
                mp[node]=mp[temp]+1;
                q.push(node);

            }

        }



    }

}

int main()
{
    int tt=0,test;
    scanf("%d",&test);
    getchar();

    char s11[4],s22[4], t11[10000],t22[10000],t33[10000];
    while(tt<test)
    {

        string s1="",s2="",t1="",t2="",t3="";


        scanf("%s",&s11);
        getchar();
        scanf("%s",&s22);
        getchar();

        for(int i=0; s11[i]; i++)
            s1+=s11[i];

         for(int i=0; s22[i]; i++)
            s2+=s22[i];



       // cout<<s1<<" "<<s2<<" "<<n<<endl;


        scanf("%d",&n);
        getchar();

        for(int i=0; i<n; i++)
        {
           // cin>>t1>>t2>>t3;
            t1="",t2="",t3="";
            scanf("%s %s %s",&t11,&t22,&t33);
            //getchar();

            for(int k=0; t11[k]; k++)
                t1+=t11[k];

             for(int k=0; t22[k]; k++)
             t2+=t22[k];

             for(int k=0; t33[k]; k++)
              t3+=t33[k];

           // printf("%s %s %s\n",t11,t22,t33);

           // cout<<t1<<" "<<t2<<" "<<t3<<endl;

            rest[i].push_back(t1);
            rest[i].push_back(t2);
            rest[i].push_back(t3);
        }

        BFS(s1);

        printf("Case %d: ",++tt);
        if( check(s1)==1 || mp[s2]==0) printf("-1\n");
        else if(s1==s2) printf("0\n");
        else
            printf("%d\n",mp[s2]);


        clearr();
        getchar();

    }

    return 0;
}
