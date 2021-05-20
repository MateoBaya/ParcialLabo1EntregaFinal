#include "utn_general.h"

////////////////////////////////////////VALIDACIONES//////////////////////////////////////////

int distintoA0(int valor1)
{
	int funcionar=0;
	if (valor1 != 0)
	{
		funcionar = 1;
	}
	return funcionar;
}

int numeroPos(int val1)
{
	int funcionar=0;
	if (val1 >=0)
	{
		funcionar = 1;
	}
	return funcionar;
}

int numeroNeg(int val1)
{
	int funcionar=0;
	if (val1 < 0)
	{
		funcionar = 1;
	}
	return funcionar;
}

int mayor18Menor100(int val1)
{
	int funcionar=0;
	if (val1>=18 && val1<100)
	{
		funcionar =1;
	}
	return funcionar;
}

int valorConRango(int val1,int min,int max)
{
	int funcionar=0;
	if(val1<=max && val1>=min)
	{
		funcionar=1;
	}
	return funcionar;
}

int textoDeUsuarioLargoCorrecto(char texto1[],int largo)
{
	int funcionar=0;
	int auxTam=largo-3;

	if(strlen(texto1) > auxTam)
	{
		printf("ERROR. Demasiados caracteres\n");
	}else
	{
		funcionar = 1;
	}

	return funcionar;
}

int validarSoN(char respuesta)
{
	int funcionar=0;
	if (respuesta == 's' || respuesta == 'n')
	{
		funcionar = 1;
	}
	if(funcionar==0)
	{
		printf("ERROR. Caracter no valido, reingrese\n");
	}
	return funcionar;
}

int validarFMO(char respuesta)
{
	int funcionar=0;
	if(respuesta =='f' || respuesta =='m'|| respuesta =='o')
	{
		funcionar=1;
	}
	if(funcionar==0)
	{
		printf("ERROR. Caracter no valido, reingrese\n");
	}

	return funcionar;
}

int validarNumeros(char numero[], int len)
{
	int funcionar=0;
	int auxAcum=0;
	int flagNegativo=1;
	int i;


	if(numero != NULL)
	{

		for(i=0; i<len; i++)
				{

					if(isdigit(numero[i]))
					{
						auxAcum++;
					}else if(numero[0] == '-' && flagNegativo)
					{
						auxAcum++;
						flagNegativo=0;
					}else
					{
						break;
					}
				}

		if(strlen(numero)==auxAcum)
		{
			funcionar=1;
		}
	}

	return funcionar;
}

int validarChar(char caracter[], int len,int cantCaracteres,int * i)
{
	int funcionar=0;
		int auxAcum=0;

		if(caracter != NULL)
		{
			for(*i=0; *i<len; i++)
					{
						if(isalpha(caracter[*i]))
						{
							auxAcum++;
							if(auxAcum==cantCaracteres)
							{
							break;
							}
						}else
						{
							break;
						}
					}


			if(strlen(caracter)==auxAcum)
			{
				funcionar=1;
			}
		}
		return funcionar;
}

int validarFloat(char numero[], int len)
{
	int funcionar=0;
	int auxAcum=0;
	int flagNegativo=1;
	int flagPunto=1;
	int i;

	if(numero != NULL)
	{

		for(i=0; i<len; i++)
				{

					if(isdigit(numero[i]))
					{
						auxAcum++;
					}else if(numero[0] == '-' && flagNegativo)
					{
						auxAcum++;
						flagNegativo=0;
					}else if(numero[i] == '.' && flagPunto)
					{
						auxAcum++;
						flagPunto=0;
					}else
					{
						break;
					}
				}

		if(strlen(numero)==auxAcum)
		{
			funcionar=1;
		}
	}
	return funcionar;
}

int validarDNI(char array[],int len)
{
	int funcionar=0;
	int acumFuncionando=0;
	int flagPrimerPunto=1;
	int flagSegundoPunto=1;


	for(int i=0;i<len;i++)
	{
		if(isdigit(array[i]))
		{
			acumFuncionando++;
		}else if(array[2]=='.' && flagPrimerPunto)
		{
			acumFuncionando++;
			flagPrimerPunto=0;
		}else if(array[6]=='.' && flagSegundoPunto)
		{
			acumFuncionando++;
			flagSegundoPunto=0;
		}else
		{
			break;
		}
	}

	if(acumFuncionando==10)
	{
		funcionar=1;
	}

	return funcionar;
}

