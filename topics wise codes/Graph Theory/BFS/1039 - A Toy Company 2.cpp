#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

//vector<int [30]>rest[60];

int rest[60][3][30];
map<string, int > mp;
int n;

void clearr()
{

    ms(rest,0);

    mp.clear();

}



int check(string s)
{
    for(int i=0; i<n; i++)
    {
        //if( findd(s[0],rest[i][0]) ==1 &&  findd(s[1],rest[i][1]) ==1 && findd(s[2],rest[i][2]) ==1 )

        if( rest[i][0][ s[0]-'a']==1 &&  rest[i][1][ s[1]-'a' ]==1 && rest[i][2][ s[2]-'a' ]==1 )
            return 1;
    }

    return 0;
}




void create(int i, int att, string t1)
{
    //cout<<t1<<endl;

    for(int k=0;k<t1.length();k++)
    {
        //ara[ t1[i] - 'a' ] =1;

        rest[i][att][ t1[k]-'a'] =1;
       // printf("->%d %d %d %c\n",i, att, t1[k]-'a', t1[k]);
    }

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
    cin>>test;
    getchar();

    while(tt<test)
    {

        string s1,s2,t1,t2,t3;
        cin>>s1;
        cin>>s2;


        scanf("%d",&n);
//    cout<<s1<<" "<<s2<<" "<<n<<endl;
        getchar();

        for(int i=0; i<n; i++)
        {
            cin>>t1>>t2>>t3;

            create(i, 0, t1);
           create(i, 1, t2);
            create(i, 2, t3);

        }

        BFS(s1);

        //cout<<check(s1)<<endl;

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
