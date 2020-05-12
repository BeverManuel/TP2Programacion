/*
 * biblioteca.h
 *
 *  Created on: 7 abr. 2020
 *      Author: Manuel Ignacio Bever
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

int myGets(char* cadena, int longitud);

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int utn_getChar(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

void ClearScreen();

int validarNumeroFloat(char* stringRecibido);

int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

#endif /* BIBLIOTECA_H_ */
