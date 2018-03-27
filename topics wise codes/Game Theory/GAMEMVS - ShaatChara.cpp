#include<bits/stdc++.h>
using namespace std;
int a[10009];
int bin(int n)
{
    int cnt=0;
    while(n)
    {
        n=n/2;
        cnt++;
    }

    return cnt;
}
int main()
{
    int t=0,test;
    cin>>test;
    while(t<test)
    {

        int n,mx=0,cnt=0,x,xsum=0,i,m;
        scanf("%d",&n);
//        cout<<(n>>(m))<<endl;
//
//        continue;


      //  cout<<bin(n)<<endl;

        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            xsum^=a[i];

        }

        printf("Case %d: ",++t);
        int num=bin(xsum);

     //   printf("sum= %d %d\n",num,xsum);
        if(xsum==0)
        {
            printf("0\n");
            continue;
        }




        for(i=0; i<n; i++)
        {
           // printf("%d>>%d ->%d\n",a[i],num-1, a[i]>>(num-1) );
            if((a[i]>>(num-1))%2==1)
               {
                  // cout<<"divide"<<(a[i]>>(num-1))<<endl;
                   cnt++;

               }

        }

        printf("%d\n",cnt);

    }


    return 0;
}
