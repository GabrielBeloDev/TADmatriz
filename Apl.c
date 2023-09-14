// Gabriel Belo Pereira Dos Reis

#include "matriz.h"
#include <stdio.h>

void imprimirMatriz(Matriz *m)
{
    for (int i = 0; i < m->linhas; i++)
    {
        for (int j = 0; j < m->colunas; j++)
        {
            printf("%d ", m->dados[i][j]); // imprime cada elemento da matriz
        }
        printf("\n");
    }
}

int main()
{
    Matriz *A = NULL, *B = NULL, *resultado; // ponteiros para as matrizes
    int escolha, linhas, colunas, valor;

    while (1) // loop infinito pro menu
    {
        printf("\nMenu:\n");
        printf("1. Criar matriz A\n");
        printf("2. Criar matriz B\n");
        printf("3. Ler e inserir os dados da matriz A\n");
        printf("4. Ler e inserir os dados da matriz B\n");
        printf("5. Calcular a multiplicação de A por B e imprimir o resultado\n");
        printf("6. Calcular a transposta de A e imprimir o resultado\n");
        printf("7. Calcular a transposta de B e imprimir o resultado\n");
        printf("8. Destruir a matriz A\n");
        printf("9. Destruir a matriz B\n");
        printf("10. Sair\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Digite o número de linhas para A: ");
            scanf("%d", &linhas);
            printf("Digite o número de colunas para A: ");
            scanf("%d", &colunas);
            A = criarMatriz(linhas, colunas); // chama a função criarMatriz e atribui o retorno ao ponteiro A
            printf("Matriz A criada.\n");
            break;

        case 2:
            printf("Digite o número de linhas para B: ");
            scanf("%d", &linhas);
            printf("Digite o número de colunas para B: ");
            scanf("%d", &colunas);
            B = criarMatriz(linhas, colunas); // chama a função criarMatriz e atribui o retorno ao ponteiro B}
            printf("Matriz B criada.\n");
            break;

        case 3:
            if (A == NULL)
            {
                printf("Matriz A não criada. Crie primeiro.\n");
                break;
            }
            for (int i = 0; i < A->linhas; i++)
            {
                for (int j = 0; j < A->colunas; j++)
                {
                    printf("Digite o valor para A[%d][%d]: ", i, j);
                    scanf("%d", &valor);
                    definirElemento(A, i, j, valor);
                }
            }
            break;

        case 4:
            if (B == NULL)
            {
                printf("Matriz B não criada. Crie primeiro.\n");
                break;
            }
            for (int i = 0; i < B->linhas; i++)
            {
                for (int j = 0; j < B->colunas; j++)
                {
                    printf("Digite o valor para B[%d][%d]: ", i, j);
                    scanf("%d", &valor);
                    definirElemento(B, i, j, valor);
                }
            }
            break;

        case 5:
            resultado = multiplicarMatrizes(A, B);
            if (resultado == NULL)
            {
                printf("Multiplicação não é possível.\n");
                break;
            }
            printf("Resultado da multiplicação de A por B:\n");
            imprimirMatriz(resultado);
            destruirMatriz(resultado);
            break;

        case 6:
            resultado = transposta(A);
            if (resultado == NULL)
            {
                printf("Erro na transposta de A.\n");
                break;
            }
            printf("Resultado da transposta de A:\n");
            imprimirMatriz(resultado);
            destruirMatriz(resultado);
            break;

        case 7:
            resultado = transposta(B);
            if (resultado == NULL)
            {
                printf("Erro na transposta de B.\n");
                break;
            }
            printf("Resultado da transposta de B:\n");
            imprimirMatriz(resultado);
            destruirMatriz(resultado);
            break;

        case 8:
            destruirMatriz(A);
            A = NULL;
            printf("Matriz A destruída.\n");
            break;

        case 9:
            destruirMatriz(B);
            B = NULL;
            printf("Matriz B destruída.\n");
            break;

        case 10:
            if (A)
                destruirMatriz(A);
            if (B)
                destruirMatriz(B);
            printf("Saindo...\n");
            return 0;
            break;

        default:
            printf("Opção inválida!\n");
        }
    }

    return 0;
}
