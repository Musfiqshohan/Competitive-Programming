#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node* next;
};

struct queuex
{

    node* frnt=NULL, *rear=NULL, *temp, *extra;
    int i;
    void push(int x)
    {
        node *newnode= (node*) malloc(sizeof(node));
        newnode->val=x;
        newnode->next=NULL;
        if(rear==NULL)
        {
            rear=frnt=newnode;
        }
        else
        {
            rear->next=newnode;
            rear=rear->next;
        }

        rear->next=frnt;
    }


    void del(int k)
    {
        temp=frnt;

        while(temp!=temp->next)
        {
            for(i=1;i<k;i++)
                {temp=temp->next;
                 printf("%d  ",temp->val);
                }

            extra=temp->next;
            temp->next= temp->next->next;
            temp=temp->next;
            free(extra);
        }
        printf("%d\n",temp->val);
        free(temp);
    }



};
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    queuex q;
    int i,n,m;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        q.push(i);

    }

    printf("Case %d: ",t+1);
    q.del(m);
   // printf("\n");



    }


    return 0;
}
