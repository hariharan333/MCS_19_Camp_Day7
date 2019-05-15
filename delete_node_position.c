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
  
void deleteNode(struct node** head_ref,int position)
{
    //1.linked list is empty
    if(*head_ref == NULL)
        return;
        
    //2.store the head node
    struct node* temp = *head_ref;
    
    if(position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return ;
    }
    for(int i=0; temp != NULL && i<position-1;i++)
        temp=temp->next;
        
    //if position is more than no.of nodes
    if(temp == NULL || temp->next ==NULL)
        return;
        
    struct node* next = temp->next->next;
    
    free(temp->next);
    
    temp->next = next;
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
  
  printf("linked list inside the all element:");
  print(head);
  
  deleteNode(&head,3);
  
  printf("\n remaining all element in linked list: "); 
  print(head); 
  
  return 0; 
} 
