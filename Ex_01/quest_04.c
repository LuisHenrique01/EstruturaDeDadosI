#include <stdio.h>
#include <math.h>
#include <string.h>

int main(){
    int bin[8], i, dec=0, exp=0, a, b;
    printf("Digite numero por numero:\n");
    for (i=0;i<8;i++){
        printf("%d º termo: ", i+1);
        scanf("%d",&bin[i]);
    }
    //binario
    for (i=7; i>=0; i--){
        dec = dec + (bin[i] * pow(2, exp));
        exp++;
    }
    
    
    printf("O numero na base decimal é %d\n", dec);

    return 0;
}