#include<bits/stdc++.h>
#define pb push_back
using namespace std;
#define ms(a,b) memset((a),(b),sizeof(a))

int n,p;
vector<double>vec;
pair<int,int>par;

void make_vector(int a, int b)
{
    int last= (b/p)*p;

    int first= (a/p)*p;
    if(a%p!=0) first+=p;

    int tot= last/p - first/p +1;

    double res= b-a+1 -tot;
    res/=(b-a+1);
    vec.push_back(res);

}




int main()
{
    int l,r;
    scanf("%d %d",&n,&p);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&l,&r);
        make_vector(l,r);
    }


    double sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum+= 1-(vec[i]*vec[i+1]);
    }

    sum+= 1-(vec[0]* vec[n-1]);


   printf("%.6f\n", sum*2000);



    return 0;
}
