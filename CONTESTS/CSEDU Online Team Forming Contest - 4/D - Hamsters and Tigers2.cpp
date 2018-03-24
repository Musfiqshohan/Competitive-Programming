#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector<int>vec;
string str,temp;
int n;
int f(int mid, char ch1, char ch2)
{
    int i=0,j=mid, k=n-1;
    int moves1=0, moves2=0;
    while(i<j)
    {
        while(temp[i]!=ch1 && i<j)
            i++;
        while(temp[j]!=ch2 && j>i)
            j--;

        // printf("%d %d\n",i,j);
        if(i<j)
        {
            swap(temp[i],temp[j]);
            moves1++;

            i++;
            j++;

        }
    }

   //  printf("moves1=%d\n",moves1);
    j=mid;
    while(j<k)
    {
        while(temp[j]!=ch2 && j<k)
            j++;

        while(temp[k]!=ch1 && k>j)
            k--;

      //   printf("j=%d k=%d\n",j,k);
        if(j<k)
        {

            swap(temp[j],temp[k]);
            moves2++;

            j++;
            k--;
        }
    }

   //  printf("moves2=%d\n",moves2);
    return moves1+moves2;

}

int srch1(int targ)
{
    int low=0,high=vec.size()-1, mid, cnt=0;

    while(cnt++<32)
    {
        mid= low+(high-low)/2;
        if(vec[mid]>=targ)
            high=mid;
        else
            low=mid+1;
    }

    if(vec[mid]<targ) return mid+1;
    return  mid;
}

int srch2(int targ)
{
    int low=0,high=vec.size()-1, mid, cnt=0;

    while(cnt++<32)
    {
        mid= low+(high-low)/2;
        if(vec[mid]>targ)
            high=mid-1;
        else
            low=mid;
    }

    if(vec[mid]>targ) return mid-1;
    return mid;
}
int main()
{

    scanf("%d",&n);

    getchar();
    cin>>str;

    int mn=INT_MAX;


    for(int i=0; i<n; i++)
    {
        if(str[i]=='T')
            vec.push_back(i);
    }



    int moves=0;


    for(int i=0; i<=vec[vec.size()-1]; i++)
    {
        temp=str;
        moves=0;

        int next= vec[srch1(i)];


        if(i!=next) moves++;
        swap(temp[i],temp[next]);
        moves+= f(i, 'T','H');
        mn= min(mn,moves);


    }

    for(int i=n-1;i>=vec[0] ;i--)
    {
        temp=str;
        moves=0;
        int prev=vec[srch2(i)];
        if(i!=prev) moves++;
        swap(temp[i],temp[prev]);
        moves+=f(i, 'T', 'H');

        mn=min(mn,moves);
    }


    vec.clear();

    for(int i=0; i<n; i++)
    {
        if(str[i]=='H')
            vec.push_back(i);
    }

     for(int i=0; i<=vec[vec.size()-1]; i++)
    {
        temp=str;
        moves=0;

        int next= vec[srch1(i)];


        if(i!=next) moves++;
        swap(temp[i],temp[next]);
        moves+= f(i, 'H','T');
        mn= min(mn,moves);


    }

    for(int i=n-1;i>=vec[0] ;i--)
    {
        temp=str;
        moves=0;
        int prev=vec[srch2(i)];
        if(i!=prev) moves++;
        swap(temp[i],temp[prev]);
        moves+=f(i, 'H', 'T');

        mn=min(mn,moves);
    }



    cout<<mn<<endl;
    return 0;
}
