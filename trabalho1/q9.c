#include <stdio.h>

#define TAM 10
#define NUM_NAVIOS 5

typedef struct {
    int tam;
    int pos[TAM][2];
    int hit[TAM];
} Navio;

typedef struct {
    char mapa[TAM][TAM];
    char mapa_adv[TAM][TAM];
    Navio nav[NUM_NAVIOS];
    int nav_af;
} Jogador;

Jogador jog[2];
int jog_at = 0;

void inicializarMapas() {
    for (int p = 0; p < 2; p++) {
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                jog[p].mapa[i][j] = ' ';
                jog[p].mapa_adv[i][j] = ' ';
            }
        }
        jog[p].nav_af = 0;
    }
}

void exibirMapa(Jogador jx, int pr) {
    printf("\n  ");
    for (char c = 'A'; c < 'A' + TAM; c++) {
        printf(" %c", c);
    }
    printf("\n");
    
    for (int i = 0; i < TAM; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < TAM; j++) {
            char cel;
            if (pr)
                cel = jx.mapa[i][j];
            else
                cel = jx.mapa_adv[i][j];

            printf(" %c", cel);
        }
        printf("\n");
    }
    printf("\n");
}

int posicionarNavio(int jog_id, int nav_id, int tam, int lin, int col, int dir) {
    if (dir == 0) {
        if (col + tam > TAM) return 0;
    } else {
        if (lin + tam > TAM) return 0;
    }
    
    for (int i = 0; i < tam; i++) {
        int l = lin + (dir == 1 ? i : 0);
        int c = col + (dir == 0 ? i : 0);
        
        if (jog[jog_id].mapa[l][c] != ' ') return 0;
    }
    
    for (int i = 0; i < tam; i++) {
        int l = lin + (dir == 1 ? i : 0);
        int c = col + (dir == 0 ? i : 0);
        
        jog[jog_id].mapa[l][c] = 'N';
        
        jog[jog_id].nav[nav_id].pos[i][0] = l;
        jog[jog_id].nav[nav_id].pos[i][1] = c;
        jog[jog_id].nav[nav_id].hit[i] = 0;
    }
    
    jog[jog_id].nav[nav_id].tam = tam;
    
    return 1;
}

void posicionarNavios(int jog_id) {
    printf("Jogador %d, posicione seus navios:\n", jog_id + 1);
    
    printf("Navio tam 4:\n");
    int ok = 0;
    while (!ok) {
        printf("Informe linha (1-10), coluna (A-J) e direção (H/V): ");
        int lin;
        char col_c, dir;
        scanf("%d %c %c", &lin, &col_c, &dir);
        
        int col = col_c - 'A';
        lin--;
        
        ok = posicionarNavio(jog_id, 0, 4, lin, col, (dir == 'V' || dir == 'v'));
        if (!ok) printf("Posição inválida! Tente novamente.\n");
    }
    
    printf("Navio tam 3:\n");
    ok = 0;
    while (!ok) {
        printf("Informe linha (1-10), coluna (A-J) e direção (H/V): ");
        int lin;
        char col_c, dir;
        scanf("%d %c %c", &lin, &col_c, &dir);
        
        int col = col_c - 'A';
        lin--;
        
        ok = posicionarNavio(jog_id, 1, 3, lin, col, (dir == 'V' || dir == 'v'));
        if (!ok) printf("Posição inválida! Tente novamente.\n");
    }
    
    for (int i = 0; i < 3; i++) {
        printf("Navio tam 1 (%d/3):\n", i + 1);
        ok = 0;
        while (!ok) {
            printf("Informe linha (1-10) e coluna (A-J): ");
            int lin;
            char col_c;
            scanf("%d %c", &lin, &col_c);
            
            int col = col_c - 'A';
            lin--;
            
            ok = posicionarNavio(jog_id, 2 + i, 1, lin, col, 0);
            if (!ok) printf("Posição inválida! Tente novamente.\n");
        }
    }
}

int atirar(int at, int df, int lin, int col) {
    if (jog[at].mapa_adv[lin][col] != ' ') return -1;
    
    if (jog[df].mapa[lin][col] == 'N') {
        jog[at].mapa_adv[lin][col] = '0';
        jog[df].mapa[lin][col] = '0';
        
        for (int n = 0; n < NUM_NAVIOS; n++) {
            int af = 1;
            for (int p = 0; p < jog[df].nav[n].tam; p++) {
                int l = jog[df].nav[n].pos[p][0];
                int c = jog[df].nav[n].pos[p][1];
                
                if (l == lin && c == col)
                    jog[df].nav[n].hit[p] = 1;
                
                if (!jog[df].nav[n].hit[p]) af = 0;
            }
            
            if (af) {
                jog[df].nav_af++;
                return 2;
            }
        }
        
        return 1;
    } 
    
    jog[at].mapa_adv[lin][col] = 'X';
    return 0;
}

void jogar() {
    int venc = -1;
    
    while (venc == -1) {
        printf("\n=== Vez do Jogador %d ===\n", jog_at + 1);
        
        printf("Seu mapa:\n");
        exibirMapa(jog[jog_at], 1);
        
        printf("Mapa do adversário:\n");
        exibirMapa(jog[jog_at], 0);
        
        printf("Informe coordenada para atirar (ex: A1): ");
        int lin;
        char col_c;
        scanf("%d %c", &lin, &col_c);
        
        int col = col_c - 'A';
        lin--;
        
        if (lin < 0 || lin >= TAM || col < 0 || col >= TAM) {
            printf("Coordenada inválida!\n");
            continue;
        }
        
        int r = atirar(jog_at, 1 - jog_at, lin, col);
        
        if (r == -1) printf("Você já atirou aqui!\n");
        else if (r == 0) { printf("Água!\n"); jog_at = 1 - jog_at; }
        else if (r == 1) printf("Acertou!\n");
        else printf("Afundou um navio!\n");
        
        if (jog[1 - jog_at].nav_af == NUM_NAVIOS)
            venc = jog_at;
    }
    
    printf("\nJogador %d venceu!\n", venc + 1);
}

int main() {
    printf("=== BATALHA NAVAL ===\n");
    
    inicializarMapas();
    
    for (int i = 0; i < 2; i++) {
        printf("\nJogador %d - Posicionamento:\n", i + 1);
        posicionarNavios(i);
    }
    
    jogar();
    
    return 0;
}
