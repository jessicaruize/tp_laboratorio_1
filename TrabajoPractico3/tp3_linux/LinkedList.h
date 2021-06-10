/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
//Es una lista dinamica. - Recibe punteros(generico) -

//constructor, crea empleado.
LinkedList* ll_newLinkedList(void);

//cuantos elemtos hay en la lista
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//agregar empleado a las lista
int ll_add(LinkedList* this, void* pElement);

//get devuelve un empleado
void* ll_get(LinkedList* this, int index);

//reemplaza un elemento
int ll_set(LinkedList* this, int index,void* pElement);
//mete un elemento ej17.3
int ll_push(LinkedList* this, int index, void* pElement);

//borra el elemento
int ll_remove(LinkedList* this,int index);
//borra el elemento y lo devuelve para poder mostrar a quien elimine.o pasar a otra lista
void* ll_pop(LinkedList* this,int index);

//Limpia la lista
int ll_clear(LinkedList* this);
//Elimina la lista-destructor
int ll_deleteLinkedList(LinkedList* this);

//se le pasa un elemento y la funcion nos dice en q indice esta, si no devuelve-1.
int ll_indexOf(LinkedList* this, void* pElement);
//pregunta si la lista esta vacia
int ll_isEmpty(LinkedList* this);

//me dice si el elemento esta en la lista
int ll_contains(LinkedList* this, void* pElement);
//dice si todos los elementos de la lista2 esta en la lista1
int ll_containsAll(LinkedList* this,LinkedList* this2);

//achica una lista desde hasta donde se le indica(from inclusivo-to exclusivo)
LinkedList* ll_subList(LinkedList* this,int from,int to);
//crea una copia identica de una lista.
LinkedList* ll_clone(LinkedList* this);

//(ordena la lista)mueve direcciones de memoria.crear funciones que devuelva el criterio de ordenamiento.
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
