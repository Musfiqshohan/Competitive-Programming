///https://vjudge.net/contest/212862#problem/K
#include<bits/stdc++.h>
#define pii pair<int,int>
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;

const int MAXN=100009;
vector<pii>jokes[MAXN];
vector<int>last[MAXN],vec;

int T[MAXN*4];

void clr()
{
    for(int i=0; i<MAXN-2; i++)
        jokes[i].clear(), last[i].clear();
    vec.clear();
    ms(T,0);

}
void update(int nd, int beg, int en, int le, int re, int j)
{
    if(beg>re || en<le)
        return ;

    if(beg>=le && en<=re)
    {
        //   printf("->%d %d %d\n",beg,en,j);
        T[nd]=j;
        return ;
    }


    int mid=(beg+en)/2;
    int l=nd*2;
    int r=nd*2+1;

    if(T[nd])
    {
        T[l]=T[r]=T[nd];
        T[nd]=0;
    }


    update(l,beg,mid, le,re,j);
    update(r,mid+1,en, le,re,j);
}

int query(int nd, int beg,int en, int pos)
{

    //printf("%d %d %d T[nd]=%d\n",beg,en,pos,T[nd]);

    if(beg==en)
    {
        return T[nd];
    }


    int mid=(beg+en)/2;
    int l=nd*2;
    int r=nd*2+1;

    if(T[nd])
    {
        T[l]=T[r]=T[nd];
        T[nd]=0;
    }

    int res=0;
    if(pos<=mid)
        res=query(l,beg, mid, pos);
    else
        res=query(r,mid+1,en,pos);


    return res;
}


int BIT[MAXN+5], mxval=MAXN-5;
void update_bit(int idx, int val)
{
    while(idx<=mxval)
    {
        BIT[idx]+=val, idx+= idx&-idx;
    }
}



int query_bit(int idx)
{
    int ret=0;
    while(idx)
    {
        ret+=BIT[idx], idx-= idx&-idx;
        //  printf("%d %d\n",idx,ret);
    }
    return ret;

}



int main()
{
    int tt;
    cin>>tt;

    while(tt--)
    {


        int n,m,x,l,k;
        scanf("%d %d",&n,&m);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&x,&l,&k);
            if(jokes[l].size()==0)
                vec.push_back(l);

            jokes[l].push_back({max(1,x-k),min(x+k,n)});

            update(1,1,n, max(1,x-k), min(x+k,n), l);
        }


        for(int i=1; i<=n; i++)
        {
            int res=query(1,1,n, i);

            // printf("i=%d  res=%d\n",i,res);
            last[res].push_back(i);
        }



        int tot=0;
        for(int k=0; k<vec.size(); k++)
        {
            int i=vec[k];

            //  printf("jokesno %d\n",i);

            for(int j=0; j<jokes[i].size(); j++)
            {

                pii rng=jokes[i][j];

                update_bit(rng.first,+1);
                update_bit(rng.second+1, -1);
                // printf("j=%d  %d %d\n",i,rng.first,rng.second);
            }

            for(int j=0; j<last[i].size(); j++)
            {
                int r=query_bit(last[i][j]);
                //  printf("%d %d\n",last[i][j],r);
                if(r>1)
                    tot++;
            }

            memset(BIT,0,sizeof BIT);

        }


        cout<<tot<<endl;
        clr();

    }


}
