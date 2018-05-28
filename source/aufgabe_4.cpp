#include "circle.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#include <string>
#include <set>
#include <vector>

bool operator < (Circle const& l,Circle const& r){ //自定义类型 需要重载operator<
	return ( l.name_<r.name_? true: false  );  //find laut name！！！
}

int main(){
// Aufgabe 3.4
        Circle c11{"Circle1", {8,8},50,{1.0,1.0,1.0}  };
        Circle c22{"Circle2", {2,3},100,{1.0,1.0,0.0} };
        Circle c33{"Circle3" , {4,8},5,{1.0,1.0,1.0} };
        Circle c44{"Circle3" , {9,8},900,{1.0,1.0,1.0} };
        set<Circle> s;      //Eintragen Kreise in set 把圆登记在set中
        vector<Circle> v{c11,c22,c33,c44};

        // abfangen set wenn doppelte Name 拦截
        for(auto& item: v){   // 将Circle储存在vector,在set中寻找有无相同的元素, 若有相同的元素,则不插入到set
            auto it=s.find(item); 
            if(s.end()!=it){        //if s.end()=it iterator到了最后一个的最后 说明没有相同的元素
                cout<<item.name_<<" existiert schon.\n\n";
            }
            else{
                s.insert(item);    //set也可以使用insert插入
            }
        }
        //Ausgeben set s: 
        for(auto const& item: s){
            cout<<item<<endl;
        }

        //fragen Circle und dann finden und ausgeben 
        cout<<"Bitte geben Sie Circle-Name ein:"<<endl;
        string name;
        cin>>name;

        Circle nutzer;          //Objekt erzeugen 定义这个对象的name_是name 其他的egal
        nutzer.name_=name;        
        auto it=s.find(nutzer);     //*it才是指针(对象)
        if(it != s.end()){      //it不是s的end() 则说明找到了
            cout<<*it<<endl;
        }
        else{
            cout<<"Sorry! Es existiert nicht."<<endl;
        }

	return 0;
}
