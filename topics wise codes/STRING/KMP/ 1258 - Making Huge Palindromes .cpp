#include<bits/stdc++.h>
using namespace std;

int lps[1000009];

void computeLPSArray(string pat, int M)
{

    int len=0, i=1;
    lps[0]=0;

    while(i<M)
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
                len= lps[len-1];

            else
            {
                lps[i]=0;
                i++;
            }
        }

    }

}
int KMPSearch(string text, string pat)
{

    int N= text.size();
    int M= pat.size();

    computeLPSArray(pat,M);

    int i=0,j=0;

    while(i+j<N)
    {
       // printf("%d=%c  %d=%c\n",i,text[i], j,pat[j]);
        if(text[i]== pat[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }

    //cout<<i<<" "<<j<<" "<<i+j<<" "<<M<<endl;

    int res;
    if(i+j==M+1)
    {
        res= M + (M- 2*j +1 );
    }
    else
    {
      //  j--;
        res=M + (M-2*j);
    }

    return res;


}

int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {

        string str;
        cin>>str;

        string str2=str;
        reverse(str2.begin(), str2.end());

        printf("Case %d: %d\n",++tt,KMPSearch(str,str2));

    }

}
