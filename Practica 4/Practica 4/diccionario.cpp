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
int LeerPalabra(char strEntrada[], int iTamMax);
int BuscarElemento(tPalabra Dicc[], int tamDicc, char Palabra[]);
void PintarDiccionario(tPalabra Dicc[], int num);

#pragma endregion 

#pragma region M�todos y Funciones de gesti�n de Diccionario.

// Nombre: MenuManager
// Descripcion: Metodo de negocio para la gesti�n de Men�s de Diccionario
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
			printf("=  4. Borrar elemento                                                        =\n");
			printf("=  5. Salir                                                                  =\n");
			printf("=                                                                            =\n");
			printf("= Pulse una opcion o Esc para salir...                                       =\n");
			printf("==============================================================================\n");

			break;
		case PRINCIPAL_ERROR:
			// Cargar mensaje
			printf("==============================================================================\n");
			printf("= La opcion seleccionada es incorrecta. Pulse una tecla para continuar...    =\n");
			printf("==============================================================================\n");

			break;
		case PRINCIPAL_DESPEDIDA:
			// Cargar mensaje
			printf("==============================================================================\n");
			printf("= Gracias por usar nuestra aplicacion. Vuelva pronto...                      =\n");
			printf("= Pulse una tecla para salir...                                              =\n");
			printf("==============================================================================\n");
			break;
		case ANYADIRPALABRA_ESPA�OL: 
			printf("==============================================================================\n");
			printf(" Introduzca la nueva palabra en el Diccionario:                               \n");
			printf("                                                                              \n");
			printf(" Pulse Intro para Introducir opcion o Esc para salir...                       \n");
			printf(" Pulse para salir...                                                          \n");
			printf("==============================================================================\n");
			printf("                                                                              \n");
			printf("Palabra a traducir en Espanyol: \n");
		
			break;
		case ANYADIRPALABRA_INGLES: 
			printf("==============================================================================\n");
			printf(" Introduzca la nueva palabra en el Diccionario:                               \n");
			printf("                                                                              \n");
			printf(" Pulse Intro para Introducir opcion o Esc para salir...                       \n");
			printf(" Pulse para salir...                                                          \n");
			printf("==============================================================================\n");
			printf("                                                                              \n");
			printf("Traduccion de la palabra en Ingles: \n");

			break;
		case ANYADIRPALABRA_SALIDA_MOSTRAR: 
			printf("==============================================================================\n");
			printf("  Se ha introducido la siguiente palabra: %s                                  \n", pString);
			printf("  Pulse una tecla para continuar...                                           \n");
			printf("==============================================================================\n");
		
			break;
		case ANYADIRPALABRA_SALIDA_MAXCAR_MOSTRAR: 
			printf("==============================================================================\n");
			printf("  Se ha llegado al numero maximo de caracteres disponibles.                   \n");
			printf("  Se ha introducido la siguiente palabra: %s                                  \n", pString);
			printf("  Pulse una tecla para continuar...                                           \n");
			printf("==============================================================================\n");

			break;
		case ANYADIRPALABRA_SALIDA_CANCELAR: 		
		case BORRAR_ELEMTENTO_SALIDA_CANCELAR:
			printf("==============================================================================\n");
			printf("= Accion cancelada por el usuario. Se retorna al menu principal.             =\n");
			printf("= Pulse una tecla para continuar...                                          =\n");
			printf("==============================================================================\n");

			break;
		case TRADUCIR_BUSCAR:
			printf("==============================================================================\n");
			printf(" Introduzca la palabra a buscar en el Diccionario                             \n");
			printf("                                                                              \n");
			printf(" Pulse Intro para Introducir opcion o Esc para salir...                       \n");
			printf(" Pulse para salir...                                                          \n");
			printf("==============================================================================\n");
			printf("                                                                              \n");
			printf("Palabra a buscar en el diccionario: \n");
		
			break;
		case TRADUCIR_SALIDA_MOSTRAR_RESULTADO:
			printf("==============================================================================\n");
			printf("  La traduccion es la siguiente palabra: %s                                   \n", pString);
			printf("  Pulse una tecla para continuar...                                           \n");
			printf("==============================================================================\n");

			break;
		case TRADUCIR_SALIDA_MOSTRAR_NO_ENCONTRADO:
		case BORRAR_ELEMENTO_SALIDA_NO_ENCONTRADO:
			printf("==============================================================================\n");
			printf("= Palabra no encontrada en el diccionario. Se retorna al menu principal.     =\n");
			printf("= Pulse una tecla para continuar...                                          =\n");
			printf("==============================================================================\n");

			break;
		case TRADUCIR_SALIDA_PALABRA_VACIA:
		case BORRAR_ELEMTENTO_SALIDA_PALABRA_VACIA:
			printf("==============================================================================\n");
			printf("= No se ha introducido ninguna palabra. Se retorna al menu principal.        =\n");
			printf("= Pulse una tecla para continuar...                                          =\n");
			printf("==============================================================================\n");

			break;
		case TRADUCIR_SALIDA_CANCELAR:
			printf("==============================================================================\n");
			printf("= Accion cancelada por el usuario. Se retorna al menu principal.             =\n");
			printf("= Pulse una tecla para continuar...                                          =\n");
			printf("==============================================================================\n");

			break;
		case MOSTRAR_DICCIONARIO_VACIO:
		case BORRAR_ELEMENTO_SALIDA_DICCIONARIO_VACIO:
			printf("==============================================================================\n");
			printf("= No existe ningun registro en el diccionario. Se retorna al menu principal. =\n");
			printf("= Pulse una tecla para continuar...                                          =\n");
			printf("==============================================================================\n");

			break;
		case BORRAR_ELEMENTO_BUSCAR_ELEMENTO:
			printf("==============================================================================\n");
			printf(" Introduzca la palabra a borrar del Diccionario                               \n");
			printf("                                                                              \n");
			printf(" Pulse Intro para Introducir opcion o Esc para salir...                       \n");
			printf(" Pulse para salir...                                                          \n");
			printf("==============================================================================\n");
			printf("                                                                              \n");
			printf("Palabra a borrar del diccionario: \n");

			break;
		case BORRAR_ELEMENTO_SALIDA_ENCONTRADO:
			printf("==============================================================================\n");
			printf("  Acci�n de borrado realizada correctamente.                                  \n");
			printf("  Pulse una tecla para continuar...                                           \n");
			printf("==============================================================================\n");

			break;
		default: /* Nota: Este caso no deber�a ocurrir */ break;
	}
}

