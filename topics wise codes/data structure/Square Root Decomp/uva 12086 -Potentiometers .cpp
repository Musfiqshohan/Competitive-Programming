#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define loop(i,n) for(int i=0;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;
int b_size;

int buckets[450], ara[200009];

void clearr()
{
    ms(buckets,0);
    ms(ara,0);
}
void make_bucket(int n)
{
    b_size= sqrt(n);

    int b_index=-1;
    for(int i=0; i<n; i++)
    {
        if(i%b_size==0)
            b_index++;

        buckets[b_index]+=ara[i];
    }

}


void update(int x, int val)
{
    int cur_buck= x/b_size;

    buckets[cur_buck]-=ara[x];
    ara[x]=val;
    buckets[cur_buck]+=ara[x];

}

int query(int l, int r)
{
    int sum=0;
    while(l<r && l%b_size!=0)
    {
        sum+= ara[l];
        l++;
    }

    while(l+b_size<=r)
    {
        sum+=buckets[l/b_size];

        l+=b_size;
    }


    while(l<=r)
    {
        sum+=ara[l];
        l++;
    }

    return sum;


}

int main()
{

    int n,test=0;
    while(scanf("%d",&n) && n!=0)
    {
        if(test)
            puts("");

        for(int i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);
        }

        make_bucket(n);

        char str[4];

        int x,r,l;

        getchar();

        printf("Case %d:\n",++test);
        while(scanf("%s",&str))
        {

            if(str[0]=='S')
            {
                scanf("%d %d",&x,&r);

                update(x-1,r);

            }
            else if(str[0]=='M')
            {
                scanf("%d %d",&l,&r);
                printf("%d\n",query(l-1,r-1));
            }
            else
                break;

            getchar();
        }


        clearr();

    }

    return 0;
}
