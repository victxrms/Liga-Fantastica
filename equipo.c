#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga.h"

#define presupuesto 1000

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
    FILE *jugadores;
	FILE *plantillas;
	int i=1, i2=0, i3=0, i4=0, n=0, j[11], salida=0, reset2, codigo;
	float precio, valor=0, diferencia;
	char menu1, name[25], c, reset;

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

                jugadores=fopen("jugadores.txt","r");

                printf("Codigo    Equipo    Nombre                        Valor(M)  Puntos    Puntos totales\n\n");
                while((c = getc(jugadores)) != EOF)
                {
                    if(c!='-')
                    {
                        putchar(c);
                        i++;
                    }
                    else
                    {
                        switch(i2)
                        {
                        case 0:
                            for(i; i<11; i++)
                                printf(" ");
                            i=0;
                            break;

                        case 1:
                        case 3:
                        case 4:
                        case 5:
                            for(i; i<10; i++)
                                printf(" ");
                            i=0;
                            break;

                        case 2:
                            for(i; i<30; i++)
                                printf(" ");
                            i=0;
                            break;
                        default:
                            break;
                        }

                        i2++;
                        if(i2==6)
                            i2=0;
                    }
                }

                fclose(jugadores);

                do
                {
                    do
                    {
                        printf("\n\n");

                        do
                        {
                            printf("Introduzca el codigo de su portero (numeros 1, 5, 9 ,13...) --> ");
                            scanf("%i", &j[0]);
                            if(j[0]%4!=1||j[0]>80)
                                printf("Codigo no existente o no es portero.\n");
                        }while(j[0]%4!=1||j[0]>80);

                        do
                        {
                            printf("Introduzca el codigo de sus cuatro defensas (separados por espacios) (numeros 2, 6, 10 ,14...) --> ");
                            scanf("%i %i %i %i", &j[1], &j[2], &j[3], &j[4]);
                            if(j[1]%4!=2||j[2]%4!=2||j[3]%4!=2||j[4]%4!=2||j[1]>80||j[2]>80||j[3]>80||j[4]>80)
                                printf("Codigo/s no existente/s o no es/son defensa/s.\n");
                        }while(j[1]%4!=2||j[2]%4!=2||j[3]%4!=2||j[4]%4!=2||j[1]>80||j[2]>80||j[3]>80||j[4]>80);

                        do
                        {
                            printf("Introduzca el codigo de sus tres centrocampistas (separados por espacios) (numeros 3, 7, 11 ,15...) --> ");
                            scanf("%i %i %i", &j[5], &j[6], &j[7]);
                            if(j[5]%4!=3||j[6]%4!=3||j[7]%4!=3||j[5]>80||j[6]>80||j[7]>80)
                                printf("Codigo/s no existente/s o no es/son centrocampista/s.\n");
                        }while(j[5]%4!=3||j[6]%4!=3||j[7]%4!=3||j[5]>80||j[6]>80||j[7]>80);

                        do
                        {
                            printf("Introduzca el codigo de sus tres delanteros (separados por espacios) (numeros 4, 8, 12 ,16...) --> ");
                            scanf("%i %i %i", &j[8], &j[9], &j[10]);
                            if(j[8]%4!=0||j[9]%4!=0||j[10]%4!=0||j[8]>80||j[9]>80||j[10]>80)
                                printf("Codigo/s no existente/s o no es/son delantero/s.\n");
                        }while(j[8]%4!=0||j[9]%4!=0||j[10]%4!=0||j[8]>80||j[9]>80||j[10]>80);

                        printf("\n");

                        for(i=0; i<11; i++)
                            printf("%i ", j[i]);

                        printf("\n\nSon correctos estos codigos? [s/n] --> ");
                        fflush(stdin);
                        scanf("%c", &reset);
                    }while(reset!='s'&&reset!='S');

                    jugadores=fopen("jugadores2.txt","r");

                    i=0;

                    while((fscanf(jugadores, "%i %f ", &codigo, &precio)==2)&&i<11)
                    {
                        if(j[i]==codigo)
                        {
                            valor+=precio;
                            rewind(jugadores);
                            i++;
                        }
                    }

                    printf("%i", j[10]);

                    fclose(jugadores);

                    diferencia=presupuesto-valor;

                    if(diferencia>=0) //variable presupuesto
                    {
                        plantillas=fopen("plantillas.txt","a");
                        for(i=0; i<10; i++)
                            fprintf(plantillas, "%i ", j[i]);
                        fprintf(plantillas, "%i\n", j[10]);
                        fclose(plantillas);
                        printf("Su plantilla ha sido creada correctamente.");
                        reset2=0;
                    }
                    else
                    {
                        printf("Su plantilla se pasa del presupuesto por %.1f millones. Por favor, vuelva a elegir sus jugadores.", diferencia*-1);
                        reset2=1;
                    }
                }while(reset2!=0);

            }
        break;
    }
}
