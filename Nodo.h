#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
	int id;
	//Valores para almacenar recorrido algoritmo de dijktra
	int dijFinal;
	int dijTemporal;
	int dijID;

	Lista *sigL;

	struct Nodo *sig;	
}Nodo; 

//TDA Grafo, Matriz dispersa .
	//Crear Nodo
	Nodo * crearNN(){
		//Solicitamos La memoria para el nodo.
		Nodo * nodo = (Nodo *)malloc(sizeof(Nodo));
		if (nodo != NULL){
			nodo->id = 0;
			//Valores de dijktra considerados nulos
			nodo->dijFinal    = -1000;
			nodo->dijTemporal = -1000;
			nodo->dijID       = -1000;
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
	//Imprimir Grafo
	void imprimirN(Nodo * cabeza){
	   	Nodo * aux = cabeza;
		while (aux != NULL){
	      	printf("%d .- ", aux->id);
	      	imprimirL(aux->sigL);
	      	printf("\n");
	      	aux = aux->sig;
	   	}
	}	


//Funcion Particular para Dijktra
	//dijFinal   -------- valor final.
	//dijTemporal-------- valor temporal.
	//dijId      -------- Id del nodo del que viene
	//Estos valores tendran el valor -1000 para indicar null.

	//Encontrar menor sin temporal
	Nodo * menorTempSinFinal(Nodo ** cabeza){
		Nodo * aux = *cabeza;
		Nodo * menor = *cabeza;
		while(aux!= NULL){
			if (aux->dijFinal == -1000 && aux->dijTemporal < menor->dijTemporal){
				menor = aux;
			}
			aux = aux->sig;
		}
		return menor;
	}

	//Rellenar lista temporal
	void inTemp(Nodo ** cabeza){
		int numero = 0;
		Nodo * aux = *cabeza;
		while(aux!= NULL){
			printf("\nIntroduzca un numero entero: ");
    		scanf("%d", &numero);
    		printf("\n");
			aux->dijTemporal = numero;
			aux = aux->sig;
		}
	}
	//Imprimir temporal 
	void imprimirDij(Nodo * cabeza){
		Nodo * aux	= cabeza;
		printf("\n");
		while(aux!=NULL){
			printf("%d ", aux->dijTemporal);
	      	aux = aux->sig;
		}
		printf("\n");
	}

	//FuncionAlgoritmoDijktra
	void dijktra(Nodo ** cabeza){
		//Debemos recorrer y verificar hasta el nodo final

	}





