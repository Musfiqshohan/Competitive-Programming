#include<bits/stdc++.h>
using namespace std;

string str;
int dp[52][52][52];

bool isVowel(int i)
{
    if(str[i]=='A' || str[i]=='E' || str[i]=='O' || str[i]=='I' || str[i]=='U')
        return true;


    return false;

}

int f(int pos,int vow, int cons) // IU????W?????RZ?I
{
  //  cout<<pos<<" "<<vow<<" "<<cons<<endl;
    if(vow==3 || cons==5) return 1;
    if(pos==str.size()) return 2;

   if(dp[pos][vow][cons]!=-1) return dp[pos][vow][cons];

    int t1=1000,t2=1000;
    if(isVowel(pos))
    {
        t1=f(pos+1,vow+1,0);
       // printf("1st at=%d  %d\n",pos, t1);

        return dp[pos][vow][cons]=t1;
    }
    else if(str[pos]=='?')
    {
        int t1= f(pos+1, vow+1, 0);
        int t2= f(pos+1, 0, cons+1);

        // printf("2nd at=%d  %d,%d\n",pos, t1,t2);
        if(t1!=t2) return dp[pos][vow][cons]=3;
        else return dp[pos][vow][cons]=t1;

    }
    else
    {
        t1=f(pos+1,0,cons+1);
       // printf("3rd at=%d  %d\n",pos, t1);
        return dp[pos][vow][cons]=t1;

    }

}

int main()
{
    int t=0,test;
    cin>>test;
    getchar();

    while(t<test) {
    memset(dp,-1,sizeof dp);
    cin>>str;

 //cout<<str<<endl;
    int ret=f(0,0,0);


    printf("Case %d: ",++t);



    if(ret==2) printf("GOOD\n");
    else if(ret==1) printf("BAD\n");
    else printf("MIXED\n");

    }

    return 0;
}
