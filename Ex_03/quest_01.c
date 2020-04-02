#include <stdio.h>
#include <string.h>
#define n 80

int main(){
    char frase[n];
    int i;
    printf("Digite uma frase de até 80 caracteres: ");
    //scanf("%s", frase);
    fgets(frase, n, stdin);
    for (i=0; i<n; i++){
        if (frase[i]>64 && frase[i]<91){
            frase[i]='#';
        }
    }
    printf("criptografia: %s\n", frase);
    return 0;
}