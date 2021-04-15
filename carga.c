#include "carga.h"

FILE *f_equipos, *f_configuracion, *f_usuario;
equipo *total_equipos;
configuraciones *toda_config;
usuarios *total_usuarios;

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
