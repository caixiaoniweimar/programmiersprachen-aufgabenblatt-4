#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "circle.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;   
#include <string>
#include <set>
#include <vector>
#include <map>
#include <string>

// Ueberladen Operator < > ==   vector若为自定义类型, 它的输出需要自定Operator
bool operator < (Circle const& l,Circle const& r){ 
	return ( l.radius_<r.radius_? true: false  );
}
bool operator > (Circle const& l,Circle const& r){
	return ( l.radius_>r.radius_? true: false  );
}
bool operator == (Circle const& l,Circle const& r){
	return ( l.radius_==r.radius_? true: false  );
}

// Speicher Circles im vector
		Circle c1{"Circle1", {2,3},50,{1.0,1.0,1.0}  };
        Circle c2{"Circle2", {5,5},5,{1.0,1.0,0.0} };
        Circle c3{"Circle3" , {8,8},100,{1.0,1.0,1.0} };
        Circle c4{"Circle4" , {10,10},5,{1.0,1.0,1.0} };
        Circle c5{"Circle5" , {9,9},900,{1.0,1.0,1.0} };
	
    	vector<Circle> sorted_circles{c1,c2,c5,c3,c4};

// Test ob schon sort
TEST_CASE ("test_sorted_circles","[sorted_circles]"){ 
    REQUIRE(std::is_sorted(sorted_circles.begin(),sorted_circles.end()));
}

int main(){	

// Aufgabe 3.5 probieren
    map<string, int> matrikelnummern;

    //Einfuegen
    matrikelnummern["Max"]=12345;
    /*1*/matrikelnummern["Erika"]=23523;
    //exmatrikulation(matrikelnummern["Fred"]);  error: use of undeclared identifier 'exmatrikulation'
    /*2*/matrikelnummern.insert(make_pair("Paul",12356));

    //Suchen
    auto i=matrikelnummern.find("Paul");
    if(i!=matrikelnummern.end()){
        cout<<i->first<<" ist here!"<<endl<<endl;
        matrikelnummern.erase(i);
    }
    else{
        cout<<i->first<<" existiert nicht!"<<endl<<endl;
    }
    for(auto const& item: matrikelnummern){
        cout<<item.first<<" "<<item.second<<endl;
    }
    cout<<endl;

//Aufgabe 3.6
    sort(sorted_circles.begin(),sorted_circles.end());
    cout<<"Circles Ausgaben:"<<endl;
    for(auto const& item: sorted_circles){
    	cout<<item<<endl;
    }
    return Catch::Session().run();
    return 0;
}