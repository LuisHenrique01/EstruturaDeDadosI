#include <stdio.h>
#include <stdlib.h>

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
    int i, tam=1,op=-1, soma;
    double media;
    int *vet = (int *) malloc(tam*sizeof(int));
    while (op!=0){
        printf("Digite o numero: ");
        scanf("%d", &op);
        vet[tam-1] = op;
        tam++;
        vet = (int *) realloc(vet, tam*sizeof(int));
    }
    soma = soma_fun(vet, tam-2);
    media = media_fun(soma, tam-2);
    
    printf("Média: %.2lf\n", media);
    printf("Soma: %d\n", soma);

    free(vet);
    return 0;
}