// Nombre: anyadir_palabra
// Descripcion: Metodo de negocio para la gesti�n de inserciones en el diccionario 
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
			if ((tElemDicc.espanyol != NULL && strlen(tElemDicc.espanyol) > 0) && 
				(tElemDicc.ingles != NULL && strlen(tElemDicc.ingles) > 0)) {
				Diccionario[numpal] = tElemDicc;
				numpal++;
			}

			// Asignar el resultado con el nuevo valor de tama�o del Diccionario 
			iResult = numpal; 
		}
		else { 
			// TODO Esto no deber�a ocurrir por lo que deber�amos incluir un 
			// try and catch... (C++) u otro tipo de gesti�n de errores
		}
	}

	// Retorno de datos por defecto
	return iResult;
}

// Nombre: traducir_palabra
// Descripcion: Metodo de negocio para la gesti�n de traducciones en el diccionario 
void traducir_palabra(tPalabra Dicc[], int num) {
	
	// Declaraci�n de variables de trabajo:
	char stPalabra[MAX_CAD];
	int iResultEntrada, iFound;

	// Inicializaci�n de Variables
	iResultEntrada = -1;
	iFound = -1;

	// Carga de men�
	MenuManager(TRADUCIR_BUSCAR, nullptr);

	// Lanzamiento de lectura de palabras
	iResultEntrada = LeerPalabra(stPalabra, MAX_CAD);

	// Validar entrada recibida
	if (iResultEntrada == -1) 
		// Se ha recibido un ESC, mostrar mensaje de cancelaci�n
		MenuManager(TRADUCIR_SALIDA_CANCELAR, nullptr); 
	else if (iResultEntrada == 0)
		// No se ha introducido ninguna palabra, mostrar mensaje de retorno
		MenuManager(TRADUCIR_SALIDA_PALABRA_VACIA, nullptr);
	else { // Se ha leido una palabra
	
		// Se busca la palabra en el diccionario
		iFound = BuscarElemento(Dicc, num, stPalabra);

		// Validamos si se ha encontrado o no
		if (iFound == -1) 
			// No se ha encontrado. Mostramos mensaje informativo
			MenuManager(TRADUCIR_SALIDA_MOSTRAR_NO_ENCONTRADO, nullptr);
		else  
			// Se ha encontrado. Mostrar palabra encontrada por pantalla
			MenuManager(TRADUCIR_SALIDA_MOSTRAR_RESULTADO, Dicc[iFound].ingles);
	}
	
	// Lectura de teclado y salida
	_getch();
}

