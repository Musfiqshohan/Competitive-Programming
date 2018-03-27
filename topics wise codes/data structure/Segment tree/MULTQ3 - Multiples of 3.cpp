///Wrong one

#include<bits/stdc++.h>
using namespace std;

struct data{
    int  propflag=0;
    int a[4];
};
data tree[4*100009];


data merger(data x, data y)
{
    x.a[0]+= y.a[0];
    x.a[1]+= y.a[1];
    x.a[2]+= y.a[2];
    return x;
}

void init(int node,  int  beg, int endd)
{

    if(beg==endd)
    {
        tree[node].a[0]=1;
        return ;
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    init(left, beg, mid);
    init(right, mid+1, endd);

    tree[node] = merger(tree[left], tree[right]);

}
void update(int node, int beg, int endd, int i, int j)
{



    if(i>j) return;

    if(beg==i && endd ==j)
    {

        tree[node].propflag=1;

            swap(tree[node].a[0],tree[node].a[2]);
            swap(tree[node].a[1], tree[node].a[2]);


        return ;
    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;

    update(left,beg,mid, i, min(mid,j) );
    update(right, mid+1, endd,  max(i,mid+1), j);

     if(tree[3].propflag==1) printf("Fucl\n");
    tree[node]= merger( tree[left] , tree[right]);

}

void print(data temp)
{
    for(int i=0;i<3;i++) printf("%d ",temp.a[i]);
     puts("");
}

data query(int node, int beg, int endd ,int i , int j, int carry)
{

    if(i>j)
    {
        data temp;
        temp.a[0]=temp.a[1]= temp.a[2]=0;
        return temp;
    }

    if(beg==i && endd ==j)
    {

            carry= carry%3;
            if(carry==1)
            {
                swap(tree[node].a[0],tree[node].a[2]);
                swap(tree[node].a[1], tree[node].a[2]);

            }
            else if(carry==2)
            {
                swap(tree[node].a[0],tree[node].a[1]);
                swap(tree[node].a[1],tree[node].a[2]);
            }



        return tree[node];


    }

    int left= node*2;
    int right= node*2+1;

    int mid= (beg+endd)/2;


    data l= query(left, beg, mid,  i, min(mid,j), carry+ tree[node].propflag);

    data r= query(right, mid+1, endd,  max(mid+1,i), j, carry+ tree[node].propflag);

    return merger(l,r);

}
int main()
{

    int n,q,i,cs,x,y;

    scanf("%d %d",&n,&q);

    init(1,1,n);


    for(i=0;i<q;i++)
    {
        scanf("%d %d %d",&cs,&x,&y);


        if(cs==0)
        {
            update(1,1,n,x+1,y+1);

             for(i=0;i<=14 ;i++) printf("propnode =%d node=%d\n",tree[i].propflag,i);


        }
        else
        {
            data temp=query(1,1,n,x+1,y+1,0);


            printf("%d\n",temp.a[0]);




        }


    }
}
