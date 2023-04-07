/*
Objetivo: Determinar se todas as palavras listadas serão encontradas ou não em um caça palavras
Autores: Guilherme Godoy - 758710, Lara Rodrigues - 769701 e Paula Larocca - 769705
Data: de 08/06/2019 a 24/06/2019
*/

//Declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Declaração de constantes
#define qtdePalavras 20 // Quantidade máxima de palavras que podem ser geradas ou lidas
#define tamMaxPalavras 20 // Tamanho máximo de cada palavra que for gerada ou lida
#define linhas 20 // Quantidade máxima de linhas para os caça-palavras do programa
#define colunas 20 // Quantidade máxima de colunas para os caça-palavras do programa
#define opcoes 8 // Quantidade de opções para a geração de palavras aleatórias em todos os sentidos possíveis

// Protótipos de funções

// Menu de opções ao usuário
int menuOpcoesMatriz();
int menuOpcoesLista();

// Conversão de letras em maiúsculas
void converteMatriz(char matriz[][colunas], int, int);
void converteLista(char palavras[][tamMaxPalavras], int);

// opções de matriz
void matrizAleatoria(char matriz[][colunas], int *, int *);
void matrizArquivo(char mat[][colunas], int*, int*);
void matrizUsuario(char mat[][colunas], int*, int*);

// opções para geração de lista
void geraPalavraAleatoria(char lista[][tamMaxPalavras], int *);
void geraPelaMatriz(char mat[][colunas], char lista[][tamMaxPalavras], int *, int, int);
void listaArquivo(char lista[][tamMaxPalavras], int *);
void listaUsuario(char lista[][tamMaxPalavras], int *);

// geração da matriz aleatória de caracteres
void geraMatriz(char mat[linhas][colunas], int, int);

// geração de palavras aleatórias a partir de uma matriz
void geraPalavraHorizontal(char matriz[][colunas], char lista[][tamMaxPalavras], int, int, int);
void geraPalavraHorizontalInversa(char matriz[][colunas], char lista[][tamMaxPalavras], int, int, int);
void geraPalavraVertical(char matriz[][colunas], char lista[][tamMaxPalavras], int, int, int);
void geraPalavraVerticalInversa(char matriz[][colunas], char lista[][tamMaxPalavras], int, int, int);
void geraPalavraDiagonalPrincipal(char matriz[][colunas], char lista[][tamMaxPalavras], int, int, int);
void geraPalavraDiagonalPrincipalInversa(char matriz[][colunas], char lista[][tamMaxPalavras], int, int, int);
void geraPalavraDiagonalSecundaria(char matriz[][colunas], char lista[][tamMaxPalavras], int, int, int);
void geraPalavraDiagonalSecundariaInversa(char matriz[][colunas], char lista[][tamMaxPalavras], int, int, int);

// Verificações da existência das palavras em todos os sentidos possíveis
int verHorizontal(char palavras[][tamMaxPalavras], char matriz[][colunas], int , int, int);
int verHorizontalInversa(char palavras[][tamMaxPalavras], char matriz[][colunas], int , int, int);
int verVertical(char palavras[][tamMaxPalavras], char matriz[][colunas], int, int, int);
int verVerticalInversa(char palavras[][tamMaxPalavras], char matriz[][colunas], int, int, int);
int verDiagonalPrincipal(char palavras[][tamMaxPalavras], char matriz[][colunas], int, int, int);
int verDiagonalPrincipalInversa(char palavras[][tamMaxPalavras], char matriz[][colunas], int, int, int);
int verDiagonalSecundaria(char palavras[][tamMaxPalavras], char matriz[][colunas], int, int, int);
int verDiagonalSecundariaInversa(char palavras[][tamMaxPalavras], char matriz[][colunas], int, int, int);

// Impressão das matrizes
void imprimeMatriz (char matriz[][colunas], int, int);
void imprimeLista (char palavras[][tamMaxPalavras], int);

// Varredura com todas as Verificações
int varredura(char lista[][tamMaxPalavras], char matriz[][colunas], int, int, int);

// Apresentação do resultado se encontrou ou não todas as palavras
void resultado(int, int);

// Início da função principal do programa
int main()
{
    system ("explorer LEIA-ME.txt"); // Abertura do documento com instruções sobre o programa
    int opMatriz, opLista; // Criação do Menu Matriz e do Menu Lista
    char lista[qtdePalavras][tamMaxPalavras]; // Lista de palavras usada como parâmetro nas funções para criação de palavras
    char matriz[linhas][colunas]; // Matriz usada como parâmetro nas funções para criação da matriz de caracteres
    int L, C, Q, palavrasEncontradas; // Número de linhas, colunas, quantidade de palavras e verificação do encontro de palavras usados como parâmetro das funções

    srand(time(NULL)); // geração de números aleatórios

    opMatriz = menuOpcoesMatriz(); // Tipo de matriz escolhida pelo usuário

    // Execução do programa de acordo com a escolha do usuário
    switch (opMatriz)
    {
        case 1: // Caso matriz aleatória
            matrizAleatoria(matriz, &L, &C); // Chamada da função que gera uma matriz aleatória
            opLista = menuOpcoesLista(); // Opção de lista escolhida pelo usuário
            if (opLista == 1) // Lista de palavras gerada aleatoriamente
            {
                system("cls"); // Limpeza da tela
                geraPalavraAleatoria(lista, &Q); // Chamada da função que gera palavras aleatórias para a lista
            }
            else if (opLista == 2) // Lista de palavras digitada pelo usuário
            {
                system("cls");
                listaUsuario(lista, &Q); // Chamada da função que lê palavras digitadas pelo usuário para lista
                converteLista(lista, Q); // Conversão das palavras para letras maiúsculas
            }
            else if (opLista == 3) // Lista de palavras a partir de um arquivo
            {
                system("cls"); // Limpeza da tela
                listaArquivo(lista, &Q); // Chamada da função que lê um arquivo para gerar a lista
                converteLista(lista, Q); // Conversão das palavras para letras maiúsculas
            }
            else if (opLista == 4) // Lista de palavras gerada a partir de trechos da matriz
            {
                system("cls"); // Limpeza da tela
                geraPelaMatriz(matriz, lista, &Q, L, C); // Chamada da função que extrai partes da matriz para gerar a lista de palavras
            }
            else
                printf("Valor invalido!\n"); // Numero de menu inadequadamente escolhido pelo usuário
            break;
        case 2: // Caso matriz digitada pelo usuário
            system("cls"); // Limpeza da tela
            matrizUsuario(matriz, &L, &C); // Chamada da função que lê uma matriz digitada
            converteMatriz(matriz, L, C); // Chamada da função que converte os caracteres da matriz para maiúsculo
            opLista = menuOpcoesLista(); // Chamada da função que mostra o menu de opções de lista ao usuário
            if (opLista == 1) // Opção de lista gerada aleatoriamente
            {
                system("cls"); // Limpeza da tela
                geraPalavraAleatoria(lista, &Q); // Chamada da função que gera palavras aleatórias
            }
            else if (opLista == 2) // Opção de lista digitada pelo usuário
            {
                system("cls"); // Limpeza da tela
                listaUsuario(lista, &Q); // Chamada da função que lê uma lista de palavras digitadas pelo usuário
                converteLista(lista, Q); // Chamada da função de Conversão dos caracteres da lista para maiúsculo
            }
            else if (opLista == 3) // Opção de lista lida a partir de um arquivo
            {
                system("cls"); // Limpeza da tela
                listaArquivo(lista, &Q); // Chamada da função que lê um arquivo e gera uma lista
                converteLista(lista, Q); // Chamada da função que converte os caracteres da lista para maiúsculo
            }
            else if (opLista == 4) // Opção de lista que gera a lista a partir de partes da matriz
            {
                system("cls"); // Limpeza do sistema
                geraPelaMatriz(matriz, lista, &Q, L, C); // Chamada da função que gera palavras a partir de partes da matriz
            }
            else
                printf("Valor invalido!\n");
            break;
        case 3: // Caso matriz lida a partir de um arquivo
            system("cls"); // Limpeza da tela
            matrizArquivo(matriz, &L, &C); // Chamada da função que lê a matriz de um arquivo
            converteMatriz(matriz, L, C); // Chamada da função que converte os caracteres da matriz para maiúsculo
            opLista = menuOpcoesLista(); // Controlador da opção de lista escolhido pelo usuário e função de exibição do menu de lista
            if (opLista == 1) // Opção de lista de palavras geradas aleatoriamente
            {
                system("cls"); // Limpeza da tela
                geraPalavraAleatoria(lista, &Q); // Chamada da função que gera palavras aleatórias
            }
            else if (opLista == 2) // Opção de lista digitada pelo usuário
            {
                system("cls"); // Limpeza do sistema
                listaUsuario(lista, &Q); // Chamada da função que lê uma lista digitada pelo usuário
                converteLista(lista, Q); // Chamada da função que converte os caracteres das palavras da lista para maiúsculo
            }
            else if (opLista == 3) // Opção de lista gerada a partir de um arquivo
            {
                system("cls"); // Limpeza do sistema
                listaArquivo(lista, &Q); // Chamada da função que lê um arquivo para gerar lista
                converteLista(lista, Q); // Chamada da função que converte os caracteres das palavras da lista para maiúsculo
            }
            else if (opLista == 4) // Opção de lista gerada a partir de partes da matriz
            {
                system("cls"); // Limpeza do sistema
                geraPelaMatriz(matriz, lista, &Q, L, C); // Chamada da função que gera uma lista a partir de trechos da matriz
            }
            else
                printf("Valor invalido!\n");
            break;
        default:
            printf("Valor invalido!\n");
    }

    system("cls"); // Limpeza da tela
    imprimeLista(lista, Q); // Mostra da lista de palavras gerada para o usuário
    imprimeMatriz(matriz, L, C); // Mostra da matriz gerada para o usuário

    palavrasEncontradas = varredura(lista, matriz, L, C, Q); // função para verificar a existência das palavras da lista na matriz

    resultado(palavrasEncontradas, Q); // Verificação do resultado do encontro da palavra
    system ("pause");
    return 0;
}
// Final do programa principal

