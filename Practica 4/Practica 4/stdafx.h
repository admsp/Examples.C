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

#pragma region Area de declaración de variables/literales/constantes globales

// Teclas de aplicación
#define ENTER			13
#define ESP				32
#define ESC				27
#define EOL	            '\0'
#define DEL				8

#pragma endregion 