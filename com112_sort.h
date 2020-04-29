#ifndef COM112_SORT_H
#define COM112_SORT_H

int* AlocaVetor(int n);
void PreencheVetor(int n, int* V);
int* BubbleSort(int* V, int tam);
int* SelectionSort(int* V, int tam);
int* InsertionSort(int* V, int tam);
double BubbleSortTempoDeExecucao(int* V, int tam);
int BubbleSortNumeroDeComparacoes(int* V, int tam);
int BubbleSortNumeroDeMovimentacoes(int* V, int tam);
double SelectionSortTempoDeExecucao(int* V, int tam);
int SelectionSortNumeroDeComparacoes(int* V, int tam);
int SelectionSortNumeroDeMovimentacoes(int* V, int tam);
double InsertionSortTempoDeExecucao(int* V, int tam);
int InsertionSortNumeroDeComparacoes(int* V, int tam);
int InsertionSortNumeroDeMovimentacoes(int* V, int tam);

#endif /*COM112_H */
