#include "recaudaciones_estructura.h"

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAltaR(eRecaudaciones varGeneral[],int len,int * id,eContribuyentes varContribuyente[],int lenContribuyente)
{
	int funcionar=0;
	int i;
	int error;
	int reintentos=3;
	int auxEntero;
	int posicionContribuyente;
	float auxFloat;

	if(varGeneral != NULL)
	{
		i=buscarVacioR(varGeneral, len);
		if(i==-1)
		{
			printf("ERROR. Todos los espacioes estan llenos");
		}else
		{
			*id=*id+1;
			varGeneral[i].idRecaudaciones=*id;

			do
			{
				posicionContribuyente = buscarIdC(varContribuyente, lenContribuyente);
				if(posicionContribuyente ==-1)
				{
					reintentos--;
					error=1;
					if(reintentos==0)
					{
						error=0;
					}else
					{
						printf("El id ingresado no existe,tiene %d intentos mas, reingrese\n",reintentos);
					}
				}else
				{
					varGeneral[i].idContribuyente = varContribuyente[posicionContribuyente].idContribuyente;
					error=0;
				}
			}while(error);

			if(reintentos>0)
			{

				do
				{
					printf("Cargue numero de mes: ");
					cargarNumero(&auxEntero);
					error = valorConRango(auxEntero, 1, 12);
				}while(error==0);

				varGeneral[i].mes = auxEntero;

				do
				{
					printf("Cargue tipo de Recaudacion [1]-ARBA [2]-IIBB [3]-GANANCIAS: ");
					cargarNumero(&auxEntero);
					error = valorConRango(auxEntero, 1, 3);
				}while(error==0);

				varGeneral[i].tipo = auxEntero;

				do
				{
					printf("Cargue importe: ");
					error = cargarFloat(&auxFloat);
				}while(error);

				varGeneral[i].importe = auxFloat;

				varGeneral[i].estado=DEBE;

				varGeneral[i].isEmpty=0;

				printf("Carga de recaudacion con exito:\n");
				printf("   IdRec  | IdCont | Estado  |       Importe       |  Mes   |   Tipo  \n");
				mostrarEstructuraR(varGeneral, i);
				funcionar=1;
			}


		}
	}
	return funcionar;
}

int ABMBajaR(eRecaudaciones varGeneral[],int len, eContribuyentes varContribuyentes[], int lenContribuyentes)
{
	int posicionACambiar;
	int funcionar=0;
	if(varGeneral != NULL && varContribuyentes != NULL)
	{
		if(validarEstructuraNoVaciaC(varContribuyentes, lenContribuyentes)==0)
			{
				printf("ERROR. No hay contribuyentes ingresados.");
			}else
			{
				posicionACambiar=buscarIdC(varContribuyentes,lenContribuyentes);
				if(validarIntencionUsuarioContriRecauda(varGeneral, varContribuyentes, lenContribuyentes, posicionACambiar))
				{
					varContribuyentes[posicionACambiar].isEmpty=0;
					for(int i=0;i<len;i++)
					{
						if(varContribuyentes[posicionACambiar].idContribuyente == varGeneral[i].idContribuyente)
						{
							varGeneral[i].isEmpty=1;
						}
					}
					funcionar=1;
				}
			}

	}
	return funcionar;
}

int ABMLecturaR(eRecaudaciones varGeneral[],int len)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		if(validarEstructuraNoVaciaR(varGeneral, len)==0)
		{
			printf("ERROR. No tiene recaudaciones ingresadas.");
		}else
		{
			ordenarPorIdR(varGeneral, len);
			printf("\n************************************************************************************************\n");
			printf("   IdRec  | IdCont | Estado  |       Importe       |  Mes   |   Tipo  \n");
			printf("************************************************************************************************\n");

			for(int i=0;i<len;i++)
			{

				if(varGeneral[i].isEmpty==0)
				{
					mostrarEstructuraR(varGeneral,i);
					funcionar=1;
				}
			}
			printf("*************************************************************************************************\n");
		}

	}


	return funcionar;
}

int ABMRefinanciarSaldarR(eRecaudaciones varGeneral[],int len,int refinanciaOsalda)
{
	int funcionar=0;
	int posicionACambiar;

	if(varGeneral != NULL)
		{
		if(validarEstructuraNoVaciaR(varGeneral, len)==0)
		{
			printf("ERROR. No hay recaudaciones ingresadas.");
		}else
		{
			posicionACambiar=buscarIdR(varGeneral,len);
					if(posicionACambiar==-1)
					{
						printf("No se encontro el id, reintente");
					}else if(varGeneral[posicionACambiar].estado != refinanciaOsalda)
					{
						printf("   IdRec  | IdCont | Estado  |       Importe       |  Mes   |   Tipo  \n");
						switch(refinanciaOsalda)
						{
						case REFINANCIAR:
							if(validarIntencionUsuarioR(varGeneral, posicionACambiar, "recaudacion", "refinanciar"))
							{
								varGeneral[posicionACambiar].estado = REFINANCIAR;
								funcionar=1;
							}
							break;
						case SALDADO:
							if(validarIntencionUsuarioR(varGeneral, posicionACambiar, "recaudacion", "saldar"))
							{
								varGeneral[posicionACambiar].estado = SALDADO;
								funcionar=1;
							}
							break;
						}

					}else
					{
						printf("Ya esta en el estado que quiere cambiar");
					}

		}
	}
	return funcionar;
}

