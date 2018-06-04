#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "List.hpp"
#include <list>

// Aufgabe 4.2
TEST_CASE("test_size","[test_size]"){
	List<int> list1;
	REQUIRE( list1.size()==0 );

	list1.push_back(5);
	list1.push_back(6);
	REQUIRE( list1.size()==2 );

	list1.pop_back();
	REQUIRE( list1.size()==1 );
	
}
TEST_CASE("test_ob_empty","[test_empty]"){
	List<int> list2;
	REQUIRE( list2.empty()==true );
	list2.push_back(1);
	REQUIRE( list2.empty()==false );
}
// Aufgabe 4.3
TEST_CASE("test_push_front","[test_push_front]"){
	List<int> list2;
	list2.push_front(1);
	list2.push_back(2);
	REQUIRE( 1==list2.front() );         
}
TEST_CASE("test_push_back","[test_push_back]"){
	List<int> list2;
	list2.push_back(2);
	list2.push_back(3);
	REQUIRE( 3==list2.back() );
}
TEST_CASE("test_pop_front","[test_pop_front]"){
	List<int> list2;
	list2.push_back(2);
	list2.push_back(3);
	list2.pop_front();
	REQUIRE( 3==list2.front() );
}
TEST_CASE("test_pop_back","[test_pop_back]"){
	List<int> list2;
	list2.push_back(2);
	list2.push_back(3);
	list2.pop_back();
	REQUIRE( 2==list2.back() );

	REQUIRE( list2.empty()==false);
	list2.pop_back();
	REQUIRE( list2.empty()==true );
}
// Aufgabe 4.4
TEST_CASE("test_clear","[test_clear]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	list.clear();
	REQUIRE(list.empty()==true);
}


int main(int argc, char* argv[]){
	return Catch::Session().run(argc,argv);
}