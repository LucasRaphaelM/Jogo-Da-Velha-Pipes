#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>
#include <windows.h>

void tabuleiro(int velha[3][3]);

int main(void)
{
    int X1 = 10,
        X2 = 10;

    int vez = 0;

    bool vitoria;
    int teste[2];
    char ultimaJogada = '-';
    

    int velha[3][3] = { 0, 0, 0,
                        0, 0, 0,
                        0, 0, 0 };

    while(vez < 9 || !vitoria)
    {
        system("cls");
        tabuleiro(velha);
        printf("--+--\n");
        if(vez % 2 == 0)
            printf("VEZ: X\n");
        else
            printf("VEZ: O\n");

        printf("Escolha a linha: ");
        scanf("%d", &X1);
        printf("Escolha a coluna: ");
        scanf("%d", &X2);

        if(X1 < 1 || X1 > 3)
            X1 = 0;
        if(X2 < 1 || X2 > 3)
            X2 = 0;

        if(X1 != 0 && X2 != 0 && velha[X1-1][X2-1] == 0)
        {
            if(vez % 2 == 0)
            {
                velha[X1-1][X2-1] = 1;
                ultimaJogada = 'X';
            }
            else
            {
                velha[X1-1][X2-1] = 2;
                ultimaJogada = 'O';
            }
            vez++;
        }
        else
        {
            system("cls");
            printf("Valor invalido ou casa ja utilizada!");
            Sleep(1000);
        }


            //      VERTICAIS E HORIZONTAIS     //
        for(int i = 0, j = 0; i < 3; i++)
        {
            if((velha[i][j] == velha[i][j+1] && velha[i][j] == velha[i][j+2] && velha[i][j] != 0) ||
               (velha[j][i] == velha[j+1][i] && velha[j][i] == velha[j+2][i] && velha[j][i] != 0))
            {
                system("cls");
                tabuleiro(velha);
                printf("\nJogador %c venceu", ultimaJogada);
                vitoria = true;
                vez = 9;
            }
        }

            //      DIAGONAIS       //
        if(velha[0][0] == velha[1][1] && velha[0][0] == velha[2][2] && velha[0][0] != 0)
        {
            system("cls");
            tabuleiro(velha);
            printf("\nJogador %c venceu", ultimaJogada);
            vitoria = true;
            vez = 9;
        }
        if(velha[2][0] == velha[1][1] && velha[2][0] == velha[0][2] && velha[2][0] != 0)
        {
            system("cls");
            tabuleiro(velha);
            printf("\nJogador %c venceu", ultimaJogada);
            vitoria = true;
            vez = 9;
        }
        printf("\n");

    }
    if(vez >= 9 && !vitoria)
        printf("DEU VELHA!");
}

void tabuleiro(int velha[3][3])
{
    for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(velha[i][j] == 0)
                    printf("- ");
                if(velha[i][j] == 1)
                    printf("X ");
                if(velha[i][j] == 2)
                    printf("O ");
                if(j == 2)
                    printf("\n");
            }
        }
}