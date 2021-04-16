/*
 * pedir_valores.c
 *
 *  Created on: 15 abr. 2021
 *      Author: jessica
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

float pedirNumero(char mensaje[])
{
	float auxiliar;
	printf("%s",mensaje);
	scanf("%f", &auxiliar);
	return auxiliar;
}

int pedirValidarNumero(int* numero, char mensaje[], int minimo, int maximo)
{
	int respuesta = -1;
	int auxiliar;
	printf("%s",mensaje);
	scanf("%d", &auxiliar);
	if(numero != NULL)
	{
		while(auxiliar < minimo || auxiliar > maximo)
		{
			printf("ERROR, ingrese un número del %d al %d : ", minimo, maximo);
			scanf("%d", &auxiliar);
		}
		respuesta=0;
		*numero = auxiliar;
	}

	return respuesta;
}
