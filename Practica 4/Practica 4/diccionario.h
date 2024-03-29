// ============================================================================================
// Nombre: diccionario.h: 
// Descripci�n: 
// Librer�a global con las librer�as de negocio de la aplicaci�n de diccionario
// =============================================================================================

#pragma region Area de declaraci�n de variables/literales/constantes globales

// Teclas de aplicaci�n
#define ENTER			13
#define ESP				32
#define ESC				27
#define EOL	            '\0'
#define DEL				8

#pragma endregion 

#pragma region Modelo de datos espec�fico

// Constantes de tama�o de cadena de palabra
const int MAX_PAL = 100;
const int MAX_CAD = 20;

// Enumerado base de gesti�n de Men�s
enum eMenuType {
	PRINCIPAL,
	PRINCIPAL_ERROR,
	PRINCIPAL_DESPEDIDA,
	ANYADIRPALABRA_ESPA�OL,
	ANYADIRPALABRA_INGLES,
	ANYADIRPALABRA_SALIDA_MOSTRAR,
	ANYADIRPALABRA_SALIDA_MAXCAR_MOSTRAR,
	ANYADIRPALABRA_SALIDA_CANCELAR,
	TRADUCIR_BUSCAR,
	TRADUCIR_SALIDA_MOSTRAR_RESULTADO,
	TRADUCIR_SALIDA_MOSTRAR_NO_ENCONTRADO,
	TRADUCIR_SALIDA_PALABRA_VACIA,
	TRADUCIR_SALIDA_CANCELAR,
	MOSTRAR_DICCIONARIO_VACIO,
	BORRAR_ELEMENTO_SALIDA_DICCIONARIO_VACIO,
	BORRAR_ELEMENTO_BUSCAR_ELEMENTO,
	BORRAR_ELEMENTO_SALIDA_NO_ENCONTRADO,
	BORRAR_ELEMENTO_SALIDA_ENCONTRADO,
	BORRAR_ELEMTENTO_SALIDA_PALABRA_VACIA,
	BORRAR_ELEMTENTO_SALIDA_CANCELAR
};

// Tipo de negocio para el tratamiento de tipos de men�s
typedef eMenuType tMenuType;

// Estructura de negocio para implementaci�n de diccionario
struct stpalabra {
	char ingles[MAX_CAD];
	char espanyol[MAX_CAD];
}; 

// Tipo de negocio para gesti�n de la estructura base de diccionario
typedef stpalabra tPalabra;

#pragma endregion 

#pragma region Librer�as de Trabajo

// Metodos y Funciones de gesti�n del diccionario

// Nombre: MenuManager
// Descripcion: Metodo de negocio para la gesti�n de Men�s de Diccionario 
void MenuManager(tMenuType pType, char pString[]);

// Nombre: anyadir_palabra
// Descripcion: Metodo de negocio para la gesti�n de inserciones en el diccionario 
int anyadir_palabra(tPalabra Diccionario[], int numpal);

// Nombre: traducir_palabra
// Descripcion: Metodo de negocio para la gesti�n de traducciones en el diccionario 
void traducir_palabra(tPalabra Dicc[], int num);

// Nombre: mostrar_diccionario
// Descripcion: Metodo de negocio para la mostrar el contenido del diccionario
void mostrar_diccionario(tPalabra Dicc[], int num);

// Nombre: borrar_palabra
// Descripcion: Metodo de negocio para el borrado de palabras dentro del dicccionario
int borrar_palabra(tPalabra Dicc[], int num);

#pragma endregion 
