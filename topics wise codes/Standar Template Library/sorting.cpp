#include<bits/stdc++.h>
using namespace std;

struct data{
    char name[100];
    int height, weight;
    long long income;
};

bool compare(data a, data b)
{
    if( a.income == b.income)
    {
        if(a.height==b.height)
        {
            if(a.weigth==b.weight)
            {
                return strlen(a.name)<strlen(b.name);

            }
            else return a.weight<b.weight;

        }
        else return a.height>b.height;

    }
    else return a.income>b.income;

}
int main()
{
    vector<int>v;
    v.push_back(5);
    v.push_back(2);

    sort(v.begin(), v.end());

    vector<data> t;
    sort(t.begin(), t.end(), compare);
}
