Node* Insert(Node *head,int data)
{

    if(head==NULL)
    {
        Node *newnode=new node();
        newnode->data=data;
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        Node *newnode=new node();
        newnode->data=data;
         newnode->next=NULL;
        newnode->next=head;
        head=newnode;
    }
    return head;
}
