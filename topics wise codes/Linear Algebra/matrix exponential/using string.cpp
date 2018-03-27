#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int i,j,k;
struct matrix{
    int row,col;
    int v[20][20];
};

matrix multiply(matrix &a,matrix &b)
{
    int sum=0;
    matrix r;
    assert(a.col==a.row);
    r.row=a.row, r.col=b.col;

    for(i=0;i<r.row;i++)
    {
        for(j=0;j<r.col;j++)
        {   sum=0;
            for(k=0;k<a.col;k++)
                sum+=a.v[i][k]*b.v[k][j];
            r.v[i][j]=sum;
        }
    }

    return r;
}
string binary(int p) {
  string ret = "";
  while (p > 0) {
    ret += (p % 2 == 0) ? "0" : "1";
    p /= 2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

matrix power(matrix mat, int p)
{
    int i;
    string bin=binary(p);
    cout<<bin<<endl;
    matrix ret=mat;
    for(i=1;i<bin.size();i++)
    {   printf("%d %c\n",i,bin[i]);
        ret=multiply(ret,ret);
        if(bin[i]=='1')
            ret=multiply(ret,mat);
    }
    return ret;

}



int main()
{   while(1){
    int n,ans;
    matrix mat;
    mat.row=mat.col=2;
    mat.v[0][0]=mat.v[0][1]=mat.v[1][0]=1;
    mat.v[1][1]=0;

    scanf("%d",&n);

    if(n==0) printf("0\n");
    else if(n==1) printf("1\n");
    else if(n==2) printf("1\n");
    else{
    mat=power(mat,n-1);

    ans=mat.v[0][0]*1+mat.v[0][1]*1;
    printf("%d\n",ans);
    }

    }


return 0;
}
