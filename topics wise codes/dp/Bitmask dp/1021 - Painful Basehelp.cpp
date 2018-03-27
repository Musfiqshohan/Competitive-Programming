/*
 * 1021 - Painful Bases.cpp
 *
 *  Created on: Feb 12, 2014
 *      Author: khairullah
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstring>

using namespace std;
typedef long long int ll;

int base, K, len, arr[20];
ll DP[25][(1<<17)];
 string num;
ll rec(int val, int mask)
{
    ll &ret = DP[val][mask];
    if(mask==(1<<len)-1)
    {
        return val==0;
    }
    if(ret!=-1) return ret;
    ret = 0;
    for(int i=len-1; i>=0; i--)
    {
        if(!(mask&(1<<i)))
        {
           // printf("%d\n",arr[i]);
            ret+=rec((val*base+arr[i])%K,(mask|(1<<i)));
        }
    }
    return ret;
}
int main(int argc, char **argv) {


       // stdout("output.txt","w","stdout");

        num.clear();
        cin>>base>>K;
        cin>>num;
        len = num.length();
        for(int j=0; j<len; j++)
        {
            if(num[j]>='0' and num[j]<='9') arr[j] = num[j] - '0';
            else arr[j] = num[j] - 'A' + 10;
        }
        memset(DP,-1,sizeof(DP));
        ll res= rec(0,0);
        cout<<"Case "<<": "<<res<<endl;

    return 0;
}
