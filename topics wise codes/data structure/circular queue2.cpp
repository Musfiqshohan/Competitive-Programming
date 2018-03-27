#include<bits/stdc++.h>
using namespace std;

struct  node
{
    int val;
    node* next;
};

struct linked_list
{

    node *frnt=NULL, *rear=NULL, *temp;

    void insrt(int x)
    {
        node *newnode;
        newnode= (node*) malloc(sizeof(node));
        newnode->val=x;
        newnode->next=NULL;

        if(rear==NULL)
        {
            frnt=rear=newnode;
        }
        else
        {
            rear->next= newnode;
            rear=rear->next;                    // i used newnode->next=NULL ,,so that rear->next will always be null
        }

        rear->next=frnt;
    }

    void dlt()
    {
        temp=frnt;

        if(frnt==NULL) printf("Underflow\n");
        else if(  frnt==rear) frnt=rear=NULL;
        else
        {
            frnt=frnt->next;
            rear->next=frnt;
            temp->next=NULL;
            free(temp);
        }


    }

    void traverse()
    {
        temp=frnt;
        if(rear==NULL) printf("Empty\n");
        else
        {
            for(  ; rear!=temp; temp= temp->next)
                printf("%d ",temp->val);

            printf("%d \n",temp->val);
        }

    }
};

struct queuex
{
    linked_list l;

    void push(int x)
    {
        l.insrt(x);
    }

    void pop()
    {
        l.dlt();
    }

    void print()
    {
        l.traverse();
    }



};
int main()
{
    queuex q;

    do
    {   int x,ch;
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
            scanf("%d",&x);
            q.push(x);
            break;
            }

        case 2:
            {
                q.pop();
            }
        case 3:
            {
                q.print();
                break;
            }
        case 4:
            exit(1);
            break;

        }

    }
    while(1);


}






