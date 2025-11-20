// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Brenda Silva Cruz
//  Email: brendasilvacruz.ba@gmail.com
//  Matrícula: 20251160014
//  Semestre: 2 semestre

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>
#include <string.h>

DataQuebrada quebrar(char data[]);
void tratarString(char *texto);
int ehBissexto(int ano);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

 /*
 typedef struct DQ
{
    int iDia; 
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 
} DataQuebrada;

atoi transforma de string para inteiro

Pegar a data
Verificar até a barra
Contar quantidade de numeros
Se for entre 1 e 2 pegar isso e colocar no iDia
Pular a barra e ir para o proximo
Se for entre 1 e 2 pegar isso e colocar no iMes
Pular a barra e ir para o proximo
Se for entre 2 e 4 pegar isso e colocar no iAno
Transformar isso em inteiro
Verificar se o dia está entre 1 e 31
Verificar se o mes está entre 1 e 12
Verificar se o ano está entre 1500 e 2100
Verificar se a quantidade de dias equivale no mes
Verificar se o ano é bissexto para ver se funciona em fevereiro (28 dias ou 29 dias)
Se tudo certo, valido == 1
Se nao, valido == 0 e break
 */

DataQuebrada quebrar(char data[]){
  DataQuebrada d = {0, 0, 0, 1};
  int i = 0;
  char iDia[3] = {0}, iMes[3] = {0}, iAno[5] = {0};

  if(data[0] == '/'){ // dia vazio
        d.valido = 0;
        return d;
  }

  for(i = 0; data[i] != '/' && i < 2; i++){
    iDia[i] = data[i];
  }

  if(i < 1){
    d.valido = 0;
    return d;
  }
  iDia[i] = '\0';
  int j = i + 1;
  i = 0;

  for(j; data[j] != '/' && i < 2 && data[j] != '\0'; j++){
    iMes[i] = data[j];
    i++;
  }
  if(i < 1){
      d.valido = 0;
      return d;
  }
  iMes[i] = '\0';
  j++;
  int k = j;
  i = 0;
  for(k; data[k] != '\0' && i < 4; k++){
    iAno[i] = data[k];
    i++;
  }
  if(i != 2 && i!= 4){
      d.valido = 0;
      return d;
  }
  iAno[i] = '\0';

  d.iDia = atoi(iDia);
  d.iMes = atoi(iMes);
  d.iAno = atoi(iAno);

  return d;
}


int ehBissexto(int ano) {
  if ((ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0))
    return 1;
  else
    return 0;
} 


