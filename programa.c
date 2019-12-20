#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Laboratorio 2 EDA, César Antonio Salazar Silva.

//Declaracion de la estructura Rgb
typedef struct rgb{
	int fila;
	int columna;
	int R;
	int G;
	int B;
}rgb;

//Declaracion de la estructura Nodo para una lista enlazada
typedef struct nodo{
	int similitud;
	struct nodo *sig;
}Nodo;

typedef Nodo* lista;

//De lista enlazada con similitudes
void agregarNodo(lista *cabeza, int n);
double encontrarPromedio();
double encontrarDesviacion(lista * L, double promedio);
void insertar(struct nodo **primero, struct nodo *nodo);
void ordenar(struct nodo **primero);

//De Cargar los datos de las imagenes.
rgb ** Matriz();
void verificar0(rgb ** imagen, rgb ** buscar, int posX, int posY, lista *L);
void verificar90(rgb ** imagen, rgb ** buscar, int posX, int posY, lista *L);
void verificar180(rgb ** imagen, rgb ** buscar, int posX, int posY, lista *L);
void verificar270(rgb ** imagen, rgb ** buscar, int posX, int posY, lista *L);
void vecesContenida(rgb ** imagen, rgb ** buscar);

//Main 
int main ( int argc, const char* argv[]){
	int menu;
	do{
		menu = 0;
		//Menu para ordenar
		printf("\n \n - Menu Experiencia 1 - \n");
		printf("\n Presione \"1\" para continuar, \"0\" para salir ... ");
		scanf("%d", &menu);
		
		switch(menu){
			case 1:
				//Solicitamos la matriz de la imagen 
				printf("\n Introduzca el nombre del archivo que contiene la imagen (con extencion): ");
				rgb ** matriz = Matriz();
				printf("\n Introduzca el nombre del archivo a buscar (con extencion): ");
				rgb ** matrizbuscar = Matriz();

				//Procesamos La informacion y buscamos coincidencias.
				if(matriz != NULL && matrizbuscar != NULL){
					vecesContenida(matriz,matrizbuscar);

					//Liberar memoria de ambos arreglos.
					int filamatriz = matriz[0][0].fila;
					int filamatrizbuscar = matrizbuscar[0][0].fila;
					for(int i = 0; i < filamatriz; i++)
			    		free(matriz[i]);
					free(matriz);
					for(int i = 0; i < filamatrizbuscar; i++)
			    		free(matrizbuscar[i]);
					free(matrizbuscar);
				}
				break;
			case 0:
				printf("Fin del Programa. \n");
				break;
			default:
				printf("Favor ejecutar, con datos en el formato solicitado. \n");
		}		
	}while(menu == 1);
	return 0;
	
}

//Encontrar el promedio de los datos en una lista enlazada.
//Entrada: Una cabeza de similitudes, un entero de Similitudes encontradas.
//Salida : El promedio de los datos, (double).
double encontrarPromedio(lista * L){
	double sumatoria = 0;
	double contador = 0;
	lista aux = *L;
	while(aux != NULL){
		sumatoria += aux->similitud;
		contador+=1;
		aux = aux->sig;
	}
	//printf("La sumatoria es : %f \n", sumatoria);
	//printf("Cantidad de datos : %f \n",contador);
	return sumatoria / contador;
}

//Encontrar la desviacion estandar de los datos en una lista enlazada.
//Entrada: Una cabeza de similitudes, un entero de Similitudes encontradas.
//Salida : La desviacion de los datos, (double).
double encontrarDesviacion(lista * L, double promedio){
	double sumatoria = 0;
	double contador = 0;

	lista aux = *L;
	while(aux != NULL){
		double resta = aux->similitud - promedio; 
		sumatoria += pow(resta,2);
		contador+=1;
		aux = aux->sig;
	}
	double desviacion = pow(sumatoria/contador,0.5);
	return desviacion;
}

//Encontrar Mediana
double encontrarMediana(lista * L){
	double mediana;
	ordenar(L);
	double largo = 0;
	lista aux = *L;
	while(aux != NULL){
		largo+=1;
		aux = aux->sig;
	}

	if ((int)largo%2 == 0 ){
		int contador = 0;
		lista aux = *L;
		while(aux != NULL){
			aux = aux->sig;
			contador+=1;
			if (contador == (int)(largo/2)){
				mediana = (aux->similitud + (aux->sig)->similitud)/2;
			}
		}
	}else if((int)largo%2 != 0 ){
		int contador = 0;
		lista aux = *L;
		while(aux != NULL){
			aux = aux->sig;
			contador+=1;
			if (contador == (int)ceil(largo/2)){
				mediana = aux->similitud ;
			}
		}
	}
	return mediana;
}

