#include <stdio.h>
#define TAM 100

typedef struct {
    int ano;
    int chassi;
}Carro;

int main() {
    
    Carro carros[TAM];
    int escolha;
    int numero = 0;

    do{
        printf("Sistema de registro de carros\n");
        printf("1 - Registrar carro\n");
        printf("2 - Mostrar carros\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha){
            case 1:
                if (numero < TAM) {
                    printf("Digitre o ano do carro: ");
                    scanf("%d", &carros[numero].ano);
                    printf("Digitre o numero do chassi do carro: ");
                    scanf("%d", &carros[numero].chassi);
                    printf("Carro adicionado.\n");
                    numero = numero + 1;
                }
                else{
                    printf("Limite de carros atingidos.");
                }
                break;
            case 2: 
                printf("Lista de carros: \n");
                for(int i = 0; i < numero; i++){
                    printf("Carro %d= Ano: %d, Chassi: %d\n", i, carros[i]. ano, carros[i].chassi);
                }
                break;
            case 0: 
                printf("Fim do programa.");
                break;
            default: 
                printf("Opcao invalida.\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}