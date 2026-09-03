// Implementação de lista circular duplamente encadeada
#include <stdio.h>
#include <stdlib.h>

struct node {
  int number;
  struct node *previous;
  struct node *next;
};

struct node *insert(struct node *head, int number) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->number = number;

  // Lista vazia
  if (head == NULL) {
    head = newNode;
    head->previous = head;
    head->next = head;
    return head;
  }

  // Lista não vazia
  struct node *last = head->previous;
  last->next = newNode;
  newNode->previous = last;
  newNode->next = head;
  head->previous = newNode;
  return head;
}

struct node *delete(struct node *head, int number) {
  // Lista vazia
  if (head == NULL) {
    return NULL;
  }

  // Excluir o único
  if (head->next == head && head->number == number) {
    free(head);
    return NULL;
  }

  // Excluir o primeiro
  if (head->number == number) {
    struct node *last = head->previous;
    head = head->next;
    head->previous = last;

    free(last->next);
    last->next = head;
    return head;
  }

  // Número no meio/fim
  struct node *previous = head;
  while (previous->next->number != number && previous->next != head) {
    previous = previous->next;
  }

  // Número não está na lista
  if (previous->next->number != number) {
    return head;
  }

  // Número encontrado
  previous->next = previous->next->next;
  free(previous->next->previous);
  previous->next->previous = previous;
  return head;
}

void print(struct node *head) {
  if (head == NULL) {
    return;
  }

  struct node *pointer = head;
  do {
    printf("%d\n", pointer->number);
    pointer = pointer->next;
  } while (pointer != head);
}

int main() {
  struct node *head = NULL;

  print(head);
  head = delete(head, 0);
  print(head);

  head = insert(head, 1);
  head = insert(head, 2);
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 5);
  print(head);

  printf("\n");
  head = delete(head, 0);
  head = delete(head, 1);
  head = delete(head, 3);
  head = delete(head, 5);
  print(head);

  printf("\n");
  head = delete(head, 2);
  head = delete(head, 4);
  print(head);
}
