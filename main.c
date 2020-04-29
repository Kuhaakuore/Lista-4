// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
// bibliotecas do projeto
#include "com112_sort.h"
#include "com112_file.h"
#include<locale.h>

int Menu(int* V, int tam, FILE *com112_saida)
{
    int c = 0, *Vaux;
    do
    {
        printf("\n Escolha o método de ordenação que deseja utilizar: \n");
        printf("\n 1 - Bubble Sort \n");
        printf("\n 2 - Selection Sort \n");
        printf("\n 3 - Insertion Sort \n");
        printf("\n 4 - Encerrar programa \n");
        printf("\n Sua escolha: ");
        scanf("%d", &c);
        switch(c)
        {
        case 1:
            Vaux = BubbleSort(V, tam);
            ArmazenaSaida(Vaux, tam, com112_saida);
            Relatorio(V, tam, c);
            break;
        case 2:
            Vaux = SelectionSort(V, tam);
            ArmazenaSaida(Vaux, tam, com112_saida);
            Relatorio(V, tam, c);
            break;
        case 3:
            Vaux = InsertionSort(V, tam);
            ArmazenaSaida(Vaux, tam, com112_saida);
            Relatorio(V, tam, c);
            break;
        case 4:
            printf("\n Encerrando programa.\n");
            return 0;
            break;
        }
    }
    while (c != 4);
    return 0;
}

int Relatorio(int *V, int tam, int c)
{
    switch (c)
    {
    case 1:
        printf("\n Método Bubble Sort\n");
        printf("\n Tempo de execução em milisegundos: %0.lfms\n", BubbleSortTempoDeExecucao(V, tam));
        printf("\n Número de comparações: %d\n", BubbleSortNumeroDeComparacoes(V, tam));
        printf("\n Número de movimentações: %d\n", BubbleSortNumeroDeMovimentacoes(V, tam));
        break;
    case 2:
        printf("\n Método Selection Sort\n");
        printf("\n Tempo de execução em milisegundos: %0.lfms\n", SelectionSortTempoDeExecucao(V, tam));
        printf("\n Número de comparações: %d\n", SelectionSortNumeroDeComparacoes(V, tam));
        printf("\n Número de movimentações: %d\n", SelectionSortNumeroDeMovimentacoes(V, tam));
        break;
    case 3:
        printf("\n Método Insertion Sort\n");
        printf("\n Tempo de execução em milisegundos: %0.lfms\n", InsertionSortTempoDeExecucao(V, tam));
        printf("\n Número de comparações: %d\n", InsertionSortNumeroDeComparacoes(V, tam));
        printf("\n Número de movimentações: %d\n", InsertionSortNumeroDeMovimentacoes(V, tam));
        break;
    }
}

int main()
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    int n = 0, *Vetor;
    FILE *com112_entrada, *com112_saida, *com112_relatorio;
    com112_entrada = fopen("com112_entrada.TXT", "w+");
    com112_saida = fopen("com112_saida.TXT", "w+");
    com112_relatorio = fopen("com112_relatorio.TXT", "w+");
    printf("\n Digite o tamanho do vetor à ser criado: ");
    scanf("%d", &n);
    while(n <= 0)
    {
        printf("\n Valor inválido \n");
        printf("\n Digite um valor válido: ");
        scanf("%d", &n);
    }
    if(n >= 1)
    {
        Vetor = AlocaVetor(n);
        PreencheVetor(n, Vetor);
        NumeroDeElementos(n, com112_relatorio);
        ArmazenaEntrada(Vetor, n, com112_entrada);
        Menu(Vetor, n, com112_saida);
        ArmazenaRelatorio(1, BubbleSortTempoDeExecucao(Vetor, n), BubbleSortNumeroDeComparacoes(Vetor, n), BubbleSortNumeroDeMovimentacoes(Vetor, n), com112_relatorio);
        ArmazenaRelatorio(2, SelectionSortTempoDeExecucao(Vetor, n), SelectionSortNumeroDeComparacoes(Vetor, n), SelectionSortNumeroDeMovimentacoes(Vetor, n), com112_relatorio);
        ArmazenaRelatorio(3, InsertionSortTempoDeExecucao(Vetor, n), InsertionSortNumeroDeComparacoes(Vetor, n), InsertionSortNumeroDeMovimentacoes(Vetor, n), com112_relatorio);
    }
    fclose (com112_entrada);
    fclose (com112_saida);
    fclose (com112_relatorio);
    free(Vetor);
    return 0;
}
