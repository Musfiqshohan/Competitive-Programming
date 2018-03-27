#include<bits/stdc++.h>
using namespace std;


double f(int C, int D, int H, int S, int J)
{
   // printf("%d %d %d %d %d\n",C,D,H,S,J);
    if(C==0 && D==0 && H==0 && S==0)
        return 0;

    double sum= C+D+H+S+J;

    double ara[8];
    memset(ara,0,sizeof ara);

    if(C>0)
    {
        ara[0]= C/sum * (1 + f(C-1, D,   H,  S,  J) );
        if(J>0)  ara[4]= J/sum * (1 + f(C-1,   D,   H,  S,  J-1) );
    }

    if(D>0)
    {
        ara[1]= D/sum * (1 + f(C,   D-1, H,  S,  J) );
        if(J>0) ara[5]= J/sum * (1 + f(C,     D-1, H,  S,  J-1) );
    }
    if(H>0)
    {
        ara[2]= H/sum * (1 + f(C,   D,   H-1,S,  J) );
        if(J>0)  ara[6]= J/sum * (1 + f(C,     D,   H-1,S,  J-1) );
    }
    if(S>0)
    {
        ara[3]= S/sum * (1 + f(C,   D,   H,  S-1,J) );
        if(J>0)   ara[7]= J/sum * (1 + f(C,     D,   H,  S-1,J-1) );
    }

//    if(J>0)
//    {
//        ara[4]= J/sum * (1 + f(C-1,   D,   H,  S,  J-1) );
//        ara[5]= J/sum * (1 + f(C,     D-1, H,  S,  J-1) );
//        ara[6]= J/sum * (1 + f(C,     D,   H-1,S,  J-1) );
//        ara[7]= J/sum * (1 + f(C,     D,   H,  S-1,J-1) );
//
//    }

    sort(ara,ara+8);

    return ara[7];

}

int main()
{
    int C,D,H,S;
    cin>>C>>D>>H>>S;

    cout<<f(C,D,H,S,2)<<endl;
}
