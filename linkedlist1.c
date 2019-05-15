#include <stdio.h>
#include <stdlib.h>

//lets declare the structure

typedef struct node
{
    int data;
    struct node * next;
}node;
//lets write a function to create a linkedlist
node* create(int n);
void display(node * head);
int main()
{
   int n=0;
   node * head = NULL;
   printf("How many elements sir?");
   scanf("%d",&n);
   head = create(n);
   display(head);
    return 0;
}
//this is the function to create a linkedlist
node * create(int n)
{
    int i=0;
    node *head=NULL;
    node *temp=NULL;
    node *p=NULL;
    
    for(i=0;i<n;i++)
    {
        temp=(node *)malloc(sizeof(node));
        printf("\nenter value of node no %d",i+1);
        scanf("%d",&temp->data);
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            p=head;
            while(p->next != NULL)
                p=p->next;
            p->next = temp;
        }
    }
    return head;
}
void display(node * head)
{
    node *p = NULL;
    if(head == NULL)
    {
        printf("no element");
    }
    else
    {
        p=head;
        while(p != NULL)
        {
            printf("%d->",p->data);
            p=p->next;
        }
    }
}
