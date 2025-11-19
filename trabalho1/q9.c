#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DIM 10

typedef struct bat{
    char tabProprio[DIM][DIM];
    char tabJogadas[DIM][DIM];
} batalha;

int qtdBcoTam4 = 1;
int qtdBcoTam3 = 1;
int qtdBcoTam1 = 3;

void imprimeTab(char tab[DIM][DIM]);
void addBco(char tab[DIM][DIM]);
int validaPos(char *posStr, char tab[DIM][DIM], int tam);
void convertePos(char *posStr, int *posIni, int *posFim, int tam);
int jogoGanho(char tab[DIM][DIM]);
void atira(char tabAlvo[DIM][DIM], char tabVista[DIM][DIM]);

int main() {
    batalha jgd1;
    batalha jgd2;

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            jgd1.tabProprio[i][j] = ' ';
            jgd1.tabJogadas[i][j] = ' ';
            jgd2.tabProprio[i][j] = ' ';
            jgd2.tabJogadas[i][j] = ' ';
        }
    }

    printf("===== Vez do Jogador 1 =====\n");

    imprimeTab(jgd1.tabProprio);
    addBco(jgd1.tabProprio);

    printf("===== Vez do Jogador 2 =====\n");

    imprimeTab(jgd2.tabProprio);
    addBco(jgd2.tabProprio);

    while (!jogoGanho(jgd1.tabProprio) && !jogoGanho(jgd2.tabProprio)) {

        printf("===== Vez do Jogador 1 =====\n");

        printf("Seu tabuleiro: \n");
        imprimeTab(jgd1.tabProprio);
        printf("Tabuleiro do oponente (vista de Jgd1): \n");
        imprimeTab(jgd1.tabJogadas);

        atira(jgd2.tabProprio, jgd1.tabJogadas);

        if (jogoGanho(jgd2.tabProprio)){
            printf("Jogador 1 VENCEU!\n");
            imprimeTab(jgd1.tabProprio);
            imprimeTab(jgd2.tabProprio);
            break;
        }

        printf("===== Vez do Jogador 2 =====\n");

        printf("Seu tabuleiro: \n");
        imprimeTab(jgd2.tabProprio);
        printf("Tabuleiro do oponente (vista de Jgd2): \n");
        imprimeTab(jgd2.tabJogadas);

        atira(jgd1.tabProprio, jgd2.tabJogadas);

        if (jogoGanho(jgd1.tabProprio)) {
            printf("Jogador 2 VENCEU!\n");
            imprimeTab(jgd1.tabProprio);
            imprimeTab(jgd2.tabProprio);
            break;
        }

    }
    printf("Enter para Finalizar...\n");
    while ((getchar()) != '\n');

    return 0;
}

void imprimeTab(char tab[DIM][DIM]) {
    int i, j, k;

    for (i = 0; i < DIM; i++) {
        if (i == 0) {
            for (k = 0; k < DIM; k++)
                printf("   %d", k + 1);
            printf("\n");
        }

        for (j = 0; j < DIM; j++) {
            if (j == 0)
                printf("%c ", i + 'A');

            printf("| %c ", tab[i][j]);

            if (j == DIM - 1)
                printf("|");
        }
        printf("\n");
    }
}

void addBco(char tab[DIM][DIM]) {
    char posStr[8];
    int posIni[2], posFim[2];
    int i, j, k;

    do {
        printf("Insira a pos. inicial e final do BARCO tam 4: ");
        fgets(posStr, 8, stdin);

        if (!validaPos(posStr, tab, 4))
            printf("Insira uma posicao valida!\n");
        if (validaPos(posStr, tab, 4) == 2)
            printf("Posicao ja ocupada!\n");

    } while (!validaPos(posStr, tab, 4) || validaPos(posStr, tab, 4) == 2);

    convertePos(posStr, posIni, posFim, 4);
    for (i = posIni[0]; i <= posFim[0]; i++) {
        for (j = posIni[1]; j <= posFim[1]; j++) {
            tab[i][j] = 'N';
        }
    }
    imprimeTab(tab);

    do {
        printf("Insira a pos. inicial e final do BARCO tam 3: ");
        fgets(posStr, 8, stdin);

        if (!validaPos(posStr, tab, 3))
            printf("Insira uma posicao valida!\n");
        if (validaPos(posStr, tab, 3) == 2)
            printf("Posicao ja ocupada!\n");
    } while (!validaPos(posStr, tab, 3) || validaPos(posStr, tab, 3) == 2);

    convertePos(posStr, posIni, posFim, 3);
    for (i = posIni[0]; i <= posFim[0]; i++) {
        for (j = posIni[1]; j <= posFim[1]; j++) {
            tab[i][j] = 'N';
        }
    }
    imprimeTab(tab);

    for (k = 0; k < qtdBcoTam1; k++) {
        do {
            printf("Insira a posicao do BARCO tam 1 (restam %d): ", qtdBcoTam1 - k);
            fgets(posStr, 8, stdin);

            if (!validaPos(posStr, tab, 1))
                printf("Insira uma posicao valida!\n");

            if (validaPos(posStr, tab, 1) == 2)
                printf("Posicao ja ocupada!\n");

        } while (!validaPos(posStr, tab, 1) || validaPos(posStr, tab, 1) == 2);

        convertePos(posStr, posIni, posFim, 1);

        for (i = posIni[0]; i <= posFim[0]; i++) {
            for (j = posIni[1]; j <= posFim[1]; j++) {
                tab[i][j] = 'N';
            }
        }
        imprimeTab(tab);
    }
}

