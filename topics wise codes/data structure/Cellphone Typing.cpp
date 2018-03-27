#include<bits/stdc++.h>
using namespace std;

char str[100009][90];

struct node
{
    bool endmark;
    int childs=0,serial;
    node *next[26+1];
    node()
    {
        endmark=false;
        childs=0;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }
}*root;


void insert(char *str,  int len)
{
    node* curr=root;
    root->serial=0;

    for(int i=0; i<len; i++)
    {
        int id= str[i]-'a';

        if(curr->next[id]==NULL)
        {
            int num=curr->serial;
            curr->next[id]=new node();
            curr->childs++;
            curr->serial=num+1;
           // printf("seri= %d\n",curr->serial);
        }
        curr= curr->next[id];
    }

    //printf("len=%d\n",len);
   // printf("serial->%d\n",curr->serial);
    curr->endmark=true;
}

int search(char *str, int len)
{
    node *curr=root;
    int keystrokes=0;

    for(int i=0; i<len; i++)
    {
        int id= str[i]-'a';

        curr=curr->next[id];

        if(curr->childs >1 || curr->endmark==true)
            keystrokes++;

    }

    return keystrokes;
}


void del(node *curr)
{
    for(int i=0; i<26; i++)
    {
        if(curr->next[i])
            del(curr->next[i]);
    }

    delete(curr);

}
int main()
{

    int n;
    while(scanf("%d",&n)==1)
    {
        root= new node();
        getchar();

        for(int i=0; i<n; i++)
        {
            scanf("%s",&str[i]);
            getchar();

            insert(str[i],strlen(str[i]));
        }

        int tot=0,num=0;
        for(int i=0; i<n; i++)
        {
            num= search(str[i],strlen(str[i]));
           // cout<<num<<endl;
            tot+=num;

        }

        printf("%.2f\n",tot*1.0/n);

        del(root);


    }


    return 0;
}
