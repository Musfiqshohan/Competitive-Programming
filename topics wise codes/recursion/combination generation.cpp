#include<bits/stdc++.h>
using namespace std;
int ara[200];
int n,r;


void loop(int i, int till,int pos);
void dfs(int num, int pos);
void loop(int i, int till,int pos)
{
    if(i<till) return;
    loop(i-1,till,pos);
    if(n-i>=r-pos)
    {
        ara[pos]=i;
        dfs(i+1,pos+1);
    }

}
void dfs(int num, int pos)
{
    int i;
    if(pos==r+1)
    {
        for(i=1; i<=r; i++)
            printf("%d ",ara[i]);

        puts("");
    }

    loop(n,num,pos);
//    for(i=num;i<=n;i++)
//    {
//         if(n-i>=r-pos){
//        ara[pos]=i;
//        dfs(i+1,pos+1);
//        }
//
//    }
}


int main()
{


    scanf("%d %d",&n,&r);

    dfs(1,1);

}
