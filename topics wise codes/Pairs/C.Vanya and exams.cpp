#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long  i,n,r,avg,num;
    long long target,sum=0,total=0;
    pair<long long int ,long long int > points[100009];
    scanf("%I64d %I64d %I64d",&n,&r,&avg);
    target=n*avg;
    for(i=0;i<n;i++)
    {
        scanf("%I64d",&points[i].second);
        scanf("%I64d",&points[i].first);
        total+=points[i].second;
    }

    //printf("%d\n",target);
    if(target<=total) printf("0\n");
    else{
    target=target-total;
    sort(points,points+n);
    for(i=0;i<n;i++)
    {
        if(points[i].second<r)
        {
            num= r- points[i].second;
            target=target-num;
            if(target>=0)   sum+=num*points[i].first;
            else sum+=(target+num)*points[i].first;
        }
        if(target<=0) break;
    }
    printf("%I64d\n",sum);

    }
    return 0;
}

