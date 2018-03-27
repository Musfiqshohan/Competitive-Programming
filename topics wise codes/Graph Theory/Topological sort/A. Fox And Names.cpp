#include<bits/stdc++.h>
using namespace std;
vector<string>str;
vector<int>adj[200];
stack<int>stk;
int vis[200],parent[200],color[200],flag;

void dfs(int src)
{
    vis[src]=1;
    color[src]=1;
    for(int i=0;i<adj[src].size();i++)
    {
        int node=adj[src][i];
        if(vis[node]==0)
        {
          //  printf("%c ->%c \n",src,node);
           // parent[node]=src;
            dfs(node);
        }
        else
        {
            // printf("QuaImpo  %c->%c\n",src,node);
            if( color[node]==1)   //node!=parent[src] &&
                {
                  //  printf("Impo  %c->%c\n",src,node);
                    flag=1;

                }
        }
    }
    color[src]=2;
    stk.push(src);
}
int main()
{
    int n,i,j;
    scanf("%d",&n);

    string x;

    for(i=0;i<n;i++)
    {
        cin>>x;
        str.push_back(x);
    }

    for(i=0;i<n-1;i++)
    {
        string s1=str[i];
        string s2=str[i+1];

        j=0;
        int mn= min(s1.length(),s2.length());
        while(j<mn &&  s1[j]==s2[j] ) j++;

        if(j<mn)
        {adj[s1[j]].push_back(s2[j]);

        // cout<<s1<<" "<<s1[j]<<" | "<<s2<<" "<<s2[j]<<endl;
        }
        else if(s1.length()>s2.length()) flag=1;


    }

    for(i=97;i<=122;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }

    if(flag==1) { printf("Impossible\n"); return 0; }
    while(!stk.empty())
    {
        printf("%c",stk.top());
        stk.pop();
    }

    puts("");

    //printf("%d\n",flag);


    return 0;
}
