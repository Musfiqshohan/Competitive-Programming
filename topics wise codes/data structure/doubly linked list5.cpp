#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *next;
    node *prev;
};

struct linked_list{

    node *head=NULL;

    void insrt_hd(int x)
    {
        node* newnode= (node*) malloc(sizeof(node));
        newnode->val=x;
        newnode->next= newnode->prev=NULL;


        if(head==NULL)
        {
            head=newnode;

        }
        else
        {
            head->prev=newnode;
            newnode->next=head;
            head=head->prev;

        }

    }

    void insrt_tl(int x)
    {
        node* newnode= (node*) malloc(sizeof(node));
        newnode->val=x;
        newnode->next= newnode->prev=NULL;

        if(head==NULL)
            head=newnode;
        else
        {
            node * temp= head;
            while(temp->next!=NULL)
                temp=temp->next;

                temp->next=newnode;
                newnode->prev= temp;

        }

    }

    void print()
    {
        node* temp= head;

        while(temp!=NULL)
            {
                printf("%d ",temp->val);
                temp=temp->next;

            }
        printf("\n");
    }

    void ReversePrint()
    {
        node *temp= head;

        while(temp->next!=NULL) temp=temp->next;

        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->prev;

        }

        printf("\n");

    }

};
int main()
{
    linked_list l;

    for(int i=1; i<5;i++)
    {

        l.insrt_hd(i);
       // l.insrt_tl(i);
        l.print();
    }

    l.ReversePrint();
}

