// Nombre: diccionario.h
// Descripci�n: Librer�a de gesti�n de Diccionario
// Nota: 

#pragma region Librer�as de trabajo

// Librer�as base de aplicaci�n
#include "stdafx.h"

// Referencia a la librer�a base
#include "diccionario.h"

#pragma endregion

#pragma region Declaraci�n de M�todos y Funciones Auxiliares de gesti�n de Diccionario.

tPalabra LeerNuevoElemento();

#pragma endregion 

#pragma region M�todos y Funciones de gesti�n de Diccionario.

// Nombre: anyadir_palabra
// Descripcion: 
int anyadir_palabra(tPalabra Diccionario[], int numpal) {

	// Declaraci�n de variables de trabajo
	int iResult;

	// Inicializaci�n de variables de trabajo
	iResult = numpal;

	// Validar parametros de entrada. 
	if ((numpal >= 0) && (numpal < MAX_PAL)) {

		// Validar que el Diccionario est� inicializado
		if (Diccionario != NULL) {

			// Decalaraci�n de variable auxiliar 
			tPalabra tElemDicc; 

			// Leer palabras
			tElemDicc = LeerNuevoElemento();
						
			// Validar elementos de estructura
			if ((tElemDicc.espanyol != NULL) && (tElemDicc.ingles != NULL)) {
				numpal++;
				Diccionario[numpal] = tElemDicc;
			}

			// Asignar el resultado con el nuevo valor de tama�o del Diccionario 
			iResult = numpal; 
		}
		else { 
			// TODO Proceso de inicializaci�n del diccionario
		}
	}

	// Retorno de datos por defecto
	return iResult;
}

#pragma endregion 

#pragma region Implementaci�n de M�todos y Funciones Auxiliares de gesti�n de Diccionario.

tPalabra LeerNuevoElemento() {

	// Declaraci�n e Inicializaci�n de Variables
	tPalabra tpResultado;
	int iTam;
	short iBucle = 0; /* 0 = Espa�ol && 1=Ingles */
	char cKey;

	// Presentaci�n de opciones de menu
	do {
		// Carga de valor de variables de Trabajo: 
		iTam = 0;
		cKey = NULL;

		// Limpieza de pantalla
		system("cls");

		// Mostrar menu de opciones
		printf("==============================================================================\n");
		printf(" Introduzca la nueva palabra en el Diccionario:                               \n");
		printf("                                                                              \n");
		printf("  Pulse Intro para Introducir opcion o Esc para salir...                      \n");
		printf("  Pulse para salir...                                                         \n");
		printf("                                                                              \n");
		
		// Validar momento del bucle (Espa�ol o Ingl�s): 
		if (iBucle == 0) printf("  Palabra a traducir en Espanyol: \n");
		else printf("  Palabra a traducir en Ingles: \n");
		
		// Proceso de Lectura, Validaci�n y Almacenamiento desde Pantalla
		do {  
			// Leer de pantalla
			cKey = _getch();

			// Capturar la opci�n seleccionada y Validar caracter
			switch (cKey) {
				case ENTER:

					// Validamos el tama�o actual 
					if (iTam < (MAX_CAD - 1)) {

						// Introducir el caracter en el array correspondiente
						tpResultado.espanyol[iTam] = EOL;
					}
					
					// Limpieza de pantalla
					system("cls");
						
					// Cargar mensaje y Mosrar dato
					printf("==============================================================================\n");
					printf("  Se ha introducido la siguiente palabra: %d                                  \n", tpResultado.espanyol);
					printf("  Pulse una tecla para continuar...                                           \n");
					printf("==============================================================================\n");

					// Lectura de teclado: 
					_getch();

					// Pasar a la siguiente vuelta del bucle
					iBucle++;

					break;
				case ESC:

					// Limpieza de pantalla
					system("cls");
					
					// Limpiar el array correspondiente 
					for (int iElem = 0; iElem < iTam; iElem++) tpResultado.espanyol[iElem] = NULL;
					
					// Establecemos el tama�o a 0
					iTam = 0;

					// Cargar mensaje
					printf("==============================================================================\n");
					printf("= No se ha introducido ninguna palabra. Se retorna al men� principal         =\n");
					printf("  Pulse una tecla para continuar...                                           \n");
					printf("==============================================================================\n");

					// Lectura de teclado: 
					_getch();

					// TODO: Gestionar la salida al men� principal

					break;
				default:	
					
					// Validar que caracteres se han introducido 
					if ((cKey >= 'A' || cKey <= 'Z') || (cKey >= 'a' || cKey <= 'z')) {

						// Validamos que no hayamos llegado al fin del array
						/* Nota: Se puede usar indistintamente iTam y strlen(tpResultado.idioma que corresponda) */
						if (iTam < (MAX_CAD - 1)) {

							// Introducir el caracter en el array correspondiente
							tpResultado.espanyol[iTam] = cKey;

							// Incrementamos el tama�o del array (num elem ocupados dentro del mismo)
							iTam++;

							// Mostrar elemento en pantalla
							printf("%c", cKey);
						}

						// Validamos que tras la �ltima inserci�n se haya llegado al final
						if (iTam == (MAX_CAD - 1)) {

							// Establecer el valor de la variable de entrada a fin de linea
							cKey = EOL;

							// Introducir el caracter en el array correspondiente
							tpResultado.espanyol[iTam] = cKey;

							// Limpieza de pantalla
							system("cls");

							// Cargar mensaje
							printf("==============================================================================\n");
							printf("  Se ha llegado al n�mero m�ximo de caracteres disponibles.                   \n");
							printf("  Se ha introducido la siguiente palabra: %d                                  \n", tpResultado.espanyol);
							printf("  Pulse una tecla para continuar...                                           \n");
							printf("==============================================================================\n");

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

			 //(cKey != ENTER) &&   // Salida por introducci�n de palabra ??
			 
	// Retorno de Datos
	return tpResultado;
}

#pragma endregion 

