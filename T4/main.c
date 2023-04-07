/*
Nome: Mulheres_na_ciencia
Objetivo: Mostrar as dificuldades em ser mulher na sociedade brasileira por meio de um jogo de tabuleiro
Data: 09/07/2019
Autores: 
Guilherme Santos de Godoy RA: 757710
Igor Teixeira Machado RA: 769708
Lara Santiago Rodrigues RA: 769701
Paula Martins Larocca RA: 769705
 */

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constantes
#define TAM_MAX_MSG 128
#define TAM_DADO 6

// Tipos de dados
typedef struct
{
    int posicaoJogador1;
}tJogador;

typedef struct
{
    int cartaAtual;
}tCartas;

// Protótipos de sub-rotinas
void AbrirOuFazerArquivo(int);
int Dado();
void GerarHTML(int, char mensagem[TAM_MAX_MSG]);

int main()
{
    tJogador Jogador; 
    tCartas Cartas;
    char mensagem[TAM_MAX_MSG] = {'\n'}; // Variavel para mostrar mensagens de aviso
    Jogador.posicaoJogador1 = 0; // A posicao do jogador inicia-se zerada, ou seja, no tabuleiro esta sendo representado por uma "casa" antes da 1
    Cartas.cartaAtual = 0; // A carta

    AbrirOuFazerArquivo(Jogador.posicaoJogador1); // Chamada do procedimento para abrir ou criar arquivo
    GerarHTML(Jogador.posicaoJogador1, mensagem); // Chamada do procedimento para gerar html

    return 0;
}

/*
Nome: AbrirOuFazerArquivo
Objetivo: Abrir ou criar um arquivo, caso nao exita um arquivo
Parametros Formais:
- posicaoJogador1 (parametro de entrada de dados)
Valor de retorno:
- Inexistente (procedimento)
*/
void AbrirOuFazerArquivo(int posicaoJogador1)
{
    FILE *ArquivoBin;
    ArquivoBin = fopen("tabuleiro.bin", "r+b"); // Abrir um arquivo Binario

    if (ArquivoBin == NULL)
    {
        ArquivoBin = fopen("tabuleiro.bin","w+b"); // Criar o arquivo caso ele nao exista

        fseek(ArquivoBin, 0 , SEEK_SET); // Aponta para a posicao que sera gravada a posicao do jogador
        fwrite(&posicaoJogador1, 1, sizeof(int), ArquivoBin); // Escreve a posicao do jogador no arquivo

        fflush(ArquivoBin);
    }
    fseek(ArquivoBin, 0 , SEEK_SET); // Aponta para a posicao que sera gravada a posicao do jogador
    fread(&posicaoJogador1, 1, sizeof(int), ArquivoBin); // Leitura da posicao do jogador no arquivo

    fflush(ArquivoBin); 
    fclose(ArquivoBin); // Fechar arquivo binario
}

/*
Nome: Dado
Objetivo: Sortear um valor do dado do tabuleiro
Parametros Formais:
- Nao existe
Valor de retorno:
- ValorDado
*/
int Dado()
{
    int ValorDado;
    srand (time(NULL)); // Busca de nova semente
    ValorDado = 1 + (rand() % TAM_DADO); // Sorteio de valor aleatorio no dado
    return ValorDado; // Retorna valor gerado aleatoriamente
}

