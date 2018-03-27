#include<bits/stdc++.h>
using namespace std;

struct node{

    int roll;
    node *left, *right;
    node()
    {
        left=NULL;
        right=NULL;
    }
};

node *root;

void print_preorder(node *current)
{
	if(current==NULL) return;
	cout<<current->roll<<endl;
	print_preorder(current->left);
	print_preorder(current->right);

}
void insertx(int roll)
{
    if(root==NULL)
    {
        root=new node();
        root->roll=roll;
    }
    else
    {
        node *current_node=root, *parent;
        while(current_node!=NULL)
        {
            parent=current_node;
            if(roll>current_node->roll)
                current_node=current_node->right;
            else
                current_node=current_node->left;

        }

        node *newnode;
        newnode= new node();
        newnode->roll=roll;

        if(newnode->roll>parent->roll)
            parent->right=newnode;
        else
            parent->left=newnode;

    }

    print_preorder(root);
}


int main()
{
    int i,x;
    for(i=0;i<4;i++)
    {scanf("%d",&x);
        insertx(x);

    }

}
