// ============================================================================================
// Nombre: stdafx.h: 
// Descripción: 
// Librería global con las librerías standard del sistema y otros específicos del proyecto.
// =============================================================================================

#pragma region Librerías de Trabajo

// Librería para de funciones matematicas
#include <math.h>

#pragma endregion

#pragma region Librerías de Trabajo

// Nombre: potencia
// Descripcion: Metodo de para la obtención de la potencia dado un número y su exponente
// Entrada: base, exponente
// Salida: -1 si valores introducidos incorrectos
//          0 > si valores introducidos correctos
int potencia(int base, int exponente); 

// Nombre: factorial
// Descripcion: Metodo de para la obtención del factorial de un numero
// Entrada: numero
// Salida: -1 si valores introducidos incorrectos
//          0 > si valores introducidos correctos
int factorial(int numero);

// Nombre: factorialRecursivo
// Descripcion: Metodo de para la obtención del factorial de un numero
// Entrada: numero
// Salida: -1 si valores introducidos incorrectos
//          0 > si valores introducidos correctos
int factorialRecursivo(int numero);

#pragma endregion
