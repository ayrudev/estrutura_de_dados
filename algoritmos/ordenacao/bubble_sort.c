#include <stdio.h>

int main() {
  int vetor[10];
  int i, temp;
  int continuar = 1;

  for (i = 0; i < 10; i++) {
    printf("Digite o valor do indice %d: ", i);
    scanf("%d", &vetor[i]);
  }

  while (continuar) {
    continuar = 0;
    for (i = 0; i < 9; i++) {
      if (vetor[i] > vetor[i + 1]) {
        temp = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = temp;
        continuar = 1;
      }
    }
  }

  for (i = 0; i < 10; i++) {
    printf("%d\n", vetor[i]);
  }

  return 0;
}
