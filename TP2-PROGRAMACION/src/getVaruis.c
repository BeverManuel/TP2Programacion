/*
 * getVaruis.c
 *
 *  Created on: 4 may. 2020
 *      Author: Manuel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"
#include "getVarios.h"

int utn_getEmail(char* mensaje, char* mensajeError, int longitud, int reintentos, char* pResultado)
{
    int retorno=-1;
    char bufferString[longitud];

    if(mensaje!=NULL && mensajeError!=NULL && reintentos>=0 && pResultado!=NULL)
    {
        do
        {
        	printf("%s",mensaje);
        	if(myGets(bufferString,sizeof(bufferString)) == 0) //==0 sin errores !0
            {
                if(isValidEmail(bufferString)==1)
                {
                    strncpy(pResultado,bufferString,longitud);
                    retorno=0;
                    break;
                }
                else
                {
                	printf("%s",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


/** \brief validar que sea un email .
*
*\param char* stringrecibido.
*\param revisa la cadena cumpla con las condiciones
*\return status -1 si hay error, 0 si  esta todo bien
*
*/
int isValidEmail(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
