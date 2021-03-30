#include <stdio.h>
#include <stdlib.h>
#include "carga.h"

FILE *f_equipos;
equipo *total_equipos;

void limpiar(char *string)
{
  int i;
  char c;
for(i=0;string[i]!='\0');i++)
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
  c=getc(f)
  if(c=='\n')
{
  cuenta++;
}
}
  return cuenta;
}


void carga_equipos()
{
  int numero_equipos, i, j, num=0;
  char letra, cad_aux[21];
  f_equipos=fopen("equipos.txt", "r");
  if(f_eq==NULL)
{
  printf("Se ha producido un error al abrir el fichero");
}
  else
{
  numero_equipos=contar_lineas(f_equipos)
  rewinf(f_equipos);
  total_equipos=(equipo *)malloc(numero_equipos*sizeof(equipo));
  if(total_equipos==NULL)
{
  printf("error al reservar memoria \n");
}
  else
{
  for(i=0;!feof(f_equipos);i++)
}
  limpiar(cad_aux)
  for(j=0;!feof(f_equipos)&& letra!='-';j++)
{
  letra=fgetc(f_equipos);
    if(letra!='-')
{
    num*=10;
    num+=atoi(letra);
}
}
  equipo[i].identificador_equipo=num;
  num=0;
  for(j=0;!feof(f_equipos) && letra!='\n')
}
}
}
}
}
