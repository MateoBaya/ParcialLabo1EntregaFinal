#include "contribuyente_estructura.h"

///////////////////////////////////FUNCIONES_ABM///////////////////////////////////////////////////////

int ABMAltaC(eContribuyentes varGeneral[],int len,int * id)
{
	int funcionar=0;
	int i;
	int error;
	char auxTexto[MAXCHAR];
	int flagSalir=0;

		if(varGeneral != NULL)
		{

			i=buscarVacioC(varGeneral,len);
			if(i==-1)
			{
				printf("ERROR. Todos los espacios estan llenos");
			}else
			{
				*id=*id+1;
				varGeneral[i].idContribuyente=*id;
				printf("Si ingresa SALIR, saldra de la alta de este contribuyente\n");
				do
				{
					printf("Cargue el CUIL: ");
					cargarTexto(auxTexto);
					if(strcmp(auxTexto,"SALIR")==0)
					{
						flagSalir=1;
						break;
					}
					error=validarCUIT(auxTexto, len);
				}while(error == 0);
				if(flagSalir)
				{
					*id=*id-1;
				}else
				{
					strcpy(varGeneral[i].CUIL,auxTexto);

					do
					{
						printf("Cargue el nombre: ");
						error=cargarTexto(auxTexto);
					}while(error==0);
					if(strcmp(auxTexto,"SALIR")==0)
					{
						*id=*id-1;
					}else
					{
						primerLetraMayuscula(auxTexto);
						strcpy(varGeneral[i].nombre,auxTexto);

						do
						{
							printf("Cargue el apellido: ");
							error=cargarTexto(auxTexto);
						}while(error==0);
						if(strcmp(auxTexto,"SALIR")==0)
						{
							*id=*id-1;
						}else
						{
							primerLetraMayuscula(auxTexto);
							strcpy(varGeneral[i].apellido,auxTexto);

							varGeneral[i].isEmpty=0;
							printf("\nCarga de contribuyente con exito:\n");
							printf("   Id    |      CUIL     |   Nombre    |   Apellido   \n");
							mostrarEstructuraC(varGeneral, i);
							funcionar=1;
						}
					}

				}

			}
	}

	return funcionar;
}

int ABMLecturaC(eContribuyentes varGeneral[],int len)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		if(validarEstructuraNoVaciaC(varGeneral, len)==0)
		{
			printf("ERROR. No hay contribuyentes ingresados.");
		}else
		{
			printf("\n************************************************************************************************\n");
			printf("   Id    |      CUIL     |   Nombre    |   Apellido   \n");
			printf("************************************************************************************************\n");

			for(int i=0;i<len;i++)
			{

				if(varGeneral[i].isEmpty==0)
				{
					mostrarEstructuraC(varGeneral,i);
					funcionar=1;
				}
			}
			printf("*************************************************************************************************\n");
		}

	}


	return funcionar;
}

int ABMModificarC(eContribuyentes varGeneral[],int len,const char * deseoModificar,const char * mensajeOpcion1,
const char * mensajeOpcion2,const char * mensajeOpcion3)
{
	int funcionar=0;
	int posicionACambiar;
	char elegir;
	int flagError=1;
	char auxTexto[MAXCHAR];
	if(varGeneral != NULL)
	{
		if(validarEstructuraNoVaciaC(varGeneral, len)==0)
		{
			printf("ERROR. No hay contribuyentes ingresados.");
		}else
		{
			posicionACambiar = buscarIdC(varGeneral, len);
					if(posicionACambiar==-1)
					{
						printf("No se encontro el legajo, reintente");
					}else{
						printf("   Id    |      CUIL     |   Nombre    |   Apellido   \n");
						if(validarIntencionUsuarioC(varGeneral, posicionACambiar, "contribuyente", "modificar"))
						{

							printf("Desea modificar %s, [c]-CUIL, [n]-Nombre, [a]-Apellido: ",deseoModificar);
							if(cargarCaracter(&elegir)==0)
							{
								do
								{
									if(flagError)
									{
										flagError=0;
									}else
									{
										printf("ERROR. Escribio un caracter incorrecto, reintente.");
									}
									switch(elegir)
									{
										case 'c':
											printf("Ingrese un %s nuevo: ",mensajeOpcion1);
											if (cargarTexto(auxTexto))
											{
												if(validarCUIT(auxTexto, len))
												{
													strcpy(varGeneral[posicionACambiar].CUIL,auxTexto);
												}
												else
												{
													printf("No ingreso un CUIT correcto");
												}
											}
											break;
										case 'n':
											printf("Ingrese un %s nuevo: ",mensajeOpcion2);
											if (cargarTexto(auxTexto))
											{
												strcpy(varGeneral[posicionACambiar].nombre,auxTexto);
											}

											break;
										case 'a':
											printf("Ingrese un %s nuevo: ",mensajeOpcion3);
											if (cargarTexto(auxTexto))
											{
												strcpy(varGeneral[posicionACambiar].apellido,auxTexto);
											}
											break;
										default:
											printf("ERROR. No es una opcion valida");
											break;
									}
						}while(elegir == '0');
							}

				}
			}
		}

	}

	return funcionar;
}

