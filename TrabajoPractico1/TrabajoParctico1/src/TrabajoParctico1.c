/*
 ============================================================================
 Name        : TrabajoParctico1.c
 Author      : Ruiz Espada Jessica Johanna.
 División	 : 1°B
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
#include "pedir_valores.h"

int main(void)
{
	int opciones;
	int respuesta;
	int respuestaSumar;
	int respuestaRestar;
	int respuestaMultiplicar;
	int respuestaDividir;
	int respuestaFactorial1;
	int respuestaFactorial2;
	int resultadoFactorial1;
	int resultadoFactorial2;
	int flag1;
	int flag2;
	int flag3;
	float operador1;
	float operador2;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;

	flag1 = 1;
	flag2 = 1;
	flag3 = 1;

	setbuf(stdout, NULL);
	printf("_____________________________________\n\n	C A L C U L A D O R A  \n_____________________________________\n\n");

	do
	{
		printf("\nMENU.\n\n1. Ingresar 1er operando (A = %.2f). \n2. Ingresar 2do operando (B = %.2f). \n", operador1, operador2);
		respuesta = pedirValidarNumero (&opciones,"3. Calcular todas las operaciones. \n4. Informar resultados. \n5. Salir.\n\nIngrese la opción que desea realizar: ", 1, 5);

		if(respuesta == 0)
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
					if(flag2==1 && flag1==0)
					{
					operador2 = pedirNumero("\nIngresar 2do operador: \n");
					flag2=0;
					}
					else
					{
						printf("\nYa ingreso el 2do operador y/o le falta ingresar el 1er operador.\n");
					}
				break;
				case 3:
					if(flag2==0)
					{
						printf("\n	C  A  L  C  U  L  A  N  D  O  .  .  .\n");
						respuestaSumar = sumar(operador1, operador2, &resultadoSuma);
						respuestaRestar = restar(operador1, operador2, &resultadoResta);
						respuestaMultiplicar = multiplicar (operador1, operador2, &resultadoMultiplicacion);
						respuestaDividir = dividir(operador1, operador2, &resultadoDivision);
						respuestaFactorial1 = calcularFactorial(operador1, &resultadoFactorial1);
						respuestaFactorial2 = calcularFactorial(operador2, &resultadoFactorial2);
						flag3 = 0;
					}
					else
					{
						printf("\nLe falta ingresar el 1er operador y/o el 2do.\n");
					}
				break;
				case 4:

					if(flag3 == 0)
					{
						if(respuestaSumar == 0)
						{
							printf("\na) El resultado de %.2f + %.2f es: %.2f ", operador1, operador2, resultadoSuma);
						}
						else
						{
							printf("\nERROR, intente nuevamente, por favor.");
						}
						if(respuestaRestar == 0)
						{
							printf("\nb) El resultado de %.2f - %.2f es: %.2f ", operador1, operador2, resultadoResta);
						}
						else
						{
							printf("\nERROR, intente nuevamente, por favor.");
						}
						if(respuestaDividir==0)
						{
							printf("\nc) El resultado de %.2f / %.2f es: %.2f", operador1, operador2, resultadoDivision);
						}
						else
						{
							if(respuestaDividir == -2)
							{
								printf("\nc) No es posible dividir por cero");
							}
							else
							{
								printf("\nERROR, intente nuevamente, por favor.");
							}
						}
						if(respuestaMultiplicar == 0)
						{
							printf("\nd) El resultado de %.2f X %.2f es: %.2f ", operador1, operador2, resultadoMultiplicacion);
						}
						else
						{
							printf("\nERROR, intente nuevamente, por favor.");
						}
						if(respuestaFactorial1==0)
						{
							printf("\ne) El factorial de %.2f es: %d y ", operador1, resultadoFactorial1);
						}
						else
						{
							printf("\ne) No es posible calcular el factorial de %.2f y ", operador1);
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
		else
		{
			printf("\nERROR, intente nuevamente, por favor.\n");
		}
	}while(opciones != 5);
	printf("_____________________________________\n\n	G  R  A  C  I  A  S \n_____________________________________");

	return EXIT_SUCCESS;
}

