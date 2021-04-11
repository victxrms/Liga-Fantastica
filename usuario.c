#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "futbolista.h"
#include "configuracion.h"

#define USER 1
#define CHRONIST 2
#define ADMIN 3

void configuracion ();
void equipo ();

void usuario(){

        int reg, useropt, regyes, i=1, j=1, val1, val2, valreg1, valreg2, user=0, ntotal, jugedit;

        usuarios usuario_tot[99];
        futbolista futbolista_tot[99];

        char userinp[9], contrinp[9], usertemp[9], newuser[9], newcontr[9];

        printf ("\t\t   Bienvenido a la Liga Fantastica\n");                    // Printea el titulo
        printf ("\t\t------------------------------------\n");

        do{                                                                     // Pantalla de inicio sesion o registro hasta que se seleccione 1 o 2
                printf ("\t\tIniciar sesion (1) | Registrarse (2)\n");
                scanf ("%d", &reg);
        } while(reg!=1 & reg !=2);

        if (reg==1) {

                printf ("Introduce tu usuario: ");
                scanf ("%s", &userinp);
                do {
                        strcpy (usertemp, usuario_tot[i].usuario);
                        val1 = strcmp(userinp, usertemp);
                        i++;
                }while (val1 != 0 || i<99);

                if (val1==1) {


                        printf ("Introduce tu contraseña: \n");
                        scanf ("%s", &contrinp);
                        val2 = strcmp(contrinp, usuario_tot[i].contrasena);
                        if (val2 == 1)
                                printf ("Inicio de sesion correcto\n");
                        else ("La contraseña es incorrecta\n");

                }else printf ("El usuario no existe\n");
        }
        else
                printf ("\t\t\tQuieres crear una cuenta?\n");                   // Pantalla de registro
        printf ("\t\t\t    Si (1) || No (2)\n");
        scanf ("%i", &regyes);
        if (regyes == 1) {
                do {
                        printf("Introduce un nombre de usuario:\n");            // Elige usuario y comprueba si ya existe, en caso de existir se repite hasta elegir uno que no exista
                        scanf("%s", &newuser );
                        do {
                                strcpy (usertemp, usuario_tot[j].user);      // Comprueba si existe o no el usuario que se ha escrito
                                valreg1 = strcmp(newuser, usertemp);
                                j++;
                        }while (valreg1 != 0 || i<99);
                        if (valreg1 == 1)
                                printf ("Este nombre de usuario ya existe\n");
                        else{
                                strcpy (newuser, usuario_tot[ntotal].user);  // Copia lo que se ha escrito en el vector en el vector de usuario para despues cargarlo
                                printf ("Usuario creado con exito\n");
                                printf("Escribe tu contraseña\n");
                                scanf("%s", &newcontr);
                                strcpy (newcontr, usuario_tot[ntotal].contrasena); // Copia lo que se ha escrito en el vector en el vector de usuario.contraseña para despues cargarlo
                        }
                }while (valreg1 == 1);
        }


        switch (usuario_tot[i].perfil_usuario){

          case 01: {
            printf ("Eres usuario, escribe un mensaje al administrador si no es asi \n");
            equipo ();

            }

          case 02: {
            printf("Eres cronista, escribe un mensaje al administrador si no es asi \n");
            do {
              printf("?Que jugador quieres editar? Introduce su identificador: \n");
              scanf("%d", &jugedit );
              printf ("El jugador es %s y su valoración actual es %d\n", futbolista_tot[jugedit].nombre_futbolista, futbolista_tot[jugedit].valoracion);
              printf("Introduce la nueva valoracion: \n");
              scanf("%d", &futbolista_tot[jugedit].valoracion);
              do {
                printf("?Quieres seguir editando jugadores?\n");
                printf("Si (1) | No (2)\n");
                scanf("%d", &reg);
              } while(reg!=1 & reg !=2);
            } while (reg=1);

          }
          case 03: {
            printf("Eres administrador, escribe un mensaje a otro administrador si no es asi \n");
            configuracion ();

          }
        }
}
