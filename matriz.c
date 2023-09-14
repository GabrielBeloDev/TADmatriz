#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

Matriz *criarMatriz(int linhas, int colunas)
{
    Matriz *novaMatriz = (Matriz *)malloc(sizeof(Matriz)); // aloquei a memória para criar uma nova matriz
    if (novaMatriz != NULL)                                // testei
    {
        novaMatriz->linhas = linhas; // inicializei a matriz linhas e colunas
        novaMatriz->colunas = colunas;

        novaMatriz->dados = (int **)malloc(linhas * sizeof(int *)); // aloquei a memória para as linhas da matriz
        if (novaMatriz->dados != NULL)                              // testei
        {
            for (int i = 0; i < linhas; i++)
            {
                novaMatriz->dados[i] = (int *)malloc(colunas * sizeof(int)); // aqui aloquei a memória para cada coluna
                if (novaMatriz->dados[i] != NULL)                            // testei
                {
                    for (int j = 0; j < colunas; j++)
                    {
                        novaMatriz->dados[i][j] = 0; //  atribui 0 a cada elemento da matriz, ou seja, foi criada com valor 0 todos os elementos
                    }
                }
                else
                {
                    for (int k = 0; k < i; k++)
                    {
                        free(novaMatriz->dados[k]); // libera a memória se alguma linha aqui falhar
                    }
                    free(novaMatriz->dados);
                    free(novaMatriz);
                    return NULL;
                }
            }
        }
        else
        {
            free(novaMatriz); // limpa memória se a alocação no geral falhar
            return NULL;
        }
    }
    else
    {
        return NULL;
    }

    return novaMatriz; // retorna a matriz criada
}

void destruirMatriz(Matriz *m)
{
    if (m != NULL) // testei
    {
        for (int i = 0; i < m->linhas; i++) // percorre as linhas e destroi cada uma
        {
            free(m->dados[i]); // libera a memória de cada linha
        }
        free(m->dados); // libera a memória do ponteiro para o array de duas dimensões ou seja o array de linhas e colunas
        free(m);        // libera a matriz
    }
}

void definirElemento(Matriz *m, int i, int j, int valor)
{
    if (m != NULL && i < m->linhas && j < m->colunas) // testei e verifiquei se a matriz é válida e os índices estão dentro dos limites
    {
        m->dados[i][j] = valor; // atribui o valor
    }
}

int obterElemento(Matriz *m, int i, int j)
{
    if (m != NULL && i < m->linhas && j < m->colunas) // testei e verifiquei se a matriz é válida e os índices estão dentro dos limites
    {
        return m->dados[i][j]; // retorna o valor do elemento na matriz
    }
    return -1; // como declarei sendo int,botei o -1 para indicar erro
}

Matriz *multiplicarMatrizes(Matriz *a, Matriz *b)
{
    if (a != NULL && b != NULL && a->colunas == b->linhas) // testei e verifiquei se as matrizes são válidas e se a coluna de a é igual a linha de b
    {
        Matriz *resultado = criarMatriz(a->linhas, b->colunas); // criei a matriz resultado
        if (resultado != NULL)                                  // testei
        {
            for (int i = 0; i < a->linhas; i++)
            {
                for (int j = 0; j < b->colunas; j++)
                {
                    for (int k = 0; k < a->colunas; k++)
                    {
                        resultado->dados[i][j] += a->dados[i][k] * b->dados[k][j]; // aqui multipliquei as matrizes
                    }
                }
            }
        }
        return resultado;
    }
    return NULL; // indica erro se as matrizes não forem válidas
}

Matriz *transposta(Matriz *m)
{
    if (m != NULL) // testei
    {
        Matriz *resultado = criarMatriz(m->colunas, m->linhas); // aloquei e testei
        if (resultado != NULL)
        {
            for (int i = 0; i < m->linhas; i++)
            {
                for (int j = 0; j < m->colunas; j++)
                {
                    resultado->dados[j][i] = m->dados[i][j]; // verifica a transposta da matriz e atribui ao resultado
                }
            }
        }
        return resultado;
    }
    return NULL; // indica erro
}
