#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "List.hpp"
#include <list>
#include <vector>
#include <initializer_list>
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

// Aufgabe 4.9
TEST_CASE("test_insert","[insert]"){
	List<int> list;
	list.push_back(1);
	list.push_back(2);
	auto i=list.begin();
	list.insert(4,i);
	REQUIRE( list.front()==4 );

	/*auto j=list.end();
	list.insert(3,j);
	REQUIRE( list.back()==3 );*/
}


// Aufgabe 4.10
TEST_CASE("test_reverse","[reverse]"){
	List<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.reverse();
	REQUIRE( list.front()==3 );
	REQUIRE( list.back()==1 );

	List<int> list1=reverse(list);
	REQUIRE( list1.back()==3 );
	REQUIRE( list1.front()==1 );

}
// Aufgabe 4.11
TEST_CASE("test_copy","[copy_in_vector]"){
	List<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	vector<int> vector(list.size()); // 
	copy(list.begin(),list.end(),vector.begin());
	REQUIRE( *vector.begin()==1 );
	//REQUIRE( *vector.end()==3 ); ?
}
// Aufgabe 4.12
TEST_CASE("test_operator_zuweisung","[test_operator_zuweisung]"){
	List<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	List<int> list2;
	list2=list1;
	REQUIRE( list2.front()==1 );
	REQUIRE( list2.back()==3);
}
// Aufgabe 4.13
TEST_CASE (" move constructor ", "[ constructor ]")
{
	List<int> list;
	list.push_front (1);
	list.push_front (2);
	list.push_front (3);
	list.push_front (4);
	List<int> list2 =move(list);
	REQUIRE (0 == list.size ());
	REQUIRE ( list.empty() );
	REQUIRE (4 == list2.size ());
}
// Aufgabe 4.14
TEST_CASE (" test_initializer_list ", "[ initializer_list]")
{
	List<int> int_list{9,5,38,100};
	List<int> int_list1{1,2};
	List<int> int_list2{5,6};
	REQUIRE(int_list.front()==9);

	auto summe_list= int_list1+int_list2;
	List<int> int_list3{1,2,5,6};
	REQUIRE( int_list3==summe_list);

	REQUIRE(int_list1.front()==1 );
	REQUIRE(int_list1.back()==2 );
	REQUIRE(int_list2.front()==5 );
	REQUIRE(int_list2.back()==6 );

	REQUIRE(summe_list.front()==1);
	REQUIRE(summe_list.back()==6);
}
int main(int argc, char* argv[]){
	auto l = List<int>{1 , 2, 3, 4, 5} + List <int>{6 , 7, 8, 9};
	return Catch::Session().run(argc,argv);
}





