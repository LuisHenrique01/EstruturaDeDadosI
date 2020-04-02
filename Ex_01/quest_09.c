#include <stdio.h>


int soma_fun(int vet[], int ta){
    int soma=0, i;
    for (i = 0; i < ta; i++){
        soma = soma + vet[i];
    }
    return soma;
}

double media_fun(int soma, int ta){
    return soma/ta;
}

int main(){
    printf("Quantos numeros deseja? ");
    int n;
    scanf("%d",&n);
    int vetor[n], i, soma;
    double media;
    for (i=0;i<n;i++){
        printf("Vetor[%d]: ", i);
        scanf("%d",&vetor[i]);
    }
    soma = soma_fun(vetor, n);
    media = media_fun(soma, n);

    printf("Soma = %d\nMédia = %.2lf\n", soma, media);
    return 0;
}