// ============================================================================================
// Nombre: stdafx.h: 
// Descripci�n: 
// Librer�a global con las librer�as standard del sistema y otros espec�ficos del proyecto.
// =============================================================================================

#pragma region Librer�as de Trabajo

// Librer�a para de funciones matematicas
#include <math.h>

#pragma endregion

#pragma region Librer�as de Trabajo

// Nombre: potencia
// Descripcion: Metodo de para la obtenci�n de la potencia dado un n�mero y su exponente
// Entrada: base, exponente
// Salida: -1 si valores introducidos incorrectos
//          0 > si valores introducidos correctos
int potencia(int base, int exponente); 

// Nombre: factorial
// Descripcion: Metodo de para la obtenci�n del factorial de un numero
// Entrada: numero
// Salida: -1 si valores introducidos incorrectos
//          0 > si valores introducidos correctos
int factorial(int numero);

// Nombre: factorialRecursivo
// Descripcion: Metodo de para la obtenci�n del factorial de un numero
// Entrada: numero
// Salida: -1 si valores introducidos incorrectos
//          0 > si valores introducidos correctos
int factorialRecursivo(int numero);

#pragma endregion
