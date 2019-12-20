#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *sig;	
};

int main(){

	int a, b;
	int *p1, *p2;
	struct nodo n1,n2;
	struct nodo *pn1, *pn2, *pn3, *aux;
	
	a = 100;
	b = 200;
	
	printf("Direccion: %p, dato: %d\n", &a, a);

	p1 = &a;
	
	printf("Direccion: %p, dato: %d\n", p1, *p1);
	
	p2 = &b;
	
	printf("Suma de contenidos de punteros: %d\n", *p1 + *p2);
	
	//Manejo de estructuras
	
	n1.dato = 500;
	n2.dato = 1000;
	
	n2.sig = &n1;
	n1.sig = &n2;
	
	printf("Dato de estructura: %d\n",n2.sig->dato);

	printf("Dato de estructura: %d\n",n2.sig->sig->dato);
	
	pn1 = &n1;
	n2.sig= NULL;
	
	printf("\n\nContenido de pn1: %p\n",pn1);
	printf("Direccion de n1: %p\n",&n1);
	printf("Contenido de pn1: %d\n",pn1->dato);
	printf("Contenido del siguiente a pn1: %d\n",pn1->sig->dato);
	
	printf("Siguiente a pn1->sig: %p\n\n",pn1->sig->sig);
	
	
	pn3 = (struct nodo *)malloc(sizeof(struct nodo));
	
	pn1->sig->sig = pn3;
	
	pn3->dato = 3000;
	pn3->sig = NULL;
	
	
//	aux = pn1;
//	while(aux!=NULL)
//		printf("Direccion nodo: %p, dato: %d\n",aux,aux->dato);
	
	aux = pn1;
	while(aux!=NULL){
		printf("Direccion nodo: %p, dato: %d\n",aux,aux->dato);
		aux = aux->sig;
	}
}
