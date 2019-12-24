#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_NODOS  16

struct nodo {
   int valor;
   struct nodo *sig;
};

struct nodo *crear(int valor);
struct nodo *agregar(struct nodo **primero, int valor);
void insertar(struct nodo **primero, struct nodo *nodo);
void ordenar(struct nodo **primero);
void imprimir(struct nodo *primero);
void liberar(struct nodo **primero);

int main(void)
{
   struct nodo *primero;
   int i;
   
   srand((unsigned) time(NULL));
   
   primero = NULL;
   for (i = 0; i < NUM_NODOS; i++)
      if (agregar(&primero, rand() % (NUM_NODOS / 2)) == NULL)
         return EXIT_FAILURE;
   
   puts("Lista original:");
   imprimir(primero);
   
   puts("Lista ordenada:");
   ordenar(&primero);
   imprimir(primero);
   
   liberar(&primero);
   return EXIT_SUCCESS;
}

struct nodo *crear(int valor)
{
   struct nodo *p;
   
   if ((p = malloc(sizeof *p)) != NULL){
      p->valor = valor;
      p->sig = NULL;
   }
   
   return p;
}

struct nodo *agregar(struct nodo **primero, int valor)
{
   struct nodo *p;
   
   if ((p = crear(valor)) != NULL){
      p->sig = *primero;
      *primero = p;
   }
   
   return p;
}

void insertar(struct nodo **primero, struct nodo *nodo)
{
   struct nodo **p;
   
   p = primero;
   
   while (*p != NULL && (*p)->valor < nodo->valor)
      p = &((*p)->sig);
      
   nodo->sig = *p;
   *p = nodo;
}

void ordenar(struct nodo **primero)
{
   struct nodo *aux = NULL;
   struct nodo *nodo;
   
   /* Por cada nodo en la lista original apuntada por "*primero" */
   while (*primero != NULL){
      /* Extraemos un nodo de la lista original ... */
      nodo = *primero;
      *primero = (*primero)->sig;
      
      /* ... y lo insertamos (en orden) en la lista auxiliar */
      insertar(&aux, nodo);
   }
   
   /* Ajustamos el puntero a la lista original */
   *primero = aux;
}

void imprimir(struct nodo *primero)
{
   struct nodo *aux;
   
   for (aux = primero; aux != NULL; aux = aux->sig)
      printf("%3d", aux->valor);
   putchar('\n');
}   

void liberar(struct nodo **primero)
{
   struct nodo *nodo;
   struct nodo *aux;
   
   for (nodo = *primero; nodo != NULL; nodo = aux){
      aux = nodo->sig;
      free(nodo);
   }
   
   *primero = NULL;
}