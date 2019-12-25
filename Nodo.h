#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int id;
	Lista *sigL;

	struct Nodo *sig;	
}Nodo; 

//TDA Para estructura nodo.
	//Crear Nodo
	Nodo * crearNN(){
			//Solicitamos La memoria para el nodo.
			Nodo * nodo = (Nodo *)malloc(sizeof(Nodo));
			if (nodo != NULL){
				nodo->id = 0;
				nodo->sig  = NULL;
				nodo->sigL = NULL;
				return nodo;
			}else{
				printf("Memoria llena, no se puede crear nodo.");
				return NULL;
			}
		}

	//Insertar Nodo por la cabeza
	void insertarIN(Nodo ** cabeza, Nodo * nodo){
		if (*cabeza != NULL){
			if( nodo != NULL ){
				nodo->sig =  *cabeza;
				*cabeza = nodo;
			}
		}else{
			if (nodo != NULL){
				*cabeza = nodo;
			}else{
				printf("Ambos Son nulos");
			}
		}
	}
	//Insertar Nodo en el Final
	void insertarFN(Nodo ** cabeza, Nodo * nodo){
		if (*cabeza != NULL){
			if( nodo != NULL){
				Nodo * aux = *cabeza;
				while( aux->sig != NULL){
					aux = aux->sig;
				}
				aux->sig = nodo;
			}
		}else{
			if (nodo != NULL){
				*cabeza = nodo;
			}else{
				printf("Ambos Son nulos");
			}
		}
	}
	//Eliminar al inicio
	void eliminarIN(Nodo ** cabeza){
		Nodo * aux = *cabeza;
		if (*cabeza != NULL){
			*cabeza = (*cabeza)->sig;
			free(aux);
		}
	}
	//Eliminar al final
	void eliminarFN(Nodo ** cabeza){
		if(*cabeza != NULL){
			Nodo * aux = *cabeza;
			while( aux->sig->sig != NULL){
				aux = aux->sig;
			}
			free(aux->sig);
			aux->sig = NULL;
		}
	}
	//Contar largo
	int largoN(Nodo ** cabeza){
		if (*cabeza != NULL){
			int contador = 0;
			Nodo * aux = *cabeza;
			while( aux != NULL){
				contador +=1;
				aux = aux->sig;
			}
			return contador;
		}else{
			return 0;
		}	
	}
	//Imprimir arreglo
	void imprimirN(Nodo * cabeza){
	   	Nodo * aux = cabeza;
		while (aux != NULL){
	      	printf("%d\n", aux->id);
	      	aux = aux->sig;
	   	}
	}	


