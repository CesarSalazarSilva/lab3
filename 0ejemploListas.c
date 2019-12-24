#include <stdlib.h>
#include <stdio.h>
//Se genera una estructura de lista, con un dato
typedef struct Lista
{
	int dato;
	struct Lista *siguiente;
}Lista;

//Funci�n crear nodo
Lista* crearNodo(){
    //Se pide el espacio de memoria para la estructura
	Lista *lista = (Lista *)malloc(sizeof(Lista));
	//Si la asignaci�n de memoria es exitosa, se inicializan las variables
	if(lista!=NULL){
	    lista->dato = 0;
		lista->siguiente = NULL;
		return lista;
	}
	//En caso contrario se retorna nulo
	else{
		return NULL;
	}
}

//Funcion de insertar un dato en la lista
Lista* insertar(int dato,Lista * L){
    //Se crea una nueva lista
	Lista *nuevo = crearNodo();
	//Se comprueba si se realiz� con �xito
	//Si la lista es creada con �xito
	if(nuevo!=NULL){
        //Se ve si L est� vac�a
        if (L==NULL){
            //En ese caso, L ser� igual a la nueva lista que creamos
            L=nuevo;
            nuevo->dato = dato;
            nuevo->siguiente = NULL;
            return L;
        }
        //Si L contiene alg�n dato, la lista nueva, tendr� el dato y se pondr� el nodo delante de la lista L.
        else{
            nuevo->dato = dato;
            nuevo->siguiente = L;
            return nuevo;
        }
	}
	//En caso que la asignaci�n de memoria falle, se avisa del error y se retorna la lista L
	else{
        printf("Error en la asignaci�n de memoria\n");
        return L;
    }
}

void mostrar(Lista * L){
	if(L!=NULL){
        Lista *auxiliar = crearNodo();
        auxiliar=L;
        while(auxiliar!=NULL){
            printf("Elemento:%d\n", auxiliar->dato);
            auxiliar = auxiliar->siguiente;
        }
	}
}

int main(int argc, char const *argv[])
{
	int continuar = 0;
	int opcion = 0;
	Lista * L = NULL;
	while(continuar==0){
        printf("Continuar Si(1)/No(0)\n");
        scanf("%d",&opcion);
		switch(opcion){
			case 1: {
                    int aux;
                    printf("Ingrese un Numero:");
					scanf("%d",&aux);
					L = insertar(aux,L);
					mostrar(L);
					break;
					}
			case 0: continuar = 1;
					break;
		}
	}
	return 0;
}