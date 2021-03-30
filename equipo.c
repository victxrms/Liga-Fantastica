#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *jugadores, *equipos, *plantillas;



int numero_plantillas()
{
    int n, corr, num_plant;
    char aux[3];

    plantillas=fopen("Plantillas.txt","r");

    while(aux[3]!=EOF)
    {
        fgets(aux,3,plantillas);
        n=1;
        while(n<=3)
        {
            if(aux[n]=ident[n]) //ident: numero de identificacion de usuario
            {
                corr++;
            }
            n++;

            if(corr=3)
                num_plant++;
        }
    }
    fclose(plantillas);

    return num_plant;
}


int main()
{
    int i;
    char menu1, name[25];

    do
    {
        printf("Crear nueva plantilla (1) | Ver/editar mis plantillas (2) | Borrar plantilla (3)\n");
        scanf("%c", &menu1);
        if(menu1!=1,2,3)
            printf("Comando no valido");
    }while(menu1!=1,2,3);

    switch (menu1)
    {
        case '1':
            if(numero_plantillas()>=3)    //crear numero_plantillas
                printf("Ya tienes el numero maximo de plantillas");
            else
            {
                plantillas=fopen("Plantillas.txt","rw");
                printf("Como quieres que se llame la nueva plantilla?\n");
                fgets(name,25,stdin);
                fputs(name, plantillas);        //    ?????
                


                jugadores=fopen("Jugadores.txt","r");

            }
        break;
    }
}
