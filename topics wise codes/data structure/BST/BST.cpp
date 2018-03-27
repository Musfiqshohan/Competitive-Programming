#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
};

node *fnd_node(node* temp,int num)
{
    if(temp==NULL) return temp;


    if( num < temp->val)
    return fnd_node(temp->left,num);

    else
    return fnd_node(temp->right,num);

}

void p_print(node *temp)
{


    if(temp!=NULL) {


    p_print(temp->left);
     cout<<temp->val<<endl;
    p_print(temp->right);

    }

}
struct BST
{
    node *head=NULL;


    void insrt(int num)
    {
        node *newnode= (node*)malloc(sizeof(node));
        newnode->val=num;
        newnode->left=NULL;
        newnode->right=NULL;

        if(head==NULL) head=newnode;
        else{
        node *temp= fnd_node(head,num);

        if(temp->left==NULL)
            temp->left=newnode;
        else if(temp->right)
            temp->right=newnode;
        }

    }


    void pre_print()
    {
        p_print(head);

    }

};

int main()
{
    BST tree;
   int num;

    while(1)
    {
        cin>>num;
        tree.insrt(num);
        tree.pre_print();
    }

    return 0;
}
