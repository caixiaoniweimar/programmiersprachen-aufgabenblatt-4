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
		using Self=ListIterator<T>;
		using value_type=T;
		using pointer=T*;
		using reference=T&;
		using difference_type=ptrdiff_t;
		using iterator_category=bidirectional_iterator_tag;
		ListIterator() {} // not implemented yet
		ListIterator(ListNode<T>* n){}
		reference operator*() const{}
		pointer operator->() const{}
		Self& operator++() {}
		Self operator++(int) {}
		bool operator==(Self const& x) const {}
		bool operator!=(Self const& x) const {} //not implemented yet
		Self next() const{
			if(node)
				return ListIterator(node->next);
			else
				return ListIterator(nullptr);
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

		ListNode<T>* begin() const{		//需要自己写begin()函数 返回 元素first
			return first_;
		}
		ListNode<T>* end() const {		//需要自己写end()函数 返回 nullptr
			return nullptr;
		}

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

	private:
	    std::size_t size_;
		ListNode<T>* first_;  //Pointer,Zeiger first_ ist ein Zeiger auf ListNode
		// *first_ : Node(Element )
		ListNode<T>* last_;
};

#endif