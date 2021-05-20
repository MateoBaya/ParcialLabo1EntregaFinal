#ifndef INFORMES_H_
#define INFORMES_H_
#include "menuGeneral.h"

int contribuyentesConMasFinanciar(eContribuyentes varContribuyentes[],int lenContribuyentes,eRecaudaciones varRecaudaciones[],int lenRecaudaciones);

void mostrarRecaudacionesFebrero(eRecaudaciones varRecaudaciones[], eContribuyentes varContribuyente[],int lenRecaudaciones,int lenContribuyente);

void mostrarEleccionUsuario(eRecaudaciones varRecaudaciones[], eContribuyentes varContribuyente[],int lenRecaudaciones,int lenContribuyente,int decisionUsuario);

#endif /* INFORMES_H_ */
