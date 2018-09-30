#include "vector.h"
#include "list.h"
#pragma once

namespace JH{
	template <typename T>
	class stack{
		private:
			vector<T> arr;
		public:
			bool empty(){ return arr.empty(); } //O(1)
			size_t size(){ return arr.size(); } //O(1)
			T top(){ return arr.back(); } //O(1)
			void push(T value){ arr.push_back(value); } //amotized O(1)
			void pop(){ arr.pop_back(); } //amotized O(1)
	};
	
	template <typename T>
	class stack_list{
		private:
			list<T> arr;
		public:
			bool empty(){ return arr.empty(); } //O(1)
			size_t size(){ return arr.size(); } //O(1)
			T top(){ return arr.back(); } //O(1)
			void push(T value){ arr.push_back(value); } //amotized O(1)
			void pop(){ arr.pop_back(); } //amotized O(1)
	};
}
