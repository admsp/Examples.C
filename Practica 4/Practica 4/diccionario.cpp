// Nombre: diccionario.h
// Descripción: Librería de gestión de Diccionario
// Nota: 

#pragma region Librerías de trabajo

// Librerías base de aplicación
#include "stdafx.h"

// Referencia a la librería base
#include "diccionario.h"

#pragma endregion

#pragma region Declaración de Métodos y Funciones Auxiliares de gestión de Diccionario.

tPalabra LeerNuevoElemento();

#pragma endregion 

#pragma region Métodos y Funciones de gestión de Diccionario.

// Nombre: MenuManager
// Descripcion: Metodo de negocio para la gestión de Menús de Diccionario
void MenuManager(tMenuType pType, char pString[]) {

	// Limpieza de pantalla
	system("cls");

	// Validar tipo de Menu a mostrar
	switch (pType) {
	case PRINCIPAL:
		// Mostrar menu de opciones
		printf("==============================================================================\n");
		printf("= Elija una de las siguientes opciones:                                      =\n");
		printf("=                                                                            =\n");
		printf("=  1. Anyadir palabra                                                        =\n");
		printf("=  2. Traducir palabra                                                       =\n");
		printf("=  3. Mostrar diccionario                                                    =\n");
		printf("=  4. Salir                                                                  =\n");
		printf("=                                                                            =\n");
		printf("= Pulse una opcion o Esc para salir...                                       =\n");
		printf("==============================================================================\n");

		break;
	case PRINCIPAL_ERROR:
		// Cargar mensaje
		printf("==============================================================================\n");
		printf("= La opción seleccionada es incorrecta. Pulse una tecla para continuar...    =\n");
		printf("==============================================================================\n");

		break;
	case PRINCIPAL_DESPEDIDA:
		// Cargar mensaje
		printf("==============================================================================\n");
		printf("= Gracias por usar nuestra aplicacion. Vuelva pronto...                      =\n");
		printf("= Pulse una tecla para salir...                                             =\n");
		printf("==============================================================================\n");
		break;
	case ANYADIRPALABRA_ESPAÑOL: 
		printf("==============================================================================\n");
		printf(" Introduzca la nueva palabra en el Diccionario:                               \n");
		printf("                                                                              \n");
		printf("  Pulse Intro para Introducir opcion o Esc para salir...                      \n");
		printf("  Pulse para salir...                                                         \n");
		printf("==============================================================================\n");
		printf("                                                                              \n");
		printf("  Palabra a traducir en Espanyol: \n");
		
		break;
	case ANYADIRPALABRA_INGLES: 
		printf("==============================================================================\n");
		printf(" Introduzca la nueva palabra en el Diccionario:                               \n");
		printf("                                                                              \n");
		printf(" Pulse Intro para Introducir opcion o Esc para salir...                       \n");
		printf(" Pulse para salir...                                                          \n");
		printf("==============================================================================\n");
		printf("                                                                              \n");
		printf("Traducción de la palabra en Ingles: \n");

		break;
	case ANYADIRPALABRA_SALIDA_MOSTRAR: 
		printf("==============================================================================\n");
		printf("  Se ha introducido la siguiente palabra: %s                                  \n", pString);
		printf("  Pulse una tecla para continuar...                                           \n");
		printf("==============================================================================\n");
		
		break;
	case ANYADIRPALABRA_SALIDA_MAXCAR_MOSTRAR: 
		printf("==============================================================================\n");
		printf("  Se ha llegado al número máximo de caracteres disponibles.                   \n");
		printf("  Se ha introducido la siguiente palabra: %s                                  \n", pString);
		printf("  Pulse una tecla para continuar...                                           \n");
		printf("==============================================================================\n");

		break;
	case ANYADIRPALABRA_SALIDA_CANCELAR: 		
		printf("==============================================================================\n");
		printf("= No se ha introducido ninguna palabra. Se retorna al menu principal         =\n");
		printf("= Pulse una tecla para continuar...                                          =\n");
		printf("==============================================================================\n");

		break;

	default: /*No tiene que ocurrir, incluir una gestión de excepciones*/ break;
	}
}

// Nombre: anyadir_palabra
// Descripcion: Metodo de negocio para la gestión de inserciones en el diccionario 
int anyadir_palabra(tPalabra Diccionario[], int numpal) {

	// Declaración de variables de trabajo
	int iResult;

	// Inicialización de variables de trabajo
	iResult = numpal;

	// Validar parametros de entrada. 
	if ((numpal >= 0) && (numpal < MAX_PAL)) {

		// Validar que el Diccionario esté inicializado
		if (Diccionario != NULL) {

			// Decalaración de variable auxiliar 
			tPalabra tElemDicc; 

			// Leer palabras
			tElemDicc = LeerNuevoElemento();
						
			// Validar elementos de estructura
			if ((tElemDicc.espanyol != NULL && strlen(tElemDicc.espanyol) > 0) && 
				(tElemDicc.ingles != NULL && strlen(tElemDicc.ingles) > 0)) {
				Diccionario[numpal] = tElemDicc;
				numpal++;
			}

			// Asignar el resultado con el nuevo valor de tamaño del Diccionario 
			iResult = numpal; 
		}
		else { 
			// TODO Proceso de inicialización del diccionario
		}
	}

	// Retorno de datos por defecto
	return iResult;
}

