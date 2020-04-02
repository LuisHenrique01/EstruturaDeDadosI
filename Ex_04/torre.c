#include <stdio.h>
#include <stdlib.h>
#define max 3

typedef struct{
    int item[max];
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

void pilha_insere(pilha *p, int x){
    if (pilha_cheia(p) == 1){
        printf("A pilha está cheia!\n");
    } else {
        p->topo++;
        p->item[p->topo] = x;
    }   
}

int pilha_retira(pilha *p){
    int aux;
    if (pilha_vazia(p) == 1){
        printf("Pilha vazia!!\n");
    } else{
        aux = p->item[p->topo];
        p->topo--;
        return aux;
    }
}

void movimenta(pilha *t1, pilha *t2, pilha *t3){
    int entra, sai, novo_topo, velho_topo, torre;
    printf("\nTorre retirada: ");
    scanf("%d", &sai);
    printf("\nTorre entrada: ");
    scanf("%d", &entra);
    if (sai == 1){
        novo_topo = t1->item[t1->topo];
        torre = 1;
    } else if (sai == 2){
        novo_topo = t2->item[t2->topo];
        torre = 2;
    } else if (sai == 3){
        novo_topo = t3->item[t3->topo];
        torre = 3;
    } else{
        printf("valor invalido!\n");  
    }
    if (entra == 1){
        velho_topo = t1->item[t1->topo];
        if(pilha_vazia(t1)){
            velho_topo = 4;
        }
    } else if (entra == 2){
        velho_topo = t2->item[t2->topo];
        if(pilha_vazia(t2)){
            velho_topo = 4;
        }
    } else if (entra == 3){
        velho_topo = t3->item[t3->topo];
        if(pilha_vazia(t3)){
            velho_topo = 4;
        }
    } else{
        printf("valor invalido!\n");  
    }
    if (velho_topo > novo_topo){
        if (entra == 1){
            pilha_insere(t1, novo_topo);
        } else if (entra == 2){
            pilha_insere(t2, novo_topo);
        } else if (entra == 3){
            pilha_insere(t3, novo_topo); 
        }
        if(torre == 1){
            pilha_retira(t1);
        } else if (torre == 2){
            pilha_retira(t2);
        } else if (torre == 3){
            pilha_retira(t3);
        }
    } else {
        printf("Jogada invalida!!\n");
    } 
}

void mostrar_torres(pilha *t1, pilha *t2, pilha *t3){
        if (t1->topo == 2){
            printf("T-1: %d   %d   %d \n", t1->item[t1->topo-2], t1->item[t1->topo-1], t1->item[t1->topo]);
        } else if (t1->topo == 1){
            printf("T-1: %d   %d \n", t1->item[t1->topo-1], t1->item[t1->topo]);
        } else if (t1->topo == 0){
            printf("T-1: %d  \n", t1->item[t1->topo]);
        } else {
            printf("T-1: \n");
        }
        
        if (t2->topo == 2){
            printf("T-2: %d   %d   %d \n", t2->item[t2->topo-2], t2->item[t2->topo-1], t2->item[t2->topo]);
        } else if (t2->topo == 1){
            printf("T-2: %d   %d \n", t2->item[t2->topo-1], t2->item[t2->topo]);
        } else if (t2->topo == 0){
            printf("T-2: %d  \n", t2->item[t2->topo]);
        } else {
            printf("T-2: \n");
        }
        if (t3->topo == 2){
            printf("T-3: %d   %d   %d \n", t3->item[t3->topo-2], t3->item[t3->topo-1], t3->item[t3->topo]);
        } else if (t3->topo == 1){
            printf("T-3: %d   %d \n", t3->item[t3->topo-1], t3->item[t3->topo]);
        } else if (t3->topo == 0){
            printf("T-3: %d  \n", t3->item[t3->topo]);
        } else {
            printf("T-3: \n");
        }
        
    }

int main(){
    pilha *t1 = (pilha*)malloc(sizeof(pilha));
    pilha *t2 = (pilha*)malloc(sizeof(pilha));
    pilha *t3 = (pilha*)malloc(sizeof(pilha));
    pilha_inicia(t1);
    pilha_inicia(t2);
    pilha_inicia(t3);
    pilha_insere(t1, 3);
    pilha_insere(t1, 2);
    pilha_insere(t1, 1);
    int ven=0;

    while (ven==0){

        mostrar_torres(t1, t2, t3);
        movimenta(t1, t2, t3);
        //printf("\e[H\e[2J");
    
        if (pilha_cheia(t2) || pilha_cheia(t3)){
            ven = 1;
        }
    }
    mostrar_torres(t1, t2, t3);
    printf("PARABÉNS!\n");
    return 0;
}