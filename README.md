# TADmatriz

## Descrição

Este projeto implementa um Tipo Abstrato de Dados (TAD) para uma matriz em C. Ele fornece operações básicas como criação de matrizes, definição e obtenção de elementos, multiplicação de matrizes e cálculo da matriz transposta.

## Estrutura de Arquivos

- `matriz.c`: Contém a implementação das funções que manipulam a matriz.
- `matriz.h`: Contém a declaração das funções e da estrutura `Matriz`.
- `Apl.c`: É o arquivo de aplicação que utiliza o TAD Matriz.
- `output/`: Diretório onde o executável `Apl` é armazenado e executado.

## Requisitos

- C/C++ compilador

## Instalação

Clone este repositório ou baixe os arquivos fonte.

```bash
git clone https://github.com/gabrielbelodev/TADmatriz.git

Compilação
Para compilar o código, navegue até o diretório e execute:

bash
Copy code
gcc -o output/Apl matriz.c Apl.c
Isso gerará o executável Apl na pasta output.

Uso
Após compilar, você pode executar o programa navegando até a pasta output e usando:

bash
Copy code
./Apl
Funcionalidades Implementadas
Matriz *criarMatriz(int linhas, int colunas)
Cria uma nova matriz com linhas e colunas, inicializando todos os elementos com o valor 0.

void destruirMatriz(Matriz *m)
Libera a memória alocada para a matriz.

void definirElemento(Matriz *m, int i, int j, int valor)
Define o valor de um elemento na matriz nas posições i e j.

int obterElemento(Matriz *m, int i, int j)
Obtém o valor de um elemento na matriz nas posições i e j.

Matriz *multiplicarMatrizes(Matriz *a, Matriz *b)
Multiplica duas matrizes, retornando uma nova matriz como resultado.

Matriz *transposta(Matriz *m)
Calcula a matriz transposta e retorna uma nova matriz como resultado.

Contribuição
Se você deseja contribuir, sinta-se à vontade para fazer um fork do projeto, criar uma nova branch, fazer suas alterações e abrir um Pull Request.

Licença
Este projeto está sob a licença MIT. Veja o arquivo LICENSE.md para mais detalhes.