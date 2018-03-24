#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

struct tripple
{
    int left,right,  sum;
} ara[1000009];

string str,str1;
int n,K;
int srch1(int low, int high, int targ, int turn)
{
    int mid, cnt=0;
    while(cnt++<=26)
    {
        //printf("Hello\n");
        mid= low+ (high-low)/2;
        if(turn==1)
        {
            if(ara[mid].sum>=targ)
                high=mid;
            else
                low=mid+1;
        }
//        else
//        {
//            if(ara[mid].sum<=targ)
//                low=mid;
//            else high=mid-1;
//        }
    }

    if(turn==1)
    {
        if(ara[mid-1].sum==targ) return mid-1;
    }
    else
    {
        if(ara[mid+1].sum==targ) return mid+1;
    }
    return mid;

}

int Get()
{

    int total=0,start=1;
    while(start+K-1<=ara[n].sum)
    {
        int beg, endd;
        if(K>1)
        {
            beg= srch1(1,n,start,1);
            endd=srch1(1,n,start+K-1,1);
        }
        else
        {
            beg=srch1(1,n,start,1);
            endd=srch1(1,n,start,2);
        }



        printf("->->%d %d\n",ara[beg].left,ara[endd].right);
        total+= (ara[beg].left* ara[endd].right);

        if(K>1)
        start=start+K-1;
        else start++;
    }


    return total;
}

int main()
{

    scanf("%d %d",&n,&K);
    getchar();
    cin>>str1;
    str='A';
    str+=str1;
    //  cout<<str<<endl;
    str+='1';
    int index=0,i;
    for( i=1; i<=n+1; i++)
    {
        if(str[i]=='1')
        {
            //printf("hi %d\n",i);
            ara[i].left=i-index;
            ara[index].right=i-index;
            index=i;
        }
    }


    // for(int i=1;i<=n;i++) printf("%d -> %d %d\n",i,ara[i].left, ara[i].right);

    int cons=0;
    for(int i=1; i<=n; i++)
    {
        if(str[i]=='1')
        {
            cons++;
        }
        ara[i].sum= cons;
    }

    // for(int i=1;i<=n;i++) printf("%d ",ara[i].sum);

    puts("xxx");
    cout<<Get()<<endl;

    // cout<<srch1(1,n,2)<<endl;


    return 0;
}