int validaPos(char *posStr, char tab[DIM][DIM], int tam) {
    int posIni[2], posFim[2];

    if ((strlen(posStr) < 2 || strlen(posStr) > 4) && tam == 1) return 0;

    convertePos(posStr, posIni, posFim, tam);

    if (posIni[0] < 0 || posIni[0] > 9 || posIni[1] < 0 || posIni[1] > 9) return 0;
    if (posFim[0] < 0 || posFim[0] > 9 || posFim[1] < 0 || posFim[1] > 9) return 0;

    if (posIni[0] != posFim[0] && posIni[1] != posFim[1]) return 0;

    int distL = posFim[0] - posIni[0];
    int distC = posFim[1] - posIni[1];
    if (distL < 0 || distC < 0) return 0;

    if ((distL == 0 && distC != tam - 1) || (distC == 0 && distL != tam - 1)) return 0;

    for (int i = posIni[0]; i <= posFim[0]; i++) {
        for (int j = posIni[1]; j <= posFim[1]; j++) {
            if (tab[i][j] == 'N') return 2;
            if (tab[i][j] == 'X' || tab[i][j] == 'O') return 3;
        }
    }
    return 1;
}

void convertePos(char *posStr, int *posIni, int *posFim, int tam) {
    int i = 0;

    posIni[0] = posStr[i++] - 'A';
    posIni[1] = 0;

    while (posStr[i] != ' ' && posStr[i] != '\0' && posStr[i] != '\n')
        posIni[1] = (posIni[1] * 10) + (posStr[i++] - '0');

    posIni[1] -= 1;

    if (tam > 1) {
        i++;
        
        posFim[0] = posStr[i++] - 'A';
        posFim[1] = 0;
        
        while (posStr[i] != ' ' && posStr[i] != '\0' && posStr[i] != '\n')
            posFim[1] = (posFim[1] * 10) + (posStr[i++] - '0');

        posFim[1] -= 1;

    } else {
        posFim[0] = posIni[0];
        posFim[1] = posIni[1];
    }
}

int jogoGanho(char tab[DIM][DIM]) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            if (tab[i][j] == 'N')
                return 0;
        }
    }
    return 1;
}

void atira(char tabAlvo[DIM][DIM], char tabVista[DIM][DIM]) {
    char posStr[4];
    int posIni[2], posFim[2];

    do {
        printf("Insira a posicao que voce quer atirar (Ex: A1): ");
        fgets(posStr, 4, stdin);
        
        int resValida = validaPos(posStr, tabAlvo, 1);
        
        if (resValida == 0)
            printf("Insira uma posicao valida!\n");

        if (resValida == 3)
            printf("Posicao ja escolhida!\n");

        if (resValida == 2) {
            convertePos(posStr, posIni, posFim, 1);
            
            printf("ACERTOU! Tiro na agua, continue atirando!\n");
            tabAlvo[posIni[0]][posIni[1]] = 'O';
            tabVista[posIni[0]][posIni[1]] = 'O';
            imprimeTab(tabVista);
        }
        
        if (jogoGanho(tabAlvo))
            break;
            
    } while (validaPos(posStr, tabAlvo, 1) != 1); 
    
    if (validaPos(posStr, tabAlvo, 1) == 1) {
        convertePos(posStr, posIni, posFim, 1);
        
        printf("AGUA! Passa a vez.\n");
        tabAlvo[posIni[0]][posIni[1]] = 'X';
        tabVista[posIni[0]][posIni[1]] = 'X';
        imprimeTab(tabVista);
    }
}