#include <stdio.h>

main()
{
	char cadena[50];
	char *p;

	puts("Escriba un texto:");
	p = gets(cadena);
	if (p) {
		puts("El texto escrito es:"); puts(cadena);
	}
	else
		puts("No se ha guardado nada.");
}