///////////////////////////////////BUSQUEDA_INFORMACION////////////////////////////////////////////////

int mostrarEstructuraR(eRecaudaciones varGeneral[],int i)
{
	int funcionar=0;
	printf("    %-5d    %-5d      %-5d     %-15f      %-5d     %-5d   \n",varGeneral[i].idRecaudaciones,varGeneral[i].idContribuyente,varGeneral[i].estado,varGeneral[i].importe,varGeneral[i].mes,varGeneral[i].tipo);
	return funcionar;
}

int buscarIdR(eRecaudaciones varGeneral[],int len)
{
	int posicion=-1;
	int i;
	int id;
	if(varGeneral != NULL)
	{
		printf("Id a buscar: ");
		cargarNumero(&id);
		for(i=0;i<len;i++)
		{
			if(varGeneral[i].isEmpty==0)
			{
				if(varGeneral[i].idRecaudaciones == id)
				{
					posicion = i;
					break;
				}
			}
		}
	}
	return posicion;
}

int buscarVacioR(eRecaudaciones varGeneral[],int len)
{
	int posicion=-1;
	int i;
	if(varGeneral != NULL)
	{

		for(i=0;i<len;i++)
		{
			if(varGeneral[i].isEmpty==1)
			{
				posicion = i;
				break;
			}
		}

	}
	return posicion;
}

///////////////////////////////////VALIDACIONES_ESTRUCTURAS////////////////////////////////////////////

int validarIdR(eRecaudaciones varGeneral[],int len,int numero)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if (varGeneral[i].idRecaudaciones==numero)
			{
				funcionar=1;
				break;
			}
		}
	}
	return funcionar;
}

int validarIntencionUsuarioR(eRecaudaciones varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar)
{
	int funcionar=0;
	char decidir;
	int sinError;
	if(varGeneral != NULL)
	{
		do
		{
			mostrarEstructuraR(varGeneral, posicionACambiar);
			printf("\nSeguro que quiere %s este %s s/n: ",textoAValidar,mensaje);
			cargarCaracter(&decidir);
			sinError=validarSoN(decidir);
			if(sinError && decidir == 's')
			{
				funcionar = 1;
			}
		}while(sinError==0);
	}
	return funcionar;
}

int validarIntencionUsuarioContriRecauda(eRecaudaciones varRecaudaciones[],eContribuyentes varContribuyente[],int lenContribuyentes,int posicionACambiar)
{
	int funcionar=0;
	char decidir;
	int sinError;
	if(varRecaudaciones != NULL)
	{
		mostrarEstructuraC(varContribuyente, posicionACambiar);
		printf("Dar de baja recaudaciones: \n");
		printf("---------------------------------------------------------------------------------\n");
		for(int i=0;i<lenContribuyentes;i++)
			{
				if(varContribuyente[posicionACambiar].idContribuyente == varRecaudaciones[i].idContribuyente)
				{
					mostrarEstructuraR(varRecaudaciones, i);
					printf("---------------------------------------------------------------------------------\n");
				}

			}
		do
		{

			mostrarEstructuraC(varContribuyente, posicionACambiar);
			printf("\nSeguro que quiere eliiminar este contribuyente y sus recaudaciones s/n: ");
			cargarCaracter(&decidir);
			sinError=validarSoN(decidir);
			if(sinError && decidir == 's')
			{
				funcionar = 1;
			}
		}while(sinError==0);	}

	return funcionar;
}

int validarEstructuraNoVaciaR(eRecaudaciones varGeneral[],int len)
{
	int funcionar=0;

	for (int i=0;i<len;i++)
	{
		if(varGeneral[i].isEmpty == 0)
		{
			funcionar=1;
			break;
		}
	}

	return funcionar;
}

//////////////////////////////////////////FUNCIONES_ESTRUCTURAS////////////////////////////////////////

int inicializarisEmptyR(eRecaudaciones varGeneral[],int len)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		for(int i=0;i<len;i++)
		{
			varGeneral[i].isEmpty=1;
		}
		funcionar =1;
	}

	return funcionar;
}

///////////////////////////////////////ORDENAMIENTOS////////////////////////////////////////////////////

int ordenarPorIdR(eRecaudaciones varGeneral[],int len)
{
	int funcionar=0;
	int flagNoOrdenado=1;
	float auxFloat;
	int aux;
	if(varGeneral != NULL)
	{
		while(flagNoOrdenado)
		{
			flagNoOrdenado=0;
			for(int i=1; i<len;i++)
			{
				if(varGeneral[i].isEmpty==0 && varGeneral[i-1].isEmpty==0)
				{
					if(varGeneral[i].idRecaudaciones < varGeneral[i-1].idRecaudaciones)
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

