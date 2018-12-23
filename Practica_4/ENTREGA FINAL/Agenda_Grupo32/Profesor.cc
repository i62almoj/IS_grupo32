#include "Profesor.h"

using namespace std;

//Estructura de alumnos para poder trabajar con ellos correctamente
typedef struct alumno{
	
	char DNI[20], Nombre[20], Apellidos[50], Email[20], Direccion[50], Nota[5];
	int Telefono, CursoAlto, Grupo;
	bool Lider;
	
}alu;

void Profesor::CargarCopia(Agenda *Ptr_Agenda_){
	
	ifstream fichero;
	char nombreFichero[20];
	alu al;
	Alumno a;
	Agenda agenda;
	
	//Se le pedirá al profesor que introduzca el nombre de la copia de seguridad que quiere cargar
	cout<<"Introduzca el nombre del fichero que quiere cargar: ";
	cin>>nombreFichero;
	strcat(nombreFichero, ".bin");
	
	//Se abre el fichero binario en modo lectura
	fichero.open(nombreFichero, ios::in | ios::binary);
	
	//Si el fichero se ha abierto correctamente
	if(fichero.is_open()){
		
		//Comprobamos que el fichero no esté vacío calculando el número de bytes
		fichero.seekg(0, ios::end);
		
		if(fichero.tellg()/sizeof(al)!=0){
			
			//Volvemos a colocarnos al principio del fichero
			fichero.seekg((0)*sizeof(al), ios::beg);
			
			//Limpiamos la lista de alumnos cada vez que carguemos para que no se dupliquen alumnos
			Ptr_Agenda_->Alumnos_.clear();
			
			//Recorremos el fichero y vamos leyendo cada dato de cada alumno
			while(!fichero.eof() && fichero.read((char *)&al, sizeof(al))){
				
				a.setDNI(al.DNI);
				a.setNombre(al.Nombre);
				a.setApellidos(al.Apellidos);
				a.setEmail(al.Email);
				a.setDireccion(al.Direccion);
				a.setNota(al.Nota);
				a.setTelefono(al.Telefono);
				a.setCursoAlto(al.CursoAlto);
				a.setGrupo(al.Grupo);
				a.setLider(al.Lider);
				
				//Guarda en la lista alumno por alumno
				Ptr_Agenda_->Alumnos_.push_back(a);
			}
		
			//Cerramos el fichero
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
	string nomb, nombreFichero;
	alu al;
	int contador=0;
	
	//Comprobamos que la lista no esté vacía, ya que eso sería que no hay nada que guardar
	if(!Ptr_Agenda_->Alumnos_.empty()){
	
		//Se le pedirá al profesor que introduzca el nombre de la copia de seguridad donde quiere guardar
		cout<<"Introduzca el nombre del fichero donde quiere guardar: ";
		cin>>nomb;
		
		nombreFichero=nomb+".bin";
	
		//Abrimos el fichero binario en modo escritura
		fichero.open(nombreFichero.c_str(), ios::out | ios::binary);
	
		//Si el fichero se ha abierto correctamente
		if(fichero.is_open()){
		
			//Vamos recorriendo la lista y compruebo que no se añadan más de 150 alumnos
			for(it=Ptr_Agenda_->Alumnos_.begin();it!=Ptr_Agenda_->Alumnos_.end() && contador<=150;it++){
				
				strcpy(al.DNI,(*it).getDNI().c_str());
				strcpy(al.Nombre,(*it).getNombre().c_str());
				strcpy(al.Apellidos,(*it).getApellidos().c_str());
				strcpy(al.Email,(*it).getEmail().c_str());
				strcpy(al.Direccion,(*it).getDireccion().c_str());
				strcpy(al.Nota,(*it).getNota().c_str());
				al.Telefono=((*it).getTelefono());
				al.CursoAlto=((*it).getCursoAlto());
				al.Grupo=((*it).getGrupo());
				al.Lider=((*it).getLider());
			
				//Se va escribiendo en el fichero cada uno de los alumnos existentes
				fichero.write((const char *)&al, sizeof(al));
				
				contador++;
			}
		
			//Cerramos el fichero
			fichero.close();
			
			//Máximo de alumnos
			if(contador==150){
			
				cout<<"NO ES POSIBLE AÑADIR MÁS ALUMNOS. Esta agenda ya contiene 150 alumnos."<<endl;
			}
		}
		
	}else{
		
		cout<<"No hay alumnos nuevos para guardar"<<endl;
	}
}

void Profesor::CargarBD(Agenda *Ptr_Agenda_){
	
	ifstream fichero;
	alu al;
	Alumno a;
	Agenda agenda;
	
	//Se abre el fichero binario en modo lectura
	fichero.open("BaseDatos.bin", ios::in | ios::binary);
	
	//Si el fichero se ha abierto correctamente
	if(fichero.is_open()){
		
		//Comprobamos que el fichero no esté vacío calculando el número de bytes
		fichero.seekg(0, ios::end);
		
		if(fichero.tellg()/sizeof(al)!=0){
			
			//Volvemos a colocarnos al principio del fichero
			fichero.seekg((0)*sizeof(al), ios::beg);
			
			//Limpiamos la lista de alumnos cada vez que carguemos para que no se dupliquen alumnos
			Ptr_Agenda_->Alumnos_.clear();
			
			//Recorremos el fichero y vamos leyendo cada dato de cada alumno
			while(!fichero.eof() && fichero.read((char *)&al, sizeof(al))){
				
				a.setDNI(al.DNI);
				a.setNombre(al.Nombre);
				a.setApellidos(al.Apellidos);
				a.setEmail(al.Email);
				a.setDireccion(al.Direccion);
				a.setNota(al.Nota);
				a.setTelefono(al.Telefono);
				a.setCursoAlto(al.CursoAlto);
				a.setGrupo(al.Grupo);
				a.setLider(al.Lider);
				
				//Guarda en la lista alumno por alumno
				Ptr_Agenda_->Alumnos_.push_back(a);
			}
		
			//Cerramos el fichero
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
	alu al;
	int contador=0;
	
	//Comprobamos que la lista no esté vacía, ya que eso sería que no hay nada que guardar
	if(!Ptr_Agenda_->Alumnos_.empty()){
	
		//Abrimos el fichero binario en modo escritura
		fichero.open("BaseDatos.bin", ios::out | ios::binary);
	
		//Si el fichero se ha abierto correctamente
		if(fichero.is_open()){
		
			//Vamos recorriendo la lista y compruebo que no se añadan más de 150 alumnos
			for(it=Ptr_Agenda_->Alumnos_.begin();it!=Ptr_Agenda_->Alumnos_.end() && contador<=150;it++){
				
				strcpy(al.DNI,(*it).getDNI().c_str());
				strcpy(al.Nombre,(*it).getNombre().c_str());
				strcpy(al.Apellidos,(*it).getApellidos().c_str());
				strcpy(al.Email,(*it).getEmail().c_str());
				strcpy(al.Direccion,(*it).getDireccion().c_str());
				strcpy(al.Nota,(*it).getNota().c_str());
				al.Telefono=((*it).getTelefono());
				al.CursoAlto=((*it).getCursoAlto());
				al.Grupo=((*it).getGrupo());
				al.Lider=((*it).getLider());
			
				//Se va escribiendo en el fichero cada uno de los alumnos existentes
				fichero.write((const char *)&al, sizeof(al));
			}
		
			//Cerramos el fichero
			fichero.close();
			
			//Máximo de alumnos
			if(contador==150){
			
				cout<<"NO ES POSIBLE AÑADIR MÁS ALUMNOS. Esta agenda ya contiene 150 alumnos."<<endl;
			}
		}
		
	}else{
		
		cout<<"No hay alumnos nuevos para guardar"<<endl;
	}
}
