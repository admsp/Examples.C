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

// Constantes de tamaño de cadena de palabra
const int MAX_PAL = 100;
const int MAX_CAD = 20;

// Enumerado base de gestión de Menús
enum eMenuType {
	PRINCIPAL,
	PRINCIPAL_ERROR,
	PRINCIPAL_DESPEDIDA,
	ANYADIRPALABRA_ESPAÑOL,
	ANYADIRPALABRA_INGLES,
	ANYADIRPALABRA_SALIDA_MOSTRAR,
	ANYADIRPALABRA_SALIDA_MAXCAR_MOSTRAR,
	ANYADIRPALABRA_SALIDA_CANCELAR,
	TRADUCIR,
};

// Tipo de negocio para el tratamiento de tipos de menús
typedef eMenuType tMenuType;

// Estructura de negocio para implementación de diccionario
struct stpalabra {
	char ingles[MAX_CAD];
	char espanyol[MAX_CAD];
}; 

// Tipo de negocio para gestión de la estructura base de diccionario
typedef stpalabra tPalabra;

#pragma endregion 

#pragma region Librerías de Trabajo

// Metodos y Funciones de gestión del diccionario

// Nombre: MenuManager
// Descripcion: Metodo de negocio para la gestión de Menús de Diccionario 
void MenuManager(tMenuType pType, char pString[]);

// Nombre: anyadir_palabra
// Descripcion: Metodo de negocio para la gestión de inserciones en el diccionario 
int anyadir_palabra(tPalabra Diccionario[], int numpal);

// Nombre: traducir_palabra
// Descripcion: Metodo de negocio para la gestión de traducciones en el diccionario 
void traducir_palabra(tPalabra Dicc[], int num);

#pragma endregion 
