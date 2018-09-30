#pragma once
#include <iostream>
#include <string>
namespace JH{
	template <typename T>
	class node{
		public:
			T data;
			node<T>* prv;
			node<T>* nxt;
			node(){
				data = 0, prv = nxt = nullptr;
			}
			node(T value){
				data = value, prv = nxt = nullptr;
			}
	};
	
	template <typename T>
	class list{
		private:
			node<T> *nbegin;
			node<T> *nend;
			size_t nsize;
		public:
			//constructor
			list(){
				nbegin = new node<T>();
				nend = new node<T>();
				nbegin->nxt = nend;
				nend->prv = nbegin;
				nsize = 0;
			} //O(1)
			//destructor
			~list(); //O(n)
			//iterators
			node<T>* begin(){ return nbegin->nxt; } //O(1)
			node<T>* end(){ return nend; } //O(1)
			//capacity
			size_t size(){ return nsize; } //O(1)
			bool empty(){ return (nsize == 0); } //O(1)
			//element access
			T front(){ return nbegin->nxt->data; } //O(1)
			T back(){ return nend->prv->data; } //O(1)
			//modifiers
			void insert(node<T>*, T); //O(1)
			void insert(int, T); //O(n)
			void erase(node<T>*); //O(1)
			void erase(int); //O(n)
			void push_back(T); //O(1)
			void pop_back(); //O(1)
			void push_front(T); //O(1)
			void pop_front(); //O(1)
			void print(); //O(n)
			std::string iterType();
	};
	
	template <typename T>
	void list<T>::insert(node<T>* prv, T value){
		if(prv == nend){
			std::cout << "reject" << std::endl;
			return;
		}
		if(prv == nullptr){
			std::cout << "NullPointerException" << std::endl;
			return;
		}
		nsize++;
		node<T> *ptr = new node<T>(value);
		ptr->prv = prv;
		ptr->nxt = prv->nxt;
		prv->nxt->prv = ptr;
		prv->nxt = ptr;
	} 
	
	template <typename T>
	void list<T>::insert(int pos, T value){
		node<T> *iter = nbegin;
		for(int i=0; i<pos; i++){
			iter = iter->nxt;
		}
		insert(iter, value);
	}
	
	template <typename T>
	void list<T>::erase(node<T>* ptr){
		if(ptr == nbegin){
			std::cout << "reject" << std::endl;
			return;
		}
		if(ptr == nullptr){
			std::cout << "NullPointerException" << std::endl;
			return;
		}
		nsize--;
		ptr->prv->nxt = ptr->nxt;
		ptr->nxt->prv = ptr->prv;
		delete ptr;
	}
	
	template <typename T>
	void list<T>::erase(int pos){
		node<T> *iter = nbegin;
		for(int i=0; i<=pos; i++){
			iter = iter->nxt;
		}
		erase(iter);
	}
	
	template <typename T>
	void list<T>::push_back(T value){
		insert(nend->prv, value);
	}
	
	template <typename T>
	void list<T>::pop_back(){
		erase(nend->prv);
	}
	
	template <typename T>
	void list<T>::push_front(T value){
		insert(nbegin, value);
	}
	
	template <typename T>
	void list<T>::pop_front(){
		erase(nbegin->nxt);
	}
	
	template <typename T>
	list<T>::~list(){
		auto now = nbegin;
		auto nxt = nbegin->nxt;
		while(now != nend){
			if(now) delete now;
			now = nxt;
			if(now != nend) nxt = now->nxt;
		}
	}
	
	template <typename T>
	void list<T>::print(){
		auto iter = begin();
		for(; iter != end(); iter = iter->nxt) std::cout << iter->data << std::ends;
	}
	
	template <typename T>
	std::string list<T>::iterType(){
		return "bidirectional";
	}
}
