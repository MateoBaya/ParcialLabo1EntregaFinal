#ifndef UTN_GENERAL_H_
#define UTN_GENERAL_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXCHAR 45

////////////////////////////////////////VALIDACIONES//////////////////////////////////////////
int distintoA0(int valor1);
/* @brief valida un numero distinto de 0
 * @param valor1 un numero entero obtenido por referencia
 * @return devuelve 0 si el numero es 0, sino 1
 */

int numeroPos(int val1);
/* @brief Confirma si valor1 es positivo, igual o mayor a 0
 * @param val1 un numero entero obtenido por referencia
 * @return El valor de return es 0 si el if dio negativo
 */

int numeroNeg(int val1);
/* @brief Confirma si valor1 es menor a 0, o sea negativo
 * @param un numero entero obtenido por referencia
 * @return El valor de return es 0 si el if dio negativo
 */

int mayor18Menor100(int val1);
/*@brief Confirma si valor1 es mayor a 18 y menor a 100 (IMPORTANTE AJUSTABILIDAD)
 * @param val1 un numero entero obtenido por referencia
 * @return El valor de return es 0 si el if dio negativo
 */

int valorConRango(int val1,int min,int max);
/* @brief Confirma si el valor1 es menor a un numero max y mayor a un numero min (GRAN ADAPTABILIDAD)
 * @param val1 es un numero entero obtenido por referencia
 * @param min es un numero entero obtenido por referencia que funciona como minimo
 * @param max es un numero entero obtenido por referencia que funciona como maximo
 * @return El valor de return es 0 si el if dio negativo
 */

int textoDeUsuarioLargoCorrecto(char texto1[],int largo);
/* @brief Confirma si el array texto1 tiene el largo correcto, avisandole al usuario si hubo error o no
 * @param texto1[] es un array de caracteres (TEXTO) obtenido por referencia
 * @param largo es un entero que funciona como limite maximo (ES UN LIMITE REAL, EL LIMITE IMPUESTO POR LA FUNCION ES MENOR)
 * @return El valor de return da 0 si tenia demasiados caracteres el texto
 */

int validarSoN(char respuesta);
/* @brief Confirma si el caracter es S o N, si no es ninguna, tira mensaje de error
 * @param respuesta es el caracter obtenido por referencia
 * @return El valor de return es 0 si el caracter no era ni N ni S
 */

int validarFMO(char respuesta);
/* @brief Confirma si el caracter es F/M/O, si no es ninguna, tira mensaje de error
 * @param respuesta es el caracter obtenido por referencia
 * @return El valor de return es 0 si el caracter no era ni F ni M ni O
 */

int validarNumeros(char numero[], int len);
/* @brief Confirma si todos los caracteres del array son numeros, incluye la posibilidad de un numero negativo
 * @param numero[] es el array de carateres obtenido por referencia
 * @param len sirve para las iteraciones del for
 * @return El valor de return es 0 si encuentra algun caracter no numero
 */

int validarFloat(char numero[], int len);

int validarChar(char caracter[], int len,int cantCaracteres,int * i);

int validarDNI(char array[],int len);

int validarCUIT(char array[],int len);

int validarMAIL(const char * array,int len);

////////////////////////////////////GENERAR U OBTENER DATOS//////////////////////////////////////

//MEJORAR OBTENER CHAR

int cargarCaracter(char * respuestaUsuario);
/* @brief Realiza un scanf que pide al usuario un caracter, lo pasa por validar caracter
 * @param respuestaUsuario es un puntero para guardar la respuesta
 * @return error es una variable que se vuelve 0 si hubo 0 problemas en la funcion y validacion
 */

int cargarNumero(int * numeroFinal);
/* @brief Pide al usuario un ingreso de caracteres, llama a validarNumeros(), si da error se lo dice al usuario
 * @param *numeroFinal es un puntero para guardar el numero como valor entero por referencia
 * @return el valor es 0 si no ocurrio ningun error (si el valor es un numero decimal)
 */

int cargarTexto(char texto[]);

int cargarFloat(float * numeroFinal);

void inicioEntero(int array[], int len);
/*
* brief ingresa 0 a todas las posiciones del array
* param array[] funciona de puntero a el array ingresado entero
* param len es el largo del array
*/

void inicioFloat(float array[], int len);
/*
* brief ingresa 0 a todas las posiciones del array float
* param array[] funciona de puntero a el array ingresado float
* param len es el largo del array
*/

void inicioChar(char array[],int len);
/*
 * brief ingresa ' ' a todas las posiciones del array
 * param array[] funciona de puntero a el array ingresado char
 * param len es el largo del array
 */

void inicioCharMatriz(char array[][MAXCHAR], int len);
/*
 * brief ingresa espacio vacio a todas las posiciones de la matriz con un strcpy
 * param array[][] funciona de puntero a la matriz ingresada
 * param len es la cantidad de posiciones de la matriz en un eje, el mismo
 */

void primerLetraMayuscula(char array[]);

#endif /* UTN_GENERAL_H_ */
