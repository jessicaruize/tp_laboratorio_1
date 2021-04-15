/*
 ============================================================================
 Name        : TrabajoParctico1.c
 Author      : Ruiz Espada Jessica Johanna.
 Description : 1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
2
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "operaciones_matematicas.h"
int pedirValidarNumero(int* numero, char mensaje[], int minimo, int maximo);
float pedirNumero(char mensaje[]);
int main(void)
{
	int opciones;
	float operador1;
	float operador2;
	int flag1;
	int flag2;
	int flag3;
	int respuesta;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorial1;
	int resultadoFactorial2;
	int respuestaDividir;
	int respuestaFactorial1;
	int respuestaFactorial2;
	flag1 = 1;
	flag2 = 1;
	flag3 = 1;

	setbuf(stdout, NULL);
	printf("_____________________________________\n\n	C A L C U L A D O R A  \n_____________________________________\n\n");

	do
	{
		respuesta = pedirValidarNumero (&opciones,"\nMENU.\n\n1. Ingresar 1er operando. \n2. Ingresar 2do operando. \n3. Calcular todas las operaciones. \n4. Informar resultados. \n5. Salir.\n\nIngrese la opción que desea realizar: ", 1, 5);

		if(respuesta == 0) //hacer else
		{
			switch (opciones)
			{
				case 1:
					if(flag1==1)
					{
					operador1 = pedirNumero("\nIngresar 1er operador: \n");
					flag1=0;
					}
					else
					{
						printf("\nYa ingreso el 1er operador.\n");
					}
				break;
				case 2:
					if(flag2==1)
					{
					operador2 = pedirNumero("\nIngresar 2do operador: \n");
					flag2=0;
					}
					else
					{
						printf("\nYa ingreso el 2do operador.\n");
					}
				break;
				case 3:
					if(flag1 == 0 || flag2==0)
					{
						printf("\n	C  A  L  C  U  L  A  N  D  O  .  .  .\n");
						sumar (&resultadoSuma, operador1, operador2);
						restar (&resultadoResta, operador1, operador2);
						multiplicar (&resultadoMultiplicacion, operador1, operador2);
						respuestaDividir = dividir(&resultadoDivision, operador1, operador2);
						respuestaFactorial1 = calcularFactorial(&resultadoFactorial1, operador1);
						respuestaFactorial2 = calcularFactorial(&resultadoFactorial2, operador2);
						flag3 = 0;
					}
					else
					{
						printf("\nLe falta ingresar el 1er operador y/o el 2do.\n");
					}
				break;
				case 4:
					if(flag3 == 0 && (flag1 == 0 || flag2 == 0))
					{
						printf("\na) El resultado de %.2f + %.2f es: %.2f \nb) El resultado de %.2f - %.2f es: %.2f\n", operador1, operador2, resultadoSuma, operador1, operador2, resultadoResta);
						if(respuestaDividir==0)
						{
							printf("c)El resultado de %.2f / %.2f es: %.2f\n", operador1, operador2, resultadoDivision);
						}
						else
						{
							printf("c)No es posible dividir por cero");
						}
						printf("\nd)El resultado de %.2f * %.2f es: %.2f\n", operador1, operador2, resultadoMultiplicacion);
						if(respuestaFactorial1==0)
						{
							printf("e) “El factorial de %.2f es: %d y ", operador1, resultadoFactorial1);
						}
						else
						{
							printf("e) “No es posible calcular el factorial de %.2f y ", operador1);
						}
						if(respuestaFactorial2==0)
						{
							printf("el factorial de %.2f es: %d\n", operador2, resultadoFactorial2);
						}
						else
						{
							printf("no es posible calcular el factorial de %.2f\n", operador2);
						}
					}
					else
					{
						printf("\nTenga a bien ingresar los dos operadores y luego calcular para poder ver los resultados. Gracias!\n");
					}
				break;
			}
		}
	}while(opciones != 5);
	printf("_____________________________________\n\n	G  R  A  C  I  A  S \n_____________________________________");

	return EXIT_SUCCESS;
}

int pedirValidarNumero(int* numero, char mensaje[], int minimo, int maximo)
{
	int respuesta = -1;
	int auxiliar;
	printf("%s",mensaje);
	scanf("%d", &auxiliar);
	while(auxiliar < minimo || auxiliar > maximo)
	{
		printf("ERROR, ingrese un número del %d al %d : ", minimo, maximo);
		scanf("%d", &auxiliar);
	}
	respuesta=0;
	*numero = auxiliar;
	return respuesta;
}

float pedirNumero(char mensaje[])
{
	float auxiliar;
	printf("%s",mensaje);
	scanf("%f", &auxiliar);
	return auxiliar;
}
