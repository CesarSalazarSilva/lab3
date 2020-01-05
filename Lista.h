#include <stdio.h>
#include <stdlib.h>

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
	//Retorna un nodo dada una posicion.
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
	//Cambiar valor entre nodos *NOTA HACER CONTROL DE INDICES*
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
	//Funcion que ordena una lista de mayor a menor dependiendo de dato o dato2
	void ordenarMayorMenorL(Lista ** cabeza, int modo){
		Lista * temporal1;
		Lista * temporal2;
		int largo = largoL(cabeza);

		for (int i = 2; i < largo+1; i++){
			for (int j = 1; j < largo; j++){
				temporal1 = rtrNodo(cabeza,j,largo);
				temporal2 = rtrNodo(cabeza,j+1,largo);
				if (modo == 1){
					if ((temporal1->dato) < (temporal2->dato) ){
						swapnodosL(cabeza,j,j+1,largo);
					}
				}else if (modo == 2){
					if ((temporal1->dato2) < (temporal2->dato2) ){
						swapnodosL(cabeza,j,j+1,largo);
					}
				}
			}
		}	
	}
	//Imprimir arreglo
	void imprimirL(Lista * cabeza){
	   	Lista * aux = cabeza;
		while (aux != NULL){
	      	printf("%d,%d ", aux->dato,aux->dato2);
	      	aux = aux->sig;
	   	}
	}	  	 