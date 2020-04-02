#include <stdio.h>

int main(){
    int n;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    int vet[n], i, j, index_me, menor, burro_carga, tem_menor=0;
    for (i=0;i<n;i++){
        printf("Vetor[%d] = ", i);
        scanf("%d", &vet[i]);
    }
    for (i=0;i<n;i++){
        menor = vet[i];
        for (j=i;j<n;j++){
            if (menor>vet[j]){
                menor = vet[j];
                index_me = j;
                tem_menor = 1;
            }
        }
        if (tem_menor == 1){
            burro_carga = vet[i];
            vet[i] = menor;
            vet[index_me] = burro_carga;
            tem_menor = 0;
        }
    }
    printf("===============\n");
    for (i=0;i<n;i++){
        printf("Vetor[%d] = %d\n", i, vet[i]);
    }
}