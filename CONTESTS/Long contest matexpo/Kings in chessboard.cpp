#include<bits/stdc++.h>
#define i64 long long
using namespace std;

int ara[1029];
int f(int num)
{
    if(__builtin_popcount(num)!=2) return -1;

    bitset<10>bset(num);

    for(int i=0; i<9; i++)
    {
        if(bset[i]==bset[i+1] && bset[i]==1) return -1;
    }

    // cout<<bset<<endl;
    return 1;
}

struct matrix
{
    int row, col;
    unsigned v[37][37];

} mat, I;

void func(int pos, int root, int mask)
{
    if(pos>=10)
    {
        if(__builtin_popcount(mask)!=2)
            return ;

//        printf("%d %d\n",root,mask);
//        bitset<10>b1(mask);
//        bitset<10>b2(root);
//
//        cout<<b2<<" "<<b1<<endl;
        mat.v[ara[root]][ara[mask]]++;

        return;
    }


    int t1,t2,t3;
    t1=t2=t3=0;
    t1=root&(1<<pos);
    if(pos-1>=0)
        t2=root&(1<<(pos-1));
    if(pos+1<10)
        t3=root&(1<<(pos+1));

    if(t1==0 && t2==0 && t3==0)
    {
        func(pos+2,root,mask|(1<<pos));
    }

    func(pos+1, root, mask);

}

matrix multiply(matrix a, matrix b)
{
    matrix r;
    assert(a.col==b.row);
    r.row=a.row,  r.col=b.col;

    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            unsigned int sum=0;
            for(int k=0; k<a.col; k++)
            {
                sum+= a.v[i][k]*b.v[k][j];

            }

            r.v[i][j]=sum;
        }
    }

    return r;
}

matrix power(matrix base, int n)
{
    matrix res=I;

    while(n!=0)
    {
        // cout<<n<<endl;
        if(n&1)
            res=multiply(res,base);

        base=multiply(base,base);
        n=n>>1;
    }
    return res;
}





int main()
{
    int tot1=1<<10;

    int cnt=0;
    for(int i=0; i<tot1; i++)
    {
        if(f(i)==1)
        {
            ara[i]=cnt++;
        }
    }


    I.row=I.col=cnt;

    for(int i=0; i<cnt; i++)
        I.v[i][i]=1;

    mat.col=mat.row=cnt;




    for(int i=0; i<tot1; i++)
    {
        if(f(i)==-1) continue;

        func(0,i,0);
        // puts("");

    }


    int tt=0,test;
    cin>>test;

    while(tt<test)
    {

        int n;
        cin>>n;


        matrix matt=power(mat,n-1);



        unsigned int res=0;
        for(int i=0; i<cnt; i++)
        {
            for(int j=0; j<cnt; j++)
            {
                res+=matt.v[i][j];
            }
        }


        printf("Case %d: %lu\n",++tt,res);

    }


    return 0;
}
