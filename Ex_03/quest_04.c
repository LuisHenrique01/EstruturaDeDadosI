#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char senha[20];
    scanf("%s", senha);
    if (strcmp(senha, "Luis")==0){
        printf("Senha correta!\n");
    } else {
        printf("Senha invalida!\n");
    }
    return 0;
}
