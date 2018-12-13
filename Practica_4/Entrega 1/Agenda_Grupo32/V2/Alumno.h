#ifndef ALUMNO_H
#define ALUMNO_H

#include "Agenda.h"

using namespace std;

typedef struct alumno{

	string DNI, Nombre, Apellidos, Email, Direccion;
	int Telefono, CursoAlto, Grupo;
	bool Lider;
	float Nota;
		
}Alumno;

#endif
