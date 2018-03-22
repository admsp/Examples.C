// ============================================================================================
// Nombre: diccionario.h: 
// Descripci�n: 
// Librer�a global con las librer�as de negocio de la aplicaci�n de diccionario
// =============================================================================================

#pragma region Modelo de datos espec�fico

const int MAX_PAL = 100;
const int MAX_CAD = 20;

struct stpalabra {
	char ingles[MAX_CAD];
	char espanyol[MAX_CAD];
};

typedef stpalabra tPalabra;

#pragma endregion 

#pragma region Librer�as de Trabajo

// Metodos y Funciones de gesti�n del diccionario

// Nombre: anyadir_palabra
// Descripcion: 
int anyadir_palabra(tPalabra Diccionario[], int numpal);

#pragma endregion 
