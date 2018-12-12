#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <cstdlib>
#include <list>
#include "Alumno.h"
#include "Profesor.h"
using namespace std;

class Agenda 
{
	private:

		list<Alumno> Alumnos_;

	public:

		Agenda(list<Alumno> Alumnos);
		
		void BuscarAlumno(Alumno a);
		void AnadirAlumno(Alumno a);
		void ModificarAlumno(Alumno a);
		void Eliminar();
		void EliminarAlumno(Alumno a);
		void EliminarTodos();
		void Mostrar();
		void MostrarAlumno(Alumno a);
		void MostrarTodos();
		void MostrarGrupo(Alumno a);
};

#endif