#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct node{
    char val;
    node *next;
};


struct stackx
{   int top;
    node *head=NULL;

    void push(char x)
    {
        node *new_node= (node*)malloc(sizeof(node));
        new_node->val=x;
        new_node->next=NULL;

        if(head==NULL)
        {
            head=new_node;

        }
        else
        {
            new_node->next=head;
            head=new_node;
        }
        top++;

    }

    void pop()
    {
        head=head->next;
        top--;
    }

    char view_top()
    {   if(head==NULL) return 'x';
        return head->val;
    }


};
int main()
{
    stackx stk;
    stk.top=0;

    int i=0,countx=0,count2=0,maxx=0,last=0,num=0;
    char x;
    char str[100009];
    scanf("%s",&str);

    while(str[i]==')')
    {   x=str[i];
        stk.push(x);
        i++;
    }

    for( ; str[i] ; i++)
    {
        x= str[i];

       //if(stk.top==0) {stk.push(x);   num++;    last++;  }

        if(stk.view_top()=='(' & x==')')
            {
                stk.pop();
                last++;
                num--;

            }
        else if(x==')') num--;
        else
        {
            stk.push(x);
            num++;
            last++;
        }

        if(num==-1)
        {
            countx++;
            if(last >maxx) maxx=last;
            last=0;
        }

       // printf("%c ",stk.view_top());
    }

    if(num!=0)   last= last-num;
    if(last>maxx) maxx=last;
   // printf("%d \n",maxx);




   i=0,countx=0,count2=0,last=0,num=0;

     while(str[i]==')')
    {   x=str[i];
        stk.push(x);
        i++;
    }

    for( ; str[i] ; i++)
    {
        x= str[i];

       //if(stk.top==0) {stk.push(x);   num++;    last++;  }

        if(stk.view_top()=='(' & x==')')
            {
                stk.pop();
                last++;
                num--;

            }
        else if(x==')') num--;
        else
        {
            stk.push(x);
            num++;
            last++;
        }

        if(num==-1)
        {

            if(last ==maxx) countx++;
            last=0;
        }

       // printf("%c ",stk.view_top());
    }

    if(num!=0)   last= last-num;
    if(last==maxx) countx++;

    printf("%d %d\n",maxx,countx);


    return 0;
}
