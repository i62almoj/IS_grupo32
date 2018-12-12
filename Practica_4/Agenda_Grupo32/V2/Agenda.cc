#include "Agenda.h"

int main(){

	int opcion;
	char opc = 's';
	while (opc == 's'){
	
        system("cls");
		cout << "\n\n";
        cout << "\t\t  ====== AGENDA DE ALUMNOS ======";
        cout <<"\n\n                                          ";
     	cout << "\n \t\t\t 1. Añadir";
        cout << "\n \t\t\t 2. Modificar";
        cout << "\n \t\t\t 3. Eliminar";
        cout << "\n \t\t\t 4. Mostrar";
        cout << "\n \t\t\t 5. Cargar fichero";
        cout << "\n \t\t\t 6. Guardar fichero";
        cout << "\n \t\t\t 7. Cargar base de datos";
        cout << "\n \t\t\t 8. Guardar base de datos";
        cout << "\n \t\t\t 9. Salir";
        cout << "\n\n";
        cout << "\t\t\t Seleccione su opción: ";
        cin>>opcion;
        
        if(opcion>9 || opcion<1){
        
            cout<<"\n \t\t\t¡Opción incorrecta!"<<endl;
            cout<<"\n \t\t\tIntroduzca otra opción: ";
            cin>>opcion;
        }
        
        switch(opcion){
        
        	case 1: 
         		AnadirAlumno();
         		break;
         	case 2:
         		ModificarAlumno();
         		break;
            case 3: 
         		Eliminar();
         		break;
         	case 4: 
         	    Mostrar();
         	    break;
         	case 5: 
         	    CargarFichero();
         	    break;
         	case 6: 
         	    GuardarFichero();
         	    break;
         	case 7: 
         	    CargarBD();
         	    break;
         	case 8: 
         	    GuardarBD();
         	    break;
         	case 9: 
         		exit(-1);
				break;
       }
	}
}

int BuscarAlumno(string DNI){

	ifstream fichero;
	
	fichero.open("CopiaSeguridad.bin", ios::in | ios::binary);
	
	Alumno a;
	
	if(fichero.is_open()){
	
		fichero.read((char *)&a, sizeof(a));
		while(!fichero.eof()){
		
			if(a.DNI==DNI){
			
				return 1;
			}
		}
	}
	
	fichero.close();
	
	return 0;
}

int BuscarAlumnoA(string Apellidos){

	ifstream fichero;
	
	fichero.open("CopiaSeguridad.bin", ios::in | ios::binary);
	
	Alumno a;
	
	if(fichero.is_open()){
	
		fichero.read((char *)&a, sizeof(a));
		while(!fichero.eof()){
		
			if(a.Apellidos==Apellidos){
			
				return 1;
			}
		}
	}
	
	fichero.close();
	
	return 0;
}

void AnadirAlumno(){

	string DNI, Nombre, Apellidos, Email, Direccion, Lider;
	int Telefono, CursoAlto, Grupo;
	float Nota;

	ofstream fichero;
	
	fichero.open("CopiaSeguridad.bin", ios::out | ios::app | ios::binary);
	
	Alumno a;
	
	if(fichero.is_open()){
	
		cout<<"Introduzca el DNI: ";
		cin>>DNI;
		if(BuscarAlumno(DNI)==0){
		
			a.DNI=DNI;
			cout<<"Introduzca el nombre: ";
			cin>>a.Nombre;
			cout<<"Introduzca los apellidos: ";
			cin.ignore();
			getline(cin, a.Apellidos, '\n');
			cout<<"Introduzca el email: ";
			cin>>a.Email;
			cout<<"Introduzca la dirección: ";
			cin>>a.Direccion;
			cout<<"Introduzca el teléfono: ";
			cin>>a.Telefono;
			cout<<"Introduzca el curso más alto matriculado: ";
			cin>>a.CursoAlto;
			cout<<"Introduzca el grupo de trabajo al que pertenece: ";
			cin>>a.Grupo;
			cout<<"¿Es líder de su grupo(S/N)?: ";
			cin>>Lider;
			if(Lider=="S" || Lider=="s"){
			
				a.Lider=true;
				
			}else if(Lider=="N" || Lider=="n"){
			
				a.Lider=false;
			}
			cout<<"Introduzca la nota: ";
			cin>>a.Nota;
			
			fichero.write((const char *)&a, sizeof(a));
			
		}else if(BuscarAlumno(DNI)==1){
		
			cout<<"Ya existe un alumno con ese DNI"<<endl;
		}
	}
	
	fichero.close();
}

void ModificarAlumno(){

	
}

void Eliminar(){

	
}

void EliminarAlumno(){

	
}

void EliminarTodos(){

	
}

void Mostrar(){


}

void MostrarAlumno(){


}

void MostrarTodos(){


}

void MostrarGrupo(){


}
