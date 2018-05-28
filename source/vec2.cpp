#include "vec2.hpp"
#include <iostream>

//Aufgabe 2.2
Vec2::Vec2():	 //StandardKonstruktor!!! Vec2::Vec2(): x{0},y{0} {}
	x{0.0f},
	y{0.0f} {}

Vec2::Vec2(float x1, float y1):  //NormalKonstruktor
	x{x1},
	y{y1}  {}

//Aufgabe 2.3
Vec2& Vec2::operator+= (Vec2 const& v){ //Vec2& Vec2::
    x += v.x;                           //return *this
    y += v.y;
    return *this;
}
Vec2& Vec2::operator-= (Vec2 const& v){
	x -= v.x;
	y -= v.y;       
	return *this;
}
Vec2& Vec2::operator*= (float s){
	x *= s;
	y *= s;
	return *this;     
}
Vec2& Vec2::operator/= (float s){
	if(s==0){
		x=0.0f;
		y=0.0f;
		std::cout<<"Fehler! Vector kann nicht durch/= 0."<<std::endl;
	}
	else{
		x/=s;
		y/=s;
	}              //Methode
	return *this;
}

//Aufgabe 2.4
Vec2 operator+(Vec2 const& u, Vec2 const& v){
	Vec2 result(u);   // first erzeuge neue Objekt und copy u!!;
	result+=v;
	return result;    // Funktion
}
Vec2 operator-(Vec2 const& u, Vec2 const& v){
	Vec2 result(u);
	result-=v;
	return result;
}
Vec2 operator*(Vec2 const& v, float s){
	Vec2 result(v);
	result*=s;
	return result;
}
Vec2 operator/(Vec2 const& v, float s){
	Vec2 result(v);
	if(s==0){
        result.x=0;             // muss x,y getrennt definiert
        result.y=0;
		std::cout<<"Fehler! Vector kann nicht durch v/s 0."<<std::endl;
	}
	else{
		result/=s;
	}
	return result;
}
Vec2 operator*(float s, Vec2 const& v){
    return v*s;                // einfach v*s, operator keine Funktion, * ist schon definiert
}
//Aufgabe 2.6
/* 2 Vec2 operator* (Mat2 const& m, Vec2 const& v) {
   			Vec2 result;
    		result.x=m.arr[0]*v.x+m.arr[1]*v.y;
    		result.y=m.arr[2]*v.x+m.arr[3]*v.y;
    		return result;
}*/
 /* 3 Vec2 operator* (Vec2 const& v, Mat2 const& m) {
    		Vec2 result;
    		result.x=m.arr[0]*v.x+m.arr[2]*v.y;
    		result.y=m.arr[1]*v.x+m.arr[3]*v.y;
    		return result;
}
*/

Vec2::~Vec2(){}
//Aufgabe 2.7








