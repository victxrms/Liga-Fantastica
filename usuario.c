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
        int reg, i=0, val1, val2;

        char userinp[9], contrinp[9], userarch[9], contrarch[9], currentline[100];

        FILE *fp;
        fp = fopen ("usuarios.txt", "r");

        assert(fp != NULL);

        printf ("\t\t   Bienvenido a la Liga Fantastica\n");            // Printea el titulo
        printf ("%s", SEPARADOR);

        do{
                printf ("\t\tIniciar sesion (1) | Registrarse (2)\n");  // Pantalla de inicio sesion o registro hasta que se seleccione 1 o 2
                scanf ("%d", &reg);
        } while(reg!=1 & reg !=2);

        if (reg=1) {
                printf ("Introduce tu usuario: ");                     // Introduce usuario y comprueba si existe, si es asi introduce contraseña y comprueba contraseña.
                scanf ("%s", &userinp);                                // Si alguno de los dos es erroneo muestra mensaje de fallo
                do {
                        fscanf (fp, "%s, %s", &userarch, &contrarch);
                        val1 = strcmp(userinp, userarch);
                        if (val1=0) {
                                printf ("Introduce tu contraseña: ");
                                val2 = strcmp(contrinp, contrarch);
                                if (val2=0) {
                                        printf ("Inicio de sesion correcto\n");
                                }else printf("Contraseña incorrecta");
                        }else printf ("El usuario no existe\n");
                }while(fgets(currentline, sizeof(currentline), fp) != NULL);


        }

        fclose(fp);
}