/*
Nome: menuOpcoesMatriz
Objetivo: Mostrar para o usuário um menu com os tipos de matriz passíveis de serem geradas e ler a escolha
parâmetros formais:
    - não há parâmetro
Valor de retorno:
    - n (Número do menu escolhido pelo usuário)
*/
int menuOpcoesMatriz()
{
    int n; // Variável utilizada para ler o valor digitado pelo usuário
    
    printf ("Ola! Este programa descobre se palavras estao em um Caca-Palavras. Para isso, escolha uma opcao:\n\n");
    printf("---------------- MENU DE CACA-PALAVRAS ---------------- \n");
    printf("[1] - Caca-palavras gerado aleatoriamente\n");
    printf("[2] - Digite o seu caca-palavras\n");
    printf("[3] - Entre com o arquivo do caca-palavras\n");
    printf("\nPor favor, digite a opcao desejada para gerar o caca-palavras: ");
    scanf("%d", &n);

    return n;
}

/*
Nome: menuOpcoesLista
Objetivo: Mostrar para o usuário um menu com os tipos de lista de palavras passíveis de serem geradas e ler a escolha
parâmetros formais:
    - não há parâmetro
Valor de retorno:
    - n (Opção escolhida pelo usuário)
*/
int menuOpcoesLista()
{
    int n; // Variável utilizada para ler o valor digitado pelo usuário

    system("cls");
    printf("------------------------ MENU DE LISTAS ------------------------ \n");
    printf("[1] - Lista de palavras gerada aleatoriamente\n");
    printf("[2] - Digite a sua lista de palavras\n");
    printf("[3] - Entre com o arquivo da lista de palavras\n");
    printf("[4] - Lista de palavras gerada a partir de trechos do caca-palavras\n");
    printf("\nPor favor, digite a opcao desejada para gerar a lista de palavras: ");
    scanf("%d", &n);

    return n;
}

/*
Nome: converteMatriz
Objetivo: Tornar os caracteres da matriz maiúsculos, para fins de padronização
parâmetros formais:
    - matriz (parâmetro de entrada e saída, pois é um ponteiro contendo os caracteres)
    - L (parâmetro de entrada, indicando o número de linhas da matriz)
    - C (parâmetro de entrada, indicando o número de colunas da matriz)
Valor de retorno:
    - não há valor de retorno, pois é procedimento
*/
void converteMatriz(char matriz[][colunas], int L, int C)
{
    int i, j; // Variáveis controladoras de laço

    for (i = 0; i < L; i++)
        for (j = 0; j < C; j++)
            // Valores na tabela ASCII correspondentes ao intervalo de letras minúsculas
            if (matriz[i][j] >= 97 && matriz[i][j] <= 122)
                matriz[i][j] -= 32; // Subtração que efetua a Conversão
}

/*
Nome: converteLista
Objetivo: Conversão dos caracteres das palavras da lista para maiúsculo, para fins de padronização
parâmetros formais:
    - palavras (parâmetro de entrada e saída, indicando a lista de palavras)
    - quantidade (parâmetro de entrada, indicando a quantidade de palavras)
Valor de retorno:
    - não há retorno, pois é procedimento
*/
void converteLista(char palavras[][tamMaxPalavras], int quantidade)
{
    int i, j; // Variáveis controladoras de laço

    for (i = 0; i < quantidade; i++)
        for (j = 0; j < strlen(palavras[i]); j++)
            // Valores na tabela ASCII correspondentes ao intervalo de letras minúsculas
            if (palavras[i][j] >= 97 && palavras[i][j] <= 122)
                palavras[i][j] -= 32; // Subtração que efetua a Conversão
}

/*
Nome: matrizAleatoria
Objetivo: Gerar a matriz com caracteres aleatórios de acordo com os valores de linha e coluna digitados pelo usuário
parâmetros formais:
    - matriz (parâmetro de entrada)
    - L (parâmetro de saída, que será utilizado para receber o valor de linhas digitado pelo usuário, que será usado diversas vezes ao longo do programa)
    - C (parâmetro de saída, que será utilizado para receber o valor de colunas digitado pelo usuário, que será usado diversas vezes ao longo do programa))
Valor de retorno:
    - não há, pois é um procedimento
*/
void matrizAleatoria(char mat[][colunas], int *L, int *C)
{
    system("cls"); // Limpa a tela

    int aux; // Variável auxiliar para ler os valores de linha e coluna e atribuí-los aos parâmetros de saída

    printf("Caca-Palavras Aleatorio\n\n");

    // Entrada de dados
    do
    {
        printf("Quantidade de linhas (entre 1 e %d): ", linhas);
        scanf("%d", &aux);
    } while (aux == 0 || aux > linhas);
    *L = aux; // Atribuição do valor lido ao ponteiro utilizado como parâmetro

    do
    {
        printf("Quantidade de colunas (entre 1 e %d): ", colunas);
        scanf("%d", &aux);
    } while (aux == 0 || aux > colunas);
    *C = aux; // Atribuição do valor lido ao ponteiro utilizado como parâmetro

    // Chama a função que gera a matriz de caracteres aleatórios
    geraMatriz(mat, *L, *C);
}

/*
Nome: matrizArquivo
Objetivo: Ler o arquivo correspondente à matriz desejada pelo usuário e incorporá-la no programa
parâmetros formais:
    - mat (parâmetro de entrada e saída)
    - L (parâmetro de saída, correspondente à quantidade de linhas da matriz, que será lida do arquivo)
    - C (parâmetro de saída, correspondente à quantidade de colunas da matriz, que será lida do arquivo)
Valor de retorno:
    - não há, pois é um procedimento
*/
void matrizArquivo(char mat[][colunas], int *L, int *C)
{
    FILE *arquivoMatriz; // Ponteiro correspondente ao arquivo de matriz que será lido

    int i, j; // Variáveis controladoras de laço
    int aux; // Variável auxiliar para ler os valores de linha e coluna e atribuí-los aos parâmetros de saída
    char arquivo[tamMaxPalavras]; // String que será utilizada para ler o nome do arquivo que será aberto

    printf("Caca-Palavras a partir de um arquivo\n\n");

    // Entrada do nome do arquivo
    fflush(stdin);
    printf("Digite o nome do arquivo desejado para a matriz de caracteres: ");
    gets(arquivo);

    // Abertura do arquivo
    arquivoMatriz = fopen(arquivo, "rt");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivoMatriz == NULL)
    {
        printf("Erro na abertura do arquivo\n");
        exit(1); // Caso ocorra um erro, o programa será encerrado
    }

    // Leitura do número de linhas a partir do arquivo
    fscanf (arquivoMatriz, "%d", &aux);
    *L = aux; // Atribuição do valor lido ao ponteiro utilizado como parâmetro

    // Leitura do número de colunas a partir do arquivo
    fscanf (arquivoMatriz, "%d", &aux);
    *C = aux; // Atribuição do valor lido ao ponteiro utilizado como parâmetro

    // Leitura dos caracteres da matriz a partir do arquivo
    while (!feof(arquivoMatriz)) // laço que indica que a leitura deverá continuar, enquanto o fim do arquivo não tiver sido alcançado
    {
        for (i = 0; i < *L; i++)
        {
            for (j = 0; j < *C; j++)
            {
                do
                {
                    fscanf(arquivoMatriz, "%c", &mat[i][j]); // Leitura dos caracteres da matriz
                } while (mat[i][j] == 32 || mat[i][j] == 10);  // Essa condição faz com que a leitura do arquivo não considere os espaços
                                                               // e os caracteres de nova linha, de modo que será efetuada a leitura da mesma
                                                               // posição até que seja lido um caractere válido
            }
        }
    }

    fclose(arquivoMatriz); // Fechamento do arquivo
}

