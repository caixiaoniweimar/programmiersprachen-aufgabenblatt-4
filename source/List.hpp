#ifndef LIST_HPP
#define LIST_HPP
#include <cstddef>
#include <list>
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
		pointer operator->() const{  //取所指节点中数据的地址  c2->radius();
			return &( operator*() ); 		
			//return &( (*this).value );
		}

		Self& operator++() {		//前置++操作符,指向下一个节点   ++iterator 返回 增加后的引用！！
			//node=node->next;
			node =(*node).next;     //++i iterator推迟
			return *this;
		}
		
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
       	/*void insert( ListNode<T>* obj, iterator position){
       		ListNode<T>* obj=new ListNode<T>{obj, (*position).prev, (*position)};

        } */

	private:
	    std::size_t size_;
		ListNode<T>* first_;  //Pointer,Zeiger first_ ist ein Zeiger auf ListNode   // *first_ : Node(Element )
		ListNode<T>* last_;
};

// Aufgabe 4.7
template<typename T>
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

template<typename T>
bool operator !=(List<T> const& xs, List<T> const& ys){
	if(xs==ys){
		return false;
	}
	else 
		return true;
}              












#endif