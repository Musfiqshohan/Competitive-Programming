#include<stdio.h>

typedef struct node{
    int val;
    node* next;

};

 struct queue{

    node *front =NULL;
    node *rear =NULL;
    void push(int x)
    {    node *temp= (node*) malloc(sizeof(node));
         temp->val=x;
         temp->next=NULL;

        if(front==NULL)
        {
            front=temp;
            front->next=rear;
        }
        else
        {
            rear=temp;
            rear=rear->next;
        }

    }

   /* void pop()
    {

    }*/

    void print()
    {


    }

};
int main()
{
    queue list;
    int n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        list.push(x);
        list.print();
    }





}
