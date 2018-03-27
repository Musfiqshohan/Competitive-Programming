#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(b,"w",stdout)
using namespace std;


struct info
{
    int x,y;
};
vector<info>vec;
int exist[1000009];
bool compare(info a, info b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;

}

int pow1(int x, int n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        int ret= pow1(x,n/2);
        return ret*ret;
    }

    return x* pow1(x,n-1);

}

int f1(int m,int n, int k)
{

    return pow1(k,n) *  pow1((k-1),(m-1)*n);

}

int main()
{
//    int test,t=0;
//    cin>>test;
//
//    while(t<test)
//    {

    int N,M,k,B,x,y;

    scanf("%d %d %d %d",&M,&N,&k,&B);

    int row=M, col= N;

    for(int i=0; i<B; i++)
    {
        scanf("%d %d",&x,&y);

        vec.push_back({x,y});

        if(exist[y]==0)
        {
            exist[y]=1;
            col--;
        }

    }


    int ans1= f1(M, col ,k);


    sort(vec.begin(), vec.end(), compare);

    int ans2=1;
    for(int i=0; i<vec.size(); i++)
    {
        int col= vec[i].y;
        int row= vec[i].x;

        int block=0, uniqus=0;

        if(row!=1) uniqus++;


        while(vec[i].y==col )
        {

            block++;


            if(  vec[i+1].y==col && vec[i+1].x<=M &&  (vec[i].x != vec[i+1].x -1)){
                uniqus++;

            printf("here-> %d %d %d\n",vec[i+1],  vec[i].x, vec[i+1].x-1);

            }

            i++;
        }

        printf("at col=%d , %d %d\n",col, block, uniqus);
        //ans2= ans2* pow1(k-1, (M-block)-uniqus) * pow1(k, uniqus);

        i--;

    }





    int res= ans1*ans2;

   // cout<<res<<endl;




    return 0;
}
