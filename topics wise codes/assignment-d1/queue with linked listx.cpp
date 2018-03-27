#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* next;

};

 struct queuex{

    node *front =NULL;
    node *rear = new node();

   // front->next=rear;
    void push(int x)
    {    node *temp= (node*) malloc(sizeof(node));
         temp->val=x;
         temp->next=NULL;

        if(front==NULL)
        {
            front=temp;
            front->next=NULL;
        }
        else if(front->next==NULL)
        {

            rear=temp;
            front->next= rear;
            rear->next=NULL;

        }
        else
        {   rear->next=temp;
            rear=rear->next;

        }

    }

    void pop()
    {
        if(front==rear) printf("an empty queue after popped\n");
        else
        front=front->next;
    }

    void print()
    {
        node* temp=front;
        if(front==rear) printf("The queue is empty.\n");
        else{
        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
        printf("\n");
        }


    }

};
int main()
{
    queuex list;
    int n,x,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        list.push(x);
        list.print();
    }

    list.pop();
    list.print();
    list.pop();
    list.print();



    return 0;
}

