#include <stdio.h>
#include "menuGeneral.h"

int main(void)
{
	setbuf(stdout,NULL);

	eContribuyentes contribuyentes[cantidadContribuyentes];
	eRecaudaciones recaudaciones[cantidadRecaudacion];
	inicializarisEmptyC(contribuyentes,cantidadContribuyentes);
	inicializarisEmptyR(recaudaciones, cantidadRecaudacion);

	menuGeneral(contribuyentes,recaudaciones);

	return 0;
}
