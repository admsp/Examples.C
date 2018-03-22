// ============================================================================================
// Nombre: diccionario.h: 
// Descripción: 
// Librería global con las librerías de negocio de la aplicación de diccionario
// =============================================================================================

#pragma region Modelo de datos específico

const int MAX_PAL = 100;
const int MAX_CAD = 20;

struct stpalabra {
	char ingles[MAX_CAD];
	char espanyol[MAX_CAD];
};

typedef stpalabra tPalabra;

#pragma endregion 

#pragma region Librerías de Trabajo

// Metodos y Funciones de gestión del diccionario

// Nombre: anyadir_palabra
// Descripcion: 
int anyadir_palabra(tPalabra Diccionario[], int numpal);

#pragma endregion 
