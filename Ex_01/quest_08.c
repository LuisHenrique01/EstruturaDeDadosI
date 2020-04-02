#include <stdio.h>

int main(){
    printf("Quantos termos deseja(maior que 2)? ");
    int n;
    scanf("%d", &n);
    int vetor[n], i;
    vetor[0] = 0;
    vetor[1] = 1;
    for(i=2; i<n; i++){
        vetor[i] = vetor[i-1] + vetor[i-2];
    }

    for (i=0; i<n; i++){
        printf("%dº termo: %d\n", i+1, vetor[i]);
    }
    return 0;
}