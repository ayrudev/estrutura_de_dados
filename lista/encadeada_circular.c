// Implementação de lista circular simplesmente encadeada
#include <stdio.h>
#include <stdlib.h>

// Estrutura
struct node {
  int number;
  struct node *next;
};

// Função que insere um nó na lista
struct node *insert(struct node *head, int number) {
  // Criação do novo nó
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->number = number;
  newNode->next = NULL;

  // lista vazia
  if (head == NULL) {
    head = newNode;
    head->next = head;
    return head;
  }

  // lista não vazia
  struct node *last = head;
  while (last->next != head) {
    last = last->next;
  }

  last->next = newNode;
  newNode->next = head;
  return head;
}

// Função que exclui um nó da lista
struct node *delete(struct node *head, int number) {
  // lista vazia
  if (head == NULL) {
    return NULL;
  }

  // excluir o único
  if ((head->number == number) && (head->next == head)) {
    free(head);
    return NULL;
  }

  // excluir o primeiro
  if (head->number == number) {
    struct node *last = head;

    while (last->next != head) {
      last = last->next;
    }

    head = head->next;
    free(last->next); // limpa a cabeça velha (próximo do último)
    last->next = head;
    return head;
  }

  // excluir no meio ou no fim
  struct node *previous = head;
  while ((previous->next != head) && (previous->next->number != number)) {
    previous = previous->next;
  }

  if (previous->next == head) {
    return head;
  }

  struct node *toFree = previous->next;
  previous->next = previous->next->next;
  free(toFree);
  return head;
}

// Função que imprime a lista na tela
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

  head = insert(head, 1);
  head = insert(head, 2);
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 5);

  print(head);

  head = delete(head, 1);
  head = delete(head, 3);
  head = delete(head, 5);

  print(head);

  head = delete(head, 0);
  head = delete(head, 2);
  head = delete(head, 4);

  print(head);
}
