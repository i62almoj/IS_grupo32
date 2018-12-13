#ifndef PROFESOR_H
#define PROFESOR_H

#include "Agenda.h"
#include "Alumno.h"

using namespace std;

typedef struct profesor{

	string ID_;
	int Rol_;
	//list <Alumno> Ptr_Agenda_;
		
}Profesor;

void CargarFichero();
void GuardarFichero();
void CargarBD();
void GuardarBD();

#endif
