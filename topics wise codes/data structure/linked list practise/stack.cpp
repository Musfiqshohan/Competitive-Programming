#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node* next, *prev;
};
struct stackx{

    node*top=NULL;

    void push(int x)
    {
        node *newNode= new node();
        newNode->key=x;

        if(top==NULL) {top=newNode;
            top->next=top->prev=NULL;
        }
        else{
        top->next=newNode;
        newNode->prev=newNode->next=NULL;
        newNode->prev=top;
        top=newNode;

        }
    }

    void pop()
    {
        node*temp= top;
        top=top->prev;
        free(temp);

    }

    node* rettop()
    {
        return top;
    }

    void print()
    {
        while(top!=NULL)
        {
            printf("%d\n",rettop()->key);
            pop();
        }
    }


};
int main()
{
    stackx stk;
    int n,i,x;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);

        stk.push(x);
    }

    stk.pop();
    stk.print();
}