#pragma endregion 

#pragma region Implementación de Métodos y Funciones Auxiliares de gestión de Diccionario.

tPalabra LeerNuevoElemento() {

	// Declaración e Inicialización de Variables
	tPalabra tpResultado;
	int iTam;
	short iBucle;
	char cKey;

	// Inicialización de variables
	iBucle = 0; /* 0 = Español && 1=Ingles */

	// Presentación de opciones de menu
	do {
		// Carga de valor de variables de Trabajo: 
		iTam = 0;
		cKey = NULL;

		// Validar momento del bucle (Español o Inglés) para definir el Menú: 
		iBucle == 0 ? MenuManager(ANYADIRPALABRA_ESPAÑOL, nullptr): MenuManager(ANYADIRPALABRA_INGLES, nullptr);
		
		// Proceso de Lectura, Validación y Almacenamiento desde Pantalla
		do {  
			// Leer de pantalla
			cKey = _getch();

			// Capturar la opción seleccionada y Validar caracter
			switch (cKey) {
				case ENTER:

					// Validamos el tamaño actual 
					if (iTam < (MAX_CAD - 1)) {
						
						// Introducir el caracter en el array correspondiente
						if (iBucle == 0) tpResultado.espanyol[iTam] = EOL;
						else tpResultado.ingles[iTam] = EOL;
					}
					
					// Cargar mensaje y Mosrar datos
					MenuManager(ANYADIRPALABRA_SALIDA_MOSTRAR, 
								iBucle == 0 ? tpResultado.espanyol : tpResultado.ingles);

					// Lectura de teclado: 
					_getch();

					// Pasar a la siguiente vuelta del bucle
					iBucle++;

					break;
				case DEL:
					
					// Validar que haya algún caracter introducido
					if (iTam > 0) { 
						// Retroceder un caracter
						iTam--;

						// Borrado de un caracter 
						if (iBucle == 0) tpResultado.espanyol[iTam] = NULL;
						else tpResultado.ingles[iTam] = NULL;

						// Mover el cursor hacia atrás
						printf("%c",cKey); 
					}

					break;
				case ESC:
										
					// Limpiar todos los arrays
					for (int iElem = 0; iElem < iTam; iElem++) { 
						tpResultado.espanyol[iElem] = NULL;
						tpResultado.ingles[iElem] = NULL;
					}
					
					// Establecemos el tamaño a 0
					iTam = 0;

					// Introducir el caracter EOL en ambos arrays
					tpResultado.espanyol[iTam] = EOL;
					tpResultado.ingles[iTam] = EOL;
					
					// Cargar mensaje
					MenuManager(ANYADIRPALABRA_SALIDA_CANCELAR, nullptr);
					
					// Lectura de teclado: 
					_getch();

					break;
				default:	
					// Validar que caracteres se han introducido 
					if ((cKey >= 'A' || cKey <= 'Z') || (cKey >= 'a' || cKey <= 'z')) {

						// Validamos que no hayamos llegado al fin del array
						/* Nota: Se puede usar indistintamente iTam y strlen(tpResultado.idioma que corresponda) */
						if (iTam < (MAX_CAD - 1)) {

							// Introducir el caracter en el array correspondiente
							if (iBucle == 0) tpResultado.espanyol[iTam] = cKey;
							else tpResultado.ingles[iTam] = cKey;

							// Incrementamos el tamaño del array (num elem ocupados dentro del mismo)
							iTam++;

							// Mostrar elemento en pantalla
							printf("%c", cKey);
						}

						// Validamos que tras la última inserción se haya llegado al final
						if (iTam == (MAX_CAD - 1)) {

							// Establecer el valor de la variable de entrada a fin de linea
							cKey = EOL;

							// Introducir el caracter en el array correspondiente
							if (iBucle == 0) tpResultado.espanyol[iTam] = cKey;
							else tpResultado.ingles[iTam] = cKey;

							// Cargar mensaje y Mosrar datos
							MenuManager(ANYADIRPALABRA_SALIDA_MOSTRAR,
								iBucle == 0 ? tpResultado.espanyol : tpResultado.ingles);

							// Lectura de teclado: 
							_getch();

							// TODO: Quiere introducir de nuevo la palabra de 0??
							// cKey = ESC;

							// Pasar a la siguiente vuelta del bucle
							iBucle++;
						}
					}

					break;
			}

		} while ((cKey != ESC) && (cKey != ENTER) && (cKey != EOL));

	} while ((cKey != ESC) &&     // Salida por solicitud del usuario
			 (iBucle < 2));		  // Salida por que se ha introducido el par de palabras de diccionario	

			 //(cKey != ENTER) &&   // Salida por introducción de palabra ??
			 
	// Retorno de Datos
	return tpResultado;
}

#pragma endregion 

