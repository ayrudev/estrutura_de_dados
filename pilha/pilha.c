// Pilha (Política FILO)
#include <stdio.h>
#include <stdlib.h>

struct node {
  int number;
  struct node *next;
};

struct node *push(struct node *head, int number) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->number = number;
  newNode->next = head;

  return newNode;
}

struct node *pop(struct node *head) {
  if (head == NULL) {
    printf("Pilha vazia\n");
    return NULL;
  }

  printf("%d\n", head->number);
  struct node *toFree = head;
  head = head->next;
  free(toFree);

  return head;
}

int main() {
  struct node *head = NULL;
  for (int i = 0; i < 100000000; i++) {
    head = push(head, i);
  }

  for (int i = 0; i < 100000000; i++) {
    head = pop(head);
  }
}
