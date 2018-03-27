#include<bits/stdc++.h>
using namespace std;

int ara[101][101][11], cum[101][101][11];

struct star
{
    int x,y,s;
}sara[100009];

int f(int x, int y, int mom)
{
    if(x<1 || y<1) return 0;

    if(cum[x][y][mom] !=-1) return cum[x][y][mom];

    int t1=f(x-1,y,mom);
    int t2=f(x,y-1,mom);
    int t3=f(x-1,y-1,mom);

    int res= t1+t2-t3 + ara[x][y][mom];

    return cum[x][y][mom]=res;

}

int main()
{
//    ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);

    int n,q,c;

    cin>>n>>q>>c;

    for(int i=0;i<n;i++)
    {
        cin>>sara[i].x>>sara[i].y>>sara[i].s;
    }


    for(int i=0;i<=c;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x=sara[j].x;
            int y=sara[j].y;
            int s=sara[j].s;
            s= (s+i)%(c+1);
            //cout<<s<<endl;
            ara[x][y][i]+=s;

          //  printf("x=%d y=%d s=%d\n",x,y,s);
        }
    }


//    for(int i=1;i<=5;i++)
//    {
//        for(int j=1;j<=5;j++)
//            printf("%d ",ara[i][j][3]);
//        puts("");
//    }

    memset(cum,-1,sizeof cum);

    for(int i=0;i<=c;i++)
    {
        cum[100][100][i]= f(100,100,i);
        //cout<<cum[100][100][i]<<endl;
    }


    int t,x1,y1,x2,y2;
    for(int i=0;i<q;i++)
    {
        cin>>t>>x1>>y1>>x2>>y2;
        t=t%(c+1);
        cout<<f(x2,y2,t) - f(x1-1,y2,t) - f(x2,y1-1,t) + f(x1-1,y1-1,t)<<endl;
    }



    return 0;
}
