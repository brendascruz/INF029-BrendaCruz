#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"



typedef struct{
    int *aux;
    int tam;
    int qtd;
} item;



item vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/


int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
    posicao--;

    

    if(posicao > 9 || posicao < 0){
        return POSICAO_INVALIDA;
    }

    if(tamanho < 1){
        return TAMANHO_INVALIDO;
    }

    if(vetorPrincipal[posicao].aux != NULL){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    vetorPrincipal[posicao].aux = malloc(tamanho * sizeof(int));

    if(vetorPrincipal[posicao].aux == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[posicao].tam = tamanho;
    vetorPrincipal[posicao].qtd = 0;

    return SUCESSO;

    // a posicao pode já existir estrutura auxiliar
    
    // se posição é um valor válido {entre 1 e 10}
    
    // o tamanho ser muito grande
    
    // o tamanho nao pode ser menor que 1
    
    // deu tudo certo, crie
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/


int inserirNumeroEmEstrutura(int posicao, int valor)
{

    posicao--;
    

    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;
    
    
    if(posicao > 9 || posicao < 0){
        posicao_invalida = 1;
    }
    
    
    if (posicao_invalida)
        return POSICAO_INVALIDA;
    else
    {
        int index = vetorPrincipal[posicao].qtd;
        if(vetorPrincipal[posicao].aux != NULL){
            existeEstruturaAuxiliar = 1;
        }
        
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar)
        {
            if(vetorPrincipal[posicao].tam > vetorPrincipal[posicao].qtd){
                    temEspaco = 1;
                }  
            if (temEspaco)
            {   
                //insere
                vetorPrincipal[posicao].aux[index] = valor;
                vetorPrincipal[posicao].qtd++;
                return SUCESSO;
            }
            else
            {
                return SEM_ESPACO;
            }
        }
        else
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    posicao--;
    if(posicao > 9 || posicao < 0){
        return POSICAO_INVALIDA;
    }
    else if(vetorPrincipal[posicao].aux == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    else if(vetorPrincipal[posicao].qtd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    else{
        vetorPrincipal[posicao].qtd--;
        return SUCESSO;
    }
   
    
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    posicao--;
    if(posicao > 9 || posicao < 0){
        return POSICAO_INVALIDA;
    }
    if(vetorPrincipal[posicao].aux == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if(vetorPrincipal[posicao].qtd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }
    int index = -1;
    for(int i = 0; i < vetorPrincipal[posicao].qtd; i++){
        if(vetorPrincipal[posicao].aux[i] == valor){
            index = i;
            break;
        }
    }
    if(index == -1){
        return NUMERO_INEXISTENTE;
    }

    for(int j = index; j < vetorPrincipal[posicao].qtd - 1; j++){
        vetorPrincipal[posicao].aux[j] = vetorPrincipal[posicao].aux[j + 1];
    }

    vetorPrincipal[posicao].qtd--;
    return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;
    if (posicao < 0 || posicao > 9){
        return POSICAO_INVALIDA;
    }
    if(vetorPrincipal[posicao].aux == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    for(int i = 0; i < vetorPrincipal[posicao].qtd ; i++){
        vetorAux[i] = vetorPrincipal[posicao].aux[i];
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    posicao--;
    if (posicao < 0 || posicao > 9){
        return POSICAO_INVALIDA;
    }
    if(vetorPrincipal[posicao].aux == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    for(int i = 0; i < vetorPrincipal[posicao].qtd ; i++){
        vetorAux[i] = vetorPrincipal[posicao].aux[i];
    }
    for (int i = 0; i < vetorPrincipal[posicao].qtd - 1; i++) {
        for (int j = i + 1; j < vetorPrincipal[posicao].qtd; j++) {
            if (vetorAux[i] > vetorAux[j]) {
                int temp = vetorAux[i];
                vetorAux[i] = vetorAux[j];
                vetorAux[j] = temp;
            }
        }
    }
    return SUCESSO;

}


/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int posicao = 0;
    int qtdexiste = 0;
    int qtdvazio = 0;
    for(posicao; posicao < 10; posicao++){
        if (vetorPrincipal[posicao].aux == NULL) {
            continue;
        }
        qtdexiste++;
        if(vetorPrincipal[posicao].qtd == 0){
            qtdvazio++;
        }
    }
    if (qtdexiste == 0) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    if(qtdexiste == qtdvazio){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    

    int k = 0;

    for (posicao = 0; posicao < 10; posicao++) {

        if (vetorPrincipal[posicao].aux == NULL) {
            continue;  
        }

        if (vetorPrincipal[posicao].qtd == 0) {
            continue; 
        }

        for (int j = 0; j < vetorPrincipal[posicao].qtd; j++) {
            vetorAux[k++] = vetorPrincipal[posicao].aux[j];
        }
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int posicao = 0;
    int qtdexiste = 0;
    int qtdvazio = 0;
    for(posicao; posicao < 10; posicao++){
        if (vetorPrincipal[posicao].aux == NULL) {
            continue;
        }
        qtdexiste++;
        if(vetorPrincipal[posicao].qtd == 0){
            qtdvazio++;
        }
    }
    if (qtdexiste == 0) {
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    if(qtdexiste == qtdvazio){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    int k = 0;

    for (posicao = 0; posicao < 10; posicao++) {

        if (vetorPrincipal[posicao].aux == NULL) {
            continue;  
        }

        if (vetorPrincipal[posicao].qtd == 0) {
            continue; 
        }

        for (int j = 0; j < vetorPrincipal[posicao].qtd; j++) {
            vetorAux[k++] = vetorPrincipal[posicao].aux[j];
        }
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (vetorAux[i] > vetorAux[j]) {
                int temp = vetorAux[i];
                vetorAux[i] = vetorAux[j];
                vetorAux[j] = temp;
            }
        }
    }

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    posicao--;
    if(posicao > 9 || posicao < 0){
        return POSICAO_INVALIDA;
    }
    if(vetorPrincipal[posicao].aux == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    int tamFinal = vetorPrincipal[posicao].tam + novoTamanho;
    
    if(tamFinal < 1){
        return NOVO_TAMANHO_INVALIDO;
    }

    int *novo = realloc(vetorPrincipal[posicao].aux, tamFinal * sizeof(int));

    if(novo == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }
    
    vetorPrincipal[posicao].aux = novo;
    vetorPrincipal[posicao].tam = tamFinal;

    if (vetorPrincipal[posicao].qtd > tamFinal) {
        vetorPrincipal[posicao].qtd = tamFinal;
    }

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    posicao--;
    if(posicao > 9 || posicao < 0){
        return POSICAO_INVALIDA;
    }
    if(vetorPrincipal[posicao].aux == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }
    if(vetorPrincipal[posicao].qtd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;    
    }
    return vetorPrincipal[posicao].qtd;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
    for(int i = 0;  i < 10; i++){
        vetorPrincipal[i].aux = NULL;
        vetorPrincipal[i].qtd = 0;
        vetorPrincipal[i].tam = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for(int i = 0; i < 10; i++){
        if(vetorPrincipal[i].aux != NULL){
            free(vetorPrincipal[i].aux);
            vetorPrincipal[i].aux = NULL;
        }
        vetorPrincipal[i].qtd = 0; 
        vetorPrincipal[i].tam = 0;
    }
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

