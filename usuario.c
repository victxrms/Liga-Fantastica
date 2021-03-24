#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

#define SEPARADOR "-------------------------------------\n"

int reg;

int main (){
  printf ("Bienvenido a la Liga Fantastica\n");
  printf ("%s", SEPARADOR);
  printf ("Hola mundo")
  do{
    printf ("Iniciar sesion (1) | Registrarse (2)\n");
    scanf ("%d", &reg);
  } while(reg!=1 & reg !=2);
  if (reg=1){
    printf ("Introduce usuario: ");
    scanf ("%c", &nombre_usuario);
    printf("Introduce contraseña: ");
    scanf ("%c", &contrasena);
}
}
