/* Pide al usuario un número N. 
 * Usa malloc para reservar un arreglo de N enteros. 
 * Pide al usuario que ingrese los valores, muéstralos en pantalla y luego libera la memoria con free.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;

	printf("Ingresa un valor N para el arreglo de N enteros: ");
	scanf("%d", &n);

	int *array = (int *) malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		printf("Ingrese un valor para array[%d]: ", i);
		scanf("%d", (array + i));
	}

	for (int i = 0; i < n; i++) {
		printf("array[%d]: %d\n", i, array[i]);
	}

	free(array);

	return 0;
}
