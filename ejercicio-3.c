/* Define un struct Estudiante que contenga un int para la edad y un puntero a char para el nombre.
 * Pide memoria dinámicamente para un estudiante y, por separado, pide memoria dinámica para almacenar su nombre.
 * Llena los datos, imprímelos y libera ambas reservas de memoria en el orden correcto para evitar fugas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estudiante {
	int edad;
	char *nombre;
} Estudiante;

int main(void)
{
	Estudiante *estudiante = (Estudiante *) malloc(sizeof(Estudiante));

	if (!estudiante) {
		perror("malloc");
		return 1;
	}

	char buffer[100];

	printf("Introduce la edad para el estudiante: ");
	scanf("%d", &estudiante->edad);

	printf("Introduce un nombre para el estudiante: ");
	scanf("%99s", buffer);

	estudiante->nombre = (char *) malloc(strlen(buffer) + 1);

	if (!estudiante->nombre) {
		perror("malloc");
		free(estudiante);
		return 1;
	}

	strcpy(estudiante->nombre, buffer);
	printf("Estudiante: %s\nEdad: %d\n", estudiante->nombre, estudiante->edad);

	free(estudiante->nombre);
	free(estudiante);
	return 0;
}
