///https://vjudge.net/contest/212042#problem/I
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,k;

    string str;
    cin>>n>>a>>b>>k;
    cin>>str;

    str="1"+str+"1";
    int boats=0,zeros,kk;

    vector<int>vec;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='1')
        {
            zeros=0;
            i++;
            while(str[i]!='1' && i<str.size())
            {
                zeros++;
                i++;
            }
            boats+=(zeros/b);
        }
        i--;
    }


    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='1')
        {
            kk=0;
            i++;
            while(str[i]!='1' && i<str.size() )
            {
                kk++;
                if(kk%b==0 && boats>=a){
                    vec.push_back(i);
                    boats--;
                }
                i++;
            }
        }
        i--;
    }





    cout<<vec.size()<<endl;

    for(int i=0; i<vec.size(); i++)
        printf("%d ",vec[i]);
    puts("");








    return 0;
}
