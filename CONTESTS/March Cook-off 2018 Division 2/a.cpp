#include<bits/stdc++.h>
#define pii pair<i64,i64>
#define inf 10000000000
#define i64 long long
using namespace std;

pii ara[105][105];
i64 res[105][105];
bool isFix[105][105];


void first_iter(i64 n, i64 m)
{
    i64 num=0;
    for(i64 i=0; i<n; i++)
    {

        i64 j=0;
        while(ara[i][j].first==-1 && j<m)
            j++;

        if(j==m) continue;

        num=ara[i][j].first;
        j++;


        for( ; j<m; j++)
        {
            while(ara[i][j].first==-1)
            {
                if(isFix[i][j]==0)
                    ara[i][j].first=num;
            }

            num=ara[i][j].first;

        }

    }


    for(i64 i=0; i<m; i++)
    {

        i64 j=0;
        while(ara[j][i].second==-1 && j<n)
            j++;

        if(j==n) continue;

        num=ara[j][i].second;
        j++;


        for( ; j<n; j++)
        {
            while(ara[j][i].second==-1)
            {
                if(isFix[j][i]==0)
                    ara[j][i].second=num;
            }

            num=ara[j][i].second;

        }

    }

}


void second_iter(i64 n, i64 m)
{
    for(i64 i=0; i<n; i++)
    {

        i64 mx=res[i][0];
        for(i64 j=0 ; j<m; j++)
        {
            if(res[i][j]<mx && isFix[i][j]==0)
                    res[i][j]=mx;
                else mx=res[i][j];
        }
    }


    for(i64 i=0; i<m; i++)
    {
        i64 mx=res[0][i];
        for(i64 j=0; j<n; j++)
        {
            if(res[j][i]<mx && isFix[j][i]==0)
                res[j][i]=mx;
            else mx=res[j][i];
        }

    }



}


i64 check(i64 n, i64 m)
{
    for(i64 i=0; i<n; i++)
    {
        for(i64 j=0 ; j<m-1; j++)
        {
            if(res[i][j]>res[i][j+1])
            {
               // puts("from here?");
                return -1;
            }
        }
    }

    for(i64 i=0; i<m; i++)
    {

        for(i64 j=0; j<n-1; j++)
        {
            if(res[j][i]>res[j+1][i])
            {
                //printf("%lld %lld\n",res[j][i],res[j+1][i]);
                return -1;
            }
        }

    }



    return 1;
}
int main()
{

    i64 tt;
    cin>>tt;

    while(tt--)
    {

        i64 n,m,x;
        cin>>n>>m;

        for(i64 i=0; i<n; i++)
        {
            for(i64 j=0; j<m; j++)
            {
                cin>>x;
                ara[i][j]= {x,x};
                if(x!=-1)
                    isFix[i][j]=1;
            }
        }

//ara[i][j]=1;


        first_iter(n,m);



        for(i64 i=0; i<n; i++)
        {
            for(i64 j=0; j<m; j++)
            {
                //printf("%lld,%lld  ",ara[i][j].first, ara[i][j].second);
                i64 rest=max(ara[i][j].first,ara[i][j].second);

                if(rest==-1)
                    res[i][j]= 1;
                else
                    res[i][j]=rest;

                //printf("%lld %lld\n",ara[i][j].first,ara[i][j].second);
            }

        }


        second_iter(n,m);

        if(check(n,m)==-1)
            printf("-1\n");
        else
        {


            for(i64 i=0; i<n; i++)
            {
                for(i64 j=0; j<m; j++)
                {
                    if(j) printf(" ");
                    printf("%lld",res[i][j]);
                }
                puts("");
            }

        }


        memset(ara,0,sizeof ara);
        memset(res,0,sizeof res);
        memset(isFix,0,sizeof isFix);


    }



    return 0;

}
