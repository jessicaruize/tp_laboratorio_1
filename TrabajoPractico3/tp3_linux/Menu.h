/*
 * Menu.h
 *
 *  Created on: 11 jun. 2021
 *      Author: jessica
 */

#ifndef MENU_H_
#define MENU_H_

#include <stdio.h>
#include <stdlib.h>
#include "pedir_valores.h"

int menu_principal(int* respuesta);
int menu_edit(int* respuesta);
int menu_sort(int* opcion, int* criterio);
int menu_listNotEmpty(int* opcion);
int menu_salir();
#endif /* MENU_H_ */
