#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node{
  int data;
  struct node* next;
};

struct node* newNode(int data){
  struct node* nNode = (struct node*)malloc(sizeof(struct node));
  if(nNode == NULL){
    return NULL;
  }
  nNode->data = data;
  nNode->next = NULL;
  return nNode;

}

int pop(struct node** headRef){
  if(*headRef == NULL){
    return 0;
  }

  int data = (*headRef)->data;
  struct node* delHead = *headRef;
  (*headRef) = (*headRef)->next;


  free(delHead);
  return data;
}

void delete_list(struct node** headRef){
  if((*headRef) == NULL){
    return;
  }

  struct node* current = *headRef;
  struct node* next = NULL;

  while(current != NULL){
    printf("Free: %d\n", current->data);
    next = current->next;
    current->next = NULL;
    free(current);
    current = next;
  }

}

void insert_nth(struct node** headRef, int data, int n){
  assert(headRef != NULL);
  assert(n >= 0);

  if(n == 0 || *headRef == NULL){
    struct node* newHead = newNode(data);
    newHead->next = (*headRef);
    (*headRef) = newHead;
    return;
  }

    struct node* current = *headRef;
    struct node* prev = *headRef;

    int index = 0;
    while(current != NULL && index < n){
      index++;
      prev = current;
      current = current->next;
    }

    if(prev != NULL){
      prev->next = newNode(data);
      prev->next->next = current;
    }


}

void sorted_insert(struct node** headRef, int data){
  //assume sorted already.
  assert(headRef != NULL);

  struct node* current = *headRef;
  struct node* prev = NULL;
  while(current != NULL && data > current->data){
    prev = current;
    current = current->next;
  }

  struct node* nNode = newNode(data);

  if(prev != NULL){
    prev->next = nNode;
  }
  else{
    *headRef = nNode;
  }

  nNode->next = current;


}

void print_list(struct node* head){
  if(head == NULL){
    return;
  }
  struct node* current = head;
  while(current != NULL){
    printf("[%p|%d]\n", current, current->data);
    current = current->next;
  }
  printf("\n");
}

void append_second_list(struct node** a, struct node** b){
  //first option
  assert(a != NULL && b != NULL);

  if(*a == NULL){
    *a = *b;
    *b = NULL;
    return;
  }

  struct node* head = *a;

  while(head->next != NULL){
    head = head->next;
  }

  head->next = *b;
  *b = NULL;
}

void front_back_split(struct node* source, struct node** frontRef, struct node** backRef){
  //try fast and slow pointer method
  //initially both front and back reference are null so we have to populate it
  assert(frontRef != NULL && backRef != NULL);

  if(source == NULL){
    *frontRef = NULL;
    *backRef = NULL;
    return;
  }
  if(source->next == NULL){
    *frontRef = source;
    *backRef = NULL;
    return;
  }

  struct node* hare = source;
  struct node* turtle = source;
  
  while(hare != NULL){
    hare = hare->next;
    if(hare == NULL){
      break;
    }
    hare = hare->next;
    if(hare == NULL){
      break;
    }
    turtle = turtle->next;
  }

  *backRef = turtle->next;
  turtle->next = NULL;
  *frontRef = source;

}

int main(){
  struct node* head = (struct node*)malloc(sizeof(struct node));
  head->data = 10;
  head->next = NULL;
  head->next = newNode(60);
  head->next->next = newNode(5);
  print_list(head);
  printf("Popped Value: %d\n\n", pop(&head));
  print_list(head);
  //delete_list(&head);

  // printf("Inserting nth Element\n");
  // insert_nth(&head, 77, 2);
  // print_list(head);
  struct node* head2 = newNode(1);
   head2->next = newNode(3);
   head2->next->next = newNode(5);
   head2->next->next->next = newNode(7);
   head2->next->next->next->next = newNode(9);
   head2->next->next->next->next->next = newNode(10);
   head2->next->next->next->next->next->next = newNode(11);

  //sorted_insert(&head2, 8);
  print_list(head2);
  //append_second_list(&head, &head2);
  //print_list(head);

  struct node* frontRef = NULL;
  struct node* backRef = NULL;
  front_back_split(head2, &frontRef, &backRef);
  printf("Printing front back split results.\n");
  printf("Front: ");
  print_list(frontRef);
  printf("Back: ");

  print_list(backRef);
}
