#include "Agenda.h"

using namespace std;

//Búsqueda de un alumno por su DNI
bool Agenda::BuscarAlumno(string DNI){
	
	list<Alumno>::iterator it;
	
	//Comprobamos si hay algún DNI igual en la lista
	for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
		if((*it).getDNI()==DNI){
			
			return true;
		}
	}
	
	return false;
}

//Búsqueda de un alumno por sus apellidos
int Agenda::BuscarAlumnoAp(string Apellidos){
	
	int cont=0;
	list<Alumno>::iterator it;

	//Va comprobando cuántos alumnos hay con esos apellidos
	for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
		if((*it).getApellidos()==Apellidos){
			
			cont++;
		}
	}
	
	//Si existe más de un alumno con esos apellidos, devuelve un 2
	if(cont>1){
		
		return 2;
		
	//Si existe un solo alumno con esos apellidos, devuelve un 1
	}else if(cont==1){
		
		return 1;
	}
	
	//Si no existe ningún alumno con esos apellidos, devuelve un 0
	return 0;
}

//Búsqueda de un alumno por su email
bool Agenda::BuscarAlumnoEm(string Email){
	
	list<Alumno>::iterator it;
	
	//Comprobamos si hay algún email igual en la lista
	for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
		if((*it).getEmail()==Email){
			
			return true;
		}
	}
	
	return false;
}

//Función para añadir un alumno
void Agenda::AnadirAlumno(){
	
	Alumno a;
	
	string DNI, Nombre, Apellidos, Email, Direccion, Lid, resp, Nota;
	int Telefono, CursoAlto, Grupo;
	bool Lider, silider=false;
	
	list<Alumno>::iterator it;
	
	//Compruebo que no haya ya más de 150 alumnos en la lista
	if(Alumnos_.size()<=150){
	
		cout<<"Introduzca el DNI del alumno: ";
		cin>>DNI;
		
		//Comprobamos que no exista ya el alumno
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
			
			//Comprobamos si ya existe un líder en ese grupo
			it=Alumnos_.begin();
			while(it!=Alumnos_.end() && silider==false){
			
				if((*it).getGrupo()==Grupo){
				
					if((*it).getLider()==true){
						
						silider=true;
					}
				}
			
				it++;
			}
			
			//Si no había ningún líder, pregunta si quieres poner a este alumno como tal
			if(silider==false){
				
				cout<<"Introduzca si es líder de su grupo o no el alumno(S/N): ";
				cin>>Lid;
				if(Lid=="S" || Lid=="s"){

					Lider=true;

				}else if(Lid=="N" || Lid=="n"){

					Lider=false;
				}
				a.setLider(Lider);
				
			//Si ya existía un líder
			}else{
			
				cout<<"\nAVISO: Como ya existe un líder en ese grupo, se añadirá automáticamente a este alumno sin ser líder. Si quiere modificarlo, vaya a la opción de modificar en el menú."<<endl;
				
				a.setLider(false);
			}
			
			//Pregunta si quiere introducir la nota, ya que ésta no es obligatoria
			cout<<"¿Quiere introducir la nota del alumno? (S/N)"<<endl;
			cin>>resp;
			if(resp=="S" || resp=="s"){
			
				cout<<"Introduzca la nota del alumno: ";
				cin>>Nota;
				a.setNota(Nota);
				
			//Si no quiere introducir la nota, se quedará en blanco
			}else if(resp=="N" || resp=="n"){

				a.setNota("");
			}
			
			//Actualizamos el alumno modificado en la lista
			Alumnos_.push_back(a);
			
		}else{
			
			cout<<"ERROR: Ya existe un alumno con ese DNI."<<endl;
		}
		
	//Máximo de alumnos
	}else{
	
		cout<<"NO ES POSIBLE AÑADIR MÁS ALUMNOS. Esta agenda ya contiene 150 alumnos."<<endl;
	}
}

