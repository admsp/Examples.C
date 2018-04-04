// ============================================================
// Nombre: Menu.cpp 
// Descripción: 
// Tercera práctica de Programación de 1º de Teleco UA.
// Objetivo: Se divide en dos partes:
//			 a. Funciones Matemáticas
//			 b. Funciones con Arrays
// ============================================================

#pragma region Librerías de Programa

// Invocación de la Librería de agrupación de librerías base Standard para la aplicación.
#include "Menu.h"
#include "Funciones.h"

#pragma endregion

#pragma region Variables Globales 

// No Aplica

#pragma endregion

#pragma region Declaracion de Metodos y Funciones de Programa

// Nombre: MainMenuManager
// Descripcion: Metodo de negocio para la gestión de Menús de Diccionario
void MenuManager(eMenusMessages eType, char pString[]);

// Nombre: LeerOpcionNumerica
// Descripción: Lee la opcion seleccionada por el usuario para el menú numerico principal
// Salida: Contempla las siguientes salidas: 
//			NULL				Opción no soportada
//			pValorSeleccionado  Opción seleccionada entre los valores máximo y mínimo indicado
//			pValorSalida        Opcion de salida seleccionada o ESC pulsado
char LeerOpcionNumerica(char pValorMin, char pValorMax, char pValorSalida);

// Nombre: LeerNumero
// Descripcion: Metodo de negocio para la lectura de numeros desde consola.
//			    Solo admite caracteres numéricos.
// Salida: >=0 Numero obtenido tras pulsar ENTER. 
//		   -1 En caso de cancelación (ESC).
//         -2 Cadena vacia.
int LeerNumero();

// Nombre: fMatematicaManager
// Descripción: Gestiona las opciones de la práctica de Matemáticas
// Salida: Contempla las siguientes salidas: 
//			-1   				Cancelación
//			1					Finalización correcta
int fMatematicaManager();

// Nombre: fMatematicaPotencia
// Descripción: Gestiona el calculo de potencia
// Salida: Contempla las siguientes salidas: 
//			-1   				Incorrecta
//			0					Cancelación
//			2					Correcta
int fMatematicaPotencia();

// Nombre: fArrayManager
// Descripción: Gestiona las opciones de la práctica de Arrays
// Salida: Contempla las siguientes salidas: 
//			-1   				Cancelación
//			2					Finalización correcta
int fArrayManager();

#pragma endregion

#pragma region Ciclo de Vida

// Descripción: Programa Principal Practica 3 UAH
// Entrada: none
// Salida:	> 0 Correcta
//			0 Cancelación
//			-1 Incorrecto (no debe darse)
int main() {
	
	// Declaración e Inicialización de Variables
	int iResult;
	char cOptionSelected;
	
	// Inicialización de variables globales
	cOptionSelected = NULL;
	iResult = -1;

	// Inicialización de variables
	do {
		// Mostrar menu de opciones
		MenuManager(PRINCIPAL, nullptr);

		// Leer de pantalla
		cOptionSelected = LeerOpcionNumerica(OPT_PRINCIPAL_MATEMATICA, 
											 OPT_PRINCIPAL_ARRAYS, 
											 OPT_PRINCIPAL_SALIDA);
		
		// Validar caracter
		switch (cOptionSelected) {
			case OPT_PRINCIPAL_MATEMATICA:
				fMatematicaManager();
				break;
			case OPT_PRINCIPAL_ARRAYS:
				fArrayManager();
				break;
			default:
				// Mostramos mensaje correspondiente
				if (cOptionSelected == OPT_PRINCIPAL_SALIDA) {
					MenuManager(PRINCIPAL_DESPEDIDA, nullptr);
					iResult = 0;
				}
				else MenuManager(GLOBAL_ERROR, nullptr);
				
				// Recogemos tecla pulsada
				_getch();

			break;
		}
		
	} while (cOptionSelected != OPT_PRINCIPAL_SALIDA);

	// Retorno de datos
	return iResult;
}

#pragma endregion

#pragma region Metodos y funciones de Gestion de Practica de Funciones Matemáticas

// Nombre: fMatematicaManager
// Descripción: Gestiona las opciones de la práctica de Matemáticas
// Salida: Contempla las siguientes salidas: 
//			-1   				Incorrecta
//			0					Cancelación
//			2					Correcta
int fMatematicaManager() {

	// Declaración de Variables
	int iResult;
	char cOptionSelected;
	
	// Inicialización de variables globales
	cOptionSelected = NULL;
	iResult = -1;

	// Inicialización de variables
	do {
		// Mostrar menu de opciones
		MenuManager(MATEMATICA, nullptr);

		// Leer de pantalla
		cOptionSelected = LeerOpcionNumerica(OPT_MATEMATICA_POTENCIA, OPT_MATEMATICA_FACTORIAL_RECURSIVO, OPT_MATEMATICA_SALIDA);

		// Validar caracter
		switch (cOptionSelected) {
		case OPT_MATEMATICA_POTENCIA:
			fMatematicaPotencia();
			iResult = 2;
			break;
		case OPT_MATEMATICA_FACTORIAL:
			// TODO
			iResult = 2;
			break;
		case OPT_MATEMATICA_FACTORIAL_RECURSIVO:
			// TODO
			iResult = 2;
			break;
		default:
			// Mostramos mensaje correspondiente
			if (cOptionSelected == OPT_MATEMATICA_SALIDA) { 
				MenuManager(PARCIAL_DESPEDIDA, nullptr);
				iResult = 0;
			}
			else MenuManager(PARCIAL_ERROR, nullptr);

			// Recogemos tecla pulsada
			_getch();

			break;
		}

	} while (cOptionSelected != OPT_PRINCIPAL_SALIDA);

	// Retorno de datos
	return iResult;
}

