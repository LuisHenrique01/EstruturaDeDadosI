#include <stdio.h>
#define MAX 10

typedef struct{
    int num[MAX];
    int inicio;
    int numElementos;
}fila;

void fila_inicia(fila *f){
    f->inicio = 0;
    f->numElementos = 0;
}

int fila_vazia(fila *f){
    if(f->numElementos == 0){
        return 1;
    }else{
        return 0;
    }
}

int fila_cheia(fila *f){
    if(f->numElementos >= MAX){
        return 1;
    }else{
        return 0;
    }
}

int fila_numero_elementos(fila *f){
    return f->numElementos;
}

void fila_mostra_completa(fila *f){
    int inicio = f->inicio;
    int i;
    for (i = 0; i < f->numElementos; i++){
        printf("Valor[%d] = %d\n", i, f->num[inicio]);
        inicio = (inicio+1)%MAX;
    }
}

void fila_insere(fila *f, int num){
    if(fila_cheia(f) == 1){
        printf("Fila cheia\n");
    }else{
        int posicao = (f->inicio + f->numElementos) % MAX;
        f->num[posicao] = num;
        f->numElementos++;
    }
}

int fila_retira(fila *f){
    if (fila_vazia(f) == 1){
        printf("Fila vazia!\n");
    }else{
        int saida; 
        saida = f->num[f->inicio];
        f->inicio = (f->inicio + 1) % MAX;
        f->numElementos--;
        return saida;
    }
}

int fila_reinicializacao(fila *f){
    fila_inicia(f);
}

int main(){
    fila *f = (fila*)malloc(sizeof(fila));
    fila_inicia(f);
    printf("1 - Entrar na fila\n2 - Sair da fila\n3 - Mostrar fila\n0 - Sair do sistema\n");
    int op = -1;
    int valor;
    while(op != 0){
        printf("Opção: ");
        scanf("%d", &op);
        if (op == 1){
            printf("Valor: ");
            scanf("%d", &valor);
            fila_insere(f, valor);
        }
        if (op == 2){
            valor = fila_retira(f);
            printf("Valor retirado: %d\n", valor);
        }
        if (op == 3){
            fila_mostra_completa(f);
        }
    }
    free(f);
    return 0;
}