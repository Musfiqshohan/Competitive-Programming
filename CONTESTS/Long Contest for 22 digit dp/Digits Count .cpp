#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<i64,i64>
#define inf 1000000000000000000
using namespace std;

vector<int>vec,digs1, digs2;

struct info
{
    int ara[11];
    info()
    {
        memset(ara,0,sizeof ara);
    }
};

info* add(info* a, info* b)
{
    for(int i=0; i<10; i++)
        a->ara[i]+=b->ara[i];
    return a;
}

info* Sub(info* a, info* b)
{
    for(int i=0; i<10; i++)
        a->ara[i]-=b->ara[i];
    return a;
}

void print(info* a)
{
    for(int i=0; i<10; i++)
    {

        if(i) printf(" ");
        printf("%d",a->ara[i]);
    }
    puts("");

}

info* dp[10][5][5][11];
bool vis[10][5][5][11];
info* f(int pos, int isStart, int isSmaller, int n)
{
    //printf("%d %d %d\n",pos,isSmaller,n);
    if(pos==n)
    {
      //  printf("root=%d\n",sum);
        info* rt= new info();
        return rt;
    }

//   if(vis[pos][isStart][isSmaller][n]==1) return dp[pos][isStart][isSmaller][n];
        vis[pos][isStart][isSmaller][n]=1;

    int st= isStart? 1:0;
    int ses= isSmaller? 9: vec[pos];

    info* tot= new info();
    for(int i=st; i<=ses; i++)
    {

        info* ret=f(pos+1,0, isSmaller| i<ses,n);

        int L=vec.size();

        if(isSmaller| i<ses)
        {
            ret->ara[i]+=digs2[L-n+pos+1];
            printf("pos=%d  n=%d  ones=%d\n",pos,n,ret->ara[1]);
        }
        else
        {
            ret->ara[i]+=digs1[L-n+pos+1];
        }

        tot=add(tot,ret);
    }



    dp[pos][isStart][isSmaller][n]=new info();
    return dp[pos][isStart][isSmaller][n]=tot;
}

info* Solve(int n)
{

    vec.clear();
//    digs1.clear();
//    digs2.clear();
    int tot1=0,tot2=1, d=1;
    while(n)
    {
        vec.push_back(n%10);

        tot1=(n%10*d)+tot1;
        d*=10;
        tot2*=10;
        digs1.push_back(tot1+1);
        digs2.push_back(tot2);

        n/=10;
    }




    reverse(vec.begin(),vec.end());
    reverse(digs1.begin(),digs1.end());
    reverse(digs2.begin(),digs2.end());

    digs1.push_back(1);  ///changed here
    digs2.push_back(1);


    int l=vec.size();

    info* tot=new info();
    info* ret=f(0,1,0,l);
    print(ret);
    tot=add(tot,ret);
    while(l--)
    {
        memset(vis,0,sizeof vis);
        printf("l=%d\n",l);
        info* ret=f(0,1,1,l);
        print(ret);
        tot=add(tot,ret);
    }

    tot->ara[0]++;
    return tot;

}


info* count_dig(int n)
{
    info* t=new info();
    for(int i=0; i<=n; i++)
    {
        int m=i;
        while(m)
        {
            t->ara[m%10]++;
            m/=10;
        }
        // printf("%d\n",i);
    }

    t->ara[0]++;
    return t;
}

int main()
{
    int a,b;
     // scanf("%d %d",&a,&b);
    scanf("%d",&b);

    info* test=count_dig(b);
    print(test);
    memset(vis,0,sizeof vis);
    info* t1=Solve(b);
//    memset(vis,0,sizeof vis);
//    info* t2=Solve(a-1);
//
//    info* res=Sub(t1,t2);
    print(t1);

}
