#include <stdio.h>
#include <stdlib.h>

struct cel{
  int conteudo;
  struct cel *proximo;
};

typedef struct cel cel;

int main(){
  cel *p = NULL, *aux = NULL;
  cel *nova;

  int i = 0;
  int num = 1;

//Digitar numeros e organizar lista
  aux = p;
  while(1){
    i = i + 1;
    nova = (cel *)malloc(sizeof(cel));
    printf("Digite um número para a posição %d [00 para parar]: ", i);
    scanf("%d", &num);
    if (num==0){
      break;
    }
    nova->conteudo = num;
    if (p == NULL || num < p->conteudo) {
        nova->proximo = p;
        p = nova;
    } else {
        aux = p;
        while (aux->proximo != NULL && num > aux->proximo->conteudo) {
            aux = aux->proximo;
        }
        nova->proximo = aux->proximo;
        aux->proximo = nova;
    }
  }
  
//Imprimir lista
  if (p==NULL){
    printf("A lista está vazia");
  }else{
    printf("Conteúdo da lista ");
    aux = p;
    while (aux!= NULL){
      printf("%d ", aux->conteudo);
      aux = aux->proximo;
    }
  }

  printf("\n");


//Achar numero
  int x;
  printf("Digite um valor que quer descobrir: ");
  scanf("%d",&x);

  aux = p;
  while(aux!=NULL && aux->conteudo != x){
    aux = aux->proximo;
  }
  if (aux == NULL){
    printf("Elemento não encontrado");
  }else{
    printf("Elementro encontrado");
  }
  printf("\n");

//Apagar determinado número
  int delet;
  
  printf("Digite um valor que quer apagar: ");
  scanf("%d",&delet);

  aux = p;
  cel *anterior = NULL;
  while(aux!=NULL && aux->conteudo != delet){
    anterior = aux;
    aux = aux->proximo;
  }
  if (aux == NULL){
    printf("Elemento que quer apagar não encontrado");
  }else{
    if (anterior == NULL){
      p = aux->proximo;
    }else{
      anterior->proximo = aux->proximo;
    }

    free(aux);
    printf("Elemento apagado!");
  }
  printf("\n");

//Imprimir lista depois de ter apagado algum elemento
  if (p==NULL){
    printf("A lista está vazia");
  }else{
    printf("Conteúdo da lista: ");
    aux = p;
    while (aux!= NULL){
      printf("%d ", aux->conteudo);
      aux = aux->proximo;
    }
  }

  printf("\n");

//Liberar memória 
  while (p != NULL) {
      aux = p;
      p = p->proximo;
      free(aux);
  }
}
