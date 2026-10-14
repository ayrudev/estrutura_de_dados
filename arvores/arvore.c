#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node {
  int number;
  struct node *branch1;
  struct node *branch2;
  struct node *branch3;
  struct node *branch4;
  struct node *branch5;
};

// Função que insere um nó na arvore
struct node *insert(struct node *root, int number) { // Função recursiva
  if (root == NULL) {                                // Árvore vazia
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->number = number;
    newNode->branch1 = NULL;
    newNode->branch2 = NULL;
    newNode->branch3 = NULL;
    newNode->branch4 = NULL;
    newNode->branch5 = NULL;
    return newNode;
  }

  int random = (1 + (rand() % 5));

  if (random == 1) {
    root->branch1 = insert(root->branch1, number); // Invocação recursiva
  } else if (random == 2) {
    root->branch2 = insert(root->branch2, number);
  } else if (random == 3) {
    root->branch3 = insert(root->branch3, number);
  } else if (random == 4) {
    root->branch4 = insert(root->branch4, number);
  } else {
    root->branch5 = insert(root->branch5, number);
  }
  return root;
}

// Função que imprime a árvore na tela
void printTree(struct node *root, char *indentation) {
  if (root == NULL)
    return;

  printf("%s%d\n", indentation, root->number);

  char *temp = (char *)malloc(strlen(indentation) + 4);
  strcpy(temp, indentation);
  strcat(indentation, "---");

  printTree(root->branch1, temp);
  printTree(root->branch2, temp);
  printTree(root->branch3, temp);
  printTree(root->branch4, temp);
  printTree(root->branch5, temp);
}

int main(void) {
  struct node *root = NULL;

  time_t t;
  srand(time(&t));

  for (int i = 0; i < 10000000; i++) {
    root = insert(root, i);
  }

  char *indentation = (char *)malloc(sizeof(char));
  strcpy(indentation, "");
  printTree(root, indentation);
}