// Nombre: mostrar_diccionario
// Descripcion: Metodo de negocio para la mostrar el contenido del diccionario
void mostrar_diccionario(tPalabra Dicc[], int num) {

	// Validar el n�mero de elementos en el diccionario
	if (num <= 0)
		MenuManager(MOSTRAR_DICCIONARIO_VACIO, nullptr);
	else
		PintarDiccionario(Dicc, num);
	// Lectura de teclado y salida
	_getch();
}

// Nombre: borrar_palabra
// Descripcion: Metodo de negocio para el borrado de palabras dentro del dicccionario
// Salida: -1 = No se ha borrado el elemento; > 0 = numero de elementos del array 
int borrar_palabra(tPalabra Dicc[], int num) {

	// Declaraci�n de Variables
	int iResult = -1; 

	// Validar numero de elementos
	if (num <= 0) {
		// Mostrar mensaje no hay elementos
		MenuManager(BORRAR_ELEMENTO_SALIDA_DICCIONARIO_VACIO, nullptr);
	}
	else {
		// Declaraci�n e inicializaci�n de palabras
		char stPalabra[MAX_CAD];
		
		// Lanzamiento de lectura de palabra
		iResult = LeerPalabra(stPalabra, MAX_CAD);

		// Validar Resultado de Lectura
		if (iResult != -1) { // Se ha introducido alguna palabra
		
			// Validar el tama�o de la palabra: 
			if (iResult > 0) { // Palabra no vacia

				// BuscarElemento: 
				// 1. Existe: Se borra y muestra mensaje informativo
				// 2. No Existe Muestras un mensaje de que no existe 
				// Por ultimo se retorna al men� principal
				iResult = BuscarElemento(Dicc, num, stPalabra);

				// Validar B�squeda realizada
				if (iResult != -1) { // Caso 1: Existe: 

					// a. Borrado
					
					// Nota: Dado que el tama�o m�ximo del array es constante, no tenemos que hacer un 
					//		 realloc del mismo sino simplemente mover todos los elementos existentes y
					//		 asignar al �ltimo elemento anterior el valor null o nullptr para los arrays
					//		 contenidos en la estructura palabra.

					// Movemos todos los elementos existentes a la posici�n inmediatament anterior
					// a partir de la posici�n del array
					for (int iPosElem = iResult; iPosElem <= num; iPosElem++) 
						Dicc[iPosElem] = Dicc[iPosElem + 1];

					// Asignamos al anterior �ltimo elemento existente un elemento tPalabra vacio
					tPalabra tUltElem; 
					tUltElem.espanyol[0] = tUltElem.ingles[0] = EOL;
					Dicc[num - 1] = tUltElem;

					// Actualizamos el n�mero de elementos y el resultado a devolver
					iResult = num--;

					// b. Mostrar mensaje indicando que el elemento Existe y se ha borrado
					MenuManager(BORRAR_ELEMENTO_SALIDA_ENCONTRADO, nullptr);
				}
				else // Caso 2: No Existe -> Mostrar mensaje indicando que el elemento No Existe
					MenuManager(BORRAR_ELEMENTO_SALIDA_NO_ENCONTRADO, nullptr);
			}
			else // Palabra vacia -> Mostrar mensaje indicando que no se ha introducido ninguna palabra
				MenuManager(BORRAR_ELEMTENTO_SALIDA_PALABRA_VACIA, nullptr);
		}
		else // No se ha encontrado nada -> Mostrar mensaje indicando que el usuario desea salir (ESC)
			MenuManager(BORRAR_ELEMTENTO_SALIDA_CANCELAR, nullptr);
	}

	// Leemos la tecla pulsada y volvemos al men� anterior.
	_getch();

	// Retorno de datos
	return iResult;
}

#pragma endregion 

#pragma region Implementaci�n de M�todos y Funciones Auxiliares de gesti�n de Diccionario.

