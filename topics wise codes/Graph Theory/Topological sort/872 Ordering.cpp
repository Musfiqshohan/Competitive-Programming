#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

int indegree[30];
int exist[30], vis[30],ara[30];
int n,flag=0;
vector<int>adj[30];
void f(string str, int num)
{

    if(num==n)
    {
        cout<<str<<endl;
        return;
    }

    for(int k=0; k<n; k++)
    {
        int i=ara[k];



        if(vis[i]==0 && indegree[i]==0)
        {
            flag=1;
            vis[i]=1;
            int src=i;


            str+=(i+'A');
            if(num<n-1) str+=" ";


            if(adj[src].size()==0) f(str,num+1);
            else
            {

                for(int j=0; j<adj[src].size(); j++)
                {
                    int node= adj[src][j];

                    indegree[node]--;

                }


                f(str, num+1);



                for(int j=0; j<adj[src].size(); j++)
                {
                    int node= adj[src][j];

                    indegree[node]++;
                }

            }



            str.erase(str.size()-1);
            str.erase(str.size()-1);

            vis[i]=0;



        }

    }

}



int main()
{

//    freopen("input872.txt", "r", stdin);
//    freopen("output872.txt", "w", stdout);

    int test;
    cin>>test;
    getchar();
    getchar();

    while(test--)
    {


        int x,y,m;

        string s1,s2;
        getline(cin,s1);
        getline(cin,s2);



        n=0;

        for(int i=0; i<s1.length(); i+=2)
        {
            x= s1[i]-'A';
            ara[n]=x;

            exist[x]=1;
            n++;
        }

        for(int i=1; i+1<s2.length(); i+=4)
        {
            x=s2[i-1]-'A';
            y=s2[i+1]-'A';
            adj[x].push_back(y);
            indegree[y]++;

        }


        f("",0);
        if(flag==0) printf("NO\n");

        for(int i=0; i<=n; i++) adj[i].clear();
        ms(exist,0);
        ms(vis,0);
        ms(indegree,0);
        flag=0;

        if(test>0) puts("");
        getchar();


    }


    return 0;
}
