#include "carga.h"
FILE *f_equipos, *f_configuracion, *f_usuario, *f_futbolista, *f_plantillas, *f_jugadores_plantilla;


void limpiar(char *string)                       //convierte todos los caracteres de una string a un espacio, asi la deja en blanco
{
        int i;
        for(i=0; string[i]!='\0'; i++)
        {
                string[i]=' ';
        }
}

int contar_lineas(FILE *f)                   //cuenta las lineas que tiene un fichero
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


void carga_equipos()                          //carga el fichero de equipos en su correspondiente estructura
{
        int i, j;
        char letra, cad_aux[21];
        f_equipos=fopen("equipos.txt", "r");
        if(f_equipos==NULL)
        {
                printf("Se ha producido un error al abrir el fichero");
        }
        else
        {
                lineas_equipos=contar_lineas(f_equipos);
                rewind(f_equipos);
                total_equipos=(equipo *)malloc(lineas_equipos*sizeof(equipo));
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


void carga_configuracion()                   //carga el fichero configuracion en su correspondiente estructura
{
        int i, j;
        char letra, cad_aux[31];
        f_configuracion=fopen("configuracion.txt", "r");
        if(f_configuracion==NULL)
        {
                printf("Se ha producido un error al abrir el fichero");
        }
        else
        {
                lineas_config=contar_lineas(f_configuracion);
                rewind(f_configuracion);
                toda_config=(configuraciones *)malloc(lineas_config*sizeof(configuraciones));
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


void carga_usuario()                             //carga el fichero usuario en su correspondiente estructura
{
        int i, j;
        char cad_n_usuario[21], cad_contra[9], cad_usuario[6], letra;
        f_usuario=fopen("usuarios.txt", "r");
        if(f_usuario==NULL)
        {
                printf("error al arbir fichero usuarios \n");
        }
        else
        {
                lineas_usuarios=contar_lineas(f_usuario);
                rewind(f_usuario);
                total_usuarios=(usuarios *) malloc (lineas_usuarios*sizeof(usuarios));
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


void carga_futbolistas()                     //carga el fichero futbolista en su correspondiente estructura
{
        int i, j;
        char aux[21], letra;
        f_futbolista=fopen("futbolistas.txt", "r");
        if(f_futbolista==NULL)
        {
                printf("error al abrir fichero futbolistas \n");
        }
        else
        {
                lineas_futbolistas=contar_lineas(f_futbolista);
                rewind(f_futbolista);
                total_futbolistas=(futbolista *) malloc (lineas_futbolistas*sizeof(futbolista));
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
                                for(j=0; !feof(f_futbolista) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_futbolista);
                                        if(letra!='-')
                                        {
                                                aux[j]=letra;
                                        }
                                }
                                total_futbolistas[i].valoracion=atoi(aux);
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
                                total_futbolistas[i].valoracion_total=atoi(aux);
                                while(!feof(f_futbolista) && letra!='\n')
                                {
                                        letra=fgetc(f_futbolista);
                                }
                        }
                }
        }
        fclose(f_futbolista);
}

void carga_plantillas()                    //carga el fichero plantillas en su correspondiente estructura
{
        int i, j, k;
        char cad_aux[31], letra;
        f_plantillas=fopen("Plantillas.txt", "r");
        if(f_plantillas==NULL)
        {
                printf("error al abrir fichero de plantillas. \n");
        }
        else
        {
                lineas_plantillas=contar_lineas(f_plantillas);
                rewind(f_plantillas);
                total_plantillas=(plantilla *) malloc(lineas_plantillas*sizeof(plantilla));
                if(total_plantillas==NULL)
                {
                        printf("error al reservar espacio de memoria para plantillas. \n");
                }
                else
                {
                        for(i=0; !feof(f_plantillas); i++)
                        {
                                limpiar(cad_aux);
                                letra='0';
                                for(j=0; !feof(f_plantillas) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_plantillas);
                                        if(letra!='-')
                                        {
                                                cad_aux[j]=letra;
                                        }
                                }
                                total_plantillas[i].identificador_prop_plantilla=atoi(cad_aux);
                                limpiar(cad_aux);
                                letra='0';
                                for(j=0; !feof(f_plantillas) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_plantillas);
                                        if(letra!='-')
                                        {
                                                cad_aux[j]=letra;
                                        }
                                }
                                total_plantillas[i].identificador_plantilla=atoi(cad_aux);
                                limpiar(cad_aux);
                                letra='0';
                                for(j=0; !feof(f_plantillas) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_plantillas);
                                        if(letra!='-')
                                        {
                                                cad_aux[j]=letra;
                                        }
                                }
                                strcpy(total_plantillas[i].nombre_plantilla, cad_aux);
                                limpiar(cad_aux);
                                letra='0';
                                for(j=0; !feof(f_plantillas) && letra!='-'; j++)
                                {
                                        letra=fgetc(f_plantillas);
                                        if(letra!='-')
                                        {
                                                cad_aux[j]=letra;
                                        }
                                }
                                total_plantillas[i].presupuesto=atoi(cad_aux);
                                limpiar(cad_aux);
                                letra='0';
                                for(j=0; !feof(f_plantillas) && letra!='\n'; j++)
                                {
                                        letra=fgetc(f_plantillas);
                                        if(letra!='\n')
                                        {
                                                cad_aux[j]=letra;
                                        }
                                }
                                total_plantillas[i].puntuacion_plantilla=atoi(cad_aux);
                                limpiar(cad_aux);
                                letra='0';
                                for(j=0; !feof(f_plantillas) && letra!='\n'; j++)
                                {
                                        for(k=0; !feof(f_plantillas) && letra!='-'; k++)
                                        {
                                                letra=fgetc(f_plantillas);
                                                if(letra!='-')
                                                {
                                                        cad_aux[k]=letra;
                                                }

                                        }
                                        total_plantillas[i].jugadores[j]=atoi(cad_aux);
                                }
                        }
                }
        }
        fclose(f_plantillas);
}

