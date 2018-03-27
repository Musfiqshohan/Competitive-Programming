#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;
struct node{

    int roll;
    node *prev, *next;
    node()
    {
        prev=NULL;
        next=NULL;
    }
};

node *root=NULL;
node *tail=NULL;

void print()
{
    node *search_node=root;
    while(search_node!=NULL)
    {
        printf("%d ",search_node->roll);
        search_node=search_node->next;
    }
    puts(" ");
}

void append(int roll)
{
    if(root==NULL)
    {
        root=new node();
        root->roll=roll;
        root->next=NULL;
        tail=root;
    }
    else
    {
        node *newnode;
        newnode= new node();
        newnode->roll=roll;
        newnode->next=NULL;
        tail->next=newnode;
        tail=tail->next;
    }

    print();

}


void deletex(int roll)
{
    node *current_node=root;
    while(current_node->roll!=roll)
    {
        current_node=current_node->next;
    }

    //node *temp;
    //temp=current_node->prev;

    current_node->prev->next=current_node->next;

   // temp->next=current_node->next;


    print();

}
int main()
{
  int x,y;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&x);
        append(x);

    }

    scanf("%d",&x);
    deletex(x);
}
