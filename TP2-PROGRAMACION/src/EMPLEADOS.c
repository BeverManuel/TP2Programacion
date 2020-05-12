/*
 * producto.c
 *
 *  Created on: 23 abr. 2020
 *      Author: Manuel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "EMPLEADOS.h"
#include "getVarios.h"
#include "menu.h"


/**
 * \brief Pone el indice de la estructura en 1
 * \return Retorna 0 si se realizo correctamente y -1 si no
 */
int empleado_Inicializar(Employee array[],int limite){

	int retorno=1;

	if(array!=NULL && limite > 0){
		int i;
		for(i=0;i<limite;i++){
			array[i].isEmty=1;  // SI VALE 1 EMPY ESTA VACIO Y SI VALE 0 ESTA CARGADA
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Pide al usuario un ID y Borra el ID la estructura cargada por el USUARIO
 *
 */
int empleado_Borrar(Employee array[],int limite, int indice){

	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmty == 0)
	{
		array[indice].isEmty = 1;
		respuesta = 0;
	}
	return respuesta;
}

/**
 * \brief Imprime un array de Estructura cargada por el usuario
 * \return Retorna 0 si se realizo correctamente y -1 si no
 */
void empleado_Imprimir(Employee array[],int limite){

	if(array!=NULL && limite > 0)
	{
		int i;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmty==0 && array[i].sector>0)
			{
				printf("ID del empleado: %d ||| Nombre: %s -- Apellido: %s -- Sector: %d -- Salario: %.2f\n",array[i].ID,array[i].nombre,array[i].apellido,array[i].sector,array[i].salario);
			}
		}
	}
}

/**
 * \brief Buscar primer posicion vacia
 * \param arrayProductos Array de productos a ser actualizado
 * \param limite Limite del array de productos
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int empleado_getEmptyIndex(Employee* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmty == 1)
			{
				if(i==0)
				{
					respuesta = i;
				}
				if(i>0){
					respuesta = i-7;
				}
				break;
			}
		}
	}
	return respuesta;
}

/** Busca un ID en un array y devuelve la posicion en que se encuentra
* array cliente Array de Employee
* limite int es el tamaño del array
* posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado - (0) si encuentra el valor buscado
*
*/
int empleado_buscarID(Employee* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].ID == valorBuscado)
			{
				respuesta = 0;
				break;
			}
		}
	}
	return respuesta;
}

/*
 * Se le solicita un indice al sistema el cual le permitira al usuario cargar datos a la estructura de Empleados
 */
int empleado_CargarDATOS(Employee array[],int limite, int indice){

	int retorno = 1;
	if(array != NULL && limite > 0 && indice >= 0)
	{
		if((utn_getNombre(array[indice].nombre,limite,"\nIngrese el nombre del empleado: ","\nERROR - CARGA INCORRECTO\n", 3)==0) &&
			(utn_getNombre(array[indice].apellido,limite,"\nIngrese el apellidp del empleado: ","\nERROR - CARGA INCORRECTO\n", 3)==0) &&
			(utn_getNumero(&array[indice].sector,"\nIngrese el sector del empleado: ","\nERROR - CARGA INCORRECTO\n",1,9999,3)==0) &&
			(utn_getNumeroFloat(&array[indice].salario,"\nIngrese el salirio del empleado:" ,"\nERROR - CARGA INCORRECTO\n",1,999999,3)==0))
		{
			printf("\nCarga Correcta.\n");
		}
		array[indice].isEmty=0;
		array[indice].ID=indice;

		retorno=0;
	}
	return retorno;

}

/*
 * Se le solicita un indice al sistema el cual le permitira al usuario modificar datos a la estructura de Empleados
 */
int empleado_Modificar(Employee array[],int limite, int indice){

	int retorno = -1;
	int opcionMenu;

	if(array != NULL && limite > 0 && indice >= 0 && array[indice].isEmty == 0)
	{
		if(array != NULL && limite > 0 && indice >= 0)
		{

			while(opcionMenu != 5)
			{
				menuModificar();
				if(utn_getNumero(&opcionMenu,"Eliga ->\n","\n - ERROR - \n",1,5,3)==0)
				{
					switch(opcionMenu)
					{
					case 1:
						if(utn_getNombre(array[indice].nombre,limite,"\nIngrese el nombre del empleado: ","\nERROR - CARGA INCORRECTO\n", 3)==0)
						{
							printf("\nCarga Correcta.\n");
						}
						break;
					case 2:
						if(utn_getNombre(array[indice].apellido,limite,"\nIngrese el apellidp del empleado: ","\nERROR - CARGA INCORRECTO\n", 3)==0)
						{
							printf("\nCarga Correcta.\n");
						}
						break;
					case 3:
						if(utn_getNumero(&array[indice].sector,"\nIngrese el sector del empleado: ","\nERROR - CARGA INCORRECTO\n",1,9999,3)==0)
						{
							printf("\nCarga Correcta.\n");
						}
						break;
					case 4:
						if(utn_getNumeroFloat(&array[indice].salario,"\nIngrese el salirio del empleado:" ,"\nERROR - CARGA INCORRECTO\n",1,999999,3)==0)
						{
							printf("\nCarga Correcta.\n");
						}
						break;
					case 5:
						//salir - volver
						break;
					}
				}
			}
			array[indice].isEmty=0;
			array[indice].ID=indice;

			retorno=0;
			}
	}
	return retorno;
}

/*
 * Funcion central del programa
 * desde aca vamos a gestionar todos los requisitos solicitados por el usuruario para gestionar el programa
 */
