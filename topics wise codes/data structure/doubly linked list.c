#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node *prev , *next;
};

typedef struct doubly_linked_list{

    node *head=NULL, *temp=NULL;

    void insrt_Bfr(int x)
    {
        node *newnode= (node*) malloc(sizeof(node));

        newnode->data=x;
        newnode->next=NULL;

        newnode->next= head;
        newnode->prev=NULL;

        if(head!=NULL)
            head->prev=newnode;

        head=newnode;
    }

    void insrt_Aftr(int x)
    {
        node *newnode= (node*) malloc(sizeof(node));
        newnode->data=x;



        while(newnode->data!=current_node->data)

    }
};
