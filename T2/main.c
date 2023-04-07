/*
Autor: Guilherme Santos de Godoy - RA: 758710
Objetivo: Determinar se houve colisão no lançamento de um projétil
Data: 05/06/2019
*/

// Declaração de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Declaração de constantes
   Obs: os resultados podem variar de acordo com os valores adotados para as constantes a seguir */

// Valor aproximado da aceleração da gravidade
#define gravidade 9.81
// Valor aproximado de PI
#define PI 3.1415

int main()
{
    // Inicialização e declaração de variáveis
    int colidiu = 0;
    double velocidadeInicial, anguloGraus, anguloRad, distanciaObstaculo, alturaObstaculo, espessuraObstaculo, distanciaTotal, alturaLancamento;

    // Entrada de dados
    printf("Digite o valor da velocidade inicial: ");
    scanf("%lf", &velocidadeInicial);

    printf("Digite o valor do ângulo: ");
    scanf("%lf", &anguloGraus);

    printf("Digite o valor da distância ao obstáculo: ");
    scanf("%lf", &distanciaObstaculo);

    printf("Digite o valor da altura do obstáculo: ");
    scanf("%lf", &alturaObstaculo);

    printf("Digite o valor da espessura do obstáculo: ");
    scanf("%lf", &espessuraObstaculo);

    // Conversão do ângulo em graus para radianos
    anguloRad = anguloGraus * (PI/180);

    /* Cálculo da altura em relação ao deslocamento horizontal
       O cálculo será dividido em duas situações: uma considerando a distância até o obstáculo e outra
       considerando a distância do obstáculo mais sua espessura, já que mesmo que o projétil caia no meio
       do obstáculo, o segundo caso indicaria que houve a colisão
       Obs1: A equação utilizada nos cálculos obtém a altura do lançamento em relação ao deslocamento horizontal (y em relação a x)
       Obs2: A primeira condição calcula a altura no ponto em que se encontra o obstáculo e a segunda condição calcula
             a altura no ponto da distância do obstáculo + espessura, e a partir disso, é feita a comparação com a
             altura do obstáculo nesses pontos calculados */

    // Condição 1
    alturaLancamento = (tan(anguloRad) * distanciaObstaculo) - ((gravidade * (distanciaObstaculo*distanciaObstaculo)) / (2 * (velocidadeInicial*velocidadeInicial) * (cos(anguloRad)*cos(anguloRad))));

    if (alturaLancamento <= alturaObstaculo)
        colidiu = 1;

    // Condição 2
    distanciaTotal = distanciaObstaculo + espessuraObstaculo;
    alturaLancamento = (tan(anguloRad) * distanciaTotal) - ((gravidade * (distanciaTotal*distanciaTotal)) / (2 * (velocidadeInicial*velocidadeInicial) * (cos(anguloRad)*cos(anguloRad))));

    if (alturaLancamento <= alturaObstaculo)
        colidiu = 1;

    // Apresentação do resultado
    if (colidiu)
        printf("\nSim, houve colisao.\n");
    else
        printf("\nNao, nao houve colisao.\n");

    return 0;
}
