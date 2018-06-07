#ifndef LIST_HPP
#define LIST_HPP
#include <cstddef>
#include <list>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;
//不要忘记 每个Klasse的成员变量的初始化(通过Initialisierungslist) 
template <typename T>
class List;

template <typename T>
struct ListNode{
	T value = T(); 
	ListNode* prev= nullptr;
	ListNode* next= nullptr;
};

template <typename T>        
class ListIterator{
	public:
// Aufgabe 4.5					！！！！！！
/*指针Zeiger/Point是一个变量,这个变量存储的是一个地址,指向内存的一个存储单元。
	int a=1; int *p=&a;  //指针变量p,该指针变量指向a的存储单元,即p的值是a存储单元的地址
	int a=1; int &b=a;   //引用不可以为空,必须初始化。
*/
		using Self=ListIterator<T>;	  //迭代器指的是数据, *(iterator)数据的值,	
		using value_type=T;				//迭代器所指数据类型					  值
		using pointer=T*;				//迭代器所指的数据,不允许改变,可以当右值   指针
		using reference=T&;				//迭代器所指的数据,允许改变,可以当左值	  引用
		using difference_type=ptrdiff_t;  //两个迭代器间的距离
		using iterator_category=bidirectional_iterator_tag;
		ListIterator():
			node{nullptr} {}      				// not implemented yet

		ListIterator(ListNode<T>* n):
			node{n} {}				// this-> Objdekt Address
									// *this -> reference wert
		// 重要⬇️
		reference operator*() const{  //取所指节点中的数据  *(iterator);
			return (*node).value;  // this->pointer
			//return (*this).value;					//指向相同的结果
		}

		/*int a = 5;

		int& int_ref =  a; // direkte referenz
		int* int_ptr = &a; // indirekte referenz

		std::cout << int_ref;  // direkter zugriff
		std::cout << *int_ptr; // indirekter zugriff
		*/

		pointer operator->() const{  //取所指节点中数据的地址  c2->radius();
			return &( (*this).value ); 		
		}

		// pre-increment
		Self& operator++() {		//前置++操作符,指向下一个节点   ++iterator 返回 增加后的引用！！
			//node=node->next;
			node =(*node).next;     //++i iterator推迟
			return *this;
		}
		//post-increment
		Self operator++(int) {		//后置++操作符，指向下一个节点	 iterator++    返回之前的值
			 Self neue = *this;    //i++ 
			 ++ *this;				
			 return neue;
		}
		// 重要⬆️

		bool operator==(Self const& x) const {  // zwei Iterator vergleich 是不是指向同一个的node  //重要！！！
			if ( node == x.get_node() )  // vergleichen ob zeigt, die selber Node ist.
			{							  // 比较两个Iterator指的地址是否相同
				return true;            
			}
			else
				return false; 				//return node==x.node
		}
		bool operator!=(Self const& x) const {
			if( node != x.get_node() )
			{
				return true;
			}
			else
			{
				return false;
			}
		}									//not implemented yet

		Self next() const{
			if(node)
				return ListIterator(node->next);
			else
				return ListIterator(nullptr);
		}

		ListNode<T>* get_node() const {
			return node;
		}
	private:
	  	ListNode<T>* node;  //The node the iterator is poingting to	
};

template <typename T>
class ListConstIterator{
	public:
 	private:
 		ListNode<T>* node;
};

template <typename T>
class List{
	public:
		using value_type =T;
		using pointer =T*;
		using const_pointer = T const*;
		using reference = T&;
		using const_reference = T const&;
		using iterator = ListIterator<T>;
		using const_iterator = ListConstIterator<T>;

// Aufgabe 4.2
		List(): // Standard-Konstruktor
			size_{0},
			first_ {nullptr},
			last_ {nullptr} {}

// Aufgabe 4.8: Copy construtor
		List(List<T> const& list):
			size_{ 0 },
			first_{ nullptr },
			last_{ nullptr } { 
				auto i=list.begin();
				while( i!=list.end() ){
					push_back(*i);
					++i;
				}
			}

// Aufgabe 4.6 Iterator_begin(),end()重写
		ListIterator<T> begin() const{		
			return ListIterator<T>(first_);
		}
		ListIterator<T> end() const {		
			return ListIterator<T>(nullptr);
		}
// Aufgabe 4.2 
		bool empty() const {			//如果begin()==end() 说明为空
			if( begin()==end() )
				return true;
			else
				return false;
		}

