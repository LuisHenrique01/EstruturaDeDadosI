#include <stdio.h>
#include <math.h>
#define n 20

int calculaS(int vetor[]){
    int s=0, i;
    for (i=0; i<n; i++){
        if (i<n-(i+1)){
            s += pow((vetor[i] - vetor[n-i-1]), 2);
        }
    }
    return s;
}

void mostra(int s){
    printf("O resultado da soma é: %d\n", s);
}

int main(){
    int vetor[n], i, s;
    for (i=0; i<n; i++){
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    s = calculaS(vetor);
    mostra(s);
    return 0;
}