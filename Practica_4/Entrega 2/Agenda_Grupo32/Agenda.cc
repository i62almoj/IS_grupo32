#include "Agenda.h"

using namespace std;

bool Agenda::BuscarAlumno(string DNI){
	
	list<Alumno>::iterator it;
	
	for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
		if((*it).getDNI()==DNI){
			
			return true;
		}
	}
	
	return false;
}

int Agenda::BuscarAlumnoAp(string Apellidos){
	
	int cont=0;
	list<Alumno>::iterator it;

	for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
		if((*it).getApellidos()==Apellidos){
			
			cont++;
		}
	}
	
	if(cont>1){
		
		return 2;
		
	}else if(cont==1){
		
		return 1;
	}
	
	return 0;
}

bool Agenda::BuscarAlumnoEm(string Email){
	
	list<Alumno>::iterator it;
	
	for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
		if((*it).getEmail()==Email){
			
			return true;
		}
	}
	
	return false;
}

void Agenda::AnadirAlumno(){
	
	Alumno a;
	
	string DNI, Nombre, Apellidos, Email, Direccion, Lid;
	int Telefono, CursoAlto, Grupo;
	bool Lider, silider=false;
	float Nota;
	
	list<Alumno>::iterator it;

	cout<<"Introduzca el DNI del alumno: ";
	cin>>DNI;
	
	if(BuscarAlumno(DNI)==false){
		
		a.setDNI(DNI);
		cout<<"Introduzca el nombre del alumno: ";
		cin>>Nombre;
		a.setNombre(Nombre);
		cout<<"Introduzca los apellidos del alumno: ";
		cin.ignore();
		getline(cin, Apellidos, '\n');
		a.setApellidos(Apellidos);
		cout<<"Introduzca el email del alumno: ";
		cin>>Email;
		a.setEmail(Email);
		cout<<"Introduzca la dirección del alumno: ";
		cin.ignore();
		getline(cin, Direccion, '\n');
		a.setDireccion(Direccion);
		cout<<"Introduzca el teléfono del alumno: ";
		cin>>Telefono;
		a.setTelefono(Telefono);
		cout<<"Introduzca el curso más alto matriculado del alumno: ";
		cin>>CursoAlto;
		a.setCursoAlto(CursoAlto);
		cout<<"Introduzca el grupo del alumno: ";
		cin>>Grupo;
		a.setGrupo(Grupo);
		
		it=Alumnos_.begin();
		while(it!=Alumnos_.end() && silider==false){
		
			if((*it).getGrupo()==Grupo){
			
				if((*it).getLider()==true){
					
					silider=true;
				}
			}
		
			it++;
		}
		
		if(silider==false){
			
			cout<<"Introduzca si es líder de su grupo o no el alumno(S/N): ";
			cin>>Lid;
			if(Lid=="S" || Lid=="s"){

				Lider=true;

			}else if(Lid=="N" || Lid=="n"){

				Lider=false;
			}
			a.setLider(Lider);
			
		}else{
			
			a.setLider(false);
		}
		
		cout<<"Introduzca la nota del alumno: ";
		cin>>Nota;
		a.setNota(Nota);
		
		Alumnos_.push_back(a);
		
	}else{
		
		cout<<"ERROR: Ya existe un alumno con ese DNI."<<endl;
	}
}

void Agenda::ModificarAlumno(string DNI){

	string DNInuevo, Nombre, Apellidos, Email, Direccion, Lid;
	int Telefono, CursoAlto, Grupo;
	bool Lider, encontrado=false;
	float Nota;
	
	list<Alumno>::iterator it;
	
	it=Alumnos_.begin();
	while(it!=Alumnos_.end() && encontrado==false){
		
		if((*it).getDNI()==DNI){
			
			cout<<"Introduzca el nuevo DNI del alumno: ";
			cin>>DNInuevo;
			(*it).setDNI(DNInuevo);
			cout<<"Introduzca el nuevo nombre del alumno: ";
			cin>>Nombre;
			(*it).setNombre(Nombre);
			cout<<"Introduzca los nuevos apellidos del alumno: ";
			cin.ignore();
			getline(cin, Apellidos, '\n');
			(*it).setApellidos(Apellidos);
			cout<<"Introduzca el nuevo email del alumno: ";
			cin>>Email;
			(*it).setEmail(Email);
			cout<<"Introduzca la nueva dirección del alumno: ";
			cin.ignore();
			getline(cin, Direccion, '\n');
			(*it).setDireccion(Direccion);
			cout<<"Introduzca el nuevo teléfono del alumno: ";
			cin>>Telefono;
			(*it).setTelefono(Telefono);
			cout<<"Introduzca el nuevo curso más alto matriculado del alumno: ";
			cin>>CursoAlto;
			(*it).setCursoAlto(CursoAlto);
			cout<<"Introduzca el nuevo grupo del alumno: ";
			cin>>Grupo;
			(*it).setGrupo(Grupo);
			cout<<"Introduzca si es líder de su grupo o no el alumno(S/N): ";
			cin>>Lid;
			if(Lid=="S" || Lid=="s"){

				Lider=true;

			}else if(Lid=="N" || Lid=="n"){

				Lider=false;
			}
			(*it).setLider(Lider);
			cout<<"Introduzca la nota del alumno: ";
			cin>>Nota;
			(*it).setNota(Nota);
			
			encontrado=true;
		}
		
		it++;
	}
}

void Agenda::EliminarAlumno(string DNI){
	
	list<Alumno>::iterator it;

    for(it=Alumnos_.begin();it!=Alumnos_.end();it++){

         if((*it).getDNI()==DNI){
			 
              Alumnos_.erase(it);
			  cout<<"Alumno eliminado"<<endl;
         }
    }
}

void Agenda::EliminarTodos(){
	
	string resp;

	cout<<"¿Está seguro de que desea eliminar todos los alumnos? (S/N)"<<endl;
	cin>>resp;
	
	if(resp=="S" || resp=="s"){
		
		Alumnos_.clear();
		
	}else if(resp=="N" || resp=="n"){
		
	}else{
		
		cout<<"Opción incorrecta, debe introducir 'S' ó 'N'"<<endl;
	}
}

void Agenda::MostrarAlumno(string DNI){

	list<Alumno>::iterator it;
	string Lider;
	
	for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
		if((*it).getDNI()==DNI){
			
			if((*it).getLider()==true){
				
				Lider="Sí";
				
			}else{
				
				Lider="No";
			}
			
			cout<<"DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<
				" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<
					" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<endl;
		}
	} 
}

void Agenda::MostrarTodos(){

	list<Alumno>::iterator it;
	string Lider;
	int cont=1;
	
	for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
		if((*it).getLider()==true){
			
			Lider="Sí";
				
		}else{
				
			Lider="No";
		}
			
		cout<<cont<<".- DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<
			" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<
				" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<endl;
		
		cont++;
	}
}