#include <iostream>
#include <cstdlib>
#include <list>
#include <string>
#include <cstring>
#include <stdio.h>
#include "Profesor.h"
#include "Agenda.h"

using namespace std;

//Funciones para el manejo de profesores
bool BuscarProfesor(char ID[10], Profesor *Ptr_Profesores_);
void AnadirProfesor(Profesor *Ptr_Profesores_);
void MostrarTodos(Profesor *Ptr_Profesores_);

//Estructura de profesor para poder trabajar con ellos correctamente
typedef struct profesor{
	
	char ID[10], Password[20];
	int Rol;
	
}profe;

//Menú de la gestión de profesores
int main(){

	int opcion;
	char ID[10], Password[20];
	Profesor p;
	
	//Se lanza el menú
	while(true){

		cout << "\n\n";
        cout << "\t\t  ====== GESTIÓN DE PROFESORES ======";
        cout <<"\n\n                                          ";
     	cout << "\n \t\t\t 1. Añadir un profesor";
		cout << "\n \t\t\t 2. Mostrar todos los profesores";
        cout << "\n \t\t\t 3. Salir";
        cout << "\n\n";
        cout << "\t\t\t Seleccione la opción que desee: ";
        cin>>opcion;

        if(opcion>3 || opcion<1){

            cout<<"\n \t\t\t¡Opción incorrecta!"<<endl;
            cout<<"\n \t\t\tIntroduzca otra opción: ";
            cin>>opcion;
        }

        switch(opcion){

			//Añadir un profesor
        	case 1: 
         		AnadirProfesor(&p);
         		break;
         		
         	//Mostrar todos los profesores existentes
	        case 2: 
	         	MostrarTodos(&p);
	         	break;
	         	
	        //Salir del programa
		    case 3: 
		        exit(-1);
		        break;
		}
	}
}

//Función para buscar un profesor a través de su ID
bool BuscarProfesor(char ID[10], Profesor *Ptr_Profesores_){
	
	list<Profesor>::iterator it;
	
	for(it=Ptr_Profesores_->Profesores_.begin();it!=Ptr_Profesores_->Profesores_.end();it++){
		
		if((*it).getID()==ID){
			
			return true;
		}
	}
	
	return false;
}

//Función para añadir un profesor
void AnadirProfesor(Profesor *Ptr_Profesores_){
	
	char ID[10], Password[20];
	int Rol;
	Profesor p;
	ofstream fichero;
	list<Profesor>::iterator it;
	profe pro;

	cout<<"Introduzca el ID del nuevo profesor: ";
	cin>>ID;
	
	//Comprobamos que no exista ya el profesor
	if(BuscarProfesor(ID, Ptr_Profesores_)==false){
		
		p.setID(ID);
		cout<<"Introduzca la contraseña del nuevo profesor: ";
		cin>>Password;
		p.setPassword(Password);
		cout<<"Introduzca el rol del nuevo profesor, Coordinador(1) ó Ayudante(0): ";
		cin>>Rol;
		p.setRol(Rol);
		
		//Se guarda el profesor en la lista
		Ptr_Profesores_->Profesores_.push_back(p);
		
	}else{
		
		cout<<"ERROR: Ya existe un profesor con ese ID."<<endl;
	}
	
	//Se escribirá el nuevo profesor en el fichero de profesores
	if(!Ptr_Profesores_->Profesores_.empty()){
		
		//Se abre el fichero binario para escritura
		fichero.open("Profesores.bin", ios::out | ios::binary);
	
		//Si el fichero se ha abierto correctamente
		if(fichero.is_open()){
		
			//Se va recorriendo la lista
			for(it=Ptr_Profesores_->Profesores_.begin();it!=Ptr_Profesores_->Profesores_.end();it++){
				
				strcpy(pro.ID,(*it).getID().c_str());
				strcpy(pro.Password,(*it).getPassword().c_str());
				pro.Rol=((*it).getRol());
				
				//Se va escribiendo cada profesor en el fichero
				fichero.write((const char *)&pro, sizeof(pro));
			}
		
			//Cerramos el fichero
			fichero.close();
		}
		
	}else{
		
		cout<<"No hay profesores nuevos para guardar"<<endl;
	}
}

//Función para mostrar todos los profesores existentes
void MostrarTodos(Profesor *Ptr_Profesores_){

	list<Profesor>::iterator it;
	int cont=1;
	ifstream fichero;
	Profesor p;
	profe pro;
	string nombreFichero;
	
	nombreFichero="Profesores.bin";
	
	//Se abre el fichero binario para lectura
	fichero.open(nombreFichero.c_str(), ios::in | ios::binary);
	
	//Si el fichero se ha abierto correctamente
	if(fichero.is_open()){
		
		//Comprobamos que el fichero no esté vacío calculando el número de bytes
		fichero.seekg(0, ios::end);
		
		if(fichero.tellg()/sizeof(pro)!=0){
			
			//Volvemos a colocarnos al inicio del fichero
			fichero.seekg((0)*sizeof(pro), ios::beg);
			
			//Limpiamos la lista para que no se dupliquen los profesores
			Ptr_Profesores_->Profesores_.clear();
			
			//Vamos recorriendo el fichero
			while(!fichero.eof() && fichero.read((char *)&pro, sizeof(pro))){
				
				p.setID(pro.ID);
				p.setPassword(pro.Password);
				p.setRol(pro.Rol);
				
				//Se guarda en la lista cada profesor leído
				Ptr_Profesores_->Profesores_.push_back(p);
			}
		
			//Cerramos el fichero
			fichero.close();
			
		}else{
			
			cout<<"Fichero vacío"<<endl;
		}
	}
	
	//Mostramos los profesores
	for(it=Ptr_Profesores_->Profesores_.begin();it!=Ptr_Profesores_->Profesores_.end();it++){
			
		cout<<cont<<".- ID: "<<(*it).getID()<<" - Contraseña: "<<(*it).getPassword()<<" - Rol: "<<(*it).getRol()<<endl;
		
		cont++;
	}
}