/*
Nome: matrizUsuario
Objetivo: o usuário digita o caractere que deseja em cada posição que constitui a matriz
parâmetros formais:
    - matriz (parâmetro de saída, representando a matriz que vai ser constituída pelos caracteres inseridos pelo usuário)
    - L (parâmetro de saída que recebe a quantidade de linhas que o usuário digitou em aux)
    - C (parâmetro de saída que recebe a quantidade de colunas que o usuário digitou em aux)
Valor de retorno:
    - não há, pois é um procedimento
*/
void matrizUsuario(char matriz[][colunas], int *L, int *C)
{
    int i, j; // Controlador de laço
    int aux; // Variável que recebe a quantidade de linhas e colunas informadas pelo usuário

    printf("Digite o seu Caca-Palavras\n\n");

    do
    {
        printf("Quantidade de linhas (entre 1 e %d): ", linhas);
        scanf("%d", &aux);
    } while (aux == 0 || aux > linhas);
    *L = aux; // O ponteiro L recebe a quantidade de linhas digitada pelo usuário armazenada temporariamente em aux)

    do
    {
        printf("Quantidade de colunas (entre 1 e %d): ", colunas);
        scanf("%d", &aux);
    } while (aux == 0 || aux > colunas);
    *C = aux; // O ponteiro C recebe a quantidade de colunas digitada pelo usuário armazenada temporariamente em aux)

    for (i = 0; i < *L; i++) // Varredura das linhas
    {
        for (j = 0; j < *C; j++) // Varredura das colunas
        {
            fflush(stdin);
            printf("Digite o caractere da posicao %d.%d: ", i, j);
            scanf("%c", &matriz[i][j]);
        }
    }
}

/*
Nome: geraPalavraAleatoria
Objetivo: Gerar palavras aleatórias usando a tabela ASCII
parâmetros formais:
    - lista (parâmetro de entrada)
    - Q (parâmetro de saída, que será utilizado para receber a quantidade de palavras digitada pelo usuário, que será usada diversas vezes ao longo do programa)
Valor de retorno:
    - não há, pois é um procedimento
*/
void geraPalavraAleatoria(char lista[][tamMaxPalavras], int *Q)
{
    int tamPalavra; // Variável utilizada para armazenar o tamanho da palavra gerado aleatoriamente
    int aux; // Variável auxiliar para ler os valores de linha e coluna e atribuí-los aos parâmetros de saída
    int i, j; // Variáveis controladoras de laço

    printf("Geracao de palavras aleatorias\n\n");

    // Entrada de dados
    do
    {
        printf("Digite a quantidade de palavras (entre 1 e %d): ", qtdePalavras);
        scanf("%d", &aux);
    } while (aux == 0 || aux > qtdePalavras);

    *Q = aux; // Atribuição do valor lido ao ponteiro utilizado como parâmetro

    for (i = 0; i < aux; i++)
    {
        // Gera aleatoriamente o tamanho da palavra
        do
        {
            tamPalavra = rand()%tamMaxPalavras; // O tamanho da palavra é no máximo o tamMaxPalavras definido acima
        }
        while (tamPalavra == 0);

        // Gera aleatoriamente os caracteres da palavra, de acordo com o tamanho gerado
        for (j = 0; j < tamPalavra; j++)
        {
            do
            {
                lista[i][j] = rand()%91;
            } while(lista[i][j] < 65);
        }
        lista[i][tamPalavra] = '\0'; // Adiciona o caractere '\0' no final da palavra, indicando seu final
    }
}

/*
Nome: geraPelaMatriz
Objetivo: Gerar palavras aleatórias a partir da matriz
parâmetros formais:
    - mat (parâmetro de entrada)
    - lista (parâmetro de entrada e saída)
    - Q (parâmetro de saída, correspondente à quantidade de palavras digitada pelo usuário)
    - L (parâmetro de entrada, correspondente ao número de linhas da matriz)
    - C (parâmetro de entrada, correspondente ao número de colunas da matriz)
Valor de retorno:
    - não há, pois é um procedimento
*/
void geraPelaMatriz(char mat[][colunas], char lista[][tamMaxPalavras], int *Q, int L, int C)
{
    int i; // Variável controladora de laço
    int opcao; // Variável que armazenará a opção gerada aleatoriamente para a escolha do sentido de palavra que será palavra
    int aux; // Variável auxiliar para ler os valores de linha e coluna e atribuí-los aos parâmetros de saída

    printf("Geracao de palavras a partir de trechos da matriz\n\n");

    // Entrada de dados
    do
    {
        printf("Digite a quantidade de palavras (entre 1 e %d): ", qtdePalavras);
        scanf("%d", &aux);
    } while (aux == 0 || aux > qtdePalavras);

    *Q = aux; // Atribuição do valor lido ao ponteiro utilizado como parâmetro

    for (i = 0; i < *Q; i++)
    {
        opcao = rand()%opcoes; // geração de valores aleatórios para escolher a opção de palavra que será gerada

        //opções para geração aleatória de palavras em todos os sentidos possíveis, como indicado abaixo
        switch (opcao)
        {
            case 0:
                geraPalavraHorizontal(mat, lista, i, L, C);
                break;
            case 1:
                geraPalavraHorizontalInversa(mat, lista, i, L, C);
                break;
            case 2:
                geraPalavraVertical(mat, lista, i, L, C);
                break;
            case 3:
                geraPalavraVerticalInversa(mat, lista, i, L, C);
                break;
            case 4:
                geraPalavraDiagonalPrincipal(mat, lista, i, L, C);
                break;
            case 5:
                geraPalavraDiagonalPrincipalInversa(mat, lista, i, L, C);
                break;
            case 6:
                geraPalavraDiagonalSecundaria(mat, lista, i, L, C);
                break;
            case 7:
                geraPalavraDiagonalSecundariaInversa(mat, lista, i, L, C);
                break;
        }
    }
}

/*
Nome: listaArquivo
Objetivo: Ler o arquivo correspondente à lista de palavras desejada pelo usuário e incorporá-la no programa
parâmetros formais:
    - lista (parâmetro de entrada e saída)
    - L (parâmetro de saída, correspondente à quantidade de linhas da matriz, que será lida do arquivo)
Valor de retorno:
    - não há, pois é um procedimento
*/
void listaArquivo(char lista[][tamMaxPalavras], int *Q)
{
    FILE *arquivoLista; // Ponteiro correspondente ao arquivo de lista de palavras que será lido

    int i; // Variável controladora de laço
    char arquivo[tamMaxPalavras]; // String que será utilizada para ler o nome do arquivo que será aberto
    int qtde; // Variável que será utilizada para contar quantas palavras estão na lista que está sendo aberta

    printf("Lista de palavras a partir de um arquivo\n\n");

    // Entrada do nome do arquivo
    fflush(stdin);
    printf("Digite o nome do arquivo desejado para a lista de palavras: ");
    gets(arquivo);

    // Abertura do arquivo
    arquivoLista = fopen(arquivo, "rt");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivoLista == NULL)
    {
        printf("Erro na abertura do arquivo\n"); // Caso ocorra um erro, o programa será encerrado
        exit(1);
    }

    // Inicialização de variáveis
    qtde = 0; // Variável que conta a quantidade de palavras
    i = 0; // Variável que percorrerá as linhas da lista de palavras

    // Leitura das palavras a partir do arquivo
    while(!feof(arquivoLista)) // laço que indica que a leitura deverá continuar, enquanto o fim do arquivo não tiver sido alcançado
    {
        fgets(lista[i], tamMaxPalavras, arquivoLista); // Leitura das palavras a partir do arquivo
        // Incremento de variáveis
        qtde++;
        i++;
    }

    *Q = qtde; // Atribuição do valor lido ao ponteiro utilizado como parâmetro

    // Fechamento do arquivo
    fclose(arquivoLista);

    // Quando é lida, a palavra vem com o caractere de pular linha e depois o \0
    // Este laço serve para colocar o \0 na posição correta em todas as palavras e corrigir o seu tamanho
    for (i = 0; i < *Q-1; i++) // Este laço vai até a quantidade de palavras -1, pois a última palavra é lida corretamente
        lista[i][strlen(lista[i])-1] = '\0';
}