//Encontrar mayor Similitud
void menorSimilitud(lista * L){
	int contador = 0;
	int menorValor = 0;
	lista aux = *L;
	while(aux != NULL && menorValor == 0){
		if(aux->sig > 0){
			menorValor = aux->similitud;
		}
		aux = aux->sig;
	}
	aux = *L;
	while(aux != NULL){
		if (aux->similitud == menorValor){
			contador+=1;
		}
		aux = aux->sig;
	}
	if (contador == 0){
		aux = *L;
		menorValor = 0;
		while(aux != NULL){
			if (aux->similitud == (*L)->similitud){
				contador+=1;
			}
			aux = aux->sig;
		}

	}
	printf("Menor Similitud : %d Pixeles encontrados %d veces .\n", menorValor, contador);
}

//Encontrar menor Similitud
void mayorSimilitud(lista * L){
	int contador = 0;
	int mayorValor = 0;
	lista aux = *L;
	while(aux != NULL){
		if(aux->sig == NULL){
			mayorValor = aux->similitud;
		}
		aux = aux->sig;
	}
	aux = *L;
	while(aux != NULL){
		if (aux->similitud == mayorValor){
			contador+=1;
		}
		aux = aux->sig;
	}

	printf("Mayor Similitud : %d Pixeles encontrados %d veces .\n", mayorValor, contador);

}
//Funcion que lee a partir de un txt y almacena en una matriz.
//Entrada : Se solicita el nombre del archivo.
//Salida  : Matriz con datos cargados.
rgb ** Matriz(){
	//Se abre el archivo
	char nombre[50];
	scanf("%s", nombre);
	FILE * archivo;
	archivo=fopen(nombre,"r");
	int fila = 0;
	int columna = 0;
	//Control de error para archivo nulo
	if (archivo == NULL){
		printf("\n No hay ningun archivo con el nombre indicado. \n");
		return NULL;
	}else{
		//Se extrae la cantidad de filas y columnas
		fscanf(archivo, "%d %d", &columna, &fila );

		//Asignamos espacio de memoria para la matriz
		rgb ** matriz= (rgb**)malloc(sizeof(rgb*)*fila);
		for (int i=0;i<fila;i++){
			matriz[i]=(rgb*)malloc(sizeof(rgb)*columna);
		}
		rgb nuevoRGB;
		for(int i=0;i<fila;i++){
			for (int j = 0; j < columna; ++j){
				fscanf(archivo, "%d,%d,%d", &nuevoRGB.R ,&nuevoRGB.G,&nuevoRGB.B);
				nuevoRGB.fila = fila;
				nuevoRGB.columna = columna;
				matriz[i][j] = nuevoRGB; 
			}
		}

		//Cerramos el archivo y entregamos la matriz
		fclose(archivo);
		return matriz;
	}
}

