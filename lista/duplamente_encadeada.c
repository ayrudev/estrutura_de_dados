// Programa que implementa uma lista duplamente encadeada
#include <stdio.h>
#include <stdlib.h>

// Declaração da estrutura
struct node {
  int number;
  struct node *previous;
  struct node *next;
};

// Função que insere um nó na lista
struct node *insert(struct node *head, int number) {
  // Criação do novo nó
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->number = number;
  newNode->previous = NULL;
  newNode->next = head; // cabeça velha, antigo "primeiro"

  // Ajuste do apontamento da cabeça
  head = newNode;

  // Ajuste do anterior do segundo nó
  if (head->next != NULL) {      // Caso haja um segundo nó
    head->next->previous = head; // O anterior do segundo deve ser o primeiro
  }

  return head;
}

// Função que exclui um nó da lista
struct node *delete(struct node *head, int number) {
  // Lista vazia
  if (head == NULL) {
    return NULL;
  }

  // Único
  if (head->number == number) {
    struct node *toRemove = head;
    head = head->next;
    free(toRemove);

    if (head != NULL) { // Excluir o NÃO único
      head->previous = NULL;
    }
    return head;
  }

  // Procura do nó a ser excluido
  struct node *pointer = head;
  while ((pointer != NULL) && (pointer->number != number)) {
    pointer = pointer->next;
  }

  // Não encontrei o número na lista
  if (pointer == NULL) {
    return head;
  }

  // Excluir o último
  pointer->previous->next = pointer->next;
  if (pointer->next != NULL) { // Excluir no meio
    pointer->next->previous = pointer->previous;
  }
  free(pointer);

  // Retorno da cabeça atualizada
  return head;
}

// Imprime a lista
void printList(struct node *head) {
  struct node *pointer = head;

  while (pointer != NULL) {
    printf("%d\n", pointer->number);
    pointer = pointer->next;
  }
}

int main(int argc, char *argv[]) {
  // Declaração da cabeça da lista
  struct node *head = NULL;

  // Primeiro teste
  /* printList(head);
  head = delete(head, 0);

  head = insert(head, 1);
  head = insert(head, 2);
  head = insert(head, 3);
  head = insert(head, 4);
  head = insert(head, 5);
  printList(head);

  head = delete(head, 0);
  head = delete(head, 1);
  head = delete(head, 3);
  head = delete(head, 5);
  printList(head);

  head = delete(head, 2);
  head = delete(head, 4);
  printList(head); */

  // Segundo teste
  for (int i = 0; i < 1000000000; i++) {
    head = insert(head, i);
    printf("%d\n", i);
  }

  return 0;
}
