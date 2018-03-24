    #include<bits/stdc++.h>
    #define pb push_back
    #define ms(a,b) memset((a),(b),sizeof(a))
    //#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
    #define ll long long
    using namespace std;

    int main()
    {
        int n;
        scanf("%d",&n);

        int cnt=n/4;

        int mn=100000000,mnx,mny;

       // printf("%d\n",cnt);
        while(cnt>=0)
        {
            int num= n- 4*cnt;

            if(num%7==0)
            {
                int total= cnt+ num/7;
                if(total<mn)
                {

                    mn=total;
                    mnx=cnt;
                    mny=num/7;
                    //break;
                }
            }

            cnt--;
        }

       // printf("%d %d\n",mnx,mny);
        if(mnx*4 + mny*7 !=n) {printf("-1\n"); return 0; }
        for(int i=1;i<=mnx;i++) printf("4");
        for(int i=1;i<=mny;i++) printf("7");

        puts("");

        return 0;
    }
