#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node *next;
};

struct queuex{

    node *frnt=NULL, *rear= NULL, *temp;

    void push(int x)
    {
        node *newnode;
        newnode= (node*)malloc(sizeof(node));

        newnode->val=x;
        newnode->next=NULL;

        if(rear==NULL)
        {
            frnt=newnode;
            rear=newnode;
        }
        else
        {
            rear->next=newnode;
            rear= rear->next;
        }

        rear->next=frnt;

    }

    void pop()
    {
        temp= frnt;
        if(frnt==NULL) printf("\nUnderFlow\n");
        else{

        if(frnt==rear) frnt=rear=NULL;
        else{
        frnt=frnt->next;
        rear->next= frnt;

        printf("%u %u\n",frnt, temp->next);
         temp->next=NULL;
        free(temp);
        }
        }



    }



    void print()
    {
        temp= frnt;
        if(frnt==NULL) printf("Empty\n");
        else
        {
           for(  ;temp!=rear;temp=temp->next)
            {
                printf("%d address=%u next=%u\n", temp->val, temp, temp->next);
                //temp= temp->next;
            }
            printf("%d address=%u next=%u\n", temp->val, temp , temp->next);

        }

        printf("\n");

    }

};
int main()
{

    queuex q;
    int i,x;

    do
    {
        int ch;
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            {
                scanf("%d",&x);
                q.push(x);
                break;

            }
            case 2:
                q.pop();

            case 3:
                q.print();
                break;


        }


    } while(1);

}
