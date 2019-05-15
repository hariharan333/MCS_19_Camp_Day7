/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

struct node   
{
    int data;
    struct node* next;
};

void print(struct node* n)
{
    while(n != NULL)
    {
        printf("%d",n->data);
        n=n->next;
    }
}
int main()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    
    //allocated to three node in the heap
    
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));
    
    //head node 
    
    head->data = 1;
    head->next = second;
    
    //seocnd node
    
    second->data = 2;
    second->next = third;
    
    //third node
    
    third->data = 3;
    third->next = NULL;
    
    print(head);
    return 0;
}