///////////////////////////////////BUSQUEDA_INFORMACION////////////////////////////////////////////////

int mostrarEstructuraC(eContribuyentes varGeneral[],int i)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
	printf("  %-5d     %-15s  %-10s   %-10s   \n",varGeneral[i].idContribuyente,varGeneral[i].CUIL,varGeneral[i].nombre,varGeneral[i].apellido);
	}
	return funcionar;
}

int buscarIdC(eContribuyentes varGeneral[],int len)
{
	int posicion=-1;
	int i;
	int id;
	if(varGeneral != NULL)
	{
		printf("Ingrese id de contribuyente: ");
		cargarNumero(&id);
		for(i=0;i<len;i++)
		{
			if(varGeneral[i].isEmpty==0)
			{
				if(varGeneral[i].idContribuyente == id)
				{
					posicion = i;
					break;
				}
			}
		}
	}
	return posicion;
}

int buscarDescripcionC(eContribuyentes varGeneral[],int len)
{
	int id=-1;
	int i;
	char auxString[MAXCHAR];
	if(varGeneral != NULL)
	{
		printf("Escriba descripcion: ");
		scanf("%s",auxString);
		for(i=0;i<len;i++)
		{
			if(varGeneral[i].isEmpty==0)
			{
				if(strcmp(auxString,varGeneral[i].nombre)==0)
				{
					id = varGeneral[i].idContribuyente;
					break;
				}
			}
		}
	}

	return id;
}

int buscarVacioC(eContribuyentes varGeneral[],int len)
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

int validarIdC(eContribuyentes varGeneral[],int len,int numero)
{
	int funcionar=0;
	if(varGeneral != NULL)
	{
		for(int i=0;i<len;i++)
		{
			if (varGeneral[i].idContribuyente==numero)
			{
				funcionar=1;
				break;
			}
		}
	}
	return funcionar;
}

int validarIntencionUsuarioC(eContribuyentes varGeneral[],int posicionACambiar,const char * mensaje,const char * textoAValidar)
{
	int funcionar=0;
	char decidir;
	int sinError;
	if(varGeneral != NULL)
	{
		do
		{
			mostrarEstructuraC(varGeneral, posicionACambiar);
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

int validarEstructuraNoVaciaC(eContribuyentes varGeneral[],int len)
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

int inicializarisEmptyC(eContribuyentes varGeneral[],int len)
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

int ordenarPorIdC(eContribuyentes varGeneral[],int len)
{
	int funcionar=0;
	int flagNoOrdenado=1;
	int aux;
	char auxArrayTexto[MAXCHAR];
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
						aux=varGeneral[i].idContribuyente;
						varGeneral[i].idContribuyente=varGeneral[i-1].idContribuyente;
						varGeneral[i-1].idContribuyente=aux;

						strcpy(auxArrayTexto,varGeneral[i].nombre);
						strcpy(varGeneral[i].nombre,varGeneral[i-1].nombre);
						strcpy(varGeneral[i-1].nombre,auxArrayTexto);

						strcpy(auxArrayTexto,varGeneral[i].apellido);
						strcpy(varGeneral[i].apellido,varGeneral[i-1].apellido);
						strcpy(varGeneral[i-1].apellido,auxArrayTexto);

					}
				}
			}
			funcionar=1;
		}
	}
	return funcionar;
}
