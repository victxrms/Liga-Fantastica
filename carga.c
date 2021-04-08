#include "carga.h"

FILE *f_equipos, *f_configuracion;
equipo *total_equipos;
configuracion *toda_config;

void limpiar(char *string)
{
        int i;
        char c;
        for(i=0; string[i]!='\0'; i++)
        {
                string[i]=' ';
        }
}

int contar_lineas(FILE *f)
{
        char c;
        int cuenta=0;
        while(!feof(f))
        {
                c=getc(f);
                if(c=='\n')
                {
                        cuenta++;
                }
        }
        return cuenta;
}


void carga_equipos()
{
        int numero_equipos, i, j;
        char letra, cad_aux[21];
        f_equipos=fopen("equipos.txt", "r");
        if(f_equipos==NULL)
        {
                printf("Se ha producido un error al abrir el fichero");
        }
        else
        {
                numero_equipos=contar_lineas(f_equipos);
                rewind(f_equipos);
                total_equipos=(equipo *)malloc(numero_equipos*sizeof(equipo));
                if(total_equipos==NULL)
                {
                        printf("error al reservar memoria \n");
                }
                else
                {
                        for(i=0; !feof(f_equipos); i++)
                        {
                                limpiar(cad_aux);
                                for(j=0; !feof(f_equipos) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_equipos);
                                        if(letra!='-')
                                        {
                                                cad_aux[j]=letra;
                                        }
                                }
                                total_equipos[i].identificador_equipo=atoi(cad_aux);
                                for(j=0; !feof(f_equipos) && letra!='\n'; j++)
                                {
                                        letra=fgetc(f_equipos);
                                        if(letra!='\n')
                                        {
                                                cad_aux[j]=letra;
                                        }
                                }
                                strcpy (total_equipos[i].nombre_equipo, cad_aux);
                        }
                }
        }
}


void carga_configuracion()
{
        int numero_config, i, j;
        char letra, cad_aux[31];
        f_configuracion=fopen("configuracion.txt", "r");
        if(f_configuracion==NULL)
        {
                printf("Se ha producido un error al abrir el fichero");
        }
        else
        {
                numero_config=contar_lineas(f_configuracion);
                rewind(f_configuracion);
                toda_config=(configuracion *)malloc(numero_config*sizeof(configuracion));
                if(toda_config==NULL)
                {
                        printf("error al reservar memoria");
                }
                else
                {
                        for(i=0; !feof(f_configuracion); i++)
                        {
                                for(j=0; !feof(f_configuracion) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_configuracion);
                                        if(letra!='-')
                                        {
                                                cad_aux[j]=letra;
                                        }
                                }
                                strcpy(toda_config[i].campo_configuracion, cad_aux);
                                limpiar(cad_aux);
                                letra='0';
                                for(j=0; !feof(f_configuracion) && letra!='\n'; j++)
                                {
                                        letra=fgetc(f_configuracion);
                                        if(letra!='\n')
                                        {
                                                cad_aux[j]=letra;
                                        }
                                }
                                toda_config[i].valor_campo=atoi(cad_aux);
                        }
                }
        }
}
