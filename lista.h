typedef struct dl_Elemento_Lista
{
  char *dato;
  struct dl_Elemento_Lista *siguiente;
} dl_Elemento;


typedef struct dl_ListaIdentificar
{
  dl_Elemento *inicio;
  dl_Elemento *fin;
  int tamaño;
} dl_Lista;

/* inicialización de la liste */

//void inicialización (dl_Lista * lista);

dl_Elemento *alloc (dl_Elemento * nuevo_elemento);

/* INSERCION */

//int ins_en_lista_vacia (dl_Lista * lista, char *dato);

int ins_inicio_lista(dl_Lista * lista, char *dato);

int ins_fin_lista(dl_Lista * lista, char *dato);

int insercion_en_lista_vacia (dl_Lista * lista, char
*dato);


/*ELIMINACION*/

int sup(dl_Lista *liste, int pos);

void muestra (dl_Lista * lista);

/**************************/

void destruir (dl_Lista * lista);

/* ——– FIN lista.h ——— */