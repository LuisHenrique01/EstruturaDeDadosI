#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{
    char tag[MAX];
    struct elemento *prox;
}elemento;

typedef struct{
    struct elemento *topo;
}pilha;

void pilha_inicia(pilha *p){
    p->topo = NULL;
}

int pilha_vazia(pilha *p){
    if (p->topo == NULL){
        return 1;
    }else{
        return 0;
    }
}
/*
int tamanho_pilha(pilha *p){
    elemento *aux = (elemento*)malloc(sizeof(elemento));
    aux = p->topo;
    int tam = 0;
    while (aux->prox == NULL){
        tam++;
        aux = aux->prox;
    }
    free(aux);
    return tam;
}*/

void pilha_insere(pilha *p, char tag[]){
    elemento *novo = (elemento*)malloc(sizeof(elemento));
    strcpy(novo->tag, tag);
    novo->prox = p->topo;
    p->topo = novo;
}

void pilha_retira(pilha *p){
    elemento *aux = (elemento*)malloc(sizeof(elemento));
    if (pilha_vazia(p) == 1){
        printf("A pilha está vazia!\n");
    }else{
        aux = p->topo;
        p->topo = aux->prox;
    }
    free(aux);
}

char limpa_tag(char tag[]){
    char c = tag[1];
    char tag2[MAX];
    int i=1;
    while(strcmp(c, ">") != 0){
        if (strcmp(c, "/") != 0){
            strcat(tag2, c);
        }
        i++;
        c = tag[i];
    }
    return tag2;
}

int tem_barra(char tag[]){
    int i, tam;
    tam = strlen(tag);
    for(i=0;i<tam;i++){
        if(tag[i] == '/'){
            return 1;
        }
    }
    return 0;
}
int main(){
    pilha *p = (elemento*)malloc(sizeof(elemento));
    elemento *t = (elemento*)malloc(sizeof(elemento));
    char tag[MAX];
    int inicio = 1;
    int erro = 0;
    pilha_inicia(p);
    pilha_inicia(t);
    while ((inicio == 1 || pilha_vazia != 0) && erro == 0){
        scanf("%s", tag);
        if(tem_barra(tag) == 1){
            strcpy(tag, limpa_tag(tag));
            t = p->topo;
            if(strcmp(t->tag, tag) == 0){
                pilha_retira(p);
            } else{
                printf("O código contém erro!\n");
                erro = 1;
            }
        }else{
            strcpy(tag, limpa_tag(tag));
            pilha_insere(p, tag);
        }
        inicio = 0;
        free(t);
    }
    return 0;
    free(p);
}