/*
Nome: listaUsuario
Objetivo: o usuário digita as palavras que deseja para verificar sua existência na matriz
parâmetros formais:
    - lista (parâmetro de entrada e saída, representando a lista que será constituída pelas palavras que o usuário digitar)
    - Q (parâmetro de saída, que receberá a quantidade de palavras digitadas pelo usuário)
Valor de retorno:
    - não há, pois é um procedimento
*/
void listaUsuario(char lista[][tamMaxPalavras], int *Q)
{
    int i; // Controlador de laço
    int aux; // Variável que irá atribuir a quantidade de palavras para o ponteiro Q

    printf("Digite a sua lista de palavras\n\n");

    do
    {
        printf("Digite a quantidade de palavras (entre 1 e %d): ", qtdePalavras);
        scanf("%d", &aux);
    } while (aux == 0 || aux > qtdePalavras);

    *Q = aux; // Atribuição da quantidade de palavras de aux para Q

    for (i = 0; i < *Q; i++) // Varredura para listar todas as palavras que o usuário digitar
    {
        fflush(stdin);
        printf("Digite a palavra: ");
        gets(lista[i]);
    }
}

/*
Nome: geraMatriz
Objetivo: gerar matriz com caracteres aleatórios
parâmetros formais:
    - mat (parâmetro de entrada e saída representando a matriz)
    - L (parâmetro de entrada, contendo a quantidade de linhas que o usuário irá escolher para gerá-la)
    - C (parâmetro de entrada, contendo a quantidade de colunas que o usuário irá escolher para gerá-la)
Valor de retorno:
    - Nenhum, pois é um procedimento
*/
void geraMatriz(char mat[][colunas], int L, int C)
{
    int i, j; // Controladores de laço

    for (i = 0; i < L; i++) // Varredura no sentido da linha
        for (j = 0; j < C; j++) // Varredura no sentido da coluna
            do
            {
                mat[i][j] = rand()%91; // geração de caracteres aleatórios em cada posição da matriz; Atribuído 91, pois seguindo a tabela ASCII é o término dos caracteres maiúsculo
            } while(mat[i][j] < 65 || mat[i][j] > 90); // valores na tabela ASCII correspondentes às letras maiúsculas
}

/*
Nome: geraPalavraHorizontal
Objetivo: gerar palavras que são retiradas dos trechos horizontais da matriz (independente de qual seja escolhida)
parâmetros formais:
    - matriz (parâmetro de entrada)
    - lista (parâmetro de entrada e saída, contendo as palavras que vão ser geradas especificadamente nesse procedimento)
    - indice (parâmetro de entrada, informando a qual o índice que respectiva palavra ocupa na lista)
    - linha (parâmetro de entrada, informando a quantidade de linhas da matriz)
    - coluna (parâmetro de entrada, informando a quantidade de colunas da matriz)
Valor de retorno:
    - não há, pois é um procedimento
*/
void geraPalavraHorizontal(char matriz[][colunas], char lista[][tamMaxPalavras], int indice, int linha, int coluna)
{
    int j; // Variável controladora de laço
    int tamPalavra, posicao; // Variáveis referentes à geração da palavra
    int L, C; // Variáveis auxiliares para obter os valores de linha e coluna da primeira letra da palavra

    // Gera o tamanho da palavra
    do
    {
        tamPalavra = rand()%tamMaxPalavras; // O tamanho da palavra é no máximo o tamMaxPalavras definido acima
    } while (tamPalavra == 0 || tamPalavra >= coluna); // Essa condição restringe o tamanho da palavra para que ela não fique maior do que as dimensões da matriz

    // Gera aleatoriamente a posição da primeira letra da palavra
    L = rand()%linha; // O valor da linha está compreendido no intervalo (0, número de linhas da matriz)
    C = rand()%(coluna - tamPalavra + 1); // O valor da coluna está compreendido no intervalo (0, número de colunas - tamanho da palavra),
                                          // de modo que a palavra gerada estará compreendida dentro da matriz
                                          // O acréscimo do valor 1 é realizado de modo que o intervalo de geração do valor da coluna compreenda todas as possibilidades

    // posição é referente à posição das letras da palavra que está sendo gerada
    posicao = 0;
    // j começa no valor da coluna e vai até valor da coluna + tamanho da palavra
    // Variável utilizada para percorrer a matriz
    j = C;

    do
    {
        lista[indice][posicao] = matriz[L][j];
        posicao++;
        j++;
    } while (posicao < tamPalavra); // Esse laço ocorre enquanto a variável posição for menor que o tamanho da palavra, de modo que todas as posições sejam percorridas

    lista[indice][tamPalavra] = '\0'; // Adiciona o caractere '\0' no final da palavra, indicando seu final
}

/*
Nome: geraPalavraHorizontalInversa
Objetivo: gerar palavras que são retiradas dos trechos horizontais invertidos da matriz (independente de qual seja escolhida)
parâmetros formais:
    - matriz (parâmetro de entrada)
    - lista (parâmetro de entrada e saída, contendo as palavras que vão ser geradas especificadamente nesse procedimento)
    - indice (parâmetro de entrada, informando a qual o índice que respectiva palavra ocupa na lista)
    - linha (parâmetro de entrada, informando a quantidade de linhas da matriz)
    - coluna (parâmetro de entrada, informando a quantidade de colunas da matriz)
Valor de retorno:
    - não há, pois é um procedimento
*/
void geraPalavraHorizontalInversa(char matriz[][colunas], char lista[][tamMaxPalavras], int indice, int linha, int coluna)
{
    int j; // Variável controladora de laço
    int tamPalavra, posicao; // Variáveis referentes à geração da palavra
    int L, C; // Variáveis auxiliares para obter os valores de linha e coluna da primeira letra da palavra

    // Gera o tamanho da palavra
    do
    {
        tamPalavra = rand()%tamMaxPalavras; // O tamanho da palavra é no máximo o tamMaxPalavras definido acima
    } while (tamPalavra == 0 || tamPalavra >= coluna); // Essa condição restringe o tamanho da palavra para que ela não fique maior do que as dimensões da matriz

    // pega a posicao da primeira letra
    L = rand()%linha; // O valor da linha está compreendido no intervalo (0, número de linhas da matriz)
    do
    {
        C = rand()%coluna;
    } while(C < tamPalavra-1); // A coluna da palavra deve ser maior do que o seu tamanho, de modo que ela fique de acordo com as dimensões da matriz

    // posição é referente àposição das letras da palavra que está sendo gerada
    posicao = 0;
    // j começa no valor da coluna e vai até valor da coluna + tamanho da palavra
    // Variável utilizada para percorrer a matriz
    j = C;

    do
    {
        lista[indice][posicao] = matriz[L][j];
        posicao++;
        j--;
    } while (posicao < tamPalavra); // Esse laço ocorre enquanto a variável posição for menor que o tamanho da palavra, de modo que todas as posições sejam percorridas

    lista[indice][tamPalavra] = '\0'; // Adiciona o caractere '\0' no final da palavra, indicando seu final
}

/*
Nome: geraPalavraVertical
Objetivo: gerar palavras que são retiradas dos trechos verticais da matriz (independente de qual seja escolhida)
parâmetros formais:
    - matriz (parâmetro de entrada)
    - lista (parâmetro de entrada e saída, contendo as palavras que vão ser geradas especificadamente nesse procedimento)
    - indice (parâmetro de entrada, informando a qual o índice que respectiva palavra ocupa na lista)
    - linha (parâmetro de entrada, informando a quantidade de linhas da matriz)
    - coluna (parâmetro de entrada, informando a quantidade de colunas da matriz)
Valor de retorno:
    - não há, pois é um procedimento
*/
void geraPalavraVertical(char matriz[][colunas], char lista[][tamMaxPalavras], int indice, int linha, int coluna)
{
    int i; // Variável controladora de laço
    int tamPalavra, posicao; // Variáveis referentes à geração da palavra
    int L, C; // Variáveis auxiliares para obter os valores de linha e coluna da primeira letra da palavra

    // Gera o tamanho da palavra
    do
    {
        tamPalavra = rand()%tamMaxPalavras; // O tamanho da palavra é no máximo o tamMaxPalavras definido acima
    } while (tamPalavra == 0 || tamPalavra >= linha); // Essa condição restringe o tamanho da palavra para que ela não fique maior do que as dimensões da matriz

    // pega a posicao da primeira letra
    L = rand()%(linha - tamPalavra + 1); // O valor da linha está compreendido no intervalo (0, número de linhas - tamanho da palavra),
                                         // de modo que a palavra gerada estará compreendida dentro da matriz
                                         // O acréscimo do valor 1 é realizado de modo que o intervalo de geração do valor da linha compreenda todas as possibilidades

    C = rand()%coluna; // O valor da coluna está compreendido no intervalo (0, número de colunas da matriz)
                       // de modo que a palavra gerada estará compreendida dentro da matriz

    // posição é referente àposição das letras da palavra que está sendo gerada
    posicao = 0;
    // j começa no valor da coluna e vai até valor da coluna + tamanho da palavra
    // Variável utilizada para percorrer a matriz
    i = L;

    do
    {
        lista[indice][posicao] = matriz[i][C];
        posicao++;
        i++;
    } while (posicao < tamPalavra); // Esse laço ocorre enquanto a variável posição for menor que o tamanho da palavra, de modo que todas as posições sejam percorridas

    lista[indice][tamPalavra] = '\0'; // Adiciona o caractere '\0' no final da palavra, indicando seu final
}

