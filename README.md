# Gerenciamento da Fila Virtual de Clientes
Foi desenvolvido um sistema de atendimento online, ou seja, uma fila FIFO. Foi solicitado como requisito do sistema ter uma fila específica para prioridade (idosos) ordenada pela idade das pessoas na fila, ou seja os mais velhos devem ser atendidos primeiro (ordenação de menor para maior). Trabalho da matéria Algoritmos e Estrutura de Dados 2024/2, ministrada pelo professor Juan Colonna.

### Funcionalidades:
1. Criar e manipular uma fila de clientes.
2. Ordenar a fila em ordem decrescente com base na idade.
3. Atender clientes sequencialmente e exibir o estado atual da fila após cada atendimento.

### Tecnologias:
1. Linguagem C
2. Manipulação de arquivos com a biblioteca padrão de C (stdio.h).
3. Alocação dinâmica de memória com malloc e free.

### Compile o programa:
1° Passo: gcc suyara.c fila.c -o gerenciar_fila
### Execute o programa:
2° Passo: ./gerenciar_fila

### Resultados esperados:
1. As idades dos clientes serão exibidas na ordem do arquivo.
2. A fila será exibida ordenada de maior para menor.
3. Os clientes serão atendidos sequencialmente, com a fila sendo atualizada e exibida após cada atendimento.

### Organização do Código
1. fila.h: Define as estruturas de dados e declara as funções usadas para manipulação da fila.
2. fila.c: Implementa as funções principais, como criação, inserção, ordenação, exibição e liberação da fila.
3. suyara.c: Gerencia o programa principal, lidando com a entrada de dados, manipulação da fila e exibição do estado.
O arquivo clientes.txt já existe, mas você pode editá-lo para as idades que quiseres testar. Organizando conforme já está no arquivo disponibilizado.
#### Ex.:(Um número em cada linha)
65
56
100
50
79
90
### Fluxo do Programa
Lê o arquivo clientes.txt e insere as idades na fila.
Ordena a fila de forma decrescente por idade.
Realiza o atendimento dos clientes, um por um, removendo-os da fila.
Exibe a fila após cada atendimento e finaliza liberando a memória.
