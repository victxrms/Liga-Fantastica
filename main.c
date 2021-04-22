#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga.h"

void usuario ();
void carga_equipos();
void carga_configuracion();
void carga_usuario();
void carga_futbolistas();
void carga_plantillas();

void descarga_configuracion();
void descarga_usuario();
void descarga_futbolistas();
void descarga_plantillas();
void descarga_equipos();

int main (){

        carga_equipos();                //Carga los archivos a la memoria principal
        carga_configuracion();
        carga_usuario();
        carga_futbolistas();
        carga_plantillas();

        usuario ();                     //Se ejecuta el modulo usuario a traves del cual se redirecciona al resto

        printf ("\t\tGracias por jugar Liga Fantastica\n");

        descarga_configuracion();       //Se descargan los cambios en los archivos desde la memoria principal
        descarga_usuario();             //para que haya una permanencia de los datos.
        descarga_futbolistas();
        descarga_plantillas();
        descarga_equipos();


}