/*
Nome: geraPalavraVerticalInversa
Objetivo: gerar palavras que são retiradas dos trechos verticais invertidos da matriz (independente de qual seja escolhida)
parâmetros formais:
    - matriz (parâmetro de entrada)
    - lista (parâmetro de entrada e saída, contendo as palavras que vão ser geradas especificadamente nesse procedimento)
    - indice (parâmetro de entrada, informando a qual o índice que respectiva palavra ocupa na lista)
    - linha (parâmetro de entrada, informando a quantidade de linhas da matriz)
    - coluna (parâmetro de entrada, informando a quantidade de colunas da matriz)
Valor de retorno:
    - não há, pois é um procedimento
*/
void geraPalavraVerticalInversa(char matriz[][colunas], char lista[][tamMaxPalavras], int indice, int linha, int coluna)
{
    int i; // Variável controladora de laço
    int tamPalavra, posicao; // Variáveis referentes à geração da palavra
    int L, C; // Variáveis auxiliares para obter os valores de linha e coluna da primeira letra da palavra

    // Gera o tamanho da palavra
    do
    {
        tamPalavra = rand()%tamMaxPalavras; // O tamanho da palavra é no máximo o tamMaxPalavras definido acima
    } while (tamPalavra == 0 || tamPalavra >= linha); // Essa condição restringe o tamanho da palavra para que ela não fique maior do que as dimensões da matriz

    // Pega a posicao da primeira letra
    do
    {
        L = rand()%linha;
    }
    while (L < tamPalavra - 1); // A linha da palavra deve ser maior do que o seu tamanho, de modo que ela fique de acordo com as dimensões da matriz

    C = rand()%coluna; // O valor da coluna está compreendido no intervalo (0, número de colunas da matriz)
                       // de modo que a palavra gerada estará compreendida dentro da matriz

    // posição é referente àposição das letras da palavra que está sendo gerada
    posicao = 0;
    // j começa no valor da coluna e vai até valor da coluna + tamanho da palavra
    // Variável utilizada para percorrer a matriz
    i = L;

    do
    {
        lista[indice][posicao] = matriz[i][C];
        posicao++;
        i--;
    } while (posicao < tamPalavra); // Esse laço ocorre enquanto a variável posição for menor que o tamanho da palavra, de modo que todas as posições sejam percorridas

    lista[indice][tamPalavra] = '\0'; // Adiciona o caractere '\0' no final da palavra, indicando seu final
}

/*
Nome: geraPalavraDiagonalPrincipal
Objetivo: gerar palavras que são retiradas da matriz dos trechos da diagonal principal e suas paralelas (independente de qual seja escolhida)
parâmetros formais:
    - matriz (parâmetro de entrada)
    - lista (parâmetro de entrada e saída, contendo as palavras que vão ser geradas especificadamente nesse procedimento)
    - indice (parâmetro de entrada, informando a qual o índice que respectiva palavra ocupa na lista)
    - linha (parâmetro de entrada, informando a quantidade de linhas da matriz)
    - coluna (parâmetro de entrada, informando a quantidade de colunas da matriz)
Valor de retorno:
    - não há, pois é um procedimento
*/
void geraPalavraDiagonalPrincipal(char matriz[][colunas], char lista[][tamMaxPalavras], int indice, int linha, int coluna)
{
    int i, j; // Variáveis controladoras de laço
    int tamPalavra, posicao; // Variáveis referentes à geração da palavra
    int L, C; // Variáveis auxiliares para obter os valores de linha e coluna da primeira letra da palavra

    // Gera o tamanho da palavra
    do
    {
        tamPalavra = rand()%tamMaxPalavras; // O tamanho da palavra é no máximo o tamMaxPalavras definido acima
    } while (tamPalavra == 0 || tamPalavra >= linha || tamPalavra >= coluna); // Essa condição restringe o tamanho da palavra para que ela não fique maior do que as dimensões da matriz

    // Pega a posicao da primeira letra
    L = rand()%(linha - tamPalavra + 1); // O valor da linha está compreendido no intervalo (0, número de linhas - tamanho da palavra),
                                         // de modo que a palavra gerada estará compreendida dentro da matriz
                                         // O acréscimo do valor 1 é realizado de modo que o intervalo de geração do valor da linha compreenda todas as possibilidades
    C = rand()%(coluna - tamPalavra + 1); // O valor da coluna está compreendido no intervalo (0, número de colunas - tamanho da palavra),
                                          // de modo que a palavra gerada estará compreendida dentro da matriz
                                          // O acréscimo do valor 1 é realizado de modo que o intervalo de geração do valor da coluna compreenda todas as possibilidades

    // posição é referente àposição das letras da palavra que está sendo gerada
    posicao = 0;
    // j começa no valor da coluna e vai até valor da coluna + tamanho da palavra
    // Variáveis utilizadas para percorrer a matriz
    i = L;
    j = C;

    do
    {
        lista[indice][posicao] = matriz[i][j];
        posicao++;
        i++;
        j++;
    } while (posicao < tamPalavra); // Esse laço ocorre enquanto a variável posição for menor que o tamanho da palavra, de modo que todas as posições sejam percorridas

    lista[indice][tamPalavra] = '\0'; // Adiciona o caractere '\0' no final da palavra, indicando seu final
}

/*
Nome: geraPalavraDiagonalPrincipalInversa
Objetivo: gerar palavras que são retiradas da matriz dos trechos da diagonal principal inversa e suas paralelas (independente de qual seja escolhida)
parâmetros formais:
    - matriz (parâmetro de entrada)
    - lista (parâmetro de entrada e saída, contendo as palavras que vão ser geradas especificadamente nesse procedimento)
    - indice (parâmetro de entrada, informando a qual o índice que respectiva palavra ocupa na lista)
    - linha (parâmetro de entrada, informando a quantidade de linhas da matriz)
    - coluna (parâmetro de entrada, informando a quantidade de colunas da matriz)
Valor de retorno:
    - não há, pois é um procedimento
*/
void geraPalavraDiagonalPrincipalInversa(char matriz[][colunas], char lista[][tamMaxPalavras], int indice, int linha, int coluna)
{
    int i, j; // Variáveis controladoras de laço
    int tamPalavra, posicao; // Variáveis referentes à geração da palavra
    int L, C; // Variáveis auxiliares para obter os valores de linha e coluna da primeira letra da palavra

    // Gera o tamanho da palavra
    do
    {
        tamPalavra = rand()%tamMaxPalavras; // O tamanho da palavra é no máximo o tamMaxPalavras definido acima
    } while (tamPalavra == 0 || tamPalavra >= linha || tamPalavra >= coluna); // Essa condição restringe o tamanho da palavra para que ela não fique maior do que as dimensões da matriz

    // Pega a posicao da primeira letra
    do
    {
        L = rand()%linha;
    }
    while (L < tamPalavra - 1); // A linha da palavra deve ser maior do que o seu tamanho, de modo que ela fique de acordo com as dimensões da matriz

    do
    {
        C = rand()%coluna;
    }
    while (C < tamPalavra - 1); // A coluna da palavra deve ser maior do que o seu tamanho, de modo que ela fique de acordo com as dimensões da matriz

    // posição é referente àposição das letras da palavra que está sendo gerada
    posicao = 0;
    // j começa no valor da coluna e vai até valor da coluna + tamanho da palavra
    // Variável utilizada para percorrer a matriz
    i = L;
    j = C;

    do
    {
        lista[indice][posicao] = matriz[i][j];
        posicao++;
        i--;
        j--;
    } while (posicao < tamPalavra); // Esse laço ocorre enquanto a variável posição for menor que o tamanho da palavra, de modo que todas as posições sejam percorridas

    lista[indice][tamPalavra] = '\0'; // Adiciona o caractere '\0' no final da palavra, indicando seu final
}