void empleado_Cargar(Employee array[],int limite){

	if(array!=NULL && limite > 0)
	{

		int opcionMenu;
		int indiceModificar;
		int indiceFuncion;
		int flag = -1;
		int indiceBorrar;
		int opcionPuntoCuatro;

		while(opcionMenu != 5){

			menuPrincipal();
			if(utn_getNumero(&opcionMenu," Eliga ->\n","\n - ERROR - \n",1,5,3)==0)
			{

				switch(opcionMenu)
				{
				case 1:
					printf("\n\nAlta de empleado\n");
					indiceFuncion = empleado_getEmptyIndex(array,limite);
					//printf("%d INDICE\n",indiceFuncion);
					if(indiceFuncion >= 0)
					{
						if(empleado_CargarDATOS(array,limite,indiceFuncion) == 0)
						{
							printf("\nCarga OK\n");
							flag = 0;
						}
						else
						{
							printf("\nNO HAY MAS LUGAR\n");
						}
					}
					break;

				case 2:
					if(indiceFuncion >= 0 && flag == 0)
					{
						printf("\n\nModificar un empleado\n");
						empleado_Imprimir(array,limite);
						if(utn_getNumero(&indiceModificar,"\nIngrese el ID a modificar: ","\nERROR - INIDICE FUERA DE CAMPO\n",0,limite,3)==0)
						{
							if(empleado_buscarID(array,limite,indiceModificar)==0)
							{
								printf("\nIndice Correcto.\n");
								if(empleado_Modificar(array,limite,indiceModificar) == 0)
								{
									printf("\nModificacion realizada con exito\n");
								}
							}
							else
							{
								printf("\n\nID elegido incorrecto\n\n");
							}
						}
					}
					else
					{
						printf("\n --- NO HAY CLIENTES CARGADOS --- \n\n");
					}
					break;

				case 3:
					if(indiceFuncion >= 0 && flag == 0)
					{
						printf("\n\nBaja de empleado\n");
						empleado_Imprimir(array,limite);
						if(utn_getNumero(&indiceBorrar,"\nIngrese el ID a dar de baja: ","\nERROR - INIDICE FUERA DE CAMPO\n",0,limite,3)==0)
						{
							if(empleado_buscarID(array,limite,indiceBorrar)==0)
							{
								printf("\nIndice Correcto.\n");
								int pregunta;
								/*
								 * confirmacion si quiere borrar o no
								 */
								if(utn_getNumero(&pregunta,"Seguro que quiere borrar al empleado:\n1.SI\n2.NO","\nERROR\n",1,2,3)==0)
								{
									if(pregunta == 1 &&
											empleado_Borrar(array,limite,indiceBorrar) == 0)
									{
										printf("\nEMPLEADO DADO CON BAJA CON EXITO\n");
									}
									else
									{
										printf("\nBaja de empleado cancelada\n");
									}
								}
							}
							else
							{
								printf("\n\nID elegido incorrecto\n\n");
							}
						}
					}
					else
					{
						printf("\n --- NO HAY CLIENTES CARGADOS --- \n\n");
					}
					break;
				case 4:
					if(indiceFuncion >= 0 && flag == 0)
					{
						while(opcionPuntoCuatro != 3)
						{
							menuPuntoCuatro();
							if(utn_getNumero(&opcionPuntoCuatro," Eliga ->\n","\n - ERROR - \n",1,3,3)==0)
							{
								switch(opcionPuntoCuatro)
								{
								case 1:
									printf("\nLista de empleados:\n");
									empleado_OrdenarPorAPELLIDOySECTOR(array,limite);
									empleado_Imprimir(array,limite);
									break;
								case 2:
									printf("\nSueldos:\n");
									empleado_Sueldos(array,limite);
									break;
								case 3:
									//volvemos
									break;
								}
							}
						}
					}
					else
					{
						printf("\n --- NO HAY CLIENTES CARGADOS --- \n\n");
					}
					break;
				case 5:
					//salir
					break;
				}
			}
		}
	}
}

/*
 *  Ordena el programa por apellido y sectores
 */
int empleado_OrdenarPorAPELLIDOySECTOR(Employee array[],int limite)
{
	int retorno = -1;
	int flagSwap;
	int i;
	Employee buffer;
	if(array!=NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{											// strncmp -> se usa para comprar un texto con otro texto
				{										// DONDE ESTA 20 CAMBIARLO POR EL TAMAÑO COLOCALADO
				if(strncmp(array[i].apellido,array[i+1].apellido,TAMANO_APELLIDO) > 0 ||
				   (strncmp(array[i].apellido,array[i+1].apellido,TAMANO_APELLIDO) == 0 &&
				    array[i].sector < array[i+1].sector))
					{
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1] = buffer;
					}
				}
			}
			limite--;
		}while(flagSwap);
	}
	return retorno;
}

/*
 * Se solicita un array de empleados y sus limites, el cual se va a calcular su total
 * su promedio, y contar cuantos sueldos superan el promedio
 */
int empleado_Sueldos(Employee array[],int limite)
{
	int i=0;
	int contador=0;
	float total=0;
	float promedio=0;
	int contadorEmpleados=0;
	if(array!=NULL && limite > 0)
	{
		for(i=0;i<limite-1;i++)
		{
			if(array[i].isEmty == 0)
			{
				total=array[i].salario+total;
				contador++;
			}
		}
		promedio=total/contador;
		for(i=0;i<limite-1;i++)
		{
			if(array[i].isEmty == 0 && promedio < array[i].salario)
			{
				contadorEmpleados++;
			}
		}
		printf("El total de sueldos es: %f\n",total);
		printf("El promedio de sueldos es: %.2f\n", promedio);
		printf("Los empleados que superan el promedio son: %d\n", contadorEmpleados);
	}
	return i;
}
