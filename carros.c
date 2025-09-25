#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct {
    char modelo[TAM];
    int ano;
    int chassi;
    int potencia;
}Carro;

int main() {
    
    Carro carros[TAM];
    int escolha;
    int numero = 0;
    int posicao = 0;

    do{
        printf("Sistema de registro de carros\n");
        printf("1 - Registrar carro\n");
        printf("2 - Mostrar carros\n");
        printf("3 - Excluir carro\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        getchar();
        printf("\n");

        switch (escolha){
            case 1:
                if (numero < TAM) {
                    printf("Digite o modelo do carro: ");
                    fgets(carros[numero].modelo, TAM, stdin);
                    for (int i = 0; carros[numero].modelo[i] != '\0'; i++) {
                        if (carros[numero].modelo[i] == '\n') {
                        carros[numero].modelo[i] = '\0'; 
                        break;
                        }
                    }
                    printf("Digite o ano do carro: ");
                    scanf("%d", &carros[numero].ano);
                    printf("Digite o numero do chassi do carro: ");
                    scanf("%d", &carros[numero].chassi);
                    printf("Digite a potencia do carro (Em cavalos): ");
                    scanf("%d", &carros[numero].potencia);
                    printf("Carro adicionado.\n\n");
                    numero = numero + 1;
                }
                else{
                    printf("Limite de carros atingidos.\n\n");
                }
                break;
            case 2: 
                if(numero == 0){
                    printf("Nenhum carro foi adicionado\n\n");
                }
                else{
                    printf("Lista de carros: \n");
                    for(int i = 0; i < numero; i++){
                        printf("Carro %d = Modelo: %s, Ano: %d, Chassi: %d, Potencia: %d\n", i, carros[i].modelo, carros[i].ano, carros[i].chassi, carros[i].potencia);
                    }
                    printf("\n");
                }
                break;
            case 3: 
                if (numero == 0) {
                    printf("Nenhum carro cadastrado para excluir.\n\n");
                }
                else if(numero == 1){
                    numero--;
                    printf("O unico carro registrado foi excluido.\n\n");
                }
                else{
                    printf("Digite a posicao do carro a ser excluido (De 0 a %d.): ", numero - 1);
                    scanf("%d", &posicao);
                    if (posicao < 0 || posicao >= numero) {
                        printf("Posição inválida!\n");
                    }
                    else{
                        for(int i = posicao; i < numero - 1; i++){
                        strcpy(carros[i].modelo, carros[i+1].modelo);
                        carros[i].ano = carros[i+1].ano;
                        carros[i].chassi = carros[i+1].chassi;
                        carros[i].potencia = carros[i+1].potencia;
                        }
                        numero = numero - 1;
                        printf("Carro removido.\n\n");
                    }
                }   
                break;
            case 0: 
                printf("Fim do programa.\n");
                break;
            default: 
                printf("Opcao invalida.\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}