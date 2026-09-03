#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000

int main() {
  int vetor[SIZE];
  int search_parameter;
  int i;

  srand(time(NULL));

  for (i = 0; i < SIZE; i++) {
    vetor[i] = rand() % 10000;
  }

  while (search_parameter != -99) {
    printf("Digite o parametro de pesquisa: ");
    scanf("%d", &search_parameter);

    for (i = 0; i < SIZE; i++) {
      if (search_parameter == vetor[i]) {
        printf("Achei no índice %d\n", i);
        break;
      }
    }
  }

  return 0;
}
