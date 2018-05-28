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
//#include <functional>
#include "vergleichen.hpp"

//Aufgabe 3.7+3.8
		Circle c1{"Circle1", {2,3},50,{1.0,1.0,1.0}  };
        Circle c2{"Circle2", {5,5},5,{1.0,1.0,0.0} };
        Circle c3{"Circle3" , {8,8},100,{1.0,1.0,1.0} };
        Circle c4{"Circle4" , {10,10},5,{1.0,1.0,1.0} };
        Circle c5{"Circle4" , {9,9},900,{1.0,1.0,1.0} };

    	vector<Circle> sorted_circles{c1,c2,c5,c3,c4};
        vector<Circle> sorted_circles1{c1,c2,c5,c3,c4};

// Vergleichensfunkton mit Lambdas
auto l=[] (Circle const& r, Circle const& s) -> bool { //Lamdas
    return ( (r.radius_ < s.radius_) ? true: 
             ( (r.radius_ == s.radius_)? 
               (r.radius_ < s.radius_) : false ) );
};

// Test ob Container sortiert
TEST_CASE ("test_sorted_circles","[sorted_circles]"){ 
    REQUIRE(std::is_sorted(sorted_circles.begin(),sorted_circles.end(),l));// remember l!!!
}
TEST_CASE ("test_sorted_circles1","[sorted_circles1]"){ 
    REQUIRE(std::is_sorted(sorted_circles1.begin(),sorted_circles1.end(),vergleichen{}));// remember l!!!
}

int main(){	
// Aufgabe 3.7 sort mit Lambdas
    sort(sorted_circles.begin(),sorted_circles.end(),l);
    for(auto const& item: sorted_circles){
    	cout<<item<<endl;
    }
    cout<<endl;

// Aufgabe 3.8 sort mit Funktor
    sort(sorted_circles1.begin(),sorted_circles1.end(),vergleichen{}); //Funktor
    for(auto const& item: sorted_circles1){
        cout<<item<<endl;
    }

    return Catch::Session().run();
    return 0;
}