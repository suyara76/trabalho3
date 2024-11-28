#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//cria uma nova fila
Fila* criar_fila(){
    Fila *nova_fila = (Fila *)malloc(sizeof(Fila));
    if(!nova_fila){
        printf("Erro ao alocar memoria para a fila.\n");
        exit(1);
    }
    nova_fila->inicio = NULL;
    nova_fila->fim = NULL;
    return nova_fila;
}

//insere um elemento no final da fila
void inserir_fila(Fila *fila, int idade){
    No *novo_no = (No *)malloc(sizeof(No));
    if(!novo_no){
        printf("Erro ao alocar memoria para o nó.\n");
        exit(1);
    }
    novo_no->idade = idade;
    novo_no->proximo = NULL;
    novo_no->anterior = fila->fim;

    if(fila->fim){
        fila->fim->proximo = novo_no;
    }
    fila->fim = novo_no;

    if(!fila->inicio){
        fila->inicio = novo_no;
    }
}

//ordena a fila em ordem decrescente usando bubble sort
void ordenar_fila(Fila *fila){
    if(!fila->inicio){
        return;
    }
    int trocado;
    No *atual;

    do{
        trocado = 0;
        atual = fila->inicio;

        while(atual->proximo){
            if(atual->idade < atual->proximo->idade){
                int temp = atual->idade;
                atual->idade = atual->proximo->idade;
                atual->proximo->idade = temp;
                trocado = 1;
            }
            atual = atual->proximo;
        }
    }while(trocado);
}

//remove o elemento no inicio da fila
int remover_fila(Fila *fila){
    if(!fila->inicio){
        printf("A fila está vazia.\n");
        return -1;
    }

    No *remover = fila->inicio;
    int idade = remover->idade;
    fila->inicio = remover->proximo;

    if(fila->inicio){
        fila->inicio->anterior = NULL;
    }else{
        fila->fim = NULL;
    }

    free(remover);
    return idade;
}

//funcao para exibir o estado atual da fila
void mostrar_fila(Fila *fila){
    printf("Fila atual: ");
    No *atual = fila->inicio;
    if (!atual){
        printf("vazia\n");
        return;
    }
    while(atual){
        printf("%d ", atual->idade);
        atual = atual->proximo;
    }
    printf("\n\n");
}

//libera a memoria alocada para a fila
void liberar_fila(Fila *fila){
    No *atual = fila->inicio;
    while(atual){
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(fila);
}
