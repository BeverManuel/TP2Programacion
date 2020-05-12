/*
 * producto.h
 *
 *  Created on: 23 abr. 2020
 *      Author: Manuel
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_

#define TAMANO_NOMBRE 51
#define TAMANO_APELLIDO 51

typedef	struct {
	char nombre[TAMANO_NOMBRE];
	char apellido[TAMANO_APELLIDO];
	int sector;
	float salario;
	int isEmty;
	int ID;
}Employee;

int empleado_Inicializar(Employee array[],int limite);

int empleado_Borrar(Employee array[],int limite, int indice);

void empleado_Imprimir(Employee array[],int limite);

int empleado_getEmptyIndex(Employee* array,int limite);

int empleado_buscarID(Employee* array, int limite, int valorBuscado);

void empleado_Cargar(Employee array[],int limite);

int empleado_CargarDATOS(Employee array[],int limite, int indice);

int empleado_Modificar(Employee array[],int limite, int indice);

int empleado_OrdenarPorAPELLIDOySECTOR(Employee array[],int limite);

int empleado_Sueldos(Employee array[],int limite);

#endif /* EMPLEADOS_H_ */
