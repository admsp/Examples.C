// ============================================================
// Nombre: Practica 1.cpp 
// Descripción: 
// Primera práctica de Programación de 1º de Teleco UA.
// Objetivo: Cambio de medidas de tiempo básicas.
// ============================================================

// Invocación de la Librería de agrupación de librerías base Standard para la aplicación.
#include "stdafx.h"

// TODO: Area de invocación de librerías específicas de aplicación.
#define _CRT_SECURE_NO_DEPRECATE

#pragma region Area de declaración de variables/literales/constantes globales

// Definición de variables globales de aplicación

// Variables definidas
#define NON_ID			'0'
#define SEG_ID			'1'
#define MIN_ID			'2'
#define HOU_ID			'3'
#define DAY_ID			'4'

// Diferencia entre Medidas
#define SEG_POR_MINUTO	60
#define SEG_POR_HORA	3600
#define SEG_POR_DIA		86400

#define MIN_POR_HORA	60
#define MIN_POR_DIA		1440

#define HORA_POR_DIA	24

// Teclas de aplicación
#define ENTER			13
#define ESP				32
#define ESC				27

// Definición de aplicación
#define MAX_ELEMENTS    2

#pragma endregion

#pragma region Area de declaración de funciones y variables de negocio  

// Variable de trabajo para diferentes medidas:
struct TimeMeasures {
	char id;
	char name[10];
	float value;
};

typedef TimeMeasures TimeMeasure;

// Declaración de funciones

// Funciones y Metodos Auxiliares
int fReadNumericString();
TimeMeasure fChargeMeasure(char cSelectedKey);

// Funciones y Metodos de Flujo/Negocio
char fLoadPresentationMenu();
void fSelectMeasureMenu(TimeMeasure* pTimeMeasures);
bool fTransformMeasures(TimeMeasure* tmMeasures);
void fShowResultMeasures(TimeMeasure *pTimeMeasures);

#pragma endregion  

#pragma region Ciclo de Vida de la Aplicación  

// Inicio de la aplicación
int main(int args, char argv[]) {
    
	// Declaración de variables
	TimeMeasure tmMeasures[MAX_ELEMENTS]; 
	
	// Carga Menú informativo inicial
	fLoadPresentationMenu();
	
	// Seleccionar datos a transformar
	fSelectMeasureMenu(tmMeasures);
	
	// Validar opciones seleccionadas
	fTransformMeasures(tmMeasures);

	// Mostar resultado en pantalla
	fShowResultMeasures(tmMeasures);

	// Retorno o salida correcta. 
	return 0;
} 

#pragma endregion  

#pragma region Area de Funciones y Métodos de negocio

// Nombre: fLoadMainMenu
// Descripción: Mensaje informativo inicial
char fLoadPresentationMenu() {

	// Declaración de variables de método
	char selectedkey;

	// Inicialización de variables
	selectedkey = NULL;

	// Carga de Menú (Información y salida)
	do {
		// Limpiar pantalla
		system("cls");

		// Cargar mensaje
		printf("==============================================================================\n");
		printf("= Este programa permite el paso de segundos a minutos, horas y dias.         =\n");
		printf("= Pulse cualquier tecla para continuar o Esc para Salir                      =\n");
		printf("==============================================================================\n");

		// Ejemplo-Prueba de valores de punteros :D 
		
		//int tamInicial = 2;
		//int* pa = &tamInicial;
		//int tamfinal;
		//tamfinal = *pa;

		//printf("= El tamaño inicial vale %d                                                  =\n", tamInicial);
		//printf("= El valor asignado al puntero al tamaño inicial vale %d                     =\n", &tamInicial);
		//printf("= El puntero al tamaño inicial vale %d                                       =\n", pa);
		//printf("= El valor del puntero al tamaño inicial vale %d                             =\n", *pa);
		//printf("= El valor de la nueva variable vale %d                                      =\n", tamfinal);
		//printf("= El valor de la posición de memoria de la nueva variable vale %d            =\n", &tamfinal);

		// Espera de respuesta de usuario
		selectedkey = _getch();
		
		// Validar caracter introducido
		switch (selectedkey) {
			case ESC: 
				// TODO: Crear salida por señales de sistema (SIG_KILL)
				break;
			default: break;
		}

	} while (selectedkey == NULL);

	// Retorno valor recibido
	return selectedkey;
}

