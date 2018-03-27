#include<bits/stdc++.h>
using namespace std;

struct node{
    char val;
    node *next;
};

struct stackx{
    int top=0;
    node *head=NULL;


    void push(char x)
    {
        node *new_node= new node();
        new_node->val=x;
        new_node->next=NULL;


        if(head==NULL)
        {
            head=new_node;
        }
        else
        {
            new_node->next= head;
            head= new_node;
        }
        top++;

    }

    void pop()
    {
        head=head->next;
        top--;
    }

    char view_top()
    {
        if(head==NULL)
            return 'x';
        else return head->val;
    }

};

int main()
{
    stackx stk;
    char str[100];
    int i;
    scanf("%s",&str);

    for(i=0; str[i]; i++)
    {
        char x= str[i];


        if( stk.view_top()=='(' && x==')')
        {
            stk.pop();
        }
        else
           stk.push(x);
    }

    if(stk.top==0) printf("YES\n");
    else printf("NO\n");
}