int validarCUIT(char array[],int len)
{
	int funcionar=0;
	int acumFuncionando=0;
	int flagPrimerGuion=1;
	int flagSegundoGuion=1;


	for(int i=0;i<len;i++)
	{
		if(isdigit(array[i]))
		{
			acumFuncionando++;
		}else if(array[2]=='-' && flagPrimerGuion)
		{
			acumFuncionando++;
			flagPrimerGuion=0;

		}else if(array[11]=='-' && flagSegundoGuion)
		{
			acumFuncionando++;
			flagSegundoGuion=0;

		}else
		{
			break;
		}
	}

	if(acumFuncionando==13)
	{
		funcionar=1;
	}

	return funcionar;
}

int validarMAIL(const char * array,int len)
{
	int funcionar=0;
	int acumFuncionando=0;
	int i;
	int j=0;
	char auxTexto[MAXCHAR];
	int flagPasadaArroba=0;

	for(i=0;i<len;i++)
	{
		if(isgraph(array[i]))
		{
			acumFuncionando++;
			if(array[i]=='@' || flagPasadaArroba)
			{
				flagPasadaArroba=1;
				auxTexto[j]=array[i];

				j++;
			}
		}else if(isalnum(array[i])==0)
		{
			break;
		}
	}

	/*if(strcmp(auxTexto,"@gmail.com")==0)
	{
		funcionar=1;
	}else */if(strcmp(auxTexto,"@hotmail.com")==0)
	{
		funcionar=1;
	}else if(strcmp(auxTexto,"@outlook.com")==0)
	{
		funcionar=1;
	}

	return funcionar;
}

////////////////////////////////////GENERAR U OBTENER DATOS//////////////////////////////////////

int cargarCaracter(char * respuestaUsuario)
{
	int error;
	char caracter[MAXCHAR];
	int i;
	fflush(stdin);
	scanf("%s",caracter);

	if(validarChar(caracter, MAXCHAR, 1, &i)==0)
	{
		printf("ERROR. No escribio un caracter\n");
	}else
	{
		error=0;
		*respuestaUsuario = caracter[i];
	}
	return error;
}

int cargarNumero(int * numeroFinal)
{
int error;
char numero[MAXCHAR];

	fflush(stdin);
	scanf("%s",numero);

	if(validarFloat(numero, MAXCHAR)==0)
	{
		printf("ERROR. No escribio un numero\n");
	}else
	{
		error=0;
		*numeroFinal=atoi(numero);
	}

return error;
}

int cargarTexto(char texto[])
{
	int funcionar=0;
	char auxtexto[MAXCHAR];
	if(texto != NULL)
	{
		fflush(stdin);
		fgets(auxtexto,MAXCHAR,stdin);
		if(auxtexto[strlen(auxtexto)-1]=='\n')
		{
			auxtexto[strlen(auxtexto)-1]='\0';
		}
		if (textoDeUsuarioLargoCorrecto(auxtexto, MAXCHAR))
		{
		strcpy(texto,auxtexto);
		funcionar=1;
		}
	}
	return funcionar;
}

int cargarFloat(float * numeroFinal)
{
	int error;
	char numero[MAXCHAR];

		fflush(stdin);
		scanf("%s",numero);

		if(validarFloat(numero, MAXCHAR)==0)
		{
			printf("ERROR. No escribio un numero\n");
		}else
		{
			error=0;
			*numeroFinal=atof(numero);
		}

	return error;
}

void inicioEntero(int array[], int len)
{
	if(array != NULL)
	{
		for(int i=0;i<len;i++)
		{
			array[i] = 0;
		}
	}
}

void inicioFloat(float array[], int len)
{
	if(array != NULL)
	{
		for(int i=0;i<len;i++)
			{
				array[i] = 0;
			}
	}
}

void inicioChar(char array[], int len)
{
	if(array != NULL)
	{
		for(int i=0;i<len;i++)
			{
				array[i] = ' ';
			}
	}
}

void inicioCharMatriz(char array[][MAXCHAR], int len)
{
	if(array != NULL)
	{
		for(int i=0;i<len;i++)
		{
			strcpy(array[i],"");
		}
	}
}

void primerLetraMayuscula(char array[])
{
	if(array != NULL)
	{
		strlwr(array);
		array[0]=toupper(array[0]);
	}
}