// Nombre: fLoadMainMenu
// Descripción: Mensaje informativo inicial
 void fSelectMeasureMenu(TimeMeasure *pTimeMeasures) {

	// Bucle de obtención de datos: 
	for (int iElement = 0; iElement < MAX_ELEMENTS; iElement++) {

		// Declaramos la variable de trabajo (una por iteración)	
		char cKey;
		TimeMeasure tmMeasure;
		
		// Bucle de obtención y carga de información
		// Nota: Se repite hasta que el elemento obtenido es coherente. 
		do {
			// Inicializamos las variables
			cKey = NULL;
			tmMeasure = fChargeMeasure(NON_ID);

			// Limpieza de pantalla
			system("cls");

			// Cargar mensaje
			printf("==============================================================================\n");
			printf("= ¿Que medida desea transformar?                                             =\n");
			printf("=                                                                            =\n");

			// Determinar las opciones disponibles
			if (iElement != 0) {
				// Apuntar al elemento actual y posteriormente apuntar al anterior
				TimeMeasure *tmPrevious = pTimeMeasures;
				tmPrevious--;

				// Revisar el valor actual
				switch ((*tmPrevious).id) {
					case SEG_ID:
						printf("=  2.Minutos                                                                 =\n");
						printf("=  3.Horas                                                                   =\n");
						printf("=  4.Dias                                                                    =\n");
						break;
					case MIN_ID:
						printf("=  1.Segundos                                                                =\n");
						printf("=  3.Horas                                                                   =\n");
						printf("=  4.Dias                                                                    =\n");
						break;
					case HOU_ID:
						printf("=  1.Segundos                                                                =\n");
						printf("=  2.Minutos                                                                 =\n");
						printf("=  4.Dias                                                                    =\n");
						break;
					case DAY_ID:
						printf("=  1.Segundos                                                                =\n");
						printf("=  2.Minutos                                                                 =\n");
						printf("=  3.Horas                                                                   =\n");
						break;
					default:
						break;
				}
			}
			else {
				printf("=  1.Segundos                                                                =\n");
				printf("=  2.Minutos                                                                 =\n");
				printf("=  3.Horas                                                                   =\n");
				printf("=  4.Dias                                                                    =\n");
			}
			// 
			printf("=                                                                            =\n");
			printf("= Pulse una opcion o Esc para salir...                                       =\n");
			printf("==============================================================================\n");

			// Espera de respuesta de usuario
			cKey = _getch();

			// Validar el caracter recibido
			if (cKey != ESP) {

				// Validar caracter
				switch (cKey) {
					case '1':
					case '2':
					case '3':
					case '4':
						// Limpieza de pantalla
						system("cls");

						// Carga valor seleccionado
						tmMeasure = fChargeMeasure(cKey);

						// Si la medida es inicial (0 dado que no se ha terminado de cargar ninguno)
						if (iElement == 0) {
						
							// Solicitar el valor de la medida
							printf("==============================================================================\n");
							printf("= ¿Que valor asigna a la medida a transformar?                               =\n");
							printf("==============================================================================\n");

							// Leer el valor y asignarlo a la variable de trabajo
							tmMeasure.value = (float) fReadNumericString();
						}

						// Charge measure selected and value in the array 
						*pTimeMeasures = tmMeasure;
					
						/* Note about pointers and movemente between the elements of an array using pointers.
						int iTam = 10;
						int *ptr = (int *) malloc ((iTam) * sizeof (int));
						
						*ptr      // Refers to the pointers value
						ptr       // Refers to the position the pointer is referencing to
						
						ptr++;    // Pointer moves to the next element position (as if it was an array)
						++ptr;    // Pointer moves to the next element position (as if it was an array)
						++*ptr;   // The value of ptr is incremented
						++(*ptr); // The value of ptr is incremented
						++*(ptr); // The value of ptr is incremented
						*ptr++;   // Pointer moves to the next int position (as if it was an array). But returns the old content
						(*ptr)++; // The value of ptr is incremented
						*(ptr)++; // Pointer moves to the next element position (as if it was an array). But returns the old content
						*++ptr;   // Pointer moves to the next element position, and then get's accessed, with your code, segfault
						*(++ptr); // Pointer moves to the next element position, and then get's accessed, with your code, segfault

						// About a variable the situation is different
						int var = 0;

						var // Refers to the value of the variable
						&var // Refers to the position in which the value is stored

						*/

						break;
					case 'X':
					case 'x':
					default:
						// Carga de datos por defecto
						tmMeasure = fChargeMeasure(cKey);

						// Limpieza de pantalla
						system("cls");

						// Cargar mensaje
						printf("==============================================================================\n");
						printf("= La opción seleccionada es incorrecta. Pulse una tecla para continuar...    =\n");
						printf("==============================================================================\n");

						// Recogemos tecla pulsada
						cKey = _getch();

						break;
				}
			}
		} 
		// Es decir mientras no se haya asignado un nuevo elemento
		while (tmMeasure.id == NON_ID);

		// Apuntar al siguiente elemento 
		pTimeMeasures++;
	} 

	// Apuntar al primer elemento del array de elementos 
	(pTimeMeasures - MAX_ELEMENTS);
}

