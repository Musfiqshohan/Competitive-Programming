    #include<bits/stdc++.h>
    #define ll long long
    #define pb push_back
    #define SL(x) scanf("%lld",&x)
    #define PL(x) printf("%lld\n",x)
    #define N 500
    #define CLR(x) memset(x,0,sizeof(x))
    #define nl printf("\n")
    #define tll tuple<ll,ll,ll>
    using namespace std;
    bitset<N*N+1> b,c;
    int main()
    {
        ll n,t,i,x,y,ans,z,l,r;
        bool flag;
        char cc;
        SL(t);
        while(t--)
        {
            ans=0;
            b.reset();
            c.reset();
            b[0]=1;c[0]=1;
            SL(n);
            y=0;z=0;
            flag=false;
            for(i=0;i<n;i++)
            {
                SL(x);
                if(flag)y+=x,b|=b<<x;
                else z+=x,c|=c<<x;
                flag=!flag;
                cin>>cc;
            }
            SL(x);
            if(flag)y+=x,b|=b<<x;
            else z+=x,c|=c<<x;
            if(y%2==0 and b[(y/2)])ans+=0;
            else
            {
                l=y/2;
                r=l+1;
                while(1)
                {
                    if(b[l])break;
                    l--;
                }
                while(1)
                {
                    if(b[r])break;
                    r++;
                }
                ans=r-l;
            }
            if(z%2==0 and c[(z/2)])ans+=0;
            else
            {
                l=z/2;
                r=l+1;
                while(1)
                {
                    if(c[l])break;
                    l--;
                }
                while(1)
                {
                    if(c[r])break;
                    r++;
                }
                ans+=(r-l);
            }
            if(n<=2)printf("NO\n");
            else PL(ans);
        }
    }
