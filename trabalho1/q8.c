#include <stdio.h>
#define LINHAS 3
#define COLUNAS 3
#define Branco ' '


void inicializaTabuleiro(char tabuleiro[LINHAS][COLUNAS]){
    for(int l = 0; l < LINHAS; l++)
        for(int c = 0; c < COLUNAS; c++)
            tabuleiro[l][c] = Branco;
}

void imprimeTabuleiro(char tabuleiro[LINHAS][COLUNAS]){

    printf("\n     1   2   3\n");

    for(int l = 0; l < LINHAS; l++){

        printf("%c   ", 'A' + l);

        for(int c = 0; c < COLUNAS; c++){
            char v = tabuleiro[l][c];
            if(v == ' ')
                printf("  ");
            else
                printf(" %c", v);

            if(c < 2) printf(" |");
        }

        printf("\n");

        if(l < 2)
            printf("    ---+---+---\n");
    }

    printf("\n");
}

int validaPosicao(char tabuleiro[LINHAS][COLUNAS], char letra, char numero){

    if(letra >= 'a' && letra <= 'z')
        letra = letra - 32;

    if(letra < 'A' || letra > 'C')
        return 0;

    if(numero < '1' || numero > '3')
        return 0;

    int l = letra - 'A';
    int c = numero - '1';

    if(tabuleiro[l][c] != Branco)
        return 2;

    return 1;
}

void jogada(char tabuleiro[LINHAS][COLUNAS], int jogador){
    char letra, num;
    int linha, coluna;
    char simbolo = (jogador == 1 ? 'X' : 'O');

    while(1){
        printf("Jogador %d, sua vez: ", jogador);
        scanf(" %c%c", &letra, &num);

        if(letra >= 'a' && letra <= 'z')
            letra -= 32;

        if(letra < 'A' || letra > 'C'){
            printf("Linha invalida. Use A, B ou C.\n");
            continue;
        }

        if(num < '1' || num > '3'){
            printf("Coluna invalida. Use 1, 2 ou 3.\n");
            continue;
        }

        linha = letra - 'A';
        coluna = num - '1';

        if(tabuleiro[linha][coluna] != ' '){
            printf("Posição já ocupada!\n");
            continue;
        }

        tabuleiro[linha][coluna] = simbolo;
        break;
    }
}

int verificaVitoria(char tabuleiro[LINHAS][COLUNAS], char simbolo){
    for(int i = 0; i < 3; i++){
        if(tabuleiro[i][0] == simbolo && tabuleiro[i][1] == simbolo && tabuleiro[i][2] == simbolo)
            return 1;
        if(tabuleiro[0][i] == simbolo && tabuleiro[1][i] == simbolo && tabuleiro[2][i] == simbolo)
            return 1;
    }

    if(tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo)
        return 1;

    if(tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][0] == simbolo)
        return 1;

    return 0;
}

int verificaEmpate(int turno){
    return turno == 9;
}

int main(){
    char tabuleiro[LINHAS][COLUNAS];
    int turno = 0;

    for(int l = 0; l < 3; l++)
        for(int c = 0; c < 3; c++)
            tabuleiro[l][c] = ' ';

    while(1){
        imprimeTabuleiro(tabuleiro);

        int jogador = (turno % 2 == 0 ? 1 : 2);
        char simbolo = (jogador == 1 ? 'X' : 'O');

        jogada(tabuleiro, jogador);

        if(verificaVitoria(tabuleiro, simbolo)){
            imprimeTabuleiro(tabuleiro);
            printf("Jogador %d venceu!\n", jogador);
            break;
        }

        turno++;

        if(turno == 9){
            imprimeTabuleiro(tabuleiro);
            printf("Deu velha!\n");
            break;
        }
    }

    return 0;
}
