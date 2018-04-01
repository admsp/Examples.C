// ============================================================
// Nombre: Practica 3.cpp 
// Descripción: 
// Tercera práctica de Programación de 1º de Teleco UA.
// Objetivo: Se divide en dos partes:
//			 a. Funciones Matemáticas
//			 b. Funciones con Arrays
// ============================================================

#pragma region Librerías de Programa

// Invocación de la Librería de agrupación de librerías base Standard para la aplicación.
#include "stdafx.h"

#pragma endregion

#pragma region Variables Globales 

// Gestión de Menú
char cOptionSelected;

#pragma endregion


#pragma region Ciclo de Vida

int main() {
	
	// Declaración e Inicialización de Variables
	int iResult;

	// Inicialización de variables globales

	// Menu
	cOptionSelected = ESP;
	iResult = 0;

	// Inicialización de variables
	do {
		// Mostrar menu de opciones
		MainMenuManager(PRINCIPAL, nullptr);

		// Leer de pantalla
		cOptionSelected = _getch();

		// Capturar la opción seleccionada
		if (cOptionSelected != ESP) {
			// Validar caracter
			switch (cOptionSelected) {
				case '1':
					// TODO: A la práctica de Operaciones Matematicas

					break;
				case '2':
					// TODO: A la práctica de Operaciones de Arrays

					break;
				case '3':
				case ESC:
					// Mostrar mensaje de salida
					MainMenuManager(PRINCIPAL_DESPEDIDA, nullptr);

					// Esperamos que pulse una tecla
					_getch();

					break;
				default:
				// Mostrar mensaje de salida
				MainMenuManager(PRINCIPAL_ERROR, nullptr);

				// Recogemos tecla pulsada
				_getch();

				break;
			}
		}

	} while ((cOptionSelected != ESC) && (cOptionSelected != '3'));

	// Retorno de datos
	return iResult;
}

#pragma endregion


