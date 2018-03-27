#include<bits/stdc++.h>
using namespace std;


struct node
{
    int key;
    node *left, *right;
    node()
    {
        key=0;
        left=NULL;
        right=NULL;
    }
};

struct BST
{
    node *head=NULL;


    node* insert(node*temp, int val)
    {
        if(head==NULL)
        {
            head= (node*) malloc(sizeof (node));
            head->key=val;
            head->left=head->right=NULL;
            return head;
        }

        if(temp==NULL)
        {
            node *newNode= (node*) malloc(sizeof (node));
            newNode->key=val;
            newNode->left=newNode->right= NULL;

            return newNode;
        }

        if(val<temp->key)
            temp->left=insert(temp->left,val);

        else if(val>temp->key)
            temp->right=insert(temp->right,val);

    }

    node* search(node*temp,int val)
    {
        if(temp==NULL)
            return temp;

        if(val<temp->key)
            return search(temp->left,val);
        else if(val>temp->key)
            return search(temp->right,val);
        else return temp;

    }

    void inorder(node *temp)
    {
        if(temp==NULL) return;

        inorder(temp->left);
        printf("%d\n",temp->key);
        inorder(temp->right);
    }



    int find_min(node *temp)
    {
        if(temp->left==NULL) return temp->key;
        find_min(temp->left);
    }
};

int main()
{
    BST tree;

    int n,i,x;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        tree.insert(tree.head,x);
    }

    tree.inorder(tree.head);

//    scanf("%d",&x);
//
//    node* ret=tree.search(tree.head,x);
//
//    if(ret==NULL)
//    printf("%p \n",ret);
//    else
//    printf("%p %d\n",ret,ret->key);

    cout<<tree.find_min(tree.head)<<endl;

    return 0;
}









