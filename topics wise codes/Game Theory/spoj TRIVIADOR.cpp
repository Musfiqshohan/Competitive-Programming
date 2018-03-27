#include<bits/stdc++.h>
using namespace std;

string str;
vector<int>vec;

int main()
{
    int tt=0,test;
    scanf("%d",&test);

    while(test--)
    {
        int n;
        scanf("%d",&n);
        getchar();

        cin>>str;

        int i;
        vec.push_back(str[0]);

        for( i=1; i<n; i++)
        {
            while(str[i]==vec[vec.size()-1])
                i++;
            vec.push_back(str[i]);

        }

        int t1=0,t2=0;

        for(int i=0; i<vec.size(); i++)
        {
            if(vec[i]=='X')
                t1++;
            else if(vec[i]=='O')t2++;

        }

        if(t2<=t1) printf("X");
        else printf("O");
        puts("");

        vec.clear();


    }



}
