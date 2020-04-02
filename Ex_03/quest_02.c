#include <stdio.h>
#include <string.h>
#define n 11

int main(){
    char data[n];
    printf("Digite a data conforme o exemplo(01/01/2000): ");
    fgets(data, n, stdin);
    printf("%c%c de ", data[0], data[1]);
    if (data[3] == '0'){
        if (data[4] == '1'){
            printf("Janeiro ");
        } else if (data[4] == '2'){
            printf("Fevereiro ");
        } else if (data[4] == '3'){
            printf("Março ");
        } else if (data[4] == '4'){
            printf("Abril ");
        } else if (data[4] == '5'){
            printf("Maio");
        } else if (data[4] == '6'){
            printf("Junho ");
        } else if (data[4] == '7'){
            printf("Julho ");
        } else if (data[4] == '8'){
            printf("Agosto ");
        } else if (data[4] == '9'){
            printf("Setembro ");
        } else{
            printf("\nData inválida!\n");
            return 0;
        }
    } else if (data[3] == '1' && data[4]=='0'){
        printf("Outubro");
    }else if (data[3] == '1' && data[4]=='1'){
        printf("Novembro");
    }else if (data[3] == '1' && data[4]=='2'){
        printf("Dezembro");
    }else{
        printf("\nData inválida!\n");
        return 0;
    }
    
    printf("de %c%c%c%c\n", data[6], data[7], data[8], data[9]);
    return 0;
}