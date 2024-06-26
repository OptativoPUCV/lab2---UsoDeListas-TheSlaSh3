#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
    for (int i = 1; i <= 10; i ++)
      {
        int *elemento = (int*)malloc(sizeof(int)); 
        *elemento = i;
        pushBack(L, elemento);
      }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) 
{
  int suma = 0;
  int talla = get_size(L);
  int *numero = first(L);
  for (int i = 0 ; i < talla ; i++)
    {
      suma += *numero;
      numero = (int*) next(L);
    }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
  int *elemento = first(L);
  while (elemento != NULL)
    {
      if (*elemento == elem)
      {
        popCurrent(L);
      }
      elemento = next(L);
    }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) 
{
  Stack* PilaAuxiliar = create_stack(); //se crea la pila
  int *elemento = top(P1); //el elemento es el ultimo dato que ingresa arriba.
  while (top(P1) != NULL) //mientras el valor de mas arriba sea distinto de nada.
    {
      elemento = top(P1); //Al elemento se le asigna 
      push(PilaAuxiliar, elemento);
      pop(P1);
    }
  int *elemento2 = top(PilaAuxiliar);
  while(top(PilaAuxiliar) != NULL)
    {
      elemento2 = top(PilaAuxiliar);
      push(P1, elemento2);
      push(P2, elemento2);
      pop(PilaAuxiliar);
    }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) 
{
  Stack* Pila = create_stack();
  for (int i = 0 ; i < strlen(cadena) ; i++)
    {
      if (cadena[i] == '(')
      {
        push(Pila, &cadena[i]);
      }
      else
      {
        if (cadena[i] == ')')
        {
          if (top(Pila) == NULL)
          {
            return 0;
          }
          else
          {
            pop(Pila);
          }
        }
      }
    }
  if (top(Pila) == NULL)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

