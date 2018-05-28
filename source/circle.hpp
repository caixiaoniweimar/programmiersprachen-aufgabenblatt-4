#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Circle{
	public:

//Aufgabe 3.4
		Circle();
		Circle(string const& name,Vec2 const& cen, double rad, Color const& col);
		Circle(string const& name);

		ostream& print(ostream& os) const{  //Methode 
			os << "Name: " << name_ <<" Position: (" << center_.x << "," << center_.y << ") "
			<< "Radius: "<< radius_ << " Farbe: " << "(" << color_.r <<"," << color_.h <<
			"," << color_.g << ")";
            return os;
		}
		~Circle();

	public:
		string name_;
		Vec2 center_;
		double radius_;   
		Color color_;
		
};

ostream& operator<<(ostream& os, Circle const& c); // frei Funktion

//immer vergessen #endif Error!
#endif 