/*
Nome: GerarHTML
Objetivo: Gerar a pagina HTML para mostrar os resultados para o usuario
Parametros Formais:
- posicaoJogador1 (parametro de entrada de dados)
- mensagem (parametro de entrada de dados)
Valor de retorno:
- Inexistente (procedimento)
*/
void GerarHTML(int posicaoJogador1, char mensagem[TAM_MAX_MSG])
{
    int valorDado = 0;
    FILE *ArquivoBin; // Declaracao do ponteiro ArquivoBin do tipo FILE

    ArquivoBin = fopen("tabuleiro.bin", "r+b"); // Abre o arquivo para salvar a posicao do jogador

    // Lendo a posicao do jogador 1
    fseek(ArquivoBin, 0 , SEEK_SET); // Aponta para a posicao que sera gravada a posicao do jogador
    fread(&posicaoJogador1, 1, sizeof(int), ArquivoBin); // Leitura da posicao do jogador no arquivo

    printf("%s%c%c\n","Content-Type:text/html;charset=UTF-8",13,10); // Cabecalho necessario para gerar a pagina html do cgi
    printf("<html lang=\"pt-br\">"); //Início da pagina html
    printf("<head>");
    printf("<title> Mulheres na Ciência </title>");

    printf("<link href=\"../cssTabuleiro.css\" rel=\"stylesheet\" type=\"text/css\" />"); // Abrir o css
    printf("<link href=\"../estilopop.css\" rel=\"stylesheet\" type=\"text/css\" />"); // Abrir o css
    printf("<script src=\"../scripts.js\"></script>"); // Abrir o javascript

    printf("</head>");
    printf("<body>");

    printf("<div class=\"container\">"); //Chamada da classe container, contendo a imagem do tabuleiro

    printf("<div class=\"cedula\" id=\"c%d-J%d\">", posicaoJogador1, 1); // Impressao da posicao do jogador no tabuleiro
    printf("</div>");

    if(posicaoJogador1 == 2) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Você ganhou um jogo de laboratório e se divertiu muito realizando as experiências. Isso aguçou sua curiosidade científica. Avance 3 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 + 3;

    }
    else if(posicaoJogador1 == 4) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Seus brinquedos te incentivam apenas a ser dona de casa e mãe, não estimulando sua lógica, que pena! Volte para o início.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 4;

    }
    else if(posicaoJogador1 == 5) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\">Nos Estados Unidos, Maria Mitchell fez seu nome ao descobrir um cometa em 1847, mas também contribuiu com cálculos para o Almanaque Náutico produzido pelo Observatório Naval dos Estados Unidos. Ela se tornou a primeira mulher membro da Academia Americana de Artes e Ciências em 1848 e da Associação Americana para o Avanço da Ciência em 1850. Diante disso, ande 3 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 + 3;

    }
    else if(posicaoJogador1 == 6) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Você ouviu que mulheres que gostam de matemática são muito masculinas e isso te desestimulou. Volte 3 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 3;

    }
    else if(posicaoJogador1 == 7) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\">Em 1881, Caroline Kennard, uma feminista de Brookline, Massachusetts, enviou uma carta a Charles Darwin. Apaixonada por ciência, ela tinha uma pergunta simples: é cientificamente comprovado que as mulheres são inferiores aos homens? “Eu certamente penso que, embora as mulheres sejam moralmente superiores aos homens, elas são inferiores intelectualmente”, respondeu Darwin. “E, com base nas leis de herança, parece-me haver uma grande dificuldade de elas se tornarem intelectualmente iguais aos homens.” Ideias como essa impediram as mulheres de buscar a formação necessária para uma carreira na área e por isso, você será impedido de ir adiante. Volte 4 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 4;

    }
    else if(posicaoJogador1 == 10) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Você se divertiu muito na Feira de Ciências da escola e está entusiasmada em aprender ainda mais. Ande 2 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 + 2;
    }
    else if(posicaoJogador1 == 11) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\">Ada Lovelace, filha do poeta Lord Byron, lançou as bases do que agora conhecemos como programação informática, mas seu nome sempre se submeteu ao de Charles Babbage, que ficou famoso como o precursor do computador – um conceito que, na verdade, Ada desenvolveu. A história ocultou um modelo feminino e portanto, volte 2 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 2;
    }
    else if(posicaoJogador1 == 13) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Seus pais não te incentivam muito a estudar, afinal, para eles você será bem sucedida se tiver um bom casamento e filhos. Volte 1 casa.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 1;
    }
    else if(posicaoJogador1 == 14) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Em 2014, Maryam Mirzakhani foi primeira mulher a ganhar a medalha Fields, maior honraria da matemática. Ela é considerada até hoje uma artista dos números. Diante disso, ande 1 casa. ");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 + 1;
    }
    else if(posicaoJogador1 == 16) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br> Você assistiu ao filme estrelas além do tempo e aquela ideia de trabalhar na Nasa não parece mais tão absurda. Ande 1 casa.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 + 1;
    }
    else if(posicaoJogador1 == 19) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\">Rosalind Franklin, artífice da imagem que mostra a estrutura helicoidal do DNA, teve seus dados “roubados”. Estes serviram para que Watson e Crick recebessem o Nobel de 1962 por sua contribuição para o entendimento da estrutura do DNA como uma hélice dupla. Nem sequer a mencionaram e por isso, volte 2 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 2;
    }
    else if(posicaoJogador1 == 20) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Nos grupos da faculdade, os meninos sempre são mais ouvidos, mesmo que eles digam o mesmo que você está dizendo. Isso faz com que você sinta que o lugar não é para você. Volte 3 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 3;
    }
    else if(posicaoJogador1 == 22) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Você se casou e seu marido não te deixa estudar. Dê um pé na bunda do marido e avance 3 casas. ");
        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 + 3;
    }
    else if(posicaoJogador1 == 23) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\">Em 1903, Marie Curie se torna a primeira mulher a ganhar o Prêmio Nobel (física), passou a ser laureada uma segunda vez em 1911 (química), ambos pelo seu trabalho sobre a radioatividade. Ela foi a primeira pessoa a ganhar dois prêmios Nobel, um feito realizado por apenas três outros indivíduos desde então. Diante dessa vitória, ande 2 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 + 2;
    }
    else if(posicaoJogador1 == 24) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Você entrou na faculdade de engenharia, mas é a única menina em 30 alunos. Esse vai ser um grande desafio. Volte 3 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 3;
    }
    else if(posicaoJogador1 == 26) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Você teve filhos e precisa cuidar deles sem nenhum suporte. Agora não pode dedicar tanto tempo para sua pesquisa. Volte 1 casa.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 1;
    }
    else if(posicaoJogador1 == 27) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Lisa Meitner, uma das descobridoras da fissão nuclear, tampouco foi mencionada quando a Academia Sueca premiou seu companheiro Otto Hahn pela façanha. Diante desse fato, volte 2 casas. ");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 2;
    }
    else if(posicaoJogador1 == 28) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Os investimentos na sua pesquisa foram cortados, que pena! Volte 3 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 3;
    }
    else if(posicaoJogador1 == 29) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Você foi assediada pelo seu orientador e a comissão da universidade o protegeu. Volte 4 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 4;
    }
    else if(posicaoJogador1 == 30) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Segundo estudos recentes da Cornell University, dados mostram que a diferença de gênero na área da Ciência da Computação poderá levar no mínimo 100 anos para acabar. Diante desse fato, volte 5 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 5;
    }
    else if(posicaoJogador1 == 32) // Condicao para aparecer a janela de pop-up
    {
        printf("<div class=\"pop-up pop-up3\" id=\"container\">");
        printf("<div class=\"top-border\">");

        printf("<div class=\"close-button\" id=\"close-window1\"></div>");
        printf("<div class=\"close-button2\" id=\"close-window2\"></div>");
        printf("<div class=\"close-button3\" id=\"close-window3\" onclick=\"hideElement('container')\"></div>");
        printf("</div>");
        printf("<p class=\"message\"><br>Você foi convocada para uma entrevista na NASA, oba! Mas, mesmo que você tenha tido uma nota altíssima no teste, preferiram um homem, pois \"ele se enquadrava mais no perfil\". O mundo é horrível, eu sinto muito! Volte 7 casas.");

        printf("</p>");
        printf("</div>");

        posicaoJogador1 = posicaoJogador1 - 7;
    }

    printf("<form action=\"http://cap.dc.ufscar.br/~769708/cgi-bin/mulheresnaciencia.cgi\" method = \"get\">"); // form para abrir novamente o cgi
    printf("<input type =\"hidden\" value = \"%d\" name = \"posicaoJogador1\">", posicaoJogador1); // Mostrar no link o valor 
    printf("<input type=\"submit\" class = \"jogarDado jogarDado-IndianRed2\" value=\"Jogar o dado\">"); // Botao de jogar o dado
    printf("</form>");


    printf("</div>");

    printf("<div id=\"log\">%s</div>", mensagem); // Impressao de uma mensagem de erro caso haja erro
    printf("</div>");

    fseek(ArquivoBin, 4*sizeof(int), SEEK_SET); // Aponta para a posicao que sera gravada a posicao do jogador
    fread(&valorDado, 1, sizeof(int), ArquivoBin); // Leitura do valor do dado no arquivo
    fflush(ArquivoBin);

    printf("<p style=\"text-color: white\"> %d", valorDado);

    posicaoJogador1 = posicaoJogador1 + valorDado; // Logica para que o jogador ande a quantidade de casas que foi gerado pelo dado mais a que ele esta anteriormente

    if(posicaoJogador1 >= 33) // Condicao para verificar se o jogador chegou ao final e venceu
    {
        printf("<meta http-equiv=\"refresh\" content=\"0;url=../vitoria.html\" />"); // Abrir a pagina de vencedor

        posicaoJogador1 = 0; // Move o jogador para a posicao inicial

        fseek(ArquivoBin, 0, SEEK_SET); // Aponta para a posicao que sera gravada a posicao do jogador
        fwrite(&posicaoJogador1, 1, sizeof(int), ArquivoBin); // Escreve no arquivo a posicao que o jogador esta
        fflush(ArquivoBin);
    }
    valorDado = Dado(); // Pegar o valor aleatorio gerado do dado

    printf("</body>");
    printf("</html>");

    fseek(ArquivoBin, 0 , SEEK_SET); // Aponta para a posicao que sera gravada a posicao do jogador
    fwrite(&posicaoJogador1, 1, sizeof(int), ArquivoBin); // Escreve no arquivo a posicao do jogador

    fseek(ArquivoBin, 4*sizeof(int), SEEK_SET); // Aponta para a posicao que sera gravado o valor do dado
    fwrite(&valorDado, 1, sizeof(int), ArquivoBin); // Escreve no arquivo o valor do dado que foi gerado

    fflush(ArquivoBin);

    fclose(ArquivoBin); // Fecha o arquivo binario
}