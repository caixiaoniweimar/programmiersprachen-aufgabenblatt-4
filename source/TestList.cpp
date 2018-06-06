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

// Aufgabe 4.6
TEST_CASE("should be an empty range after default construction","[iterators]"){ 
	List<int> list;
	auto b=list.begin();
	auto e=list.end();
	REQUIRE(b==e);
}

TEST_CASE("provide access to the first elemen","[iterators]"){
	List<int> list;
	list.push_front(42);
	REQUIRE( 42 == *list.begin());
}

// Aufgabe 4.7
TEST_CASE("beurteilen zwei List ob gleich","[List_ob_gleich]"){
	List<int> list1;
	List<int> list2;
	REQUIRE( list1==list2);

	list1.push_back(1);
	list2.push_back(1);
	REQUIRE( list1==list2 );
	list2.push_back(2);
	list1.push_back(3);
	REQUIRE( list1!=list2 );

	List<int> list4;
	List<int> list3;
	list3.push_back(1);
	REQUIRE( list4!=list3);
	list4.push_back(2);
	list3.pop_back();
	REQUIRE( list4!=list3);
}

// Aufgabe 4.8
TEST_CASE("copy constructor","[constructor]"){
	List<int> list;
	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.push_front(4);
	List<int> list2{list};
	REQUIRE( list==list2);           
}

int main(int argc, char* argv[]){
	return Catch::Session().run(argc,argv);
}





