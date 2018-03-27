#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int ara[305][305];
int n;
void floydWarshall()
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                ara[i][j]= min(ara[i][j], ara[i][k]+ ara[k][j]);

    int tot=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            tot+=ara[i][j];
           // printf("%d ",ara[i][j]);
        }
       // puts("");

    }
    printf("%d ",tot);
}

int main()
{

    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            scanf("%d",&ara[i][j]);
    }

    int k,a,b,l;
    cin>>k;

    for(int i=0; i<k; i++)
    {
        cin>>a>>b>>l;

        ara[a][b]= min(ara[a][b], l);
        ara[b][a]= min(ara[b][a], l);
        floydWarshall();
    }



    return 0;
}

