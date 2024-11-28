#ifndef FILA_H
#define FILA_H

//estrutura para o nó da fila
typedef struct No{
    int idade;
    //ponteiro para o proximo nó
    struct No *proximo; 
    //ponteiro para o nó anterior
    struct No *anterior; 
}No;

//estrutura para a fila
typedef struct{
    //ponteiro para o inicio da fila
    No *inicio; 
    //ponteiro para o fim da fila
    No *fim; 
}Fila;

//cria uma nova fila
Fila* criar_fila();

//insere um elemento no final da fila
void inserir_fila(Fila *fila, int idade);

//ordena a fila em ordem decrescente usando bubble sort
void ordenar_fila(Fila *fila);

//remove o elemento no inicio da fila
int remover_fila(Fila *fila); 

//atualiza a fila depois que do cliente ser atendido
void mostrar_fila(Fila *fila);

//libera a memoria alocada para a fila
void liberar_fila(Fila *fila); 

#endif
