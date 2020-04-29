#ifndef COM112_FILE_H
#define COM112_FILE_H

void ArmazenaDados(int *V, int tam, FILE *com112_entrada);
void ArmazenaSaida(int *V, int tam, FILE *com112_saida);
void ArmazenaRelatorio(int id, double tempoDeExecucao, int comparacoes, int movimentacoes, FILE *com112_relatorio);
void NumeroDeElementos(int n, FILE *com112_relatorio);

#endif /*FILE_H */
