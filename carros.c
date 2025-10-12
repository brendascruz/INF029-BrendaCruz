#include <stdio.h>
#include <string.h>
#define TAM 100

typedef struct {
    char modelo[TAM];
    int ano;
    int chassi;
    int potencia;
}Carro;

int adicionar_carros(Carro carros[], int numero){
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
        return 1;
    }
    else{
        printf("Limite de carros atingidos.\n\n");
        return 2;
    }
}

void mostrar_carros(Carro carros[], int numero){
    if(numero == 0){
        printf("Nenhum carro foi adicionado\n\n");
    }
    else{
        printf("Lista de carros: \n");
        for(int i = 0; i < numero; i++){
            printf("Carro %d = Modelo: %s, Ano: %d, Chassi: %d, Potencia: %d\n", i + 1, carros[i].modelo, carros[i].ano, carros[i].chassi, carros[i].potencia);
        }
        printf("Há um total de %d carros adicionados.\n", numero);
        printf("\n");
    }
}

void mostrar_potencia(Carro carros[], int numero){
    int maior = 0, menor = 500;
    int chassi_menor = 0, chassi_maior = 0;
    for(int i = 0; i < numero; i++){
        if(carros[i].potencia > maior){
            chassi_maior = carros[i].chassi;
            maior = carros[i].potencia;
        }
        if(carros[i].potencia < menor){
            chassi_menor = carros[i].chassi;
            menor = carros[i].potencia;
        }
    }
    for(int i = 0; i < numero; i++){
        if(chassi_menor == carros[i].chassi){
            printf("\nCarro de menor potencia (%d) = Modelo: %s, Ano: %d, Chassi: %d\n", menor ,carros[i].modelo, carros[i].ano,  carros[i].chassi);
            break;
        }
    }
    for(int i = 0; i < numero; i++){
        if(chassi_maior == carros[i].chassi){
            printf("\nCarro de maior potencia (%d) = Modelo: %s, Ano: %d, Chassi: %d\n", maior ,carros[i].modelo, carros[i].ano,  carros[i].chassi);
            break;
        }
    }
    printf("\n");
}

int excluir_carros(Carro carros[], int numero){
    int posicao;
    int confirmacao = 1;
    if (numero == 0) {
        printf("Nenhum carro cadastrado para excluir.\n\n");
        return 2;
    }
    else if(numero == 1){
        printf("Tem certeza que deseja excluir o carro? (1 - Sim / 0 - Nao): ");
        scanf("%d", &confirmacao);
        if(confirmacao == 1){
            numero--;
            printf("O unico carro registrado foi excluido.\n\n");
            return 1;
        }
        else if(confirmacao == 0){
            printf("Carro mantido.\n\n");
            return 0;
        }
    }
    else{
        printf("Digite a posicao do carro a ser excluido (De 1 a %d.): ", numero);
        scanf("%d", &posicao);
        if (posicao < 1 || posicao > numero) {
                printf("Posição inválida!\n");
                return 0;
        }
        printf("Tem certeza que deseja excluir o carro '%s'? (1 - Sim / 0 - Nao): ", carros[posicao - 1].modelo);
        scanf("%d", &confirmacao);
        if(confirmacao == 1){
            posicao--;
            for(int i = posicao; i < numero - 1; i++){
            strcpy(carros[i].modelo, carros[i+1].modelo);
            carros[i].ano = carros[i+1].ano;
            carros[i].chassi = carros[i+1].chassi;
            carros[i].potencia = carros[i+1].potencia;
            }
            numero = numero - 1;
            printf("Carro removido.\n\n");
            return 1;
        }
        else if(confirmacao == 0){
            printf("Carro mantido.\n\n");
            return 0;
        }
    }   
    return 0;
}

void atualizar_carros(Carro carros[], int numero){
    int chassi = 0;
    int achou = -1;
    int opcao = 1;
    printf("Digite o chassi do carro a ser atualizado: ");
    scanf("%d", &chassi);
    for(int i = 0; i < numero; i++){
        if(chassi == carros[i].chassi){
            achou = i;
            break;
        }
    }
    if(achou != -1){
        do{
            printf("Menu de atualizacao.\n");
            printf("1 - Mudar o modelo do carro\n");
            printf("2 - Mudar o ano do carro\n");
            printf("3 - Mudar a potencia do carro\n");
            printf("0 - Sair do menu\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch(opcao){
                case 1: 
                    printf("Digite o novo modelo do carro: ");
                    fgets(carros[achou].modelo, TAM, stdin);
                    for (int j = 0; carros[achou].modelo[j] != '\0'; j++) {
                        if (carros[achou].modelo[j] == '\n') {
                        carros[achou].modelo[j] = '\0'; 
                        break;
                        }
                    }
                    break;
                case 2:
                    printf("Digite o novo ano do carro: ");
                    scanf("%d", &carros[achou].ano);
                    break;
                case 3:
                    printf("Digite a nova potencia do carro: ");
                    scanf("%d", &carros[achou].potencia);
                    break;
                case 0:
                    printf("Saindo...\n\n");
                    break;
                default:
                    printf("Digite uma das opcoes do menu.\n");
                    break;
            }
        }while(opcao != 0);
    }
    else{
        printf("Carro nao encontrado.\n");
    }
}

