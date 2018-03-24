#include<bits/stdc++.h>
using namespace std;

double ara[1000];

int n;
//double f(int pos)
//{
//
//    if(pos==n)
//    return 0;
//
//    double t=0;
//
//
//    //t= ara[pos] + (1-ara[pos])*(1+ f(pos+1));
//    t= ara[pos] + (pos+1)*(f(pos+1));
//
//    return t;
//}

int main()
{
    string str;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>str>>ara[i];


    sort(ara,ara+n);

    double sum=0;
    for(int i=n-1;i>=0;i--)
        sum+= ara[i]*(n-i);

    printf("%.6lf\n",sum);

}


/*
3
0.1234
0.5432
0.3334
*/


