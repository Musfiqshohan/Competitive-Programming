#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<int,int>
#define inf 1000000000000000000

using namespace std;
const int MAXN=100009;
vector<pii>vec;
struct edge {
    int u, v, w;
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};
int pr[MAXN];
vector<edge> e;
int find(int r)
{
    return (pr[r] == r) ? r : find(pr[r]);
}
int mst(int n)
{
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++)
        pr[i] = i;

    int count = 0, s = 0;
    for (int i = 0; i < (int)e.size(); i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if (u != v) {
            pr[u] = v;
            count++;
            s += e[i].w;
            vec.push_back({u,v});
            if (count == n - 1)
                break;
        }
    }
    return s;
}

int main()
{
    // READ("in");
    int n, m;
    cin >> n;
    string s1,s2;
    cin>>s1>>s2;
    for (int i = 0; i <n; i++) {

        int u=s1[i]-97;
        int v=s2[i]-97;
        int w=1;

        //printf("%d %d\n",u,v);

        edge get;
        get.u = u;
        get.v = v;
        get.w = w;
        e.push_back(get);
    }

    mst(100005);

    cout<<vec.size()<<endl;

    for(int i=0;i<vec.size();i++)
        printf("%c %c\n",vec[i].first+97,vec[i].second+97);


    return 0;
}
