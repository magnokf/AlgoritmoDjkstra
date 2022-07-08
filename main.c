#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void menu(void);
void addGrafo(void);



int destinos = 0;
double custo;
double *custos = [];
int origem;
int destino;

int main(void) {
  int opt = -1;
  do{
    menu();
    scanf("%d", &opt);
    if(opt == 1){
      addGrafo();
    }
    else if (opt == 2){
      printf("Opção 2\n");
    }
    else if(opt == 3){
      printf("sair\n");
    }
    else {
      printf("Opção Inválida\n");
    }

  }while(opt != 0);
  return 0;

  return 0;
}

void menu(void){
  printf("ALGORITMO DE DIJKSTRA\n");
  printf("Selecione as opções possíveis :\n");
  printf("\t 1 - Add um Grafo\n");
  printf("\t 2 - Busca os caminhos mais curtos no grafo\n");
  printf("\t 3 - Sair\n");
}

void addGrafo(void){

    printf("Favor informar o número de vértices :");
    scanf("%d", &destinos);
  if(destinos < 3){
    custos = (double*) malloc(sizeof(double)*destinos*destinos);
    if(custos == NULL){
      printf("Memória não é suficiente");
      exit (-1);
    }
    for(int i=0; i <= destinos; i++){
      custos[i] = -1;
    }
    }

  do{
    system("clear");
    printf("Informe as arestas :\n");
    do{
      printf("Origem (entre 1 e %d ou '0' para sair)", destinos);
      scanf("%d", &origem);
    } while (origem < 0 || origem > destinos);
    if(origem){
      do{
        printf("Destino (entre 1 e %d, - %d)", destinos, origem);
        scanf("%d", &destino);
        }while(destino < 1 || destino > destinos || destino == origem);

      do{
        printf("O custo (positivo) da origem %d para o destino %d :", origem, destino);
      }while(custo < 0);
      custos[(origem-1)* destinos + destino -1] = custo;
    }
  }while(origem);



}

void principalFunction(int destinos, int origem, int destino, double custos){

  int *x, *y, *z, i;
  double dist[destinos];

  x = (int *) calloc(destinos, sizeof(int *));
  if(x == NULL){
    printf("Oops: Erro de Memória");
    exit(-1);
  }
  y = (int *) calloc(destinos, sizeof(int *));
  if(x == NULL){
    printf("Oops: Erro de Memória");
    exit(-1);
  }
  z = (int *) calloc(destinos, sizeof(int *));
  if(x == NULL){
    printf("Oops: Erro de Memória");
    exit(-1);
  }

  for(int i = 0; i < destinos; i++){
    if(custos[(origem - 1)*(destinos + i)] != -1){
      x[i] = origem -1;
      dist[i] = custos [(origem-1) * destinos + 1];

    }
    else{
      x[i]=-1;
      dist[i]= HUGE_VAL;
    }
    z[i] = 0;
  }
  z[origem-1] =1;
  dist[origem-1]=0;

}
