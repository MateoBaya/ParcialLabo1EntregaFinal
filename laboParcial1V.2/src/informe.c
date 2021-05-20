#include "informe.h"

/////////////////////////////////////////////////////////////////INFORMES//////////////////////////////////////////////////////////////////////

int imprimirContribuyentes(eContribuyentes varContribuyente[],int lenContribuyente, eRecaudaciones varRecaudaciones[],int lenRecaudaciones)
{
	int funcionar=0;

	if(varContribuyente != NULL && varRecaudaciones != NULL)
	{
		if(validarEstructuraNoVaciaC(varContribuyente, lenContribuyente)==0)
		{
			printf("ERROR. No hay contribuyentes ingresados.");
		}else
		{
				mostrarRecaudacionContribuyente(varRecaudaciones, varContribuyente, lenRecaudaciones, lenContribuyente);
				funcionar=1;

		}
	}
	return funcionar;
}

int imprimirRecaudacionesSaldadas(eRecaudaciones varRecaudaciones[],int lenRecaudaciones, eContribuyentes varContribuyente[],int lenContribuyente)
{
	int funcionar=0;
	if(varContribuyente != NULL && varRecaudaciones != NULL)
	{
		if(validarEstructuraNoVaciaC(varContribuyente, lenContribuyente)==0)
		{
			printf("ERROR. No hay contribuyentes ingresados.");
		}else
		{
			if(validarEstructuraNoVaciaR(varRecaudaciones, lenRecaudaciones)==0)
			{
				printf("ERROR. No hay recaudaciones ingresadas.");
			}else
			{
				mostrarRecaudacionesSaldadas(varRecaudaciones, varContribuyente, lenRecaudaciones, lenContribuyente);
				funcionar=1;
			}

		}
	}

	return funcionar;
}

///////////////////////////////////////////////////////////////FUNCIONES_INFORMES//////////////////////////////////////////////////////////////
int buscarIdRecaudacionSinConsultarUsuario(eRecaudaciones varGeneral[],int len,int idContribuyente)
{
	int posicion=-1;
	int i;
	if(varGeneral != NULL)
	{
		for(i=0;i<len;i++)
		{
			if(varGeneral[i].isEmpty==0)
			{
				if(varGeneral[i].idContribuyente == idContribuyente)
				{
					posicion = i;
					break;
				}
			}
		}
	}
	return posicion;
}

int buscarIdContribuyenteSinConsultarUsuario(eContribuyentes varGeneral[],int len,int idContribuyente)
{
	int posicion=-1;
	int i;
	if(varGeneral != NULL)
	{
		for(i=0;i<len;i++)
		{
			if(varGeneral[i].isEmpty==0)
			{
				if(varGeneral[i].idContribuyente == idContribuyente)
				{
					posicion = i;
					break;
				}
			}
		}
	}
	return posicion;
}

int ordenarPorIdContribuyenteR(eRecaudaciones varGeneral[],int len)
{
	int funcionar=0;
	int flagNoOrdenado=1;
	int aux;
	float auxFloat;
	if(varGeneral != NULL)
	{
		while(flagNoOrdenado)
		{
			flagNoOrdenado=0;
			for(int i=1; i<len;i++)
			{
				if(varGeneral[i].isEmpty==0 && varGeneral[i-1].isEmpty==0)
				{
					if(varGeneral[i].idContribuyente < varGeneral[i-1].idContribuyente)
					{
						aux=varGeneral[i].idRecaudaciones;
						varGeneral[i].idRecaudaciones=varGeneral[i-1].idRecaudaciones;
						varGeneral[i-1].idRecaudaciones=aux;

						aux=varGeneral[i].idContribuyente;
						varGeneral[i].idContribuyente=varGeneral[i-1].idContribuyente;
						varGeneral[i-1].idContribuyente=aux;

						auxFloat=varGeneral[i].importe;
						varGeneral[i].importe=varGeneral[i-1].importe;
						varGeneral[i].importe=auxFloat;

						aux=varGeneral[i].tipo;
						varGeneral[i].tipo=varGeneral[i-1].tipo;
						varGeneral[i-1].tipo=aux;

						aux=varGeneral[i].estado;
						varGeneral[i].estado=varGeneral[i-1].estado;
						varGeneral[i-1].estado=aux;

						aux=varGeneral[i].mes;
						varGeneral[i].mes=varGeneral[i-1].mes;
						varGeneral[i-1].mes=aux;
					}
				}
			}
		funcionar=1;
		}
	}
	return funcionar;
}

///////////////////////////////////////////////////////////////FUNCIONES_MOSTRAR////////////////////////////////////////////////////////////////////////////

void mostrarRecaudacionContribuyente(eRecaudaciones varRecaudaciones[], eContribuyentes varContribuyente[],int lenRecaudaciones,int lenContribuyente)
{
	int posicion;
	if(varRecaudaciones != NULL && varContribuyente != NULL)
	{
		printf("\n******************************************************************************************************************************\n");
		printf("   Id    |      CUIL     |   Nombre    |   Apellido  |  idRecaudacion |  Estado  |       Importe       |  Mes   |   Tipo \n");
		printf("******************************************************************************************************************************\n");

		ordenarPorIdContribuyenteR(varRecaudaciones, lenRecaudaciones);

		for(int i=0;i<lenContribuyente;i++)
		{

			if(varContribuyente[i].isEmpty==0)
			{
				posicion = buscarIdRecaudacionSinConsultarUsuario(varRecaudaciones, lenRecaudaciones, varContribuyente[i].idContribuyente);
				if (posicion == -1)
				{
					mostrarEstructuraC(varContribuyente, i);
				}else
				{
					printf("  %-5d     %-15s   %-10s   %-10s       %-5d          %-5d       %-15f      %-5d     %-5d\n",varContribuyente[i].idContribuyente,
					varContribuyente[i].CUIL,varContribuyente[i].nombre,varContribuyente[i].apellido,
					varRecaudaciones[posicion].idRecaudaciones,varRecaudaciones[posicion].estado,varRecaudaciones[posicion].importe,
					varRecaudaciones[posicion].mes,varRecaudaciones[posicion].tipo);
					for(int j=1;j<lenRecaudaciones;j++)
						{
							if(varRecaudaciones[j].isEmpty==0 && varRecaudaciones[j-1].isEmpty==0)
							{
								if(varRecaudaciones[j].idContribuyente == varRecaudaciones[j-1].idContribuyente && varRecaudaciones[j].idContribuyente == varContribuyente[i].idContribuyente)
								{
									posicion = j;
									printf("  %-5d     %-15s   %-10s   %-10s       %-5d          %-5d       %-15f      %-5d     %-5d\n",varContribuyente[i].idContribuyente,
									varContribuyente[i].CUIL,varContribuyente[i].nombre,varContribuyente[i].apellido,
									varRecaudaciones[posicion].idRecaudaciones,varRecaudaciones[posicion].estado,varRecaudaciones[posicion].importe,
									varRecaudaciones[posicion].mes,varRecaudaciones[posicion].tipo);

								}
							}
						}


				}
			}
		}
		printf("******************************************************************************************************************************\n");
	}
}

void mostrarRecaudacionesSaldadas(eRecaudaciones varRecaudaciones[], eContribuyentes varContribuyente[],int lenRecaudaciones,int lenContribuyente)
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
				if(varRecaudaciones[i].estado == SALDADO)
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