// Nombre: fMatematicaPotencia
// Descripción: Gestiona el calculo de potencia
// Salida: Contempla las siguientes salidas: 
//			-1   				Incorrecta
//			0					Cancelación
//			2					Correcta
int fMatematicaPotencia() {

	// Declaración de Variables
	int iResult;
	char cKey;

	// Inicialización de variables globales
	cKey = NULL;
	iResult = -1;

	// Inicialización de variables
	do {
		// Mostrar menu de presentacion
		MenuManager(tMenusMessages::MATEMATICA_POTENCIA, nullptr);

		// Leer de pantalla
		cKey = _getch();

		// Capturar la opción selecionada y Validar caracter
		if (cKey == ESC) 
			// Solicitada salida
			iResult = 0;
		else {
			// Declaracion de variables
			int iBase, iExponente;
			
			// Obtener la base
			do {
				// Mostrar menu de solicitud de datos de 
				MenuManager(tMenusMessages::MATEMATICA_POTENCIA_BASE, nullptr);
				
				// Leer base numérica 
				iBase = LeerNumero();

				// TODO Validar numero recibido
			}
			while (cKey != OPT_MATEMATICA_POTENCIA_SALIDA);

			// Obtener el exponente
			iExponente = 2;

			// Calcular resultado
			iResult = potencia(iBase, iExponente);


		}
	} while (cKey != OPT_MATEMATICA_POTENCIA_SALIDA);

	// Retorno de datos
	return iResult;
}

#pragma endregion

#pragma region Metodos y funciones de Gestion de Practica de Arrays

// Nombre: fArrayManager
// Descripción: Gestiona las opciones de la práctica de Arrays
// Salida: Contempla las siguientes salidas: 
//			-1   				Incorrecta
//			0					Cancelación
//			2					Correcta
int fArrayManager() {

	// Declaración de Variables
	int iResult;

	// Inicialización de variables
	iResult = 0;

	// Gestión de Opciones de Menu

	// Retorno por defecto
	return iResult;
}

#pragma endregion

#pragma region Metodos y funciones auxiliares 

// Nombre: MainMenuManager
// Descripcion: Metodo de negocio para la gestión de Menús de Diccionario
void MenuManager(eMenusMessages pType, char pString[]) {

	// Limpieza de pantalla
	system("cls");

	// Validar tipo de Menu a mostrar
	switch (pType) {
		case PRINCIPAL:
			// Mostrar menu de opciones
			printf("==============================================================================\n");
			printf("= Elija una de las siguientes opciones:                                      =\n");
			printf("=                                                                            =\n");
			printf("=  1. Practica de Operaciones Matematicas                                    =\n");
			printf("=  2. Practica de Operaciones con Arrays                                     =\n");
			printf("=  3. Salir                                                                  =\n");
			printf("=                                                                            =\n");
			printf("= Pulse una opcion o Esc para salir...                                       =\n");
			printf("==============================================================================\n");

			break;
		case MATEMATICA:
			printf("==============================================================================\n");
			printf("= Elija una de las siguientes opciones:                                      =\n");
			printf("=                                                                            =\n");
			printf("= 1. Calcular la potencia                                                    =\n");
			printf("= 2. Calcular numero del factorial                                           =\n");
			printf("= 3. Calcular numero del factorial (Recursivo)                               =\n");
			printf("= 4. Salir                                                                   =\n");
			printf("=                                                                            =\n");
			printf("= Pulse una opcion o Esc para salir...                                       =\n");
			printf("==============================================================================\n");

			break;
		case MATEMATICA_POTENCIA:
			printf("==============================================================================\n");
			printf("= La presente opción calcula la potencia de un número dada la base y el      =\n");
			printf("= exponente del mismo.                                                       =\n");
			printf("=                                                                            =\n");
			printf("= Pulse una tecla para continuar o Esc para salir...                         =\n");
			printf("==============================================================================\n");

			break;
		case MATEMATICA_POTENCIA_BASE:
			printf("==============================================================================\n");
			printf("= Introduzca un valor para la Base. Pulse una opcion o Esc para salir...     =\n");
			printf("==============================================================================\n");
			printf("                                                                              \n");
			printf("  Valor de Base: ");

			break;
		case MATEMATICA_POTENCIA_EXPONENTE:
			printf("==============================================================================\n");
			printf("= Introduzca un valor para el Exponente. Pulse una opcion o Esc para salir...=\n");
			printf("==============================================================================\n");
			printf("                                                                              \n");
			printf("  Valor de Exponente: ");

			break;
		case MATEMATICA_POTENCIA_RESULTADO:
			printf("==============================================================================\n");
			printf("= El valor resultante es: %s. 	                                             =\n", pString);
			printf("= Pulse una opcion o Esc para salir...                                       =\n");
			printf("==============================================================================\n");
			
			break;
		case PARCIAL_DESPEDIDA:
			// Cargar mensaje
			printf("==============================================================================\n");
			printf("= Solicitada salida. Se retorna al menú principal.                           =\n");
			printf("= Pulse una tecla para continuar...                                          =\n");
			printf("==============================================================================\n");
			
			break;
		case PRINCIPAL_DESPEDIDA:
			// Cargar mensaje
			printf("==============================================================================\n");
			printf("= Gracias por usar nuestra aplicacion. Vuelva pronto...                      =\n");
			printf("= Pulse una tecla para salir...                                              =\n");
			printf("==============================================================================\n");

			break;
		case GLOBAL_ERROR:
			// Cargar mensaje
			printf("==============================================================================\n");
			printf("= La opcion seleccionada es incorrecta. Pulse una tecla para continuar...    =\n");
			printf("==============================================================================\n");

		default: /* Nota: Este caso no debería ocurrir */ break;
	}
}