void descarga_configuracion()                         //devuelve los valores de la estructura de configuracion a su fichero
{
        f_configuracion=fopen("configuracion.txt","w");
        if(f_configuracion==NULL)
        {
                printf("error al abrir fichero \n");
        }
        else
        {
                int i=-1;
                do{
                        i++;
                        fprintf(f_configuracion,"$d-$s-$d\n",toda_config[i].identificador_configuracion, toda_config[i].campo_configuracion, toda_config[i].valor_campo);
                }while(toda_config[i+1].identificador_configuracion==toda_config[i].identificador_configuracion+1);
        }
        fclose(f_configuracion);
        free(toda_config);
}

void descarga_usuario()                      //devuelve los valores de la estructura de usuario a su fichero
{
        f_usuario=fopen("usuarios.txt","w");
        if(f_usuario==NULL)
        {
                printf("error al abrir fichero \n");
        }
        else
        {
                int i=-1;
                do{
                        i++;
                        fprintf(f_usuario, "$d-$s-$d-$s-$s\n", total_usuarios[i].identificador_usuario, total_usuarios[i].nombre_usuario, total_usuarios[i].perfil_usuario, total_usuarios[i].user, total_usuarios[i].contrasena);
                }while(total_usuarios[i+1].identificador_usuario==total_usuarios[i].identificador_usuario+1);
        }
        fclose(f_usuario);
        free(total_usuarios);
}

void descarga_futbolistas()           //devuelve los valores de la estructura de futbolistas a su fichero
{
        f_futbolista=fopen("futbolistas.txt", "w");
        if(f_futbolista==NULL)
        {
                printf("error al abrir fichero \n");
        }
        else
        {
                int i=-1;
                do{
                        i++;
                        fprintf(f_futbolista,"%d-%d-%s-%d-%d-%d-\n",total_futbolistas[i].identificador_futbolista, total_futbolistas[i].identificador_equipo_pertenece, total_futbolistas[i].nombre_futbolista, total_futbolistas[i].precio_futbolista, total_futbolistas[i].valoracion, total_futbolistas[i].valoracion_total);
                }while(total_futbolistas[i+1].identificador_futbolista==total_futbolistas[i].identificador_futbolista+1);
        }
        fclose(f_futbolista);
        free(total_futbolistas);
}

void descarga_equipos()                //devuelve los valores de la estructura de equipos a su fichero
{
        f_equipos=fopen("equipos.txt", "w");
        if(f_equipos==NULL)
        {
                printf("error al abrir fichero \n");
        }
        else
        {
                int i=-1;
                do{
                        i++;
                        fprintf(f_equipos,"%d-%s\n", total_equipos[i].identificador_equipo, total_equipos[i].nombre_equipo);
                }while(total_equipos[i+1].identificador_equipo==total_equipos[i].identificador_equipo+1);
        }
        fclose(f_equipos);
        free(total_equipos);
}


void descarga_plantillas()           // devuelve los valores de la estructura de plantillas a su fichero
{
        f_plantillas=fopen("Plantillas.txt", "w");
        if(f_plantillas==NULL)
        {
                printf("error al abrir fichero \n");
        }
        else
        {
                int i=-1, j, cuenta=0;
                do{
                        i++;
                        cuenta=0;
                        fprintf(f_plantillas,"$d-%d-%s-%d-%d",total_plantillas[i].identificador_prop_plantilla, total_plantillas[i].identificador_plantilla, total_plantillas[i].nombre_plantilla, total_plantillas[i].presupuesto, total_plantillas[i].puntuacion_plantilla);
                        for(j=0; j<11; j++)
                        {

                                fprintf(f_plantillas,"$d", total_plantillas[i].jugadores[j]);
                                if(cuenta<10)
                                {
                                        fprintf(f_plantillas, "-");
                                }
                                else
                                {
                                        fprintf(f_plantillas,"\n");
                                }
                        }
                }while(total_plantillas[i+1].identificador_plantilla==total_plantillas[i].identificador_plantilla+1);
        }
        fclose(f_plantillas);
        free(total_equipos);
}
