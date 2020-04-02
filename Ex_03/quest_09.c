#include <stdio.h>
#include <string.h>
#define n 80

int main(){
    char nome[n], iniciais[10];
    printf("Nome: ");
    fgets(nome, n, stdin);
    iniciais[0] = nome[0];
    int i, j=1;
    for (i=0; i<n; i++){
        if (nome[i] == ' '){
            iniciais[j] = nome[i+1];
            j++;
        }
    }
    iniciais[j] = '\0';
    printf("Login: %s\n", iniciais);
    return 0;
}