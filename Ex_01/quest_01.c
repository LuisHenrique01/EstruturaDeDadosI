#include <stdio.h>

int main(){
    int n;
    printf("Digite o tamanho dos vetores A e B: ");
    scanf("%d", &n);
    int a[n], b[n], c[n*2], i;
    for (i=0; i<n; i++){
        printf("A[%d]: ", i);
        scanf("%d",&a[i]);
        printf("B[%d]: ", i);
        scanf("%d",&b[i]);
    }
    for (i=0; i<n; i++){
        c[i] = a[i];
        c[i+n] = b[i];
    }
    for (i=0; i<2*n; i++){
        printf("C[%d]: %d \n", i, c[i]);
    }
    return 0;
}