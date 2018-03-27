#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a);
using namespace std;
string a,b;
int dp[109][109];

int f(int i,int j)
{
    if(i==a.length() || j==b.length()) return 0;

    int res,res1,res2;
    if(dp[i][j]!=-1)  return dp[i][j];

    if(a[i]==b[j])
    {
        res= 1+ f(i+1,j+1);
    }
    else
    {
        res1= f(i+1,j);
        res2= f(i,j+1);
        res= max(res1,res2);
    }

    return dp[i][j]=res;

}

string f2(int l)
{
    string str;

    int i=0,i1=0, j=0,j1=0;

    while(l)
    {
        for(char ch='a'; ch<='z' ; ch++)
        {
            while(i<a.length())
            {
                if(ch==a[i]) break;
                i++;
            }

            while(j<b.length())
            {
                if(ch==b[j]) break;
                j++;
            }

          //  printf("%c %d %d %d->%d\n",ch,i,j,l,dp[i][j]);

            if(dp[i][j]==l)
            {
                l--;

                str+=a[i];

                i++;
                i1=i;
                j++;
                j1=j;
                break;
            }
            else
            {
                i=i1;
                j=j1;
            }

        }


    }


    return str;
}
int main()
{
    int t=0,test;

    cin>>test;

    while(t<test){
    ms(dp,-1);
    cin>>a>>b;

    int l= f(0,0);


    printf("Case %d: ",++t);
    if(l==0) printf(":(\n");
    else
    cout<<f2(l)<<endl;

    }

    return 0;
}
