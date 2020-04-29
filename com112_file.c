#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "com112_file.h"

void ArmazenaEntrada(int *V, int tam, FILE *com112_entrada)
{
    int i = 0;
    if (com112_entrada == NULL)
    {
        printf("\nArquivo com112_entrada.TXT nao pode ser aberto.");
        printf("\nOcorreu um Erro Grave ! Use alguma tecla para finalizar !");
        getch();
    }
    else
    {
        fprintf(com112_entrada, "%d\n", tam);
        for(i=0; i<tam; i++)
        {
            fprintf(com112_entrada, "%d ", V[i]);
        }
    }
    fclose (com112_entrada);
}

void ArmazenaSaida(int *V, int tam, FILE *com112_saida)
{
    int i = 0;
    if (com112_saida == NULL)
    {
        printf("\nArquivo com112_saida.TXT nao pode ser aberto.");
        printf("\nOcorreu um Erro Grave ! Use alguma tecla para finalizar !");
        getch();
    }
    else
    {
        fprintf(com112_saida, "%d\n", tam);
        for(i=0; i<tam; i++)
        {
            fprintf(com112_saida, "%d ", V[i]);
        }
        fprintf(com112_saida, "\n");
    }
    fclose(com112_saida);
}

void ArmazenaRelatorio(int id, double tempoDeExecucao, int comparacoes, int movimentacoes, FILE *com112_relatorio)
{
    const char* metodo = " ";
    switch (id)
    {
    case 1:
        metodo = "Método Bubble Sort";
        break;
    case 2:
        metodo = "Método Selection Sort";
        break;
    case 3:
        metodo = "Método Insertion Sort";
        break;
    }


    if (com112_relatorio == NULL)
    {
        printf("\nArquivo com112_relatorio.TXT nao pode ser aberto.");
        printf("\nOcorreu um Erro Grave ! Use alguma tecla para finalizar !");
        getch();
    }
    else
    {
        fprintf(com112_relatorio, " Método %s\n", metodo);
        fprintf(com112_relatorio, " Tempo de execução em milisegundos: %0.lfms\n", tempoDeExecucao);
        fprintf(com112_relatorio, " Número de comparações: %d\n", comparacoes);
        fprintf(com112_relatorio, " Número de movimentações: %d\n", movimentacoes);
        fprintf(com112_relatorio, "\n");
    }
    if(id == 3)
    {
        fclose(com112_relatorio);
    }
}

void NumeroDeElementos(int n, FILE *com112_relatorio)
{
    fprintf(com112_relatorio, " Número de elementos ordenados: %d\n", n);
    fprintf(com112_relatorio, "\n");
}
