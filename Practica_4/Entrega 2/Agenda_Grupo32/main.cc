#include <iostream>
#include <cstdlib>
#include <list>
#include "Alumno.h"
#include "Profesor.h"
#include "Agenda.h"

using namespace std;

int main(){

	int opcion, resp, cont;
	char opc = 's';
	string DNI, Apellidos, Email;
	Agenda agenda;
	list<Alumno>::iterator it;
	
	while (opc == 's'){
	
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
        cout << "\t\t\t Seleccione la opción que desee: ";
        cin>>opcion;
        
        if(opcion>9 || opcion<1){
        
            cout<<"\n \t\t\t¡Opción incorrecta!"<<endl;
            cout<<"\n \t\t\tIntroduzca otra opción: ";
            cin>>opcion;
        }
        
        switch(opcion){
        
        	case 1: 
         		agenda.AnadirAlumno();
         		break;
         	case 2:
		    	if(agenda.Alumnos_.empty()){
         
				 	cout<<"No hay ningún alumno en la base de datos"<<endl;
					
		    	}else{
		    		
					cout<<"¿Desea buscar por DNI(0) o por Apellidos(1)?"<<endl;
					cin>>resp;
					if(resp==0){
					
						cout<<"Introduzca el DNI del alumno a modificar: ";
						cin>>DNI;
						if(agenda.BuscarAlumno(DNI)==false){
						
							cout<<"No existe ningún alumno con ese DNI"<<endl;
						
						}else if(agenda.BuscarAlumno(DNI)==true){
						
							agenda.ModificarAlumno(DNI);
						}
					
					}else if(resp==1){
					
						cout<<"Introduzca los apellidos del alumno a modificar: ";
						cin.ignore();
						getline(cin, Apellidos, '\n');
						if(agenda.BuscarAlumnoAp(Apellidos)==0){
						
							cout<<"No existe ningún alumno con esos apellidos"<<endl;
						
						}else if(agenda.BuscarAlumnoAp(Apellidos)==1){
						
							for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
		
								if((*it).getApellidos()==Apellidos){
			
									DNI=(*it).getDNI();
								}
							}
						
							agenda.ModificarAlumno(DNI);
						
						}else if(agenda.BuscarAlumnoAp(Apellidos)==2){
							
							cont=1;
							
							for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
		
								if((*it).getApellidos()==Apellidos){
			
									cout<<cont<<".- DNI: "<<(*it).getDNI()<<" - Apellidos: "<<(*it).getApellidos()<<endl;
									
									cont++;
								}
							}
						
							cout<<"Hay varios alumnos con esos apellidos, introduzca el DNI del alumno a modificar: "<<endl;
							cin>>DNI;
							if(agenda.BuscarAlumno(DNI)==false){
						
								cout<<"No existe ningún alumno con ese DNI"<<endl;
						
							}else if(agenda.BuscarAlumno(DNI)==true){
						
								agenda.ModificarAlumno(DNI);
							}
						}
					
					}else{
					
						cout<<"Opción incorrecta, debe ser 0 ó 1"<<endl;
					}
		    	}
         		break;
            case 3:
    			if(agenda.Alumnos_.empty()){

		 			cout<<"No hay ningún alumno en la base de datos"<<endl;
				
				}else{
					
					cout<<"¿Desea eliminar todos los alumnos(0) o solo un alumno(1)?"<<endl;
					cin>>resp;
					if(resp==0){
					
						agenda.EliminarTodos();
					
					}else if(resp==1){
					
				    	cout<<"¿Desea buscar por DNI(0) o por Apellidos(1)?"<<endl;
						cin>>resp;
						if(resp==0){
					
							cout<<"Introduzca el DNI del alumno a modificar: ";
							cin>>DNI;
							if(agenda.BuscarAlumno(DNI)==false){
						
								cout<<"No existe ningún alumno con ese DNI"<<endl;
						
							}else if(agenda.BuscarAlumno(DNI)==true){
						
								agenda.EliminarAlumno(DNI);
							}
					
						}else if(resp==1){
					
							cout<<"Introduzca los apellidos del alumno a modificar: ";
							cin.ignore();
							getline(cin, Apellidos, '\n');
							if(agenda.BuscarAlumnoAp(Apellidos)==0){
						
								cout<<"No existe ningún alumno con esos apellidos"<<endl;
						
							}else if(agenda.BuscarAlumnoAp(Apellidos)==1){
						
								for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
		
									if((*it).getApellidos()==Apellidos){
			
										DNI=(*it).getDNI();
									}
								}
						
								agenda.EliminarAlumno(DNI);
						
							}else if(agenda.BuscarAlumnoAp(Apellidos)==2){
						
								cout<<"Hay varios alumnos con esos apellidos, introduzca el DNI del alumno a modificar: "<<endl;
								cin>>DNI;
								if(agenda.BuscarAlumno(DNI)==false){
						
									cout<<"No existe ningún alumno con ese DNI"<<endl;
						
								}else if(agenda.BuscarAlumno(DNI)==true){
						
									agenda.EliminarAlumno(DNI);
								}
							}
					
						}else{
					
						cout<<"Opción incorrecta, debe ser 0 ó 1"<<endl;
						
					}
					
					}else{
					
						cout<<"Error, opción incorrecta, debe introducir 0 ó 1."<<endl;
					}
				}
	         	break;
         	case 4:
    			if(agenda.Alumnos_.empty()){

		 			cout<<"No hay ningún alumno en la base de datos"<<endl;
		
    			}else{
					
					cout<<"¿Desea mostrar todos los alumnos(0), solo un alumno(1), o los alumnos de un grupo(2)?"<<endl;
					cin>>resp;
					if(resp==0){
				
						agenda.MostrarTodos();
				
					}else if(resp==1){
						
						cout<<"¿Desea buscar por DNI(0), por Apellidos(1), o por Email(2)?"<<endl;
						cin>>resp;
						if(resp==0){
				
							cout<<"Introduzca el DNI del alumno a mostrar: ";
							cin>>DNI;
							if(agenda.BuscarAlumno(DNI)==false){
					
								cout<<"No existe ningún alumno con ese DNI"<<endl;
					
							}else if(agenda.BuscarAlumno(DNI)==true){
					
								agenda.MostrarAlumno(DNI);
							}
				
						}else if(resp==1){
				
							cout<<"Introduzca los apellidos del alumno a mostrar: ";
							cin.ignore();
							getline(cin, Apellidos, '\n');
							if(agenda.BuscarAlumnoAp(Apellidos)==0){
					
								cout<<"No existe ningún alumno con esos apellidos"<<endl;
					
							}else if(agenda.BuscarAlumnoAp(Apellidos)==1){
					
								for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
	
									if((*it).getApellidos()==Apellidos){
		
										DNI=(*it).getDNI();
									}
								}
					
								agenda.MostrarAlumno(DNI);
					
							}else if(agenda.BuscarAlumnoAp(Apellidos)==2){
					
								cout<<"Hay varios alumnos con esos apellidos, introduzca el DNI del alumno a mostrar: "<<endl;
								cin>>DNI;
								if(agenda.BuscarAlumno(DNI)==false){
					
									cout<<"No existe ningún alumno con ese DNI"<<endl;
					
								}else if(agenda.BuscarAlumno(DNI)==true){
					
									agenda.MostrarAlumno(DNI);
								}
							}
				
						}else if(resp==2){
				
							cout<<"Introduzca el email del alumno a mostrar: ";
							cin>>Email;
							if(agenda.BuscarAlumnoEm(Email)==false){
					
								cout<<"No existe ningún alumno con ese email"<<endl;
					
							}else if(agenda.BuscarAlumnoEm(Email)==true){
					
								for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
	
									if((*it).getEmail()==Email){
		
										DNI=(*it).getDNI();
									}
								}
					
								agenda.MostrarAlumno(DNI);
							}
				
						}else{
				
							cout<<"Opción incorrecta, debe ser 0, 1 ó 2"<<endl;
						}
				
					}else if(resp==2){
					
						agenda.MostrarGrupo();
					
					}else{
				
						cout<<"Error, opción incorrecta, debe introducir 0, 1 ó 2."<<endl;
					}
				}
         	    break;
         	/*case 5: 
         	    profesor.CargarFichero();
         	    break;
         	case 6: 
         	    profesor.GuardarFichero();
         	    break;
         	case 7: 
         	    profesor.CargarBD();
         	    break;
         	case 8: 
         	    profesor.GuardarBD();
         	    break;*/
         	case 9: 
         		exit(-1);
				break;
       }
	}
}