#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Funciones externas separadas

//Estuctura para nodovecino va a ser Lista 
#include "Lista.h"
//Estuctura para nodo va a ser Nodo
#include "Nodo.h"


void lecturaGrafo(Nodo ** cabeza){
	printf("\nIniciando Lectura de archivo...\n");
	//Se abre el archivo
	printf("\n Introduzca el nombre del archivo que contiene la ruta (con extencion): ");
	char nombre[50];
	scanf("%s", nombre);
	FILE * archivo;
	archivo=fopen(nombre,"r");
	if (archivo == NULL){
		printf("\n No hay ningun archivo con el nombre indicado. \n");
	}else{
		//Extraemos cantidad de nodos
		int cantidadNodos,idnodo,peso;
		char verificador;

		for (int i = 0; i < 21; ++i){
			fscanf(archivo, "%i,%i,%c. ", &idnodo,&peso,&verificador);

			printf("%i,%i,%c.\n",idnodo,peso,verificador );

		}
		//Asignamos memoria para la lista de cabeceras
		/*Nodo * aux;
		fscanf(archivo, "%d,%d%c", &idnodo, &peso, &verificador);
		while(verificador != EOF){
			aux = crearNN();
			//Asignamos id
			aux->id = i;
			//Asignamos conexiones
			int o = 0;
			while( o < 10){
				printf("%d,%d%c ",idnodo,peso,verificador);
				fscanf(archivo, "%d,%d%c", &idnodo, &peso, &verificador);
				o++;
			}
			printf("\n");
			//Finalmente se agrega el nodo
			insertarFN(cabeza,aux);	
			
		}
	}
	printf("\nFin Lectura de archivo.\n");*/
	}
}

int main(int argc, char const *argv[]){
	//Lectura de Grafo
	Nodo * cabeza = NULL;
	lecturaGrafo(&cabeza);
	printf("\n-----------------------------\n");
	imprimirN(cabeza);

	/*Fun 3, Entregar en un archivo listados de mayor a menor segun conexiones
		*/

	/*Fun 2, Encontrar ruta que permita pasar por todos los puntos de entrega
			y entregarlo con su distancia total recorrida y los nodos recorridos
		*/

	/*Fun 1, Ruta mas corta entre 2 nodos y la distancia.
		*/


	return 0;
}