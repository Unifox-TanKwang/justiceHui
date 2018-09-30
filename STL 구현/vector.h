#pragma once
#include <string>
namespace JH{
	typedef unsigned int size_t;
	template <typename T>
	class vector{
		private:
			T *arr;
			size_t ncapacity, nsize;
			void realloc(size_t); //O(n)
		public:
			//constructor
			vector(); //O(1)
			vector(size_t); //O(n)
			vector(size_t size, T value); //O(n)
			//destructor
			~vector(){ delete[] arr; } //O(1)
			//element eccess
			T at(size_t); //O(1)
			T operator [] (size_t); //O(1)
			T front(){ return at(0); } //O(1)
			T back(){ return at(nsize-1); } //O(1)
			//iterators
			T* begin(){ return arr; } //O(1)
			T* end(){ return arr+nsize(); } //O(1)
			//capacity
			bool empty(){ return (nsize==0); } //O(1)
			size_t size(){ return nsize; } //O(n)
			size_t capacity(){ return ncapacity; } //O(1)
			//modifiers
			void clear(); //O(1)
			void push_back(T); //amotized O(1)
			void pop_back(); //amotized O(1)
			void resize(size_t); //O(n)
			std::string iterType();
	};
	
	template <typename T>
	vector<T>::vector(){
		arr = nullptr;
		ncapacity = nsize = 0;
	}
	
	template <typename T>
	vector<T>::vector(size_t size){
		ncapacity = nsize = size;
		arr = new T[size];
		for(int i=0; i<size; i++) arr[i] = 0;
	}
	
	template <typename T>
	vector<T>::vector(size_t size, T value){
		ncapacity = nsize = size;
		arr = new T[size];
		for(int i=0; i<size; i++) arr[i] = value;
	}
	
	template <typename T>
	void vector<T>::realloc(size_t newSize){
		T *tmp = arr;
		arr = new T[newSize];
		for(int i=0; i<nsize && i<newSize; i++){ 
			arr[i] = tmp[i];
		}
		if(tmp) delete[] tmp;
		ncapacity = newSize;
	}
	
	template <typename T>
	T vector<T>::at(size_t idx){
		if(idx < nsize) return arr[idx];
		else return 0;
	}
	
	template <typename T>
	T vector<T>::operator [] (size_t idx){
		return at(idx);
	}
	
	template <typename T>
	void vector<T>::clear(){
		nsize = 0;
		realloc(0);
	}
	
	template <typename T>
	void vector<T>::push_back(T value){
		if(nsize == ncapacity){
			int newSize;
			if(!nsize) newSize = 16;
			else newSize *= 2;
			realloc(newSize);
		}
		arr[nsize++] = value;
	}
	
	template <typename T>
	void vector<T>::pop_back(){
		if(nsize == 0) return;
		nsize--;
		if(nsize < ncapacity/2){
			realloc(ncapacity/2);
		}
	}
	
	template <typename T>
	void vector<T>::resize(size_t size){
		realloc(size);
	}
	
	template <typename T>
	std::string vector<T>::iterType(){
		return "random access";
	}
}
