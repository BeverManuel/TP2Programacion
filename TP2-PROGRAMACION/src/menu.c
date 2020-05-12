/*
 * menu.c
 *
 *  Created on: 12 abr. 2020
 *      Author: Manuel
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "menu.h"

void menuPrincipal()
	{
		printf("1. Alta - Empleado\n");
		printf("2. Modificar - Empleado\n");
		printf("3. Baja - Empleado\n");
		printf("4. Informar:\n"
			   "   1. Lista de los empleado\n"
			   "   2. Salarios\n");
		printf("5. Salir\n");
}
void menuModificar()
	{
		printf("1. Modificar nombre\n");
		printf("2. Modificar apellido\n");
		printf("3. Modificar sector\n");
		printf("4. Modificar salario\n");
		printf("5. Volver // Terminada la modificacion\n");
}
void menuPuntoCuatro()
	{
		printf("1. Listado de los empleados\n");
		printf("2. Total y promedio de los salarios\n");
		printf("3. Volver\n");
}
