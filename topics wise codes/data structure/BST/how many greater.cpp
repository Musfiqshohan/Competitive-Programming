#include<bits/stdc++.h>
using namespace std;


struct node
{
    int key;
    node *left, *right;
    int  greater_than, increase_right;
    node(int val)
    {
        key=val;
        left=NULL;
        right=NULL;
        greater_than=1;
        //increase_right=0;
    }

};

struct BST
{
    node *head=NULL;


    node* insert(node*temp, int val)
    {
        if(head==NULL)
        {
            head= new node(val);
            return head;
        }

        if(temp==NULL)
        {
            node newNode= new node(val);
            return newNode;
        }

        if(val<temp->key)
        {

            temp->greater_than++;
            //  temp->increase_right++;
            if(temp->left == NULL)
            {
                node newNode= new node(val);
                temp->left = newNode;
                temp->left->greater_than = temp->greater_than + 1;
                return;
            }
            else
                temp->left = insert(temp->left,val);

        }

        else if(val>temp->key)
        {
            temp->greater_than++;
            increase(temp->left);
            temp->right=insert(temp->right,val);

        }

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
    int find_ (node* temp,int k)
    {
        if(temp==NULL)
            return 0;
        if(temp->val <= k)
        {
            if(temp->val == k || temp->left == NULL || temp->left->val < k)
            {
                return temp->greater_than;
            }
            else
            {
                return find_(temp->left,k);
            }
        }
        else
        {
            return find_(temp->right,k);
        }

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
    void increase(node* temp)
    {
        if(temp==NULL)
            return;
        increase(temp->left);
        increase(temp->right);
        temp->greater_than++;
    }
};

int main()
{
    BST tree;

    int n,i,x;

    scanf("%d",&n);

    for(i=0; i<n; i++)
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









