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

    for(int i=-1, i<x, i++)
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



void equipo()
{
    int i, opt, codigo[10];
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
                        printinpos(40, string[]);
                }while(opt!=1);

                rewind(jugadores);

                printf("\n\nIntroduzca el codigo de su portero -->");

                do
                {
                    scanf("%i", &codigo[0]);
                    if(codigo[0]%4=1&&codigo[0]<=80)
                    {
                        //escribir en txt
                    }
                    else
                        printf("El jugador no existe o no es un portero.\n\nVuelva a introducir el codigo -->");
                }while(codigo[0]%4!=1||codigo[0]>80);

                printf("\n\nIntroduzca el codigo de sus cuatro defensas (separados por espacios) -->");

                do
                {
                    scanf("%i%i%i%i", &codigo[1], &codigo[2], &codigo[3], &codigo[4]);
                    if(codigo[1]%4=2&&codigo[1]<=80&&codigo[2]%4=2&&codigo[2]<=80&&codigo[3]%4=2&&codigo[3]<=80&&codigo[4]%4=2&&codigo[4]<=80)
                    {
                        //escribir en txt
                    }
                    else
                        printf("Uno/varios de los jugadores no existen o no son un defensa.");
                }while(codigo[1]%4!=2||codigo[1]>80||codigo[2]%4!=2||codigo[2]>80||codigo[3]%4!=2||codigo[3]>80||codigo[4]%4!=2||codigo[4]>80);

                printf("\n\nIntroduzca el codigo de sus tres centrocampistas (separados por espacios) -->");

                do
                {
                    scanf("%i%i%i", &codigo[5], &codigo[6], &codigo[7]);
                    if(codigo[5]%4=2&&codigo[5]<=80&&codigo[6]%4=2&&codigo[6]<=80&&codigo[7]%4=2&&codigo[7]<=80)
                    {
                        //escribir en txt
                    }
                    else
                        printf("Uno/varios de los jugadores no existen o no son un defensa.");
                }while(codigo[5]%4!=2||codigo[5]>80||codigo[6]%4!=2||codigo[6]>80||codigo[7]%4!=2||codigo[7]>80);

                printf("\n\nIntroduzca el codigo de sus tres delanteros (separados por espacios) -->");

                do
                {
                    scanf("%i%i%i", &codigo[8], &codigo[9], &codigo[10]);
                    if(codigo[8]%4=2&&codigo[8]<=80&&codigo[9]%4=2&&codigo[9]<=80&&codigo[10]%4=2&&codigo[10]<=80)
                    {
                        //escribir en txt
                    }
                    else
                        printf("Uno/varios de los jugadores no existen o no son un defensa.");
                }while(codigo[8]%4!=2||codigo[8]>80||codigo[9]%4!=2||codigo[9]>80||codigo[10]%4!=2||codigo[10]>80);

                printf("Sus jugadores son:");

                for(i=0,i<=10,i++)
                {
                    fgets()
                }

            }
        break;
    }
}
