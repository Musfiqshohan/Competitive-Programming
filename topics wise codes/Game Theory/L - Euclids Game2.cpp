#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
vector<int>vec;
int main()
{
    while(1){
    int n,m;

    scanf("%d %d",&n,&m);
    if(n==0 && m==0) break;

    while(max(n,m)%min(n,m)!=0)
    {
        vec.push_back(max(m,n)/ min(m,n));

        //cout<<max(m,n)/ min(m,n)<<endl;

        if(m>n)
            m=m%n;

        else
            n=n%m;

    }


    int turn=1;
    for(int i=vec.size()-1;i>=0;i--)
    {
      //  printf("%d ",vec[i]);
        if(vec[i]>1)
            turn=1;
        else
            turn^=1;

    }

    if(turn ==0)
        printf("Ollie wins\n");
    else
        printf("Stan wins\n");

    vec.clear();

    }
    return 0;
}
