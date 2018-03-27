#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *next;

};
struct linked_list{

   // node *head= ( node*) malloc(sizeof(node));
    node *head= NULL;

    void push(int x)
    {
        if(head==NULL)
        {   head= (node*)malloc(sizeof(node));
            head->val=x;
            head->next=NULL;
        }
        else
        {
            node *temp=  (node*)malloc(sizeof(node));
            temp->val=x;
            temp->next=head;
            head=temp;
        }
    }

    void pop()
    {
        node *temp;
        temp=head;
        head=head->next;
        free(head);
    }

    void print()
    {
        node *temp;
        temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->val);
            temp=temp->next;
        }
        printf("\n");
    }


};
int main()
{
    linked_list list;
    int i,x,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    scanf("%d",&x);
    list.push(x);
    list.print();
    }

    scanf("%d",&n);
    for(i=0;i<n;i++){
    list.pop();
    list.print();
    }


    return 0;
}
