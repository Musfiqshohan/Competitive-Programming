#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int G;

        cin>>G;

        while(G--)
        {

            int I,N,Q;

            scanf("%d %d %d",&I,&N,&Q);


            if(N%2==0)
            {
                printf("%d\n",N/2);
            }
            else
            {
                if(I!=Q) printf("%d\n",(N/2)+1);
                else printf("%d\n",N/2);
            }

        }
    }
    return 0;
}
