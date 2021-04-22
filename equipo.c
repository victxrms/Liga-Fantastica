#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipo.h"
#include "usuario.h"
#include "carga.h"
#include "configuracion.h"
#include "futbolista.h"

FILE *fichero;

int numero_plantillas(int );
void equipo(int );

int numero_plantillas(int x)
{
	int i, num=0;

	fichero=fopen("plantillas.txt","r");

	for(i=1; i<=contar_lineas(fichero); i++)
		if(total_plantillas[i].identificador_prop_plantilla==x)
			num++;

	fclose(fichero);

	return num;
}

void equipo(int x)
{


	int menu1, menu2, i=1, i2=0, reset2, y, borrar, bucle=0, editar, comp=0;
	char c, reset, full_res;

	do
	{
		do
		{
			printf("Crear nueva plantilla (1) | Ver/editar mis plantillas (2) | Borrar plantilla (3)\n");
			fflush(stdin);
			scanf("%i", &menu1);
			if(menu1!=1&&menu1!=2&&menu1!=3)
				printf("Comando no valido\n");
		}while(menu1!=1&&menu1!=2&&menu1!=3);

		switch (menu1)
		{
		case '1':
			if(numero_plantillas(x)>=3)
				printf("Ya tienes el numero maximo de plantillas");
			else
			{
				printf("Como quieres que se llame la nueva plantilla? (sin espacios, max 21 caracteres) --> ");

				fichero=fopen("plantillas .txt","r");
				y=contar_lineas(fichero);
				fclose(fichero);

				total_plantillas=(plantilla *)realloc(total_plantillas, (y+1)*sizeof(plantilla));

				fflush(stdin);
				scanf("%s", &total_plantillas.nombre_plantilla);

				total_plantillas.identificador_plantilla=y+1;
				total_plantillas.identificador_prop_plantilla=x;

				i=1;
				i2=0;

				fichero=fopen("jugadores.txt","r");

				printf("Codigo    Equipo    Nombre                        Valor(M)  Puntos    Puntos totales\n\n");
				while((c = getc(fichero)) != EOF)
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
						}

						i2++;
						if(i2==6)
							i2=0;
					}
				}

				fclose(fichero);

				do
				{
					do
					{
						printf("\n\n");

						do
						{
							printf("Introduzca el codigo de su portero (numeros 1, 5, 9 ,13...) --> ");
							fflush(stdin);
							scanf("%i", &total_plantillas.jugadores[0]);
							if(total_plantillas.jugadores[0]%4!=1||total_plantillas.jugadores[0]>80)
								printf("Codigo no existente o no es portero.\n");
						}while(total_plantillas.jugadores[0]%4!=1||total_plantillas.jugadores[0]>80);

						do
						{
							printf("Introduzca el codigo de sus cuatro defensas (separados por espacios) (numeros 2, 6, 10 ,14...) --> ");
							fflush(stdin);
							scanf("%i %i %i %i", &j[1], &j[2], &j[3], &j[4]);
							if(total_plantillas.jugadores[1]%4!=2||total_plantillas.jugadores[2]%4!=2||total_plantillas.jugadores[3]%4!=2||total_plantillas.jugadores[4]%4!=2||total_plantillas.jugadores[1]>80||total_plantillas.jugadores[2]>80||total_plantillas.jugadores[3]>80||total_plantillas.jugadores[4]>80)
								printf("Codigo/s no existente/s o no es/son defensa/s.\n");
						}while(total_plantillas.jugadores[1]%4!=2||total_plantillas.jugadores[2]%4!=2||total_plantillas.jugadores[3]%4!=2||total_plantillas.jugadores[4]%4!=2||total_plantillas.jugadores[1]>80||total_plantillas.jugadores[2]>80||total_plantillas.jugadores[3]>80||total_plantillas.jugadores[4]>80);

						do
						{
							printf("Introduzca el codigo de sus tres centrocampistas (separados por espacios) (numeros 3, 7, 11 ,15...) --> ");
							fflush(stdin);
							scanf("%i %i %i", &j[5], &j[6], &j[7]);
							if(total_plantillas.jugadores[5]%4!=3||total_plantillas.jugadores[6]%4!=3||total_plantillas.jugadores[7]%4!=3||total_plantillas.jugadores[5]>80||total_plantillas.jugadores[6]>80||total_plantillas.jugadores[7]>80)
								printf("Codigo/s no existente/s o no es/son centrocampista/s.\n");
						}while(total_plantillas.jugadores[5]%4!=3||total_plantillas.jugadores[6]%4!=3||total_plantillas.jugadores[7]%4!=3||total_plantillas.jugadores[5]>80||total_plantillas.jugadores[6]>80||total_plantillas.jugadores[7]>80);

						do
						{
							printf("Introduzca el codigo de sus tres delanteros (separados por espacios) (numeros 4, 8, 12 ,16...) --> ");
							fflush(stdin);
							scanf("%i %i %i", &j[8], &j[9], &j[10]);
							if(total_plantillas.jugadores[8]%4!=0||total_plantillas.jugadores[9]%4!=0||total_plantillas.jugadores[10]%4!=0||total_plantillas.jugadores[8]>80||total_plantillas.jugadores[9]>80||total_plantillas.jugadores[10]>80)
								printf("Codigo/s no existente/s o no es/son delantero/s.\n");
						}while(total_plantillas.jugadores[8]%4!=0||total_plantillas.jugadores[9]%4!=0||total_plantillas.jugadores[10]%4!=0||total_plantillas.jugadores[8]>80||total_plantillas.jugadores[9]>80||total_plantillas.jugadores[10]>80);

						printf("\n");

						for(i=0; i<11; i++)
							printf("%i ", total_plantillas.jugadores[i]);

						printf("\n\nSon correctos estos codigos? [s/n] --> ");
						fflush(stdin);
						scanf("%c", &reset);
					}while(reset!='s'&&reset!='S');

					i=0;

					for(i=0; i<11; i++)
						total_plantillas.presupuesto+=total_futbolistas[total_plantillas.jugadores[i]].precio_futbolista;

					if(total_plantillas.presupuesto>toda_config[1].valor_campo)
					{
						printf("Su plantilla se pasa del presupuesto por %i millones. Por favor, vuelva a elegir sus jugadores.", total_plantillas.presupuesto-toda_config[1].valor_campo);
						reset2=1;
					}
					else if(total_plantillas.presupuesto<toda_config[0].valor_campo)
					{
						printf("Su plantilla esta por debajo del presupuesto por %i millones. Por favor, vuelva a elegir sus jugadores.", toda_config[0].valor_campo-total_plantillas.presupuesto);
						reset2=1;
					}
					else
					{
						for(i=0; i<11; i++)
							total_plantillas.puntuacion_plantilla+=total_futbolistas[total_plantillas.jugadores[i]].valoracion_total;
						printf("Su plantilla ha sido creada correctamente.");
						reset2=0;
					}
				}while(reset2!=0);
			}
			break;

		case 2:
			do
			{
				printf("Ver plantillas (1) | Editar plantilla (2)\n");
				fflush(stdin);
				scanf("%i", &menu2);

				if(menu2!=1&&menu2!=2)
					printf("Comando no valido");
			}while(menu1!=1&&menu2!=2);

			switch(menu2)
			{
			case 1:
				fichero=fopen("plantillas.txt","r");
				y=contar_lineas(fichero);
				fclose(fichero);

				for(i=0; i<y; i++)
					if(total_plantillas[i].identificador_prop_plantilla==x)
					{
						printf("Codigo:%i\nNombre:%s\nValor total:%i Millones\nPuntuacion total:%i puntos\nJugadores:\n");
						for(i2=0; i2<11; i2++);
						{
							printf("\t%s - %s - Puntuacion individual: %i\n", total_futbolistas[total_plantillas.jugadores[i2]].nombre_futbolista, total_equipos[total_futbolistas[total_plantillas.jugadores[i2]].identificador_equipo_pertenece-1].nombre_equipo, total_futbolistas[total_plantillas.jugadores[i2]].valoracion_total);
						}
						printf("\n");
					}

				break;

			case 2:
				printf("Que plantilla quiere editar? (Escriba el codigo de plantilla)\n");

				fichero=fopen("plantillas.txt","r");
				y=contar_lineas(fichero);
				fclose(fichero);

				for(i=0; i<y; i++)
					if(total_plantillas[i].identificador_prop_plantilla==x)
						printf("%i %s\n", total_plantillas[i].identificador_plantilla, total_plantillas[i].nombre_plantilla);

				fflush(stdin);
				scanf("%i", &editar);

				for(i=0; i<y; i++)
				{
					if(total_plantillas[i].identificador_prop_plantilla==x&&total_plantillas[i].identificador_plantilla==editar)
					{
						comp=1;
						printf("Como quiere que pase a llamarse esta plantilla? (sin espacios, max 21 caracteres) --> ");
						limpiar(total_plantillas[i].nombre_plantilla);
						fflush(stdin);
						scanf("%s", &total_plantillas[i].nombre_plantilla);
					}
				}
				if(comp=0)
					printf("Plantilla inexistente o no es suya.\n");
				else
				{
					comp=0;
					printf("Plantilla renombrada correctamente.\n");
				}
				break;

			default:
				printf("Ha ocurrido un error. El programa se cerrara.");
				exit(1);
			}
			break;

		case 3:
			printf("Que plantilla quiere borrar? (Escriba el codigo de plantilla)\n");

			fichero=fopen("plantillas.txt","r");
			y=contar_lineas(fichero);
			fclose(fichero);

			for(i=0; i<y; i++)
				if(total_plantillas[i].identificador_prop_plantilla==x)
					printf("%i %s\n", total_plantillas[i].identificador_plantilla, total_plantillas[i].nombre_plantilla);

			fflush(stdin);
			scanf("%i", &borrar);

			for(i=0; i<y; i++)
			{
				if(bucle=1)
				{
					total_plantillas[i].identificador_plantilla=total_plantillas[i].identificador_plantilla-1;
					total_plantillas[i]=total_plantillas[i-1];
				}
				if(total_plantillas[i].identificador_prop_plantilla==x&&total_plantillas[i].identificador_plantilla==borrar)
					bucle=1;
			}
			if(bucle=0)
				printf("Plantilla inexistente o no es suya.\n");
			else
			{
				total_plantillas=(plantilla *)realloc(total_plantillas, (y-1)*sizeof(plantilla));
				bucle=0;
				printf("Su plantilla ha sido borrada correctamente.\n");
			}
			break;

		default:
			printf("Ha ocurrido un error. El programa se cerrara.");
			exit(1);
		}

		printf("Desea realizar alguna otra operacion? [s/n] --> ");
		fflush(stdin);
		scanf("%c", &full_res);
	}while(full_res=='s'||full_res=='S');

	exit(0);
}