// Nombre: LeerOpcionNumerica
// Descripción: Lee la opcion seleccionada por el usuario para el menú numerico principal
// Salida: Contempla las siguientes salidas: 
//			NULL				Opción no soportada
//			pValorSeleccionado  Opción seleccionada entre los valores máximo y mínimo indicado
//			pValorSalida        Opcion de salida seleccionada o ESC pulsado
char LeerOpcionNumerica(char pValorMin, char pValorMax, char pValorSalida) {

	// Declaración e Inicialización de Variables
	char cReturn;
	char cKey;

	// Inicialización de variables
	cKey = NULL;

	// Proceso de Lectura, Validación y Almacenamiento desde Pantalla
	do {
		// Leer de pantalla
		cKey = _getch();

		// Capturar la opción selecionada y Validar caracter
		if ((cKey == ESC) || (cKey == pValorSalida)) cReturn = pValorSalida;
		else if ((cKey >= pValorMin) && (cKey <= pValorMax)) cReturn = cKey;
		else cReturn = NULL;

	} while (cKey == NULL);

	// Retorno Standard
	return cReturn;
}

// Nombre: LeerNumero
// Descripcion: Metodo de negocio para la lectura de numeros desde consola.
//			    Solo admite caracteres numéricos.
// Salida: >=0 Numero obtenido tras pulsar ENTER. 
//		   -1 En caso de cancelación (ESC).
//         -2 Cadena vacia.
int LeerNumero () {

	// Declaración e Inicialización de Variables
	int iReturn;
	int iTam;
	char *strNumber;

	// Inicialización de variables
	iReturn = -1;
	iTam = 0;
	strNumber = NULL;

	// Proceso de Lectura, Validación y Almacenamiento desde Pantalla
	for (char cKey = NULL; ((cKey != ESC) || (cKey != ENTER));) {

		// Leer caracter de pantalla
		cKey = _getch();

		// Capturar la opción seleccionada y Validar caracter
		switch (cKey) {
		case ENTER:
			// Validamos el tamaño actual 
			if (iTam == 0)
				// Cargar la salida con el valor de número erroneo
				iReturn = -2;
			else if (iTam > 0) {
				// Cargar la salida standard con el valor del numero obtenido 
				strNumber = &strNumber[0];  // 1. Apuntar al primer elemento
				iReturn = atoi(strNumber);	// 2. Obtener número
			}
			
			break;
		case DEL:
			// Validar que haya algún caracter introducido
			if (iTam > 0) {
				// Disminuir tamaño
				iTam--;

				// Redimensionar el array
				strNumber = (char*)realloc(strNumber, sizeof(char)*iTam);

				// Retroceder un caracter y mover el cursor hacia atrás
				printf("%c", cKey);
				printf("%c", ESP);
				printf("%c", cKey);
			}

			break;
		case ESC:
			// Asignamos el valor de salida por cancelación
			iReturn = -1;
			break;
		default:
			// Validar que sea un numero
			if (cKey >= '0' && cKey <= '9') {

				// Aumentamos el tamaño del array
				iTam++;

				// Validamos el tamaño del array y actualizamos su dimensionamiento
				if (strNumber != NULL && strlen(strNumber) != 0)
					// array no vacio
					strNumber = (char*)realloc(strNumber, sizeof(char)*iTam);
				else 
					// array vacio
					strNumber = (char*)malloc(sizeof(char)*iTam);
				
				// Añadimos el nuevo elemento al array
				strNumber[iTam - 1] = cKey;

				// Mostramos el caracter por pantalla
				printf("%c", cKey);
			}

			break;
		}
	}

	// Limpiar arrays
	free(strNumber);

	// Retorno Standard
	return iReturn;
}

#pragma endregion 