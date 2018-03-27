#include<bits/stdc++.h>
using namespace std;

int game(int r, int c)
{

    if(a[r+1][c]==-1) g1=game(r+1,c,arr);
    if(a[r-1][c]==-1) g2=
    if(a[r][c+1]==-1)
    if(a[r][c-1]==-1)
    if(a[r+1][c+1]==-1)
    if(a[r+1][c-1]==-1)
    if(a[r-1][c+1]==-1)
    if(a[r-1][c-1]==-1)
}

int main()
{
    scanf("%d",&n);

    cout<<game(n)<<endl;
}
