#include <stdio.h>
#define n 50

double porcentagem_fun(int vetor[], int valor){
    double perc;
    int i, repeticoes=0;
    for (i=0; i<n; i++){
        if (vetor[i]==valor){
            repeticoes++;
        }
    }
    perc = (repeticoes*100)/n;
    return perc;
}

int main(){
    double per_1, per_2, per_3, per_4, per_5, per_6;
    int vetor[n], i;
    for (i=0;i<n;i++){
        printf("Valor[%d] = ", i);
        scanf("%d",&vetor[i]);
    }

    per_1 = porcentagem_fun(vetor, 1);
    per_2 = porcentagem_fun(vetor, 2);
    per_3 = porcentagem_fun(vetor, 3);
    per_4 = porcentagem_fun(vetor, 4);
    per_5 = porcentagem_fun(vetor, 5);
    per_6 = porcentagem_fun(vetor, 6);

    printf("%.2lf%% repetiçoes de 1\n", per_1);
    printf("%.2lf%% repetiçoes de 2\n", per_2);
    printf("%.2lf%% repetiçoes de 3\n", per_3);
    printf("%.2lf%% repetiçoes de 4\n", per_4);
    printf("%.2lf%% repetiçoes de 5\n", per_5);
    printf("%.2lf%% repetiçoes de 6\n", per_6);

    return 0;
}