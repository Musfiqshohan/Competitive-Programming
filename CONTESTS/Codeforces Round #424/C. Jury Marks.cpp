#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

int a[2009],b[2009],sum[2009];

map<int,int>mp;
map<int,int>mp2;
vector<int>vec;
int k,n;
int f(int indx, int x)
{
    for(int i=1; i<=n; i++)
    {

        int points= b[i]-x;

        printf("point= %d bi=%d x=%d  indc=%d i=%d\n",points, b[i],x, indx,mp[points]);
        if(mp[points]==0) return 0;
        else if(mp[points]!=0 && mp[points]<indx) return 0;

    }


    return 1;
}


int main()
{

    scanf("%d %d",&k,&n);

    for(int i=1; i<=k; i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]=i;
        sum[i]=a[i]+sum[i-1];
    }

    for(int i=1; i<=n; i++) scanf("%d",&b[i]);

    int total=0;
    for(int i=1; i<=k; i++)
    {
        int x= b[1]-sum[i];

        if(f(i,x)==1)
        {
          //  printf("Hi\n");
            if(mp.find(x)==mp.end()) {total++; mp[x]=1; }
        }
    }

    //sort(vec.begin(), vec.end)


    printf("%d\n",total);
    return 0;
}
