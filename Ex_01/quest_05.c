#include <stdio.h>

int main(){
    int n;
    printf("Digite o tamanho dos vetores A: ");
    scanf("%d", &n);
    int a[n], b[n], i;
    for (i=0; i<n; i++){
        printf("A[%d]: ", i);
        scanf("%d",&a[i]);
    }
    for (i=0; i<n; i++){
        if (a[i]%2 == 0){
            b[i] = 0;
        }else{
            b[i] = 1;
        }
    }
    for (i=0; i<n; i++){
        printf("B[%d] = %d\n", i, b[i]);
    }
    return 0;
}