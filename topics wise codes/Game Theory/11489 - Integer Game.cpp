#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    int t=0,test;
    cin>>test;
    for(t=0;t<test;t++){

    int i,num,t1=0,cnt=0;
    string s;

    cin>>s;

    printf("Case %d: ",t+1);
    for(i=0; i<s.size(); i++)
    {
        num= s[i]-'0';
        if(num%3==0) cnt++;
        t1+= num;
    }

    if(t1%3==0)
    {
        if(cnt==0) puts("T");
        else if(cnt%2==1)  puts("S");
        else puts("T");

    }
    else
    {

        for(i=0; i<s.size(); i++)
        {
            num= s[i]-'0';
            if((t1-num)%3==0)
                break;
        }

        if(i==s.size()) printf("T\n");
        else
        {
            if(cnt%2==1)  puts("T");
            else  puts("S");

        }

    }




    }
    return 0;

}
