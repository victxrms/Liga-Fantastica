#include "carga.h"

FILE *f_equipos, *f_configuracion, *f_usuario, *f_futbolista;
equipo *total_equipos;
configuraciones *toda_config;
usuarios *total_usuarios;
futbolista *total_futbolistas;

void limpiar(char *string)
{
        int i;
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
        fclose(f_equipos);
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
                toda_config=(configuraciones *)malloc(numero_config*sizeof(configuraciones));
                if(toda_config==NULL)
                {
                        printf("error al reservar memoria");
                }
                else
                {
                        for(i=0; !feof(f_configuracion); i++)
                        {
                                limpiar(cad_aux);
                                letra='0';
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
        fclose(f_configuracion);
}


void carga_usuario()
{
        int n_usuarios, i, j;
        char cad_n_usuario[21], cad_contra[9], cad_usuario[6], letra;
        f_usuario=fopen("usuarios.txt", "r");
        if(f_usuario==NULL)
        {
                printf("error al arbir fichero usuarios \n");
        }
        else
        {
                n_usuarios=contar_lineas(f_usuario);
                rewind(f_usuario);
                total_usuarios=(usuarios *) malloc (n_usuarios*sizeof(usuarios));
                if(total_usuarios==NULL)
                {
                        printf("error al reservar memoria");
                }
                else
                {
                        for(i=0; !feof(f_usuario); i++)
                        {
                                limpiar(cad_n_usuario);
                                limpiar(cad_contra);
                                letra='0';
                                for(j=0; letra!='-' && !feof(f_usuario); j++)
                                {
                                        letra=fgetc(f_usuario);
                                        if(letra!='-')
                                        {
                                                cad_usuario[j]=letra;
                                        }
                                }
                                total_usuarios[i].identificador_usuario=atoi(cad_usuario);
                                limpiar(cad_usuario);
                                letra='0';
                                for(j=0; letra!='-'&& !feof(f_usuario); j++)
                                {
                                        letra=fgetc(f_usuario);
                                        if(letra!='-')
                                        {
                                                cad_n_usuario[j]=letra;
                                        }
                                }
                                strcpy(total_usuarios[i].nombre_usuario, cad_n_usuario);
                                limpiar(cad_n_usuario);
                                letra='0';
                                for(j=0; letra!='-' && !feof(f_usuario); j++)
                                {
                                        letra=fgetc(f_usuario);
                                        if (letra!='-')
                                        {
                                                cad_usuario[j]=letra;
                                        }
                                }
                                total_usuarios[i].perfil_usuario=atoi(cad_usuario);
                                limpiar(cad_usuario);
                                letra='0';
                                for(j=0; letra!='-' && !feof(f_usuario); j++)
                                {
                                        letra=fgetc(f_usuario);
                                        if(letra!='-')
                                        {
                                                cad_usuario[j]=letra;
                                        }
                                }
                                strcpy(total_usuarios[i].user, cad_usuario);
                                limpiar(cad_usuario);
                                letra='0';
                                for(j=0; letra!='\n' && !feof(f_usuario); j++)
                                {
                                        letra=fgetc(f_usuario);
                                        if(letra!='\n')
                                        {
                                                cad_contra[j]=letra;
                                        }
                                }
                                strcpy(total_usuarios[i].contrasena, cad_contra);
                        }
                }
        }
        fclose(f_usuario);
}


void carga_futbolistas()
{
        int n_futbolistas, i, j;
        char aux[21], letra;
        f_futbolista=fopen("futbolistas.txt", "r");
        if(f_futbolista==NULL)
        {
                printf("error al abrir fichero futbolistas \n");
        }
        else
        {
                n_futbolistas=contar_lineas(f_futbolista);
                rewind(f_futbolista);
                total_futbolistas=(futbolista *) malloc (n_futbolistas*sizeof(futbolista));
                if(total_futbolistas==NULL)
                {
                        printf("error al reservar espacio de memoria para futbolistas \n");
                }
                else
                {
                        for(i=0; !feof(f_futbolista); i++)
                        {
                                limpiar(aux);
                                letra='0';
                                for(j=0; !feof(f_futbolista) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_futbolista);
                                        if(letra!='-')
                                        {
                                                aux[j]=letra;
                                        }
                                }
                                total_futbolistas[i].identificador_futbolista=atoi(aux);
                                limpiar(aux);
                                letra='0';
                                for(j=0; !feof(f_futbolista) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_futbolista);
                                        if(letra!='-')
                                        {
                                                aux[j]=letra;
                                        }
                                }
                                total_futbolistas[i].identificador_equipo_pertenece=atoi(aux);
                                limpiar(aux);
                                letra='0';
                                for(j=0; !feof(f_futbolista) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_futbolista);
                                        if(letra!='-')
                                        {
                                                aux[j]=letra;
                                        }
                                }
                                strcpy(total_futbolistas[i].nombre_futbolista, aux);
                                limpiar(aux);
                                letra='0';
                                for(j=0; !feof(f_futbolista) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_futbolista);
                                        if(letra!='0')
                                        {
                                                aux[j]=letra;
                                        }
                                }
                                total_futbolistas[i].precio_futbolista=atoi(aux);
                                limpiar(aux);
                                letra='0';
                                for(j=0; !feof(f_futbolista) && letra!='\n'; j++)
                                {
                                        letra=fgetc(f_futbolista);
                                        if(letra!='\n')
                                        {
                                                aux[j]=letra;
                                        }
                                }
                                total_futbolistas[i].valoracion=atoi(aux);
                        }
                }
        }
        fclose(f_futbolista);
}
