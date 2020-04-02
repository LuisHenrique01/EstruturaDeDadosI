#include <stdio.h>
#include <stdlib.h>
#define tam 5

struct lista {
 int inicio, fim;
 int elemento[tam];
};

void lista_inicia(lista *l){
    l->inicio = -1;
    l->fim = -1;
}

void lista_destroi(lista *l){
    lista_inicia(l);
}

int lista_vazia(lista *l){
    if(l->fim == -1 && l->inicio == -1){
        return 1;
    }else {
        return 0;
    }
}

int lista_cheia(lista *l){
    if(l->fim == tam){
        return 1;
    } else
    {
        return 0;
    }
}

int busca_item(lista *l, int valor){
    int i, posicao;
    if (lista_vazia(l)){
        return -1;
    }else{
        for (i=l->inicio; i<=l->fim; i++){
            if(l->elemento[i] == valor){
                return i;
            }
        }
        return -1;
    }
}

void insere(lista *l,int valor) {
	int i;
	if(lista_cheia(l)) {
		printf("A lista esta cheia\n");
	}else{
        for(i=l->fim; i>0 && valor<l->elemento[i-1]; i--) {
            l->elemento[i]=l->elemento[i-1];
        }
        l->elemento[i]=valor;
        l->fim++;
        l->inicio = 0;
        printf("Lista atualizada!\n");
        }
}

void remove(lista *l, int valor){
    int i, posicao;
    posicao = busca_item(l, valor);
    if (posicao == -1){
        printf("Não existe esse elemento!\n");
    }else{
        for(i=posicao; i<l->fim; i++){
            l->elemento[i] = l->elemento[i+1];
        }
        l->fim--;
        printf("Elemento retirado!\n");
    }
}

void exibir(lista *l){
    int i;
    if (lista_vazia(l)){
        printf("Lista vazia!\n");
    }else{
        printf("Elementos:\n");
        for(i=l->inicio; i<=l->fim; i++){
            printf("%dº = %d\n", i+1, l->elemento[i]);
        }
    }
}

void primeiro_elemeno(lista *l){
    printf("O primeiro elemento é %d\n", l->elemento[l->inicio]);
}

void ultimo_elemeno(lista *l){
    printf("O ultimo elemento é %d\n", l->elemento[l->fim]);
}

void tamanho(lista *l){
    printf("O vetor tem %d elemntos\n",l->fim - l->inicio);
}

void sucessor(lista *l, int valor){
    int posicao = busca_item(l, valor);
    printf("O seu sucessor é %d\n",l->elemento[posicao+1]);
}

void antecessor(lista *l, int valor){
    int posicao = busca_item(l, valor);
    printf("O seu antecessor é %d\n",l->elemento[posicao-1]);
}

void menu(){
    printf("1  - Inserção de elemento\n");
    printf("2  - Remoção de elemento\n");
    printf("3  - Consulta de elemento\n");
    printf("4  - Mostrar lista\n");
    printf("5  - Primeiro elemento\n");
    printf("6  - Ultimo Elemento\n");
    printf("7  - Tamanho da lista\n");
    printf("8  - Sucessor\n");
    printf("9  - Antecessor\n");
    printf("0 - Sair\n");
}

int main(){
    lista *l = (lista*)malloc(sizeof(lista));
    lista_inicia(l);
    int op, valor;
    do
    {
        menu();
        scanf("%d", &op);
        
        if(op == 1){
            scanf("%d", &valor);
            insere(l, valor);
        } else if(op == 2){
            scanf("%d", &valor);
            remove(l, valor);
        } else if(op == 3){
            scanf("%d", &valor);
            printf("Está na posição %d", busca_item(l, valor));
        } else if(op == 4){
            exibir(l);
        } else if(op == 5){
            primeiro_elemeno(l);
        } else if(op == 6){
            ultimo_elemeno(l);
        } else if(op == 7){
            tamanho(l);
        } else if(op == 8){
            scanf("%d", &valor);
            sucessor(l, valor);
        } else if(op == 9){
            scanf("%d", &valor);
            antecessor(l, valor);
        } else if(op != 0){
            printf("Digite um valor valido!\n");
        }
    } while (op != 0);
    
}
