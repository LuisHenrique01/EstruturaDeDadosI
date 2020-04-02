#include <stdio.h>
#include <stdlib.h>
#define max 5

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
void mostrar_pilha(pilha *p){
    int top = p->topo, i;
    for (i=0; i < top; i--){
        printf("%d", p->item[i]);    
    }
}

int converte(char ele[]){
    return atoi(ele);
}

int main(){
    pilha *t = (pilha*)malloc(sizeof(pilha));
    pilha_inicia(t);
    char ele[5];
    int num=0, a=0, b=0;
    do{
        scanf("%c", ele);
        if (ele == "-"){
            a = pilha_retira(t);
            b = pilha_retira(t);
            num = b - a;
        } else if(ele == "*"){
            a = pilha_retira(t);
            b = pilha_retira(t);
            num = b * a; 
        } else if(ele == "+"){
            a = pilha_retira(t);
            b = pilha_retira(t);
            printf("%d %d\n", a, b);
            num = b + a;
        } else if(ele == "/"){
            a = pilha_retira(t);
            b = pilha_retira(t);
            num = b / a; 
        } else if(ele == "="){
            num = pilha_retira(t);
            printf("Resultado: %d\n", num);
        } else {
            num = converte(ele);
            pilha_insere(t, num);
        }
        mostrar_pilha(t);
    }while(ele != "=");
    free(t);
    return 0; 
}