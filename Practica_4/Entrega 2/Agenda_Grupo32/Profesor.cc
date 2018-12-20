#include "Profesor.h"

using namespace std;

void Profesor::CargarCopia(Agenda *Ptr_Agenda_){
	
	ifstream fichero;
	string nombreFichero;
	Alumno a;
	Agenda agenda;
	
	cout<<"Introduzca el nombre del fichero que quiere cargar: ";
	cin>>nombreFichero;
	
	fichero.open(nombreFichero+".bin", ios::in | ios::binary);
	
	if(fichero.is_open()){
		
		fichero.seekg(0, ios::end);
		
		if(fichero.tellg()/sizeof(Alumno)!=0){
			
			fichero.seekg((0)*sizeof(Alumno), ios::beg);
			
			while(!fichero.eof() && fichero.read((char *)&a, sizeof(Alumno))){
				
				Ptr_Agenda_->Alumnos_.push_back(a);
			}
		
			fichero.close();
			
		}else{
			
			cout<<"Fichero vacío"<<endl;
		}
	}
}

void Profesor::GuardarCopia(Agenda *Ptr_Agenda_){
	
	ofstream fichero;
	Alumno a;
	list<Alumno>::iterator it;
	string nombreFichero;
	
	if(!Ptr_Agenda_->Alumnos_.empty()){
		
		cout<<"Introduzca el nombre del fichero donde quiere guardar: ";
		cin>>nombreFichero;
	
		fichero.open(nombreFichero+".bin", ios::out | ios::binary);
	
		if(fichero.is_open()){
		
			for(it=Ptr_Agenda_->Alumnos_.begin();it!=Ptr_Agenda_->Alumnos_.end();it++){
		
				a.setDNI((*it).getDNI());
				a.setNombre((*it).getNombre());
				a.setApellidos((*it).getApellidos());
				a.setEmail((*it).getEmail());
				a.setDireccion((*it).getDireccion());
				a.setTelefono((*it).getTelefono());
				a.setCursoAlto((*it).getCursoAlto());
				a.setGrupo((*it).getGrupo());
				a.setLider((*it).getLider());
				a.setNota((*it).getNota());
			
				fichero.write((const char *)&a, sizeof(Alumno));
			}
		
			fichero.close();
		}
		
	}else{
		
		cout<<"No hay alumnos nuevos para guardar"<<endl;
	}
}

void Profesor::CargarBD(Agenda *Ptr_Agenda_){
	
	ifstream fichero;
	Alumno a;
	Agenda agenda;
	
	fichero.open("BaseDatos.bin", ios::in | ios::binary);
	
	if(fichero.is_open()){
		
		fichero.seekg(0, ios::end);
		
		if(fichero.tellg()/sizeof(Alumno)!=0){
			
			fichero.seekg((0)*sizeof(Alumno), ios::beg);
			
			while(!fichero.eof() && fichero.read((char *)&a, sizeof(Alumno))){
				
				Ptr_Agenda_->Alumnos_.push_back(a);
			}
		
			fichero.close();
			
		}else{
			
			cout<<"Fichero vacío"<<endl;
		}
	}
}

void Profesor::GuardarBD(Agenda *Ptr_Agenda_){
	
	ofstream fichero;
	Alumno a;
	list<Alumno>::iterator it;
	
	if(!Ptr_Agenda_->Alumnos_.empty()){
		
		fichero.open("BaseDatos.bin", ios::out | ios::binary);
	
		if(fichero.is_open()){
		
			for(it=Ptr_Agenda_->Alumnos_.begin();it!=Ptr_Agenda_->Alumnos_.end();it++){
		
				a.setDNI((*it).getDNI());
				a.setNombre((*it).getNombre());
				a.setApellidos((*it).getApellidos());
				a.setEmail((*it).getEmail());
				a.setDireccion((*it).getDireccion());
				a.setTelefono((*it).getTelefono());
				a.setCursoAlto((*it).getCursoAlto());
				a.setGrupo((*it).getGrupo());
				a.setLider((*it).getLider());
				a.setNota((*it).getNota());
			
				fichero.write((const char *)&a, sizeof(Alumno));
			}
		
			fichero.close();
		}
		
	}else{
		
		cout<<"No hay alumnos nuevos para guardar"<<endl;
	}
}