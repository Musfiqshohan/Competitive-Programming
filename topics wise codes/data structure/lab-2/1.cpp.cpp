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
int main()
{
    int n,i,x;
    linked_list l;


    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        l.insert_last(x);
        l.print();
    }

    while(1){
    scanf("%d",&n);
    if(n==1){
    scanf("%d",&x);
    l.insert_first(x);
    l.print();
    }

    if(n==2){
    l.del_first();
    l.print();
    }

    else if(n==3){
    l.del_last();
    l.print();
    }

    else if(n==4){
    scanf("%d",&x);
    printf("%d th from beg   and ",l.sea_beg(x));
    printf("%d th from last\n",l.sea_last(x));
    }

    else if(n==5)
    {   scanf("%d",&x);
           l.insert_last(x);
        l.print();
    }

    }


    return 0;
}
