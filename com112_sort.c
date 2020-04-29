#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "com112_sort.h"

int* AlocaVetor(int n)
{
    int *V;
    V = malloc(n * sizeof(int));
    if(V != NULL)
    {
        printf("\n Memória alocada com sucesso!\n");
    }
    return V;
}

void PreencheVetor(int tam, int* V)
{
    int i = 0;
    srand(time(NULL));
    for(i=0; i<tam; i++)
    {
        V[i] = rand();
    }
    printf("\n Vetor preenchido com sucesso!\n");
}

int* BubbleSort(int* V, int tam)
{
    int i, j, aux, *Vaux;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam-1; j++)
        {
            if(Vaux[j] > Vaux[j+1])
            {
                aux = Vaux[j];
                Vaux[j] = Vaux[j+1];
                Vaux[j+1] = aux;
            }
        }
    }
    return Vaux;
}

double BubbleSortTempoDeExecucao(int* V, int tam)
{
    clock_t t;
    int i, j, aux, *Vaux;
    double ms;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    t = clock();
    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam-1; j++)
        {
            if(Vaux[j] > Vaux[j+1])
            {
                aux = Vaux[j];
                Vaux[j] = Vaux[j+1];
                Vaux[j+1] = aux;
            }
        }
    }
    t = clock() - t;
    ms = ((double)t)/((CLOCKS_PER_SEC/1000));
    return ms;
}

int BubbleSortNumeroDeComparacoes(int* V, int tam)
{
    int i, j, aux, *Vaux, comparacoes = 0;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam-1; j++)
        {
            comparacoes += 1;
            if(Vaux[j] > Vaux[j+1])
            {
                aux = Vaux[j];
                Vaux[j] = Vaux[j+1];
                Vaux[j+1] = aux;
            }
        }
    }
    return comparacoes;
}

int BubbleSortNumeroDeMovimentacoes(int* V, int tam)
{
    int i, j, aux, *Vaux, movimentacoes = 0;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    for(i=0; i<tam; i++)
    {
        for(j=0; j<tam-1; j++)
        {
            if(Vaux[j] > Vaux[j+1])
            {
                aux = Vaux[j];
                Vaux[j] = Vaux[j+1];
                Vaux[j+1] = aux;
                movimentacoes++;
            }
        }
    }
    return movimentacoes;
}

int* SelectionSort(int* V, int tam)
{
    int i, j, aux, menor, *Vaux;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    for (i = 0; i<tam-1; i++)
    {
        menor = i;
        for (j = i+1; j<tam; j++)
        {
            if (Vaux[j] < Vaux[menor])
            {
                menor = j;
                aux = Vaux[menor];
                Vaux[menor] = Vaux[i];
                Vaux[i] = aux;
            }
        }

    }
    return Vaux;
}

double SelectionSortTempoDeExecucao(int* V, int tam)
{
    clock_t t;
    int i, j, aux, *Vaux, menor;
    double ms = 0.0;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    t = clock();
    for (i = 0; i<tam-1; i++)
    {
        menor = i;
        for (j = i+1; j<tam; j++)
        {
            if (Vaux[j] < Vaux[menor])
            {
                menor = j;
                aux = Vaux[menor];
                Vaux[menor] = Vaux[i];
                Vaux[i] = aux;
            }
        }

    }
    t = clock() - t;
    ms = ((double)t)/((CLOCKS_PER_SEC/1000));
    return ms;
}

int SelectionSortNumeroDeComparacoes(int* V, int tam)
{
    int i, j, aux, *Vaux, comparacoes = 0, menor;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    for (i = 0; i<tam-1; i++)
    {
        menor = i;
        for (j = i+1; j<tam; j++)
        {
            comparacoes++;
            if (Vaux[j] < Vaux[menor])
            {
                menor = j;
                aux = Vaux[menor];
                Vaux[menor] = Vaux[i];
                Vaux[i] = aux;
            }
        }
    }
    return comparacoes;
}

int SelectionSortNumeroDeMovimentacoes(int* V, int tam)
{
    int i, j, aux, *Vaux, movimentacoes = 0, menor;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    for (i = 0; i<tam-1; i++)
    {
        menor = i;
        for (j = i+1; j<tam; j++)
        {
            if (Vaux[j] < Vaux[menor])
            {
                menor = j;
                aux = Vaux[menor];
                Vaux[menor] = Vaux[i];
                Vaux[i] = aux;
                movimentacoes++;
            }
        }
    }
    return movimentacoes;
}

int* InsertionSort(int* V, int tam)
{
    int i, j, aux, *Vaux;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    for (i = 1; i < tam; i++)
    {
        aux = Vaux[i];
        j = i - 1;
        while (j >= 0 && Vaux[j] > aux)
        {
            Vaux[j + 1] = Vaux[j];
            j = j - 1;
        }
        Vaux[j + 1] = aux;
    }
    return Vaux;
}

double InsertionSortTempoDeExecucao(int* V, int tam)
{
    clock_t t;
    int i, j, aux, *Vaux;
    double ms = 0.0;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    t = clock();
    for (i = 1; i < tam; i++)
    {
        aux = Vaux[i];
        j = i - 1;
        while (j >= 0 && Vaux[j] > aux)
        {
            Vaux[j + 1] = Vaux[j];
            j = j - 1;
        }
        Vaux[j + 1] = aux;
    }
    t = clock() - t;
    ms = ((double)t)/((CLOCKS_PER_SEC/1000));
    return ms;
}

int InsertionSortNumeroDeComparacoes(int* V, int tam)
{
    int i, j, aux, *Vaux, comparacoes = 0;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    for (i = 1; i < tam; i++)
    {
        aux = Vaux[i];
        j = i - 1;
        while (j >= 0 && Vaux[j] > aux)
        {
            Vaux[j + 1] = Vaux[j];
            j = j - 1;
            comparacoes++;
        }
        Vaux[j + 1] = aux;
    }
    return comparacoes;
}

int InsertionSortNumeroDeMovimentacoes(int* V, int tam)
{

    int i, j, aux, *Vaux, movimentacoes = 0;
    Vaux = malloc(tam * sizeof(int));

    for(i=0; i<tam; i++)
    {
        Vaux[i] = V[i];
    }

    for (i = 1; i < tam; i++)
    {
        aux = Vaux[i];
        j = i - 1;
        while (j >= 0 && Vaux[j] > aux)
        {
            Vaux[j + 1] = Vaux[j];
            j = j - 1;
        }
        Vaux[j + 1] = aux;
        movimentacoes++;
    }
    return movimentacoes;
}
