///https://vjudge.net/contest/212344#problem/A
#include<bits/stdc++.h>
#define  pb push_back
#define pii pair<int,int>
using namespace std;

struct rect
{
    int x,y,w,h,id;
} ara[50009];

vector<int>vx,vy,vw,vh, adj[50009];
map<int,int>mpx,mpy,mpw,mph;

set<pii>myset;
set<pii>::iterator it;

int mark[500][500];


void addEdge(int u, int v)
{
   // printf("%d->%d\n",u,v);
    myset.insert({u,v});
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void draw(rect a)
{
    for(int i=a.x; i<=a.x+a.w; i++)
    {
        addEdge(mark[a.y][i],a.id);
        addEdge(mark[a.y+a.h][i],a.id);
        mark[a.y][i]=a.id;
        mark[a.y+a.h][i]=a.id;
    }

    for(int i=a.y; i<=a.y+a.h; i++){

        addEdge(mark[i][a.x],a.id);
        addEdge(mark[i][a.x+a.w],a.id);
        mark[i][a.x]=a.id;
        mark[i][a.x+a.w]=a.id;
    }

}



void print()
{
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++)
            printf("%d",mark[i][j]);
        puts("");
    }

    puts("");
}


int main()
{

    //memset(mark,-1,sizeof mark);

    int n,x,y,w,h;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d %d",&x,&y,&w,&h);
        ara[i]= {x,y,w,h,i};
        vx.pb(x);
        vy.pb(y);
        vw.pb(w);
        vh.pb(h);
    }

    sort(vx.begin(),vx.end());
    sort(vy.begin(),vy.end());
    sort(vw.begin(),vw.end());
    sort(vh.begin(),vh.end());

    int cnt=1;
    for(int i=0; i<vx.size(); i++)
    {
        if(mpx.find(vx[i])==mpx.end())
            mpx[vx[i]]=cnt++;
    }

    cnt=1;
    for(int i=0; i<vy.size(); i++)
    {
        if(mpy.find(vy[i])==mpy.end())
            mpy[vy[i]]=cnt++;
    }

    cnt=1;
    for(int i=0; i<vw.size(); i++)
    {
        if(mpw.find(vw[i])==mpw.end())
            mpw[vw[i]]=cnt++;
    }

    cnt=1;
    for(int i=0; i<vh.size(); i++)
    {
        if(mph.find(vh[i])==mph.end())
            mph[vh[i]]=cnt++;
    }



    for(int i=0; i<n; i++)
    {
        ara[i].x=mpx[ara[i].x];
        ara[i].y=mpy[ara[i].y];
        ara[i].w=mpw[ara[i].w];
        ara[i].h=mph[ara[i].h];
    }


    for(int i=0; i<n; i++)
    {

      //  printf("->%d %d %d %d\n",ara[i].x,ara[i].y,ara[i].w,ara[i].h);
        draw(ara[i]);
        print();
    }


    for(it=myset.begin();it!=myset.end();it++)
    {
        pii t=*(it);
        printf("%d -> %d\n",t.first,t.second);
    }

//    for(int i=0; i<20; i++)
//    {
//        for(int j=0; j<20; j++)
//            printf("%d",mark[i][j]);
//        puts("");
//    }




    return 0;
}
