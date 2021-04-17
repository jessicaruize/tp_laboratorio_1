/*
 * pedir_valores.h
 *
 *  Created on: 15 abr. 2021
 *      Author: jessica
 */

#ifndef PEDIR_VALORES_H_
#define PEDIR_VALORES_H_

/**
 * @fn float pedirNumero(char[])
 * @brief función que recibe un mensaje, pide un número
 * y lo devuelve por retorno.
 * @param mensaje Mensaje que va a ser recibido indicando que debe ingresar el usuario.
 * @return Va a retornar lo que el usuario ingreso.
 */
float pedirNumero(char mensaje[]);

/**
 * @fn int pedirValidarNumero(int*, char[], char[], int, int)
 * @brief Función que va a pedir numeros, los va a validar entre un mínimo y máximo
 * y los devuelve mediante un puntero, recibe un mensaje indicando al usuario que
 * debe ingresar y otro indicando error si no se encuentra entre el rango pedido.
 * devuelve retorno indicando si esta todo bien o no.
 * @param numero puntero que va a devolver el numero ingresado por el usuario.
 * @param mensaje Mensaje que va a indicar al usuario que debe ingresar.
 * @param mensajeError Mensaje de error en caso de que el numero no se encuentre en el rango pedido.
 * @param minimo Numero mínimo que el usuario va a poder ingresar
 * @param maximo Numero máximo que que usuario va a poder ingresar.
 * @return
 */
int pedirValidarNumero(int* numero, char mensaje[], char mensajeError[], int minimo, int maximo);

#endif /* PEDIR_VALORES_H_ */
