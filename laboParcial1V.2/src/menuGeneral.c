#include "menuGeneral.h"

int menuGeneral(eContribuyentes varGeneralContribuyente[],eRecaudaciones varGeneralRecaudaciones[])
{
	int funcionar=0;
	int elegir;
	int error;
	int legajoRecaudaciones=100;
	int legajoContribuyente=1000;
	if(varGeneralContribuyente != NULL && varGeneralRecaudaciones != NULL)
	{
		do
		{
			printf("\n/////////////////////////////////////////////\n");
			printf("///                                       ///\n");
			printf("///      [1]-ALTA CONTRIBUYENTE           ///\n");
			printf("///      [2]-MODIFICAR CONTRIBUYENTE      ///\n");
			printf("///      [3]-BAJA CONTRIBUYENTE           ///\n");
			printf("///      [4]-RECAUDACION                  ///\n");
			printf("///      [5]-REFINANCIAR RECAUDACION      ///\n");
			printf("///      [6]-SALDAR RECAUDACION           ///\n");
			printf("///      [7]-IMPRIMIR CONTRIBUYENTES      ///\n");
			printf("///      [8]-IMPRIMIR RECAUDACIONES       ///\n");
			printf("///      [9]-SALIR                        ///\n");
			printf("///                                       ///\n");
			printf("/////////////////////////////////////////////\n");
			printf("Opcion:  ");
			error = cargarNumero(&elegir);
			if (error==0)
			{
				if(valorConRango(elegir, 1, 9))
				{
					switch(elegir)
					{
					case 1:
						ABMAltaC(varGeneralContribuyente, cantidadContribuyentes, &legajoContribuyente);
						funcionar=1;
						break;
					case 2:
						ABMModificarC(varGeneralContribuyente, cantidadContribuyentes, "contribuyentes", "CUIL", "nombre", "apellido");
						funcionar=1;
						break;
					case 3:
						ABMBajaR(varGeneralRecaudaciones, cantidadRecaudacion, varGeneralContribuyente, cantidadContribuyentes);
						funcionar=1;
						break;
					case 4:
						ABMAltaR(varGeneralRecaudaciones, cantidadRecaudacion, &legajoRecaudaciones, varGeneralContribuyente, cantidadContribuyentes);
						funcionar=1;
						break;
					case 5:
						ABMRefinanciarSaldarR(varGeneralRecaudaciones, cantidadRecaudacion, REFINANCIAR);
						funcionar=1;
						break;
					case 6:
						ABMRefinanciarSaldarR(varGeneralRecaudaciones, cantidadRecaudacion, SALDADO);
						funcionar=1;
						break;
					case 7:
						imprimirContribuyentes(varGeneralContribuyente, cantidadContribuyentes, varGeneralRecaudaciones, cantidadRecaudacion);
						funcionar=1;
						break;
					case 8:
						imprimirRecaudacionesSaldadas(varGeneralRecaudaciones, cantidadRecaudacion, varGeneralContribuyente, cantidadContribuyentes);
						funcionar=1;
						break;
					}
				}else
				{
					printf("ERROR, ese valor no estaba dentro del rango\n");
				}
			}

		}while(elegir!=9);
	}

	return funcionar;
}
