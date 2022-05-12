#include <iostream>
#include <time.h>
#include <locale.h>
using namespace std;

#define TAM 4

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int matPrincipal [TAM][TAM] = {1, 4, 5, 2, 7, 2, 8, 7, 3, 6, 1, 4, 6, 5, 3, 8}; //Matriz Principal
    int matGabarito [TAM][TAM]; //Matriz Gabarito
    int matJogo [TAM][TAM]; //Matriz Jogo

    int selectMenu, jogadas, paresEncontrados; //Controles do programa e pontuação no jogo
    int peca1L, peca2L, peca1C, peca2C; //Vari�veis para Linha e Coluna das pe�as selecionadas pelo jogador
    bool posicaoVazia; //condi��o dos loops da linha 134 e 167. Repetir caso posicão informada j� esteja sendo utilizada.

    do //Do-While Loop do Programa. Sair caso selecao do menu seja 3-Fim.
    {
        system("cls");
        cout << "---------- Menu ----------\n" << "Digite o n�mero da op��o desejada\n"; //Menu
        cout << "1-Jogar / 2-Fim\n";
        cin >> selectMenu;

        //If-ElseIf para sele��o do menu, 1-Jogar
        if(selectMenu == 1) /*************************** JOGAR ***************************/
        {
            system("cls");
            srand(time(NULL));

            //Opera��es selecionadas aleatoriamente para a matriz principal gerar a matriz gabarito
            switch(rand() % TAM + 1) //Condi��o ao n�mero aleat�rio de 1-4
            {
                case 1: //Sem Modifica��o
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[i][j];
                        }
                    }
                    break;
                case 2: //Transposta
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[j][i];
                        }
                    }
                    break;
                case 3: //Invertida por Linha
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[(TAM - 1) - i][j];
                        }
                    }
                    break;
                case 4: //Invertida por Coluna
                    for(int i = 0; i < TAM; i++)
                    {
                        for(int j = 0; j < TAM; j++)
                        {
                            matGabarito[i][j] = matPrincipal[i][(TAM - 1) - j];
                        }
                    }
                    break;
                default: //Debug do rand()
                    cout << "Gerou um n�mero aleat�rio fora do par�metro!" << endl;
                    system("Pause");
                    break;
            }

            //Zerando Matriz Jogo
            for (int i = 0; i < TAM; i++)
                {
                    for(int j = 0; j < TAM; j++)
                    {
                        matJogo [i][j] = 0;
                    }
                }

            jogadas = 24;
            paresEncontrados = 0;

            //INTERA��O DO JOGO
            do
            {
                //Mostrar intera��o do jogo (tabuleiro e pontua��o)
                cout << "Pares Encontrados: " << paresEncontrados << " / 8\t" << "Jogadas: " << jogadas << " / 24\n" << endl;
                for (int i = 0; i < TAM; i++)
                {
                    for(int j = 0; j < TAM; j++)
                    {
                        cout << matJogo[i][j] << "\t";
                    }
                    cout << endl;
                }

                //VALOR PARA PEÇA 1
                do
                {
                    cout << "\nPe�a 1 - Informe a linha e coluna desejadas: " << endl;
                    cin >> peca1L >> peca1C;
                    //Ao inves de o jogador informar posicao entre 0-3 optamos por 1-4
                    peca1L -= 1;
                    peca1C -= 1;

                    if(matJogo[peca1L][peca1C] == 0) //If-Else para preencher posicao em matJogo caso posicao nao esteja sendo utilizada
                    {
                        matJogo[peca1L][peca1C] = matGabarito[peca1L][peca1C];
                        posicaoVazia = true;
                    }
                    else
                    {
                        cout << "\nPosi��o informada inv�lida. Tente novamente...\n" << endl;
                        posicaoVazia = false;
                    }
                } while (posicaoVazia != true); //Do-while para repetir caso a posicao informada já esteja sendo utilizada

                system("cls");
                //Atualizar tabuleiro para jogador ver pe�a 1 selecionada
                cout << "Pares Encontrados: " << paresEncontrados << " / 8\t" << "Jogadas: " << jogadas << " / 24\n" << endl;
                for (int i = 0; i < TAM; i++)
                {
                    for(int j = 0; j < TAM; j++)
                    {
                        cout << matJogo[i][j] << "\t";
                    }
                    cout << endl;
                }

                //VALOR PARA PE�A 2
                do
                {
                    cout << "\nPe�a 2 - Informe a linha e coluna desejadas: " << endl;
                    cin >> peca2L >> peca2C;
                    //Ao inves de o jogador informar posicao entre 0-3 optamos por 1-4
                    peca2L -= 1;
                    peca2C -= 1;

                    if(matJogo[peca2L][peca2C] == 0) //If-Else para preencher posicao em matJogo caso posicao nao esteja sendo utilizada
                    {
                        matJogo[peca2L][peca2C] = matGabarito[peca2L][peca2C];
                        posicaoVazia = true;
                    }
                    else
                    {
                        cout << "\nPosi��o informada inv�lida. Tente novamente...\n" << endl;
                        posicaoVazia = false;
                    }
                } while (posicaoVazia != true); //Do-while para repetir caso a posicao informada j� esteja sendo utilizada

                system("cls");
                //Atualizar tabuleiro para jogador ver pe�a 2 selecionada
                cout << "Pares Encontrados: " << paresEncontrados << " / 8\t" << "Jogadas: " << jogadas << " / 24\n" << endl;
                for (int i = 0; i < TAM; i++)
                {
                    for(int j = 0; j < TAM; j++)
                    {
                        cout << matJogo[i][j] << "\t";
                    }
                    cout << endl;
                }

                //If-Else para verificar se as peças selecionadas formam um par
                if (matJogo[peca1L][peca1C] == matJogo[peca2L][peca2C])
                {
                    cout << "\nJOGADA OK\n" << endl;
                    jogadas--;
                    paresEncontrados++;
                }
                else
                {
                    cout << "\nJOGADA NOK\n" << endl;
                    matJogo[peca1L][peca1C] = 0; //zerar posicoes caso pecas n�o formem um par
                    matJogo[peca2L][peca2C] = 0;
                    jogadas--;
                }

                system("pause");
                system("cls");
            } while (paresEncontrados < 8 && jogadas > 0); //Do-While para loop do jogo. Sai do loop quando todos os pares forem encontrados ou quando acabarem as jogadas.

            //If-Else mostrando resultado do Jogo
            if (paresEncontrados == 8)
                cout << "VIT�RIA!\n" << endl;
            else
                cout << "DERROTA!\n" << endl;

            system("pause");
        }
    }
        while(selectMenu != 2); /*************************** FIM ***************************/

    return 0;
}