// Nombre: LeerNuevoElemento
// Descripcion: Metodo de negocio para la gesti�n de lectura de consola para un nuevo Elemento tPalabra
tPalabra LeerNuevoElemento() {

	// Declaraci�n e Inicializaci�n de Variables
	tPalabra tpResultado;
	int iTam;
	short iBucle;
	char cKey;

	// Inicializaci�n de variables
	iBucle = 0; /* 0 = Espa�ol && 1=Ingles */

	// Presentaci�n de opciones de menu
	do {
		// Carga de valor de variables de Trabajo: 
		iTam = 0;
		cKey = NULL;

		// Validar momento del bucle (Espa�ol o Ingl�s) para definir el Men�: 
		iBucle == 0 ? MenuManager(ANYADIRPALABRA_ESPA�OL, nullptr): MenuManager(ANYADIRPALABRA_INGLES, nullptr);
		
		// Proceso de Lectura, Validaci�n y Almacenamiento desde Pantalla
		do {  
			// Leer de pantalla
			cKey = _getch();

			// Capturar la opci�n seleccionada y Validar caracter
			switch (cKey) {
				case ENTER:
					// Validamos el tama�o actual 
					if (iTam < (MAX_CAD - 1)) 
						// Introducir el caracter en el array correspondiente
						if (iBucle == 0) tpResultado.espanyol[iTam] = EOL;
						else tpResultado.ingles[iTam] = EOL;
					
					// Cargar mensaje y Mosrar datos
					MenuManager(ANYADIRPALABRA_SALIDA_MOSTRAR, 
								iBucle == 0 ? tpResultado.espanyol : tpResultado.ingles);

					// Lectura de teclado: 
					_getch();

					// Pasar a la siguiente vuelta del bucle
					iBucle++;

					break;
				case DEL:
					
					// Validar que haya alg�n caracter introducido
					if (iTam > 0) { 
						// Retroceder un caracter
						iTam--;

						// Borrado de un caracter 
						if (iBucle == 0) tpResultado.espanyol[iTam] = NULL;
						else tpResultado.ingles[iTam] = NULL;

						// Mover el cursor hacia atr�s
						printf("%c", cKey); 
						printf("%c", ESP);
						printf("%c", cKey);
					}

					break;
				case ESC:
										
					// Limpiar todos los arrays
					for (int iElem = 0; iElem < iTam; iElem++) 
						tpResultado.espanyol[iElem] = tpResultado.ingles[iElem] = NULL;
					
					// Establecemos el tama�o a 0
					iTam = 0;

					// Introducir el caracter EOL en ambos arrays
					tpResultado.espanyol[iTam] = tpResultado.ingles[iTam] = EOL;
					
					// Cargar mensaje
					MenuManager(ANYADIRPALABRA_SALIDA_CANCELAR, nullptr);
					
					// Lectura de teclado: 
					_getch();

					break;
				default:	

					/*Nota: Tras validar que el caracter sea correcto se valida el tama�o por lo que nunca
					        nos encontraremos en la situaci�n de que el tama�o sea mayor o igual que el 
							tama�o m�ximo de cadena MAX_CAD */

					// Validar que caracteres se han introducido 
					if ((cKey >= 'A' || cKey <= 'Z') || (cKey >= 'a' || cKey <= 'z')) {

						// Validamos que no hayamos llegado al fin del array
						/* Nota: Se puede usar indistintamente iTam y strlen(tpResultado.idioma que corresponda) */
						if (iTam < (MAX_CAD - 1)) {
							
							// Introducir el caracter en el array correspondiente
							(iBucle == 0) ? tpResultado.espanyol[iTam] = cKey : tpResultado.ingles[iTam] = cKey;

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
							(iBucle == 0) ? tpResultado.espanyol[iTam] = cKey : tpResultado.ingles[iTam] = cKey;

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
		 
	// Retorno de Datos
	return tpResultado;
}

// Nombre: LeerPalabra
// Descripcion: Metodo de negocio para la lectura de consola 
// Salida: Tama�o de la cadena leida. En caso de que se reciba ESC se devuelve -1
int LeerPalabra(char strEntrada[], int iTamMax) {

	// Declaraci�n e Inicializaci�n de Variables
	int iReturn, iTam;
	char cKey;
	
	// Inicializaci�n de variables
	iReturn = -1;
	iTam = 0;
	cKey = NULL;

	// Proceso de Lectura, Validaci�n y Almacenamiento desde Pantalla
	do {
		// Leer de pantalla
		cKey = _getch();

		// Capturar la opci�n seleccionada y Validar caracter
		switch (cKey) {
			case ENTER:
				// Validamos el tama�o actual 
				if (iTam < (iTamMax - 1)) strEntrada[iTam] = EOL;
				
				// Establecemos el resultado de salida (Tama�o)
				iReturn = iTam;

				break;
			case DEL:
				// Validar que haya alg�n caracter introducido
				if (iTam > 0) {
					// Retroceder un caracter
					iTam--;

					// Borrado de un caracter 
					strEntrada[iTam] = NULL;

					// Mover el cursor hacia atr�s
					printf("%c", cKey);
					printf("%c", ESP);
					printf("%c", cKey);
				}

				break;
			case ESC:
				// Limpiar todos los arrays
				for (int iElem = 0; iElem < iTam; iElem++) strEntrada[iElem] = NULL;

				// Establecemos el tama�o a 0
				iTam = 0;

				// Introducir el caracter EOL en ambos arrays
				strEntrada[iTam] = EOL;
				
				// Establecemos la salida a -1 (Solicitada por el usuario)
				iReturn = -1;

				break;
			default:
				// Validar que caracteres se han introducido 
				if ((cKey >= 'A' || cKey <= 'Z') || (cKey >= 'a' || cKey <= 'z')) {

					// Validamos que no hayamos llegado al fin del array
					/* Nota: Se puede usar indistintamente iTam y strlen(tpResultado.idioma que corresponda) */
					if (iTam < (iTamMax - 1)) {

						// Introducir el caracter en el array correspondiente
						strEntrada[iTam] = cKey;

						// Incrementamos el tama�o del array (num elem ocupados dentro del mismo)
						iTam++;

						// Mostrar elemento en pantalla
						printf("%c", cKey);
					}

					// Validamos que tras la �ltima inserci�n se haya llegado al final
					if (iTam == (iTamMax - 1)) {

						// Asignaci�n de valor de la variable de entrada a fin de linea y carga en el array correspondiente
						strEntrada[iTam] = cKey = EOL;

						// Establecemos el resultado de salida (Tama�o)
						iReturn = iTam;
					}
				}

				break;
		}

	} while ((cKey != ESC) && (cKey != ENTER) && (cKey != EOL));

	// Retorno Standard
	return iReturn;
}

// Nombre: Buscar Elemento
// Descripcion: Metodo de negocio para la Busqueda de una palabra en el diccionario
// Parametros: 
//			Dicc: Vector de tPalabra con el Diccionario
//			tamDicc: Tama�o del Vector Diccionario
//			Palabra: Vector con la Palabra a buscar
// Salida: posici�n del elemento en el diccionario. Si no encontrado -1
int BuscarElemento(tPalabra Dicc[], int tamDicc, char Palabra[]) {
	
	// Declaraci�n e inicializaci�n de Variables
	int iResult = -1; // --> No encontrado por defecto

	// Proceso de b�squeda
	// Nota: Pese a que de forma dogmatica se utilice un metodo while para el proceso de forma 
	//		 Standard se utiliza un for con un break de ruptura. 
	for (int pos = 0; pos < tamDicc; pos++) {
		
		// Validaci�n de cadenas
		if (strcmp(Dicc[pos].espanyol, Palabra) == 0) {
			iResult = pos;
			break;
		}
	}

	// Retorno de datos
	return iResult;
}

// Nombre: PintarDiccionario
// Descripcion: Metodo de negocio para Mostrar la informaci�n almacenada en el diccionario
void PintarDiccionario(tPalabra Dicc[], int num) {

	// Limpieza de pantalla
	system("cls");

	// Mostramos el diccionario
	printf("==============================================================================\n");
	printf("= Se han encontrado el siguiente conjunto de resultados:                      \n");
	printf("                                                                              \n");
	printf("             ESPANYOL                        INGLES                           \n");
	printf("             ========                        ======                           \n");

	// Bucle de impresi�n de resultados
	for (int iElemPair = 0; iElemPair < num; iElemPair++) {
	
		printf("             %s                              %s                           \n", 
			Dicc[iElemPair].espanyol,
			Dicc[iElemPair].ingles);
	}

	printf(" Pulse una tecla para continuar...                                            \n");
	printf("==============================================================================\n");
}

#pragma endregion 

