#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *jugadores, *equipos, *plantillas;

int main()
{
    char menu1;

    do
    {
        printf("Crear nueva plantilla (1) | Ver mis plantillas (2) | Borrar plantilla (3)\n");
        scanf("%c", &menu1);
        if(menu1!=1,2,3)
            printf("Comando no valido");
    }while(menu1!=1,2,3);

    switch (menu1)
    {
        case '1':
        {
            if(numero_plantillas>=3)    //crear numero_plantillas
                printf("Ya tienes el numero maximo de plantillas");
            else
            {
                jugadores=fopen("Jugadores.txt","r");

            }
        }
    }
}
