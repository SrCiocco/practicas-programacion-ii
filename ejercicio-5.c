/* Basándonos en la estructura de nodos del nivel anterior, implementa una Pila LIFO.
 *
 * Escribe las funciones push (para pedir memoria, crear un nodo y agregarlo al tope de la pila) y pop 
 *	(para leer el valor del tope, liberar esa memoria dinámica y actualizar el tope).
 *
 * En el main, apila algunos valores y luego desapílalos todos hasta que la pila quede vacía.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
	int dato;
	struct Nodo *siguiente;
} Nodo;

void push(Nodo **pila, int dato);
int pop(Nodo **pila);

int main(void)
{
	Nodo *pila = NULL;

	push(&pila, 10);
	push(&pila, 20);
	push(&pila, 30);

	printf("Desapilando...\n");

	while (pila)
		printf("%d\n", pop(&pila));

	return 0;
}

void push(Nodo **pila, int dato)
{
	Nodo *nuevo = (Nodo *) malloc(sizeof(Nodo));

	nuevo->dato = dato;
	nuevo->siguiente = *pila;

	*pila = nuevo;
}

int pop(Nodo **pila)
{
	if (*pila == NULL)
		return -1;

	Nodo *tmp = *pila;
	int dato = tmp->dato;

	*pila = tmp->siguiente;
	free(tmp);

	return dato;

}
