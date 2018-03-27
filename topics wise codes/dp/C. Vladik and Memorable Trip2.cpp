#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

int ara[5009], Xor[5009][5009], CntArr[5009], CntArr2[5009];
int n;
pair<int,int>p[5009];

void makeArray()
{
    for(int i=0; i<n; i++)    CntArr[ara[i]]=1;
}

void findXor()
{
    for(int i=0; i<n; i++)
    {
        int xorr=0;
         ms(CntArr2,-1);

        for(int j=i; j<n; j++)
        {
            if(CntArr2[ara[j]]==-1)
            {
                xorr=xorr^ara[j];
                CntArr2[ara[j]]=1;

                // if(i==2) printf("%d %d\n",j,xorr);
            }

            Xor[i][j]=xorr;

            // printf("xorring %d %d= %d\n",i,j,xorr);

        }

    }
}

void findMnMx()
{
    for(int i=0; i<=5009; i++)
    {
        if(CntArr[i]==1)
        {
            int mx=0,mn=5009,j;

            for( j=0; ara[j]!=i; j++);
            mn=j;

            for(j=n-1; ara[j]!=i; j--);
            mx=j;

            p[i]= {mn,mx};
        }
    }
}

vector<pair<int,int>>range;

bool compare(pair<int,int>p1, pair<int,int>p2)
{
    if(p1.first==p2.first)
        return p1.second<p2.second;
    return p1.first<p2.first;
}
void buildRange()
{
    //for(int i=0;i<n;i++) range.push_back({ara[i],ara[i]});

    for(int i=0; i<=5009; i++)
    {
        if(CntArr[i]==1)
        {
            int mn=p[i].first, mx=p[i].second;
            for(int j=p[i].first+1 ; j<=p[i].second-1; j++)
            {
                if(ara[j]!=i)
                {
                    mn= min(mn,p[ara[j]].first);
                    mx= max(mx,p[ara[j]].second);


                }
            }

            range.push_back({mn,mx});
        }
    }

    sort(range.begin(), range.end(), compare);
}

int dp[5009][5009];

int f(int i, int endd)
{
    if(i==range.size() )
    {
        return 0;
    }

    if(endd!=-1 && dp[i][endd]!=-1) return dp[i][endd];

    int res1=0,res2=0,res3=0;

    if(endd<range[i].first)
    {
        // printf("%d ->at %d %d<%d\n",xor,i,endd,range[i].first);

        // printf("xor=%d index=%d  %d < %d \n", res1, i, endd, range[i].first);
        res1= Xor[range[i].first][range[i].second];
        res1+= f(i+1,range[i].second);


    }

    //printf("xxx\n");
    res2= f(i+1,endd);

    //printf("res1=%d res2=%d\n",res1,res2);
    return dp[i][endd]=max(res1,res2);

}

int main()
{
    memset(p,-1,sizeof p);
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);

    for(int i=0; i<n; i++) scanf("%d",&ara[i]);

    findXor();
    makeArray();
    findMnMx();
    buildRange();

    cout<<f(0,-1)<<endl;

    return 0;
}
