#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector<int>numb;


int main()
{
//    for(int m=2;m<=1000;m++) {

    int n; //=m;
    int  twos=0,threes=0;
    numb.clear();
    scanf("%d",&n);

   // printf("%d ",m);
    if(n==0)     {      printf("10\n");      return 0;      } // return 0;
    if(n<10) {printf("%d\n",n); return 0;   } //return 0;

    int root= sqrt(n);
    for(int i=2; i<=root; i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                n/=i;
                cnt++;

                if(i>7)
                {
                    printf("-1\n");
                     return 0;
                }

                if(i>3)
                    numb.push_back(i);
            }



            if(i==2) twos=cnt;
            if(i==3) threes=cnt;

        }

        root= sqrt(n);
    }


    if(n!=1)
    {
        if(n==2) twos=1;
        else if(n==3) threes=1;
        else if(n<=9) numb.push_back(n);
        else
        {
            printf("-1\n");
            return 0;
        }
    }


    int cnt1= twos/3;

    twos=twos%3;
    for(int i=1; i<=cnt1; i++) numb.push_back(8);


    if(threes%2==1 && twos==2) { numb.push_back(6); numb.push_back(2);  twos=0; threes--;  }

    cnt1=twos/2;
    for(int i=1; i<=cnt1; i++) numb.push_back(4);
    twos=twos%2;

    if(twos==1)
    {
        if(threes%2==1)
        {
            numb.push_back(6);
            threes--;
        }
        else
        numb.push_back(2);
    }

    int cnt2= threes/2;
    threes= threes%2;

    for(int i=1; i<=cnt2; i++) numb.push_back(9);
    for(int i=1; i<=threes; i++) numb.push_back(3);


    sort(numb.begin(), numb.end());

    for(int i=0; i<numb.size(); i++) printf("%d",numb[i]);


    puts("");



    return 0;
}
