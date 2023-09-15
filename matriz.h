// Gabriel Belo Pereira Dos Reis
#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct Matriz
{
    int *dados; // ponteiro para um array de duas dimensões(como anselmo disse nas aulas)
    int linhas;
    int colunas;
} Matriz;

Matriz *criarMatriz(int linhas, int colunas);
void destruirMatriz(Matriz *m);
void definirElemento(Matriz *m, int i, int j, int valor);
int obterElemento(Matriz *m, int i, int j);
Matriz *multiplicarMatrizes(Matriz *a, Matriz *b);
Matriz *transposta(Matriz *m);
void imprimirMatriz(Matriz *m);


#endif
