///https://www.codechef.com/problems/RWALK
///this is a problem mainly about subset sum optimized using bit set. but good observation is needed.

#include<bits/stdc++.h>
#define i64 long long
#define inf 1000000000000000000
using namespace std;

bitset<505*500>bset;
int h[505],v[505];

int f(int ara[], int n)
{

    int sum=0,mx=0;
   // printf("Inside=%d\n",n);
    for(int i=0; i<n; i++){
        sum+=ara[i];
         mx=max(mx,ara[i]);
       // printf("i=%d, %d ",i,ara[i]);
    }

   // puts("end");

    int mid=(sum+2-1)/2;

    bset.reset();

    bset.set(0);

    for(int i=0; i<n; i++)
        bset=bset|(bset<<ara[i]);


    for(int i=mid; i<=mx*n; i++)
        if(bset[i]==1)
            return i+i-sum;

    return -1;

}

int main()
{


//    int n;
//    cin>>n;
//    for(int i=0;i<n;i++)
//        scanf("%d",&h[i]);
//
//    cout<<f(h,n)<<endl;
//
//    return 0;

    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,nh=1,nv=0;

        scanf("%d",&n);


        scanf("%d",&h[0]);

        char ch;
        int x;
        for(int i=1; i<=n; i++)
        {
            cin>>ch>>x;
             //cout<<ch<<"-> "<<x<<endl;
            if(i%2==1)
                v[nv++]=x;
            else h[nh++]=x;

           // printf("i=%d v=%d, h=%d\n",i,v[i-1],h[i]);
        }


        if(n<3)
        {
            printf("NO\n");
            memset(v,0,sizeof v);
            memset(h,0,sizeof h);
            continue;
        }

        int t1=f(h,nh);
        int t2=f(v,nv);
        printf("%d\n",t1+t2);

        memset(v,0,sizeof v);
        memset(h,0,sizeof h);

    }


    return 0;
}