// Nombre: fTransformMeasures
// Descripción: Gestión y transformación de Medidas
bool fTransformMeasures(TimeMeasure *pTimeMeasures) {

	// Declaración de variables locales
	bool bResult; 

	// Inicialización de variables locales
	bResult = false;

	// Validar datos de entrada
	if (pTimeMeasures != NULL) {
		
		// TODO: Validar el tamaño del array

		// Obtenemos la medida inicial (valor)
		TimeMeasure tmOrigin = *pTimeMeasures;
		
		// Nos movemos al siguiente elemento
		pTimeMeasures++;

		// Obtenemos la medida final (valor) 
		TimeMeasure tmFinal = *pTimeMeasures;
		
		// Transformar de una a otra medida
		float num = tmOrigin.value;
		switch (tmOrigin.id) {
			case SEG_ID: 
				switch (tmFinal.id) {
					case MIN_ID: num = num / SEG_POR_MINUTO; break;
					case HOU_ID: num = num / SEG_POR_HORA; break;
					case DAY_ID: num = num / SEG_POR_DIA; break;
					default: break;
				}
				break;
			case MIN_ID: 
				switch (tmFinal.id) {
					case SEG_ID: num = num * SEG_POR_MINUTO; break;
					case HOU_ID: num = num / MIN_POR_HORA; break;
					case DAY_ID: num = num / MIN_POR_DIA; break;
					default: break;
				}
				break;
			case HOU_ID: 
				switch (tmFinal.id) {
					case SEG_ID: num = num * SEG_POR_HORA; break;
					case MIN_ID: num = num * MIN_POR_HORA; break;
					case DAY_ID: num = num / HORA_POR_DIA; break;
					default: break;
				}
				break;
			case DAY_ID: 
				switch (tmFinal.id) {
					case SEG_ID: num = num * SEG_POR_DIA; break;
					case MIN_ID: num = num * MIN_POR_DIA; break;
					case HOU_ID: num = num * HORA_POR_DIA; break;
					default: break;
				}
				break;
			default:
				break;
		}

		// Asignar el valor al array
		(*pTimeMeasures).value = num;

		// Volver a apuntar al elemento inicial
		pTimeMeasures--;
	}

	// Retorno de resultado
	return bResult;
}

// Nombre: fShowResultMeasures
// Descripción: Mostar resultados
void fShowResultMeasures(TimeMeasure *pTimeMeasures) {

	//TODO: Validar que no esté el array a null y que el tamaño sea completo

	// Variables locales de método
	TimeMeasures tmOrigin, tmFinal;

	// Cargar las variables por valor
	tmOrigin = *pTimeMeasures;
	*pTimeMeasures++;
	tmFinal = *pTimeMeasures;
	*pTimeMeasures--;

	// Cargar mensaje
	printf("==============================================================================\n");
	printf("= El resultado es el siguiente:                                               \n");
	printf("=                                                                             \n");
	printf("= 1. Medida Original:                                                         \n");
	printf("=    a. Nombre: %s                                                            \n", tmOrigin.name);
	printf("=    b. Valor:  %.2f                                                          \n", tmOrigin.value);
	printf("= 2. Medida Final:                                                            \n");
	printf("=    a. Nombre: %s                                                            \n", tmFinal.name);
	printf("=    b. Valor:  %.2f                                                          \n", tmFinal.value);
	printf("=                                                                             \n");
	printf("= Pulse cualquier tecla para continuar...                                     \n");
	printf("==============================================================================\n");

	// Recepción de datos
	_getch();
}

