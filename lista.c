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
	Lista * rtrNodo(Lista ** cabeza, int posicion){
		if (posicion < largoL(cabeza)){
			int contador = 1;
			Lista * aux = *cabeza;
			while( contador <= posicion){
				contador +=1;
				aux = aux->sig;
			}
			return aux;
		}else{
			printf("No existe la poscion \n");
			return NULL;
		}
	}
	//Cambiar nodos, el control de indices debe hacerse en el llamado
	// de la funcion.

	void swapnodosL(Lista ** cabeza, int indice1, int indice2){
		if (*cabeza != NULL){
			int largo = largoL(cabeza);
			if (indice1 <= largo && indice2 <= largo){
				//Evitar doble trabajo más adelante
				Lista * pi1 = rtrNodo(cabeza,indice1);
				Lista * pi2 = rtrNodo(cabeza,indice2);

				Lista * pSi1 = pi1->sig;
				Lista * pSi2 = pi2->sig;

				//Caso con cabeza
				if (indice1 == 1 || indice2 == 1){
					if (indice1 == 1){
						Lista * pAi2 = rtrNodo(cabeza,indice2-1);
						
						pAi2->sig = pi1;
						pi1->sig  = pSi2;

						pi1  = pi2;
						pi2->sig  = pSi1;

						
						
						
					//Caso indice2 = 1
					}else{
						Lista * pAi1 = rtrNodo(cabeza,indice1-1);

						*cabeza  = pi1;
						(*cabeza)->sig  = pSi2;

						pAi1->sig = pi2;
						pi2->sig  = pSi1; 
						
						
					}
				//Caso ninguno es cabeza	
				}else{
					Lista * pAi1 = rtrNodo(cabeza,indice1-1);
					Lista * pAi2 = rtrNodo(cabeza,indice2-1);
					pAi2->sig = pi1;
					pi1->sig  = pSi2;
					pAi1->sig = pi2;
					pi2->sig  = pSi1;
					
				}
			}
		}else{
			printf("La lista es nula o indices fuera de rango, no se ha logrado el swap\n");
		}
		/*if (posicion == 1 && posicion < largoL(cabeza)){
			Lista * primero = *cabeza;
			Lista * segundo = (*cabeza)->sig;
			Lista * tercero = (((*cabeza)->sig)->sig);
			*cabeza = segundo;
			segundo->sig = primero;
			primero->sig = tercero;
		}else{
			if (posicion < largoL(cabeza)){
				int contador = 1;
				Lista * aux = *cabeza;
				while( contador < posicion-1){
					contador +=1;
					aux = aux->sig;
				}
				//Cambios. inicio :a->x->y->b final : a->y->x->b 
				Lista * tempa = aux;
				Lista * tempx = (aux)->sig;
				Lista * tempy = ((aux)->sig)->sig;
				Lista * tempb = (((aux)->sig)->sig)->sig;

				tempa->sig = tempy;
				tempy->sig = tempx;
				tempx->sig = tempb;	
			}else{
				printf("No se pudo hacer Swap, dado que es el ultimo elemento de la lista o la posicion no existe.\n");
			}
		}*/
	}

	//Ordenar segun:
		/*void ordenarMayorMenorDatoL(Lista ** cabeza){
			Lista * temporal1;
			Lista * temporal2;
			int largo = largoL(cabeza);

			for (int i = 1; i < largo-1; i++){
				printf("PASO\n");
				for (int j = i+1; j < largo; j++){

					temporal1 = rtrNodo(cabeza,i);
					temporal2 = rtrNodo(cabeza,j);
					
					printf(" 1. %d  2. %d\n",temporal1->dato,temporal2->dato );
					if ((temporal1->dato) > (temporal2->dato) ){
						printf("YES\n");
						swapnodosL(cabeza,i);
					}
				}
			}
			
		}*/

		void ordenarMayorMenorDato2L(Lista ** cabeza){

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
	x->dato = 5;
	x->dato2 =15; 
	x->sig = y;

	y->dato = 6;
	y->dato2 = 16; 
	y->sig = z;

	z->dato = 7;
	z->dato2 =17; 
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

	printf("Nuevo Antes swap %d\n",largoL(&x));
	imprimir(x);
	printf("%p blabla\n",x );
	swapnodosL(&x,1,3);
	printf("Nuevo Despues swap %d\n",largoL(&x));
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