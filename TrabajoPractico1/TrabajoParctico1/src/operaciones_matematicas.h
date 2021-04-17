/*
 * operaciones_matematicas.h
 *
 *  Created on: 12 abr. 2021
 *      Author: jessica
 */

#ifndef OPERACIONES_MATEMATICAS_H_
#define OPERACIONES_MATEMATICAS_H_

/**
 * @fn int sumar(float, float, float*)
 * @brief función que recibe dos números decimales, los suma y
 * devuelve el resultado por parametro.
 * @param operador1 primer operando a sumar.
 * @param operador2 segundo operando a sumar.
 * @param pResultado puntero a la variables que guarda el resultado.
 * @return retorna 0 si esta todo bien, -1 si el puntero es nulo.
 */
int sumar(float operador1, float operador2, float* pResultado);

/**
 * @fn int restar(float, float, float*)
 * @brief Función que recibe dos números decimales, los resta y
 * devuelve el resultado por parametro.
 * @param operador1 Primer operador para restar.
 * @param operador2 Segundo operador para restar.
 * @param pResultado Puntero a la variables que guarda el resultado.
 * @return Retorna 0 si esta todo bien, -1 si el puntero es nulo.
 */
int restar(float operador1, float operador2, float* pResultado);

/**
 * @fn int multiplicar(float, float, float*)
 * @brief Función que recibe dos números decimales, los multiplica y
 * devuelve el resultado por parametro.
 * @param operador1 Primer operador para multiplicar.
 * @param operador2 Segundo operador para multiplicar.
 * @param pResultado Puntero a la variables que guarda el resultado.
 * @return Retorna 0 si esta todo bien, -1 si el puntero es nulo.
 */
int multiplicar(float operador1, float operador2, float* pResultado);

/**
 * @fn int dividir(float, float, float*)
 * @brief Función que recibe dos números decimales, los divide y
 * devuelve el resultado por parametro.
 * @param operador1 Primer operador para dividir.
 * @param operador2 Segundo operador para dividir.
 * @param pResultado Puntero a la variables que guarda el resultado.
 * @return Retorna 0 si esta todo bien,, -1 si el puntero es nulo y -2 si el operador2 es cero.
 */
int dividir(float operador1, float operador2, float* pResultado);

/**
 * @fn int calcularFactorial(float, int*)
 * @brief Función que recibe un operador entero, calcula su factorial y
 * devuelve el resultado por parametro.
 * @param operador Operador a ser calculado su factorial.
 * @param pResultado Puntero a la variables que guarda el resultado.
 * @return Retorna 0 si esta todo bien, -1 si el puntero es nulo y -2 si el operador es menor de cero.
 */
int calcularFactorial(int operador, int* pResultado);


#endif /* OPERACIONES_MATEMATICAS_H_ */
