// ============================================================================================
// Nombre: stdafx.h: 
// Descripción: 
// Librería global con las librerías standard del sistema y otros específicos del proyecto.
// =============================================================================================

#pragma region Librerías de Trabajo

// Librería para determinar el uso de la versión más reciente de Windows
#include "targetver.h"

// Librerías standard del sistema

// Funciones base
#include <stdlib.h>

// Tratamiento de entrada y salida
#include <stdio.h>
#include <conio.h>

// Tratamiento de caracteres y cadenas
#include <tchar.h>
#include <string.h>

// Tratamiento de funciones matematicas
#include <math.h>

#pragma endregion

// ============================================================================================
// Nombre: diccionario.h: 
// Descripción: 
// Librería global con las librerías de negocio de la aplicación de diccionario
// =============================================================================================

#pragma region Area de declaración de variables/literales/constantes globales

// Teclas de aplicación
#define ENTER			13
#define ESP				32
#define ESC				27
#define EOL	            '\0'
#define DEL				8

#pragma endregion 

#pragma region Modelo de datos específico

// Enumerado base de gestión de Menús
enum eMainMenuType {
	PRINCIPAL,
	PRINCIPAL_ERROR,
	PRINCIPAL_DESPEDIDA
};

// Tipo de negocio para el tratamiento de tipos de menús
typedef eMainMenuType tMainMenuType;

#pragma endregion 

#pragma region Librerías de Trabajo

// Metodos y Funciones de gestión del programa

// Nombre: MainMenuManager
// Descripcion: Metodo de negocio para la gestión de Menús de Diccionario
void MainMenuManager(tMainMenuType pType, char pString[]);

// Nombre: LeerOpcionNumerica
// Descripción: Lee la opcion seleccionada por el usuario dentro de un menú numerico
// Salida: Opcion seleccionada 
int LeerOpcionNumerica(int pValorMin, int pValorMax);

#pragma endregion 


