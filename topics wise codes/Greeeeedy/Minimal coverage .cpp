#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

struct co_ord
{
    int l, r;
};
vector<co_ord>vec;

bool cmp(co_ord a, co_ord b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;
}

int main()
{

    //  out("output.txt");
    int test,t=0;
    scanf("%d",&test);

    while(t<test)
    {

        if(t) puts("");
        t++;


        int M,x,y;
        scanf("%d",&M);


        while(scanf("%d %d",&x,&y))
        {
            if(x==0 && y==0) break;
            vec.push_back({x,y});
        }

        vec.push_back({500009,500009});

        sort(vec.begin(),vec.end(),cmp);

        vector<co_ord>res;

        int mypos=0, mx=-1,mxi=-1,cnt=0;


        for(int i=0; i<vec.size(); i++)
        {
           // printf("-> %d %d %d\n",vec[i].l, vec[i].r, mypos);

            if(mypos>=M)
                break;

            if(vec[i].l>mypos)
            {
                mypos=mx;
                mx=-1;
                if(mxi>=0)
                {
                    // puts("hii");
                    cnt++;
                    res.push_back(vec[mxi]);
                }
            }


            if(vec[i].l<=mypos && mypos<=vec[i].r)
            {
                if(vec[i].r>mx)
                {
                    //puts("hee");
                    mx=vec[i].r;
                    mxi=i;
                }
            }


        }




        if(mypos>=M)
        {
            printf("%d\n",cnt);
            for(int i=0; i<res.size(); i++)
                printf("%d %d\n",res[i].l, res[i].r);
        }
        else
            printf("0\n");

        vec.clear();
        res.clear();

    }
    return 0;
}


/*
1
37
15 26
31 39
-9 2
7 29
-11 11
-20 1
19 26
14 33
0 0

1
37
57 63
15 26
67 69
31 39
39 63
56 81
-9 2
7 29
-11 11
47 51
-20 1
19 26
50 54
14 33
0 0
*/
