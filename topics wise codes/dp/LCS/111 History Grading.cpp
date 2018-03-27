#include <iostream>
#include <string>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;
int a1[30];
int b1[30];
int dp[22][22];
int l;
int printLcs(int i, int j)
{
    if(i==l || j==l) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    int total=0,t1,t2;
    if(a1[i]==b1[j])
    {

        total=1+printLcs(i+1,j+1);
    }
    else
    {
        t1= printLcs(i+1,j);
        t2=printLcs(i,j+1);

        total= max(t1,t2);
    }
    return dp[i][j]=total;
}

void result()
{
    memset(dp,-1,sizeof dp);

    printf("%d\n",printLcs(0,0));

}

int split0(string name)
{
     int n;
    stringstream ss(name);
    string arr[25];
    int i=0;
    while(ss.good())
    {
        ss>>arr[i];
        //   cout<<arr[i]<<endl;
        i++;
    }

    return i;


}


void split(string name,int pos)
{

    int n;
    stringstream ss(name);
    string arr[25];
    int i=0;
    while(ss.good())
    {
        ss>>arr[i];
        i++;
    }
    int j=0;
    while(j<i)
    {
        if(pos==1)   a1[atoi(arr[j].c_str())]=j;
        else b1[atoi(arr[j].c_str())]=j;
        j++;
        arr[i].clear();
    }

    l=j;

}
int main ()
{

    freopen("111 History GradingInput.txt","r",stdin);
    freopen("111 History GradingOutput.txt","w",stdout);
    string name;
    int flag=0;
    while(getline (cin,name))
    {
        int num=split0(name);

        if(num==1)
            flag=1;

        else if(flag==1)
        {
            split(name,1);
            flag=0;
        }
        else if(flag==0)
        {
            split(name,2);
            result();
        }
    }

    return 0;
}