//Función para modificar los datos de un alumno
void Agenda::ModificarAlumno(string DNI){

	string DNInuevo, Nombre, Apellidos, Email, Direccion, Lid, resp, DNIlider, Nota;
	int Telefono, CursoAlto, Grupo;
	bool Lider, encontrado=false, silider=false, silider2=false;
	
	list<Alumno>::iterator it;
	list<Alumno>::iterator it2;
	list<Alumno>::iterator it3;
	
	//Vamos recorriendo la lista hasta que se acabe o hasta que se encuentre el alumno deseado
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
			
			//Comprueba si ya hay un líder en ese grupo y si es él mismo u otro
			it2=Alumnos_.begin();
			while(it2!=Alumnos_.end() && silider==false){
		
				if((*it2).getGrupo()==Grupo){
			
					if((*it2).getLider()==true && (*it2).getDNI()!=(*it).getDNI()){
					
						silider=true;
						
					}else if((*it2).getLider()==true && (*it2).getDNI()==(*it).getDNI()){
					
						silider2=true;
					}
				}
		
				it2++;
			}
		
			//Si no había ningún líder en ese grupo
			if(silider==false && silider2==false){
			
				cout<<"Introduzca si es líder de su grupo o no el alumno(S/N): ";
				cin>>Lid;
				
				if(Lid=="S" || Lid=="s"){

					(*it).setLider(true);

				}else if(Lid=="N" || Lid=="n"){

					(*it).setLider(false);
				}
			
			//Si ya había un líder en ese grupo pero no es el alumno que estamos modificando
			}else if(silider==true && silider2==false){
			
				cout<<"Ya existe un líder en ese grupo, ¿desea poner a este alumno como líder y quitar al otro? (S/N)"<<endl;
				cin>>resp;
				
				if(resp=="S" || resp=="s"){
				
					it2--;
					(*it2).setLider(false);

					(*it).setLider(true);

				}else if(resp=="N" || resp=="n"){

					(*it).setLider(false);
				}
				
			//Si ya estaba este alumno como líder del grupo
			}else if(silider==false && silider2==true){
			
				cout<<"Introduzca si sigue siendo líder de su grupo o no el alumno(S/N): ";
				cin>>Lid;
				
				if(Lid=="S" || Lid=="s"){

				}else if(Lid=="N" || Lid=="n"){
					
					//Si quiere poner a otro alumno como el líder, mostrará los componentes del grupo y pedirá que se alija uno nuevo
					MostrarGrupo(Grupo);
					
					cout<<"Escriba el DNI del que será el nuevo líder:"<<endl;
					cin>>DNIlider;
					
					it3=Alumnos_.begin();
					while(it3!=Alumnos_.end()){
		
						if((*it3).getDNI()==DNIlider){
			
							(*it3).setLider(true);
						}
		
						it3++;
					}
					
					(*it).setLider(false);
				}
			}
			
			//Pregunta si quiere introducir la nota, ya que ésta no es obligatoria
			cout<<"¿Quiere introducir la nota del alumno? (S/N)"<<endl;
			cin>>resp;
			if(resp=="S" || resp=="s"){
		
				cout<<"Introduzca la nueva nota del alumno: ";
				cin>>Nota;
				(*it).setNota(Nota);
			
			//Si no quiere introducir la nota, se quedará en blanco
			}else if(resp=="N" || resp=="n"){

				(*it).setNota("");
			}
			
			encontrado=true;
		}
		
		it++;
	}
}

//Función para eliminar un alumno
void Agenda::EliminarAlumno(string DNI){
	
	list<Alumno>::iterator it;
	list<Alumno>::iterator it2;
	bool encontrado=false;
	int Grupo;
	string DNIlider;
	
	//Vamos recorriendo la lista hasta que se acabe o hasta que se encuentre el alumno deseado
	it=Alumnos_.begin();
	while(it!=Alumnos_.end() && encontrado==false){
	
		if((*it).getDNI()==DNI){
		
			//Si el alumno a eliminar es el líder de su grupo
			if((*it).getLider()==true){
			
				//Guardamos el número de grupo antes de eliminar al alumno para poder mostrar después los integrantes restantes
				Grupo=(*it).getGrupo();
				
				Alumnos_.erase(it);
				cout<<"Alumno eliminado"<<endl;
			
				//Si hay alumnos todavía de ese grupo, pide elegir un nuevo líder
				if(MostrarGrupo(Grupo)!=1){
				
					cout<<"Escriba el DNI del que será el nuevo líder:"<<endl;
					cin>>DNIlider;
					
					it2=Alumnos_.begin();
					while(it2!=Alumnos_.end()){
		
						if((*it2).getGrupo()==Grupo && (*it2).getDNI()==DNIlider){
			
							(*it2).setLider(true);
						}
		
						it2++;
					}
				}
				
				encontrado=true;
				
			//Si el alumno a eliminar no era líder de su grupo, se borra directamente
			}else{
			
				Alumnos_.erase(it);
				cout<<"Alumno eliminado"<<endl;
			  
				encontrado=true;
			}
        }
	
		it++;
	}
}

