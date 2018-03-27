#include<bits/stdc++.h>
using namespace std;


void input(int ara[],int i, int n,int flag)
{
    if(i==n) return;
    if(flag==0)
    {scanf("%d",&ara[i]);
    flag=0;
    }
    else
    {
        printf("%d ",ara[i]);
        flag=1;
    }
    i++;
    input(ara,i,n,flag);
}

void sorting(int ara[], int i, int j, int n)
{
    if(j==n-2) return;
    if(i==n-1) {i=0; j++;  }
    if(ara[i]>ara[i+1])
       swap(ara[i],ara[i+1]);
    i++;
    sorting(ara,i,j,n);

}

int main()
{
    int a[100];
    int n,i,k;
    scanf("%d",&n);

    input(a,0,n,0);

    sorting(a,0,0,n);


    input(a,0,n,1);
    return 0;


}

