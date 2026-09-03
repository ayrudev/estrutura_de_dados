#include <stdio.h>
#define SIZE 100000

int main() {
  int vetor[SIZE];
  int i, inicio, meio, fim, parametroPesquisa, contador;

  for (i = 0; i < SIZE; i++) {
    vetor[i] = i;
  }

  while (parametroPesquisa != -99) {
    printf("Digite o parametro de pesquisa: ");
    scanf("%d", &parametroPesquisa);

    inicio = 0;
    fim = 99999;
    contador = 0;

    while (inicio <= fim) {
      meio = ((inicio + fim) / 2);
      contador++;

      if (parametroPesquisa == vetor[meio]) {
        printf("Achei na tentativa de número %d\n", contador);
        break;
      } else if (parametroPesquisa < vetor[meio]) {
        fim = (meio - 1);
      } else {
        inicio = (meio + 1);
      }
    }
  }
}
