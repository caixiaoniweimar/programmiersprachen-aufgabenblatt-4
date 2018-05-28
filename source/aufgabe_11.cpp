#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include "circle1.hpp"
using namespace std;
// Aufgabe 3.11
vector<unsigned int> v(100); 

// Aufgabe 3.12
vector<int> v1{1,2,3,4,5,6,7,8,9};
vector<int> v2{9,8,7,6,5,4,3,2,1};
vector<int> v3(9);

// Aufgabe 3.11- entscheiden ob durch 3 teilbar
bool ob_teilbar_3(int i){
	return (i%3)!=0;         //若i不能整除3则回true
}

// Aufgabe 3.11- ob vielfache von drei
bool is_multiple_of_3(int i){ 
	return (i%3)==0;
}

// Aufgabe 3.12- ob alle gleich 10
bool ob_is_zehn(int i){
	return i==10;
}

// Aufgabe 3.13 - Funktionstemplate
    bool is_even(int n) { return n%2==0; }
 	template<typename T,typename K>
	T filter(T const& t,K const& k){   // T-容易(例子为向量),K-函数,若k返回为真 则这个值插入到T中
		T t1;
		for(auto item=t.begin(); item != t.end(); ++item){
			if( k(*item)==true ) {
			  t1.push_back(*item);
			}
		}
		return t1;
	}
	vector<int> v_13{1,2,3,4,5,6};
	vector<int> all_even=filter(v_13, is_even); //如何知道int n是v的每个人值? 如何插入到T(return n);

	TEST_CASE("test ob alle Werte durch 2==0","[ob_teilbar_2]"){
	REQUIRE( all_of(all_even.begin(), all_even.end(), is_even) );
	}

// Aufgabe 3.14
vector<Circle1> circles{ {5.0f} ,{3.0f} ,{8.0f},{1.0f} ,{5.0f} };
vector<Circle1> circles_copy(circles.size());        //一定要定义vector大小 

//Lambda ob alle_grosser_3
auto ob_alle_grosser_3 = [](Circle1 const& i)-> bool {
	return i.circle_radius>=3.0f;
};

//Aufgabe 3.14 Test ob alle grosser 3
TEST_CASE("test_ob_grosser_3","[grosse3]"){
	REQUIRE( all_of(circles_copy.begin(), circles_copy.end(), ob_alle_grosser_3) );
}

// Aufgabe 3.11 test ob vielfache von drei
TEST_CASE("test_vector","[vector]"){
	REQUIRE( all_of(v.begin(), v.end(), is_multiple_of_3) ); 
}

// Aufgabe 3.12 test ob gleich 10
TEST_CASE("test_ob ist zehn","[ob_is_zehn]"){
	REQUIRE( all_of(v3.begin(), v3.end(), ob_is_zehn) );
}

int main(int argc, char* argv[]){
//Aufgabe 3.11 vector zufallszahlen erzeugen:
	cout<<"cout vector mit Zufallszahlen:"<<endl;
	for(int j=0; j<v.size(); ++j){
	v[j]=rand()%100;
	}
	for(auto const& item: v){
	cout<<item<<" ";
	}
	cout<<endl<<endl;

//Aufgabe 3.11 Entfernen nicht durch drei teilbar:
	cout<<"Entfernen nicht durch drei teilbar: "<<endl;
	v.erase( remove_if(v.begin(),v.end(),ob_teilbar_3), v.end() ); //删除掉返回true的数字
	for(auto const& item: v){
	cout<<item<<" ";
	}
	cout<<endl<<endl;

//Aufgabe 3.12 mit lambda vector addieren
    auto v3_b=v3.begin();
    auto v3_e=v3.end();
    auto v1_b=v1.begin();
    auto v2_b=v2.begin();

	cout<<"v1+v2=v3:"<<endl;
    auto vector_plus=[v3_b,v3_e,v1_b,v2_b](){
			transform (v3_b, v3_e, v1_b, v3_b, std::plus<int>());
    		transform (v3_b, v3_e, v2_b, v3_b, std::plus<int>());
    		for(auto const& item: v3){
    		cout<<item<<" ";}
	};
	vector_plus();
    cout<<endl<<endl;
    /*
    OutputIterator transform (InputIterator first1, InputIterator last1,
                            OutputIterator result, UnaryOperator op)
	{
  	while (first1 != last1) {
    *result = op(*first1);  // or: *result=binary_op(*first1,*first2++);
    ++result; ++first1;
  	}
    */

//Aufgabe 3.14 
    // Lambda ob radius >4
    auto copy=[](Circle1 const& i)->bool{ return i.circle_radius>4.0f; };  

	auto it=copy_if(circles.begin(), circles.end(), circles_copy.begin(), copy);
	circles_copy.resize( distance(circles_copy.begin(),it) ); // resize!!重新更改空间

	cout<<"Ausgabe Vector,alle Radius grosse 4 sind:"<<endl;
	for(auto const& item: circles_copy){
	cout<<item.circle_radius<<" ";
	}
	cout<<endl<<endl;

// Aufgabe 3.13 cout all_even alle Werte
	cout<<"Ausgabe vector->all_even alle Werte:"<<endl;
	for(auto const& item: all_even){
		cout<<item<<" ";
	}
	cout<<endl;

	return Catch::Session().run(argc,argv);
}
