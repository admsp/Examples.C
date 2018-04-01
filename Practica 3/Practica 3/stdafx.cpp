// Nombre: stdafx.h
// Descripción: Librería auxiliar 
//		stdafx.cpp: archivo de código fuente que contiene sólo las inclusiones estándar
//		Practica 1.pch será el encabezado precompilado
//		stdafx.obj contiene la información de tipos precompilada
// Nota: La librería incluye las declaraciones a las librerías utilizadas por los métodos y funciones
//       aquí declarados. 

#pragma region Librerías de trabajo

// Librerías base de aplicación
#include "stdafx.h"

#pragma endregion

#pragma region Declaración de Métodos y Funciones Auxiliares de gestión de Diccionario.

// TODO

#pragma endregion 

#pragma region Métodos y Funciones de gestión de Diccionario.

// Nombre: MainMenuManager
// Descripcion: Metodo de negocio para la gestión de Menús de Diccionario
void MainMenuManager(tMainMenuType pType, char pString[]) {

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
		default: /* Nota: Este caso no debería ocurrir */ break;
	}
}

// Nombre: LeerOpcionNumerica
// Descripción: Lee la opcion seleccionada por el usuario dentro de un menú numerico
// Salida: Opcion seleccionada 
int LeerOpcionNumerica(int pValorMin, int pValorMax) {

	// Declaración e Inicialización de Variables
	int iReturn;
	char cKey;

	// Inicialización de variables
	iReturn = -1;
	cKey = NULL;

	// Proceso de Lectura, Validación y Almacenamiento desde Pantalla
	do {
		// Leer de pantalla
		cKey = _getch();

		// Capturar la opción seleccionada y Validar caracter
		switch (cKey) {
			case ENTER:
				// TODO: Que pasa en este caso
				break;
			case DEL:
				// TODO: Borrado es viable??
				break;
			case ESC:
				// TODO: Mostrar menu de despedida	
				break;
			default:
				// Validar que caracteres se han introducido 
				if (cKey >= '1' && cKey <= '2')
					// Establecemos el resultado de salida seleccionado (Opcion)
					(cKey == '1') ? iReturn = 1 : iReturn = 2;
				// else { TODO: // Gestión de Gilipollas - con todas las letras  
					
				break;
		}

	} while (cKey != NULL);

	// Retorno Standard
	return iReturn;
}

#pragma endregion 