/*
Nome: geraPalavraDiagonalSecundaria
Objetivo: gerar palavras que são retiradas da matriz dos trechos da diagonal secundária e suas paralelas (independente de qual seja escolhida)
parâmetros formais:
    - matriz (parâmetro de entrada)
    - lista (parâmetro de entrada e saída, contendo as palavras que vão ser geradas especificadamente nesse procedimento)
    - indice (parâmetro de entrada, informando a qual o índice que respectiva palavra ocupa na lista)
    - linha (parâmetro de entrada, informando a quantidade de linhas da matriz)
    - coluna (parâmetro de entrada, informando a quantidade de colunas da matriz)
Valor de retorno:
    - não há, pois é um procedimento
*/
void geraPalavraDiagonalSecundaria(char matriz[][colunas], char lista[][tamMaxPalavras], int indice, int linha, int coluna)
{
    int i, j; // Variáveis controladoras de laço
    int tamPalavra, posicao; // Variáveis referentes à geração da palavra
    int L, C; // Variáveis auxiliares para obter os valores de linha e coluna da primeira letra da palavra

    // Gera o tamanho da palavra
    do
    {
        tamPalavra = rand()%tamMaxPalavras; // O tamanho da palavra é no máximo o tamMaxPalavras definido acima
    } while (tamPalavra == 0 || tamPalavra >= linha || tamPalavra >= coluna); // Essa condição restringe o tamanho da palavra para que ela não fique maior do que as dimensões da matriz

    // Pega a posicao da primeira letra

    L = rand()%(linha - tamPalavra + 1); // O valor da linha está compreendido no intervalo (0, número de linhas - tamanho da palavra),
                                         // de modo que a palavra gerada estará compreendida dentro da matriz
                                         // O acréscimo do valor 1 é realizado de modo que o intervalo de geração do valor da linha compreenda todas as possibilidades

    do
    {
        C = rand()%coluna;
    } while (C < tamPalavra - 1); // A coluna da palavra deve ser maior do que o seu tamanho, de modo que ela fique de acordo com as dimensões da matriz

    // posição é referente àposição das letras da palavra que está sendo gerada
    posicao = 0;
    // j começa no valor da coluna e vai até valor da coluna + tamanho da palavra
    // Variável utilizada para percorrer a matriz
    i = L;
    j = C;

    do
    {
        lista[indice][posicao] = matriz[i][j];
        posicao++;
        i++;
        j--;
    } while (posicao < tamPalavra); // Esse laço ocorre enquanto a variável posição for menor que o tamanho da palavra, de modo que todas as posições sejam percorridas

    lista[indice][tamPalavra] = '\0'; // Adiciona o caractere '\0' no final da palavra, indicando seu final
}

/*
Nome: geraPalavraDiagonalSecundariaInversa
Objetivo: gerar palavras que são retiradas da matriz dos trechos da diagonal secundária inversa e suas paralelas (independente de qual seja escolhida)
parâmetros formais:
    - matriz (parâmetro de entrada)
    - lista (parâmetro de entrada e saída, contendo as palavras que vão ser geradas especificadamente nesse procedimento)
    - indice (parâmetro de entrada, informando a qual o índice que respectiva palavra ocupa na lista)
    - linha (parâmetro de entrada, informando a quantidade de linhas da matriz)
    - coluna (parâmetro de entrada, informando a quantidade de colunas da matriz)
Valor de retorno:
    - não há, pois é um procedimento
*/
void geraPalavraDiagonalSecundariaInversa(char matriz[][colunas], char lista[][tamMaxPalavras], int indice, int linha, int coluna)
{
    int i, j; // Variáveis controladoras de laço
    int tamPalavra, posicao; // Variáveis referentes à geração da palavra
    int L, C; // Variáveis auxiliares para obter os valores de linha e coluna da primeira letra da palavra

    // Gera o tamanho da palavra
    do
    {
        tamPalavra = rand()%tamMaxPalavras; // O tamanho da palavra é no máximo o tamMaxPalavras definido acima
    } while (tamPalavra == 0 || tamPalavra >= linha || tamPalavra >= coluna); // Essa condição restringe o tamanho da palavra para que ela não fique maior do que as dimensões da matriz

    // Pega a posicao da primeira letra
    do
    {
        L = rand()%linha;
    } while (L < tamPalavra - 1); // A linha da palavra deve ser maior do que o seu tamanho, de modo que ela fique de acordo com as dimensões da matriz

    C = rand()%(coluna - tamPalavra + 1); // O valor da linha está compreendido no intervalo (0, número de linhas - tamanho da palavra),
                                          // de modo que a palavra gerada estará compreendida dentro da matriz
                                          // O acréscimo do valor 1 é realizado de modo que o intervalo de geração do valor da linha compreenda todas as possibilidades

    // posição é referente àposição das letras da palavra que está sendo gerada
    posicao = 0;
    // j começa no valor da coluna e vai até valor da coluna + tamanho da palavra
    // Variável utilizada para percorrer a matriz
    i = L;
    j = C;

    do
    {
        lista[indice][posicao] = matriz[i][j];
        posicao++;
        i--;
        j++;
    } while (posicao < tamPalavra); // Esse laço ocorre enquanto a variável posição for menor que o tamanho da palavra, de modo que todas as posições sejam percorridas

    lista[indice][tamPalavra] = '\0'; // Adiciona o caractere '\0' no final da palavra, indicando seu final
}

/*
Nome: verHorizontal
Objetivo: Verificar se uma palavra está contida na matriz no sentido horizontal
parâmetros formais:
    - palavras (parâmetro de entrada, contendo a lista de palavras)
    - matriz (parâmetro de entrada, contendo a matriz para verificação)
    - posicaoP (parâmetro de entrada, contendo a posição da palavra na matriz da lista de palavras)
    - L (parâmetro de entrada, contendo a quantidade de linhas da matriz)
    - C (parâmetro de entrada, contendo a quantidade de colunas da matriz)
Valor de retorno:
    - 1 caso encontre a palavra e 0 caso não encontre
*/
int verHorizontal(char palavras[][tamMaxPalavras], char matriz[][colunas], int posicaoP, int L, int C)
{
    int i, j; // Controladores de laço para varrer linha e coluna respectivamente
    int percorre ; // Controlador da varredura da palavra

    for (i = 0; i < L; i++) // Varredura da matriz no sentido linha
    {
        percorre = 0; // Reinicia a verificação quando troca de linha
        for (j = 0; j < C; j++) // Varredura da matriz no sentido coluna
        {
            if (palavras[posicaoP][percorre] == matriz[i][j]) // condição onde a primeira letra da palavra é encontrada
            {
                percorre++; // Quando a condição for verdadeira, compara a próxima letra da palavra
                if (percorre == strlen(palavras[posicaoP])) // Quando a palavra total percorrida é igual a palavra encontrada na matriz
                    return 1; // Situação em que a palavra foi encontrada
            }
            else if ((matriz[i][j] == matriz[i][j-1]) && (matriz[i][j] == palavras[posicaoP][0])) //Quando a primeira letra da palavra aparece duas vezes consecutivas na mesma linha
                percorre = 1;
            else
                percorre = 0; //Reinicia a verificação na mesma linha
        }
    }
    return 0; //Situação em que a palavra não foi encontrada
}

/*
Nome: verHorizontalInversa
Objetivo: Verificar se uma palavra está contida na matriz no sentido horizontal de trás para frente
parâmetros:
    - palavras (parâmetro de entrada, contendo a lista de palavras)
    - matriz (parâmetro de entrada, contendo a matriz para verificação)
    - posicaoP (parâmetro de entrada, contendo a posição da palavra na matriz da lista de palavras)
    - L (parâmetro de entrada, contendo a quantidade de linhas da matriz)
    - C (parâmetro de entrada, contendo a quantidade de colunas da matriz)
Valor de retorno:
    - 1 caso encontre a palavra e 0 caso não encontre
*/
int verHorizontalInversa(char palavras[][tamMaxPalavras], char matriz[][colunas], int posicaoP, int L, int C)
{
    int i, j; // Variáveis para controle de laço na varredura da matriz
    int percorre; // Controlador da varredura da palavra

    for (i = 0; i < L; i++) // Varredura da matriz no sentido linha
    {
        percorre = 0; //Reinicia a verificação quando troca de linha
        for (j = C-1; j >= 0; j--) //Varredura da matriz no sentido inverso da coluna
        {
            if (palavras[posicaoP][percorre] == matriz[i][j]) // condição em que a primeira letra da palavra é encontrada na matriz
            {
                percorre++; //Quando a condição for verdadeira, compara a próxima letra da palavra
                if (percorre == strlen(palavras[posicaoP])) // condição em que todas as letras da palavra foram encontradas (percorridas)
                    return 1; //Situação em que a palavra foi encontrada
            }
            else if ((matriz[i][j] == matriz[i][j+1]) && (matriz[i][j] == palavras[posicaoP][0])) // Quando a primeira letra da palavra aparece duas vezes consecutivas na mesma linha
                percorre = 1;
            else
                percorre = 0; //Reinicia a verificação na mesma linha
        }
    }
    return 0; //Situação em que a palavra não foi encontrada
}

