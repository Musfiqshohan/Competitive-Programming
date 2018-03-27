#include<bits/stdc++.h>
using namespace std;
int a[200],bst[200];
struct node
{
    int val, index;
};
stack<node>stk;

void inorder(int root)
{
    if(bst[root]==0) return;

    inorder(root*2);
    printf("%d\n",bst[root]);
    inorder(root*2+1);

}
int main()
{
    int n,i,tindex;
    scanf("%d",&n);

    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);


    for(i=1; i<=n; i++)
    {
        if(stk.empty()==true) {stk.push({a[i],1}); bst[1]=a[i];  }
        else if(a[i]<stk.top().val)
        {
           // printf("1i=%d->%d\n",i,a[i]);
           // printf("when less= %d less than %d    %d\n",a[i],stk.top().val,tindex);
            int tindex=stk.top().index*2;
            bst[tindex]=a[i];
            stk.push({a[i], tindex});

        }
        else
        {
            node frnt;
           // printf("2i=%d->%d\n",i,a[i]);
            while(!stk.empty() && stk.top().val<a[i])
            {
                 frnt=stk.top();
                stk.pop();
            }

            tindex=frnt.index*2+1;
            bst[tindex]=a[i];
            stk.push({a[i],tindex});
        }

    }

    inorder(1);
//    for(i=1;i<=n+1;i++)
//        printf("%d->%d ",i,bst[i]);

}
