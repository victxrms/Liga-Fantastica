#include <stdio.h>
#include "configuracion.h"


int config (){

int n, precio_min, precio_max, n_max_plant, n_max_jugadores, resp;
configuracion configuracion_tot [3];

do{

printf ("Que desea editar? \n\n 1-precio minimo | 2-precio maximo | 3- Numero max de plantillas |  4-Numero max de jugadores\n");
scanf ("%d", &n);


switch (n){

case 1:
printf ("Cual desea que sea el nuevo precio minimo?\n");
scanf("%d", &precio_min);
configuracion_tot [n-1].valor_campo= precio_min;
break;

case 2:
printf ("Cual desea que sea el nuevo precio maximo?\n");
scanf ("%d", &precio_max);
configuracion_tot [n-1].valor_campo= precio_max;
break;

case 3:
printf ("Cual desea que sea el nuevo numero maximo de plantillas?\n");
scanf ("%d", &n_max_plant);
configuracion_tot [n-1].valor_campo=n_max_plant;
break;

case 4:
printf ("Cual desea que sea el nuevo numero maximo de jugadores?\n");
scanf ("%d", &n_max_jugadores);
configuracion_tot [n-1].valor_campo=n_max_jugadores;
break;
}
printf ("Desea editar algo mas?\n \t (1) Si/ (2) No\n");
scanf ("%d", &resp);

 } while (resp==1);
  }
