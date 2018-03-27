#include<bits/stdc++.h>
using namespace std;

int n;

struct heap
{
    int root=1,current=1;
    vector<int>v;
    void push_up(int i)
    {
        while(v[i]>v[i/2] && i/2!=0)
        {
            swap(v[i],v[i/2]);
            i=i/2;
        }
    }

    void push_down()
    {
        int pos=1;

        while( pos*2+1<v.size() && (v[pos]<v[pos*2]  || v[pos]<v[pos*2+1]))
        {
            if(v[pos]<v[pos*2] && v[pos]<v[pos*2+1])
            {

                if(v[pos*2]>v[pos*2+1])
                {
                    swap(v[pos],v[pos*2]);
                    pos*=2;
                }
                else
                {
                    swap(v[pos],v[pos*2+1]);
                    pos=pos*2+1;
                }
            }
            else if(v[pos]<v[pos*2])
            {
                swap(v[pos],v[pos*2]);
                pos*=2;
            }
            else if(v[pos]<v[pos*2+1])
            {
                swap(v[pos],v[pos*2+1]);
                pos*=2+1;
            }
            else break;

        }
        if(v.size()==3 && v[pos]<v[pos*2])
        {
            swap(v[pos],v[pos*2]);
        }


    }

    void insert(int x)
    {
        v.push_back(x);
        push_up(v.size()-1);
    }

    void heap_sort(int temp)
    {
        printf("Sorting: ");
        while(v.size()>1)
        {
            printf("->%d ",v[1]);
            swap(v[1],v[v.size()-1]);
            v.pop_back();
            push_down();

        }

    }


    void print()
    {
        for(int i=1; i<v.size(); i++)
            printf("%d ",v[i]);
        puts("");
    }
};

int main()
{
    heap h;
    int i,x;

    h.insert(0);
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>x;
        h.insert(x);
    }

    h.print();



    h.heap_sort(h.v.size()-1);

    // h.print();

    return 0;
}





