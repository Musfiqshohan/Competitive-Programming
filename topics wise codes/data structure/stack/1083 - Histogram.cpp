#include<bits/stdc++.h>
using namespace std;

pair<int, int>p[30009];
stack<pair<int, int> >stk;
int main()
{

    int t=0, test;
    scanf("%d",&test);

    while(t<test){
    int n,i;

    stk.push({0,0});


    int mx=0,area,index,length;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i].first);
        p[i].second=i;


    }

    p[i]= {0,i};

    for(i=1;i<=n+1;i++)
    {


        if(stk.top().first<=p[i].first)
        {
            stk.push(p[i]);

        }
        else
        {
            while(stk.top().first> p[i].first)
            {
                length=stk.top().first;
                index=stk.top().second;

                int area= length*(p[i].second- index);
               //  printf("length= %d %d %d\n",length, index,area);

                mx= max(mx,area);

                stk.pop();

            }

           // if(p[i].first)
            stk.push({p[i].first,index});
        }


    }



    printf("Case %d: %d\n",++t,mx);

    while(stk.empty()==false){ stk.pop();  }

    }
    return 0;

}
