#include <stdio.h>
#include <stdbool.h>

int contem(int vetor[], int valor, int n){
    int i=0;
    for (i=0; i<n; i++){
        if (valor == vetor[i]){
            return 1;
        }
    }
    return 0; 
}

int main(){
    /*Variaveis*/
    bool contens=false;
    int n, repeticoes=0;
    printf("Digite o tamanho dos vetores A e B: ");
    scanf("%d", &n);
    int a[n], b[n], uniao_g[n*2], intersecao[n],i, j, cont_u=0, cont_i=0;
    /*Inputs*/
    for (i=0; i<n; i++){
        printf("A[%d]: ", i);
        scanf("%d",&a[i]);
        printf("B[%d]: ", i);
        scanf("%d",&b[i]);
    }
    /*processing*/
    for (i=0; i<n*2; i++){
        uniao_g[i]=0;
    }
    for (i=0; i<n; i++){
        intersecao[i]=0;
    }
    
    for (i=0; i<n; i++){
        contens=contem(uniao_g, a[i], 2*n);
        if (contens == 0){
            uniao_g[cont_u]=a[i];
            cont_u=cont_u+1;
        }
    }
    for (i=0; i<n; i++){
        contens=contem(uniao_g, b[i], 2*n);
        if (contens == 0){
            uniao_g[cont_u]=b[i];
            cont_u=cont_u+1;
        }
    }
    
    for (i=0; i<n; i++){
        contens=contem(b, a[i], n);
        if (contens == 1){
            contens=contem(intersecao, a[i], n);
            if (contens == 0){
                intersecao[cont_i]=a[i];
                cont_i=cont_i+1;
            }
        }
    }


    /*prints*/
    printf("-------------------\n");
    for (i=0; i<n; i++){
        printf("|A[%d]: %d | B[%d]: %d|\n", i, a[i], i, b[i]);
    }
    printf("-------------------\n\n");
    printf("---------\n");
    for (i=0; i<cont_u; i++){
        printf("|U[%d]: %d|\n", i, uniao_g[i]);
    }
    printf("---------\n");
    for (i=0; i<cont_i; i++){
        printf("|I[%d]: %d|\n", i, intersecao[i]);
    }
    printf("---------\n");

    return 0;
}