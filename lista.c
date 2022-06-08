
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void inicialización (dl_Lista * lista){

lista->inicio = NULL;

lista->fin = NULL;

lista->tamaño = 0;

}

int insercion_en_lista_vacia (dl_Lista * lista, char *dato)
{
  dl_Elemento *nuevo_elemento;
  
  if ((nuevo_elemento = (dl_Elemento *) malloc (sizeof (dl_Elemento))) == NULL)
  {return -1;}
  
  if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char))) == NULL)
  {return -1;}
  
  strcpy (nuevo_elemento->dato, dato);
  
  nuevo_elemento->siguiente = NULL;
  lista->inicio = nuevo_elemento;
  lista->fin = nuevo_elemento;
  lista->tamaño++;
  
  return 0;
}

int ins_inicio_lista(dl_Lista * lista, char *dato)
{
  dl_Elemento *nuevo_elemento;
  
  if ((nuevo_elemento = (dl_Elemento *) malloc (sizeof (dl_Elemento))) == NULL)
  {return -1;}
  
  if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char))) == NULL)
  {return -1;}
  
  strcpy (nuevo_elemento->dato, dato);
  nuevo_elemento->siguiente = lista->inicio;
  lista->inicio = nuevo_elemento;
  lista->tamaño++;
  
  return 0;
}

int ins_fin_lista(dl_Lista * lista, char *dato)
{
  dl_Elemento *nuevo_elemento;
  dl_Elemento *actual;

  if ((nuevo_elemento = (dl_Elemento *) malloc (sizeof (dl_Elemento))) == NULL)
  {return -1;}
  
  if((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char))) == NULL)
  {return -1;}
  
  strcpy(nuevo_elemento->dato, dato);
  
  actual->siguiente = nuevo_elemento;
  nuevo_elemento->siguiente = NULL;
  lista->fin = nuevo_elemento;
  lista->tamaño++;
  
  return 0;
}

int ins_después (dl_Lista * lista, char *dato, int pos){

  if (lista->tamaño < 2){return -1;}
  
  if (pos < 1 || pos >= lista->tamaño){return -1;}
  
  dl_Elemento *actual;
  dl_Elemento *nuevo_elemento;
  
  int i;
  
  if ((nuevo_elemento = (dl_Elemento *) malloc (sizeof (dl_Elemento))) == NULL)
  {return -1;}
  
  if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char))) == NULL)
  {return -1;}
  actual = lista->inicio;
  
  for (i = 1; i < pos; ++i)
  actual = actual->siguiente;
  
  if (actual->siguiente == NULL)
  {return -1;}
  
  strcpy (nuevo_elemento->dato, dato);
  nuevo_elemento->siguiente = actual->siguiente;
  actual->siguiente = nuevo_elemento;
  lista->tamaño++;
  
  return 0;
}


dl_Elemento aux;
int sup(dl_Lista *lista, int pos){

int i;

dl_Elemento *actual;

dl_Elemento *sup_elemento;

actual = lista->inicio;
sup_elemento = lista -> fin;

for (i = 1; i < pos; ++i)

actual = actual->siguiente;
sup_elemento = actual->siguiente;

if(actual->siguiente == NULL)

lista->fin = actual;
free (sup_elemento->dato);
free (sup_elemento);

lista->tamaño--;

return 0;

}

void destruir(dl_Lista *lista){

while(lista->tamaño > 0)

sup(lista,1);

}

dl_Elemento *alloc (dl_Elemento * nuevo_elemento){

if ((nuevo_elemento = (dl_Elemento *) malloc (sizeof (dl_Elemento)))
== NULL)

return NULL;

if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof
(char)))

== NULL)

return NULL;

return nuevo_elemento;

}

int supp(dl_Lista *lista, int pos);

void muestra(dl_Lista *h)
{
  dl_Elemento *actual;
  
  actual = h ->inicio;
  while(actual != NULL)
    {
      printf("%p-%s\n", actual, actual->dato);
      actual = actual -> siguiente;
      
    }
}





