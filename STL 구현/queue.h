#pragma once
#include "list.h"
namespace JH{
	template <typename T>
	class queue{
		private:
			list<T> arr;
		public:
			bool empty(){ return arr.empty(); } //O(1)
			size_t size(){ return arr.size(); } //O(1)
			T back(){ return arr.back(); } //O(1)
			T front(){ return arr.front(); } //O(1)
			void push(T value){ arr.push_back(value); } //amotized O(1)
			void pop(){ arr.pop_front(); } //amotized O(1)
	};
}
