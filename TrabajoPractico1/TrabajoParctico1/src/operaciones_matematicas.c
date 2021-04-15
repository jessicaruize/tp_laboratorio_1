/*
 * operaciones_matematicas.c
 *
 *  Created on: 12 abr. 2021
 *      Author: jessica
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "operaciones_matematicas.h"
void sumar (float* pResultado, float operador1, float operador2)
{
	if(pResultado != NULL)
	{
		*pResultado = operador1 + operador2;
	}
}

void restar (float* pResultado, float operador1, float operador2)
{
	if(pResultado != NULL)
	{
		*pResultado = operador1 - operador2;
	}
}

void multiplicar (float* pResultado, float operador1, float operador2)
{
	if(pResultado != NULL)
	{
		*pResultado = operador1 * operador2;
	}
}

float dividir(float* pResultado, float operador1, float operador2)
{
	float resultado;
	int retorno = -1;
	if(pResultado != NULL && operador2 != 0)
	{
		resultado = (float)operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

int calcularFactorial(int* pResultado, float operador)
{
	int i;
	int factorial = 1;
	int retorno = -1;

	if(pResultado != NULL && operador > 1)
	{
		for(i=operador; i>1; i--)
		{
			factorial = factorial * i;
		}
		*pResultado = factorial;
		retorno = 0;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}