//Función para eliminar todos los alumnos
void Agenda::EliminarTodos(){
	
	string resp;

	//Pedirá una confirmación antes de eliminar por si el profesor se ha equivocado
	cout<<"¿Está seguro de que desea eliminar todos los alumnos? (S/N)"<<endl;
	cin>>resp;
	
	if(resp=="S" || resp=="s"){
		
		Alumnos_.clear();
		cout<<"Alumnos eliminados"<<endl;
		
	}else if(resp=="N" || resp=="n"){
		
	}else{
		
		cout<<"Opción incorrecta, debe introducir 'S' ó 'N'"<<endl;
	}
}

//Función para mostrar un alumno
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

//Función para mostrar todos los alumnos
void Agenda::MostrarTodos(int tipo1, int tipo2){

	list<Alumno>::iterator it;
	string Lider, resp;
	int cont=1, curso1, curso2, grupo1, grupo2, j=0;
	ofstream fichero;
	vector<string> nombres_, apellidos_, dni_;
	vector<int> cursos_, cursosaux_, grupos_, gruposaux_, nombresaux_, apellidosaux_, dniaux_;
	string nombre1, nombre2, apellido1, apellido2, dni1, dni2;
	bool encontrado=false;
	//char nombreFichero[20]="firefox Lista.html";
	
	//Ordenar por nombre
	if(tipo1==0){
	
		//Vector con los nombres de los alumnos
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			nombres_.push_back((*it).getNombre());
		}
		
		//Ordenamos el vector
		sort(nombres_.begin(), nombres_.end());
		
		//Descendente
		if(tipo2==1)
			reverse(nombres_.begin(), nombres_.end());
		
		//Con este vector comprobaremos si ya se ha mostrado por pantalla el alumno o no, 0->no 1->sí
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			nombresaux_.push_back(0);
		}
		nombresaux_.push_back(0);
		
		for(int i=0;i<nombres_.size();i++){
		
			encontrado=false;
			j=0;
		
			for(it=Alumnos_.begin();it!=Alumnos_.end() && encontrado==false;it++){
			
				j++;
			
				nombre1=(*it).getNombre();
      			nombre2=nombres_[i];
      			
      			//Se irán comparando los nombres del vector con los de nuestra lista de alumnos y se irán mostrando en orden, además de comprobar que ese alumno no haya sido mostrado anteriormente
      			if(!(nombre1.compare(nombre2)) && nombresaux_[j]==0) {
      			
      				encontrado=true;
      				
      				//Como ya lo mostramos le ponemos un 1 para que no se vuelva a mostrar
      				nombresaux_[j]=1;
				
					//Si el alumno a mostrar es líder saldrá de forma especial
					if((*it).getLider()==true){
			
						Lider="SI";
			
						cout<<cont<<".- ~~~~~ DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<" ~~~~~"<<endl;
				
					}else{
				
						Lider="No";
			
						cout<<cont<<".- DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<endl;
						
					}
		
					cont++;
				}
			}
		}
		
	//Ordenar por apellidos
	}else if(tipo1==1){
	
		//Vector con los apellidos de los alumnos
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			apellidos_.push_back((*it).getApellidos());
		}
		
		//Ordenamos el vector
		sort(apellidos_.begin(), apellidos_.end());
		
		//Descendente
		if(tipo2==1)
			reverse(apellidos_.begin(), apellidos_.end());
		
		//Con este vector comprobaremos si ya se ha mostrado por pantalla el alumno o no, 0->no 1->sí
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			apellidosaux_.push_back(0);
		}
		apellidosaux_.push_back(0);
		
		for(int i=0;i<apellidos_.size();i++){
		
			encontrado=false;
			j=0;
		
			for(it=Alumnos_.begin();it!=Alumnos_.end() && encontrado==false;it++){
			
				j++;
			
				apellido1=(*it).getApellidos();
      			apellido2=apellidos_[i];
      			
      			//Se irán comparando los apellidos del vector con los de nuestra lista de alumnos y se irán mostrando en orden, además de comprobar que ese alumno no haya sido mostrado anteriormente
      			if(!(apellido1.compare(apellido2)) && apellidosaux_[j]==0) {
      			
      				encontrado=true;
      				
      				//Como ya lo mostramos le ponemos un 1 para que no se vuelva a mostrar
      				apellidosaux_[j]=1;
				
					//Si el alumno a mostrar es líder saldrá de forma especial
					if((*it).getLider()==true){
			
						Lider="SI";
			
						cout<<cont<<".- ~~~~~ DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<" ~~~~~"<<endl;
				
					}else{
				
						Lider="No";
			
						cout<<cont<<".- DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<endl;
						
					}
		
					cont++;
				}
			}
		}
		
	//Ordenar por DNI
	}else if(tipo1==2){
	
		//Vector con los DNIs de los alumnos
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			dni_.push_back((*it).getDNI());
		}
		
		//Ordenamos el vector
		sort(dni_.begin(), dni_.end());
		
		//Descendente
		if(tipo2==1)
			reverse(dni_.begin(), dni_.end());
		
		//Con este vector comprobaremos si ya se ha mostrado por pantalla el alumno o no, 0->no 1->sí
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			dniaux_.push_back(0);
		}
		dniaux_.push_back(0);
		
		for(int i=0;i<dni_.size();i++){
		
			encontrado=false;
			j=0;
		
			for(it=Alumnos_.begin();it!=Alumnos_.end() && encontrado==false;it++){
			
				j++;
			
				dni1=(*it).getDNI();
      			dni2=dni_[i];
      			
      			//Se irán comparando los DNIs del vector con los de nuestra lista de alumnos y se irán mostrando en orden, además de comprobar que ese alumno no haya sido mostrado anteriormente
      			if(!(dni1.compare(dni2)) && dniaux_[j]==0) {
      			
      				encontrado=true;
      				
      				//Como ya lo mostramos le ponemos un 1 para que no se vuelva a mostrar
      				dniaux_[j]=1;
				
					//Si el alumno a mostrar es líder saldrá de forma especial
					if((*it).getLider()==true){
			
						Lider="SI";
			
						cout<<cont<<".- ~~~~~ DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<" ~~~~~"<<endl;
				
					}else{
				
						Lider="No";
			
						cout<<cont<<".- DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<endl;
						
					}
		
					cont++;
				}
			}
		}
		
	//Ordenar por curso más alto
	}else if(tipo1==3){
	
		//Vector con los cursos de los alumnos
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			cursos_.push_back((*it).getCursoAlto());
		}
		
		//Ordenamos el vector
		sort(cursos_.begin(), cursos_.end());
		
		//Descendente
		if(tipo2==1)
			reverse(cursos_.begin(), cursos_.end());
		
		//Con este vector comprobaremos si ya se ha mostrado por pantalla el alumno o no, 0->no 1->sí
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			cursosaux_.push_back(0);
		}
		cursosaux_.push_back(0);
		
		for(int i=0;i<cursos_.size();i++){
		
			encontrado=false;
			j=0;
		
			for(it=Alumnos_.begin();it!=Alumnos_.end() && encontrado==false;it++){
			
				j++;
			
				curso1=(*it).getCursoAlto();
      			curso2=cursos_[i];
      			
      			//Se irán comparando los cursos del vector con los de nuestra lista de alumnos y se irán mostrando en orden, además de comprobar que ese alumno no haya sido mostrado anteriormente
      			if(curso1==curso2 && cursosaux_[j]==0) {
      			
      				encontrado=true;
      				
      				//Como ya lo mostramos le ponemos un 1 para que no se vuelva a mostrar
      				cursosaux_[j]=1;
				
					//Si el alumno a mostrar es líder saldrá de forma especial
					if((*it).getLider()==true){
			
						Lider="SI";
			
						cout<<cont<<".- ~~~~~ DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<" ~~~~~"<<endl;
				
					}else{
				
						Lider="No";
			
						cout<<cont<<".- DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<endl;
						
					}
		
					cont++;
				}
			}
		}
	
	//Ordenar por número de grupo
	}else if(tipo1==4){
	
		//Vector con los grupos de los alumnos
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			grupos_.push_back((*it).getGrupo());
		}
		
		//Ordenamos el vector
		sort(grupos_.begin(), grupos_.end());
		
		//Descendente
		if(tipo2==1)
			reverse(grupos_.begin(), grupos_.end());
		
		//Con este vector comprobaremos si ya se ha mostrado por pantalla el alumno o no, 0->no 1->sí
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			gruposaux_.push_back(0);
		}
		gruposaux_.push_back(0);
		
		for(int i=0;i<grupos_.size();i++){
		
			encontrado=false;
			j=0;
		
			for(it=Alumnos_.begin();it!=Alumnos_.end() && encontrado==false;it++){
			
				j++;
			
				grupo1=(*it).getGrupo();
      			grupo2=grupos_[i];
      			
      			//Se irán comparando los grupos del vector con los de nuestra lista de alumnos y se irán mostrando en orden, además de comprobar que ese alumno no haya sido mostrado anteriormente
      			if(grupo1==grupo2 && gruposaux_[j]==0) {
      			
      				encontrado=true;
      				
      				//Como ya lo mostramos le ponemos un 1 para que no se vuelva a mostrar
      				gruposaux_[j]=1;
				
					//Si el alumno a mostrar es líder saldrá de forma especial
					if((*it).getLider()==true){
			
						Lider="SI";
			
						cout<<cont<<".- ~~~~~ DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<" ~~~~~"<<endl;
				
					}else{
				
						Lider="No";
			
						cout<<cont<<".- DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<endl;
						
					}
		
					cont++;
				}
			}
		}
	}
	
	//Para generar un fichero HTML con los alumnos
	cout<<"¿Desea generar una página web con los alumnos? (S/N)"<<endl;
	cin>>resp;
	
	if(resp=="S" || resp=="s"){
	
		//Abrimos el fichero del HTML
		fichero.open ("Lista.html");
		//Comienzo del HTML
    	fichero << "<!DOCTYPE html><html><head></head><body>";
	
		cont=1;
	
		for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
			//Si el alumno a mostrar es líder saldrá de forma especial
			if((*it).getLider()==true){
			
				Lider="SI";
				
				fichero << "<lu><li><span style='font-weight:bold;color:green'>" <<cont<<".- DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Direccion: "<<(*it).getDireccion()<<" - Telefono: "<<(*it).getTelefono()<<" - Curso mas alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - Lider: "<<Lider<<" - Nota: "<<(*it).getNota() << "</span></li></lu>"<<endl;
				
			}else{
				
				Lider="No";
				
				fichero << "<lu><li><span style='font-weight: bold'>" <<cont<<".- DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<" - Direccion: "<<(*it).getDireccion()<<" - Telefono: "<<(*it).getTelefono()<<" - Curso mas alto: "<<(*it).getCursoAlto()<<" - Grupo: "<<(*it).getGrupo()<<" - Lider: "<<Lider<<" - Nota: "<<(*it).getNota() << "</span></li></lu>"<<endl;
				
			}
		
			cont++;
		}
		
		//Final del HTML
		fichero << "</body></html>";
		//Cerramos el fichero
		fichero.close();
		
		cout<<"SE HA GENERADO UN HTML EN LA CARPETA. Puede acceder a él cuando desee."<<endl;
		
		//system(nombreFichero);
	
	}else if(resp=="N" || resp=="n"){
	
	}
}

//Función para mostrar los alumnos de un grupo, devolverá el número de alumnos que hay en ese grupo
int Agenda::MostrarGrupo(int Grupo){
	
	list<Alumno>::iterator it;
	string Lider;
	int cont=1;
	
	for(it=Alumnos_.begin();it!=Alumnos_.end();it++){
		
		if((*it).getGrupo()==Grupo){
			
			if((*it).getLider()==true){
			
				Lider="Sí";
				
			}else{
				
				Lider="No";
			}
			
			cout<<cont<<".- DNI: "<<(*it).getDNI()<<" - Nombre: "<<(*it).getNombre()<<" - Apellidos: "<<(*it).getApellidos()<<" - Email: "<<(*it).getEmail()<<
				" - Dirección: "<<(*it).getDireccion()<<" - Teléfono: "<<(*it).getTelefono()<<" - Curso más alto: "<<(*it).getCursoAlto()<<
					" - ¿Líder?: "<<Lider<<" - Nota: "<<(*it).getNota()<<endl;
			
			cont++;
		}
	}
	
	return cont;
}
