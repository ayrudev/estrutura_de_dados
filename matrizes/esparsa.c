// Matriz esparsa
#include <stdio.h>
#include <stdlib.h>

// Constantes
#define MODULUS 3

// Declaração de estruturas

struct node { // Estrutura que controla as colunas da tabela
  int number;
  struct node *nextNode;
};

struct rowHead { // Estrutura que controla as linhas da tabela
  int remainder;
  struct node *nextNode;
  struct rowHead *nextRowHead;
};

// Variáveis globais
struct rowHead *head = NULL;

// Função que procura um linha baseado no resto
struct rowHead *searchRowHead(int number) {
  // Deslocamento vertical
  int remainder = number % MODULUS;
  struct rowHead *pointer = head;

  while (pointer != NULL && pointer->remainder != remainder) {
    pointer = pointer->nextRowHead;
  }

  // Cabeça da coluna correta encontrada
  if (pointer != NULL) {
    return pointer;
  }

  // Cabeça da coluna não foi encontrada
  struct rowHead *newRowHead = (struct rowHead *)malloc(sizeof(struct rowHead));
  newRowHead->remainder = remainder;
  newRowHead->nextNode = NULL;
  newRowHead->nextRowHead = head;
  head = newRowHead;
  return head;
}

// Função que insere um número na matriz
void insert(int number) {
  // Deslocamento horizontal
  struct rowHead *rowHeadPointer = searchRowHead(number);

  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->number = number;
  newNode->nextNode = rowHeadPointer->nextNode;
  rowHeadPointer->nextNode = newNode;
}

// Função que exclui um número da matriz
void delete(int number) {
  struct rowHead *rowHeadPointer = searchRowHead(number);

  // Linha vazia
  if (rowHeadPointer->nextNode == NULL) {
    return;
  }

  // Excluir o primeiro
  if (rowHeadPointer->nextNode->number == number) {
    struct node *toFree = rowHeadPointer->nextNode;
    rowHeadPointer->nextNode = rowHeadPointer->nextNode->nextNode;
    free(toFree);
    return;
  }

  // Procurar pelo número a ser excluido
  // !Parar no anterior!
  struct node *previous = rowHeadPointer->nextNode;
  while (previous->nextNode != NULL && previous->nextNode->number != number) {
    previous = previous->nextNode;
  }

  // Não encontrei
  if (previous->nextNode == NULL) {
    return;
  }

  // Encontrei
  struct node *toFree = previous->nextNode;
  previous->nextNode = previous->nextNode->nextNode;
  free(toFree);
}

// Função que imprime a matriz
void printMatrix() {
  struct rowHead *rowHeadPointer = head;
  printf("Resto\tNúmeros\n");
  while (rowHeadPointer != NULL) {
    printf("%d\t", rowHeadPointer->remainder);
    struct node *nodePointer = rowHeadPointer->nextNode;
    while (nodePointer != NULL) {
      printf("%d, ", nodePointer->number);
      nodePointer = nodePointer->nextNode;
    }
    printf("\n");
    rowHeadPointer = rowHeadPointer->nextRowHead;
  }
}

// Função main
int main() {
  insert(5);
  insert(293);
  insert(10);
  insert(4);
  insert(144);
  insert(9);
  insert(6);
  printMatrix();

  printf("\n");
  delete(5);
  delete(9);
  delete(4);
  printMatrix();
}