void menu_principal(){
    printf("Sistema de registro de carros\n");
    printf("1 - Registrar carro\n");
    printf("2 - Mostrar carros\n");
    printf("3 - Excluir carro\n");
    printf("4 - Atualizar carro\n");
    printf("5 - Buscar carro registrado\n");
    printf("6 - Mostrar carro mais potente e menos potente\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
}

void busca_chassi(Carro carros[], int numero){
    int chassi = 0;
    int achou = -1;
    printf("Digite o chassi do carro a ser buscado: ");
    scanf("%d", &chassi);
    for(int i = 0; i < numero; i++){
        if(chassi == carros[i].chassi){
            printf("\nCarro de chassi %d = Modelo: %s, Ano: %d, Potencia: %d\n", carros[i].chassi, carros[i].modelo, carros[i].ano,  carros[i].potencia);
            achou = 1;
            break;
        }
    }
    if(achou != 1){
        printf("Carro nao encontrado.\n");
    }
}

void busca_ano(Carro carros[], int numero){
    int ano = 0;
    printf("Digite o ano a ser buscado: ");
    scanf("%d", &ano);
    printf("Carros de ano %d: \n", ano);
    for(int i = 0; i < numero; i++){
        if(ano == carros[i].ano){
            printf("Modelo: %s, Chassi: %d, Potencia: %d\n", carros[i].modelo, carros[i].chassi,  carros[i].potencia);
        }
    }
}

void busca_potencia(Carro carros[], int numero){
    int potencia = 0;
    printf("Digite a potencia a ser buscada: ");
    scanf("%d", &potencia);
    printf("Carros de potencia %d: \n", potencia);
    for(int i = 0; i < numero; i++){
        if(potencia == carros[i].potencia){
            printf("Modelo: %s, Chassi: %d, Ano: %d\n", carros[i].modelo, carros[i].chassi,  carros[i].ano);
        }
    }
}

void busca_modelo(Carro carros[], int numero){
    char modelo[50];
    int achou = -1;
    int qtd = 0;
    getchar();
    printf("Digite o modelo a ser procurado: ");
    fgets(modelo, 50, stdin);
    modelo[strcspn(modelo, "\n")] = '\0';
    printf("Carros de modelo %s: \n", modelo);
    for(int i = 0; i < numero; i++){
        if(strcmp(modelo, carros[i].modelo) == 0){
            printf("Chassi: %d, Ano: %d, Potencia: %d\n", carros[i].chassi,  carros[i].ano, carros[i].potencia);
            achou = 1;
            qtd ++;
        }
    }
    if(achou != 1){
        printf("Carro nao encontrado.\n");
    }
    else{
        printf("Foram encontrados %d carros desse modelo.\n", qtd);
    }
}

void buscar(Carro carros[], int numero){
    int opcao = 1;
    
    do{
        printf("\nMenu de busca\n");
        printf("1 - Buscar por chassi\n");
        printf("2 - Buscar por modelo\n");
        printf("3 - Buscar por ano\n");
        printf("4 - Buscar por potencia\n");
        printf("0 - Sair do menu de busca\n");
        printf("Digite a opcao de busca: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                busca_chassi(carros, numero);
                break;
            case 2: 
                busca_modelo(carros, numero);
                break;
            case 3: 
                busca_ano(carros, numero);
                break;
            case 4:
                busca_potencia(carros, numero);
                break;
            case 0: 
                printf("Fim da busca.\n\n");
                break;
            default: 
                printf("Opcao invalida.\n");
                break;

        }
    }while (opcao != 0);
}



int main() {
    
    Carro carros[TAM];
    int escolha;
    int numero = 0;

    do{
        menu_principal();
        scanf("%d", &escolha);
        getchar();
        printf("\n");

        switch (escolha){
            case 1:
                if(adicionar_carros(carros, numero) == 1){
                    numero++;
                }
                break;
            case 2: 
                mostrar_carros(carros, numero);
                break;
            case 3: 
                if(excluir_carros(carros, numero) == 1){
                    numero--;
                }
                break;
            case 4:
                atualizar_carros(carros, numero);
                break;
            case 5:
                buscar(carros, numero);
                break;
            case 6:
                mostrar_potencia(carros, numero);
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