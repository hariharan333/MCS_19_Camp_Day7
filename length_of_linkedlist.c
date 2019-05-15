/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h> 
#include <stdlib.h> 
  
// A linked list node 
struct node 
{ 
  int data; 
  struct node *next; 
}; 
  
/* Given a reference (pointer to pointer) to the head of a list and  
   an int, inserts a new node on the front of the list. */
void push(struct node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
  
    /* 2. put in the data  */
    new_node->data  = new_data; 
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 
  
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node; 
     
  
    
    
} 
  
int getCount(struct node* head)
{
    int count = 0;
    struct node* current = head;
    while(current != NULL)
    {
       
        current = current->next;
         count++;
    }
    return count;
}
  
// This function prints contents of linked list starting from head 
void print(struct node *n) 
{ 
  while (n != NULL) 
  { 
     printf(" %d ", n->data); 
     n = n->next; 
  } 
} 
  

int main() 
{ 
  
  struct node* head = NULL; 
  
  push(&head, 7); 
  
  push(&head, 1); 
  
  push(&head, 2);
  
  push(&head, 5);
  
  print(head);
  printf("total nodes = %d",getCount(head));
  return 0;
 
} 
