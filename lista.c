#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Lista{
	int dato;
	int dato2;
	struct Lista * sig;
}Lista;

//TDA Lista
	//Crear Nodo.
	Lista * crearNL(){
		//Solicitamos La memoria para el nodo.
		Lista * lista = (Lista *)malloc(sizeof(Lista));
		if (lista != NULL){
			lista->dato = 0;
			lista->dato2= 0;
			lista->sig  = NULL;
			return lista;
		}else{
			printf("Memoria llena, no se puede crear nodo.");
			return NULL;
		}
	}
	//Insertar Nodo por la cabeza
	void insertarIL(Lista ** cabeza, Lista * Nodo){
		if (*cabeza != NULL){
			if( Nodo != NULL ){
				Nodo->sig =  *cabeza;
				*cabeza = Nodo;
			}
		}else{
			if (Nodo != NULL){
				*cabeza = Nodo;
			}else{
				printf("Ambos Son nulos");
			}
		}
	}
	//Insertar Nodo en el Final
	void insertarFL(Lista ** cabeza, Lista * Nodo){
		if (*cabeza != NULL){
			if( Nodo != NULL){
				Lista * aux = *cabeza;
				while( aux->sig != NULL){
					aux = aux->sig;
				}
				aux->sig = Nodo;
			}
		}else{
			if (Nodo != NULL){
				*cabeza = Nodo;
			}else{
				printf("Ambos Son nulos");
			}
		}
	}
	//Eliminar al inicio
	void eliminarIL(Lista ** cabeza){
		Lista * aux = *cabeza;
		if (*cabeza != NULL){
			*cabeza = (*cabeza)->sig;
			free(aux);
		}
	}
	//Eliminar al final
	void eliminarFL(Lista ** cabeza){
		if(*cabeza != NULL){
			Lista * aux = *cabeza;
			while( aux->sig->sig != NULL){
				aux = aux->sig;
			}
			free(aux->sig);
			aux->sig = NULL;
		}
	}
	//Contar largo
	int largoL(Lista ** cabeza){
		if (*cabeza != NULL){
			int contador = 0;
			Lista * aux = *cabeza;
			while( aux != NULL){
				contador +=1;
				aux = aux->sig;
			}
			return contador;
		}else{
			return 0;
		}	
	}
	//retorna un nodo dada una posicion.
	Lista * rtrNodo(Lista ** cabeza, int posicion, int largo){
		if (posicion < largo + 1){
			int contador = 1;
			Lista * aux = *cabeza;
			while( contador < posicion){
				aux = aux->sig;
				contador +=1;
			}
			return aux;
		}else{
			printf("No existe la poscion \n");
			return NULL;
		}
	}
	//Cambiar nodos, el control de indices debe hacerse en el llamado
	// de la funcion.

	void swapnodosL(Lista ** cabeza, int indice1, int indice2, int largo){
		if (*cabeza != NULL){
			//Utilizaremos este temporal para intercambiar nodos.
			
			if (indice1 < largo +1 && indice2 < largo +1){
				//Evitar doble trabajo más adelante
				Lista * pi1 = rtrNodo(cabeza,indice1,largo);
				Lista * pi2 = rtrNodo(cabeza,indice2,largo);
				int idato1 = pi1->dato;
				int idato2 = pi1->dato2;

				int sdato1 = pi2->dato;
				int sdato2 = pi2->dato2;

				pi1->dato = sdato1;
				pi1->dato2 = sdato2;

				pi2->dato = idato1;
				pi2->dato2 = idato2;
				
			}
		}else{
			printf("La lista es nula o indices fuera de rango, no se ha logrado el swap\n");
		}
		
	}

	//Ordenar segun:
		void ordenarMayorMenorDatoL(Lista ** cabeza){
			Lista * temporal1;
			Lista * temporal2;
			int largo = largoL(cabeza);

			for (int i = 2; i < largo+1; i++){
				for (int j = 1; j < largo; j++){

					temporal1 = rtrNodo(cabeza,j,largo);
					temporal2 = rtrNodo(cabeza,j+1,largo);

					if ((temporal1->dato) < (temporal2->dato) ){
						swapnodosL(cabeza,j,j+1,largo);
					}
				}
			}	
		}

	//Imprimir arreglo
	void imprimir(Lista * cabeza){
	   	Lista * aux = cabeza;
		while (aux != NULL){
	      	printf("%d\n", aux->dato);
	      	aux = aux->sig;
	   	}
	}	  	 

int main(int argc, char const *argv[])
{
	Lista * x = crearNL();
	Lista * y = crearNL();
	Lista * z = crearNL();
	x->dato = 7;
	x->dato2 =17; 
	x->sig = y;

	y->dato = 4;
	y->dato2 = 14; 
	y->sig = z;

	z->dato = 5;
	z->dato2 =15; 
	z->sig = NULL;

	Lista * nuevo = crearNL();
	nuevo->dato = 4;
	nuevo->dato2 = 14;

	Lista * nuevo2 = crearNL();
	nuevo2->dato = 3;
	nuevo2->dato2 = 13;

	/*Lista * nuevo3 = crearNL();*/
	
	printf("Nuevo Antes i de %d\n",largoL(&x));
	imprimir(x);
	insertarIL(&x, nuevo);
	printf("Nuevo Despues i de %d\n",largoL(&x));
	imprimir(x);
	printf("\n");

	printf("Nuevo Antes f de %d\n",largoL(&x));
	imprimir(x);
	insertarFL(&x,nuevo2);
	printf("Nuevo Despues f de %d\n",largoL(&x));
	imprimir(x);
	printf("\n");


	printf("Nuevo Antes ordenar %d\n",largoL(&x));
	imprimir(x);
	ordenarMayorMenorDatoL(&x);
	printf("Nuevo Despues ordenar %d\n",largoL(&x));
	imprimir(x);
	printf("\n");

	/*printf("Nuevo Antes f de %d\n",largoL(&x));
	imprimir(x);
	eliminarIL(&x);
	printf("Nuevo Despues f de %d\n",largoL(&x));
	imprimir(x);
	printf("\n");

	printf("Nuevo Antes f de %d\n",largoL(&x));
	imprimir(x);
	eliminarFL(&x);
	printf("Nuevo Despues f de %d\n",largoL(&x));
	imprimir(x);
	printf("\n");

	printf("Nuevo Antes swap de %d\n",largoL(&x));
	imprimir(x);
	swapnodosL(&x, 1);
	printf("Nuevo Despues swap de %d\n",largoL(&x));
	imprimir(x);
	printf("\n");

	printf("Nuevo Antes swap de %d\n",largoL(&x));
	imprimir(x);
	ordenarMayorMenorDatoL(&x);
	printf("Nuevo Despues swap de %d\n",largoL(&x));
	imprimir(x);
	printf("\n");*/
	return 0;
}


/*
	codigo compilacion
	gcc -Wall x.c -o x -lm

*/