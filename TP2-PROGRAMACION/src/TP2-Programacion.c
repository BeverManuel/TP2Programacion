/*
 ============================================================================
 Name        : TP2-Programacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "biblioteca.h"
#include "EMPLEADOS.h"
#include "menu.h"
#include "getVarios.h"

#define TAMANO_EMPLEADOS 1000

int main(void)
{
	Employee empleados[TAMANO_EMPLEADOS];

	if(empleado_Inicializar(empleados,TAMANO_EMPLEADOS)==0)
	{
		printf("Los campos estan vacios\n");
	}

	empleado_Cargar(empleados,TAMANO_EMPLEADOS);


	return EXIT_SUCCESS;
}

