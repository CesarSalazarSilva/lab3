#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Estuctura para nodovecino va a ser Lista 
#include "Lista.h"
//Estuctura para nodo va a ser Nodo
#include "Nodo.h"

//Funcion que permite lectura de archivos 
//Entrada: Direccion de memoria que contiene la direccion de memoria de la cabeza del grafo.
//Salida: No hay dado que se modifica la lista enlazada que se forma al agregar nodos a cabeza.
void lecturaGrafo(Nodo ** cabeza, Lista ** LNumeroConexiones){
	printf("... Iniciando Lectura de archivo ...");
	//Se abre el archivo
	printf("\n- Introduzca el nombre del archivo que contiene la ruta (con extencion): ");
	char nombre[50];
	scanf("%s", nombre);
	FILE * archivo;
	archivo=fopen(nombre,"r");
	//Si el archivo no se encuentra.
	if (archivo == NULL){
		printf("\n No hay ningun archivo con el nombre indicado o hay error en la lectura del archivo. \n");

	//De encontrarse el archivo.
	}else{
		//Solicitamos Variables
		int contadorId,cantidadNodos,idnodo,peso;
		char verificador;
		Nodo * aux;
		Lista * nodoVecino;
		//Guardamos la cantidad de nodos 
		fscanf(archivo, "%i,%i%c", &cantidadNodos,&peso,&verificador);
		//Establecemos un contador para el id de los nodos cabezas
		contadorId = 1;
		//Para eficiencia de la solucion contamos la cantidad de nodos vecinos 
			//por nodo cabeza y lo asignamos a una lista para posterior manejo.
		//Contador cantidad conexiones por nodo.
		int cantConexiones=0;
		//Lista auxiliar para cantidad de conexiones.
		Lista * auxL;
		//Recorremos el archivo para guardar en la estructura
		while(fscanf(archivo, "%i,%i%c", &idnodo,&peso,&verificador) > 0){
			if (contadorId == 1){
				//Asignamos primera cabecera
				aux = crearNN();
				//Asignamos id
				aux->id = contadorId;
				insertarFN(cabeza,aux);
				contadorId++;
			}
			if (verificador == ' '){
				//Asignamos un nuevo nodo vecino 
				//printf("Espacio ");
				//printf("%i,%i.\n",idnodo,peso);
				nodoVecino = crearNL();
				nodoVecino->dato = idnodo;
				nodoVecino->dato2= peso;
				insertarFL(&(aux->sigL),nodoVecino);
				cantConexiones++;
			}else{
				//Agrego el ultimo nodo vecino.
				//printf("Salto de linea ");
				//printf("%i,%i.\n",idnodo,peso);
				nodoVecino = crearNL();
				nodoVecino->dato = idnodo;
				nodoVecino->dato2= peso;
				insertarFL(&(aux->sigL),nodoVecino);
				cantConexiones++;
				//Agregamos id del nodo mas su contador de conexiones a la lista entregada
				auxL = crearNL();
				//Contiene id del nodo
				auxL->dato = contadorId-1;
				//Contiene cantidad de conexiones.
				auxL->dato2= cantConexiones;
				insertarFL(LNumeroConexiones,auxL);
				cantConexiones=0;
				aux = crearNN();
				//Asignamos id a nuevo nodo cabecera
				aux->id = contadorId;
				//Agregar nodo cabecera.
				insertarFN(cabeza,aux);
				contadorId++;
			}	
		}
	//Se ingresa el ultimo nodo por formato del archivo, se considera que NO HAY una ultima 
		//linea vacia, es decir, no hay un ultimo salto de linea
	//Agregamos id del nodo mas su contador de conexiones a la lista entregada
	auxL = crearNL();
	//Contiene id del nodo
	auxL->dato = contadorId-1;
	//Contiene cantidad de conexiones.
	auxL->dato2= cantConexiones;
	insertarFL(LNumeroConexiones,auxL);
	}
	printf("... Fin de lectura de archivo ...\n");
}

//Funcion que permite encontrar el camino mas corto desde un punto a otro.
void rutaConMenorCosto(Nodo ** cabeza, Lista ** datosDijktra){
	//Crearemos una lista con los x nodos que contenga nuestro grafo.
	Nodo * auxG = *cabeza;
	Lista * auxL = NULL;
	//Asignamos la memoria necesaria.
	while(auxG != NULL){
		auxL = crearNL();
		insertarFL(datosDijktra,auxL);
		auxG = auxG->sig;
	}
}

int main(int argc, char const *argv[]){
	//Lectura de archivo
	//Creamos un nodo cabeza para el grafo.
	Nodo  * cabeza = NULL;
	Lista * LNumeroConexiones = NULL;
	//Lista que contendra el id del nodo y numero de conexiones.
	lecturaGrafo(&cabeza,&LNumeroConexiones);
	printf("--------------------------------------------------------------------------\n");
	printf("Grafo cargado al Sistema:\n");
	imprimirN(cabeza);
	//printf("Cantida de conexiones: \n");
	//imprimirL(LNumeroConexiones);

	/*Fun 3, Entregar en un archivo listados de mayor a menor segun conexiones
		*/
		printf("--------------------------------------------------------------------------\n");
		printf("Nodos ordenados por conexiones presentes de mayor a menor (id,conexiones):\n");
		ordenarMayorMenorL(&LNumeroConexiones,2);
		imprimirL(LNumeroConexiones);

	/*Fun 2, Encontrar ruta que permita pasar por todos los puntos de entrega
			y entregarlo con su distancia total recorrida y los nodos recorridos
		*/
		//Algoritmo de Busqueda por anchura o profundidad.


	/*Fun 1, Ruta mas corta entre 2 nodos y la distancia.
		*/
		//Algoritmo de Dijktra
		//Se tendrá asumido que el id del nodo estará relacionado con su posicion.
		printf("\n--------------------------------------------------------------------------\n");
		printf("Contenedor de Algoritmo de Dijktra:\n");
		Lista * datosDijktra = NULL;
		rutaConMenorCosto(&cabeza,&datosDijktra);
		imprimirL(datosDijktra);
		printf("\n--------------------------------------------------------------------------\n");

	return 0;
}