// Programa que implementa uma lista simplesente encadeada

#include <stdio.h>
#include <stdlib.h>

// Estrutura que modela o nó da lista
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

  // Cenário fácil: lista vazia
  if (head == NULL) {
    return newNode;
  }

  // Cenário difícil: lista NÃO vazia
  struct node *last = head;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = newNode;
  return head;
}

// Função que exclui um nó da lista
struct node *delete(struct node *head, int number) {
  // Cenário muito fácil:
  if (head == NULL) {
    return head;
  }

  // Cenário fácil: excluir o primeiro
  if (head->number == number) {
    struct node *to_delete = head;
    head = head->next;
    free(to_delete);
    return head;
  }

  // Procura do nó ANTERIOR ao que será excluido da lista
  struct node *previous = head;
  while ((previous->next != NULL) &&           // Não achei e parei no último
         (previous->next->number != number)) { // Achei e parei no anterior
    previous = previous->next;
  }

  // Cenário difícil: não foi encontrado
  if (previous->next == NULL) {
    return head;
  }

  // Cenário difícil: excluir no meio ou fim
  struct node *to_delete = previous->next;
  previous->next = previous->next->next;
  free(to_delete);
  return head;
}

// Função que imprime a lista
void printList(struct node *head) {
  struct node *pointer = head;
  while (pointer != NULL) {
    printf("%d\n", pointer->number);
    pointer = pointer->next;
  }
}

// Função principal de execução do programa
int main() {
  struct node *head = NULL;

  // Primeiro teste
  printList(head);
  head = delete(head, 100);

  head = insert(head, 1);
  head = insert(head, 2);
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 5);

  printList(head);

  head = delete(head, 1);
  head = delete(head, 3);
  head = delete(head, 5);

  printList(head);

  // Segundo teste
  /*
  for (int i = 0; i < 1000000; i++) {
    head = insert(head, i);
    printf("%d\n", i);
  }
  */
  return 0;
}
