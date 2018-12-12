#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "Alumno.h"
#include "Profesor.h"

using namespace std;

//list<Alumno> Alumnos_;

int BuscarAlumno(string DNI);
int BuscarAlumnoA(string Apellidos);
void AnadirAlumno();
void ModificarAlumno();
void Eliminar();
void EliminarAlumno();
void EliminarTodos();
void Mostrar();
void MostrarAlumno();
void MostrarTodos();
void MostrarGrupo();

#endif
