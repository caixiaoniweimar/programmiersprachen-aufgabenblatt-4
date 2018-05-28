#include "circle.hpp"
#include <iostream>
#include <vector>
#include <string>	
#include <algorithm>
using namespace std;
#define PI 3.1415926 // kein "="

//Aufgabe 3.4
Circle::Circle():
	name_{"deufault"},
	center_{0,0},
	radius_{1},
	color_{0.0,0.0,0.0} {}

Circle::Circle(string const& name,Vec2 const& cen, double rad, Color const& col): 
	name_{name} ,
	center_{cen},
	radius_{rad},
	color_{col} {}

Circle::Circle(string const& name):
	name_{name},
	center_{0,0},
	radius_{0},
	color_{0,0,0} {}


Circle::~Circle(){ }


ostream& operator<<(ostream& os, Circle const& c){   //frei Funktion  
	std::ostream::sentry const ostream_sentry(os);   // mit print() methode dann kann mit "couy<<c_1<<endl" print()调用
	return ostream_sentry? c.print(os) : os;
}
// Erstellen Programm Circle ausgeben im aufgabe_4.cpp