int q1(char data[])
{
  DataQuebrada d;
  d = quebrar(data);
  int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  if (!d.valido)
    return 0;


  if(ehBissexto(d.iAno)){
    meses[1] = 29;
  }
  if(d.iMes < 1 || d.iMes > 12) return 0;

  if (d.iDia < 1 || d.iDia > meses[d.iMes - 1]) return 0;

  return 1;
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */


/*
  usar uma string datainicial, uma string datafinal 

  typedef struct Qtd
  {
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;
  } DiasMesesAnos;

  dividir e validar a data inicial
  dividir e validar a data final
*/
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    DataQuebrada inicial = quebrar(datainicial);
    DataQuebrada final = quebrar(datafinal);
    int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
      
      if (inicial.iAno > final.iAno) {
          dma.retorno = 4;
          return dma;
      }
      if (inicial.iAno == final.iAno && inicial.iMes > final.iMes) {
          dma.retorno = 4;
          return dma;
      }
      if (inicial.iAno == final.iAno && inicial.iMes == final.iMes && inicial.iDia > final.iDia) {
          dma.retorno = 4;
          return dma;
      }

      dma.qtdAnos = final.iAno - inicial.iAno;
      dma.qtdMeses = final.iMes - inicial.iMes;
      dma.qtdDias = final.iDia - inicial.iDia;

      if(dma.qtdDias < 0){
        dma.qtdMeses--;
        
        int mes_ant = 0;
        mes_ant = final.iMes - 1;
        int anoA = final.iAno;

        if (mes_ant == 0) {  
            mes_ant = 12;  
            anoA--;           
        }
        if (mes_ant == 2) { 
            if (ehBissexto(anoA)) {
                dma.qtdDias += 29;
            } else {
                dma.qtdDias += 28;
            }
        }
        else{
          dma.qtdDias += meses[mes_ant - 1];
        }

      }

      if (dma.qtdMeses < 0) {
          dma.qtdMeses += 12;
          dma.qtdAnos--;
      }
      //calcule a distancia entre as datas
      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */

 /*
 no teste: 
 char str[250];
  strcpy(str, "Renato Lima Novais");
  printf("%d\n", q3(str, 'a', 0) == 3);
 */

 /*
  caseSensitive = 1 -> diferenciar maiusculo e minusculo
  caseSensitive != 1 -> nao diferenciar maiusculo e minusculo
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

    if(isCaseSensitive == 1){
      for(int i = 0; texto[i] != '\0'; i++){
        if(texto[i] == c){
          qtdOcorrencias++;
        }
      }
    }
    else{
      for(int i = 0; texto[i] != '\0'; i++){
        if(texto[i] == c){
          qtdOcorrencias++;
        }
        else if((c >= 'A' && c <= 'Z') && (texto[i] == c + 32)){
          qtdOcorrencias++;
        }
        else if((texto[i] >= 'A' && texto[i] <= 'Z') && (c == texto[i] + 32)){
          qtdOcorrencias++;
        }
      }
    }
    return qtdOcorrencias;
}



/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
// 


int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int i, j, k, tam;
    tratarString(strTexto);
    tratarString(strBusca);
    tam = strlen(strBusca);
    for (i = 0, k = 0; strTexto[i] != '\0'; i++) {
        for (j = 0; strBusca[j] != '\0'; j++) {
            if (strTexto[i + j] != strBusca[j]) {
                break;
            }
        }

        if (tam == j) {
            posicoes[k++] = i + 1;
            posicoes[k++] = i + tam;
            qtdOcorrencias++;
            i++;
        }
    }
    return qtdOcorrencias;
}






/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int inv = 0;

    while(num > 0){
      int resto = num % 10;
      inv = inv * 10 + resto;
      num = num / 10;
    }
    num = inv;

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int i, j;
    int num_base[20], num_busca[20];

    for (i = 0; numerobase > 0; i++) {
        num_base[i] = (numerobase % 10);
        numerobase = numerobase / 10;
    }
    int tam_base = i;

    for (i = 0; numerobusca > 0; i++){
        num_busca[i] = (numerobusca % 10);
        numerobusca = numerobusca / 10;
    }
    int tam_busca = i;
    for (i = 0; i < tam_base; i++) {
        for (j = 0; j < tam_busca; j++) {
            if (num_base[i + j] != num_busca[j])
                break;
        }
        if (tam_busca == j) {
            qtdOcorrencias++;
            i = i + tam_busca - 1;
        }
    }
    return qtdOcorrencias;
}


/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

int q7(char matriz[8][10], char palavra[5])
{
  int tam = 0;
  tam = strlen(palavra);

  for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 10; j++) {

          if (matriz[i][j] == palavra[0]) {

              int k;

              for (k = 1; k < tam; k++) {
                  int col = j + k;
                  if (col >= 10) 
                    break;
                  if (matriz[i][col] != palavra[k]) 
                    break;
              }
              if (k == tam) 
                return 1;

              for (k = 1; k < tam; k++) {
                  int col = j - k;
                  if (col < 0) 
                    break;
                  if (matriz[i][col] != palavra[k]) 
                    break;
              }
              if (k == tam) 
                return 1;

              for (k = 1; k < tam; k++) {
                  int lin = i + k;
                  if (lin >= 8) 
                    break;
                  if (matriz[lin][j] != palavra[k]) 
                    break;
              }
              if (k == tam) 
                return 1;

              for (k = 1; k < tam; k++) {
                  int lin = i - k;
                  if (lin < 0) 
                    break;
                  if (matriz[lin][j] != palavra[k]) 
                    break;
              }
              if (k == tam) 
                return 1;

              for (k = 1; k < tam; k++) {
                  int lin = i + k;
                  int col = j + k;
                  if (lin >= 8 || col >= 10) 
                    break;
                  if (matriz[lin][col] != palavra[k]) 
                    break;
              }
              if (k == tam) 
                return 1;

              for (k = 1; k < tam; k++) {
                  int lin = i - k;
                  int col = j - k;
                  if (lin < 0 || col < 0) 
                    break;
                  if (matriz[lin][col] != palavra[k]) 
                    break;
              }
              if (k == tam) 
                return 1;

              for (k = 1; k < tam; k++) {
                  int lin = i + k;
                  int col = j - k;
                  if (lin >= 8 || col < 0) 
                    break;
                  if (matriz[lin][col] != palavra[k]) 
                    break;
              }
              if (k == tam) 
                return 1;

              for (k = 1; k < tam; k++) {
                  int lin = i - k;
                  int col = j + k;
                  if (lin < 0 || col >= 10) 
                    break;
                  if (matriz[lin][col] != palavra[k]) 
                    break;
              }
              if (k == tam) 
                return 1;
          }
      }
  }

  return 0;
}


void tratarString(char *texto) {
    int i, j, tam;
    char com_acento[] = "ÄÁÂÀÃäáâàãÉÊËÈéêëèÍÎÏÌíîïìÖÓÔÒÕöóôòõÜÚÛÙüúûù";
    char sem_acento[] = "AAAAAAAAAAaaaaaaaaaaEEEEEEEEeeeeeeeeIIIIIIIIiiiiiiiiOOOOOOOOOOooooooooooUUUUUUUUuuuuuuuu";
    for(tam = 0; texto[tam] != '\0'; tam++);
    for(i = 0; texto[i] != '\0'; i++){
        for(j = 0; com_acento[j] != '\0'; j++) {
            if(texto[i] == com_acento[j] && texto[i+1] == com_acento[j+1]) {
                texto[i] = sem_acento[j];
                for (int k = i + 1; k < tam - 1; k++) {
                    texto[k] = texto[k+1];
                }
                texto[tam - 1] = '\0';
                tam--;
                break;
            }
        }
    }
}



/*
DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
*/
