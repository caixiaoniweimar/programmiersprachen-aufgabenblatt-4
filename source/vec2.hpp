#ifndef VEC2_HPP
#define VEC2_HPP
//#include "mat2.hpp"

struct Vec2{  //struct braucht nicht _(keine Membervariablen)

	float x;
	float y;

//Aufgabe 2.2
	Vec2();  //Standardkonstruktor

	Vec2(float x1, float y1);   //NormalKonstruktor

//Aufgabe 2.3
	Vec2& operator+= (Vec2 const& v);  // Vec2&
	Vec2& operator-= (Vec2 const& v);  
	Vec2& operator*= (float s);  
	Vec2& operator/= (float s); 

	~Vec2();	//Destruktor
};

//Aufgabe 2.4       
// keine Memberfunktion D,h außer struct{};
    Vec2 operator+ (Vec2 const& u, Vec2 const& v);
    Vec2 operator- (Vec2 const& u, Vec2 const& v);
    Vec2 operator* (Vec2 const& v, float s);
    Vec2 operator/ (Vec2 const& v, float s);
    Vec2 operator* (float s, Vec2 const& v);

 //Aufgabe 2.6
 /* 2 */  // Vec2 operator*(Mat2 const& m, Vec2 const& v);
 /* 3 */  // Vec2 operator*(Vec2 const& v, Mat2 const& m);
// freie Funktionen
/*bool operator < (Circle const& lhs, Circle const& rhs){
    return lhs.r<rhs.r; }
 freie Funktion kann Methode im Class aufrufen.
}*/
// Prädikat als freie Funktion implementieren

/*template <typname T>;
T const& max(T const& a, T const& b){
    if(a>b){
        return a;
    }
    else {
        return b;
    }
}
template <typname STACK>
class Stack{
public: void push(STACK const& item);
private: std::vector<STACK> s;
}*/
#endif
   