#pragma endregion 

#pragma region Funciones Auxiliares

// Nombre: fChargeMeasure 
// Descripción: Metodo para la carga de datos de medida
// Objetivo: Validar el caracter y devolver la opción correcta seleccionada.
TimeMeasure fChargeMeasure(char cSelectedKey) {

	// Declaración de variables
	TimeMeasure tmData;

	// Validación 
	switch (cSelectedKey) {

		case SEG_ID:
			tmData.id = SEG_ID;
			strcpy_s(tmData.name, "Segundos");
			break;
		case MIN_ID:
			tmData.id = MIN_ID;
			strcpy_s(tmData.name, "Minutos");
			break;
		case HOU_ID:
			tmData.id = HOU_ID;
			strcpy_s(tmData.name, "Horas");
			break;
		case DAY_ID:
			tmData.id = DAY_ID;
			strcpy_s(tmData.name, "Dias");
			break;
		case NON_ID:
		default:
			tmData.id = NON_ID;
			strcpy_s(tmData.name, "None");
			break;
	}

	// Retorno de datos
	return tmData;
} 

// Nombre: fReadNumericString
// Descripción: Función que realiza operaciones de lectura y escritura:
//              a. lee de la consola I/O establecida por defecto (ver getch)
//				b. solo admite los caracteres numéricos
//				c. muestra los caracteres admitidos después de leerlos
//				d. finaliza la lectura cuando recibe el caracter de retorno de carro (32= intro)
//				e. devuelve el numero entero recibido. 
// Notas: Se debe ampliar la funcionalidad para que se admitan caracteres no enteros (float y double) y se validen
//		  los caracteres . y , 
int fReadNumericString () {
	
	// Declaración e Inicialización de variables 
	int iResult;
	int iTam;

	char cKey;
	
	char* pBuffer;
	char* pAuxBuffer;

	// Inicializar variables
	cKey = 32;
	iResult = 0;
	iTam = 0; 

	pBuffer = NULL;
	pAuxBuffer = NULL;
	
	// Obtener datos del usuario
	for (int iElement = 0; cKey != ENTER; iElement++) {

		// Recepción caracter
		cKey = _getch();

		// Validar caracter
		if (cKey != ENTER) {
			
			// Validar que sea un numero
			if (cKey >= '0' && cKey <= '9') {
				
				// Evaluar el tamaño actual:
				// 1. Si el buffer principal no es nulo  
				if (pBuffer != NULL) {

					// a. Obtener tamaño del array principal
					iTam = (int)strlen(pBuffer);

					// b. Establecer tamaño del array auxiliar
					pAuxBuffer = (char*)malloc((iTam) * sizeof(char));

					// c. Añadir elementos anteriores
					for (int iElementAux = 0; iElementAux < iTam; iElementAux++)
						pAuxBuffer[iElementAux] = pBuffer[iElementAux];

					// d. Es un caracter correcto -> aumentar el tamaño del buffer
					iTam++;

					// e. Ampliar array/buffer principal para alojar el nuevo elemento
					pBuffer = (char*)malloc((iTam) * sizeof(char));
					//pBuffer = (char*)realloc((iTam) * sizeof(char));
					
					// f. Copiar el array principal en el array auxiliar
					for (int iElementAux = 0; iElementAux < (iTam - 1); iElementAux++)
						pBuffer[iElementAux] = pAuxBuffer[iElementAux];
				}
				// 2. Si el buffer es nulo
				else {
					// a. Es un caracter correcto -> aumentar el tamaño del buffer
					iTam++;

					// b. Ampliar array/buffer principal para alojar el nuevo elemento
					pBuffer = (char*)malloc((iTam) * sizeof(char));
				}

				// Añadir el elemento al array principal
				pBuffer[iElement] = cKey;
								
				// Mostrar elemento en pantalla
				printf("%c", cKey);
			}
		}
	}

	// Apuntar al primer elemento
	pBuffer = &pBuffer[0];

	// Obtener número
	iResult = atoi(pBuffer);

	// Liberar memoria
	free(pBuffer);
	free(pAuxBuffer);

	// Devolver dato
	return iResult;
}

#pragma endregion
