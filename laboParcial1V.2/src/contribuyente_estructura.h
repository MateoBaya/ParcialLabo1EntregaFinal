#ifndef CONTRIBUYENTE_ESTRUCTURA_H_
#define CONTRIBUYENTE_ESTRUCTURA_H_

#include <stdio.h>
#include <string.h>
#include "utn_general.h"

typedef struct
{
	int idContribuyente;
	char CUIL[MAXCHAR];
	char nombre[MAXCHAR];
	char apellido[MAXCHAR];
	int isEmpty;
}eContribuyentes;

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAltaC(eContribuyentes varGeneral[],int len,int * id);

int ABMLecturaC(eContribuyentes varGeneral[],int len);

int ABMModificarC(eContribuyentes varGeneral[],int len,const char * deseoModificar,const char * mensajeOpcion1,
const char * mensajeOpcion2,const char * mensajeOpcion3);

//////////////////////////////////BUSQUEDA_INFORMACION/////////////////////////////////////////////////

int mostrarEstructuraC(eContribuyentes varGeneral[],int i);

int buscarIdC(eContribuyentes varGeneral[],int len);

int buscarDescripcionC(eContribuyentes varGeneral[],int len);

int buscarVacioC(eContribuyentes varGeneral[],int len);

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarIdC(eContribuyentes varGeneral[],int len,int numero);

int validarIntencionUsuarioC(eContribuyentes varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar);

int validarEstructuraNoVaciaC(eContribuyentes varGeneral[],int len);

//////////////////////////////////////////FUNCIONES_ESTRUCTURAS////////////////////////////////////////

int inicializarisEmptyC(eContribuyentes varGeneral[],int len);

///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////

int ordenarPorIdC(eContribuyentes varGeneral[],int len);

#endif /* CONTRIBUYENTE_ESTRUCTURA_H_ */
