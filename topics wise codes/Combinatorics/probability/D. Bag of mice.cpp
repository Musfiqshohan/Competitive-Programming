#include<bits/stdc++.h>
using namespace std;

int B,W;
double dp[1009][1009][3];
int vis[1009][1009][3];
double f(int w, int b,int turn)
{
    // printf("w=%d b=%d  at %d \n",w,b,turn);
    if(w==0 && b==0 && turn==1) return 0;
    if(turn==1)
    {
        if(w==0 && b>0) return 0;
        if(b==0 && w>0) return 1.0;
    }
    else if(turn==2)
    {
        if(w==0 && b>0) return 1.0;

        if(b==0 && w>0) return 0;
    }
//    if(w==0 && turn==1) return 0;
//    if(w==0 && turn==2) return 1;

    if(vis[w][b][turn]==1) return dp[w][b][turn];

    vis[w][b][turn]=1;

    double t1=0,t2=0;
    if(turn==1)
    {
        t1= (b*1.0)/(w+b) * f(w,b-1,2);  ///black mouse

        t2= (w*1.0)/(w+b) * 1.0;    ///white mouse

      //  printf("w=%d b=%d  %d player= t1=%.2f  t2=%.2f\n",w,b,turn,t1,t2);
    }
    else
    {
        if(b-2>=0)
            t1= (b*1.0)/(b+w) * ((b-1)*1.0)/(b-1+w) * f(w,b-2,1);

        if(b-1 >=0 && w-1>=0)
            t2= (b*1.0)/(b+w) * (w*1.0)/(b-1+w) *f(w-1,b-1,1);


    }

       // printf("w=%d b=%d %d player= t1=%.2f  t2=%.2f\n",w,b,turn,t1,t2);
    return dp[w][b][turn]=t1+t2;

}

int main()
{
    //while(1){
    cin>>W>>B;
    printf("%.12f\n",f(W,B,1));
    //}
}
