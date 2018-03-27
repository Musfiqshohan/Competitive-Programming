#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

vector<int>vec;
string str;


void build_palindrome(int flag)
{
    int i,j;
    int mid= vec.size()/2;
    if(flag==1)
    {
        if(vec.size()&1)
            i=mid,j=mid+1;
        else i=mid-1,j=mid+1;

        while(i>0)
        {
            vec[j]=vec[i];
            j++,i--;
        }
    }
    else if(flag==2)
    {
        i=mid-2, j=mid+1;

        while(i>=0)
        {
            vec[j]=vec[i];
            i--,j++;
        }

     //   puts("Hi");

        if(vec.size()==2)
            vec[1]=1;

    }
    else
    {
        i=mid-1,j=mid+1;

        while(i>=0)
        {
            vec[j]=vec[i];
            i--,j++;
        }
    }


}

int main()
{
    int t=0,test;
    cin>>test;
    while(t<test)
    {


        vec.push_back(0);
        cin>>str;

        rep(i,str.length())
        vec.push_back(str[i]-'0');




        int mid= vec.size()/2, odd=0,flag=0;

        if(vec.size()%2==1)
            odd=1;

         // printf("size= %d odd= %d\n",vec.size(),odd);

        int i,j;
        if(odd)
            i=mid, j=mid+1;
        else i=mid-1, j=mid+1;

        while(i>0 && j<vec.size() && vec[i]==vec[j])
        {
            i--;
            j++;
        }

        if(i>0 && j<vec.size() && vec[i]>vec[j])  /// case 3 when normally do;
        {
            // printf("%d %d\n",vec[i],vec[j]);
            build_palindrome(1);
        }
        else
        {

            while(vec[mid]+1>9)
            {
                vec[mid]=0;
                mid--;
            }

            vec[mid]++;
            if(mid==0 && odd==0)       /// even and will create even digs
                flag=2;
            else if(mid==0 && odd==1) /// odd and create odd digs
                flag=3;
            else flag=1; /// just normal


            //printf("mid= %d  odd= %d flag=%d\n",mid, odd,flag);

            build_palindrome(flag);

        }

        printf("Case %d: ",++t);

        for(int i=0; i<vec.size(); i++)
        {
            if(vec[i]==0 && i==0) continue;
            printf("%d",vec[i]);
        }

        puts("");
        vec.clear();


    }
    return 0;
}

