#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sumarXvalor(int a,int b);
void sumarXreferencia(int a,int b,int *resultado);
 
int main(){
 int a=5;
 int b=2;
 int resultado=0;
 printf("Valores:n%in%in",a,b);
 
 printf("Paso de Parametros por Valorn");
 resultado = sumarXvalor(a,b);
 printf("Resultado: %in",resultado);
 
 printf("Paso de Parametros por ReferencianPasamos el valor de posicion en memoria de la variable resultado: %pn",&resultado);
 sumarXreferencia(a,b,&resultado);
 printf("Resultado: %in",resultado);
 sumarXreferencia(a,b,&resultado);
 printf("Resultado: %in",resultado);
 return 0;
}
 
int sumarXvalor(int a, int b){
 return a+b;
}
 
void sumarXreferencia(int a,int b,int *resultado){
 *resultado = a + b;
}