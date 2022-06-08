


#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include "leercadena.h"
#include <signal.h>
#include <sys/types.h>

//
typedef struct Lista{
char *nombre;
int identificador;
struct Lista *sig;

}Dato;

Dato *listaDeDatos(Dato *p)
{
  p = NULL;
  return p;
}

Dato *agregar(Dato *p, char *nomb, int *pid)
{
  Dato *nuevoD, *aux;
  nuevoD = (Dato *) malloc (sizeof (Dato));
  nuevoD -> nombre = nomb;
  nuevoD -> identificador = pid;
  nuevoD -> sig = NULL;

  if(p == NULL)
  {
    p  = nuevoD;
  }
  else 
  {
    aux = p;
    while(aux -> sig != NULL)
      {
        aux = aux->sig;
      }
    aux -> sig = nuevoD;
  }
  return p;
}
/*
void destruir(Dato *m)
{
  free(m);
  
}*/

Dato *quitar(int id, Dato *m)
{
  Dato *nuevoD, *aux;
  if(m -> sig == NULL)
  {
    if(m ->identificador == id)
    {
      m = NULL;
    }
  }
  else 
  {
    nuevoD = m;
    
    while(nuevoD -> identificador != id)
      {
        nuevoD = nuevoD->sig;
        //a++;
      }
    aux = nuevoD -> sig ;
    nuevoD -> sig = aux -> sig;
    //delete aux;
    aux = NULL;
  }
  return m;  
}
void removerCaracteres(char *cadena, char *caracteres) {
  int indiceCadena = 0, indiceCadenaLimpia = 0;
  int deberiaAgregarCaracter = 1;
  // Recorrer cadena carácter por carácter
  while (cadena[indiceCadena]) {
    // Primero suponemos que la letra sí debe permanecer
    deberiaAgregarCaracter = 1;
    int indiceCaracteres = 0;
    // Recorrer los caracteres prohibidos
    while (caracteres[indiceCaracteres]) {
      // Y si la letra actual es uno de los caracteres, ya no se agrega
      if (cadena[indiceCadena] == caracteres[indiceCaracteres]) {
        deberiaAgregarCaracter = 0;
      }
      indiceCaracteres++;
    }
    // Dependiendo de la variable de arriba, la letra se agrega a la "nueva
    // cadena"
    if (deberiaAgregarCaracter) {
      cadena[indiceCadenaLimpia] = cadena[indiceCadena];
      indiceCadenaLimpia++;
    }
    indiceCadena++;
  }
  // Al final se agrega el carácter NULL para terminar la cadena
  cadena[indiceCadenaLimpia] = 0;
}
char **contar(char *nom)
{
  char cadena_string[256];
  char **comando;
  for(int i=0; (strlen(nom)-2)>i; i++ )
    {
      //cadena_string[2] ;
      cadena_string[i] = nom[i];
      
    }
  comando = de_cadena_a_vector(cadena_string);
  
  return comando;
}
//list(1, 2,null)
/*
list -> sig = 2
2 != null

list = list -sig
list(2,null)
list -> sig = null

list -> sig = nuevoDato

list(1,2,nuevoDato, Null)

*/



int main(int argc, char* argv[]) {
  char command[256];
  char aux[10];
  char **comando;
 int a;

  Dato *h = listaDeDatos(h);
  //char caracter = '&';
  //char caracterEnCadena[] = {caracter, '\0'};
  int pid = 300;
  while (1) 
  {
    int i;
    pid++;
    printf(">");
    
    leer_de_teclado(256, command);
    

    if (strcmp(command,"salir") == 0)
     { 
       break;
     }

    
    comando = de_cadena_a_vector(command);
    
    if(strstr(command, "&") != NULL)
    {
      removerCaracteres(command, "&");
      comando = de_cadena_a_vector(command);
      h= agregar(h,*comando, pid);
      i=0;
   while(comando[i])
      {
        printf("%d %s\n", pid, comando[i++]); 
      }
    }
      
    
    if (strcmp(command,"tarea") == 0)
    {
      while(h != NULL)
        {
          printf("%i %s\n", h -> identificador, h->nombre);
          h = h -> sig;
        }
      
    }int a = 301;
    if(strcmp(command,"detener") == 0)
    {
      
      //printf("escriba el identificador: ");
      //quitar(a, h);
      kill( a, SIGTERM);
    }
    
    continue;


    int rc = fork();
    assert(rc >= 0);
      if (rc == 0)
        //printf("souy hfjg");
              execvp(comando[0], comando);
      else
              wait(NULL);
  }
  return 0;
}
/*
int main()
{
  Dato *m = listaDeDatos(m);
  m = agregar(m,"hola");
  m = agregar(m,"mundo");
  while(m != NULL)
    {
      printf("%s\n", m->nombre);
      m = m -> sig;
    }
  
  //printf("%p\n", m->sig);
}*/