#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Estuctura para Grafo, nodo vecino con su respectivo peso.
struct nodoVecino{
	int id;
	int distancia;
	struct nodoVecino *sig;	
};

//Estuctura para Grafo, lista de nodos.
struct nodo{
	int id;
	struct nodo *sig;
	struct nodoVecino *sigV;
};

//Estructura para listas.
struct Lista{
	int dato;
	int dato2;
	struct Lista *sig;
};

//TDA Para estructura lista.
	//Crear
	struct Lista * crearNL(){
		struct Lista * lista = (struct Lista *)malloc(sizeof(struct Lista));
		if(lista!=NULL){
		    lista->dato = 0;
		    lista->dato2 = 0;
			lista->sig = NULL;
			return lista;
		}
		else{
			return NULL;
		}
	}
	//Eliminar Primer Elemento.
	struct Lista * eliminarPNL(struct Lista * L){
		if (L == NULL){
			return L;
		}else{
			return L->sig;
		}
	}

	//Eliminar ultimo Elemento.
	struct Lista * eliminarUNL(struct Lista * L){
		if (L == NULL){
			return L;
		}else{
			struct Lista * aux = L;
			while(aux != NULL){
				if ( (aux->sig)->sig == NULL){
					aux->sig = NULL;
					return L;
				}
				aux = aux->sig;
			}
		}
	}

	//Insertar (inserta en la posicion solicitada)
	struct Lista * insertarNL(struct Lista * L, int posicion, struct Lista * nodo){
	    if (L==NULL){
	        L=nodo;
	        return L;
	    }
	    else {
	    	struct Lista * cabeza = L;
		    struct Lista * aux = L;
		    struct Lista * aux2 = L->sig;
	    	int contador = 0;

	    	while(aux2 != NULL){

	    		if (contador == posicion){
	    			aux->sig = nodo;
	    			nodo->sig = aux2;
	    		}else{

	    			aux = aux->sig;
	    			aux2 = aux->sig->sig;
	    		}
	    		contador++;
	    	}

	    	return cabeza;
	   	}
	}

	//Imprimir una Lista
	void imprimirNL(struct Lista * L){
		if(	L == NULL){
			printf("\n ListaVacia \n");
		}
		else{
			struct Lista * aux = L;
			while(aux != NULL){
				printf("\n Id Nodo %d, \n", aux->dato);
				aux = aux->sig;
			}
		}
	}

//TDA Para estructura nodo.

//TDA Para estructura nodoVecino
	//Obtener el largo de la lista enlazada de la estructura nodo vecino
	int LargoListaNV(struct nodoVecino * cabeza){
		if (cabeza!= NULL){
			struct nodoVecino * auxiliar = cabeza;
			int largo = 0;
			while(auxiliar!=NULL){
		            largo +=1;
		            auxiliar = auxiliar -> sig;
		        }
		    return largo;
		}else{
			return 0;
		}
	}
	//Crear nodo Vecino
	struct nodoVecino * crearNV(){
	    //Solicitamos memora para la lista de nodos vecinos
		struct nodoVecino * lista = (struct nodoVecino *)malloc(sizeof(struct nodoVecino));
		//Si lista se asigna con una direccion valida asignamos variables
		if(lista!=NULL){
		    lista->id = 0;
			lista->sig = NULL;
			return lista;
		}
		//En caso contrario se retorna nulo
		else{
			return NULL;
		}
	}


//Funcionalidad 1, listar los puntos de entrega de mayor a menor.
void OrdenDeNodosPorPeso(struct nodo * listadeNodos, int cantidadNodos){

	//Creamos un arreglo para guardar la cantidad de nodos vecinos por nodo.
	int ** cantidadDeNodosVecinos = (int**)malloc(sizeof(int*)*cantidadNodos);
	//Asignamos memoria para el arreglo con posiciones, 0 = cantidad de nodos, 1 = id del nodo.
	for (int i = 0; i < cantidadNodos; ++i){
		cantidadDeNodosVecinos[i] = (int*)malloc(sizeof(int)*2);
	}
	//Rellenamos el arreglo con los datos correspondientes.
	struct nodo * auxiliar = listadeNodos;
    for(int i=0;i< cantidadNodos;i++){	
    	cantidadDeNodosVecinos[i][1] = i;
        cantidadDeNodosVecinos[i][0] = LargoListaNV(auxiliar->sigV);
        auxiliar = auxiliar->sig;
    }
    //Ordenamos el arreglo de mayor a menor, por relaciones con nodos vecinos.


    //Tenemos el arreglo listo lo imprimimos
    for(int i=0;i<cantidadNodos;i++){	
    	printf("id = %d, veces que se repite = %d.\n", cantidadDeNodosVecinos[i][1],cantidadDeNodosVecinos[i][0]);
   
    }
}

int main(int argc, char const *argv[]){
	struct Lista  x,y,z,m;
	x.dato =1;
	x.dato2 =11; 
	x.sig =&y;

	y.dato =2;
	y.dato2 =12; 
	y.sig =&z;

	z.dato =3;
	z.dato2 =13; 
	z.sig = NULL;
	imprimirNL(&x);
	printf("Again\n");
	imprimirNL(&x);

	m.dato =7;
	m.dato2 =7; 
	m.sig = NULL;

	struct Lista * nueva;
	nueva = insertarNL(&x,0,&m);
	printf("Nueva 0 \n");
	imprimirNL(nueva);

	nueva = insertarNL(&x,1,&m);
	printf("Nueva 1 \n");
	imprimirNL(nueva);

	nueva = insertarNL(&x,2,&m);
	printf("Nueva 0 \n");
	imprimirNL(nueva);



	return 0;
}