//Buscar coincidencias para cada angulo
//Entrada: matriz, matriz que se va a buscar en la del primer argumento, posicion en "X" , posicion en "Y" donde se buscara.
//Salida: Se modifica la variable global aumentando si efectivamente se encontro equivalencia.
void verificar0(rgb ** imagen, rgb ** buscar, int posX, int posY,lista *L){
	int cero = 0;
	//0 grados
	for (int i = 0; i < buscar[1][1].fila; ++i){
		for (int j = 0; j < buscar[1][1].columna; ++j){
			if(imagen[posY+i][posX+j].R == buscar[i][j].R && imagen[posY+i][posX+j].G == buscar[i][j].G && imagen[posY+i][posX+j].B == buscar[i][j].B ){
				cero = cero+1;		
			}
		}
	}	
	agregarNodo(L,cero);
}
void verificar90(rgb ** imagen, rgb ** buscar, int posX, int posY,lista *L){
	//90 grados
	int noventa = 0;
	for (int i = 0; i < buscar[1][1].columna; ++i){
		for (int j = 0; j < buscar[1][1].fila; ++j){
			if(imagen[posY+i][posX+j].R == buscar[buscar[1][1].fila-1-j][i].R && buscar[buscar[1][1].fila-1-j][i].G == imagen[posY+i][posX+j].G && buscar[buscar[1][1].fila-1-j][i].B == imagen[posY+i][posX+j].B){
				noventa = noventa+1;
			}
		}
	}
	agregarNodo(L,noventa);
}
void verificar180(rgb ** imagen, rgb ** buscar, int posX, int posY,lista *L){
	//180 grados
	int cientoOchenta = 0;
	for (int i = 0; i < buscar[1][1].fila; ++i){
		for (int j = 0; j < buscar[1][1].columna; ++j){
			if(buscar[buscar[1][1].fila-1-i][buscar[1][1].columna-1-j].R == imagen[posY+i][posX+j].R && buscar[buscar[1][1].fila-i-1][buscar[1][1].columna-j-1].G == imagen[posY+i][posX+j].G && buscar[buscar[1][1].fila-1-i][buscar[1][1].columna-j-1].B == imagen[posY+i][posX+j].B){
				cientoOchenta = cientoOchenta +1;
			}
		}
	}
	agregarNodo(L,cientoOchenta);
}
void verificar270(rgb ** imagen, rgb ** buscar, int posX, int posY,lista *L){
	//270 grados
	int doscientoSetenta = 0;
	for (int i = 0; i < buscar[1][1].columna; ++i){
		for (int j = 0; j < buscar[1][1].fila; ++j){
			if(buscar[j][buscar[1][1].columna-1-i].R == imagen[posY+i][posX+j].R && buscar[j][buscar[1][1].columna-1-i].G == imagen[posY+i][posX+j].G && buscar[j][buscar[1][1].columna-1-i].B == imagen[posY+i][posX+j].B){
				doscientoSetenta = doscientoSetenta+1;
			}
		}
	}
	agregarNodo(L,doscientoSetenta);	
}

//Itera a lo largo de toda la imagen.
//Entrada: matriz, matriz que se va a buscar en la del primer argumento. (Arreglos de estructuras rgb)
//Salida : Imprimir por pantalla los valores encontrados de coincidencias.
void vecesContenida(rgb ** imagen, rgb ** buscar){
	//Creamos la cabeza de similitudes
	lista lista =NULL;
	//Iteramos por la matriz mas grande
	for (int i = 0; i < imagen[1][1].fila; ++i){
		for (int j = 0; j < imagen[1][1].columna; ++j){
			//Verificar por posicion.
			if(buscar[1][1].columna + j <= imagen[1][1].columna && buscar[1][1].fila + i <= imagen[1][1].fila){
				verificar0(imagen,buscar,j,i,&lista);
				verificar180(imagen,buscar,j,i,&lista);
			}
			if(buscar[1][1].columna + i <= imagen[1][1].fila && buscar[1][1].fila + j <= imagen[1][1].columna){
				verificar90(imagen,buscar,j,i,&lista);
				verificar270(imagen,buscar,j,i,&lista);
			}	
		}
	}
	double promedio = encontrarPromedio(&lista);
	double desviacion = encontrarDesviacion(&lista,promedio);
	double mediana = encontrarMediana(&lista);
	mayorSimilitud(&lista);
	menorSimilitud(&lista);
	printf("\nMedia = %f .\n", promedio);
	printf("\nDesviacion = %f .\n", desviacion);
	printf("\nMediana = %f .\n", mediana);

}

//Agregar un nodo a la cabeza.
//Entrada: Una cabeza de similitudes, un entero de Similitudes encontradas.
//Salida : cabeza con el nodo agregado.
void agregarNodo(lista *cabeza, int n){
	lista nuevo = malloc(sizeof(Nodo));
	nuevo->similitud = n;
	nuevo->sig = *cabeza;	
	*cabeza = nuevo;
}

void ordenar(struct nodo **primero){
   struct nodo *aux = NULL;
   struct nodo *nodo;
   while (*primero != NULL){
      nodo = *primero;
      *primero = (*primero)->sig;
      insertar(&aux, nodo);
   }
   *primero = aux;
}

void insertar(struct nodo **primero, struct nodo *nodo){
   struct nodo **p;
   p = primero;
   while (*p != NULL && (*p)->similitud < nodo->similitud)
      p = &((*p)->sig);      
   nodo->sig = *p;
   *p = nodo;
}
