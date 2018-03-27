#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

int f(int isOne, int i)
{
    if(i==3) return 0;

    int t1,t2;
    printf("%d %d\n",isOne,i);
    if(isOne==1) {t1++;      printf("->%d %d\n",isOne,i);  }


     t2= f(0,i+1);
     t1= f(1,i+1);


    return t1+t2;
}
int main()
{
    int n;
   // scanf("%d",&n);

    int res=f(0,0);
    cout<<res<<endl;
}


