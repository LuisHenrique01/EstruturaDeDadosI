#include <stdio.h>
#include <string.h>
#define n 100

int conta_palavras(char texto[]){
    int palavras=0, tamanho, i;
    tamanho = strlen(texto) - 1;
    for (i=0; i<tamanho; i++){
        if (texto[i] == ' '){
            palavras++;
        }
    }
    return palavras+1;
}

int main(){
    char texto[n];
    int palavras;
    printf("Digite o texto: ");
    fgets(texto, n, stdin);
    palavras =  conta_palavras(texto);
    printf("Contem %d palavras\n", palavras);
    return 0;
}