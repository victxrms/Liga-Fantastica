#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "usuario.h"

#define SEPARADOR "\t\t------------------------------------\n"
#define USER 1
#define CHRONIST 2
#define ADMIN 3



int main (void){
  int reg, i=0;

  char userinp, contrinp, userarch, contrarch, currentline [100];

  FILE*fp = fopen ("usuarios.txt", "r");

  assert(fp != NULL);



  printf ("\t\t   Bienvenido a la Liga Fantastica\n");
  printf ("%s", SEPARADOR);

  do{
    printf ("\t\tIniciar sesion (1) | Registrarse (2)\n");
    scanf ("%d", &reg);
  } while(reg!=1 & reg !=2);

  if (reg=1){
    printf ("Introduce tu usuario: ");
    scanf ("%s", &userinp);
    while (fgets(currentline, sizeof(currentline), fp) != NULL){
      fscanf (fp, "%s, %s", userarch, contrarch);
      printf("%s\n", userarch );
      printf("%s\n", contrarch );
    }

  }




}
