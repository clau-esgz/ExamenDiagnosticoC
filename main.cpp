#include <stdio.h>
#include <stdlib.h>
//No es necesario que escribas ningún código para probar que tu arreglo dinámico funcion
//CLAUDIA ESPINOSA GUZMAN EXAMEN DIAGNOSTIGO TECNOLOGIA ORIENTADA A OBJETOS

//definicion de estructura
typedef struct nodo
{
	 int dato;
	 struct nodo *sig;
}TNodo;

//creacion de un nodo dentro de la lista
TNodo * creaNodo(int info)
{
    TNodo *nuevo = NULL;
    nuevo = (TNodo *)malloc(sizeof(TNodo));
    if (nuevo)
    {
        nuevo->dato = info;
        nuevo->sig = NULL;
    }
    return (nuevo);
}


//addAtTail -> Inserta al final del arreglo
int addAtTail(TNodo ** head, int dato)
{
	int bandera = 0;
	if (*head == NULL)
	{
		*head = creaNodo(dato);
		bandera = 1;
		return(bandera);
	}
	else
	{
	 addAtTail(&((*head)->sig),dato);
	}

}


//addAtFront -> inserta al inicio del arreglo
int addAtFront(TNodo **head, int dato)
{
	 int bandera = 0 ;
	 TNodo *nuevo;
	 nuevo = creaNodo(dato);
	 if (nuevo != NULL)// if (nuevo) hubo memoria para el nodo
	 {
	 	nuevo->sig = *head;
	 	*head = nuevo;
	 	bandera++;
	 }
	 return(bandera);
}

//size -> Indica cuántos datos se han insertado
int size(TNodo *head)
{
  TNodo *aux = NULL; //Auxiliar
  int cont;

	if(head != NULL) // es por que tiene datos
	{
	for (aux = head; aux != NULL;aux = aux->sig)
	{
		cont++;
	}
	return (cont);
    }

  return(cont);
}

//removeAll -> Borra todos los elementos insertados
int removeAll(TNodo **head)
{
	TNodo *aux;
	aux = *head;
	int bandera = 0;
	if(*head)
	{
		aux = aux->sig;
		removeAll(&aux);
		free(aux);
		bandera = 1;
	}
	return(bandera);
}


//getAt -> Recibe un índice (0-index) y devuelve el valor en esa posición si es válido

int getAt(int index,TNodo *head)
{
	int numNodos;
    TNodo *aux = NULL;
	int i  = 0;

	if(head != NULL)
	{

		numNodos = size(head);
		if (index < 0 && index > numNodos)
		{
		   return(-1);
		}


		for (aux = head; aux != NULL ; aux = aux->sig)
		{
			i++;

			if(index == i)
				return aux->dato;
		}

	}
//	return head[index];

}