/*
Nome: verVertical
Objetivo: Verificar se uma palavra está contida na matriz no sentido vertical
parâmetros:
    - palavras (parâmetro de entrada, contendo a lista de palavras)
    - matriz (parâmetro de entrada, contendo a matriz para verificação)
    - posicaoP (parâmetro de entrada, contendo a posição da palavra na matriz da lista de palavras)
    - L (parâmetro de entrada, contendo a quantidade de linhas da matriz)
    - C (parâmetro de entrada, contendo a quantidade de colunas da matriz)
Valor de retorno:
    - 1 caso encontre a palavra e 0 caso não encontre
*/
int verVertical(char palavras[][tamMaxPalavras], char matriz[][colunas], int posicaoP, int L, int C)
{
    int i, j; // Controlador de laço
    int percorre; // Controlador da varredura da palavra

    for (j = 0; j < C; j++) // Varredura da matriz no sentido coluna
    {
        percorre = 0; //Reinicia a verificação quando troca de coluna
        for (i = 0; i < L; i++) // Varredura da matriz no sentindo linha
        {
            if (palavras[posicaoP][percorre] == matriz[i][j]) // condição para verificar se vai encontrar a letra na matriz
            {
                percorre++; //Quando a condição for verdadeira, compara a próxima letra da palavra
                if (percorre == strlen(palavras[posicaoP]))
                    return 1; //Situação em que a palavra foi encontrada
            }
            else if ((matriz[i][j] == matriz[i-1][j]) && (matriz[i][j] == palavras[posicaoP][0])) // Quando a primeira letra da palavra aparece duas vezes consecutivas na mesma linha
                percorre = 1;
            else
                percorre = 0; //Reinicia a verificação na mesma coluna
        }
    }
    return 0; //Situação em que a palavra não foi encontrada
}

/*
Nome: verVerticalInversa
Objetivo: Verificar se uma palavra está contida na matriz no sentido vertical de baixo para cima
parâmetros:
    - palavras (parâmetro de entrada, contendo a lista de palavras)
    - matriz (parâmetro de entrada, contendo a matriz para verificação)
    - posicaoP (parâmetro de entrada, contendo a posição da palavra na matriz da lista de palavras)
    - L (parâmetro de entrada, contendo a quantidade de linhas da matriz)
    - C (parâmetro de entrada, contendo a quantidade de colunas da matriz)
Valor de retorno:
    - 1 caso encontre a palavra e 0 caso não encontre
*/
int verVerticalInversa(char palavras[][tamMaxPalavras], char matriz[][colunas], int posicaoP, int L, int C)
{
    int i, j; // Controlador de laço e verificação
    int percorre; // Controlador de varredura da palavra

    for (j = 0; j < C; j++) // Varredura da matriz no sentido coluna
    {
        percorre = 0; // Reinicia a verificação quando troca de coluna
        for (i = L-1; i >= 0; i--) // Varredura da matriz no sentido linha de baixo para cima
        {
            if (palavras[posicaoP][percorre] == matriz[i][j]) // condição para verificar se vai encontrar a letra na matriz
            {
                percorre++; // Quando a condição for verdadeira, compara a próxima letra da palavra
                if (percorre == strlen(palavras[posicaoP]))
                    return 1; // Situação em que a palavra foi encontrada
            }
            else if ((matriz[i][j] == matriz[i+1][j]) && (matriz[i][j] == palavras[posicaoP][0])) // Quando a primeira letra da palavra aparece duas vezes consecutivas na mesma linha
                percorre = 1;
            else
                percorre = 0; // Reinicia a verificação na mesma coluna
        }
    }
    return 0; // Situação em que a palavra não foi encontrada
}

/*
Nome: verDiagonalPrincipal
Objetivo: Verificar se uma palavra está contida na matriz na diagonal principal e todas as diagonais paralelas a ela
parâmetros:
    - palavras (parâmetro de entrada, contendo a lista de palavras)
    - matriz (parâmetro de entrada, contendo a matriz para verificação)
    - posicaoP (parâmetro de entrada, contendo a posição da palavra na matriz da lista de palavras)
    - li (parâmetro de entrada, contendo a quantidade de linhas da matriz)
    - co (parâmetro de entrada, contendo a quantidade de colunas da matriz)
Valor de retorno:
    - 1 caso encontre a palavra e 0 caso não encontre
*/
int verDiagonalPrincipal(char palavras[][tamMaxPalavras], char matriz[][colunas], int posicaoP, int li, int co)
{
    int i, j; // Controlador de laço
    int percorre; // Controlador de varredura da palavra
    int L, C; // Linhas e colunas que, respectivamente, vão receber os controladores de laço i e j

    for (i = 0; i < li; i++) // Varredura da matriz no sentido linha
    {
        for (j = 0; j < co; j++) // Varredura da matriz no sentindo coluna
        {
            percorre = 0; // Reinicia a verificação quando troca de coluna ou linha

            if (palavras[posicaoP][percorre] == matriz[i][j]) // condição para verificar se vai encontrar a primeira letra na matriz
            {
                L = i;
                C = j;
                percorre++;
                do
                {
                    L++;
                    C++;
                    if (palavras[posicaoP][percorre] == matriz[L][C]) // condição para verificar se vai encontrar as demais letras da palavra
                    {
                        percorre++;
                        if (percorre == strlen(palavras[posicaoP])) // Se o percorre for igual o tamanho da palavra, ela foi encontrada
                            return 1; // Situação em que a palavra foi encontrada
                    }
                    else if ((matriz[L][C] == matriz[L-1][C-1]) && (matriz[L][C] == palavras[posicaoP][0])) // Quando a primeira letra da palavra aparece duas vezes consecutivas na mesma diagonal
                        percorre = 1;
                    else
                        percorre = 0;
                } while (L < linhas && C < colunas);
            }
        }
    }
    return 0; // Situação em que a palavra não foi encontrada
}

/*
Nome: verDiagonalPrincipalInversa
Objetivo: Verificar se uma palavra está contida na matriz na diagonal principal inversa, ou seja, de baixo para cima e todas as diagonais paralelas a ela
parâmetros:
    - palavras (parâmetro de entrada, contendo a lista de palavras)
    - matriz (parâmetro de entrada, contendo a matriz para verificação)
    - posicaoP (parâmetro de entrada, contendo a posição da palavra na matriz da lista de palavras)
    - li (parâmetro de entrada, contendo a quantidade de linhas da matriz)
    - co (parâmetro de entrada, contendo a quantidade de colunas da matriz)
Valor de retorno:
    - 1 caso encontre a palavra e 0 caso não encontre
*/
int verDiagonalPrincipalInversa(char palavras[][tamMaxPalavras], char matriz[][colunas], int posicaoP, int li, int co)
{
    int i, j; // Controlador de laço
    int percorre; // Controlador de varredura da palavra
    int L, C; // Linhas e colunas que, respectivamente, vão receber os controladores de laço i e j

    for (i = 0; i < li; i++) // Varredura no sentido linha
    {
        for (j = 0; j < co; j++) // Varredura no sentido coluna
        {
            percorre = 0; // Reinicia a verificação quando troca de coluna ou linha
            if (palavras[posicaoP][percorre] == matriz[i][j]) // condição para verificar se vai encontrar a primeira letra da palavra
            {
                L = i;
                C = j;
                percorre++;
                do
                {
                    L--;
                    C--;
                    if (palavras[posicaoP][percorre] == matriz[L][C]) // condição para verificar se vai encontrar as demais letras das palavras
                    {
                        percorre++;
                        if (percorre == strlen(palavras[posicaoP])) // Situação em que o percorre é igual o tamanho da palavra
                            return 1; // Neste caso, a palavra foi encontrada
                    }
                    else if ((matriz[L][C] == matriz[L+1][C+1]) && (matriz[L][C] == palavras[posicaoP][0])) // Quando a primeira letra da palavra aparece duas vezes consecutivas na mesma diagonal
                        percorre = 1;
                    else
                        percorre = 0;
                } while (L > 0 && C > 0);
            }
        }
    }
    return 0; // Situação em que a palavra não foi encontrada
}

