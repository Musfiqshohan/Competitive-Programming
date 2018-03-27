#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
using namespace std;

pair<double, double >pints[109];
int par[109];
double total=0;
struct tripple
{
    int u,v;
    double length;
};
vector<tripple>tra;


bool compare(tripple a, tripple b)
{
    return a.length<b.length;
}

int findd(int r)
{
    if(par[r]==r) return r;
    return par[r]=findd(par[r]);
}

void unionn(tripple temp)
{
    int u= findd(temp.u);
    int v= findd(temp.v);

    if(u!=v)
    {
        par[u]=v;

        total+=temp.length;
        //  cout<<temp.length<<endl;
    }
}

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    int test,t=0;
    cin>>test;

    getchar();
    for(t=0;t<test;t++)
    {
        if(t) printf("\n");

        int n;
        scanf("%d",&n);

        total=0;

        for(int i=0; i<n; i++)
        {
            // scanf("%f %f",&
            cin>>pints[i].first>>pints[i].second;
        }

        for(int i=0; i<n; i++)
        {
            //puts("hi");
            for(int j=i+1; j<n; j++)
            {
                double x= pints[i].first-pints[j].first;
                double y= pints[i].second- pints[j].second;

                double dist= sqrt(x*x + y*y);

                //  cout<<dist<<endl;
                tra.push_back({i,j,dist});
            }

        }



        sort(tra.begin(), tra.end(), compare);

        for(int i=0; i<n; i++) par[i]=i;

        for(int i=0; i<tra.size(); i++)
        {
            unionn(tra[i]);
        }

        cout<<total<<endl;


        tra.clear();

    }
    return 0;
}

