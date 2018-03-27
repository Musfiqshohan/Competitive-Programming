#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pr pair<int, int>
using namespace std;
char str[30009];


struct info{

   int open,close;

}tree[4*30009];


void update(int node, int beg, int endd, int targ)
{


    if(beg==targ && endd==targ)
    {
        if(tree[node].open==0 && tree[node].close==0)
        {

            if(str[targ]=='(')   tree[node].open=1;
            else tree[node].close=1;

        }
        else
        {

            if(tree[node].open==1) {tree[node].close=1;  tree[node].open=0; }
            else {tree[node].open=1; tree[node].close=0; }
        }

       // printf("%d ->%d %c %d %d\n",node,beg,str[targ], tree[node].open, tree[node].close);
        return ;

    }

    int left=node*2;
    int right=node*2+1;

    int mid= (beg+endd)/2;


    if(targ<=mid)
        update(left, beg,mid, targ);

    else
        update(right, mid+1, endd, targ);


    if(tree[left].open>=tree[right].close)
    {
        tree[node].open=tree[left].open- tree[right].close + tree[right].open;
        tree[node].close=tree[left].close;
    }
    else
    {
        tree[node].close= tree[right].close- tree[left].open + tree[left].close;
        tree[node].open=tree[right].open;
    }

//    tree[node].open= tree[left].open- tree[right].close  + tree[right].open;
//    tree[node].close=tree[right].close- tree[left].open + tree[left].close;


}


//void print()
//{
//       for(int i=1; i<=13; i++) printf("node=%d  brac=%d\n",i,tree[i].brac);
//}


int main()
{
    int t=0;
    while(t++<10){

    printf("Test %d:\n",t);
    int n,m,x;
    scanf("%d",&n);
    getchar();

    char str2[30009];
    scanf("%s",&str2);

    str[0]='\0';
    str[0]='A';

    strcat(str,str2);



    for(int i=1;i<=n;i++){
        update(1,1,n, i);
    }


    scanf("%d",&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        if(x==0)
        {
            if(n%2==1) printf("NO\n");
            if(tree[1].open==0 && tree[1].close==0) printf("YES\n"); else printf("NO\n");
        }
        else
            {update(1,1,n,x);
               // print();
            }
    }




    ms(tree,0);
    ms(str,0);
    ms(str2,0);

    }
    return 0;
}
