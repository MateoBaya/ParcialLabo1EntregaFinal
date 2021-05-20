#include "informes.h"

//int contribuyentesConMasFinanciar(eContribuyentes varContribuyentes[],int lenContribuyentes,eRecaudaciones varRecaudaciones[],int lenRecaudaciones)
//{
//	int funcionar=0;
//	int contadorMax=0;
//	int max=0;
//
//	if(varContribuyentes != NULL && varRecaudaciones != NULL)
//	{
//		for(int i=0;i<lenRecaudaciones;i++)
//		{
//			contadorMax=0;
//			if(varRecaudaciones[i].isEmpty==0)
//			{
//				for(int j=0;j<lenRecaudaciones;i++)
//				{
//					if(varRecaudaciones[j].idContribuyente == varContribuyentes[i].idContribuyente)
//					{
//						if(varRecaudaciones[j].estado == REFINANCIAR)
//						{
//							contadorMax++;
//						}
//					}
//
//				if(contadorMax>max)
//				{
//					max=contadorMax;
//				}
//				}
//
//			}
//		}
//		printf("%d",max);
//
//	}
//	return funcionar;
//}

//funciona
void mostrarRecaudacionesFebrero(eRecaudaciones varRecaudaciones[], eContribuyentes varContribuyente[],int lenRecaudaciones,int lenContribuyente)
{
	int flagMenu=1;
	int posicion;
	if(varRecaudaciones != NULL && varContribuyente != NULL)
	{
		ordenarPorIdContribuyenteR(varRecaudaciones, lenRecaudaciones);


		for(int i=0;i<lenRecaudaciones;i++)
		{

			if(varRecaudaciones[i].isEmpty==0)
			{
				if(varRecaudaciones[i].mes == 2)
				{
					posicion=buscarIdContribuyenteSinConsultarUsuario(varContribuyente, lenContribuyente, varRecaudaciones[i].idContribuyente);
					if(posicion!=-1)
					{
						if(flagMenu)
						{
							printf("\n*********************************************************************************************************\n");
							printf("   IdRec  | IdCont | Estado  |       Importe       |  Mes   |   Tipo  |      CUIL       |    Nombre     \n");
							printf("*********************************************************************************************************\n");
							flagMenu=0;
						}
						printf("    %-5d    %-5d      %-5d     %-15f      %-5d     %-5d  %-13s        %-10s \n",varRecaudaciones[i].idRecaudaciones,varRecaudaciones[i].idContribuyente,
								varRecaudaciones[i].estado,varRecaudaciones[i].importe,varRecaudaciones[i].mes,varRecaudaciones[i].tipo,varContribuyente[posicion].CUIL,varContribuyente[posicion].nombre);
						for(int j=1;j<lenContribuyente;j++)
						{
							if(varContribuyente[j].isEmpty==0 && varContribuyente[j-1].isEmpty==0)
							{
								if(varContribuyente[j].idContribuyente == varContribuyente[j-1].idContribuyente && varContribuyente[j].idContribuyente == varRecaudaciones[i].idContribuyente)
								{
									posicion=j;
									printf("    %-5d    %-5d      %-5d     %-15f      %-5d     %-5d  %-13s        %-10s \n",varRecaudaciones[i].idRecaudaciones,varRecaudaciones[i].idContribuyente,
									varRecaudaciones[i].estado,varRecaudaciones[i].importe,varRecaudaciones[i].mes,varRecaudaciones[i].tipo,
									varContribuyente[posicion].CUIL,varContribuyente[posicion].nombre);
								}
							}
						}

					}

				}
			}
		}
		if (flagMenu)
		{
			printf("ERROR. Ninguna recaudacion estaba saldada.");
		}else
		{
			printf("*********************************************************************************************************\n");

		}

	}

}
//funciona
void mostrarEleccionUsuario(eRecaudaciones varRecaudaciones[], eContribuyentes varContribuyente[],int lenRecaudaciones,int lenContribuyente,int decisionUsuario)
{
	int flagMenu=1;
	int posicion;
	if(varRecaudaciones != NULL && varContribuyente != NULL)
	{
		ordenarPorIdContribuyenteR(varRecaudaciones, lenRecaudaciones);


		for(int i=0;i<lenRecaudaciones;i++)
		{

			if(varRecaudaciones[i].isEmpty==0)
			{
				if(varRecaudaciones[i].tipo == decisionUsuario)
				{
					posicion=buscarIdContribuyenteSinConsultarUsuario(varContribuyente, lenContribuyente, varRecaudaciones[i].idContribuyente);
					if(posicion!=-1)
					{
						if(flagMenu)
						{
							printf("\n*********************************************************************************************************\n");
							printf("   IdRec  | IdCont | Estado  |       Importe       |  Mes   |   Tipo  |      CUIL       |    Nombre     \n");
							printf("*********************************************************************************************************\n");
							flagMenu=0;
						}
						printf("    %-5d    %-5d      %-5d     %-15f      %-5d     %-5d  %-13s        %-10s \n",varRecaudaciones[i].idRecaudaciones,varRecaudaciones[i].idContribuyente,
								varRecaudaciones[i].estado,varRecaudaciones[i].importe,varRecaudaciones[i].mes,varRecaudaciones[i].tipo,varContribuyente[posicion].CUIL,varContribuyente[posicion].nombre);
						for(int j=1;j<lenContribuyente;j++)
						{
							if(varContribuyente[j].isEmpty==0 && varContribuyente[j-1].isEmpty==0)
							{
								if(varContribuyente[j].idContribuyente == varContribuyente[j-1].idContribuyente && varContribuyente[j].idContribuyente == varRecaudaciones[i].idContribuyente)
								{
									posicion=j;
									printf("    %-5d    %-5d      %-5d     %-15f      %-5d     %-5d  %-13s        %-10s \n",varRecaudaciones[i].idRecaudaciones,varRecaudaciones[i].idContribuyente,
									varRecaudaciones[i].estado,varRecaudaciones[i].importe,varRecaudaciones[i].mes,varRecaudaciones[i].tipo,
									varContribuyente[posicion].CUIL,varContribuyente[posicion].nombre);
								}
							}
						}

					}

				}
			}
		}
		if (flagMenu)
		{
			printf("ERROR. Ninguna recaudacion estaba saldada.");
		}else
		{
			printf("*********************************************************************************************************\n");

		}

	}

}
