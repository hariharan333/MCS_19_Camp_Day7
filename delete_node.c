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
  
void deleteNode(struct node** head_ref,int key)
{
    //store the head node
    struct node* temp = *head_ref,*prev;
    
    //if check to head element is equal to key
    if(temp != NULL && temp->data == key)
    {
       *head_ref  = temp->next;
        free(temp);
        return;
    }
    
    //check the all nodes in linked list
    
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    
    //if key was not present in linked list
    if(temp == NULL)
        return;
        
        prev->next = temp->next;
        
        free(temp);
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
  
  deleteNode(&head,1);
  
  printf("\n remaining all element in linked list: "); 
  print(head); 
  
  return 0; 
} 
