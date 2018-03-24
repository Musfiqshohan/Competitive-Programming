#include<bits/stdc++.h>
#define i64 long long
using namespace std;

vector<int>v1,v2,temp;

int ara[100009];
int update(int src, int len, int val)
{
    printf("src=%d len=%d val=%d\n",src,len,val);
    while(len--)
    {
        if(ara[src]==0 && val==1) return src;
        ara[src++]=val;
    }

    return -1;
}
int main()
{
    memset(ara,-1,sizeof ara);

    int x1,x2,x;
    cin>>x1>>x2;

    int n,m, mx=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        v1.push_back(x);
        mx=max(mx,x);
    }

    cin>>m;
    for(int i=0; i<m; i++)
    {
        scanf("%d",&x);
        v2.push_back(x);
        mx=max(mx,x);
    }

    if(x1>x2)
    {
        swap(x1,x2);
        swap(v1,v2);
    }

    x1+=5;


    int xx2=x2;
    for(int i=0; i<v2.size()-1; i++)
    {
        int dif=v2[i+1]-v2[i];
       // printf("xx2=%d  dif=%d\n",xx2,dif);
        update(xx2,dif,(i+1)%2);
        xx2+=dif;;
    }


  //  printf("mx=%d\n",mx+5);
    update(xx2, mx+5, v2.size()%2);
    xx2+= mx+5;


    int xx1=x1;

    for(int i=0; i<v1.size()-1; i++)
    {
        int dif=v1[i+1]-v1[i];
        int res=update(xx1,dif,(i+1)%2);
        if(res!=-1)
            printf("bumper tap at time %d\n",res);

        xx1+=dif;
    }

    int res=update(xx1,mx+5,v1.size()%2);
    if(res==-1)
        printf("safe and sound\n");
    else printf("bumper tap at time %d\n",res);
    xx1+=mx+5;

//
//    for(int i=x2; i<=mx+x2; i++)
//        printf("i=%d v=%d\n",i,ara[i]);
//
//    puts("");



    return 0;
}
