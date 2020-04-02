#include <stdio.h>
#include <string.h>
#define n 9

int main(){
    char hora[n];
    printf("Digite a hora conforme o exemplo(12:05:20): ");
    fgets(hora, n, stdin);
    printf("%c%c hora(s), %c%c minuto(s) e %c%c segundo(s)\n", hora[0], hora[1], hora[3], hora[4], hora[6], hora[7]);
    return 0;
}