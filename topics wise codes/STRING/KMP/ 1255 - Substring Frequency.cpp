#include<bits/stdc++.h>
using namespace std;

int lps[1000009];
int cnt=0;

void ComputeLPSArray(string pat, int m);

void KMPSearch(string pat, string text)
{
    int m= pat.length();
    int n= text.length();

    ComputeLPSArray(pat,m);

    int i=0,j=0;

    while(i<n)
    {
        if(text[i]==pat[j])
        {
            i++;
            j++;

            if(j==m)
            {
                cnt++;
               // printf("Found pattern at index %d \n", i-j);
                j=lps[j-1];

            }
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else i++;

        }

    }

}

void ComputeLPSArray(string pat, int m)
{
    int len=0, i=1;
    lps[0]=0;

    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }

        }
    }

}

int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {

        string text,pat;
        cin>>text>>pat;

        cnt=0;
        KMPSearch(pat,text);

        printf("Case %d: %d\n",++tt,cnt);

    }

}
