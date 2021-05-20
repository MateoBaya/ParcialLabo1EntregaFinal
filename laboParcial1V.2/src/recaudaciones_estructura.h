#ifndef RECAUDACIONES_ESTRUCTURA_H_
#define RECAUDACIONES_ESTRUCTURA_H_

#include <stdio.h>
#include <string.h>
#include "utn_general.h"
#include "contribuyente_estructura.h"

#define ARBA 1
#define IIBB 2
#define GANANCIAS 3
#define DEBE 1
#define REFINANCIAR 2
#define SALDADO 3

typedef struct
{
	int idRecaudaciones;
	int idContribuyente;
	int mes;
	int tipo;
	float importe;
	int estado;
	int isEmpty;
}eRecaudaciones;

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAltaR(eRecaudaciones varGeneral[],int len,int * id,eContribuyentes varContribuyente[],int lenContribuyente);
/* @brief Realiza el alta de una recaudacion, averigua si el idContribuyente es correcto , si no lo es tres veces, se sale
 * @param varGeneral Es un arrray que paso por referencia, del tipo estructura Contribuyente
 * @param len Es el tamaño del array varGeneral, se utiliza para buscar espacios libres
 * @param *id Es un puntero que toma un int y lo modifica, sumandole 1 por cada Alta correcta
 * @param varContribuyente Es un array que paso por referencia desde el main, del tipo estructura Recaudaciones
 * @param lenContribuyenteEs el tamaño del array varContribuyente
 * @return funcionar vale 1 cuando el alta ocurrrio correctamente
 */

int ABMBajaR(eRecaudaciones varGeneral[],int len, eContribuyentes varContribuyentes[], int lenContribuyentes);
/* @brief Realiza la baja de un Contribuyente y todas las recaudaciones relacioneadas con este
 * @param varGeneral Es un arrray que paso por referencia, del tipo estructura Contribuyente
 * @param len Es el tamaño del array varGeneral, se utiliza para un for que pone los valores de varGeneral isEmpty en 1
 * @param varContribuyentes[] Es un array que paso por referencia, del tipo estructura Contribuyente
 * @param lenContribuyentes es el tamaño del array, se utiliza para todas las funciones de validacion y de buscarId
 * @return funcionar vale 1 cuando la baja ocurrio correctamente
 */

int ABMLecturaR(eRecaudaciones varGeneral[],int len);
/* @brief Recorre el array y lo muestra completamente
 * @param varGeneral[] Es un array que paso por referencia desde el main, del tipo estructura Contribuyente
 * @param len es el tamaño de varGeneral, se usa para definir la cantidad de iteraciones que deben ocurrir
 */

int ABMRefinanciarSaldarR(eRecaudaciones varGeneral[],int len,int refinanciaOsalda);
/* @brief Cambia el valor de la variable estado del array varGeneral, funciona para refinanciar o saldar, si ya esta refinanciado no vuelve a refinanciar y lo mismo ocurre con saldar
 * @param varGeneral Es un arrray que paso por referencia, del tipo estructura Contribuyente
 * @param len Es el tamaño del array varGeneral, se utiliza para validaciones
 * @param refinanciaoSalda esta variable se utiliza para switchear la funcion, si debe refinanciar o si debe saldar
 * @return funcionar vale 1 cuando se efectuo una refinanciacion o se saldo correctamente
 */

//////////////////////////////////BUSQUEDA_INFORMACION/////////////////////////////////////////////////

int mostrarEstructuraR(eRecaudaciones varGeneral[],int i);

int buscarIdR(eRecaudaciones varGeneral[],int len);

int buscarVacioR(eRecaudaciones varGeneral[],int len);

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarIdR(eRecaudaciones varGeneral[],int len,int numero);

int validarIntencionUsuarioR(eRecaudaciones varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar);

int validarIntencionUsuarioContriRecauda(eRecaudaciones varRecaudaciones[],eContribuyentes varContribuyente[],int lenContribuyentes,int posicionACambiar);

int validarEstructuraNoVaciaR(eRecaudaciones varGeneral[],int len);

//////////////////////////////////////////FUNCIONES_ESTRUCTURAS////////////////////////////////////////

int inicializarisEmptyR(eRecaudaciones varGeneral[],int len);

///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////

int ordenarPorIdR(eRecaudaciones varGeneral[],int len);

#endif /* RECAUDACIONES_ESTRUCTURA_H_ */
