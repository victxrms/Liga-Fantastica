#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga.h"

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

void printinpos(int x, char texto[50])
{
    int fin=0;
    char letra;

    for(int i=-1; i<x, i++)
    {
        letra=texto[i];

        if(letra='-')
            fin=1;

        if(fin=0)
            printf("%c", &letra);
        else
            printf("%c", ' ');
    }
}



int main()
{
    int i, opt, codigo;
    char menu1, name[25], string[50];

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
                opt=0;
                do
                {
                    i=0;
                    do
                    {
                        string[i]=getc(jugadores);
                        i++;
                    }while(string[i]!='-'||string[i]!=EOF);

                    if(string[i]=EOF)
                        opt=1;

                    if(opt!=1)
                        printinpos(40, string);
                }while(opt!=1);

                rewind(jugadores);

                printf("\n\nIntroduzca el codigo de su %s -->", &posicion);
                scanf("%i", &codigo);
            }
        break;
    }
}
