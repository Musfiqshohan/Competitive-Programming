#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000099
using namespace std;

int ara[505][505], tax[505];
int nextt[505][505], taxa[505][505];

int main()
{
    int test=0;
    cin>>test;
    char s[505];

    getchar();
    getchar();


    while(test--){

    gets(s);
    stringstream sin(s);
    int n=1;

    while(sin>>ara[1][n])
        n++;
    n--;

    for(int i=2; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&ara[i][j]);

    for(int i=1; i<=n; i++) scanf("%d",&tax[i]);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            nextt[i][j]=j;

            if(ara[i][j]!=-1) taxa[i][j]=tax[j];
            if(ara[i][j]==-1) ara[i][j]=100000009;

        }

    }



    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if( (ara[i][k]+taxa[i][k]) + (ara[k][j]+taxa[k][j]) < (ara[i][j]+taxa[i][j]) )
                {
                    ara[i][j]=ara[i][k]+ara[k][j];
                    taxa[i][j]=taxa[i][k]+taxa[k][j];
                    nextt[i][j]=nextt[i][k];
                }
            }

    int start,endd,total=0;

    int flag=0;
    getchar();
    while(gets(s) && s[0])
    {

       if(flag==1) puts("");
        flag=1;
        sscanf(s,"%d %d",&start,&endd);

        total=ara[start][endd];

        printf("From %d to %d :\nPath: ",start,endd);
        if(start!=endd)
        printf("%d",start);
        if(start!=endd) printf("-->");

        start=nextt[start][endd];
        while(start!=endd)
        {
            printf("%d-->",start);
            total+=tax[start];
            start=nextt[start][endd];

        }

        printf("%d",endd);
        puts("");
        printf("Total cost : %d\n",total);

    }

    if(test)
        {puts("");
       // getchar();
        }

    }

    return 0;
}
