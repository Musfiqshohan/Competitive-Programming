#include<stdio.h>
#include<bits/stdc++.h>
struct node
{
  int roll;
	node *next;
};
node *root=NULL;

void append(int roll)
{
	if(root==NULL) //If the list is empty
	{
		root=new node();
		root->roll=roll;
		root->next=NULL;
	}
	else
	{
		node *current_node=root; //make a copy of root node
		while(current_node->next!=NULL) //Find the last node
		{
			current_node=current_node->next; //go to next address
		}
		node* newnode= new node(); //create a new node
		newnode->roll=roll;
		newnode->next=NULL;

		current_node->next=newnode; //link the last node with new node
	}
}

void print()
{
    node *search_node=root;
    while(search_node!=NULL)
    {
        printf("%d ",search_node->roll);
        search_node=search_node->next;
    }
    puts(" ");
}

void deletex(int roll)
{
     node* previous_node;
    previous_node=NULL;

    node *current_node;
    current_node=root;

        while(current_node->roll!=roll)
        {
            previous_node=current_node;
            current_node=current_node->next;
        }

        if(current_node==root)
        {   node *temp=root;
            root=root->next;
            delete(temp);
        }

        else
        {
            previous_node->next=current_node->next;
            delete(current_node);
        }

        print();
}

void pushback(int roll1, int roll2)
{
    node* current_node=root;
    node *previous_node=NULL;

    node *newnode;
    newnode= new node();
    newnode->roll=roll2;
    newnode->next=NULL;

    while(current_node->roll!=roll1)
    {
        previous_node=current_node;
        current_node=current_node->next;
    }

    if(current_node==root)
    {
        newnode->next=current_node;
        root=newnode;
    }
    else{
    previous_node->next=newnode;
    newnode->next=current_node;
    }

    print();

}

void pushafter(int roll1, int roll2)
{
    node* current_node;
    current_node=root;

    node* newnode;
    newnode= new node();
    newnode->roll=roll2;
    newnode->next=NULL;

    current_node=root;
    while(current_node->roll!=roll1)
    {
        current_node=current_node->next;
    }

    newnode->next=current_node->next;
    current_node->next=newnode;

    delete(current_node);//// herer delete is working
    print();

}
int main(){

    int x,y;
    for(int i=0;i<5;i++)
    {
        scanf("%d->",&x);

        append(x);
        print();
    }


    scanf("%d %d",&x,&y);
    //deletex(x);

   // pushback(x , y );

    pushafter(x,y);

    return 0;
}
