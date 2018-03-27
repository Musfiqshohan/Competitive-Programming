#include<bits/stdc++.h>
using namespace std;

char s[100009];
int tree[4*100009];
void update(int node, int beg, int endd, int i, int j)
{
    if(i>j) return;


    if(beg==i && endd==j)
    {
        tree[node]++;
        return;
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    update(left, beg, mid, i, min(j, mid) );
    update(right, mid+1, endd, max(i, mid+1), j  );

    return;

}

int query(int node, int beg, int endd, int index, int carry)
{


    if(beg==endd)
    {
        carry+=tree[node];


        if(carry%2==1)
        {

            int x= s[beg]-'0';
            return x^1;
        }

        return s[beg]-'0';
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    int l;

    if(index<=mid)
        l=query(left, beg, mid, index, carry + tree[node]);  /// here I will add the prop values and go down
    else if(index>mid)
        l=query(right,  mid+1, endd, index, carry + tree[node]);

    return l;
}


int main()
{

    int t=0,test;
    scanf("%d",&test);

    while(t<test){

    memset(tree, 0, sizeof tree);
    printf("Case %d:\n",++t);

    scanf("%s",&s);
    int q,x,y,i,n;

    n= strlen(s);
    scanf("%d",&q);

    getchar();

    for(i=0;i<q;i++)
    {
        char ch;
        scanf("%c",&ch);


        if(ch=='I')
        {
            scanf("%d %d",&x,&y);

            update(1,0,n-1,x-1,y-1);

        }
        else  if(ch=='Q')
        {
            scanf("%d",&x);
            printf("%d\n",query(1,0,n-1,x-1,0));

        }


        getchar();


    }

    }

    return 0;
}
