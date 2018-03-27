#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pr pair<int, int>
using namespace std;

int main()
{
    int n,m,x;
    scanf("%d",&n);
    getchar();

    char str2[30009];
    scanf("%s",&str2);

    str[0]='\0';
    str[0]='A';

    strcat(str,str2);

    printf("%s\n",str);

 for(int i=1;i<=n;i++){
        update(1,1,n, i);
    }

     for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        if(x==0)
        {
            if(n%2==1) printf("NO\n");
            else if(tree[1].isCorrect==1) printf("YES\n"); else printf("NO\n");
        }
        else
            update(1,1,n,x);
    }

    ms(tree,0);
    ms(str,0);

    return 0;
}
