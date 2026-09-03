#include <stdio.h>

int main() {
  int vetor[10];
  int i, j, temp;

  for (i = 0; i < 10; i++) {
    printf("Digite o valor do indice %d: ", i);
    scanf("%d", &vetor[i]);
  }

  for (i = 0; i < 9; i++) { // A variável i navega do primeiro ao penúltimo
    for (j = (i + 1); j < 10; j++) { // A variável j navega do próximo ao último
      if (vetor[i] > vetor[j]) {
        temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
      }
    }
  }

  for (i = 0; i < 10; i++) {
    printf("%d\n", vetor[i]);
  }

  return 0;
}