		std::size_t size() const{		//返回size_
			return size_;
		}

// Aufgabe 4.3
		void push_front(T const& value) {
			if( empty() ){
				first_=new ListNode<T>{value,nullptr,nullptr};
				last_=first_;
				++size_;
			}
			else{
				first_=new ListNode<T>{value,nullptr,first_};
				( *( (*first_).next ) ).prev=first_; //Element selbst 
			    ++size_;
		    }
		}
		void push_back(T const& value) {
			if( empty() ){
				last_=new ListNode<T>{value,nullptr,nullptr};
				first_=last_;
				++size_;
			}
			else{
				last_=new ListNode<T>{value,last_,nullptr};
				( *( (*last_).prev ) ).next=last_;
				++size_;
			}
		}
		void pop_front() {
			if( size()==1 ){
				first_=last_=nullptr;     
				--size_;
			}
			else{
				first_= (*first_).next; // first_= &*( (*first_).next )
				--size_;
			}
		}
		void pop_back() {
			if( size()==1 ){
				first_=last_=nullptr;
				--size_;
			}
			else{
				last_=(*last_).prev;
				--size_;
			}
		}
		T front() const{
			return (*first_).value;
		}
		T back() const{
			return (*last_).value;
		}

// Aufgabe 4.4
		void clear() {
			while(empty()==false){
				pop_back();
			}
		}
        ~List(){ clear(); }; //Destruktor mit clear()

// Aufgabe 4.9
       	void insert( T const& objekt, ListIterator<T> const& position){ //知道iterator 就可以getnode!!得到这个位置的node
       		
       		ListNode<T>* node = position.get_node();
       		if( (*node).prev == nullptr ){
       			/*ListNode<T>* neue_objekt=new ListNode<T>{objekt,nullptr,node}; //说明node是第一个元素
       			(*node).prev=neue_objekt;
       			first_=neue_objekt;*/
       			push_front(objekt);
       		}
       		if( node==nullptr ){
       			push_back(objekt);
       		}
       		else{
       			ListNode<T>* neue_objekt=new ListNode<T>{objekt, (*node).prev, node};
       			(*(*node).prev).next=neue_objekt;
       			(*node).prev=neue_objekt;
       		}
 
       		++size_;
        } 
// Aufgabe 4.10
        void reverse(){
        	ListNode<T>* node = first_ ;  // node为first_第一个元素
        	ListNode<T>* temp = nullptr;  // 暂时的对象 为 temp 为空

        	while( node != nullptr){		// 只要node不为空 当node到end() 则为空
        		temp = (*node).next;		// temp是 node->next
        		(*node).next = (*node).prev; // node->next 是 node->prev 原来的node已经到了(原来的node.next)的后面
        		(*node).prev = temp;		 // node的前面 是temp
        		if(temp==nullptr){     //当temp为空,则node->next为空 则此时的temp为back() 最后一个元素
        			last_=first_;		// 最后的元素等于第一个元素
        			first_=node;		// 第一个元素等于node 
        		}
        		node=temp;			//每次改变循环条件, node等于temp 等于node.next 一直往后面前进
        	}
    	}

// Aufgabe 4.12							//?
    	/*void Swap( List<T>& lis){
    		swap(first_ , lis.first_);
    		swap(last_ , lis.last_);
    	}*/
    	List<T>& operator= ( List<T>& list1) {	
    		clear();
    		for(auto i=list1.begin(); i!=list1.end(); ++i){
    			push_back(*i);
    		}
    		return *this;
    	}
    	/*List<T>& operator= ( List<T> lis){
    		//clear();
    		Swap(lis);
    		return *this;
    	}*/

// Aufgabe 4.13
  		List(List<T>&& list):  // move-Konstruktor
  			size_(list.size_),
  			first_(list.first_),
  			last_(list.last_)
  			{
  				list.size_=0;
  				list.first_=nullptr;
  				list.last_=nullptr;
  				cout<<"1"<<endl;
  			}

// Aufgabe 4.14
		List(initializer_list<T> list):
			size_(0),
			first_(nullptr),
			last_(nullptr) {
				for( auto i=list.begin(); i!=list.end(); ++i){
					push_back(*i);
				}
			}
	private:
	    std::size_t size_;
		ListNode<T>* first_;  //Pointer,Zeiger first_ ist ein Zeiger auf ListNode   // *first_ : Node(Element )
		ListNode<T>* last_;
};

// Aufgabe 4.7
template <typename T>
bool operator==(List<T> const& xs,List<T> const& ys){
		if(xs.size()==ys.size()){
				auto i=xs.begin();
				auto j=ys.begin();
			for(int m=0; m<xs.size(); ++m){
					if( (*i) != (*j) ){       // 直接元素比较
						return false;
					}
					else{
						++i;
						++j;
					}
				}
		}
		else{
			return false;
		}
		return true;
}

template <typename T>
bool operator !=(List<T> const& xs, List<T> const& ys){
	if(xs==ys){
		return false;
	}
	else 
		return true;
}               

template<typename T>
List<T> reverse(List<T> const& list) {
	List<T> list1(list);
	list1.reverse();
	return list1;	
}

template<typename T>
List<T> operator+(List<T> const& lhs, List<T> const& rhs){  //有两个Uebergabeparamter-> freie Funktion!!
			//List<T> r(lhs);
			List<T> r;
			for( auto i=lhs.begin(); i!=lhs.end(); ++i){
					r.push_back(move(*i));
			}
			for( auto i=rhs.begin(); i!=rhs.end(); ++i){
					r.push_back(move(*i));
			}
			return r;
}
//可以移动而非拷贝对象的能力。在其中某些情况下，对象拷贝后就立即被销毁了，
//在这些情况下，移动而非拷贝对象会大幅度提升性能
//C++ 标准库使用比如vector::push_back 等这类函数时,会对参数的对象进行复制,
//连数据也会复制.这就会造成对象内存的额外创建
#endif