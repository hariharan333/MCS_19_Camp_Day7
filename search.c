#include <stdio.h> 
#include <stdlib.h> 
#include<stdbool.h>
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
  
bool search(struct node* head, int x)
{
    
    struct node* current = head;
    while(current != NULL)
    {
       if(current->data == x)
            return true;
       current = current->next;
    }
    return false;
}
  

int main() 
{ 
  
  struct node* head = NULL; 
  int x = 2;
  
  push(&head, 7); 
  
  push(&head, 1); 
  
  push(&head, 2);
  
  push(&head, 5);

  search(head,x)? printf("yes") : printf("no");
  return 0;
 
} 
