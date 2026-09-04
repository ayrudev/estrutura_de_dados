// Fila (Política FIFO)

#include <stdio.h>
#include <stdlib.h>

// Declaração da estrutura do nó
struct node {
  int number;
  struct node *next;
};

// Função de entrada de dados
struct node *insert(struct node *head, int number) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->number = number;
  newNode->next = head;
  return newNode;
};

// Função de saída de dados
struct node *pop(struct node *head) {
  if (head == NULL) {
    printf("Fila vazia\n");
    return NULL;
  }

  if (head->next == NULL) {
    printf("%d\n", head->number);
    free(head);
    return NULL;
  }

  struct node *ptr = head;
  while (ptr->next->next != NULL) {
    ptr = ptr->next;
  }
  printf("%d\n", ptr->next->number);
  free(ptr->next);
  ptr->next = NULL;
  return head;
}

int main() {
  struct node *head = NULL;
  for (int i = 0; i < 100000; i++) {
    head = insert(head, i);
  }

  for (int i = 0; i < 100000; i++) {
    head = pop(head);
  }
}
