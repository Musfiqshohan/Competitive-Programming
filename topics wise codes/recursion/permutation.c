#include<stdio.h>
#include<bits/stdc++.h>
struct node{
    int roll;
    node *next;
};
node *root;


void print()
{
    node *current_node;
    current_node=root;

   // printf("%d ",current_node->roll);
    while(current_node!=NULL)
        {
            printf("%d ",current_node->roll);
            current_node=current_node->next;

        }
}

void append(int roll)
{
    if(root==NULL)
    {
        root= new node();
        root->roll=roll;
        root->next=NULL;
    }

    else
    {
        node *current_node;


        current_node=root;

        while(current_node->next!=NULL)
            current_node=current_node->next;

        node *newnode;
        newnode= new node();
        newnode->roll=roll;
        newnode->next=NULL;

        current_node->next=newnode;

    }

    print();

}

void apa(int x1,int x2)
{

}

int main()
{
    int n,i;

    for(i=0;i<5;i++) { scanf("%d",&n);  append(n); }

    return 0;
}
