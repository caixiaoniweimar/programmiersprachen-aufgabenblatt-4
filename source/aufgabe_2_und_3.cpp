#include <list>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;    

    int main(){
        std::list<unsigned int> l1(100); // list mit 100 Elementen anlegen
        std::list<unsigned int> l2(100);
        std::list<unsigned int> l3(100);
        
//Aufgabe 3.2 
        cout<<"Methode1:"<<endl;
        cout<<"noch nicht sortiert:"<<endl;
    /*1*/for(auto i=l1.begin(); i != l1.end(); ++i){  // List mit Zufallswerte erzeugen
            *i= rand()%100;
            cout<< *i<<" ";
        }
        cout<<"\n"<<endl;

        cout<<"Ausgabe Zahlen, die nicht in der list sind(1-100):"<<endl;
        set<int> loesung;         
        int mal=0;
        for(int j=0; j<100; j++){
            int zahl=0;
            for(auto i=l1.begin(); i != l1.end(); ++i){
                if( (*i)==j ){
                    zahl=zahl+1;
                    break;
                }
            }
            if(zahl==0){
                loesung.insert(j);  // 将每个j insert到set Container中
                mal++;
            }
        }
        for(auto item: loesung){
            cout<<item<<" ";
        }
        cout<<endl;
        cout<<mal<<" Zahlen sind nicht in der list."<<endl;
        cout<<"Es gibt "<<100-mal<<" unterschiedliche Zahlen in der list."<<endl<<endl;

//Aufgabe 3.3       重要！！！！！
        std::map<int,int> frequency;    //map声明 <int,int> list的类型也为int
        //list的值作为key关键词 次数作为Wert值

        for(auto element: l1){         //计算每个值的出现次数           ？
            ++frequency[element];      //每出现一次,对应Key的值加1
        }                              //根据Key来分类

        for(auto const& item: frequency){
            cout<<item.first<<" : "<<item.second<<endl; //map 调用直接用 .first/.second
        }

        /*void foo(int a);
        void foo(std::string& s)
        void foo(std::string const& s);*/

//Aufgabe 3.2 andere zwei Methoden, um Zufallswert zu erzeugen 
        cout<<"Methode2:"<<endl;
    /*2*/for(std::list<unsigned int>::iterator j=l2.begin(); j !=l2.end(); ++j ){
            *j= rand()%100;
            cout<<*j<<" ";
        }
        cout<<"\n"<<endl;
        
        cout<<"Methode3:"<<endl;
    /*3*/for(auto m: l3){ // m ist Referenz auf Objekt im Container
            m=rand()%100;
        }
    /*3ausgeben*/
        for(auto m: l3){
            cout<<m<<" ";
        }
        cout<<"\n"<<endl;
   

//Aufgabe 3.10 copy-list im vector
        vector<int> copy_vector1(100);
        copy(l3.begin(), l3.end(), copy_vector1.begin());

        cout<<"Ausgabe copy:"<<endl;
        copy(l3.cbegin(), l3.cend(), ostream_iterator<int> (cout," "));
        cout<<endl;

        cout<<"Ausgabe reverse-copy:"<<endl;
        copy(l3.crbegin(), l3.crend(), ostream_iterator<int> (cout," "));
        cout<<endl;

        return 0;
    }










