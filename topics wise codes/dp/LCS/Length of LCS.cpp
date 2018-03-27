#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int l1,l2;
int dp[100][100];
int calculate(int  i, int j)
{
    if(i==l1 || j==l2) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    int total=0,t1,t2;
    if(s1[i]==s2[j])
    {


        total= 1+calculate(i+1,j+1);

    }
    else
    {
        t1= calculate(i+1,j);
        t2=calculate(i,j+1);

        total=max(t1,t2);
    }

    return dp[i][j]=total;
}

void printLcs(int i, int j)
{
    if(i==l1 || j==l2) return ;

    if(s1[i]==s2[j])
    {
        s3+=s1[i];
        //cout<<s1[i]<<endl;
        printLcs(i+1,j+1);
    }

    else
    {
        if(dp[i+1][j]>dp[i][j+1])
        {
            printLcs(i+1,j);
        }
        else
            printLcs(i,j+1);
    }


}
string s6;
void printAll(int i, int j)
{


    if(i==l1 || j==l2)
    {
        //if(s4<s6) s6=s4;
        cout<<s4<<endl;
        return ;
    }

    if(s1[i]==s2[j])
    {
        s4+=s1[i];
        printAll(i+1,j+1);
        s4.erase(s4.end()-1);
    }

    else
    {
        if(dp[i+1][j]>dp[i][j+1])
        {
            printAll(i+1,j);
        }
        else if(dp[i+1][j]<dp[i][j+1])
            printAll(i,j+1);
        else
        {
            printAll(i+1,j);

            printAll(i,j+1);
        }
    }


}

int main()
{
    memset(dp,-1,sizeof dp);
    cin>>s1;
    s2=s1;
    reverse(s2.begin(), s2.end());

    l1=s1.length();
    l2=s2.length();

   // printf("%d\n",calculate(0,0));
   // printLcs(0,0);
   // cout<<s3<<endl;

    for(int i=0; i<calculate(0,0); i++)
       s6+='z';

    printAll(0,0);
    cout<<s6<<endl;
}
