#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 10

typedef struct{
    char item[max][max];
    int topo;
} pilha;

void pilha_inicia(pilha *p){
    p->topo = -1;
}

int pilha_vazia(pilha *p){
    if (p->topo == -1){
        return 1;
    } else {
        return 0;
    }
}

int pilha_cheia(pilha *p){
    if (p->topo == max-1){
        return 1;
    } else {
        return 0;
    }
}

void pilha_insere(pilha *p, char x[]){
    if (pilha_cheia(p) == 1){
        printf("A pilha está cheia!\n");
    } else {
        p->topo++;
        strcpy(p->item[p->topo], x);
    }   
}

void pilha_retira(pilha *p){
    if (pilha_vazia(p) == 1){
        printf("Pilha vazia!!\n");
    } else{
        p->topo--;
    }
}

void entrada(pilha *esta, char placa[]){
    if (pilha_cheia(esta) == 0){
        pilha_insere(esta, placa);
    } else {
        printf("Sem vagas!!");
    }
}

int movsaida(pilha *esta, char placa[]){
    int i, mov=0;
    char carro[max];
    pilha *aux = (pilha*)malloc(sizeof(pilha));
    pilha_inicia(aux);
    while (strcmp(esta->item[esta->topo], placa) != 0){
        mov++;
        strcpy(carro, esta->item[esta->topo]);
        pilha_retira(esta);
        pilha_insere(aux, carro);
    }
    pilha_retira(esta);
    for(i=0;i<mov;i++){
        strcpy(carro, aux->item[aux->topo]);
        pilha_retira(aux);
        pilha_insere(esta, carro);
    }
    free(aux);
    return mov*2;
}

void mostrarEstacionamento(pilha *esta){
    int i;
    printf("Vagas <---> Placas\n");
    printf(" \n");
    for(i=esta->topo;i>-1;i--){
        printf("  %d   <---> %s\n", i, esta->item[i]);
    }
    printf("\n");
}

int main(){
    int op=3, mov;
    char placa[max];
    pilha *esta = (pilha*)malloc(sizeof(pilha));
    pilha_inicia(esta);
    while(op != 0){
        mostrarEstacionamento(esta);
        printf("Digite a opção desejada:\n1 - Entrar\n2 - Sair\n0 - Desligar\n");
        scanf("%d", &op);
        if (op == 1){
            printf("Placa: ");
            scanf("%s", placa);
            entrada(esta, placa);
        } else if(op == 2){
            printf("Placa: ");
            scanf("%s", placa);
            mov = movsaida(esta, placa);
            printf("Foi necessário %d movimentos para retirar o carro!\n", mov);
        }
    }
    free(esta);
    return 0;
}