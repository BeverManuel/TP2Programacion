/*
 * getVerificarVarios.h
 *
 *  Created on: 30 abr. 2020
 *      Author: Manuel
 */

#ifndef GETVARIOS_H_
#define GETVARIOS_H_

/*
 * CARGAR CUIT
 * CARGAR DNI
 * CARGAR MAIL
 */

int utn_getEmail(char* mensaje, char* mensajeError, int longitud, int reintentos, char* pResultado);

int isValidEmail(char* stringRecibido);

#endif /* GETVARIOS_H_ */
