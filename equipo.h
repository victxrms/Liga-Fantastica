typedef struct{
	int identificador_equipo;
	char nombre_equipo[21];
}equipo;

typedef struct{
	int identificador_prop_plantilla;
	int identificador_plantilla;
	char nombre_plantilla[31];
	int presupuesto;
	int puntuacion_plantilla;
}plantilla;
