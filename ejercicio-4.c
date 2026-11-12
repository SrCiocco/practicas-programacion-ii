/* Crea un struct Nodo que contenga un entero y un puntero al siguiente nodo. 
 *
 * En la función main, crea dinámicamente tres nodos, asígnales valores y enlázalos para 
 *	formar una pequeña lista. (el primero apunta al segundo, el segundo al tercero, el tercero a NULL). 
 *
 * Recorre la lista usando un puntero auxiliar para imprimir los valores y luego libera los tres nodos.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
	int dato;
	struct Nodo *siguiente;
} Nodo;

int main(void)
{
	Nodo *nodo1 = (Nodo *) malloc(sizeof(Nodo));
	Nodo *nodo2 = (Nodo *) malloc(sizeof(Nodo));
	Nodo *nodo3 = (Nodo *) malloc(sizeof(Nodo));

	if (!nodo1 || !nodo2 || !nodo3) {
		perror("malloc");
		return 1;
	}

	nodo1->dato = 10;
	nodo1->siguiente = nodo2;

	nodo2->dato = 20;
	nodo2->siguiente = nodo3;

	nodo3->dato = 30;
	nodo3->siguiente = NULL;

	Nodo *nodotmp = nodo1;

	while (nodotmp) {
		printf("%d\n", nodotmp->dato);
		nodotmp = nodotmp->siguiente;
	}

	nodotmp = nodo1;

	while (nodotmp) {
		Nodo *siguiente = nodotmp->siguiente;
		free(nodotmp);
		nodotmp = siguiente;
	}

	return 0;
}
