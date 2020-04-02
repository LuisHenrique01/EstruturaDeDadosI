#include <stdio.h>

int main(){
    int n, index_ma=0, index_me=0, maior, menor;
    printf("Digite o tamanho dos vetores A: ");
    scanf("%d", &n);
    int a[n], i;
    for (i=0; i<n; i++){
        printf("A[%d]: ", i);
        scanf("%d",&a[i]);
    }
    maior = a[index_ma];
    menor = a[index_me];
    for (i=0; i<n; i++){
        if (maior<a[i]){
            maior = a[i];
            index_ma = i;
        }
        if (menor>a[i]){
            menor = a[i];
            index_me = i;
        }
    }

    printf("Maior: %d - Index: %d\n", maior, index_ma);
    printf("Menor: %d - Index: %d\n", menor, index_me);

    return 0;
}