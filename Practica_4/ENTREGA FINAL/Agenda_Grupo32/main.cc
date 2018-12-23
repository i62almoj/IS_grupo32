#include <iostream>
#include <cstdlib>
#include <list>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include "Alumno.h"
#include "Profesor.h"
#include "Agenda.h"

using namespace std;

//Estructura de profesor para poder trabajar con ellos correctamente
typedef struct profesor{
	
	char ID[10], Password[20];
	int Rol;
	
}profe;

//Menú principal del programa

int main(){

	int opcion, resp, cont, Grupo, orden1, orden2;
	char DNI[20], Apellidos[50], Email[25], ID[10], Password[20];
	Agenda agenda;
	list<Alumno>::iterator it;
	list<Profesor> Profesores_;
	list<Profesor>::iterator it2;
	Profesor p;
	ifstream fichero;
	profe pro;
	bool encontrado=false;
	string nombreFichero;
	
	nombreFichero="Profesores.bin";
	
	//Abre el fichero de los profesores en modo lectura y los carga en la lista para poder realizar el login
	fichero.open(nombreFichero.c_str(), ios::in | ios::binary);
	
	if(fichero.is_open()){
			
		Profesores_.clear();
			
		while(!fichero.eof() && fichero.read((char *)&pro, sizeof(pro))){
				
			p.setID(pro.ID);
			p.setPassword(pro.Password);
			p.setRol(pro.Rol);
				
			Profesores_.push_back(p);
		}
		
		fichero.close();
	}
	
	//Login del profesor
	cout<<"Introduzca su ID de profesor: ";
	cin>>ID;
	
	for(it2=Profesores_.begin();it2!=Profesores_.end();it2++){
		
		//Comprueba que exista un profesor con ese ID
		if((*it2).getID()==ID){
			
			cout<<"Introduzca su contraseña: ";
			cin>>Password;
			
			//Comprueba que haya introducido bien la contraseña
			if((*it2).getPassword()==Password){
				
				encontrado=true;
				
				//Se lanza el menú principal
				while(true){
	
					cout << "\n\n";
			        cout << "\t\t  ====== AGENDA DE ALUMNOS ======";
			        cout <<"\n\n                                          ";
			     	cout << "\n \t\t\t 1. Añadir";
			        cout << "\n \t\t\t 2. Modificar";
			        cout << "\n \t\t\t 3. Eliminar";
			        cout << "\n \t\t\t 4. Mostrar";
			        cout << "\n \t\t\t 5. Cargar copia de seguridad";
			        cout << "\n \t\t\t 6. Guardar copia de seguridad";
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
        
        			//Opciones del programa
			        switch(opcion){
        
        				//Añadir alumno
			        	case 1: 
			         		agenda.AnadirAlumno();
			         		break;
			         	
			         	//Modificar alumno
			         	case 2:
					    	if(agenda.Alumnos_.empty()){
         
							 	cout<<"No hay ningún alumno en la base de datos"<<endl;
					
					    	}else{
		    		
								cout<<"¿Desea buscar por DNI(0) o por Apellidos(1)?"<<endl;
								cin>>resp;
								//Si la búsqueda es por DNI
								if(resp==0){
					
									cout<<"Introduzca el DNI del alumno a modificar: ";
									cin>>DNI;
									//Comprobamos que exista el alumno
									if(agenda.BuscarAlumno(DNI)==false){
						
										cout<<"No existe ningún alumno con ese DNI"<<endl;
						
									}else if(agenda.BuscarAlumno(DNI)==true){
						
										agenda.ModificarAlumno(DNI);
									}
					
								//Si la búsqueda es por apellidos
								}else if(resp==1){
					
									cout<<"Introduzca los apellidos del alumno a modificar: ";
									cin.ignore();
									cin.getline(Apellidos, sizeof(Apellidos));
									//Si no existe ningún alumno con esos apellidos
									if(agenda.BuscarAlumnoAp(Apellidos)==0){
						
										cout<<"No existe ningún alumno con esos apellidos"<<endl;
						
									//Si hay un alumno con esos apellidos
									}else if(agenda.BuscarAlumnoAp(Apellidos)==1){
						
										for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
		
											if((*it).getApellidos()==Apellidos){
			
												strcpy(DNI,(*it).getDNI().c_str());
											}
										}
						
										agenda.ModificarAlumno(DNI);
						
									//Si hay varios alumnos con esos apellidos
									}else if(agenda.BuscarAlumnoAp(Apellidos)==2){
							
										cont=1;
							
										//Muestra los alumnos que hay con esos apellidos
										for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
		
											if((*it).getApellidos()==Apellidos){
			
												cout<<cont<<".- DNI: "<<(*it).getDNI()<<" - Apellidos: "<<(*it).getApellidos()<<endl;
									
												cont++;
											}
										}
						
										//Pide al profesor que elija uno de ellos por el DNI
										cout<<"Hay varios alumnos con esos apellidos, introduzca el DNI del alumno a modificar: "<<endl;
										cin>>DNI;
										
										//Comprueba que exista
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
			         		
			         	//Eliminar
			            case 3:
			    			if(agenda.Alumnos_.empty()){

					 			cout<<"No hay ningún alumno en la base de datos"<<endl;
				
							}else{
					
								cout<<"¿Desea eliminar todos los alumnos(0) o solo un alumno(1)?"<<endl;
								cin>>resp;
								
								//Si desea eliminar todos
								if(resp==0){
					
									agenda.EliminarTodos();
					
								//Si desea eliminar un solo alumno
								}else if(resp==1){
					
							    	cout<<"¿Desea buscar por DNI(0) o por Apellidos(1)?"<<endl;
									cin>>resp;
									
									//Si desea buscar por DNI
									if(resp==0){
					
										cout<<"Introduzca el DNI del alumno a eliminar: ";
										cin>>DNI;
										if(agenda.BuscarAlumno(DNI)==false){
						
											cout<<"No existe ningún alumno con ese DNI"<<endl;
						
										}else if(agenda.BuscarAlumno(DNI)==true){
						
											agenda.EliminarAlumno(DNI);
										}
					
									//Si desea buscar por apellidos
									}else if(resp==1){
					
										cout<<"Introduzca los apellidos del alumno a eliminar: ";
										cin.ignore();
										cin.getline(Apellidos, sizeof(Apellidos));
										
										//Si no hay ningún alumno con esos apellidos
										if(agenda.BuscarAlumnoAp(Apellidos)==0){
						
											cout<<"No existe ningún alumno con esos apellidos"<<endl;
						
										//Si solo hay un alumno con esos apellidos
										}else if(agenda.BuscarAlumnoAp(Apellidos)==1){
						
											for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
		
												if((*it).getApellidos()==Apellidos){
			
													strcpy(DNI,(*it).getDNI().c_str());
												}
											}
						
											agenda.EliminarAlumno(DNI);
						
										//Si hay varios alumnos con esos apellidos
										}else if(agenda.BuscarAlumnoAp(Apellidos)==2){
										
											//Muestra los alumnos que hay con esos apellidos
											for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
		
												if((*it).getApellidos()==Apellidos){
			
													cout<<cont<<".- DNI: "<<(*it).getDNI()<<" - Apellidos: "<<(*it).getApellidos()<<endl;
									
													cont++;
												}
											}
											
											//Pide al profesor que elija uno por el DNI
											cout<<"Hay varios alumnos con esos apellidos, introduzca el DNI del alumno a eliminar: "<<endl;
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
				         	
				        //Mostrar
			         	case 4:
			    			if(agenda.Alumnos_.empty()){

					 			cout<<"No hay ningún alumno en la base de datos"<<endl;
		
			    			}else{
					
								cout<<"¿Desea mostrar todos los alumnos(0), solo un alumno(1), o los alumnos de un grupo(2)?"<<endl;
								cin>>resp;
								
								//Si desea mostrar todos los alumnos
								if(resp==0){
								
									//Para el tipo de ordenación
									cout<<"¿Cómo desea ordenar los alumnos?\nPor nombre(0)\nPor apellido(1)\nPor DNI(2)\nPor curso más alto(3)\nPor grupo(4)\n"<<endl;
									cin>>orden1;
									
									//Para ordenar ascendente o descendente
									cout<<"¿Y desea ordenarlos de forma ascendente(0) o descendente(1)?"<<endl;
									cin>>orden2;
				
									agenda.MostrarTodos(orden1, orden2);
				
								//Si desea mostrar solo un alumno
								}else if(resp==1){
						
									cout<<"¿Desea buscar por DNI(0), por Apellidos(1), o por Email(2)?"<<endl;
									cin>>resp;
									
									//Si desea buscar por DNI
									if(resp==0){
				
										cout<<"Introduzca el DNI del alumno a mostrar: ";
										cin>>DNI;
										if(agenda.BuscarAlumno(DNI)==false){
					
											cout<<"No existe ningún alumno con ese DNI"<<endl;
					
										}else if(agenda.BuscarAlumno(DNI)==true){
					
											agenda.MostrarAlumno(DNI);
										}
				
									//Si desea buscar por apellidos
									}else if(resp==1){
				
										cout<<"Introduzca los apellidos del alumno a mostrar: ";
										cin.ignore();
										cin.getline(Apellidos, sizeof(Apellidos));
										
										//Si no hay ningún alumno con esos apellidos
										if(agenda.BuscarAlumnoAp(Apellidos)==0){
					
											cout<<"No existe ningún alumno con esos apellidos"<<endl;
					
										//Si solo hay uno o más de un alumno con esos apellidos, los muestra
										}else{
					
											for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
	
												if((*it).getApellidos()==Apellidos){
		
													strcpy(DNI,(*it).getDNI().c_str());
												}
											}
					
											agenda.MostrarAlumno(DNI);
					
										}
				
									//Si desea buscar por email
									}else if(resp==2){
				
										cout<<"Introduzca el email del alumno a mostrar: ";
										cin>>Email;
										if(agenda.BuscarAlumnoEm(Email)==false){
					
											cout<<"No existe ningún alumno con ese email"<<endl;
					
										}else if(agenda.BuscarAlumnoEm(Email)==true){
					
											for(it=agenda.Alumnos_.begin();it!=agenda.Alumnos_.end();it++){
	
												if((*it).getEmail()==Email){
		
													strcpy(DNI,(*it).getDNI().c_str());
												}
											}
					
											agenda.MostrarAlumno(DNI);
										}
				
									}else{
				
										cout<<"Opción incorrecta, debe ser 0, 1 ó 2"<<endl;
									}
				
								//Si desea mostrar los alumnos de un grupo
								}else if(resp==2){
								
									cout<<"Introduzca el número de grupo: ";
									cin>>Grupo;
					
									agenda.MostrarGrupo(Grupo);
					
								}else{
				
									cout<<"Error, opción incorrecta, debe introducir 0, 1 ó 2."<<endl;
								}
							}
			         	    break;
			         	    
			         	//Cargar copia de seguridad
			         	case 5:
			         		//Comprobamos que sea coordinador
							if((*it2).getRol()==1){
				
								p.CargarCopia(&agenda);
					
							}else{
					
								cout<<"Debe ser coordinador para acceder a esta función";
							}
			         	    break;
			         	    
			         	//Guardar copia de seguridad
			         	case 6:
			         		//Comprobamos que sea coordinador
							if((*it2).getRol()==1){
			
								p.GuardarCopia(&agenda);
				
							}else{
				
								cout<<"Debe ser coordinador para acceder a esta función";
							}
			         	    break;
			         	    
			         	//Cargar base de datos
			         	case 7: 
			         	    p.CargarBD(&agenda);
			         	    break;
			         	    
			         	//Guardar base de datos
			         	case 8: 
			         	    p.GuardarBD(&agenda);
			         	    break;
			         	    
			         	//Salir del programa
			         	case 9: 
			         		exit(-1);
							break;
			       }
				}
				
			}else{
				
				cout<<"Contraseña incorrecta"<<endl;
				exit(-1);
			}
		}
	}
	
	//En el caso de que el ID introducido no coincida con ningún profesor registrado
	if(encontrado==false){
		
		cout<<"No existe ningún profesor con ese ID"<<endl;
	}
	
	return 0;
}
