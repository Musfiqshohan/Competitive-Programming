#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a);
using namespace std;
string a;

int dp[1009][1009];
int f(int i, int j)
{

    if(i>j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    int res1=0,res2=0,res=0;
    if(a[i]==a[j])
    {

        if(i!=j)
            res= 2 + f(i+1,j-1);
        else res= 1+ f(i+1,j-1);

    }
    else
    {
        res1= f(i+1,j);
        res2= f(i,j-1);
        res= max(res1,res2);
    }

    return dp[i][j]=res;

}


string  f2(int length)
{
    int l=length;
    string str="";

    int i=0,i1=0;
    int j=a.length()-1,j1= a.length()-1;

    while(l>0)
    {
        for(char ch='a' ; ch<='z' ; ch++)
        {
            while(i<=a.length())
            {
                if(a[i]==ch) break;
                i++;
            }

            while(j>= 0)
            {
                if(a[j]==ch) break;
                j--;

            }
            //printf("%c %d %d %d->%d\n",ch,i,j,l,dp[i][j]);

            if(dp[i][j]==l)
            {
                str+=ch;
                if(i!=j)
                l-=2;
                else l--;

                i++;
                i1=i;
                j--;
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

    string temp=str;
    reverse(temp.begin(), temp.end());

    if(length%2==1)
        str.pop_back();

    str+=temp;
    return str;
}

int main()
{

     //freopen("G - Palindromic SubsequenceI.txt","r",stdin);
    // freopen("G - Palindromic SubsequenceO.txt","w",stdout);
    while(cin>>a)
    {

        ms(dp,-1);
        int l=f(0,a.length()-1);
        //cout<<l<<endl;
        cout<<f2(l)<<endl;


    }
    return 0;
}
