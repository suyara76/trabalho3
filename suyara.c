#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    //cria a fila
    Fila *fila = criar_fila();
    
    //abrindo o arquivo de clientes que foi pedido
    FILE *arquivo = fopen("clientes.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        liberar_fila(fila);
        return 1;
    }
    
    //lendo idades do arquivo e inserindo na fila
    int idade;
    printf("As idades dos clientes da fila sao:\n");
    while (fscanf(arquivo, "%d", &idade) != EOF) {
        printf("%d\n", idade);
        inserir_fila(fila, idade);
    }
    fclose(arquivo);
    
    //ordenando a fila de maior para menor
    ordenar_fila(fila);
    printf("\nFila ordenada de maior para menor:\n");
    mostrar_fila(fila);
    
    //atendendo os clientes e esvaziando a fila
    printf("\nAtendendo clientes ordenadamente:\n");
    while (fila->inicio) {
        //remove o cliente do inicio da fila
        idade = remover_fila(fila);
        printf("-> Idade do cliente atendido: %d\n", idade);
        
        //mostra a fila depois do atendimento
        mostrar_fila(fila);
    }
    
    //liberando a memoria
    liberar_fila(fila);
    
    return 0;
}
