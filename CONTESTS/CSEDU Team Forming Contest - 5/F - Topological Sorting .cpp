#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

int mat[1009][1009], ara[1009];

int main()
{
    int n,m,x,y;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);

        mat[x][y]=1;
    }

    for(int i=1;i<=n;i++) scanf("%d",&ara[i]);


    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(mat[ara[j]][ara[i]]==1)
            {
                printf("NO\n"); return 0;
            }
        }
    }


    printf("YES\n");


  return 0;
}
