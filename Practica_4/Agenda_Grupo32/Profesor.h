#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <cstdlib>
#include <list>
#include "Agenda.h"

using namespace std;

class Profesor{

	private:
		string ID_;
		int Rol_;
		//list <Agenda> Ptr_Agenda_;

	public:	

		//Profesor(string ID, int Rol, Agenda Ptr_Agenda);

//------OBSERVADORES----

		inline string getID() const
		{
			return ID_;
		}

		inline int getRol() const
		{
			return Rol_;
		}

		/*inline Agenda getPtr_Agenda() const
		{
			return Ptr_Agenda_;
		}*/

//--------MODIFICADORES------

		inline void setID(string ID)
		{
			ID_=ID;
		}		

		inline void setRol(int Rol)
		{
			Rol_=Rol;
		}

		/*inline void setPtr_Agenda(Agenda Ptr_Agenda)
		{
			Ptr_Agenda_.clear();
			list<Agenda>::iterator it;

			for(it=Ptr_Agenda_.begin();it!=Ptr_Agenda_.end();it++)
			{
				(*it)=getPtr_Agenda();
			}
				Ptr_Agenda_.push_back(*it);
		}*/

};

#endif