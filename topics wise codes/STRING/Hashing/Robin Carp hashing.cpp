#include<bits/stdc++.h>
#define d 256
using namespace std;

void search(char pat[], char txt[], int q)
{
    int M=strlen(pat);
    int N=strlen(txt);

    int p=0;
    int t=0;
    int h=1;
    int i,j;

    /// The value of h would be "pow(d, M-1)%q"
    for( i=0;i<M-1;i++)
        h= (h*d)%q;

    /// Calculate the hash value of pattern and first
    /// window of text
    for( i=0;i<M;i++)
    {
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }

    /// Slide the pattern over text one by one
    for( i=0;i<=N-M;i++)
    {
        /// Check the hash values of current window of text
        /// and pattern. If the hash values match then only
        /// check for characters on by one
        if(p==t)
        {
            /// Check for characters one by one
            for(j=0;j<M;j++)
            {
                if(txt[i+j]!=pat[j])
                    break;
            }

            /// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if(j==M)
                printf("Pattern found at index %d \n", i);

        }

        /// Calculate hash value for next window of text: Remove
        /// leading digit, add trailing digit
        if(i<N-M)
        {

            t= (d*(t-txt[i]*h) + txt[i+M] )%q;


            if(t<0)
                t+=q;

        }

    }

}


int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = 101; // A prime number
    search(pat, txt, q);
    return 0;
}
