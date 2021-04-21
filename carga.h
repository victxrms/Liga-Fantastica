#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuracion.h"
#include "equipo.h"
#include "futbolista.h"
#include "usuario.h"
int contar_lineas(FILE *);
void limpiar(char *);
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
equipo *total_equipos;
configuraciones *toda_config;
usuarios *total_usuarios;
futbolista *total_futbolistas;
plantilla *total_plantillas;
int lineas_config, lineas_equipos, lineas_usuarios, lineas_futbolistas, lineas_plantillas, lineas_jugadores_plantillas;
