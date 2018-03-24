#include<bits/stdc++.h>
using namespace std;

string str;
int l, dp[3005][4];
int isVowel(char x)
{
    if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
        return 1;
    return 0;

}

int f(int i, int cons)
{
    if(i==l) return 0;

    if(dp[i][cons]!=-1) return dp[i][cons];
    int t1=2000000,t2=2000000;
    if(isVowel(str[i])==1)
    {
        t1=f(i+1,0);
    }
    else
    {
        if(cons==2)
        {
            if(str[i]==str[i-1] && str[i-1]==str[i-2])
            {
                t1= f(i+1,2);
            }
            else
            {
                t1=1+f(i+1,2);
                t2=1+f(i+1,1);

            }


        }
        else
            t1=f(i+1,cons+1);

    }


    return dp[i][cons]=min(t1,t2);

}

string str2;
void print(int i, int cons)
{
    if(i==l) return ;


    if(isVowel(str[i])==1)
    {
       // printf("%c\n",str[i]);
        str2+=str[i];
        print(i+1,0);
    }
    else
    {
        if(cons==2)
        {
            if(str[i]==str[i-1] && str[i-1]==str[i-2])
            {
                str2+=str[i];
                print(i+1,2);
            }
            else
            {
                if(f(i+1,2)<f(i+1,1))
                {
                    str2 = str2.substr(0, str2.size()-1);
                    str2+=' ';
                    str2+=str[i-1];
                    print(i+1,2);
                }
                else
                {
                    str2+=' ';
                    str2+=str[i];
                    print(i+1,1);
                }
//                t1=1+f(i+1,2);
//                t2=1+f(i+1,1);

            }


        }
        else
        {
            str2+=str[i];
            print(i+1,cons+1);
        }

    }


    return ;

}

int main()
{
    memset(dp,-1,sizeof dp);

    cin>>str;
    l=str.length();
    //cout<<f(0,0)<<endl;

    print(0,0);

    cout<<str2<<endl;
}
