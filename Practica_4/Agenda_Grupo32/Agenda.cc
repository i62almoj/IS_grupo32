#include "Agenda.h"

Agenda::Agenda(list<Alumno> Alumnos){


}

void Agenda::BuscarAlumno(Alumno a){

	Alumnos_.clear();

	FILE * fichero=NULL;
	fichero=fopen("BaseDatos.bin", "rb");

	if(fichero==NULL){

		printf("ERROR al abrir el fichero de la base de datos");
		exit(-1);
	}

	

	fclose(fichero);
}

void Agenda::AnadirAlumno(Alumno a)
{
	string DNI, Nombre, Apellidos, Email, Direccion, Lid;
	int Telefono, CursoAlto, Grupo;
	bool Lider;
	float Nota;

	Alumnos_.clear();

	FILE * fichero=NULL;
	fichero=fopen("BaseDatos.bin", "ab");

	if(fichero==NULL){

		printf("ERROR al abrir el fichero de la base de datos");
		exit(-1);
	}

	cout<<"Introduzca el DNI del alumno: ";
	cin>>DNI;
	a.setDNI(DNI);
	cout<<"Introduzca el nombre del alumno: ";
	cin>>Nombre;
	a.setNombre(Nombre);
	cout<<"Introduzca los apellidos del alumno: ";
	cin>>Apellidos;
	a.setApellidos(Apellidos);
	cout<<"Introduzca el email del alumno: ";
	cin>>Email;
	a.setEmail(Email);
	cout<<"Introduzca la dirección del alumno: ";
	cin>>Direccion;
	a.setDireccion(Direccion);
	cout<<"Introduzca el teléfono del alumno: ";
	cin>>Telefono;
	a.setTelefono(Telefono);
	cout<<"Introduzca curso más alto matriculado del alumno: ";
	cin>>CursoAlto;
	a.setCursoAlto(CursoAlto);
	cout<<"Introduzca el grupo del alumno: ";
	cin>>Grupo;
	a.setGrupo(Grupo);
	cout<<"Introduzca si es líder o no el alumno(S/N): ";
	cin>>Lid;
	if(Lid=="S"){

		Lider=true;

	}else if(Lid=="N"){

		Lider=false;
	}
	a.setLider(Lider);
	cout<<"Introduzca la nota del alumno: ";
	cin>>Nota;
	a.setNota(Nota);

	fwrite(&a, sizeof(Alumno), 1, fichero);

	fclose(fichero);
}

void Agenda::ModificarAlumno(Alumno a){

	
}

void Agenda::Eliminar(){

	
}

void Agenda::EliminarAlumno(Alumno a){

	
}

void Agenda::EliminarTodos(){

	
}

void Agenda::BuscarAlumno(Alumno a){

	
}