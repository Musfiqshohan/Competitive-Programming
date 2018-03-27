#include<stdio.h>

struct node{
    int val;
    node *prev;
    node *next;
};

struct linked_list{
    node *head=NULL;
    node *tail=NULL;

    void insert_last(int x)
    {
        node *new_node;
        new_node= new node();
        new_node->val=x;
        new_node->prev=NULL;
      new_node->next=NULL;

        if(head==NULL)
        {
            head=new_node;
            tail=head;

        }
        else
        {
            new_node->prev=tail;
            tail->next=new_node;
            tail=tail->next;
        }

    }

    void insert_first(int x)
    {
         node *new_node;
        new_node= new node();
        new_node->val=x;
        new_node->prev=NULL;
       new_node->next=NULL;


        new_node->next=head;
        head->prev=new_node;
        head=new_node;


    }

    int  sea_beg(int x)
    {   int countx=0;
        node *current_node= head;
        while(current_node->val!=x){
            current_node=current_node->next;
            countx++;
        }

        return countx+1;

    }

    int sea_last(int x)
    {
        int countx=0;
        node *current_node=tail;
        while(current_node->val!=x)
        {
            current_node=current_node->prev;
            countx++;
        }
        return countx+1;
    }


    void print()
    {
        node *current_node= head;
        while(current_node!=tail->next)
        {
            printf("%d ",current_node->val);
            current_node=current_node->next;
        }
        printf("\n");
    }
    void del_first()
    {

        head=head->next;
        head->prev=NULL;



    }

    void  del_last()
    {
        tail=tail->prev;
        tail->next=NULL;

    }


};

struct queuex{

    linked_list l;
    void push(int x)
    {
        l.insert_last(x);

    }

    void pop()
    {

        l.del_first();
    }

    void print()
    {
        l.print();

    }





};
int main()
{
    int n,i,x;
    queuex q;


    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        q.push(x);
        q.print();
    }

    q.pop();
    q.print();



    return 0;
}
