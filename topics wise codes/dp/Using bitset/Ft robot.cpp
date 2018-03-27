///https://www.codechef.com/problems/RWALK
///this is a problem mainly about subset sum optimized using bit set. but good observation is needed.

#include<bits/stdc++.h>
#define i64 long long
#define inf 1000000000000000000
using namespace std;

bitset<505*500>bset;

vector<int>h,v;

int f(vector<int>ara, int targ)
{

    int sum=0,mx=0;
    // printf("Inside=%d\n",n);
    for(int i=0; i<ara.size(); i++)
    {
        sum+=ara[i];
        mx=max(mx,ara[i]);
         printf("i=%d, %d \n",i,ara[i]);
    }

    // puts("end");

    //int mid=(sum+2-1)/2;

    bset.reset();

    bset.set(0);

    for(int i=0; i<ara.size(); i++)
        bset=bset|(bset<<ara[i]);


    for(int i=mid; i<=mx*n; i++){

        if(2*i-sum==abs(targ)){

            return bset[i];
        }
    }

    return 0;

}

int main()
{

    string str;
    int x,y;
    cin>>str;
    scanf("%d %d",&x,&y);

    int flag=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='T')
        {
            flag= (flag+1)%2;
        }
        else
        {
            if(flag==0)
                v.push_back(1);

            else h.push_back(1);
        }
    }

    if(f(v,x)==1 && f(h,y)==1)
        printf("Yes\n");
    else printf("No\n");



    return 0;
}