/*
Nome: verDiagonalSecundaria
Objetivo: Verificar se uma palavra está contida na matriz na diagonal secundária (diagonal principal espelhada) e todas as diagonais paralelas a ela
parâmetros:
    - palavras (parâmetro de entrada, contendo a lista de palavras)
    - matriz (parâmetro de entrada, contendo a matriz para verificação)
    - posicaoP (parâmetro de entrada, contendo a posição da palavra na matriz da lista de palavras)
    - li (parâmetro de entrada, contendo a quantidade de linhas da matriz)
    - co (parâmetro de entrada, contendo a quantidade de colunas da matriz)
Valor de retorno:
    - 1 caso encontre a palavra e 0 caso não encontre
*/
int verDiagonalSecundaria(char palavras[][tamMaxPalavras], char matriz[][colunas], int posicaoP, int li, int co)
{
    int i, j; // Controladores de laço para varredura da matriz
    int percorre; // Controlador da varredura da palavra buscada
    int L, C; // Linhas e colunas que, respectivamente, vão receber os controladores de laço i e j

    for (i = 0; i < li; i++) // Varredura da matriz no sentido linha
    {
        for (j = 0; j < co; j++) // Varredura da matriz no sentido coluna
        {
            percorre = 0;
            if (palavras[posicaoP][percorre] == matriz[i][j])
            {
                L = i;
                C = j;
                percorre++;
                do
                {
                    L++; // Incrementação da linha para que ela pule, seguindo o sentido da diagonal secundária
                    C--; // Decrementação da coluna, para que ela siga no sentido da siagonal secundária
                    if (palavras[posicaoP][percorre] == matriz[L][C]) // Caso em que a letra é encontrada e se verifica a próxima letra
                    {
                        percorre++;
                        if (percorre == strlen(palavras[posicaoP])) // Caso em que todas as letras foram percorridas e a palavra foi encontrada
                            return 1;
                    }
                    else if ((matriz[L][C] == matriz[L-1][C+1]) && (matriz[L][C] == palavras[posicaoP][0])) // Caso em que a primeira letra é igual a letra anterior
                        percorre = 1;
                    else
                        percorre = 0; // Caso em que a palavra não é encontrada
                } while (L < linhas && C > 0); // A verificação continua até que o tamanho de linhas e colunas seja excedido
            }
        }
    }
    return 0;
}

/*
Nome: verDiagonalSecundariaInversa
Objetivo: Verificar se uma palavra está contida na matriz na diagonal secundária inversa, ou seja, de baixo para cima e todas as diagonais paralelas a ela
parâmetros:
    - palavras (parâmetro de entrada, contendo a lista de palavras)
    - matriz (parâmetro de entrada, contendo a matriz para verificação)
    - posicaoP (parâmetro de entrada, contendo a posição da palavra na matriz da lista de palavras)
    - li (parâmetro de entrada, contendo a quantidade de linhas da matriz)
    - co (parâmetro de entrada, contendo a quantidade de colunas da matriz)
Valor de retorno:
    - 1 caso encontre a palavra e 0 caso não encontre
*/
int verDiagonalSecundariaInversa(char palavras[][tamMaxPalavras], char matriz[][colunas], int posicaoP, int li, int co)
{
    int i, j; // Controladores de laço para varredura da matriz
    int percorre; // Controlador da varredura da palavra
    int L, C; // Controladores de varredura no sentindo diagonal secundário inverso

    for (i = 0; i < li; i++) // Varredura da matriz no sentido linha
    {
        for (j = 0; j < co; j++) // Varredura da matriz no sentido coluna
        {
            percorre = 0;
            if (palavras[posicaoP][percorre] == matriz[i][j]) // Caso onde a primeira letra da palavra é encontrada
            {
                L = i; // A varredura para encontrar a palavra inicia na linha em que a primeira letra foi encontrada
                C = j; // A varredura para encontrar a palavra inicia na coluna em que a primeira letra foi encontrada
                percorre++; // Percorre incrementa para sinalizar a verificação da letra  seguinte
                do
                {
                    L--; // A linha de procura da palavra é decrementada para atender ao sentido diagonal secundário inverso
                    C++; // // A coluna de procura da palavra é incrementada para atender ao sentido diagonal secundário inverso
                    if (palavras[posicaoP][percorre] == matriz[L][C]) // Caso a letra seja encontrada, a busca continua
                    {
                        percorre++;
                        if (percorre == strlen(palavras[posicaoP])) // Se todas as letras forem encontradas, a palavra foi encontrada
                            return 1;
                    }
                    else if ((matriz[L][C] == matriz[L+1][C-1]) && (matriz[L][C] == palavras[posicaoP][0])) // Caso em que a primeira letra da palavra coincide com a letra anterior
                        percorre = 1;
                    else
                        percorre = 0; // Caso em que a palavra não é encontrada
                } while (L > 0 && C < colunas); // O laço é repetido até que a diagonal secundária inversa seja totalmente varrida
            }
        }
    }
    return 0;
}

/*
Nome: imprimeMatriz
Objetivo: Imprimir na tela a matriz escolhida pelo usuário
parâmetros formais:
    - matriz (parâmetro de entrada e saída, contendo a matriz que será mostrada)
    - L (parâmetro de entrada, regulando o número de linhas da matriz)
    - C (parâmetro de entrada, regulando o número de colunas da matriz)
Valor de retorno:
    - não há valor de retorno, pois é procedimento
*/
void imprimeMatriz (char matriz[][colunas], int L, int C)
{
    int i, j;

    printf("Caca-Palavras\n\n");

    for (i=0; i<L; i++)
    {
        for (j=0; j<C; j++)
            printf ("%2c ", matriz[i][j]);
        printf ("\n");
    }
    printf ("\n");
}

/*
Nome: imprimeLista
Objetivo: imprimir na tela as palavras contidas na lista escolhida pelo usuário
parâmetros formais:
    - palavras (parâmetro de entrada e saída)
    - quantidade (parâmetro de entrada indicando a quantidade de palavras contidas na lista)
Valor de retorno:
    - não há valor de retorno, pois é procedimento
*/
void imprimeLista (char palavras[][tamMaxPalavras], int quantidade)
{
    int i;

    printf("Lista de palavras\n\n");

    for (i = 0; i < quantidade; i++)
        printf("%d - %s\n", i+1, palavras[i]);

    printf("\n");
}

/*
Nome: varredura
Objetivo: realizar a varredura em todos os sentidos possíveis para verificar se as palavras foram encontradas ou não
parâmetros formais:
    - lista (parâmetro de entrada, realizando a varredura de todas as palavras para verificar se elas existem na matriz)
    - matriz (parâmetro de entrada, realizando a varredura na matriz de acordo com as palavras listadas para verificar se elas existem ou não)
    - L (parâmetro de entrada, representando a quantidade de linhas na matriz)
    - C (parâmetro de entrada, representando a quantidade de colunas na matriz)
    - Q (parâmetro de entrada, representando a quantidade de palavras existentes na lista)
Valor de retorno:
    - palavrasEncontradas: quantidade de palavras encontradas
*/
int varredura(char lista[][tamMaxPalavras], char matriz[][colunas], int L, int C, int Q)
{
    // Variáveis correspondentes a todas as Verificações possíveis
    int achouHorizontal, achouHorizontalInversa, achouVertical, achouVerticalInversa, achouDiagonalPrincipal, achouDiagonalPrincipalInversa, achouDiagonalSecundaria, achouDiagonalSecundariaInversa;
    int palavrasEncontradas = 0; // Variável de contagem para verificar quantas palavras existem na matriz
    int i; // Controlador de laço

    // função varredura, pois precisa passar parâmetros diferentes de tamanhos
    for (i = 0; i < Q; i++)
    {
        // Verificação em todos sentidos possíveis da matriz
        achouHorizontal = verHorizontal(lista, matriz, i, L, C);
        achouHorizontalInversa = verHorizontalInversa(lista, matriz, i, L, C);
        achouVertical = verVertical(lista, matriz, i, L, C);
        achouVerticalInversa = verVerticalInversa(lista, matriz, i, L, C);
        achouDiagonalPrincipal = verDiagonalPrincipal(lista, matriz, i, L, C);
        achouDiagonalPrincipalInversa = verDiagonalPrincipalInversa(lista, matriz, i, L, C);
        achouDiagonalSecundaria = verDiagonalSecundaria(lista, matriz, i, L, C);
        achouDiagonalSecundariaInversa = verDiagonalSecundariaInversa(lista, matriz, i, L, C);

        // condição para verificar e imprimir uma mensagem que indica se a determinada palavra foi encontrada ou não
        if (achouHorizontal || achouHorizontalInversa || achouVertical || achouVerticalInversa || achouDiagonalPrincipal || achouDiagonalPrincipalInversa || achouDiagonalSecundaria || achouDiagonalSecundariaInversa)
        {
            printf("A palavra %s foi encontrada.\n", lista[i]);
            palavrasEncontradas++;
        }
        else
            printf("A palavra %s nao foi encontrada.\n", lista[i]);
    }

    return palavrasEncontradas; // Valor de retorno
}

/*
Nome: resultado
Objetivo: imprimir uma mensagem para determinar se as palavras foram encontradas e se sim, qual a quantidade
parâmetros formais:
    - palavrasEncontradas (parâmetro de entrada, representando todas as palavras que posteriormente será comparada ao Q (quantidade total))
    - Q (parâmetro de entrada, representando a quantidade total de palavras)
Valor de retorno:
    - não há, pois é um procedimento
*/
void resultado(int palavrasEncontradas, int Q)
{
    //Apresentação do resultado
    if (palavrasEncontradas == Q)
        printf("\nTodas as palavras foram encontradas!\n");
    else if (palavrasEncontradas == 0)
        printf("\nNenhuma das palavras foi encontrada.\n");
    else
        printf("\nApenas %d palavras foram encontradas.\n", palavrasEncontradas);
}
