///https://odzkskevi.qnssl.com/c5d2892199bcbf84a85005a5defdf86b?v=1506007776
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>adj[1009];
vector<int>seq;
struct house
{
    int par, dem, dchord;
} ara[1009];

int parent[1009],fc[1009],sib[1009], dp[1009][105];
void dfs(int src, int pr)
{
    parent[src]=pr;
    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];
        if(node!=pr)
        {
            dfs(node,src);
        }
    }
}


int f(int src, int Rempower)
{

    if(src==-1) return 0;
//    printf("Src= %d Rempo= %d\n",src,Rempower);
    //if(Rempower<ara[src].dchord) return 0;

    if(dp[src][Rempower]!=-1) return dp[src][Rempower];

    int t1=0,t2=0,last1,last2;

    last1= min(Rempower, ara[src].dchord);
    last1=last1-ara[src].dem;
    int leftE1=Rempower-ara[src].dem;

    last2=min(Rempower,ara[src].dchord);
    int leftE2=Rempower;


  //  printf("src= %d last1= %d  last2= %d left1=%d left2=%d Rempo=%d\n",src, last1,last2,leftE1 , leftE2,Rempower);

    for(int i=0; i<=last1; i++)
    {
        t1=max(t1, 1+f(fc[src],i) + f( sib[src], leftE1-i) );
    }

    for(int i=0; i<=last2; i++)
    {
        t2=max(t2, f(fc[src], i) + f(sib[src], leftE2-i));
    }


    return dp[src][Rempower]=max(t1,t2);

}




int main()
{
    int n;
    scanf("%d",&n);



    for(int i=1; i<=n; i++)
    {
        scanf("%d %d %d",&ara[i].par, &ara[i].dem, & ara[i].dchord);
        adj[ara[i].par].push_back(i);
    }


    for(int i=0; i<adj[0].size(); i++)
    {

        int src= adj[0][i];
        dfs(src,-1);
    }

    memset(dp,-1,sizeof dp);
    memset(fc,-1,sizeof fc);
    memset(sib,-1,sizeof sib);

    for(int i=1; i<=n; i++)
    {
        seq.clear();
        for(int j=0; j<adj[i].size(); j++)
        {
            if(adj[i][j]!=parent[i])
                seq.push_back(adj[i][j]);
        }

        if(seq.size()) fc[i]=seq[0];

        for(int j=0; j+1<seq.size(); j++)
        {
            sib[seq[j]]=seq[j+1];
        }

    }




    int res=0;

    for(int i=0; i<adj[0].size(); i++)
    {
        int src= adj[0][i];

        res+= f(src,ara[src].dchord);

    }

    printf("%d\n",res);





    return 0;
}

