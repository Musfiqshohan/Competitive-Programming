#include<bits/stdc++.h>
#define i64 long long
#define pii pair<i64,i64>
using namespace std;

int ara[1000009];
void f(int st, int en, int src)
{
    ara[en]=src++;

    for(int i=st; i<en; i++)
        ara[i]=src++;
}

int main()
{
    int n,a,b;
    cin>>n>>a>>b;

    int ca=-1,cb=-1;
    for(int i=0; a*i<=n; i++)
    {
        int rem= n- a*i;

        if(rem%b==0)
        {
            ca=i;
            cb=rem/b;
            break;
        }
    }

    if(ca==-1 || cb==-1)
    {
        printf("-1\n");
        return 0;
    }

    //cout<<ca<<" "<<cb<<endl;

    int i=0;

    if(ca)
    {
        for(i=0; i<n; i++)
        {
            f(i,i+a-1,i+1);
            i+=(a-1);
            ca--;
            if(ca==0)
            {
                i++;
                break;
            }
        }
    }

    if(cb)
    {
        for( ; i<n; i++)
        {

            f(i,i+b-1,i+1);
            i+=(b-1);
            cb--;
            if(cb==0) break;
        }
    }


    for(int i=0; i<n; i++)
        printf("%d ",ara[i]);
    puts("");


}
