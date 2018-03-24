#include<bits/stdc++.h>
using namespace std;

const int MAX=100100;

string str;
struct info
{
    int x,y,z;
} T[4*MAX];

void init(int nd, int beg, int endd)
{
    if(beg==endd)
    {
        if(str[beg]=='x') T[nd].x=1;
        if(str[beg]=='y') T[nd].y=1;
        if(str[beg]=='z') T[nd].z=1;
        return ;
    }


    int lc=nd*2;
    int rc=nd*2+1;

    int mid= (beg+endd)/2;

    init(lc,beg,mid);
    init(rc,mid+1,endd);

    T[nd]= {T[lc].x+T[rc].x, T[lc].y+T[rc].y, T[lc].z+T[rc].z };
}


info query(int nd, int beg, int endd, int x, int y)
{
    if(beg>y || endd<x) return {0,0,0};
    if(beg>=x && endd<=y) return T[nd];

    int lc=nd*2;
    int rc=nd*2+1;

    int mid= (beg+endd)/2;

    info l= query(lc,beg,mid,x,y);
    info r= query(rc, mid+1, endd, x,y);

    return {l.x+r.x, l.y+r.y, l.z+r.z};
}

int main()
{

    cin>>str;
    int n=str.size();
    int x,y;

    init(1,0,n-1);

    int q;
    cin>>q;

    while(q--)
    {
        cin>>x>>y;
        if(y-x+1<3) { printf("YES\n"); continue; }

        info res=query(1,0,n-1, x-1, y-1);
       // cout<<res.x<<" "<<res.y<<" "<<res.z<<endl;
        vector<int>vec= {res.x, res.y, res.z};
        sort(vec.begin(),vec.end());

        int t1= vec[0]==vec[1] && vec[2]==vec[1]+1;
        int t2= vec[1]==vec[2] && vec[1]==vec[0]+1;
        int t3= vec[0]==vec[1] && vec[1]==vec[2];

        if(t1+t2+t3>0)
            printf("YES\n");
        else printf("NO\n");

    }




    return 0;
}
