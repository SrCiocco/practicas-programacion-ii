/* Pide al usuario que ingrese números enteros de a uno por vez, deteniéndose cuando ingrese un 0. 
 * Usa malloc inicialmente y luego realloc para ir aumentando el tamaño del arreglo dinámico a medida que llegan nuevos datos. 
 * Al final, muestra todos los números ingresados y libera la memoria.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 0;
	int i = 0;
	int size = 5;

	int *array = (int *) malloc(sizeof(int) * size); 
	int *arrayTemp = array;

	if (!array) {
		perror("malloc");
		return 1;
	}

	do {
		if (i == size) {
			arrayTemp = (int *) realloc(array, sizeof(int) * (size * 2));
			size *= 2;
		}

		if (!arrayTemp) {
			perror("realloc");
			free(array);
			return 1;
		}

		array = arrayTemp;

		printf("Ingresa un numero (termina cuando introduzcas un 0): ");
		scanf("%d", &n);

		if (n == 0)
			break;

		array[i] = n;
		i++;
	}
	while (n != 0);

	for (int idx = 0; idx < i; idx++)
		printf("array[%d]: %d\n", idx, array[idx]);

	free(array);

	return 0;
}
