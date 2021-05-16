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

int sumar(float operador1, float operador2, float* pResultado)
{
	int retorno = -1;
	if(pResultado != NULL)
	{
		*pResultado = operador1 + operador2;
		retorno = 0;
	}
	return retorno;
}

int restar(float operador1, float operador2, float* pResultado)
{
	int retorno = -1;
	if(pResultado != NULL)
	{
		*pResultado = operador1 - operador2;
		retorno = 0;
	}
	return retorno;
}

int multiplicar(float operador1, float operador2, float* pResultado)
{
	int retorno = -1;
	if(pResultado != NULL)
	{
		*pResultado = operador1 * operador2;
		retorno = 0;
	}
	return retorno;
}

int dividir(float operador1, float operador2, float* pResultado)
{
	float resultado;
	int retorno = -1;
	if(pResultado != NULL)
	{
		if(operador2 != 0)
		{
			resultado = (float)operador1 / operador2;
			*pResultado = resultado;
			retorno = 0;
		}
		else
		{
			retorno = -2;
		}
	}
	return retorno;
}

int calcularFactorial(int operador, int* pResultado)
{
	int i;
	int factorial = 1;
	int retorno = -1;

	if(pResultado != NULL)
	{
		if(operador > 1)
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
			if(operador == 0)
			{
				*pResultado = 1;
				retorno= 0;
			}
			else
			{
				retorno = -2;
			}
		}
	}
	return retorno;
}



