// Implementção de uma double ended queue
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Variaveis globais
int counter = 1;

// Estruturas
struct node {
  int number;
  struct node *next;
};

struct deque {
  struct node *normal_queue;
  struct node *preferencial_queue;
};

// Métodos
struct node *insert(struct node *queue, int number) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->number = number;
  newNode->next = queue;
  return newNode;
}

struct node *delete(struct node *queue) {
  if (queue == NULL) {
    return NULL;
  }

  if (queue->next == NULL) {
    printf("%i\n", queue->number);
    free(queue);
    return NULL;
  }

  struct node *ptr = queue;
  while (ptr->next->next != NULL) {
    ptr = ptr->next;
  }
  printf("%i\n", ptr->next->number);

  free(ptr->next);
  ptr->next = NULL;

  return queue;
}

void serve(struct deque *head) {
  if (head->normal_queue == NULL && head->preferencial_queue == NULL) {
    // ambas filas vazias
    return;

  } else if (head->preferencial_queue == NULL) {
    // fila normal apenas
    head->normal_queue = delete(head->normal_queue);
    counter = 1;
    return;

  } else if (head->normal_queue == NULL) {
    // fila preferencial apenas
    head->preferencial_queue = delete(head->preferencial_queue);
    counter = 1;
    return;
  } else if (counter % 4 == 0) {
    head->normal_queue = delete(head->normal_queue);
  } else {
    head->preferencial_queue = delete(head->preferencial_queue);
  }
  counter++;
  return;
}

int main() {
  // inicialização do deque
  struct deque *head = (struct deque *)malloc(sizeof(struct deque));
  head->normal_queue = NULL;
  head->preferencial_queue = NULL;

  // atendimento filas vazias
  serve(head);

  // atendimento apenas fila normal
  for (int i = 0; i < 10; i++) {
    head->normal_queue = insert(head->normal_queue, i);
  }

  for (int i = 0; i < 10; i++) {
    serve(head);
  }

  printf("\n"); // separador

  // atendimento apenas fila preferencial
  for (int i = 1000; i < 1010; i++) {
    head->preferencial_queue = insert(head->preferencial_queue, i);
  }

  for (int i = 0; i < 10; i++) {
    serve(head);
  }

  printf("\n"); // separador

  // atendimento ambas
  for (int i = 0; i < 10; i++) {
    head->normal_queue = insert(head->normal_queue, i);
  }

  for (int i = 1000; i < 1010; i++) {
    head->preferencial_queue = insert(head->preferencial_queue, i);
  }

  for (int i = 0; i <= 20; i++) {
    serve(head);
  }
}
