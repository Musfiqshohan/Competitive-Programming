#include<bits/stdc++.h>
using namespace std;

string str;
int isPal[1001][1001], numPal[1001], l;
int f(int i, int j)
{
    if(i==j) return 1;
    if(i==j-1)
    {
        if(str[i]==str[j])
            return 1;
        return 0;
    }

    if(isPal[i][j]!=-1) return isPal[i][j];

    int isfinal=0;
    if(str[i]==str[j])
    {
        int temp= f(i+1, j-1);


        if(temp==1)
            isfinal=1;

    }


    int t1= f(i+1,j);
    int t2= f(i,j-1);


    return isPal[i][j]=isfinal;

}


int findd(int b)
{
    if(b==l+1) return 0;

    if(numPal[b]!=-1) return  numPal[b];

    int mn=100000;
    for(int i=b; i<=l; i++)
    {

        if(f(b,i)==1)
        {
            int temp= 1+ findd(i+1);
            mn= min(mn, temp);
        }

    }

    return numPal[b]= mn;

}

int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        memset(isPal, -1, sizeof isPal);
        memset(numPal, -1, sizeof numPal);
        cin>>str;

        l=str.length()-1;
        int tot=0;

        printf("Case %d: %d\n",++tt,findd(0));

    }

}
