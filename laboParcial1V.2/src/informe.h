#ifndef INFORME_H_
#define INFORME_H_
#include "menuGeneral.h"

/////////////////////////////////////////////////////////////////INFORMES//////////////////////////////////////////////////////////////////////

int imprimirContribuyentes(eContribuyentes varContribuyente[],int lenContribuyente, eRecaudaciones varRecaudaciones[],int lenRecaudaciones);

int imprimirRecaudacionesSaldadas(eRecaudaciones varRecaudaciones[],int lenRecaudaciones, eContribuyentes varContribuyente[],int lenContribuyente);

///////////////////////////////////////////////////////////////FUNCIONES_INFORMES//////////////////////////////////////////////////////////////

int buscarIdRecaudacionSinConsultarUsuario(eRecaudaciones varGeneral[],int len,int idContribuyente);

int buscarIdContribuyenteSinConsultarUsuario(eContribuyentes varGeneral[],int len,int idContribuyente);

int ordenarPorIdContribuyenteR(eRecaudaciones varGeneral[],int len);

///////////////////////////////////////////////////////////////FUNCIONES_MOSTRAR////////////////////////////////////////////////////////////////////////////

void mostrarRecaudacionContribuyente(eRecaudaciones varRecaudaciones[], eContribuyentes varContribuyente[],int lenRecaudaciones,int lenContribuyente);

void mostrarRecaudacionesSaldadas(eRecaudaciones varRecaudaciones[], eContribuyentes varContribuyente[],int lenRecaudaciones,int lenContribuyente);

#endif /* INFORME_H_ */
