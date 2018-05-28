#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

// Aufgabe 3.9
int main(){

	vector<int> v_0(10);	// v_0 -> vector
	for(auto& v:v_0){		// v -> vector_iterator
		v=rand();			// erzeugen Zufallswerte im vector
	}
	cout<<"1. Ausgaben vector v_0 mit Zufallswerte:"<<endl;
	copy( cbegin(v_0), cend(v_0), ostream_iterator<int> (cout,"\n") ); 
	//copy vector v_0 from "first" to "last" im eine temporäre Objekt und dann cout
	cout<<endl;

	list<int> l_0( cbegin(v_0), cend(v_0) );   // copy vector v_0 im list l_0 
	list<int> l_1( cbegin(l_0), cend(l_0) );   // copy list l_0 im list l_1

	reverse( begin(l_1), end(l_1) );  // reverse Reihenfolge der Elemente im list l_1
	cout<<"2. Ausgaben reverse-list_l1:"<<endl; 
	copy( cbegin(l_1), cend(l_1), ostream_iterator<int> (cout,"\n") ); 
	// copy list reverse-l_1 im eine temporäre Objekt und dann ausgeben
	cout<<endl;

	l_1.sort();  // sort list l_1
	cout<<"3. Ausgaben sortiert-list_l1:"<<endl;
	copy( l_1.cbegin(), l_1.cend(), ostream_iterator<int> (cout,"\n") );
	// copy list sortiert-l_1 im eine temporäre Objekt und dann ausgeben
	cout<<endl;

    cout<<"4. Ausgaben generate-vector_v0:"<<endl; 
	generate( begin(v_0), end(v_0), rand ); 
	// erzeuge neue vector v_0 mit generate-funktion rand(); Frueher v_0 wird verdeckt
	copy( v_0.cbegin(), v_0.cend(), ostream_iterator<int> (cout,"\n") );
	
	cout<<"5. Ausgaben generate-reverse-vector_v0:"<<endl;
	copy( v_0.crbegin(), v_0.crend(), ostream_iterator<int> (cout,"\n") );
	// copy reverse v_0 im eine temporäre Objekt und dann ausgeben
	cout<<endl;

	return 0;

}