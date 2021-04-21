#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipo.h"
#include "usuario.h"
#include "carga.h"
#include "configuracion.h"
#include "futbolista.h"

#define presupuesto 1000

int ident_plantillas();
int numero_plantillas(int );
void equipo(int );

int ident_plantillas()
{
    int i, jug, ident_plant, ident_usuario;
    char nombre[21];

    plantillas=fopen("Plantillas.txt","r");

    while(fscanf("%i %s %i", &ident_plant, &nombre, &ident_usuario)==3)
    {
        for(i=0; i<11; i++)
            fscanf("%i", &jug)
    }

    fclose(plantillas);

    return ident_plant;
}

int numero_plantillas(int x)
{
    int i, num=0;

    for(i=0;i<;i++)
        if(total_plantillas[i].identificador_prop_plantilla==x)
            num++;
    return num;
}

void equipo(int x)
{
    FILE *fichero;

	int i=1, i2=0, i3=0, i4=0, n=0, j[11], salida=0, reset2, codigo, x, y;
	float precio, valor=0, diferencia;
	char user[9], menu1, c, reset;

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
            if(numero_plantillas(x)>=3)    //crear numero_plantillas
                printf("Ya tienes el numero maximo de plantillas");
            else
            {
                printf("Como quieres que se llame la nueva plantilla? (sin espacios, max 21 caracteres) --> ");
                fichero=fopen("plantillas .txt","r");
                y=contar_lineas(fichero);
                fclose(fichero);
                total_plantillas=(plantilla *)realloc(total_plantillas, (y+1)*sizeof(plantilla))
                scanf("%s", &total_plantillas.nombre_plantilla);
                total_plantillas.identificador_plantilla=y+1;
                total_plantillas.identificador_prop_plantilla=x;


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
