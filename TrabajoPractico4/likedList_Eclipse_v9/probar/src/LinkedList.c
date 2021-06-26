#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* aux = NULL;
	int i;
	if(this != NULL && nodeIndex > -1 && nodeIndex < ll_len(this))
	{
		aux = this->pFirstNode;
		if(aux != NULL)
		{
			if(nodeIndex > 0)
			{
				for(i = 0; i < nodeIndex; i++)
				{
					aux = aux->pNextNode;
				}
			}
		}
	}
    return aux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{//crear nodo -- validar
    int returnAux = -1;
    Node* creado = NULL;
    Node* encontrado = NULL;
    if(this != NULL && nodeIndex > -1 && nodeIndex <= ll_len(this))
    {
		creado = (Node*)malloc(sizeof(Node));
		if(creado != NULL)
		{
			creado->pElement = pElement;
			//creado->pNextNode = NULL;
			if(nodeIndex == 0)
			{
				creado->pNextNode = this->pFirstNode;
				this->pFirstNode = creado;
			}
			else
			{
				encontrado = getNode(this, nodeIndex-1);
				if(encontrado != NULL)
				{
					creado->pNextNode = encontrado->pNextNode;
					encontrado->pNextNode = creado;
				}
			}
			this->size ++;
			returnAux = 0;
		}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{//llama a addnode - si la lista esta vacia(node index-int) (size =0)enganchar al nodo con firsnode, sino con el ultimo node y el nuevo nodo apunta a null
    int returnAux = -1;
    if(this != NULL && !addNode(this, ll_len(this), pElement))
    {
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode = NULL;
    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	returnAux = pNode->pElement;
    }
    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    if(this!= NULL && index > -1 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL)
    	{
			pNode->pElement = pElement;
			returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* encontrado;
    Node* anterior;
    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	encontrado = getNode(this, index);
    	if(index == 0)
    	{
    		this->pFirstNode = encontrado->pNextNode;
    	}
    	else
    	{
    		anterior = getNode(this, index-1);
    		anterior->pNextNode = encontrado->pNextNode;
    	}
    	this->size--;
    	returnAux = 0;
    }
    return returnAux;
}//elimina un nodo

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{//llama a remove-recorre linkedlist y borra cada nodo con el remove del ultimo al inicio
    int returnAux = -1;
    int cantidad;
    int i;
    if(this != NULL)
    {
    	cantidad = ll_len(this);
    	if(cantidad > -1)
    	{
    		cantidad--;
    		for(i= cantidad; i>-1; i--)
    		{
    			ll_remove(this, i);
    		}
    		returnAux = 0;
    		this->size = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{//llama al clear
    int returnAux = -1;
    if(this != NULL && !ll_clear(this))
    {
    	free(this);
    	this = NULL;
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int cantidad;
    Node* pNodo;
    if(this != NULL)
    {
    	cantidad = ll_len(this);
    	if (cantidad > -1)
    	{
    		cantidad --;
    		while(cantidad > -1)
    		{
    			pNodo = getNode(this, cantidad);
    			if(pNodo->pElement == pElement)
    			{
    				returnAux = cantidad;
    				break;
    			}
    			cantidad--;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;// error
    int size;
    if(this != NULL)
    {
    	size = ll_len(this);
    	returnAux = 1; //lista vacia.
    	if(size > 0)
    	{
    		returnAux = 0; // no esta vacia.
    	}
    }

    return returnAux;
}
/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && !addNode(this, index, pElement))
	{
		returnAux = 0;
	}
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* pNode;
    if(this != NULL && index > -1 && index < ll_len(this))
    {
    	pNode = getNode(this, index);
    	if(pNode != NULL && !ll_remove(this, index))
    	{
    		returnAux = pNode->pElement;
    	}
    }
    return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
	if(this != NULL)
	{
		returnAux = 0;
		if(ll_indexOf(this, pElement) > -1)
		{
			returnAux = 1;
		}
	}
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{//llamar al contains
    int returnAux = -1;
    int cantidad2;
    int i;
    void* elemento2;
    if(this != NULL && this2 != NULL)
    {
    	returnAux = 0; //elementos this2 no estan en this1
    	cantidad2 = ll_len(this2);
    	for(i= 0; i < cantidad2; i++)
    	{
    		elemento2 = ll_get(this2, i);
    		returnAux = 1; //esta en la lista
			if(!ll_contains(this, elemento2))
			{
				returnAux = 0;
				break;
			}
    	}
    }
    return returnAux;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNode;
    int i;
    if(this != NULL && from > -1 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		for(i = from; i < to; i++)
    		{
    			pNode = getNode(this, i);
    			ll_add(cloneArray, pNode->pElement);
    		}
    	}
    }
    return cloneArray;
}




/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{//valorFunc : -1 ->E1<E2 / 0 ->E1=E2 / 1 -> E1>E2
    int returnAux =-1;
    int i;
    int valorFunc;
    int bandera = 1;
    void* pElemento1;
    void* pElemento2;
    if (this != NULL && pFunc != NULL && order > -1 && order < 2)
    {
    	do
    	{
    		bandera = 0;
    		for(i = 0; i < ll_len(this)-1; i++) // crear variable len
    		{
    			pElemento1 = ll_get(this, i);
    			pElemento2 = ll_get(this, i+1);
    			if(pElemento1 != NULL && pElemento2 != NULL)
    			{
    				valorFunc = pFunc(pElemento1, pElemento2);
    				if((order == 1 && valorFunc == 1) || (order == 0 && valorFunc == -1))
    				{
    					ll_set(this, i, pElemento2);
    					ll_set(this, i+1, pElemento1);
    					bandera = 1;
    					returnAux = 0;
    				}
    			}
    		}
    	}while(bandera == 1);
	}
    return returnAux;
}

