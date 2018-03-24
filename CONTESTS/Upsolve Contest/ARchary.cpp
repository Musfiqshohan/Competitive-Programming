#include<bits/stdc++.h>
#define pii pair<int,int>
#define inf 10000000000
#define ui unsigned int
#define i64 long long
#define PI acos(-1)
using namespace std;

struct point
{
    int x,y,f;
};
vector<point>pnt;

int vis[105];
double EXPM(point p1, point p2,int cnt)
{
    double ang=atan2(p2.y-p1.y,p2.x-p1.x)*180/PI;
    if(ang<0) ang+=360;

    double expv= (ang/360.0)*cnt;
    return expv;
}


int orientation(point p, point q, point r)
{
    int res= (q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x);

    if(res==0) return 0;
    return (res>0)? 1:2;  /// clock or counterclock wise
}


bool cmp(point a, point b)
{
    int o=orientation({0,0,0}, a,b);

    if(o==2)
        return true;
    else return false;
}

pii Find(point near)
{
    int cnt1=0,cnt2=0;
    for(int i=0; i<pnt.size(); i++)
    {
        if(orientation({0,0},near, pnt[i])==0)
        {
            vis[i]=1;
            if(pnt[i].f==1)
                cnt1++;
            else if (pnt[i].f==2)
                cnt2++;
        }
    }

    if(near.f==1) cnt1++;
    else cnt2++;


    return {cnt1,cnt2};
}

int main()
{
    point root={0,0,0};

    int n,x1,y1,x2,y2;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>x1>>y1>>x2>>y2;
        pnt.push_back({x1,y1,1});
        pnt.push_back({x2,y2,-1});
    }



    sort(pnt.begin(),pnt.end(),cmp);
    pnt.push_back(pnt[0]);

    //for(int i=0;i<pnt.size();i++)


    int cur=0;
    double tot=0;
    for(int i=0; i<pnt.size(); i++)
    {
        if(vis[i]==1) continue;
        pii r=Find(pnt[i]);

        printf("point %d,%d giving +%d-%d\n",pnt[i].x,pnt[i].y, r.first,r.second);

        cur=cur+ r.first-r.second;
        int j=i+1;
        while(orientation(root,pnt[i],pnt[j])==0)
            j++;

        printf("%d,%d -> %d,%d cur=%d\n",pnt[i].x,pnt[i].y, pnt[j].x, pnt[j].y,cur);

        tot+= EXPM(pnt[i],pnt[j],cur);
    }




    cout<<tot<<endl;







    return 0;
}
