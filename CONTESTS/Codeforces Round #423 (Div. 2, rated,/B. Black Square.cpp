    #include<bits/stdc++.h>
    #define pb push_back
    #define ms(a,b) memset((a),(b),sizeof(a))
    //#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
    #define ll long long
    #define pii pair<ll,ll>
    #define inf 100000000000
    using namespace std;

    char ara[200][200];
    int main()
    {
        int n,m,black=0;
        int tot=0;
        cin>>n>>m;
        getchar();

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                scanf("%c",&ara[i][j]);
            getchar();
        }

        int mxcol=0,mxrow=0, mncol=500, mnrow=500;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(ara[i][j]=='B')
                {
                    mncol= min( mncol, j);
                    mxcol= max( mxcol, j);

                    mnrow= min( mnrow, i);
                    mxrow= max( mxrow, i);

                    black++;
                }
            }
        }

        int l1= mxcol-mncol +1;
        int l2= mxrow- mnrow +1;


      //  printf("l1= %d l2= %d\n",l1,l2);

        int len= max(l1,l2);

        if( (mnrow+len -1 >n && mxrow-len +1<1 ) || (mncol+len -1>m && mxcol-len +1<1 )) { printf("-1\n"); return 0; }


        if(l1>l2)
        {
            if(mnrow< n-mxrow+1)
            {
                for(int i=mnrow; i<=mnrow+len -1 ; i ++)
                {
                    if(mncol< m-mncol+1)
                    {
                        for(int j=mncol; j<= mncol+len -1; j++)
                            if(ara[i][j]=='W') tot++;
                    }
                    else
                    {
                        for(int j=mxcol; j>= mxcol-len +1 ; j--)
                            if(ara[i][j]=='W') tot++;
                    }
                }
            }

            else
            {
                for(int i=mxrow; i>=mxrow-len +1 ; i --)
                {
                    if(mncol< m-mncol+1)
                    {
                        for(int j=mncol; j<= mncol+len -1; j++)
                            if(ara[i][j]=='W') tot++;
                    }
                    else
                    {
                        for(int j=mxcol; j>= mxcol-len +1 ; j--)
                            if(ara[i][j]=='W') tot++;
                    }
                }

            }
        }

        else
        {
    //            printf("1= %d 2=%d\n",mncol, m-mxcol+1);
            if(mncol< m-mxcol+1)
            {
                for(int i=mncol; i<=mncol+len -1 ; i ++)
                {
                    if(mnrow< m-mnrow+1)
                    {
                        for(int j=mnrow; j<= mnrow+len -1; j++)
                            if(ara[j][i]=='W') tot++;
                    }
                    else
                    {
                        for(int j=mxrow; j>= mxrow-len +1 ; j--)
                            if(ara[j][i]=='W') tot++;
                    }
                }
            }

            else
            {
                for(int i=mxcol; i>=mxcol-len +1 ; i --)
                {
                    if(mnrow< m-mnrow+1)
                    {
                        for(int j=mnrow; j<= mnrow+len -1; j++)
                            if(ara[j][i]=='W') tot++;
                    }
                    else
                    {
                        for(int j=mxrow; j>= mxrow-len +1 ; j--)
                            if(ara[j][i]=='W') tot++;
                    }
                }

            }
        }


        //if(tot==0) printf("1\n");
        if(black==0) { printf("1\n"); return 0; }
         printf("%d\n",tot);
        return 0;
    }
