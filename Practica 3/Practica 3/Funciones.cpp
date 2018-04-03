// ============================================================================================
// Nombre: funciones.cpp: 
// Descripci�n: 
// Librer�a espec�fica de aplicaci�n espec�fica para tratamiento de proyecto.
// =============================================================================================

#pragma region Librer�as de trabajo

// Librer�as base de aplicaci�n
#include "Menu.h"

// Librerias de Tratamiento de funciones matematicas
#include <math.h>

#pragma endregion

#pragma region Area de declaraci�n de variables/literales/constantes globales

// No aplica para la actual biblioteca

#pragma endregion 

#pragma region Modelo de datos espec�fico

// No aplica para la actual biblioteca

#pragma endregion 

#pragma region Metodos y Funciones de gesti�n del programa

// Nombre: potencia
// Descripcion: Metodo de para la obtenci�n de la potencia dado un n�mero y su exponente
// Entrada: base, exponente
// Salida: -1 si valores introducidos incorrectos
//          0 > si valores introducidos correctos
int potencia(int base, int exponente) {

	// Variables locales
	int iResult = -1;

	// Validaci�n de parametros de entrada
	if ((base >= 0) && (exponente >= 0)) {

		// Calculo de Potencia
		if (exponente == 0) iResult = 1;
		else {
			iResult = base;
			for (int i = 1; i < exponente; i++) iResult *= base;
		}
	}

	// Retorno de datos
	return iResult;
}

// Nombre: factorial
// Descripcion: Metodo de para la obtenci�n del factorial de un numero
// Entrada: numero
// Salida: -1 si valores introducidos incorrectos
//          0 > si valores introducidos correctos
int factorial(int numero) {

	// Variables locales
	int iResult = -1;

	// Validaci�n de parametros de entrada
	if (numero >= 0) {

		// Inicializaci�n de variables
		iResult = numero;

		// Calculo de Factorial
		if (numero > 1) for (int i = 1; i < numero; i++) iResult = iResult * i;
	}

	// Retorno de datos
	return iResult;
}

// Nombre: factorialRecursivo
// Descripcion: Metodo de para la obtenci�n del factorial de un numero
// Entrada: numero
// Salida: -1 si valores introducidos incorrectos
//          0 > si valores introducidos correctos
int factorialRecursivo(int numero) {

	// Variables locales
	int iResult;

	// Calculo de Factorial
	if (numero < 0) iResult = -1;
	else if ((numero == 0) || (numero == 1)) iResult = numero;
	else iResult = (numero * factorialRecursivo(numero - 1));

	// Retorno de datos por defecto
	return iResult;
}

#pragma endregion 
