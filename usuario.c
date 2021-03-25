#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"

#define USER 1
#define CHRONIST 2
#define ADMIN 3


int main(){
        int reg, i=1, val1, val2, user=0, con;

        usuario usuario_tot[99];

        char userinp[9], contrinp[9], usertemp [9];

        printf ("\t\t   Bienvenido a la Liga Fantastica\n");            // Printea el titulo
        printf ("\t\t------------------------------------\n");

        do{
                printf ("\t\tIniciar sesion (1) | Registrarse (2)\n");  // Pantalla de inicio sesion o registro hasta que se seleccione 1 o 2
                scanf ("%d", &reg);
        } while(reg!=1 & reg !=2);

        if (reg==1) {

            printf ("Introduce tu usuario: ");
            scanf ("%s", &userinp);
            do {
              strcpy (usertemp, usuario_tot[i].usuario);
              val1 = strcmp(userinp, usertemp);
              i++;
            }while (val1 != 0);

            if (val1==1){

              printf ("Introduce tu contraseña: \n");
              scanf ("%s", &contrinp);
                val2 = strcmp(contrinp, usuario_tot[i].contrasena);
                  if (val2 == 1)
                    printf ("Inicio de sesion correcto\n");
                  else ("La contraseña es incorrecta\n");

            }else printf ("El usuario no existe\n");
}
}
