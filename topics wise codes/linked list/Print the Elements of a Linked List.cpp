#include<stdio.h>
#include<bits/stdc++.h>
struct node
{
  int roll;
	node *next;
};

node *root=NULL;
node *tail=NULL;

Node* Insert(Node *head,int data)
{


    if(head==NULL)
    {
         Node *newnode= new Node();
        newnode->data=data;
        newnode->next=NULL;
        head=newnode;
        tail=head;
        return head;
    }
    else
    {



       Node *newnode= new Node();
        newnode->data=data;
        newnode->next=NULL;

        tail->next=newnode;
        tail=tail->next;
        return head;
    }

}


