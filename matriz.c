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

        novaMatriz->dados = (int *)malloc(linhas * colunas * sizeof(int)); // aloquei a memória para os elementos da matriz
        if (novaMatriz->dados != NULL){                                    // testei

            for (int i = 0; i < linhas * colunas; i++)
            {
                novaMatriz->dados[i] = 0; // atribui 0 a cada elemento da matriz
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
        free(m->dados); // libera a memória do vetor de elementos
        free(m);       // libera a matriz
    }
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
                    int soma = 0;
                    for (int k = 0; k < a->colunas; k++)
                    {
                        soma += a->dados[i * a->colunas + k] * b->dados[k * b->colunas + j]; // aqui multipliquei as matrizes
                    }
                    resultado->dados[i * resultado->colunas + j] = soma; // atribui o valor da soma na matriz resultado
                }
            }
        }
        return resultado;
    }
    return NULL; // indica erro se as matrizes não forem válidas
}

void definirElemento(Matriz *m, int i, int j, int valor)
{
    if (m != NULL && i >= 0 && i < m->linhas && j >= 0 && j < m->colunas)  // testei e verifiquei se a matriz é válida e os índices estão dentro dos limites
    {
        int index = i * m->colunas + j;
        m->dados[index] = valor; // atribui o valor
    }
}

int obterElemento(Matriz *m, int i, int j)
{
    if (m != NULL && i >= 0 && i < m->linhas && j >= 0 && j < m->colunas) // testei e verifiquei se a matriz é válida e os índices estão dentro dos limites
    {
        int index = i * m->colunas + j;
        return m->dados[index]; // retorna o valor do elemento na matriz
    }
    return -1; // como declarei sendo int,botei o -1 para indicar erro
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
                    int elemento = obterElemento(m, i, j);
                    definirElemento(resultado, j, i, elemento); 
                }
            }
        }
        return resultado;
    }
    return NULL; // indica erro
}

void imprimirMatriz(Matriz *m) {
    if (m != NULL) {
        for (int i = 0; i < m->linhas; i++) {
            for (int j = 0; j < m->colunas; j++) {
                printf("%d ", obterElemento(m, i, j));
            }
            printf("\n");
        }
    } else {
        printf("Matriz é NULL\n");
    }
}
