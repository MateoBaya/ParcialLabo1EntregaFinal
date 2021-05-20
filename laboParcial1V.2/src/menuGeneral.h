#ifndef MENUGENERAL_H_
#define MENUGENERAL_H_

#include <stdio.h>
#include "recaudaciones_estructura.h"
#include "contribuyente_estructura.h"
#include "mostrar.h"
#include "utn_general.h"
#include "informes.h"
#define cantidadContribuyentes 50
#define cantidadRecaudacion 50

int menuGeneral(eContribuyentes varGeneralContribuyente[],eRecaudaciones varGeneralRecaudaciones[]);
/* @brief Es un menu con un switch y validaciones de rango de valores
 * @param VarGeneralContribuyente[] Es un array que paso por referencia desde el main, del tipo estructura Contribuyente
 * @param VarGeneralRecaudaciones[] Es un array que paso por referencia desde el main, del tipo estructura Recaudaciones
 * @return funcionar se retorna 0 si no paso por ninguna funcion
 */

#endif /* MENUGENERAL_H_ */
