#include <stdio.h>
#include <string.h>

int main(){
    int n;
    printf("Digite o tamanho da palavra: ");
    scanf("%d", &n);
    char palavra[n], palavra2[n];
    printf("Digite a palavra: ");
    scanf("%s", palavra);
    int i, tamanho, j;
    tamanho=n+1;
    j=n-1;
    palavra2[tamanho] = '\0';
    for (i=0; i<tamanho; i++){
        palavra2[i] = palavra[j];
        j = j-1;
    }
    if (strcmp(palavra, palavra2) == 0){
        printf("Palídroma!\n");
    } else{
        printf("Não palídroma!\n");
    }
    return 0;
}