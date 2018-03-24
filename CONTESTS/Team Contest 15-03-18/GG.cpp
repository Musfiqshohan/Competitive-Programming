#include<bits/stdc++.h>
#define i64 long long
using namespace std;
i64 arr[1005][1005],a[1005];
int main()
{
    while(1){
    i64 n,m,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    a[0]=arr[0][0];
    for(j=1;j<m;j++)
    {
        arr[0][j]+=arr[0][j-1];
        a[j]=arr[0][j];
    }
    cout<<a[m-1];
    for(i=1;i<n;i++)
    {
        i64 temp=a[0];
        for(j=1;j<m;j++)
        {
            temp=max(temp+arr[i][j-1],a[j]);
            a[j-1]=temp;
        }
        temp=temp+arr[i][m-1];
        a[m-1]=temp;
        cout<<" "<<temp;

    }
    cout<<endl;

    memset(a,0,sizeof a);
    memset(arr,0,sizeof arr);
    }
}
