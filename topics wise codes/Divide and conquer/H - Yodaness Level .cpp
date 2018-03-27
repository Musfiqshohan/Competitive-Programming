#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

map<string,int>mp;
vector<int>vec;

void combine(int low, int high)
{
    int mid= (low+high)/2;

    int ara[high-low+1];


    int i=low, j=mid+1,k=0;

    while(i<=mid && j<=high)
    {
        if(vec[i]<vec[j])
        {
            ara[k++]=vec[i];
            i++;
        }
        else
        {
            ara[k++]=vec[j];
            j++;
        }
    }

    while(i<=mid)
        ara[k++]=vec[i],i++;

    while(j<=high)
        ara[k++]=vec[j],j++;

    for(int i=0; i<high-low+1; i++)
    {
        vec[low+i]=ara[i];
    }

    return ;
}



int divide(int low, int high)
{
    //printf("%d %d\n",low,high);
    if(low>=high)
        return 0;

    int mid= (low+high)/2;

    int t1= divide(low,mid);
    int t2= divide(mid+1,high);


    int i=low, j=mid+1;

    int tot=0;


    while(i<=mid && j<=high)
    {
        if(vec[i]>vec[j])
        {
            tot+= mid-i+1;
            j++;
        }
        else
        {
            i++;
        }

    }


    combine(low,high);

    return tot+t1+t2;


}
int main()
{
    int test;
    cin>>test;

    while(test--)
    {

        int n;
        scanf("%d",&n);
        getchar();

        int cnt=0;
        string str;
        for(int i=0; i<n; i++)
        {
            cin>>str;
            mp[str]=i;
        }

        getchar();
        for(int i=0; i<n; i++)
        {
            cin>>str;
            vec.push_back(mp[str]);
        }




        cout<<divide(0, vec.size()-1)<<endl;

        mp.clear();
        vec.clear();


    }


    return 0;

}
