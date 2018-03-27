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


int isBST(node *temp, int mn, int mx)
{
    if(temp==NULL) return 1;

    if(temp->key<mn || temp->key>mx)
        return 0;

    return isBST(temp->left, mn, temp->key-1) && isBST(temp->right, temp->key+1, mx);
}
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->key = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->right = newNode(3);

  if(isBST(root,INT_MIN, INT_MAX))
    printf("Is BST");
  else
    printf("Not a BST");

  getchar();
  return 0;
}

